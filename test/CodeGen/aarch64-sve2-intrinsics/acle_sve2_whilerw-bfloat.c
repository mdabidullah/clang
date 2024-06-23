// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2 -target-feature +bf16 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2 -target-feature +bf16 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve2 -target-feature +bf16 -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve2 -target-feature +bf16 -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svwhilerw_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.whilerw.h.nxv8i1.p0(ptr [[OP1:%.*]], ptr [[OP2:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv8i1(<vscale x 8 x i1> [[TMP0]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svwhilerw_bf16PKu6__bf16S0_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.whilerw.h.nxv8i1.p0(ptr [[OP1:%.*]], ptr [[OP2:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv8i1(<vscale x 8 x i1> [[TMP0]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP1]]
//
svbool_t test_svwhilerw_bf16(const bfloat16_t *op1, const bfloat16_t *op2)
{
  return SVE_ACLE_FUNC(svwhilerw,_bf16,,)(op1, op2);
}
