// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DTEST_SME2 -triple aarch64 -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve2p1 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s\
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DTEST_SME -triple aarch64 -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s \
// RUN: | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -DTEST_SME2 -triple aarch64 -target-feature +sme2 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

#ifndef TEST_SME2
#define ATTR
#else
#define ATTR __arm_streaming
#endif

// CHECK-LABEL: @test_svcreate2_b(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> poison, <vscale x 16 x i1> [[X0:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TMP0]], <vscale x 16 x i1> [[X1:%.*]], i64 16)
// CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z16test_svcreate2_bu10__SVBool_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> poison, <vscale x 16 x i1> [[X0:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 32 x i1> @llvm.vector.insert.nxv32i1.nxv16i1(<vscale x 32 x i1> [[TMP0]], <vscale x 16 x i1> [[X1:%.*]], i64 16)
// CPP-CHECK-NEXT:    ret <vscale x 32 x i1> [[TMP1]]
//
svboolx2_t test_svcreate2_b(svbool_t x0, svbool_t x1) ATTR
{
  return SVE_ACLE_FUNC(svcreate2,_b,,)(x0, x1);
}
