/**************************************************************************//**
 * @file     ks.c
 * @version  V1.00
 * @brief    Key Store driver source file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#include "NuMicro.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup KS_Driver KS Driver
    @{
*/

/** @addtogroup KS_EXPORTED_FUNCTIONS KS Exported Functions
    @{
*/

/**
  * @brief      Initial key store
  * @retval     0           Successful
  * @retval     others      Fail
  * @details    This function is used to initial the key store.
  *             It is necessary to be called before using other APIs of Key Store.
  */
int32_t KS_Open(void)
{
    uint32_t u32TimeOutCount;

    /* Key store initial */
    if ((KS->STS & KS_STS_INITDONE_Msk) == 0)
    {
        /* Waiting for busy */
        u32TimeOutCount = KS_TIMEOUT;

        while (KS->STS & KS_STS_BUSY_Msk)
        {
            if (--u32TimeOutCount == 0)
            {
                return KS_ERR_TIMEOUT;
            }
        }

        /* Start Key Store Initial */
        KS->CTL = KS_CTL_INIT_Msk | KS_CTL_START_Msk;

        /* Waiting for initilization */
        u32TimeOutCount = KS_TIMEOUT;

        while ((KS->STS & KS_STS_INITDONE_Msk) == 0)
        {
            if (--u32TimeOutCount == 0)
            {
                return KS_ERR_TIMEOUT;
            }
        }
    }

    /* Waiting busy to make sure KS is ready. */
    u32TimeOutCount = KS_TIMEOUT;

    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
        {
            return KS_ERR_TIMEOUT;
        }
    }

    return KS_OK;
}


/**
  * @brief      Read key from key store
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
                            \ref KS_OTP
  * @param[in]  i32KeyIdx   The key index to read
  * @param[out] au32Key     The buffer to store the key
  * @param[in]  u32WordCnt  The word (32-bit) count of the key buffer size
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to read the key.
  */

int32_t KS_Read(KS_MEM_Type eMemType, int32_t i32KeyIdx, uint32_t au32Key[], uint32_t u32WordCnt)
{
    int32_t i32Cnt;
    uint32_t u32Cont;
    int32_t offset, i, cnt;
    uint32_t u32TimeOutCount;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = ((uint32_t)eMemType << KS_METADATA_DST_Pos) | KS_TOMETAKEY(i32KeyIdx);

    offset = 0;
    u32Cont = 0;
    i32Cnt = (int32_t)u32WordCnt;

    do
    {
        /* Clear Status */
        KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

        /* Trigger to read the key */
        KS->CTL = u32Cont | KS_OP_READ | KS_CTL_START_Msk | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));
        /* Waiting for key store processing */
        u32TimeOutCount = KS_TIMEOUT;

        while (KS->STS & KS_STS_BUSY_Msk)
        {
            if (--u32TimeOutCount == 0)
                return KS_ERR_TIMEOUT;
        }

        /* Read the key to key buffer */
        cnt = i32Cnt;

        if (cnt > 8)
            cnt = 8;

        for (i = 0; i < cnt; i++)
        {
            au32Key[offset + i] = KS->KEY[i];
        }

        u32Cont = KS_CTL_CONT_Msk;
        i32Cnt -= 8;
        offset += 8;
    } while (i32Cnt > 0);

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;


    return KS_OK;
}

/**
  * @brief      Get the word count of the specified Metadata key length
  * @param[in]  u32Meta     The metadata define of the key length. It could be
                                \ref KS_META_128
                                \ref KS_META_163
                                \ref KS_META_192
                                \ref KS_META_224
                                \ref KS_META_233
                                \ref KS_META_255
                                \ref KS_META_256
                                \ref KS_META_283
                                \ref KS_META_384
                                \ref KS_META_409
                                \ref KS_META_512
                                \ref KS_META_521
                                \ref KS_META_571
                                \ref KS_META_1024
                                \ref KS_META_2048
                                \ref KS_META_4096
  * @return     The word (32-bit) count of the key
  * @details    This function is used to get word counts of the specified metadata key length.
  *             It could be used to know how may words needs to allocate for the key.
  */

uint32_t KS_GetKeyWordCnt(uint32_t u32Meta)
{
    const uint16_t au8CntTbl[21] = { 4, 6, 6, 7, 8, 8, 8, 9, 12, 13, 16, 17, 18, 0, 0, 0, 32, 48, 64, 96, 128 };
    return au8CntTbl[((u32Meta & KS_METADATA_SIZE_Msk) >> KS_METADATA_SIZE_Pos)];
}

/**
  * @brief      Write key to key store
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
  * @param[in]  u32Meta     The metadata of the key. It could be the combine of
                                \ref KS_META_AES
                                \ref KS_META_HMAC
                                \ref KS_META_RSA_EXP
                                \ref KS_META_RSA_MID
                                \ref KS_META_ECC
                                \ref KS_META_CPU
                                \ref KS_META_128
                                \ref KS_META_163
                                \ref KS_META_192
                                \ref KS_META_224
                                \ref KS_META_233
                                \ref KS_META_255
                                \ref KS_META_256
                                \ref KS_META_283
                                \ref KS_META_384
                                \ref KS_META_409
                                \ref KS_META_512
                                \ref KS_META_521
                                \ref KS_META_571
                                \ref KS_META_1024
                                \ref KS_META_2048
                                \ref KS_META_4096
                                \ref KS_META_BOOT
                                \ref KS_META_READABLE
                                \ref KS_META_PRIV
                                \ref KS_META_NONPRIV
                                \ref KS_META_SECURE
                                \ref KS_META_NONSECURE

  * @param[out] au32Key     The buffer to store the key
  * @return     Index of the key. Failed when index < 0.
  * @details    This function is used to write a key to key store.
  */

int32_t KS_Write(KS_MEM_Type eMemType, uint32_t u32Meta, uint32_t au32Key[])
{
    int32_t i32Cnt;
    uint32_t u32Cont;
    int32_t i, cnt;
    volatile int32_t offset;
    uint32_t u32TimeOutCount;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
    {
        //printf("KS->STS: 0x%08X\n", KS->STS);
        return KS_ERR_BUSY;
    }

    /* Specify the key address */
    KS->METADATA = (eMemType << KS_METADATA_DST_Pos) | u32Meta;

    /* Get size index */
    i32Cnt = (int32_t)KS_GetKeyWordCnt(u32Meta);

    /* Invalid key length */
    if (i32Cnt == 0)
        return KS_ERR_PARAMETER;

    /* OTP only support maximum 256 bits */
    if ((eMemType == KS_OTP) && (i32Cnt > 8))
        return KS_ERR_PARAMETER;

    offset = 0;
    u32Cont = 0;

    do
    {
        /* Prepare the key to write */
        cnt = i32Cnt;

        if (cnt > 8)
            cnt = 8;

        for (i = 0; i < cnt; i++)
        {
            KS->KEY[i] = au32Key[offset + i];
        }

        /* Clear Status */
        KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

        /* Write the key */
        KS->CTL = u32Cont | KS_OP_WRITE | KS_CTL_START_Msk | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

        u32Cont = KS_CTL_CONT_Msk;
        i32Cnt -= 8;
        offset += 8;

        /* Waiting for key store processing */
        u32TimeOutCount = KS_TIMEOUT;

        while (KS->STS & KS_STS_BUSY_Msk)
        {
            if (--u32TimeOutCount == 0)
                return KS_ERR_TIMEOUT;
        }

    } while (i32Cnt > 0);

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
    {
        return KS_ERR_FAIL;
    }

    return KS_TOKEYIDX(KS->METADATA);
}

/**
  * @brief      Erase a key from key store SRAM
  * @param[in]  i32KeyIdx   The key index to read
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to erase a key from SRAM of key store.
   */
int32_t KS_EraseKey(int32_t i32KeyIdx)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = (KS_SRAM << KS_METADATA_DST_Pos) | KS_TOMETAKEY(i32KeyIdx);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Erase the key */
    KS->CTL = KS_OP_ERASE | KS_CTL_START_Msk  | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

    /* Waiting for processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return KS_OK;
}


/**
  * @brief      Erase a key from key store OTP
  * @param[in]  i32KeyIdx   The key index to erase
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to erase a key from key store OTP.
   */
int32_t KS_EraseOTPKey(int32_t i32KeyIdx)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT; /* 1 second time-out */

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = ((uint32_t)KS_OTP << KS_METADATA_DST_Pos) | KS_TOMETAKEY(i32KeyIdx);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Erase the key */
    KS->CTL = KS_OP_ERASE | KS_CTL_START_Msk;

    /* Waiting for processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return KS_OK;
}


/**
  * @brief      Lock the OTP key
  * @param[in]  i32KeyIdx   The key index to lock
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to lock a key of KS OTP.
   */
int32_t KS_LockOTPKey(int32_t i32KeyIdx)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = ((uint32_t)KS_OTP << KS_METADATA_DST_Pos) | KS_TOMETAKEY(i32KeyIdx);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Erase the key */
    KS->CTL = KS_OP_LOCK | KS_CTL_START_Msk;

    /* Waiting for processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return KS_OK;
}


/**
  * @brief      Erase all keys from key store
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to erase all keys in SRAM or Flash of key store.
  */
int32_t KS_EraseAll(KS_MEM_Type eMemType)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = (eMemType << KS_METADATA_DST_Pos);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Erase the key */
    KS->CTL = KS_OP_ERASE_ALL | KS_CTL_START_Msk  | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

    /* Waiting for processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return KS_OK;
}


/**
  * @brief      Revoke a key in key store
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
                            \ref KS_OTP
  * @param[in]  i32KeyIdx   The key index to read
  * @retval     0           Successful
  * @retval     -1          Fail
  * @details    This function is used to revoke a key in key store.
  */
int32_t KS_RevokeKey(KS_MEM_Type eMemType, int32_t i32KeyIdx)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = (eMemType << KS_METADATA_DST_Pos) | KS_TOMETAKEY(i32KeyIdx);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Revoke the key */
    KS->CTL = KS_OP_REVOKE | KS_CTL_START_Msk | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

    /* Waiting for processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return KS_OK;
}


/**
  * @brief      Get remain size of specified Key Store memory
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
  * @retval     remain size of specified Key Store memory
  * @details    This function is used to get remain size of Key Store.
  */
uint32_t KS_GetRemainSize(KS_MEM_Type eMemType)
{
    if (eMemType == KS_SRAM)
        return (KS->REMAIN & KS_REMAIN_RRMNG_Msk) >> KS_REMAIN_RRMNG_Pos;
    else if (eMemType == KS_FLASH)
        return (KS->REMAIN & KS_REMAIN_FRMNG_Msk) >> KS_REMAIN_FRMNG_Pos;
    else
        return (uint32_t)KS_ERR_PARAMETER;
}


/**
  * @brief      Get remain key count of specified Key Store memory
  * @param[in]  eMemType    The memory type. It could be:
                            \ref KS_SRAM
                            \ref KS_FLASH
  * @retval     Remain key count in the specified key store memory
  * @details    This function is used to get remain key count in specified key store memory.
  */
uint32_t KS_GetRemainKeyCount(KS_MEM_Type eMemType)
{
    if (eMemType == KS_SRAM)
        return (KS->REMKCNT & KS_REMKCNT_RRMKCNT_Msk) >> KS_REMKCNT_RRMKCNT_Pos;
    else if (eMemType == KS_FLASH)
        return (KS->REMKCNT & KS_REMKCNT_FRMKCNT_Msk) >> KS_REMKCNT_FRMKCNT_Pos;
    else
        return (uint32_t)KS_ERR_PARAMETER;
}


/**
  * @brief      Write OTP key to key store
  * @param[in]  i32KeyIdx   The OTP key index to store the key. It could be 0~7.
                            OTP key index 0 is default for ROTPK.
  * @param[in]  u32Meta     The metadata of the key. It could be the combine of
                                \ref KS_META_AES
                                \ref KS_META_HMAC
                                \ref KS_META_RSA_EXP
                                \ref KS_META_RSA_MID
                                \ref KS_META_ECC
                                \ref KS_META_CPU
                                \ref KS_META_128
                                \ref KS_META_163
                                \ref KS_META_192
                                \ref KS_META_224
                                \ref KS_META_233
                                \ref KS_META_255
                                \ref KS_META_256
                                \ref KS_META_BOOT
                                \ref KS_META_READABLE
                                \ref KS_META_PRIV
                                \ref KS_META_NONPRIV
                                \ref KS_META_SECURE
                                \ref KS_META_NONSECURE

  * @param[out] au32Key     The buffer to store the key
  * @retval     Index of OTP key. Failed when index < 0.
  * @details    This function is used to write a key to OTP key store.
  */
int32_t KS_WriteOTP(int32_t i32KeyIdx, uint32_t u32Meta, uint32_t au32Key[])
{
    const uint16_t au8CntTbl[7] = { 4, 6, 6, 7, 8, 8, 8 };
    int32_t i32Cnt;
    int32_t offset, i, cnt, sidx;
    uint32_t u32TimeOutCount;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = ((uint32_t)KS_OTP << KS_METADATA_DST_Pos) | u32Meta | KS_TOMETAKEY(i32KeyIdx);

    /* Get size index */
    sidx = (u32Meta & KS_METADATA_SIZE_Msk) >> KS_METADATA_SIZE_Pos;

    /* OTP only support maximum 256 bits */
    if (sidx > (KS_META_256 >> KS_METADATA_SIZE_Pos))
        return KS_ERR_PARAMETER;

    i32Cnt = au8CntTbl[sidx];
    offset = 0;

    /* Prepare the key to write */
    cnt = i32Cnt;

    for (i = 0; i < cnt; i++)
    {
        KS->KEY[i] = au32Key[offset + i];
    }

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;

    /* Write the key */
    KS->CTL = KS_OP_WRITE | KS_CTL_START_Msk | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

    /* Waiting for key store processing */
    u32TimeOutCount = KS_TIMEOUT;

    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
    {
        return KS_ERR_FAIL;
    }

    return i32KeyIdx;
}

/**
  * @brief      Trigger to inverse the data in KS_SRAM.
  * @retval     1           The data in KS SRAM is inverted.
  * @retval     0           The data in KS SRAM is non-inverted.
  * @retval     -1          Fail to invert the data in KS SRAM.
  * @details    This function is used to trigger anti-remanence procedure by inverse the data in SRAM.
  *             This won't change the reading key.
  */

int32_t KS_ToggleSRAM(void)
{
    uint32_t u32TimeOutCount = KS_TIMEOUT;

    /* Just return when key store is in busy */
    if (KS->STS & KS_STS_BUSY_Msk)
        return KS_ERR_BUSY;

    /* Specify the key address */
    KS->METADATA = ((uint32_t)KS_SRAM << KS_METADATA_DST_Pos);

    /* Clear Status */
    KS->STS = KS_STS_EIF_Msk | KS_STS_IF_Msk;
    /* Trigger to do anti-remanence procedure */
    KS->CTL = KS_OP_REMAN | KS_CTL_START_Msk | (KS->CTL & (KS_CTL_SILENT_Msk | KS_CTL_SCMB_Msk));

    /* Waiting for key store processing */
    while (KS->STS & KS_STS_BUSY_Msk)
    {
        if (--u32TimeOutCount == 0)
            return KS_ERR_TIMEOUT;
    }

    /* Check error flag */
    if (KS->STS & KS_STS_EIF_Msk)
        return KS_ERR_FAIL;

    return ((KS->STS & KS_STS_RAMINV_Msk) > 0);
}

/** @} end of group KS_EXPORTED_FUNCTIONS */
/** @} end of group KS_Driver */
/** @} end of group Standard_Driver */
