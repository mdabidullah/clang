// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1f16.i64(<vscale x 1 x half> [[TMP0]], <vscale x 1 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf4x2(_Float16 *base, ptrdiff_t bstride, vfloat16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2f16.i64(<vscale x 2 x half> [[TMP0]], <vscale x 2 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf2x2(_Float16 *base, ptrdiff_t bstride, vfloat16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4f16.i64(<vscale x 4 x half> [[TMP0]], <vscale x 4 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m1x2(_Float16 *base, ptrdiff_t bstride, vfloat16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m1x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8f16.i64(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m2x2(_Float16 *base, ptrdiff_t bstride, vfloat16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16f16.i64(<vscale x 16 x half> [[TMP0]], <vscale x 16 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m4x2(_Float16 *base, ptrdiff_t bstride, vfloat16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf4x2(int16_t *base, ptrdiff_t bstride, vint16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf2x2(int16_t *base, ptrdiff_t bstride, vint16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m1x2(int16_t *base, ptrdiff_t bstride, vint16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m1x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m2x2(int16_t *base, ptrdiff_t bstride, vint16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16i16.i64(<vscale x 16 x i16> [[TMP0]], <vscale x 16 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m4x2(int16_t *base, ptrdiff_t bstride, vint16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16mf4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf4x2(uint16_t *base, ptrdiff_t bstride, vuint16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16mf2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf2x2(uint16_t *base, ptrdiff_t bstride, vuint16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m1x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m1x2(uint16_t *base, ptrdiff_t bstride, vuint16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m1x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m2x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m2x2(uint16_t *base, ptrdiff_t bstride, vuint16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m2x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m4x2
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16i16.i64(<vscale x 16 x i16> [[TMP0]], <vscale x 16 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m4x2(uint16_t *base, ptrdiff_t bstride, vuint16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m4x2(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1f16.i64(<vscale x 1 x half> [[TMP0]], <vscale x 1 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf4x2_m(vbool64_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf4x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2f16.i64(<vscale x 2 x half> [[TMP0]], <vscale x 2 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf2x2_m(vbool32_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4f16.i64(<vscale x 4 x half> [[TMP0]], <vscale x 4 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m1x2_m(vbool16_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m1x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x half>, <vscale x 8 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8f16.i64(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m2x2_m(vbool8_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_f16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x half>, <vscale x 16 x half> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16f16.i64(<vscale x 16 x half> [[TMP0]], <vscale x 16 x half> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m4x2_m(vbool4_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_f16m4x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf4x2_m(vbool64_t mask, int16_t *base, ptrdiff_t bstride, vint16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf4x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf2x2_m(vbool32_t mask, int16_t *base, ptrdiff_t bstride, vint16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m1x2_m(vbool16_t mask, int16_t *base, ptrdiff_t bstride, vint16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m1x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m2x2_m(vbool8_t mask, int16_t *base, ptrdiff_t bstride, vint16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_i16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16i16.i64(<vscale x 16 x i16> [[TMP0]], <vscale x 16 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m4x2_m(vbool4_t mask, int16_t *base, ptrdiff_t bstride, vint16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_i16m4x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16mf4x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1i16.i64(<vscale x 1 x i16> [[TMP0]], <vscale x 1 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf4x2_m(vbool64_t mask, uint16_t *base, ptrdiff_t bstride, vuint16mf4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf4x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16mf2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2i16.i64(<vscale x 2 x i16> [[TMP0]], <vscale x 2 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf2x2_m(vbool32_t mask, uint16_t *base, ptrdiff_t bstride, vuint16mf2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m1x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4i16.i64(<vscale x 4 x i16> [[TMP0]], <vscale x 4 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m1x2_m(vbool16_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m1x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m1x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m2x2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i16>, <vscale x 8 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8i16.i64(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m2x2_m(vbool8_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m2x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m2x2_m(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg2e16_v_u16m4x2_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 0
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x i16>, <vscale x 16 x i16> } [[V_TUPLE]], 1
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16i16.i64(<vscale x 16 x i16> [[TMP0]], <vscale x 16 x i16> [[TMP1]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m4x2_m(vbool4_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m4x2_t v_tuple, size_t vl) {
  return __riscv_vssseg2e16_v_u16m4x2_m(mask, base, bstride, v_tuple, vl);
}

