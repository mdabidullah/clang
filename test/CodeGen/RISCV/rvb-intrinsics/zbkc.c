// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple riscv32 -target-feature +zbkc -emit-llvm %s -o - \
// RUN:     -disable-O0-optnone | opt -S -passes=mem2reg \
// RUN:     | FileCheck %s  -check-prefix=RV32ZBKC
// RUN: %clang_cc1 -triple riscv64 -target-feature +zbkc -emit-llvm %s -o - \
// RUN:     -disable-O0-optnone | opt -S -passes=mem2reg \
// RUN:     | FileCheck %s  -check-prefix=RV64ZBKC

#include <riscv_bitmanip.h>

#if __riscv_xlen == 64
// RV64ZBKC-LABEL: @clmul_64(
// RV64ZBKC-NEXT:  entry:
// RV64ZBKC-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.clmul.i64(i64 [[A:%.*]], i64 [[B:%.*]])
// RV64ZBKC-NEXT:    ret i64 [[TMP0]]
//
uint64_t clmul_64(uint64_t a, uint64_t b) {
  return __riscv_clmul_64(a, b);
}

// RV64ZBKC-LABEL: @clmulh_64(
// RV64ZBKC-NEXT:  entry:
// RV64ZBKC-NEXT:    [[TMP0:%.*]] = call i64 @llvm.riscv.clmulh.i64(i64 [[A:%.*]], i64 [[B:%.*]])
// RV64ZBKC-NEXT:    ret i64 [[TMP0]]
//
uint64_t clmulh_64(uint64_t a, uint64_t b) {
  return __riscv_clmulh_64(a, b);
}
#endif

// RV32ZBKC-LABEL: @clmul_32(
// RV32ZBKC-NEXT:  entry:
// RV32ZBKC-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.clmul.i32(i32 [[A:%.*]], i32 [[B:%.*]])
// RV32ZBKC-NEXT:    ret i32 [[TMP0]]
//
// RV64ZBKC-LABEL: @clmul_32(
// RV64ZBKC-NEXT:  entry:
// RV64ZBKC-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.clmul.i32(i32 [[A:%.*]], i32 [[B:%.*]])
// RV64ZBKC-NEXT:    ret i32 [[TMP0]]
//
uint32_t clmul_32(uint32_t a, uint32_t b) {
  return __riscv_clmul_32(a, b);
}

#if __riscv_xlen == 32
// RV32ZBKC-LABEL: @clmulh_32(
// RV32ZBKC-NEXT:  entry:
// RV32ZBKC-NEXT:    [[TMP0:%.*]] = call i32 @llvm.riscv.clmulh.i32(i32 [[A:%.*]], i32 [[B:%.*]])
// RV32ZBKC-NEXT:    ret i32 [[TMP0]]
//
uint32_t clmulh_32(uint32_t a, uint32_t b) {
  return __riscv_clmulh_32(a, b);
}
#endif
