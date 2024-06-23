// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// REQUIRES: amdgpu-registered-target

// expected-no-diagnostics
#ifndef HEADER
#define HEADER

// RUN: %clang_cc1 -verify -fopenmp -x c -triple powerpc64le-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm-bc %s -o %t-ppc-host-amd.bc
// RUN: %clang_cc1 -verify -fopenmp -x c -triple amdgcn-amd-amdhsa -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-ppc-host-amd.bc -o - | FileCheck %s --check-prefix=CHECK-AMD


void write_to_aligned_array(int *a, int N) {
  int *aptr __attribute__ ((aligned(64))) = a;
  #pragma omp target teams distribute parallel for map(tofrom: aptr[0:N])
  for(int i = 0; i < N; i++) {
    aptr[i] = i;
  }
}

#endif
// CHECK-AMD-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14
// CHECK-AMD-SAME: (ptr noalias noundef [[DYN_PTR:%.*]], i64 noundef [[N:%.*]], ptr noundef [[APTR:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-AMD-NEXT:  entry:
// CHECK-AMD-NEXT:    [[DYN_PTR_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[APTR_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[N_CASTED:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTZERO_ADDR:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTTHREADID_TEMP_:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DYN_PTR_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DYN_PTR_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[N_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[N_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[APTR_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[APTR_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[N_CASTED_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[N_CASTED]] to ptr
// CHECK-AMD-NEXT:    [[DOTZERO_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTZERO_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTTHREADID_TEMP__ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTTHREADID_TEMP_]] to ptr
// CHECK-AMD-NEXT:    store ptr [[DYN_PTR]], ptr [[DYN_PTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i64 [[N]], ptr [[N_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store ptr [[APTR]], ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_target_init(ptr addrspacecast (ptr addrspace(1) @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14_kernel_environment to ptr), ptr [[DYN_PTR]])
// CHECK-AMD-NEXT:    [[EXEC_USER_CODE:%.*]] = icmp eq i32 [[TMP0]], -1
// CHECK-AMD-NEXT:    br i1 [[EXEC_USER_CODE]], label [[USER_CODE_ENTRY:%.*]], label [[WORKER_EXIT:%.*]]
// CHECK-AMD:       user_code.entry:
// CHECK-AMD-NEXT:    [[TMP1:%.*]] = call i32 @__kmpc_global_thread_num(ptr addrspacecast (ptr addrspace(1) @[[GLOB1:[0-9]+]] to ptr))
// CHECK-AMD-NEXT:    [[TMP2:%.*]] = load i32, ptr [[N_ADDR_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP2]], ptr [[N_CASTED_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP3:%.*]] = load i64, ptr [[N_CASTED_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i32 0, ptr [[DOTZERO_ADDR_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP1]], ptr [[DOTTHREADID_TEMP__ASCAST]], align 4
// CHECK-AMD-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14_omp_outlined(ptr [[DOTTHREADID_TEMP__ASCAST]], ptr [[DOTZERO_ADDR_ASCAST]], i64 [[TMP3]], ptr [[TMP4]]) #[[ATTR2:[0-9]+]]
// CHECK-AMD-NEXT:    call void @__kmpc_target_deinit()
// CHECK-AMD-NEXT:    ret void
// CHECK-AMD:       worker.exit:
// CHECK-AMD-NEXT:    ret void
//
//
// CHECK-AMD-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14_omp_outlined
// CHECK-AMD-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], i64 noundef [[N:%.*]], ptr noundef [[APTR:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK-AMD-NEXT:  entry:
// CHECK-AMD-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[APTR_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[TMP:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_1:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[I:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_COMB_LB:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_COMB_UB:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[I3:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[N_CASTED:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [4 x ptr], align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTGLOBAL_TID__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTGLOBAL_TID__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTBOUND_TID__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTBOUND_TID__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[N_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[N_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[APTR_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[APTR_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_IV_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_IV]] to ptr
// CHECK-AMD-NEXT:    [[TMP_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[TMP]] to ptr
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR__ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTCAPTURE_EXPR_]] to ptr
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTCAPTURE_EXPR_1]] to ptr
// CHECK-AMD-NEXT:    [[I_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[I]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_COMB_LB_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_COMB_LB]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_COMB_UB_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_COMB_UB]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_STRIDE_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_STRIDE]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_IS_LAST_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_IS_LAST]] to ptr
// CHECK-AMD-NEXT:    [[I3_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[I3]] to ptr
// CHECK-AMD-NEXT:    [[N_CASTED_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[N_CASTED]] to ptr
// CHECK-AMD-NEXT:    [[CAPTURED_VARS_ADDRS_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[CAPTURED_VARS_ADDRS]] to ptr
// CHECK-AMD-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i64 [[N]], ptr [[N_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store ptr [[APTR]], ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP0:%.*]] = load i32, ptr [[N_ADDR_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP0]], ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP1:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP1]], 0
// CHECK-AMD-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-AMD-NEXT:    [[SUB2:%.*]] = sub nsw i32 [[DIV]], 1
// CHECK-AMD-NEXT:    store i32 [[SUB2]], ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 0, ptr [[I_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[CMP:%.*]] = icmp slt i32 0, [[TMP2]]
// CHECK-AMD-NEXT:    br i1 [[CMP]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]]
// CHECK-AMD:       omp.precond.then:
// CHECK-AMD-NEXT:    store i32 0, ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP3]], ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[NVPTX_NUM_THREADS:%.*]] = call i32 @__kmpc_get_hardware_num_threads_in_block()
// CHECK-AMD-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP5:%.*]] = load i32, ptr [[TMP4]], align 4
// CHECK-AMD-NEXT:    call void @__kmpc_distribute_static_init_4(ptr addrspacecast (ptr addrspace(1) @[[GLOB2:[0-9]+]] to ptr), i32 [[TMP5]], i32 91, ptr [[DOTOMP_IS_LAST_ASCAST]], ptr [[DOTOMP_COMB_LB_ASCAST]], ptr [[DOTOMP_COMB_UB_ASCAST]], ptr [[DOTOMP_STRIDE_ASCAST]], i32 1, i32 [[NVPTX_NUM_THREADS]])
// CHECK-AMD-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[CMP4:%.*]] = icmp sgt i32 [[TMP6]], [[TMP7]]
// CHECK-AMD-NEXT:    br i1 [[CMP4]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK-AMD:       cond.true:
// CHECK-AMD-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[COND_END:%.*]]
// CHECK-AMD:       cond.false:
// CHECK-AMD-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[COND_END]]
// CHECK-AMD:       cond.end:
// CHECK-AMD-NEXT:    [[COND:%.*]] = phi i32 [ [[TMP8]], [[COND_TRUE]] ], [ [[TMP9]], [[COND_FALSE]] ]
// CHECK-AMD-NEXT:    store i32 [[COND]], ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP10]], ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK-AMD:       omp.inner.for.cond:
// CHECK-AMD-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP12]], 1
// CHECK-AMD-NEXT:    [[CMP5:%.*]] = icmp slt i32 [[TMP11]], [[ADD]]
// CHECK-AMD-NEXT:    br i1 [[CMP5]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK-AMD:       omp.inner.for.body:
// CHECK-AMD-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP14:%.*]] = zext i32 [[TMP13]] to i64
// CHECK-AMD-NEXT:    [[TMP15:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP16:%.*]] = zext i32 [[TMP15]] to i64
// CHECK-AMD-NEXT:    [[TMP17:%.*]] = load i32, ptr [[N_ADDR_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP17]], ptr [[N_CASTED_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP18:%.*]] = load i64, ptr [[N_CASTED_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP19:%.*]] = load ptr, ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP20:%.*]] = getelementptr inbounds [4 x ptr], ptr [[CAPTURED_VARS_ADDRS_ASCAST]], i64 0, i64 0
// CHECK-AMD-NEXT:    [[TMP21:%.*]] = inttoptr i64 [[TMP14]] to ptr
// CHECK-AMD-NEXT:    store ptr [[TMP21]], ptr [[TMP20]], align 8
// CHECK-AMD-NEXT:    [[TMP22:%.*]] = getelementptr inbounds [4 x ptr], ptr [[CAPTURED_VARS_ADDRS_ASCAST]], i64 0, i64 1
// CHECK-AMD-NEXT:    [[TMP23:%.*]] = inttoptr i64 [[TMP16]] to ptr
// CHECK-AMD-NEXT:    store ptr [[TMP23]], ptr [[TMP22]], align 8
// CHECK-AMD-NEXT:    [[TMP24:%.*]] = getelementptr inbounds [4 x ptr], ptr [[CAPTURED_VARS_ADDRS_ASCAST]], i64 0, i64 2
// CHECK-AMD-NEXT:    [[TMP25:%.*]] = inttoptr i64 [[TMP18]] to ptr
// CHECK-AMD-NEXT:    store ptr [[TMP25]], ptr [[TMP24]], align 8
// CHECK-AMD-NEXT:    [[TMP26:%.*]] = getelementptr inbounds [4 x ptr], ptr [[CAPTURED_VARS_ADDRS_ASCAST]], i64 0, i64 3
// CHECK-AMD-NEXT:    store ptr [[TMP19]], ptr [[TMP26]], align 8
// CHECK-AMD-NEXT:    [[TMP27:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP28:%.*]] = load i32, ptr [[TMP27]], align 4
// CHECK-AMD-NEXT:    call void @__kmpc_parallel_51(ptr addrspacecast (ptr addrspace(1) @[[GLOB1]] to ptr), i32 [[TMP28]], i32 1, i32 -1, i32 -1, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14_omp_outlined_omp_outlined, ptr null, ptr [[CAPTURED_VARS_ADDRS_ASCAST]], i64 4)
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK-AMD:       omp.inner.for.inc:
// CHECK-AMD-NEXT:    [[TMP29:%.*]] = load i32, ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP30:%.*]] = load i32, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[ADD6:%.*]] = add nsw i32 [[TMP29]], [[TMP30]]
// CHECK-AMD-NEXT:    store i32 [[ADD6]], ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP31:%.*]] = load i32, ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP32:%.*]] = load i32, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[ADD7:%.*]] = add nsw i32 [[TMP31]], [[TMP32]]
// CHECK-AMD-NEXT:    store i32 [[ADD7]], ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP33:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP34:%.*]] = load i32, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[ADD8:%.*]] = add nsw i32 [[TMP33]], [[TMP34]]
// CHECK-AMD-NEXT:    store i32 [[ADD8]], ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP35:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP36:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[CMP9:%.*]] = icmp sgt i32 [[TMP35]], [[TMP36]]
// CHECK-AMD-NEXT:    br i1 [[CMP9]], label [[COND_TRUE10:%.*]], label [[COND_FALSE11:%.*]]
// CHECK-AMD:       cond.true10:
// CHECK-AMD-NEXT:    [[TMP37:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[COND_END12:%.*]]
// CHECK-AMD:       cond.false11:
// CHECK-AMD-NEXT:    [[TMP38:%.*]] = load i32, ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[COND_END12]]
// CHECK-AMD:       cond.end12:
// CHECK-AMD-NEXT:    [[COND13:%.*]] = phi i32 [ [[TMP37]], [[COND_TRUE10]] ], [ [[TMP38]], [[COND_FALSE11]] ]
// CHECK-AMD-NEXT:    store i32 [[COND13]], ptr [[DOTOMP_COMB_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP39:%.*]] = load i32, ptr [[DOTOMP_COMB_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP39]], ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK-AMD:       omp.inner.for.end:
// CHECK-AMD-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// CHECK-AMD:       omp.loop.exit:
// CHECK-AMD-NEXT:    [[TMP40:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP41:%.*]] = load i32, ptr [[TMP40]], align 4
// CHECK-AMD-NEXT:    call void @__kmpc_distribute_static_fini(ptr addrspacecast (ptr addrspace(1) @[[GLOB2]] to ptr), i32 [[TMP41]])
// CHECK-AMD-NEXT:    br label [[OMP_PRECOND_END]]
// CHECK-AMD:       omp.precond.end:
// CHECK-AMD-NEXT:    ret void
//
//
// CHECK-AMD-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_write_to_aligned_array_l14_omp_outlined_omp_outlined
// CHECK-AMD-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], i64 noundef [[DOTPREVIOUS_LB_:%.*]], i64 noundef [[DOTPREVIOUS_UB_:%.*]], i64 noundef [[N:%.*]], ptr noundef [[APTR:%.*]]) #[[ATTR1]] {
// CHECK-AMD-NEXT:  entry:
// CHECK-AMD-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTPREVIOUS_LB__ADDR:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTPREVIOUS_UB__ADDR:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[N_ADDR:%.*]] = alloca i64, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[APTR_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_IV:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[TMP:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_1:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[I:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_LB:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_UB:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[I4:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-AMD-NEXT:    [[DOTGLOBAL_TID__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTGLOBAL_TID__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTBOUND_TID__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTBOUND_TID__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTPREVIOUS_LB__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTPREVIOUS_LB__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTPREVIOUS_UB__ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTPREVIOUS_UB__ADDR]] to ptr
// CHECK-AMD-NEXT:    [[N_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[N_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[APTR_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[APTR_ADDR]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_IV_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_IV]] to ptr
// CHECK-AMD-NEXT:    [[TMP_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[TMP]] to ptr
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR__ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTCAPTURE_EXPR_]] to ptr
// CHECK-AMD-NEXT:    [[DOTCAPTURE_EXPR_1_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTCAPTURE_EXPR_1]] to ptr
// CHECK-AMD-NEXT:    [[I_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[I]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_LB_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_LB]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_UB_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_UB]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_STRIDE_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_STRIDE]] to ptr
// CHECK-AMD-NEXT:    [[DOTOMP_IS_LAST_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[DOTOMP_IS_LAST]] to ptr
// CHECK-AMD-NEXT:    [[I4_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[I4]] to ptr
// CHECK-AMD-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i64 [[DOTPREVIOUS_LB_]], ptr [[DOTPREVIOUS_LB__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i64 [[DOTPREVIOUS_UB_]], ptr [[DOTPREVIOUS_UB__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store i64 [[N]], ptr [[N_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    store ptr [[APTR]], ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP0:%.*]] = load i32, ptr [[N_ADDR_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP0]], ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP1:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP1]], 0
// CHECK-AMD-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-AMD-NEXT:    [[SUB2:%.*]] = sub nsw i32 [[DIV]], 1
// CHECK-AMD-NEXT:    store i32 [[SUB2]], ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 0, ptr [[I_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR__ASCAST]], align 4
// CHECK-AMD-NEXT:    [[CMP:%.*]] = icmp slt i32 0, [[TMP2]]
// CHECK-AMD-NEXT:    br i1 [[CMP]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]]
// CHECK-AMD:       omp.precond.then:
// CHECK-AMD-NEXT:    store i32 0, ptr [[DOTOMP_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_1_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP3]], ptr [[DOTOMP_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP4:%.*]] = load i64, ptr [[DOTPREVIOUS_LB__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[CONV:%.*]] = trunc i64 [[TMP4]] to i32
// CHECK-AMD-NEXT:    [[TMP5:%.*]] = load i64, ptr [[DOTPREVIOUS_UB__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[CONV3:%.*]] = trunc i64 [[TMP5]] to i32
// CHECK-AMD-NEXT:    store i32 [[CONV]], ptr [[DOTOMP_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[CONV3]], ptr [[DOTOMP_UB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 1, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP6:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP7:%.*]] = load i32, ptr [[TMP6]], align 4
// CHECK-AMD-NEXT:    call void @__kmpc_for_static_init_4(ptr addrspacecast (ptr addrspace(1) @[[GLOB3:[0-9]+]] to ptr), i32 [[TMP7]], i32 33, ptr [[DOTOMP_IS_LAST_ASCAST]], ptr [[DOTOMP_LB_ASCAST]], ptr [[DOTOMP_UB_ASCAST]], ptr [[DOTOMP_STRIDE_ASCAST]], i32 1, i32 1)
// CHECK-AMD-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_LB_ASCAST]], align 4
// CHECK-AMD-NEXT:    store i32 [[TMP8]], ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK-AMD:       omp.inner.for.cond:
// CHECK-AMD-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[CONV5:%.*]] = sext i32 [[TMP9]] to i64
// CHECK-AMD-NEXT:    [[TMP10:%.*]] = load i64, ptr [[DOTPREVIOUS_UB__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[CMP6:%.*]] = icmp ule i64 [[CONV5]], [[TMP10]]
// CHECK-AMD-NEXT:    br i1 [[CMP6]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK-AMD:       omp.inner.for.body:
// CHECK-AMD-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[MUL:%.*]] = mul nsw i32 [[TMP11]], 1
// CHECK-AMD-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// CHECK-AMD-NEXT:    store i32 [[ADD]], ptr [[I4_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP12:%.*]] = load i32, ptr [[I4_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP13:%.*]] = load ptr, ptr [[APTR_ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP14:%.*]] = load i32, ptr [[I4_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP14]] to i64
// CHECK-AMD-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds i32, ptr [[TMP13]], i64 [[IDXPROM]]
// CHECK-AMD-NEXT:    store i32 [[TMP12]], ptr [[ARRAYIDX]], align 4
// CHECK-AMD-NEXT:    br label [[OMP_BODY_CONTINUE:%.*]]
// CHECK-AMD:       omp.body.continue:
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK-AMD:       omp.inner.for.inc:
// CHECK-AMD-NEXT:    [[TMP15:%.*]] = load i32, ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[TMP16:%.*]] = load i32, ptr [[DOTOMP_STRIDE_ASCAST]], align 4
// CHECK-AMD-NEXT:    [[ADD8:%.*]] = add nsw i32 [[TMP15]], [[TMP16]]
// CHECK-AMD-NEXT:    store i32 [[ADD8]], ptr [[DOTOMP_IV_ASCAST]], align 4
// CHECK-AMD-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK-AMD:       omp.inner.for.end:
// CHECK-AMD-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// CHECK-AMD:       omp.loop.exit:
// CHECK-AMD-NEXT:    [[TMP17:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR_ASCAST]], align 8
// CHECK-AMD-NEXT:    [[TMP18:%.*]] = load i32, ptr [[TMP17]], align 4
// CHECK-AMD-NEXT:    call void @__kmpc_for_static_fini(ptr addrspacecast (ptr addrspace(1) @[[GLOB3]] to ptr), i32 [[TMP18]])
// CHECK-AMD-NEXT:    br label [[OMP_PRECOND_END]]
// CHECK-AMD:       omp.precond.end:
// CHECK-AMD-NEXT:    ret void
//
