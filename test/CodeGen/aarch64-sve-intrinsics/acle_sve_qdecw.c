// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svqdecw_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecw_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecw_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_n_s32,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecw_n_s32_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecw_n_s32_1i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecw_n_s32_1(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_n_s32,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecw_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecw.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecw_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecw.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqdecw_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_n_s64,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecw_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecw_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqdecw_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_n_u32,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecw_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecw.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svqdecw_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecw.n64(i64 [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqdecw_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_n_u64,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecw_pat_n_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecw_pat_n_s32i(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.sqdecw.n32(i32 [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_svqdecw_pat_n_s32(int32_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_n_s32,,)(op, SV_ALL, 16);
}

// CHECK-LABEL: @test_svqdecw_pat_n_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecw.n64(i64 [[OP:%.*]], i32 0, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecw_pat_n_s64l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.sqdecw.n64(i64 [[OP:%.*]], i32 0, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
int64_t test_svqdecw_pat_n_s64(int64_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_n_s64,,)(op, SV_POW2, 1);
}

// CHECK-LABEL: @test_svqdecw_pat_n_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecw.n32(i32 [[OP:%.*]], i32 1, i32 16)
// CHECK-NEXT:    ret i32 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecw_pat_n_u32j(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.aarch64.sve.uqdecw.n32(i32 [[OP:%.*]], i32 1, i32 16)
// CPP-CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_svqdecw_pat_n_u32(uint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_n_u32,,)(op, SV_VL1, 16);
}

// CHECK-LABEL: @test_svqdecw_pat_n_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecw.n64(i64 [[OP:%.*]], i32 2, i32 1)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z22test_svqdecw_pat_n_u64m(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.uqdecw.n64(i64 [[OP:%.*]], i32 2, i32 1)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svqdecw_pat_n_u64(uint64_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_n_u64,,)(op, SV_VL2, 1);
}

// CHECK-LABEL: @test_svqdecw_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 31, i32 16)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqdecw_s32u11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 31, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svqdecw_s32(svint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_s32,,)(op, 16);
}

// CHECK-LABEL: @test_svqdecw_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 31, i32 1)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z16test_svqdecw_u32u12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 31, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svqdecw_u32(svuint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw,_u32,,)(op, 1);
}

// CHECK-LABEL: @test_svqdecw_pat_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 3, i32 16)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecw_pat_s32u11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.sqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 3, i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svint32_t test_svqdecw_pat_s32(svint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_s32,,)(op, SV_VL3, 16);
}

// CHECK-LABEL: @test_svqdecw_pat_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 4, i32 1)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svqdecw_pat_u32u12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.uqdecw.nxv4i32(<vscale x 4 x i32> [[OP:%.*]], i32 4, i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
svuint32_t test_svqdecw_pat_u32(svuint32_t op)
{
  return SVE_ACLE_FUNC(svqdecw_pat,_u32,,)(op, SV_VL4, 1);
}
