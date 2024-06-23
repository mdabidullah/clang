// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// Test target codegen - host bc file has to be created first.
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -fopenmp-cuda-mode -x c++ -triple powerpc64le-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm-bc %s -o %t-ppc-host.bc
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -fopenmp-cuda-mode -x c++ -triple nvptx64-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK1
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -fopenmp-cuda-mode -x c++ -triple i386-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm-bc %s -o %t-x86-host.bc
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -fopenmp-cuda-mode -x c++ -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK2
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=45 -fopenmp-cuda-mode -fexceptions -fcxx-exceptions -x c++ -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK2

// RUN: %clang_cc1 -verify -fopenmp -fopenmp-cuda-mode -x c++ -triple powerpc64le-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm-bc %s -o %t-ppc-host.bc
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-cuda-mode -x c++ -triple nvptx64-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK1
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-cuda-mode -x c++ -triple i386-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm-bc %s -o %t-x86-host.bc
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-cuda-mode -x c++ -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK2
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-cuda-mode -fexceptions -fcxx-exceptions -x c++ -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK2

// expected-no-diagnostics
#ifndef HEADER
#define HEADER

template<typename tx>
tx ftemplate(int n) {
  tx a = 0;
  short aa = 0;
  tx b[10];

  #pragma omp target parallel if(target: 0)
  {
    a += 1;
  }

  #pragma omp target parallel map(tofrom: aa)
  {
    aa += 1;
  }

  #pragma omp target parallel map(tofrom:a, aa, b) if(target: n>40)
  {
    a += 1;
    aa += 1;
    b[2] += 1;
  }

  return a;
}

int bar(int n){
  int a = 0;

  a += ftemplate<int>(n);

  return a;
}

#endif
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30
// CHECK1-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [1 x ptr], align 8
// CHECK1-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_kernel_environment, ptr [[DYN_PTR]])
// CHECK1-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP1]], -1
// CHECK1-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK1:       user_code.entry:
// CHECK1-NEXT:    [[TMP2:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1:[0-9]+]])
// CHECK1-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [1 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i64 0, i64 0
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[TMP3]], align 8
// CHECK1-NEXT:    call void @__kmpc_parallel_51(ptr @[[GLOB1]], i32 [[TMP2]], i32 1, i32 -1, i32 -1, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_omp_outlined, ptr null, ptr [[CAPTURED_VARS_ADDRS]], i64 1)
// CHECK1-NEXT:    call void @__kmpc_target_deinit()
// CHECK1-NEXT:    ret void
// CHECK1:       worker.exit:
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_omp_outlined
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load i16, ptr [[TMP0]], align 2
// CHECK1-NEXT:    [[CONV:%.*]] = sext i16 [[TMP1]] to i32
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[CONV]], 1
// CHECK1-NEXT:    [[CONV1:%.*]] = trunc i32 [[ADD]] to i16
// CHECK1-NEXT:    store i16 [[CONV1]], ptr [[TMP0]], align 2
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35
// CHECK1-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[A:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]], ptr noundef nonnull align 4 dereferenceable(40) [[B:%.*]]) #[[ATTR0]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [3 x ptr], align 8
// CHECK1-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[A_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[B_ADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_kernel_environment, ptr [[DYN_PTR]])
// CHECK1-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP3]], -1
// CHECK1-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK1:       user_code.entry:
// CHECK1-NEXT:    [[TMP4:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1]])
// CHECK1-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i64 0, i64 0
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[TMP5]], align 8
// CHECK1-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i64 0, i64 1
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[TMP6]], align 8
// CHECK1-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i64 0, i64 2
// CHECK1-NEXT:    store ptr [[TMP2]], ptr [[TMP7]], align 8
// CHECK1-NEXT:    call void @__kmpc_parallel_51(ptr @[[GLOB1]], i32 [[TMP4]], i32 1, i32 -1, i32 -1, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_omp_outlined, ptr null, ptr [[CAPTURED_VARS_ADDRS]], i64 3)
// CHECK1-NEXT:    call void @__kmpc_target_deinit()
// CHECK1-NEXT:    ret void
// CHECK1:       worker.exit:
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_omp_outlined
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[A:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]], ptr noundef nonnull align 4 dereferenceable(40) [[B:%.*]]) #[[ATTR1]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[A_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[AA_ADDR]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[B_ADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP3]], 1
// CHECK1-NEXT:    store i32 [[ADD]], ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[TMP4:%.*]] = load i16, ptr [[TMP1]], align 2
// CHECK1-NEXT:    [[CONV:%.*]] = sext i16 [[TMP4]] to i32
// CHECK1-NEXT:    [[ADD1:%.*]] = add nsw i32 [[CONV]], 1
// CHECK1-NEXT:    [[CONV2:%.*]] = trunc i32 [[ADD1]] to i16
// CHECK1-NEXT:    store i16 [[CONV2]], ptr [[TMP1]], align 2
// CHECK1-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [10 x i32], ptr [[TMP2]], i64 0, i64 2
// CHECK1-NEXT:    [[TMP5:%.*]] = load i32, ptr [[ARRAYIDX]], align 4
// CHECK1-NEXT:    [[ADD3:%.*]] = add nsw i32 [[TMP5]], 1
// CHECK1-NEXT:    store i32 [[ADD3]], ptr [[ARRAYIDX]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK2-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30
// CHECK2-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK2-NEXT:  entry:
// CHECK2-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [1 x ptr], align 4
// CHECK2-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP1:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_kernel_environment, ptr [[DYN_PTR]])
// CHECK2-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP1]], -1
// CHECK2-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK2:       user_code.entry:
// CHECK2-NEXT:    [[TMP2:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1:[0-9]+]])
// CHECK2-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [1 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i32 0, i32 0
// CHECK2-NEXT:    store ptr [[TMP0]], ptr [[TMP3]], align 4
// CHECK2-NEXT:    call void @__kmpc_parallel_51(ptr @[[GLOB1]], i32 [[TMP2]], i32 1, i32 -1, i32 -1, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_omp_outlined, ptr null, ptr [[CAPTURED_VARS_ADDRS]], i32 1)
// CHECK2-NEXT:    call void @__kmpc_target_deinit()
// CHECK2-NEXT:    ret void
// CHECK2:       worker.exit:
// CHECK2-NEXT:    ret void
//
//
// CHECK2-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l30_omp_outlined
// CHECK2-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK2-NEXT:  entry:
// CHECK2-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 4
// CHECK2-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 4
// CHECK2-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP1:%.*]] = load i16, ptr [[TMP0]], align 2
// CHECK2-NEXT:    [[CONV:%.*]] = sext i16 [[TMP1]] to i32
// CHECK2-NEXT:    [[ADD:%.*]] = add nsw i32 [[CONV]], 1
// CHECK2-NEXT:    [[CONV1:%.*]] = trunc i32 [[ADD]] to i16
// CHECK2-NEXT:    store i16 [[CONV1]], ptr [[TMP0]], align 2
// CHECK2-NEXT:    ret void
//
//
// CHECK2-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35
// CHECK2-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[A:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]], ptr noundef nonnull align 4 dereferenceable(40) [[B:%.*]]) #[[ATTR0]] {
// CHECK2-NEXT:  entry:
// CHECK2-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [3 x ptr], align 4
// CHECK2-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 4
// CHECK2-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[A_ADDR]], align 4
// CHECK2-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[B_ADDR]], align 4
// CHECK2-NEXT:    [[TMP3:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_kernel_environment, ptr [[DYN_PTR]])
// CHECK2-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP3]], -1
// CHECK2-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK2:       user_code.entry:
// CHECK2-NEXT:    [[TMP4:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1]])
// CHECK2-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i32 0, i32 0
// CHECK2-NEXT:    store ptr [[TMP0]], ptr [[TMP5]], align 4
// CHECK2-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i32 0, i32 1
// CHECK2-NEXT:    store ptr [[TMP1]], ptr [[TMP6]], align 4
// CHECK2-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [3 x ptr], ptr [[CAPTURED_VARS_ADDRS]], i32 0, i32 2
// CHECK2-NEXT:    store ptr [[TMP2]], ptr [[TMP7]], align 4
// CHECK2-NEXT:    call void @__kmpc_parallel_51(ptr @[[GLOB1]], i32 [[TMP4]], i32 1, i32 -1, i32 -1, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_omp_outlined, ptr null, ptr [[CAPTURED_VARS_ADDRS]], i32 3)
// CHECK2-NEXT:    call void @__kmpc_target_deinit()
// CHECK2-NEXT:    ret void
// CHECK2:       worker.exit:
// CHECK2-NEXT:    ret void
//
//
// CHECK2-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__Z9ftemplateIiET_i_l35_omp_outlined
// CHECK2-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[A:%.*]], ptr noundef nonnull align 2 dereferenceable(2) [[AA:%.*]], ptr noundef nonnull align 4 dereferenceable(40) [[B:%.*]]) #[[ATTR1]] {
// CHECK2-NEXT:  entry:
// CHECK2-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[AA_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 4
// CHECK2-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 4
// CHECK2-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 4
// CHECK2-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[AA]], ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 4
// CHECK2-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[A_ADDR]], align 4
// CHECK2-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[AA_ADDR]], align 4
// CHECK2-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[B_ADDR]], align 4
// CHECK2-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK2-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP3]], 1
// CHECK2-NEXT:    store i32 [[ADD]], ptr [[TMP0]], align 4
// CHECK2-NEXT:    [[TMP4:%.*]] = load i16, ptr [[TMP1]], align 2
// CHECK2-NEXT:    [[CONV:%.*]] = sext i16 [[TMP4]] to i32
// CHECK2-NEXT:    [[ADD1:%.*]] = add nsw i32 [[CONV]], 1
// CHECK2-NEXT:    [[CONV2:%.*]] = trunc i32 [[ADD1]] to i16
// CHECK2-NEXT:    store i16 [[CONV2]], ptr [[TMP1]], align 2
// CHECK2-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [10 x i32], ptr [[TMP2]], i32 0, i32 2
// CHECK2-NEXT:    [[TMP5:%.*]] = load i32, ptr [[ARRAYIDX]], align 4
// CHECK2-NEXT:    [[ADD3:%.*]] = add nsw i32 [[TMP5]], 1
// CHECK2-NEXT:    store i32 [[ADD3]], ptr [[ARRAYIDX]], align 4
// CHECK2-NEXT:    ret void
//
