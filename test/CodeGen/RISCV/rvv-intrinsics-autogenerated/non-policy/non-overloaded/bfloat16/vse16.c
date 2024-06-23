// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +experimental-zvfbfmin \
// RUN:   -target-feature +experimental-zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16mf4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 1 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv1bf16.i64(<vscale x 1 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16mf4(__bf16 *rs1, vbfloat16mf4_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16mf4(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16mf2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 2 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv2bf16.i64(<vscale x 2 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16mf2(__bf16 *rs1, vbfloat16mf2_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16mf2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m1(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 4 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv4bf16.i64(<vscale x 4 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m1(__bf16 *rs1, vbfloat16m1_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16m1(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 8 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv8bf16.i64(<vscale x 8 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m2(__bf16 *rs1, vbfloat16m2_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16m2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 16 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv16bf16.i64(<vscale x 16 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m4(__bf16 *rs1, vbfloat16m4_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16m4(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m8(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], <vscale x 32 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.nxv32bf16.i64(<vscale x 32 x bfloat> [[VS3]], ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m8(__bf16 *rs1, vbfloat16m8_t vs3, size_t vl) {
  return __riscv_vse16_v_bf16m8(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16mf4_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv1bf16.i64(<vscale x 1 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 1 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16mf4_m(vbool64_t vm, __bf16 *rs1, vbfloat16mf4_t vs3,
                            size_t vl) {
  return __riscv_vse16_v_bf16mf4_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16mf2_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv2bf16.i64(<vscale x 2 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 2 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16mf2_m(vbool32_t vm, __bf16 *rs1, vbfloat16mf2_t vs3,
                            size_t vl) {
  return __riscv_vse16_v_bf16mf2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m1_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv4bf16.i64(<vscale x 4 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 4 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m1_m(vbool16_t vm, __bf16 *rs1, vbfloat16m1_t vs3,
                           size_t vl) {
  return __riscv_vse16_v_bf16m1_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m2_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 8 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv8bf16.i64(<vscale x 8 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 8 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m2_m(vbool8_t vm, __bf16 *rs1, vbfloat16m2_t vs3,
                           size_t vl) {
  return __riscv_vse16_v_bf16m2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m4_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 16 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv16bf16.i64(<vscale x 16 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 16 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m4_m(vbool4_t vm, __bf16 *rs1, vbfloat16m4_t vs3,
                           size_t vl) {
  return __riscv_vse16_v_bf16m4_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vse16_v_bf16m8_m(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], <vscale x 32 x bfloat> [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vse.mask.nxv32bf16.i64(<vscale x 32 x bfloat> [[VS3]], ptr [[RS1]], <vscale x 32 x i1> [[VM]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret void
//
void test_vse16_v_bf16m8_m(vbool2_t vm, __bf16 *rs1, vbfloat16m8_t vs3,
                           size_t vl) {
  return __riscv_vse16_v_bf16m8_m(vm, rs1, vs3, vl);
}
