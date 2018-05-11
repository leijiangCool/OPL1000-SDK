/**
 * @file api_val_result.h
 *
 * @brief VAL API - Function Result Codes
 */

/*****************************************************************************
* Copyright (c) 2014-2017 INSIDE Secure B.V. All Rights Reserved.
*
* This confidential and proprietary software may be used only as authorized
* by a licensing agreement from INSIDE Secure.
*
* The entire notice above must be reproduced on all authorized copies that
* may only be made to the extent permitted by a licensing agreement from
* INSIDE Secure.
*
* For more information or support, please go to our online support system at
* https://customersupport.insidesecure.com.
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef INCLUDE_GUARD_API_VAL_RESULT_H
#define INCLUDE_GUARD_API_VAL_RESULT_H

/*----------------------------------------------------------------------------
 * Definitions and macros
 */
/** ValStatus_t\n
 *  The types can be used in pointer-parameter declarations to clarify the
 *  direction of the parameter (input-only, output-only or input-output).
 *  Use the _Optional variant when the pointer parameter may be NULL.
 */
typedef enum
{
    /** [1 .. 127]: The reserved for propagating the VaultIP firmware warnings */

    /** TRNG related warnings [64 ... 95]:\n
     * - Aprop fail\n
     * - Repcount fail\n
     * - Stuck NRBG\n
     * - Stuck output */

    /** DMA related warnings [32 ... 63]: None expected */

    /** Firmware related warnings [1 ... 31]: */
    VAL_WARNING_Z1USED = 16,            /** Z=1 is used */

    /** Success */
    VAL_SUCCESS = 0,                    /** No error */

    /** [-1 .. -137]: The reserved for propagating the VaultIP firmware error */
    /** Firmware related errors [-1 ... -31]: */
    VAL_INVALID_TOKEN = -1,             /** Invalid token */
    VAL_INVALID_PARAMETER = -2,         /** Invalid parameter */
    VAL_INVALID_KEYSIZE = -3,           /** Invalid key size */
    VAL_INVALID_LENGTH = -4,            /** Invalid length */
    VAL_INVALID_LOCATION = -5,          /** Invalid location */
    VAL_CLOCK_ERROR = -6,               /** Clock error */
    VAL_ACCESS_ERROR = -7,              /** Access error */
    VAL_UNWRAP_ERROR = -10,             /** Unwrap error */
    VAL_DATA_OVERRUN_ERROR = -11,       /** Data overrun error */
    VAL_ASSET_CHECKSUM_ERROR = -12,     /** Asset checksum error */
    VAL_INVALID_ASSET = -13,            /** Invalid Asset */
    VAL_FULL_ERROR = -14,               /** Full/Overflow error */
    VAL_INVALID_ADDRESS = -15,          /** Invalid address */
    VAL_INVALID_MODULUS = -17,          /** Invalid Modulus */
    VAL_VERIFY_ERROR = -18,             /** Verify error */
    VAL_INVALID_STATE = -19,            /** Invalid state */
    VAL_OTP_WRITE_ERROR = -20,          /** OTP write error */
    VAL_PANIC_ERROR = -31,              /** Panic error */

    /** DMA related errors are bus related [-32 ... -63] */

    /** TRNG related errors [-64 ... -95]: */
    VAL_TRNG_SHUTDOWN_ERROR = -65,      /** Too many FROs shutdown */
    VAL_DRBG_STUCK_ERROR = -66,         /** Stuck DRBG */

    /** VAL related errors [-128 ... -137]: */
    VAL_UNSUPPORTED = -128,             /** Not supported */
    VAL_NOT_INITIALIZED = -129,         /** Not initialized yet */
    VAL_BAD_ARGUMENT = -130,            /** Wrong use; not depending on configuration */
    VAL_INVALID_ALGORITHM = -131,       /** Invalid algorithm code */
    VAL_INVALID_MODE = -132,            /** Invalid mode code */
    VAL_BUFFER_TOO_SMALL = -133,        /** Provided buffer too small for intended use */
    VAL_NO_MEMORY = -134,               /** No memory */
    VAL_OPERATION_FAILED = -135,        /** Operation failed */
    VAL_TIMEOUT_ERROR = -136,           /** Token or data timeout error */
    VAL_INTERNAL_ERROR = -137,          /** Internal error */
} ValStatus_t;


#endif /* Include Guard */

/* end of file api_val_result.h */
