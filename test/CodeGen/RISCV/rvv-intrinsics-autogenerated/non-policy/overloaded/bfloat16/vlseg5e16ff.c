// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +experimental-zvfbfmin \
// RUN:   -target-feature +experimental-zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } @test_vlseg5e16ff_v_bf16mf4x5_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } @llvm.riscv.vlseg5ff.mask.nxv1bf16.i64(<vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, <vscale x 1 x bfloat> poison, ptr [[RS1]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = insertvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } poison, <vscale x 1 x bfloat> [[TMP1]], 0
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = insertvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP2]], <vscale x 1 x bfloat> [[TMP3]], 1
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = insertvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP4]], <vscale x 1 x bfloat> [[TMP5]], 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = insertvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP6]], <vscale x 1 x bfloat> [[TMP7]], 3
// CHECK-RV64-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 4
// CHECK-RV64-NEXT:    [[TMP10:%.*]] = insertvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP8]], <vscale x 1 x bfloat> [[TMP9]], 4
// CHECK-RV64-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, i64 } [[TMP0]], 5
// CHECK-RV64-NEXT:    store i64 [[TMP11]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret { <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat>, <vscale x 1 x bfloat> } [[TMP10]]
//
vbfloat16mf4x5_t test_vlseg5e16ff_v_bf16mf4x5_m(vbool64_t vm, const __bf16 *rs1,
                                                size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } @test_vlseg5e16ff_v_bf16mf2x5_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } @llvm.riscv.vlseg5ff.mask.nxv2bf16.i64(<vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, <vscale x 2 x bfloat> poison, ptr [[RS1]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = insertvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } poison, <vscale x 2 x bfloat> [[TMP1]], 0
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = insertvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP2]], <vscale x 2 x bfloat> [[TMP3]], 1
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = insertvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP4]], <vscale x 2 x bfloat> [[TMP5]], 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = insertvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP6]], <vscale x 2 x bfloat> [[TMP7]], 3
// CHECK-RV64-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 4
// CHECK-RV64-NEXT:    [[TMP10:%.*]] = insertvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP8]], <vscale x 2 x bfloat> [[TMP9]], 4
// CHECK-RV64-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, i64 } [[TMP0]], 5
// CHECK-RV64-NEXT:    store i64 [[TMP11]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret { <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat>, <vscale x 2 x bfloat> } [[TMP10]]
//
vbfloat16mf2x5_t test_vlseg5e16ff_v_bf16mf2x5_m(vbool32_t vm, const __bf16 *rs1,
                                                size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } @test_vlseg5e16ff_v_bf16m1x5_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } @llvm.riscv.vlseg5ff.mask.nxv4bf16.i64(<vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, <vscale x 4 x bfloat> poison, ptr [[RS1]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = insertvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } poison, <vscale x 4 x bfloat> [[TMP1]], 0
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = insertvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP2]], <vscale x 4 x bfloat> [[TMP3]], 1
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = insertvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP4]], <vscale x 4 x bfloat> [[TMP5]], 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 3
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = insertvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP6]], <vscale x 4 x bfloat> [[TMP7]], 3
// CHECK-RV64-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 4
// CHECK-RV64-NEXT:    [[TMP10:%.*]] = insertvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP8]], <vscale x 4 x bfloat> [[TMP9]], 4
// CHECK-RV64-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, i64 } [[TMP0]], 5
// CHECK-RV64-NEXT:    store i64 [[TMP11]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret { <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat>, <vscale x 4 x bfloat> } [[TMP10]]
//
vbfloat16m1x5_t test_vlseg5e16ff_v_bf16m1x5_m(vbool16_t vm, const __bf16 *rs1,
                                              size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff(vm, rs1, new_vl, vl);
}
