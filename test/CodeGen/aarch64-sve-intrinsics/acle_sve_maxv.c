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

// CHECK-LABEL: @test_svmaxv_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i8 @llvm.aarch64.sve.smaxv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret i8 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svmaxv_s8u10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i8 @llvm.aarch64.sve.smaxv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i8 [[TMP0]]
//
int8_t test_svmaxv_s8(svbool_t pg, svint8_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_s8,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i16 @llvm.aarch64.sve.smaxv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret i16 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_s16u10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i16 @llvm.aarch64.sve.smaxv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i16 [[TMP1]]
//
int16_t test_svmaxv_s16(svbool_t pg, svint16_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_s16,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i32 @llvm.aarch64.sve.smaxv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret i32 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_s32u10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i32 @llvm.aarch64.sve.smaxv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i32 [[TMP1]]
//
int32_t test_svmaxv_s32(svbool_t pg, svint32_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_s32,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.aarch64.sve.smaxv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret i64 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_s64u10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.aarch64.sve.smaxv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i64 [[TMP1]]
//
int64_t test_svmaxv_s64(svbool_t pg, svint64_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_s64,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i8 @llvm.aarch64.sve.umaxv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret i8 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svmaxv_u8u10__SVBool_tu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i8 @llvm.aarch64.sve.umaxv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i8 [[TMP0]]
//
uint8_t test_svmaxv_u8(svbool_t pg, svuint8_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_u8,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i16 @llvm.aarch64.sve.umaxv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret i16 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_u16u10__SVBool_tu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i16 @llvm.aarch64.sve.umaxv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i16 [[TMP1]]
//
uint16_t test_svmaxv_u16(svbool_t pg, svuint16_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_u16,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i32 @llvm.aarch64.sve.umaxv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret i32 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_u32u10__SVBool_tu12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i32 @llvm.aarch64.sve.umaxv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i32 [[TMP1]]
//
uint32_t test_svmaxv_u32(svbool_t pg, svuint32_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_u32,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.aarch64.sve.umaxv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret i64 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_u64u10__SVBool_tu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.aarch64.sve.umaxv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i64 [[TMP1]]
//
uint64_t test_svmaxv_u64(svbool_t pg, svuint64_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_u64,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call half @llvm.aarch64.sve.fmaxv.nxv8f16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x half> [[OP:%.*]])
// CHECK-NEXT:    ret half [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_f16u10__SVBool_tu13__SVFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call half @llvm.aarch64.sve.fmaxv.nxv8f16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x half> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret half [[TMP1]]
//
float16_t test_svmaxv_f16(svbool_t pg, svfloat16_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_f16,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call float @llvm.aarch64.sve.fmaxv.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP:%.*]])
// CHECK-NEXT:    ret float [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_f32u10__SVBool_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call float @llvm.aarch64.sve.fmaxv.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret float [[TMP1]]
//
float32_t test_svmaxv_f32(svbool_t pg, svfloat32_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_f32,,)(pg, op);
}

// CHECK-LABEL: @test_svmaxv_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call double @llvm.aarch64.sve.fmaxv.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP:%.*]])
// CHECK-NEXT:    ret double [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svmaxv_f64u10__SVBool_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call double @llvm.aarch64.sve.fmaxv.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret double [[TMP1]]
//
float64_t test_svmaxv_f64(svbool_t pg, svfloat64_t op)
{
  return SVE_ACLE_FUNC(svmaxv,_f64,,)(pg, op);
}
