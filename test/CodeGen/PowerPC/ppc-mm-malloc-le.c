// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: native, target=powerpc64le-{{.*}}
// The stdlib.h included in mm_malloc.h references native system header
// like: bits/libc-header-start.h or features.h, cross-compile it may
// require installing target headers in build env, otherwise expecting
// failures. So this test will focus on native build only.

// RUN: %clang -target powerpc64le-unknown-linux-gnu -S -emit-llvm %s -fno-discard-value-names -mllvm -disable-llvm-optzns -o - | llvm-cxxfilt | FileCheck %s

#include <mm_malloc.h>


void __attribute__((noinline))
test_mm_malloc() {
  char *buf = _mm_malloc(100, 16);
  _mm_free(buf);
}

// CHECK-LABEL: @test_mm_malloc

// CHECK: define internal ptr @_mm_malloc(i64 noundef [[REG1:[0-9a-zA-Z_%.]+]], i64 noundef [[REG2:[0-9a-zA-Z_%.]+]])
// CHECK: [[REG3:[0-9a-zA-Z_%.]+]] = alloca ptr, align 8
// CHECK: store i64 [[REG1]], ptr [[REG4:[0-9a-zA-Z_%.]+]], align 8
// CHECK-NEXT: store i64 [[REG2]], ptr [[REG5:[0-9a-zA-Z_%.]+]], align 8
// CHECK-NEXT: store i64 16, ptr [[REG6:[0-9a-zA-Z_%.]+]], align 8
// CHECK-NEXT: [[REG8:[0-9a-zA-Z_%.]+]] = load i64, ptr [[REG5]], align 8
// CHECK-NEXT: [[REG9:[0-9a-zA-Z_%.]+]] = load i64, ptr [[REG6]], align 8
// CHECK-NEXT: [[REG10:[0-9a-zA-Z_%.]+]] = icmp ult i64 [[REG8]], [[REG9]]
// CHECK-NEXT: br i1 [[REG10]], label %[[REG23:[0-9a-zA-Z_%.]+]], label %[[REG24:[0-9a-zA-Z_%.]+]]
// CHECK: [[REG23]]:
// CHECK-NEXT: [[REG25:[0-9a-zA-Z_%.]+]] = load i64, ptr [[REG6]], align 8
// CHECK-NEXT: store i64 [[REG25]], ptr [[REG5]], align 8
// CHECK-NEXT: br label %[[REG24:[0-9a-zA-Z_%.]+]]
// CHECK: [[REG24]]:
// CHECK-NEXT: [[REG26:[0-9a-zA-Z_%.]+]] = load i64, ptr [[REG5]], align 8
// CHECK-NEXT: [[REG27:[0-9a-zA-Z_%.]+]] = load i64, ptr [[REG4]], align 8
// CHECK-NEXT: [[REG28:[0-9a-zA-Z_%.]+]] = call signext i32 @posix_memalign(ptr noundef [[REG29:[0-9a-zA-Z_%.]+]], i64 noundef [[REG26]], i64 noundef [[REG27]])
// CHECK-NEXT: [[REG30:[0-9a-zA-Z_%.]+]] = icmp eq i32 [[REG28]], 0
// CHECK-NEXT: br i1 [[REG30]], label %[[REG31:[0-9a-zA-Z_%.]+]], label %[[REG32:[0-9a-zA-Z_%.]+]]
// CHECK: [[REG31]]:
// CHECK-NEXT: [[REG33:[0-9a-zA-Z_%.]+]] = load ptr, ptr [[REG29]], align 8
// CHECK-NEXT: store ptr [[REG33]], ptr [[REG3]], align 8
// CHECK-NEXT: br label %[[REG19:[0-9a-zA-Z_%.]+]]
// CHECK: [[REG32]]:
// CHECK-NEXT: store ptr null, ptr [[REG3]], align 8
// CHECK-NEXT: br label %[[REG19:[0-9a-zA-Z_%.]+]]
// CHECK: [[REG19]]:
// CHECK-NEXT: [[REG34:[0-9a-zA-Z_%.]+]] = load ptr, ptr [[REG3]], align 8
// CHECK-NEXT: ret ptr [[REG34]]

// CHECK: define internal void @_mm_free(ptr noundef [[REG35:[0-9a-zA-Z_%.]+]])
// CHECK: store ptr [[REG35]], ptr [[REG36:[0-9a-zA-Z_%.]+]], align 8
// CHECK-NEXT: [[REG37:[0-9a-zA-Z_%.]+]] = load ptr, ptr [[REG36]], align 8
// CHECK-NEXT: call void @free(ptr noundef [[REG37]])
// CHECK-NEXT: ret void
