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

// CHECK-LABEL: @test_svstnt1_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svstnt1_s8u10__SVBool_tPau10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_s8(svbool_t pg, int8_t *base, svint8_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_s8,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_s16u10__SVBool_tPsu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_s16(svbool_t pg, int16_t *base, svint16_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_s16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_s32u10__SVBool_tPiu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_s32(svbool_t pg, int32_t *base, svint32_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_s32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_s64u10__SVBool_tPlu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_s64(svbool_t pg, int64_t *base, svint64_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_s64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svstnt1_u8u10__SVBool_tPhu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_u8(svbool_t pg, uint8_t *base, svuint8_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_u8,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_u16u10__SVBool_tPtu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_u16(svbool_t pg, uint16_t *base, svuint16_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_u16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_u32u10__SVBool_tPju12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_u32(svbool_t pg, uint32_t *base, svuint32_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_u32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_u64u10__SVBool_tPmu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_u64(svbool_t pg, uint64_t *base, svuint64_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_u64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8f16(<vscale x 8 x half> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_f16u10__SVBool_tPDhu13__SVFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8f16(<vscale x 8 x half> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_f16(svbool_t pg, float16_t *base, svfloat16_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_f16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4f32(<vscale x 4 x float> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_f32u10__SVBool_tPfu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4f32(<vscale x 4 x float> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_f32(svbool_t pg, float32_t *base, svfloat32_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_f32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2f64(<vscale x 2 x double> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z16test_svstnt1_f64u10__SVBool_tPdu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2f64(<vscale x 2 x double> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_f64(svbool_t pg, float64_t *base, svfloat64_t data)
{
  return SVE_ACLE_FUNC(svstnt1,_f64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP0]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svstnt1_vnum_s8u10__SVBool_tPalu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP0]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_s8(svbool_t pg, int8_t *base, int64_t vnum, svint8_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_s8,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_s16u10__SVBool_tPslu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_s16(svbool_t pg, int16_t *base, int64_t vnum, svint16_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_s16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_s32u10__SVBool_tPilu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_s32(svbool_t pg, int32_t *base, int64_t vnum, svint32_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_s32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_s64u10__SVBool_tPllu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_s64(svbool_t pg, int64_t *base, int64_t vnum, svint64_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_s64,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP0]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svstnt1_vnum_u8u10__SVBool_tPhlu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv16i8(<vscale x 16 x i8> [[DATA:%.*]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP0]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_u8(svbool_t pg, uint8_t *base, int64_t vnum, svuint8_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_u8,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_u16u10__SVBool_tPtlu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8i16(<vscale x 8 x i16> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_u16(svbool_t pg, uint16_t *base, int64_t vnum, svuint16_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_u16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_u32u10__SVBool_tPjlu12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4i32(<vscale x 4 x i32> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_u32(svbool_t pg, uint32_t *base, int64_t vnum, svuint32_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_u32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_u64u10__SVBool_tPmlu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2i64(<vscale x 2 x i64> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_u64(svbool_t pg, uint64_t *base, int64_t vnum, svuint64_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_u64,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x half>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8f16(<vscale x 8 x half> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_f16u10__SVBool_tPDhlu13__SVFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x half>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv8f16(<vscale x 8 x half> [[DATA:%.*]], <vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_f16(svbool_t pg, float16_t *base, int64_t vnum, svfloat16_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_f16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x float>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4f32(<vscale x 4 x float> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_f32u10__SVBool_tPflu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 4 x float>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv4f32(<vscale x 4 x float> [[DATA:%.*]], <vscale x 4 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_f32(svbool_t pg, float32_t *base, int64_t vnum, svfloat32_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_f32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svstnt1_vnum_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x double>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2f64(<vscale x 2 x double> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z21test_svstnt1_vnum_f64u10__SVBool_tPdlu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 2 x double>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.stnt1.nxv2f64(<vscale x 2 x double> [[DATA:%.*]], <vscale x 2 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    ret void
//
void test_svstnt1_vnum_f64(svbool_t pg, float64_t *base, int64_t vnum, svfloat64_t data)
{
  return SVE_ACLE_FUNC(svstnt1_vnum,_f64,,)(pg, base, vnum, data);
}
