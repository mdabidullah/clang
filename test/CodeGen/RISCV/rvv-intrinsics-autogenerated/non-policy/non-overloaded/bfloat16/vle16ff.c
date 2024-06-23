// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +experimental-zvfbfmin \
// RUN:   -target-feature +experimental-zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vle16ff_v_bf16mf4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, i64 } @llvm.riscv.vleff.nxv1bf16.i64(<vscale x 1 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP1]]
//
vbfloat16mf4_t test_vle16ff_v_bf16mf4(const __bf16 *rs1, size_t *new_vl,
                                      size_t vl) {
  return __riscv_vle16ff_v_bf16mf4(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vle16ff_v_bf16mf2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, i64 } @llvm.riscv.vleff.nxv2bf16.i64(<vscale x 2 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP1]]
//
vbfloat16mf2_t test_vle16ff_v_bf16mf2(const __bf16 *rs1, size_t *new_vl,
                                      size_t vl) {
  return __riscv_vle16ff_v_bf16mf2(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vle16ff_v_bf16m1(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, i64 } @llvm.riscv.vleff.nxv4bf16.i64(<vscale x 4 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP1]]
//
vbfloat16m1_t test_vle16ff_v_bf16m1(const __bf16 *rs1, size_t *new_vl,
                                    size_t vl) {
  return __riscv_vle16ff_v_bf16m1(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vle16ff_v_bf16m2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x bfloat>, i64 } @llvm.riscv.vleff.nxv8bf16.i64(<vscale x 8 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP1]]
//
vbfloat16m2_t test_vle16ff_v_bf16m2(const __bf16 *rs1, size_t *new_vl,
                                    size_t vl) {
  return __riscv_vle16ff_v_bf16m2(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vle16ff_v_bf16m4(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x bfloat>, i64 } @llvm.riscv.vleff.nxv16bf16.i64(<vscale x 16 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP1]]
//
vbfloat16m4_t test_vle16ff_v_bf16m4(const __bf16 *rs1, size_t *new_vl,
                                    size_t vl) {
  return __riscv_vle16ff_v_bf16m4(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vle16ff_v_bf16m8(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 32 x bfloat>, i64 } @llvm.riscv.vleff.nxv32bf16.i64(<vscale x 32 x bfloat> poison, ptr [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 32 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 32 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP1]]
//
vbfloat16m8_t test_vle16ff_v_bf16m8(const __bf16 *rs1, size_t *new_vl,
                                    size_t vl) {
  return __riscv_vle16ff_v_bf16m8(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vle16ff_v_bf16mf4_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv1bf16.i64(<vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP1]]
//
vbfloat16mf4_t test_vle16ff_v_bf16mf4_m(vbool64_t vm, const __bf16 *rs1,
                                        size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16mf4_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vle16ff_v_bf16mf2_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv2bf16.i64(<vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP1]]
//
vbfloat16mf2_t test_vle16ff_v_bf16mf2_m(vbool32_t vm, const __bf16 *rs1,
                                        size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16mf2_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vle16ff_v_bf16m1_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv4bf16.i64(<vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP1]]
//
vbfloat16m1_t test_vle16ff_v_bf16m1_m(vbool16_t vm, const __bf16 *rs1,
                                      size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16m1_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vle16ff_v_bf16m2_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv8bf16.i64(<vscale x 8 x bfloat> poison, ptr [[RS1]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP1]]
//
vbfloat16m2_t test_vle16ff_v_bf16m2_m(vbool8_t vm, const __bf16 *rs1,
                                      size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16m2_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vle16ff_v_bf16m4_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 16 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv16bf16.i64(<vscale x 16 x bfloat> poison, ptr [[RS1]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 16 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 16 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP1]]
//
vbfloat16m4_t test_vle16ff_v_bf16m4_m(vbool4_t vm, const __bf16 *rs1,
                                      size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16m4_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vle16ff_v_bf16m8_m(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 32 x bfloat>, i64 } @llvm.riscv.vleff.mask.nxv32bf16.i64(<vscale x 32 x bfloat> poison, ptr [[RS1]], <vscale x 32 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 32 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 32 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP1]]
//
vbfloat16m8_t test_vle16ff_v_bf16m8_m(vbool2_t vm, const __bf16 *rs1,
                                      size_t *new_vl, size_t vl) {
  return __riscv_vle16ff_v_bf16m8_m(vm, rs1, new_vl, vl);
}
