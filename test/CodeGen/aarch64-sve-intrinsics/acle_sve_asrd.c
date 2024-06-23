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

// CHECK-LABEL: @test_svasrd_n_s8_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = select <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> zeroinitializer
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG]], <vscale x 16 x i8> [[TMP0]], i32 1)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z18test_svasrd_n_s8_zu10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = select <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG]], <vscale x 16 x i8> [[TMP0]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
svint8_t test_svasrd_n_s8_z(svbool_t pg, svint8_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s8,_z,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s8_z_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = select <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> zeroinitializer
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG]], <vscale x 16 x i8> [[TMP0]], i32 8)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z20test_svasrd_n_s8_z_1u10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = select <vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i8> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG]], <vscale x 16 x i8> [[TMP0]], i32 8)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
svint8_t test_svasrd_n_s8_z_1(svbool_t pg, svint8_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s8,_z,)(pg, op1, 8);
}

// CHECK-LABEL: @test_svasrd_n_s16_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[TMP1]], i32 1)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s16_zu10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[TMP1]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP2]]
//
svint16_t test_svasrd_n_s16_z(svbool_t pg, svint16_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s16,_z,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s16_z_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[TMP1]], i32 16)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z21test_svasrd_n_s16_z_1u10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i16> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[TMP1]], i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP2]]
//
svint16_t test_svasrd_n_s16_z_1(svbool_t pg, svint16_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s16,_z,)(pg, op1, 16);
}

// CHECK-LABEL: @test_svasrd_n_s32_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[TMP1]], i32 1)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s32_zu10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[TMP1]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP2]]
//
svint32_t test_svasrd_n_s32_z(svbool_t pg, svint32_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s32,_z,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s32_z_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[TMP1]], i32 32)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z21test_svasrd_n_s32_z_1u10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], <vscale x 4 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[TMP1]], i32 32)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP2]]
//
svint32_t test_svasrd_n_s32_z_1(svbool_t pg, svint32_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s32,_z,)(pg, op1, 32);
}

// CHECK-LABEL: @test_svasrd_n_s64_z(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[TMP1]], i32 1)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s64_zu10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[TMP1]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svasrd_n_s64_z(svbool_t pg, svint64_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s64,_z,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s64_z_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[TMP1]], i32 64)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z21test_svasrd_n_s64_z_1u10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = select <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], <vscale x 2 x i64> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[TMP1]], i32 64)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svasrd_n_s64_z_1(svbool_t pg, svint64_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s64,_z,)(pg, op1, 64);
}

// CHECK-LABEL: @test_svasrd_n_s8_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i32 1)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svasrd_n_s8_mu10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svasrd_n_s8_m(svbool_t pg, svint8_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s8,_m,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s16_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], i32 1)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s16_mu10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
svint16_t test_svasrd_n_s16_m(svbool_t pg, svint16_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s16,_m,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s32_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], i32 1)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s32_mu10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svasrd_n_s32_m(svbool_t pg, svint32_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s32,_m,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s64_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], i32 1)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s64_mu10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svasrd_n_s64_m(svbool_t pg, svint64_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s64,_m,)(pg, op1, 1);
}

// CHECK-LABEL: @test_svasrd_n_s8_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i32 8)
// CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z18test_svasrd_n_s8_xu10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.aarch64.sve.asrd.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i32 8)
// CPP-CHECK-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
svint8_t test_svasrd_n_s8_x(svbool_t pg, svint8_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s8,_x,)(pg, op1, 8);
}

// CHECK-LABEL: @test_svasrd_n_s16_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], i32 16)
// CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s16_xu10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.aarch64.sve.asrd.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP1:%.*]], i32 16)
// CPP-CHECK-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
svint16_t test_svasrd_n_s16_x(svbool_t pg, svint16_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s16,_x,)(pg, op1, 16);
}

// CHECK-LABEL: @test_svasrd_n_s32_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], i32 32)
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s32_xu10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.aarch64.sve.asrd.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP1:%.*]], i32 32)
// CPP-CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
svint32_t test_svasrd_n_s32_x(svbool_t pg, svint32_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s32,_x,)(pg, op1, 32);
}

// CHECK-LABEL: @test_svasrd_n_s64_x(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], i32 64)
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z19test_svasrd_n_s64_xu10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.aarch64.sve.asrd.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP1:%.*]], i32 64)
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
svint64_t test_svasrd_n_s64_x(svbool_t pg, svint64_t op1)
{
  return SVE_ACLE_FUNC(svasrd,_n_s64,_x,)(pg, op1, 64);
}
