// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vzext_vf4_u32mf2
// CHECK-RV64-SAME: (<vscale x 1 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vzext.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> poison, <vscale x 1 x i8> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vzext_vf4_u32mf2(vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32mf2(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vzext_vf4_u32m1
// CHECK-RV64-SAME: (<vscale x 2 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vzext.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> poison, <vscale x 2 x i8> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vzext_vf4_u32m1(vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m1(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vzext_vf4_u32m2
// CHECK-RV64-SAME: (<vscale x 4 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vzext.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> poison, <vscale x 4 x i8> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vzext_vf4_u32m2(vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m2(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vzext_vf4_u32m4
// CHECK-RV64-SAME: (<vscale x 8 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vzext.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> poison, <vscale x 8 x i8> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vzext_vf4_u32m4(vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m4(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vzext_vf4_u32m8
// CHECK-RV64-SAME: (<vscale x 16 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vzext.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> poison, <vscale x 16 x i8> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vzext_vf4_u32m8(vuint8m2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m8(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vzext_vf4_u64m1
// CHECK-RV64-SAME: (<vscale x 1 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> poison, <vscale x 1 x i16> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf4_u64m1(vuint16mf4_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m1(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vzext_vf4_u64m2
// CHECK-RV64-SAME: (<vscale x 2 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> poison, <vscale x 2 x i16> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf4_u64m2(vuint16mf2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m2(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vzext_vf4_u64m4
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> poison, <vscale x 4 x i16> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf4_u64m4(vuint16m1_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m4(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vzext_vf4_u64m8
// CHECK-RV64-SAME: (<vscale x 8 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> poison, <vscale x 8 x i16> [[OP1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf4_u64m8(vuint16m2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m8(op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vzext_vf4_u32mf2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vzext.mask.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> poison, <vscale x 1 x i8> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vzext_vf4_u32mf2_m(vbool64_t mask, vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32mf2_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vzext_vf4_u32m1_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vzext.mask.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> poison, <vscale x 2 x i8> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vzext_vf4_u32m1_m(vbool32_t mask, vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m1_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vzext_vf4_u32m2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vzext.mask.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> poison, <vscale x 4 x i8> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vzext_vf4_u32m2_m(vbool16_t mask, vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m2_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vzext_vf4_u32m4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vzext.mask.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> poison, <vscale x 8 x i8> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vzext_vf4_u32m4_m(vbool8_t mask, vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m4_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vzext_vf4_u32m8_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vzext.mask.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> poison, <vscale x 16 x i8> [[OP1]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vzext_vf4_u32m8_m(vbool4_t mask, vuint8m2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u32m8_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vzext_vf4_u64m1_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> poison, <vscale x 1 x i16> [[OP1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf4_u64m1_m(vbool64_t mask, vuint16mf4_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m1_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vzext_vf4_u64m2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.mask.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> poison, <vscale x 2 x i16> [[OP1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf4_u64m2_m(vbool32_t mask, vuint16mf2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m2_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vzext_vf4_u64m4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.mask.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> poison, <vscale x 4 x i16> [[OP1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf4_u64m4_m(vbool16_t mask, vuint16m1_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m4_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vzext_vf4_u64m8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i16> [[OP1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.mask.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> poison, <vscale x 8 x i16> [[OP1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf4_u64m8_m(vbool8_t mask, vuint16m2_t op1, size_t vl) {
  return __riscv_vzext_vf4_u64m8_m(mask, op1, vl);
}

