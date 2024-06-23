// RUN: %clang_cc1 -triple s390x-ibm-linux -emit-llvm -fzvector -o - %s 2>&1 \
// RUN:   | FileCheck  %s
//
// Test the emission of the "s390x-visible-vector-ABI" module flag.

// Passing vector argument to varargs function via local function pointer.

typedef __attribute__((vector_size(16))) int v4i32;

void foo(void (*bar)(int, ...)) {
  v4i32 Var = {0, 0, 0, 0};
  (*bar)(0, Var);
}

//CHECK: !llvm.module.flags = !{!0, !1}
//CHECK: !0 = !{i32 2, !"s390x-visible-vector-ABI", i32 1}
