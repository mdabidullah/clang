// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-feature +d -target-feature +v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -passes=mem2reg | FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vget_v_i8m2_i8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv16i8(<vscale x 16 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vget_v_i8m2_i8m1(vint8m2_t src, size_t index) {
  return __riscv_vget_i8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i8m4_i8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv32i8(<vscale x 32 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vget_v_i8m4_i8m1(vint8m4_t src, size_t index) {
  return __riscv_vget_i8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i8m8_i8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vget_v_i8m8_i8m1(vint8m8_t src, size_t index) {
  return __riscv_vget_i8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i8m4_i8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vint8m2_t test_vget_v_i8m4_i8m2(vint8m4_t src, size_t index) {
  return __riscv_vget_i8m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i8m8_i8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vint8m2_t test_vget_v_i8m8_i8m2(vint8m8_t src, size_t index) {
  return __riscv_vget_i8m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i8m8_i8m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.vector.extract.nxv32i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vint8m4_t test_vget_v_i8m8_i8m4(vint8m8_t src, size_t index) {
  return __riscv_vget_i8m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m2_u8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv16i8(<vscale x 16 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vget_v_u8m2_u8m1(vuint8m2_t src, size_t index) {
  return __riscv_vget_u8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m4_u8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv32i8(<vscale x 32 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vget_v_u8m4_u8m1(vuint8m4_t src, size_t index) {
  return __riscv_vget_u8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m8_u8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.vector.extract.nxv8i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vget_v_u8m8_u8m1(vuint8m8_t src, size_t index) {
  return __riscv_vget_u8m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m4_u8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vget_v_u8m4_u8m2(vuint8m4_t src, size_t index) {
  return __riscv_vget_u8m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m8_u8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vget_v_u8m8_u8m2(vuint8m8_t src, size_t index) {
  return __riscv_vget_u8m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u8m8_u8m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.vector.extract.nxv32i8.nxv64i8(<vscale x 64 x i8> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vuint8m4_t test_vget_v_u8m8_u8m4(vuint8m8_t src, size_t index) {
  return __riscv_vget_u8m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m2_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv8i16(<vscale x 8 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vget_v_i16m2_i16m1(vint16m2_t src, size_t index) {
  return __riscv_vget_i16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m4_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv16i16(<vscale x 16 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vget_v_i16m4_i16m1(vint16m4_t src, size_t index) {
  return __riscv_vget_i16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m8_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vget_v_i16m8_i16m1(vint16m8_t src, size_t index) {
  return __riscv_vget_i16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m4_i16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vget_v_i16m4_i16m2(vint16m4_t src, size_t index) {
  return __riscv_vget_i16m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m8_i16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vget_v_i16m8_i16m2(vint16m8_t src, size_t index) {
  return __riscv_vget_i16m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i16m8_i16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.vector.extract.nxv16i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vget_v_i16m8_i16m4(vint16m8_t src, size_t index) {
  return __riscv_vget_i16m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m2_u16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv8i16(<vscale x 8 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vget_v_u16m2_u16m1(vuint16m2_t src, size_t index) {
  return __riscv_vget_u16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m4_u16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv16i16(<vscale x 16 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vget_v_u16m4_u16m1(vuint16m4_t src, size_t index) {
  return __riscv_vget_u16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m8_u16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.vector.extract.nxv4i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vget_v_u16m8_u16m1(vuint16m8_t src, size_t index) {
  return __riscv_vget_u16m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m4_u16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vget_v_u16m4_u16m2(vuint16m4_t src, size_t index) {
  return __riscv_vget_u16m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m8_u16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vget_v_u16m8_u16m2(vuint16m8_t src, size_t index) {
  return __riscv_vget_u16m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u16m8_u16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.vector.extract.nxv16i16.nxv32i16(<vscale x 32 x i16> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vget_v_u16m8_u16m4(vuint16m8_t src, size_t index) {
  return __riscv_vget_u16m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m2_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv4i32(<vscale x 4 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vget_v_i32m2_i32m1(vint32m2_t src, size_t index) {
  return __riscv_vget_i32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m4_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv8i32(<vscale x 8 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vget_v_i32m4_i32m1(vint32m4_t src, size_t index) {
  return __riscv_vget_i32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m8_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vget_v_i32m8_i32m1(vint32m8_t src, size_t index) {
  return __riscv_vget_i32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m4_i32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vget_v_i32m4_i32m2(vint32m4_t src, size_t index) {
  return __riscv_vget_i32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m8_i32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vget_v_i32m8_i32m2(vint32m8_t src, size_t index) {
  return __riscv_vget_i32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i32m8_i32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.vector.extract.nxv8i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vget_v_i32m8_i32m4(vint32m8_t src, size_t index) {
  return __riscv_vget_i32m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m2_u32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv4i32(<vscale x 4 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vget_v_u32m2_u32m1(vuint32m2_t src, size_t index) {
  return __riscv_vget_u32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m4_u32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv8i32(<vscale x 8 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vget_v_u32m4_u32m1(vuint32m4_t src, size_t index) {
  return __riscv_vget_u32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m8_u32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.vector.extract.nxv2i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vget_v_u32m8_u32m1(vuint32m8_t src, size_t index) {
  return __riscv_vget_u32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m4_u32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vget_v_u32m4_u32m2(vuint32m4_t src, size_t index) {
  return __riscv_vget_u32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m8_u32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vget_v_u32m8_u32m2(vuint32m8_t src, size_t index) {
  return __riscv_vget_u32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u32m8_u32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.vector.extract.nxv8i32.nxv16i32(<vscale x 16 x i32> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vget_v_u32m8_u32m4(vuint32m8_t src, size_t index) {
  return __riscv_vget_u32m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m2_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.vector.extract.nxv2f32.nxv4f32(<vscale x 4 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vget_v_f32m2_f32m1(vfloat32m2_t src, size_t index) {
  return __riscv_vget_f32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m4_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.vector.extract.nxv2f32.nxv8f32(<vscale x 8 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vget_v_f32m4_f32m1(vfloat32m4_t src, size_t index) {
  return __riscv_vget_f32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m8_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.vector.extract.nxv2f32.nxv16f32(<vscale x 16 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vget_v_f32m8_f32m1(vfloat32m8_t src, size_t index) {
  return __riscv_vget_f32m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m4_f32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vget_v_f32m4_f32m2(vfloat32m4_t src, size_t index) {
  return __riscv_vget_f32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m8_f32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vget_v_f32m8_f32m2(vfloat32m8_t src, size_t index) {
  return __riscv_vget_f32m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f32m8_f32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.vector.extract.nxv8f32.nxv16f32(<vscale x 16 x float> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vget_v_f32m8_f32m4(vfloat32m8_t src, size_t index) {
  return __riscv_vget_f32m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m2_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv2i64(<vscale x 2 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vget_v_i64m2_i64m1(vint64m2_t src, size_t index) {
  return __riscv_vget_i64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m4_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv4i64(<vscale x 4 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vget_v_i64m4_i64m1(vint64m4_t src, size_t index) {
  return __riscv_vget_i64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m8_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vget_v_i64m8_i64m1(vint64m8_t src, size_t index) {
  return __riscv_vget_i64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m4_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vget_v_i64m4_i64m2(vint64m4_t src, size_t index) {
  return __riscv_vget_i64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m8_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vget_v_i64m8_i64m2(vint64m8_t src, size_t index) {
  return __riscv_vget_i64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_i64m8_i64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.vector.extract.nxv4i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vget_v_i64m8_i64m4(vint64m8_t src, size_t index) {
  return __riscv_vget_i64m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m2_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv2i64(<vscale x 2 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vget_v_u64m2_u64m1(vuint64m2_t src, size_t index) {
  return __riscv_vget_u64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m4_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv4i64(<vscale x 4 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vget_v_u64m4_u64m1(vuint64m4_t src, size_t index) {
  return __riscv_vget_u64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m8_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.vector.extract.nxv1i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vget_v_u64m8_u64m1(vuint64m8_t src, size_t index) {
  return __riscv_vget_u64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m4_u64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vget_v_u64m4_u64m2(vuint64m4_t src, size_t index) {
  return __riscv_vget_u64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m8_u64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vget_v_u64m8_u64m2(vuint64m8_t src, size_t index) {
  return __riscv_vget_u64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_u64m8_u64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.vector.extract.nxv4i64.nxv8i64(<vscale x 8 x i64> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vget_v_u64m8_u64m4(vuint64m8_t src, size_t index) {
  return __riscv_vget_u64m4(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m2_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.vector.extract.nxv1f64.nxv2f64(<vscale x 2 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vget_v_f64m2_f64m1(vfloat64m2_t src, size_t index) {
  return __riscv_vget_f64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m4_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.vector.extract.nxv1f64.nxv4f64(<vscale x 4 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vget_v_f64m4_f64m1(vfloat64m4_t src, size_t index) {
  return __riscv_vget_f64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m8_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.vector.extract.nxv1f64.nxv8f64(<vscale x 8 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vget_v_f64m8_f64m1(vfloat64m8_t src, size_t index) {
  return __riscv_vget_f64m1(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m4_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vget_v_f64m4_f64m2(vfloat64m4_t src, size_t index) {
  return __riscv_vget_f64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m8_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vget_v_f64m8_f64m2(vfloat64m8_t src, size_t index) {
  return __riscv_vget_f64m2(src, 0);
}

// CHECK-RV64-LABEL: @test_vget_v_f64m8_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.vector.extract.nxv4f64.nxv8f64(<vscale x 8 x double> [[SRC:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vget_v_f64m8_f64m4(vfloat64m8_t src, size_t index) {
  return __riscv_vget_f64m4(src, 0);
}

