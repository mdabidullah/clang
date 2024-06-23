// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// RUN: %clang_cc1 -triple arm-unknown-unknown -O0 -std=c23 -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-O0
// RUN: %clang_cc1 -triple arm-unknown-unknown -O1 -std=c23 -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-O1

// Verify that the result from the intrinsic call is zero extended to avoid that
// we get a negative result from popcountg/ctzg/clzg.

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_popcountg_ubi1(
// CHECK-O0-SAME: ) #[[ATTR0:[0-9]+]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i1, align 1
// CHECK-O0-NEXT:    store i1 true, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i1, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i1 @llvm.ctpop.i1(i1 [[TMP0]])
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i1 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_popcountg_ubi1(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0:[0-9]+]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 1
//
int test_popcountg_ubi1() {
  unsigned _BitInt(1) a = 1uwb;
  return __builtin_popcountg(a);
}

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_popcountg_ubi2(
// CHECK-O0-SAME: ) #[[ATTR0]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i2, align 1
// CHECK-O0-NEXT:    store i2 -1, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i2, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i2 @llvm.ctpop.i2(i2 [[TMP0]])
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i2 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_popcountg_ubi2(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 2
//
int test_popcountg_ubi2() {
  unsigned _BitInt(2) a = 3uwb;
  return __builtin_popcountg(a);
}

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_ctzg_ubi1(
// CHECK-O0-SAME: ) #[[ATTR0]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i1, align 1
// CHECK-O0-NEXT:    store i1 false, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i1, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i1 @llvm.cttz.i1(i1 [[TMP0]], i1 false)
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i1 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_ctzg_ubi1(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 1
//
int test_ctzg_ubi1() {
  unsigned _BitInt(1) a = 0uwb;
  return __builtin_ctzg(a);
}

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_ctzg_ubi2(
// CHECK-O0-SAME: ) #[[ATTR0]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i2, align 1
// CHECK-O0-NEXT:    store i2 0, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i2, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i2 @llvm.cttz.i2(i2 [[TMP0]], i1 false)
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i2 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_ctzg_ubi2(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 2
//
int test_ctzg_ubi2() {
  unsigned _BitInt(2) a = 0uwb;
  return __builtin_ctzg(a);
}

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_clzg_ubi1(
// CHECK-O0-SAME: ) #[[ATTR0]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i1, align 1
// CHECK-O0-NEXT:    store i1 false, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i1, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i1 @llvm.ctlz.i1(i1 [[TMP0]], i1 false)
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i1 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_clzg_ubi1(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 1
//
int test_clzg_ubi1() {
  unsigned _BitInt(1) a = 0uwb;
  return __builtin_clzg(a);
}

// CHECK-O0-LABEL: define dso_local arm_aapcscc i32 @test_clzg_ubi2(
// CHECK-O0-SAME: ) #[[ATTR0]] {
// CHECK-O0-NEXT:  entry:
// CHECK-O0-NEXT:    [[A:%.*]] = alloca i2, align 1
// CHECK-O0-NEXT:    store i2 0, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP0:%.*]] = load i2, ptr [[A]], align 1
// CHECK-O0-NEXT:    [[TMP1:%.*]] = call i2 @llvm.ctlz.i2(i2 [[TMP0]], i1 false)
// CHECK-O0-NEXT:    [[CAST:%.*]] = zext i2 [[TMP1]] to i32
// CHECK-O0-NEXT:    ret i32 [[CAST]]
//
// CHECK-O1-LABEL: define dso_local arm_aapcscc noundef i32 @test_clzg_ubi2(
// CHECK-O1-SAME: ) local_unnamed_addr #[[ATTR0]] {
// CHECK-O1-NEXT:  entry:
// CHECK-O1-NEXT:    ret i32 2
//
int test_clzg_ubi2() {
  unsigned _BitInt(2) a = 0uwb;
  return __builtin_clzg(a);
}
