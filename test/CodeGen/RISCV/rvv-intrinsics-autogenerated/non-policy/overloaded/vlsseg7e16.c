// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } @test_vlsseg7e16_v_f16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } @llvm.riscv.vlsseg7.mask.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]]
//
vfloat16mf4x7_t test_vlsseg7e16_v_f16mf4x7_m(vbool64_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } @test_vlsseg7e16_v_f16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } @llvm.riscv.vlsseg7.mask.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]]
//
vfloat16mf2x7_t test_vlsseg7e16_v_f16mf2x7_m(vbool32_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } @test_vlsseg7e16_v_f16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } @llvm.riscv.vlsseg7.mask.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]]
//
vfloat16m1x7_t test_vlsseg7e16_v_f16m1x7_m(vbool16_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @test_vlsseg7e16_v_i16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlsseg7.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]]
//
vint16mf4x7_t test_vlsseg7e16_v_i16mf4x7_m(vbool64_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @test_vlsseg7e16_v_i16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlsseg7.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]]
//
vint16mf2x7_t test_vlsseg7e16_v_i16mf2x7_m(vbool32_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @test_vlsseg7e16_v_i16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlsseg7.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]]
//
vint16m1x7_t test_vlsseg7e16_v_i16m1x7_m(vbool16_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @test_vlsseg7e16_v_u16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlsseg7.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]]
//
vuint16mf4x7_t test_vlsseg7e16_v_u16mf4x7_m(vbool64_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @test_vlsseg7e16_v_u16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlsseg7.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]]
//
vuint16mf2x7_t test_vlsseg7e16_v_u16mf2x7_m(vbool32_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @test_vlsseg7e16_v_u16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlsseg7.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]]
//
vuint16m1x7_t test_vlsseg7e16_v_u16m1x7_m(vbool16_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg7e16(mask, base, bstride, vl);
}

