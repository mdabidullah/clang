// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple wasm32-unknown-unknown -target-feature +reference-types -o - -emit-llvm %s | FileCheck %s

typedef __externref_t externref_t;

void helper(externref_t);

// CHECK-LABEL: @handle(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[OBJ_ADDR:%.*]] = alloca ptr addrspace(10), align 1
// CHECK-NEXT:    store ptr addrspace(10) [[OBJ:%.*]], ptr [[OBJ_ADDR]], align 1
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr addrspace(10), ptr [[OBJ_ADDR]], align 1
// CHECK-NEXT:    call void @helper(ptr addrspace(10) [[TMP0]])
// CHECK-NEXT:    ret void
//
void handle(externref_t obj) {
  helper(obj);
}
