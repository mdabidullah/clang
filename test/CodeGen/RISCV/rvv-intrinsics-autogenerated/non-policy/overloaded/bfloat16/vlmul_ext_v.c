// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +experimental-zvfbfmin \
// RUN:   -target-feature +experimental-zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vlmul_ext_v_bf16mf4_bf16mf2(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VALUE:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.vector.insert.nxv2bf16.nxv1bf16(<vscale x 2 x bfloat> poison, <vscale x 1 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vlmul_ext_v_bf16mf4_bf16mf2(vbfloat16mf4_t value) {
  return __riscv_vlmul_ext_bf16mf2(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlmul_ext_v_bf16mf4_bf16m1(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.vector.insert.nxv4bf16.nxv1bf16(<vscale x 4 x bfloat> poison, <vscale x 1 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlmul_ext_v_bf16mf4_bf16m1(vbfloat16mf4_t value) {
  return __riscv_vlmul_ext_bf16m1(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlmul_ext_v_bf16mf4_bf16m2(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.nxv1bf16(<vscale x 8 x bfloat> poison, <vscale x 1 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlmul_ext_v_bf16mf4_bf16m2(vbfloat16mf4_t value) {
  return __riscv_vlmul_ext_bf16m2(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlmul_ext_v_bf16mf4_bf16m4(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv1bf16(<vscale x 16 x bfloat> poison, <vscale x 1 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlmul_ext_v_bf16mf4_bf16m4(vbfloat16mf4_t value) {
  return __riscv_vlmul_ext_bf16m4(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlmul_ext_v_bf16mf4_bf16m8(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.vector.insert.nxv32bf16.nxv1bf16(<vscale x 32 x bfloat> poison, <vscale x 1 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlmul_ext_v_bf16mf4_bf16m8(vbfloat16mf4_t value) {
  return __riscv_vlmul_ext_bf16m8(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlmul_ext_v_bf16mf2_bf16m1(
// CHECK-RV64-SAME: <vscale x 2 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.vector.insert.nxv4bf16.nxv2bf16(<vscale x 4 x bfloat> poison, <vscale x 2 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlmul_ext_v_bf16mf2_bf16m1(vbfloat16mf2_t value) {
  return __riscv_vlmul_ext_bf16m1(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlmul_ext_v_bf16mf2_bf16m2(
// CHECK-RV64-SAME: <vscale x 2 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.nxv2bf16(<vscale x 8 x bfloat> poison, <vscale x 2 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlmul_ext_v_bf16mf2_bf16m2(vbfloat16mf2_t value) {
  return __riscv_vlmul_ext_bf16m2(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlmul_ext_v_bf16mf2_bf16m4(
// CHECK-RV64-SAME: <vscale x 2 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv2bf16(<vscale x 16 x bfloat> poison, <vscale x 2 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlmul_ext_v_bf16mf2_bf16m4(vbfloat16mf2_t value) {
  return __riscv_vlmul_ext_bf16m4(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlmul_ext_v_bf16mf2_bf16m8(
// CHECK-RV64-SAME: <vscale x 2 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.vector.insert.nxv32bf16.nxv2bf16(<vscale x 32 x bfloat> poison, <vscale x 2 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlmul_ext_v_bf16mf2_bf16m8(vbfloat16mf2_t value) {
  return __riscv_vlmul_ext_bf16m8(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlmul_ext_v_bf16m1_bf16m2(
// CHECK-RV64-SAME: <vscale x 4 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.nxv4bf16(<vscale x 8 x bfloat> poison, <vscale x 4 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlmul_ext_v_bf16m1_bf16m2(vbfloat16m1_t value) {
  return __riscv_vlmul_ext_bf16m2(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlmul_ext_v_bf16m1_bf16m4(
// CHECK-RV64-SAME: <vscale x 4 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv4bf16(<vscale x 16 x bfloat> poison, <vscale x 4 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlmul_ext_v_bf16m1_bf16m4(vbfloat16m1_t value) {
  return __riscv_vlmul_ext_bf16m4(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlmul_ext_v_bf16m1_bf16m8(
// CHECK-RV64-SAME: <vscale x 4 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.vector.insert.nxv32bf16.nxv4bf16(<vscale x 32 x bfloat> poison, <vscale x 4 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlmul_ext_v_bf16m1_bf16m8(vbfloat16m1_t value) {
  return __riscv_vlmul_ext_bf16m8(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlmul_ext_v_bf16m2_bf16m4(
// CHECK-RV64-SAME: <vscale x 8 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> poison, <vscale x 8 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlmul_ext_v_bf16m2_bf16m4(vbfloat16m2_t value) {
  return __riscv_vlmul_ext_bf16m4(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlmul_ext_v_bf16m2_bf16m8(
// CHECK-RV64-SAME: <vscale x 8 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.vector.insert.nxv32bf16.nxv8bf16(<vscale x 32 x bfloat> poison, <vscale x 8 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlmul_ext_v_bf16m2_bf16m8(vbfloat16m2_t value) {
  return __riscv_vlmul_ext_bf16m8(value);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlmul_ext_v_bf16m4_bf16m8(
// CHECK-RV64-SAME: <vscale x 16 x bfloat> [[VALUE:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.vector.insert.nxv32bf16.nxv16bf16(<vscale x 32 x bfloat> poison, <vscale x 16 x bfloat> [[VALUE]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlmul_ext_v_bf16m4_bf16m8(vbfloat16m4_t value) {
  return __riscv_vlmul_ext_bf16m8(value);
}
