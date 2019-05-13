/*===------------ avx512bf16intrin.h - AVX512_BF16 intrinsics --------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
#ifndef __IMMINTRIN_H
#error "Never use <avx512bf16intrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef __AVX512BF16INTRIN_H
#define __AVX512BF16INTRIN_H

typedef short __m512bh __attribute__((__vector_size__(64), __aligned__(64)));
typedef short __m256bh __attribute__((__vector_size__(32), __aligned__(32)));

#define __DEFAULT_FN_ATTRS512 \
  __attribute__((__always_inline__, __nodebug__, __target__("avx512bf16"), \
                 __min_vector_width__(512)))

/// Convert Two Packed Single Data to One Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNE2PS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \param __B
///    A 512-bit vector of [16 x float].
/// \returns A 512-bit vector of [32 x bfloat] whose lower 256 bits come from
///    convertion of src2, and higher 256 bits come from conversion of src1.
static __inline__ __m512bh __DEFAULT_FN_ATTRS512
_mm512_cvtne2ps_pbh(__m512 __A, __m512 __B) {
  return (__m512bh)__builtin_ia32_cvtne2ps2bf16_512((__v16sf) __A,
                                                    (__v16sf) __B);
}

/// Convert Two Packed Single Data to One Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNE2PS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \param __B
///    A 512-bit vector of [16 x float].
/// \param __W
///    A 512-bit vector of [32 x bfloat].
/// \param __U
///    An immediate value containing an 32-bit value specifying which element
///    is choosed. 1 means __A or __B, 0 means __W.
/// \returns A 512-bit vector of [32 x bfloat] whose lower 256 bits come from
///    convertion of src2, and higher 256 bits come from conversion of src1.
static __inline__ __m512bh __DEFAULT_FN_ATTRS512
_mm512_mask_cvtne2ps_pbh(__m512bh __W, __mmask32 __U, __m512 __A, __m512 __B) {
  return (__m512bh)__builtin_ia32_selectw_512((__mmask32)__U,
                                        (__v32hi)_mm512_cvtne2ps_pbh(__A, __B),
                                        (__v32hi)__W);
}

/// Convert Two Packed Single Data to One Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNE2PS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \param __B
///    A 512-bit vector of [16 x float].
/// \param __U
///    An immediate value containing an 32-bit value specifying which element
///    is choosed. 1 means __A or __B, 0 means zero.
/// \returns A 512-bit vector of [32 x bfloat] whose lower 256 bits come from
///    convertion of src2, and higher 256 bits come from conversion of src1.
static __inline__ __m512bh __DEFAULT_FN_ATTRS512
_mm512_maskz_cvtne2ps_pbh(__mmask32 __U, __m512 __A, __m512 __B) {
  return (__m512bh)__builtin_ia32_selectw_512((__mmask32)__U,
                                        (__v32hi)_mm512_cvtne2ps_pbh(__A, __B),
                                        (__v32hi)_mm512_setzero_si512());
}

/// Convert Packed Single Data to Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNEPS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \returns A 256-bit vector of [16 x bfloat] come from convertion of src
static __inline__ __m256bh __DEFAULT_FN_ATTRS512
_mm512_cvtneps_pbh(__m512 __A) {
  return (__m256bh)__builtin_ia32_cvtneps2bf16_512((__v16sf) __A);
}

/// Convert Packed Single Data to Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNEPS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \param __W
///    A 256-bit vector of [16 x bfloat].
/// \param __U
///    An immediate value containing an 16-bit value specifying which element
///    is choosed. 1 means __A, 0 means __W.
/// \returns A 256-bit vector of [16 x bfloat] come from convertion of src
static __inline__ __m256bh __DEFAULT_FN_ATTRS512
_mm512_mask_cvtneps_pbh(__m256bh __W, __mmask16 __U, __m512 __A) {
  return (__m256bh)__builtin_ia32_selectw_256((__mmask16)__U,
                                              (__v16hi)_mm512_cvtneps_pbh(__A),
                                              (__v16hi)__W);
}

/// Convert Packed Single Data to Packed BF16 Data.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VCVTNEPS2BF16 </c> instructions.
///
/// \param __A
///    A 512-bit vector of [16 x float].
/// \param __U
///    An immediate value containing an 16-bit value specifying which element
///    is choosed. 1 means __A, 0 means zero.
/// \returns A 256-bit vector of [16 x bfloat] come from convertion of src
static __inline__ __m256bh __DEFAULT_FN_ATTRS512
_mm512_maskz_cvtneps_pbh(__mmask16 __U, __m512 __A) {
  return (__m256bh)__builtin_ia32_selectw_256((__mmask16)__U,
                                              (__v16hi)_mm512_cvtneps_pbh(__A),
                                              (__v16hi)_mm256_setzero_si256());
}

/// Dot Product of BF16 Pairs Accumulated into Packed Single Precision.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VDPBF16PS </c> instructions.
///
/// \param __A
///    A 512-bit vector of [32 x bfloat].
/// \param __B
///    A 512-bit vector of [32 x bfloat].
/// \param __D
///    A 512-bit vector of [16 x float].
/// \returns A 512-bit vector of [16 x float] comes from  Dot Product of
///  __A, __B and __D
static __inline__ __m512 __DEFAULT_FN_ATTRS512
_mm512_dpbf16_ps(__m512 __D, __m512bh __A, __m512bh __B) {
  return (__m512)__builtin_ia32_dpbf16ps_512((__v16sf) __D,
                                             (__v16si) __A,
                                             (__v16si) __B);
}

/// Dot Product of BF16 Pairs Accumulated into Packed Single Precision.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VDPBF16PS </c> instructions.
///
/// \param __A
///    A 512-bit vector of [32 x bfloat].
/// \param __B
///    A 512-bit vector of [32 x bfloat].
/// \param __D
///    A 512-bit vector of [16 x float].
/// \param __U
///    An immediate value containing an 16-bit value specifying which element
///    is choosed. 1 means __A and __B's dot product, 0 means __D.
/// \returns A 512-bit vector of [16 x float] comes from  Dot Product of
///  __A, __B and __D
static __inline__ __m512 __DEFAULT_FN_ATTRS512
_mm512_mask_dpbf16_ps(__m512 __D, __mmask16 __U, __m512bh __A, __m512bh __B) {
  return (__m512)__builtin_ia32_selectps_512((__mmask16)__U,
                                       (__v16sf)_mm512_dpbf16_ps(__D, __A, __B),
                                       (__v16sf)__D);
}

/// Dot Product of BF16 Pairs Accumulated into Packed Single Precision.
///
/// \headerfile <x86intrin.h>
///
/// This intrinsic corresponds to the <c> VDPBF16PS </c> instructions.
///
/// \param __A
///    A 512-bit vector of [32 x bfloat].
/// \param __B
///    A 512-bit vector of [32 x bfloat].
/// \param __D
///    A 512-bit vector of [16 x float].
/// \param __U
///    An immediate value containing an 16-bit value specifying which element
///    is choosed. 1 means __A and __B's dot product, 0 means 0.
/// \returns A 512-bit vector of [16 x float] comes from  Dot Product of
///  __A, __B and __D
static __inline__ __m512 __DEFAULT_FN_ATTRS512
_mm512_maskz_dpbf16_ps(__mmask16 __U, __m512 __D, __m512bh __A, __m512bh __B) {
  return (__m512)__builtin_ia32_selectps_512((__mmask16)__U,
                                       (__v16sf)_mm512_dpbf16_ps(__D, __A, __B),
                                       (__v16sf)_mm512_setzero_si512());
}

#undef __DEFAULT_FN_ATTRS512

#endif