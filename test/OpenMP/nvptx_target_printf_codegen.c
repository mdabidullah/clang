// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// Test target codegen - host bc file has to be created first.
// RUN: %clang_cc1 -verify -fopenmp -x c -triple powerpc64le-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm-bc %s -o %t-ppc-host.bc
// RUN: %clang_cc1 -verify -fopenmp -x c -triple nvptx64-unknown-unknown -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - | FileCheck %s --check-prefix=CHECK-64
// RUN: %clang_cc1 -verify -fopenmp -x c -triple i386-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm-bc %s -o %t-x86-host.bc
// RUN: %clang_cc1 -verify -fopenmp -x c -triple nvptx-unknown-unknown -fopenmp-targets=nvptx-nvidia-cuda -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-x86-host.bc -o - | FileCheck %s --check-prefix=CHECK-32
// expected-no-diagnostics
extern int printf(const char *, ...);


// Check a simple call to printf end-to-end.
int CheckSimple(void) {
#pragma omp target
  {
    // printf in master-only basic block.
    const char* fmt = "%d %lld %f";

    printf(fmt, 1, 2ll, 3.0);
  }

  return 0;
}

void CheckNoArgs(void) {
#pragma omp target
  {
    // printf in master-only basic block.
    printf("hello, world!");
  }
}

// Check that printf's alloca happens in the entry block, not inside the if
// statement.
int foo;
void CheckAllocaIsInEntryBlock(void) {
#pragma omp target
  {
    if (foo) {
      printf("%d", 42);
    }
  }
}
// CHECK-64-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckSimple_l13
// CHECK-64-SAME: (ptr noalias noundef [[DYN_PTR:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-64-NEXT:  entry:
// CHECK-64-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-64-NEXT:    [[FMT:%.*]] = alloca ptr, align 8
// CHECK-64-NEXT:    [[TMP:%.*]] = alloca [[PRINTF_ARGS:%.*]], align 8
// CHECK-64-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 8
// CHECK-64-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckSimple_l13_kernel_environment, ptr [[DYN_PTR]])
// CHECK-64-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-64-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-64:       user_code.entry:
// CHECK-64-NEXT:    store ptr @.str, ptr [[FMT]], align 8
// CHECK-64-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[FMT]], align 8
// CHECK-64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 0
// CHECK-64-NEXT:    store i32 1, ptr [[TMP2]], align 4
// CHECK-64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 1
// CHECK-64-NEXT:    store i64 2, ptr [[TMP3]], align 8
// CHECK-64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 2
// CHECK-64-NEXT:    store double 3.000000e+00, ptr [[TMP4]], align 8
// CHECK-64-NEXT:    [[TMP5:%.*]] = call i32 @__llvm_omp_vprintf(ptr [[TMP1]], ptr [[TMP]], i32 24)
// CHECK-64-NEXT:    call void @__kmpc_target_deinit()
// CHECK-64-NEXT:    ret void
// CHECK-64:       worker.exit:
// CHECK-64-NEXT:    ret void
//
//
// CHECK-64-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckNoArgs_l25
// CHECK-64-SAME: (ptr noalias noundef [[DYN_PTR:%.*]]) #[[ATTR0]] {
// CHECK-64-NEXT:  entry:
// CHECK-64-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-64-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 8
// CHECK-64-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckNoArgs_l25_kernel_environment, ptr [[DYN_PTR]])
// CHECK-64-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-64-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-64:       user_code.entry:
// CHECK-64-NEXT:    [[TMP1:%.*]] = call i32 @__llvm_omp_vprintf(ptr @.str1, ptr null, i32 0)
// CHECK-64-NEXT:    call void @__kmpc_target_deinit()
// CHECK-64-NEXT:    ret void
// CHECK-64:       worker.exit:
// CHECK-64-NEXT:    ret void
//
//
// CHECK-64-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckAllocaIsInEntryBlock_l36
// CHECK-64-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], i64 noundef [[FOO:%.*]]) #[[ATTR0]] {
// CHECK-64-NEXT:  entry:
// CHECK-64-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-64-NEXT:    [[FOO_ADDR:%.*]] = alloca i64, align 8
// CHECK-64-NEXT:    [[TMP:%.*]] = alloca [[PRINTF_ARGS_0:%.*]], align 8
// CHECK-64-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 8
// CHECK-64-NEXT:    store i64 [[FOO]], ptr [[FOO_ADDR]], align 8
// CHECK-64-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckAllocaIsInEntryBlock_l36_kernel_environment, ptr [[DYN_PTR]])
// CHECK-64-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-64-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-64:       user_code.entry:
// CHECK-64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[FOO_ADDR]], align 4
// CHECK-64-NEXT:    [[TOBOOL:%.*]] = icmp ne i32 [[TMP1]], 0
// CHECK-64-NEXT:    br i1 [[TOBOOL]], label [[IF_THEN:%.*]], label [[IF_END:%.*]]
// CHECK-64:       if.then:
// CHECK-64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[PRINTF_ARGS_0]], ptr [[TMP]], i32 0, i32 0
// CHECK-64-NEXT:    store i32 42, ptr [[TMP2]], align 4
// CHECK-64-NEXT:    [[TMP3:%.*]] = call i32 @__llvm_omp_vprintf(ptr @.str2, ptr [[TMP]], i32 4)
// CHECK-64-NEXT:    br label [[IF_END]]
// CHECK-64:       worker.exit:
// CHECK-64-NEXT:    ret void
// CHECK-64:       if.end:
// CHECK-64-NEXT:    call void @__kmpc_target_deinit()
// CHECK-64-NEXT:    ret void
//
//
// CHECK-32-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckSimple_l13
// CHECK-32-SAME: (ptr noalias noundef [[DYN_PTR:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-32-NEXT:  entry:
// CHECK-32-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 4
// CHECK-32-NEXT:    [[FMT:%.*]] = alloca ptr, align 4
// CHECK-32-NEXT:    [[TMP:%.*]] = alloca [[PRINTF_ARGS:%.*]], align 8
// CHECK-32-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 4
// CHECK-32-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckSimple_l13_kernel_environment, ptr [[DYN_PTR]])
// CHECK-32-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-32-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-32:       user_code.entry:
// CHECK-32-NEXT:    store ptr @.str, ptr [[FMT]], align 4
// CHECK-32-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[FMT]], align 4
// CHECK-32-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 0
// CHECK-32-NEXT:    store i32 1, ptr [[TMP2]], align 4
// CHECK-32-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 1
// CHECK-32-NEXT:    store i64 2, ptr [[TMP3]], align 8
// CHECK-32-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[PRINTF_ARGS]], ptr [[TMP]], i32 0, i32 2
// CHECK-32-NEXT:    store double 3.000000e+00, ptr [[TMP4]], align 8
// CHECK-32-NEXT:    [[TMP5:%.*]] = call i32 @__llvm_omp_vprintf(ptr [[TMP1]], ptr [[TMP]], i32 24)
// CHECK-32-NEXT:    call void @__kmpc_target_deinit()
// CHECK-32-NEXT:    ret void
// CHECK-32:       worker.exit:
// CHECK-32-NEXT:    ret void
//
//
// CHECK-32-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckNoArgs_l25
// CHECK-32-SAME: (ptr noalias noundef [[DYN_PTR:%.*]]) #[[ATTR0]] {
// CHECK-32-NEXT:  entry:
// CHECK-32-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 4
// CHECK-32-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 4
// CHECK-32-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckNoArgs_l25_kernel_environment, ptr [[DYN_PTR]])
// CHECK-32-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-32-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-32:       user_code.entry:
// CHECK-32-NEXT:    [[TMP1:%.*]] = call i32 @__llvm_omp_vprintf(ptr @.str1, ptr null, i32 0)
// CHECK-32-NEXT:    call void @__kmpc_target_deinit()
// CHECK-32-NEXT:    ret void
// CHECK-32:       worker.exit:
// CHECK-32-NEXT:    ret void
//
//
// CHECK-32-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckAllocaIsInEntryBlock_l36
// CHECK-32-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], i32 noundef [[FOO:%.*]]) #[[ATTR0]] {
// CHECK-32-NEXT:  entry:
// CHECK-32-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 4
// CHECK-32-NEXT:    [[FOO_ADDR:%.*]] = alloca i32, align 4
// CHECK-32-NEXT:    [[TMP:%.*]] = alloca [[PRINTF_ARGS_0:%.*]], align 8
// CHECK-32-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR]], align 4
// CHECK-32-NEXT:    store i32 [[FOO]], ptr [[FOO_ADDR]], align 4
// CHECK-32-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_CheckAllocaIsInEntryBlock_l36_kernel_environment, ptr [[DYN_PTR]])
// CHECK-32-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-32-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-32:       user_code.entry:
// CHECK-32-NEXT:    [[TMP1:%.*]] = load i32, ptr [[FOO_ADDR]], align 4
// CHECK-32-NEXT:    [[TOBOOL:%.*]] = icmp ne i32 [[TMP1]], 0
// CHECK-32-NEXT:    br i1 [[TOBOOL]], label [[IF_THEN:%.*]], label [[IF_END:%.*]]
// CHECK-32:       if.then:
// CHECK-32-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[PRINTF_ARGS_0]], ptr [[TMP]], i32 0, i32 0
// CHECK-32-NEXT:    store i32 42, ptr [[TMP2]], align 4
// CHECK-32-NEXT:    [[TMP3:%.*]] = call i32 @__llvm_omp_vprintf(ptr @.str2, ptr [[TMP]], i32 4)
// CHECK-32-NEXT:    br label [[IF_END]]
// CHECK-32:       worker.exit:
// CHECK-32-NEXT:    ret void
// CHECK-32:       if.end:
// CHECK-32-NEXT:    call void @__kmpc_target_deinit()
// CHECK-32-NEXT:    ret void
//
