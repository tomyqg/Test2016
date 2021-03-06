/*
 * Copyright � 1996-2011 Certicom Corp. All rights reserved.
 * 
 * This software contains trade secrets, confidential information, and other
 * intellectual property of Certicom Corp. and its licensors. This software
 * cannot be used, reproduced, or distributed in whole or in part by any means
 * without the explicit prior consent of Certicom Corp. Such consent must arise
 * from a separate license agreement from Certicom or its licensees, as 
 * appropriate.
 * 
 * Certicom, Certicom AMS, ACC, Asset Control Core, Certicom Bar Code
 * Authentication Agent, Certicom ECC Core, Certicom Security Architecture,
 * Certicom Trusted Infrastructure, Certicom CodeSign, Certicom KeyInject,
 * ChipActivate, DieMax, Security Builder, Security Builder API, 
 * Security Builder API for .NET, Security Builder BSP, Security Builder Crypto,
 * Security Builder ETS, Security Builder GSE, Security Builder IPSec, Security
 * Builder MCE, Security Builder NSE, Security Builder PKI, Security Builder SSL
 * and SysActivate are trademarks or registered trademarks of Certicom Corp.
 * All other companies and products listed herein are trademarks or registered
 * trademarks of their respective holders.
 *
 * BlackBerry�, RIM�, Research In Motion� and related trademarks are owned by
 * Research In Motion Limited. Used under license.
 * 
 * Certicom Corp. has intellectual property rights relating to technology
 * embodied in the product that is described in this document. In particular,
 * and without limitation, these intellectual property rights may include one or
 * more of the U.S. and non-U.S. patents listed at www.certicom.com/patents and
 * one or more additional patents or pending patent applications in the U.S. and
 * in other countries. Information subject to change.
 *
 */
 * $Source: Includes/huseed.h $
 * $Name:  $
 */
#ifndef HUSEED_H
#define HUSEED_H

/** @file */

#include "sbdef.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup hula_seed
 *
 * @{
 *
 */

/**
 * Generates a PRNG seed in a system-dependent way.
 *
 * A PRNG must be initialized with a random seed. The seed must be generated
 * in a system-dependent way, from available sources of entropy. Since
 * the system entropy is unlikely to change quickly, the seed should be 
 * generated only once, and used to create a long-living PRNG.
 * Reseeding the RNG context with whatever new entropy is collected is
 * excellent practice.
 *
 * This function does not require any register function to be called
 * before its use.
 *
 * @param seedLen [Input/Output] The size of the buffer on being called, the 
 *                               size of the seed written upon return. It can 
 *                               be smaller than that requested.
 * @param seed    [Output]       A buffer to store the seed in.
 * @param sbCtx   [Input]        An SB global context. No crypto support is 
 *                               required to be registered; this context will 
 *                               be used only for the memory callbacks.
 *
 * @retval SB_ERR_NULL_OUTPUT             <tt>seed</tt> is <tt>NULL</tt>.
 * @retval SB_ERR_NULL_OUTPUT_BUF_LEN_PTR <tt>seedLen</tt> is <tt>NULL</tt>.
 * @retval SB_ERR_NULL_OUTPUT_BUF_LEN     <tt>*seedSz</tt> is <tt>NULL</tt>.
 * @retval SB_ERR_NULL_GLOBAL_CTX         <tt>sbCtx</tt> is <tt>NULL</tt>.
 */
extern
SB_EXPORT
int
SB_CALLCONV
hu_SeedFromSystem(
    size_t* seedLen, 
    unsigned char* seed, 
    sb_GlobalCtx sbCtx
);

/** Generates a PRNG seed in a system-dependent way. 

The seeding source must be registered in the global context prior 
to this call.

A PRNG must be initialized with a random seed. The seed must be generated
in a system-dependent way, from available sources of entropy. Since
the system entropy is unlikely to change quickly, the seed should be 
generated only once, and used to create a long-living PRNG.
Reseeding the RNG context with whatever new entropy is collected is
excellent practice.

@param seedLen [Input/Output] The size of the buffer on being called, the size 
                              of the seed written upon return. It can be 
			      smaller than that requested.
@param seed    [Output]       A buffer to store the seed in.
@param sbCtx   [Input]        A global context. 

@retval SB_ERR_NULL_OUTPUT             <tt>seed</tt> is <tt>NULL</tt>.
@retval SB_ERR_NULL_OUTPUT_BUF_LEN_PTR <tt>seedLen</tt> is <tt>NULL</tt>.
@retval SB_ERR_NULL_OUTPUT_BUF_LEN     <tt>*seedSz</tt> is <tt>NULL</tt>.
@retval SB_ERR_NULL_GLOBAL_CTX         <tt>sbCtx</tt> is <tt>NULL</tt>.
@retval SB_ERR_SEED_NOT_SUPPORTED      A seeding source is not registered in 
                                       the SB global context <tt>sbCtx</tt>.
*/
extern
SB_EXPORT
int
SB_CALLCONV
hu_SeedGet(
    size_t* seedLen, 
    unsigned char* seed, 
    sb_GlobalCtx sbCtx
);

/** Enables support to generic system-specific sources of seed (i.e. the same 
 * ones used in <tt>hu_SeedFromSystem()</tt>).

$FunctionListBegin
This function enables the following function(s) to be called:
<ul>
  <li>hu_SeedGet()
</ul>
$FunctionListEnd

@param sbCtx [Input] A global context.
*/

extern
SB_EXPORT
int
SB_CALLCONV
hu_RegisterSystemSeed(
    sb_GlobalCtx sbCtx
);

/** @} */

#ifdef __cplusplus
}
#endif

#endif

