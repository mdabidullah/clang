// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -O1 -Werror -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -O1 -Werror -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve2p1 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +sme2 -S -DTEST_SME2 -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme2 -DTEST_SME2 -O1 -Werror -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme2 -DTEST_SME2 -O1 -Werror -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme2 -S -DTEST_SME2 -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sve.h>

#ifndef TEST_SME2
#define ATTR
#else
#define ATTR __arm_streaming
#endif

// CHECK-LABEL: @test_svcntp_c8_vlx2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c8(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z19test_svcntp_c8_vlx2u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c8(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c8_vlx2(svcount_t pnn) ATTR {
  return svcntp_c8(pnn, 2);
}

// CHECK-LABEL: @test_svcntp_c8_vlx4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c8(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z19test_svcntp_c8_vlx4u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c8(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c8_vlx4(svcount_t pnn) ATTR {
  return svcntp_c8(pnn, 4);
}

// CHECK-LABEL: @test_svcntp_c16_vlx2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c16(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c16_vlx2u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c16(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c16_vlx2(svcount_t pnn) ATTR {
  return svcntp_c16(pnn, 2);
}

// CHECK-LABEL: @test_svcntp_c16_vlx4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c16(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c16_vlx4u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c16(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c16_vlx4(svcount_t pnn) ATTR {
  return svcntp_c16(pnn, 4);
}

// CHECK-LABEL: @test_svcntp_c32_vlx2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c32(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c32_vlx2u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c32(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c32_vlx2(svcount_t pnn) ATTR {
  return svcntp_c32(pnn, 2);
}

// CHECK-LABEL: @test_svcntp_c32_vlx4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c32(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c32_vlx4u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c32(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c32_vlx4(svcount_t pnn) ATTR {
  return svcntp_c32(pnn, 4);
}

// CHECK-LABEL: @test_svcntp_c64_vlx2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c64(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c64_vlx2u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c64(target("aarch64.svcount") [[PNN:%.*]], i32 2)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c64_vlx2(svcount_t pnn) ATTR {
  return svcntp_c64(pnn, 2);
}

// CHECK-LABEL: @test_svcntp_c64_vlx4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c64(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CHECK-NEXT:    ret i64 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z20test_svcntp_c64_vlx4u11__SVCount_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call i64 @llvm.aarch64.sve.cntp.c64(target("aarch64.svcount") [[PNN:%.*]], i32 4)
// CPP-CHECK-NEXT:    ret i64 [[TMP0]]
//
uint64_t test_svcntp_c64_vlx4(svcount_t pnn) ATTR {
  return svcntp_c64(pnn, 4);
}
