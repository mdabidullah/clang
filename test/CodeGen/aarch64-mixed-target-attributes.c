// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --check-attributes --check-globals --include-generated-funcs
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature -v9.5a -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature -fmv -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK-NOFMV

// The following is guarded because in NOFMV we get an error for redefining the default.
#ifdef __HAVE_FUNCTION_MULTI_VERSIONING
int explicit_default(void) { return 0; }
__attribute__((target_version("jscvt"))) int explicit_default(void) { return 1; }
__attribute__((target_clones("dotprod", "lse"))) int explicit_default(void) { return 2; }
__attribute__((target_version("rdma"))) int explicit_default(void) { return 3; }

int foo(void) { return explicit_default(); }
#endif

__attribute__((target_version("jscvt"))) int implicit_default(void) { return 1; }
__attribute__((target_clones("dotprod", "lse"))) int implicit_default(void) { return 2; }
__attribute__((target_version("rdma"))) int implicit_default(void) { return 3; }

int bar(void) { return implicit_default(); }

// These shouldn't generate anything.
int unused_version_declarations(void);
__attribute__((target_clones("dotprod", "lse"))) int unused_version_declarations(void);
__attribute__((target_version("jscvt"))) int unused_version_declarations(void);

// These should generate the default (mangled) version and the resolver.
int default_def_with_version_decls(void) { return 0; }
__attribute__((target_clones("dotprod", "lse"))) int default_def_with_version_decls(void);
__attribute__((target_version("jscvt"))) int default_def_with_version_decls(void);

//.
// CHECK: @__aarch64_cpu_features = external dso_local global { i64 }
// CHECK: @explicit_default.ifunc = weak_odr alias i32 (), ptr @explicit_default
// CHECK: @implicit_default.ifunc = weak_odr alias i32 (), ptr @implicit_default
// CHECK: @default_def_with_version_decls.ifunc = weak_odr alias i32 (), ptr @default_def_with_version_decls
// CHECK: @explicit_default = weak_odr ifunc i32 (), ptr @explicit_default.resolver
// CHECK: @implicit_default = weak_odr ifunc i32 (), ptr @implicit_default.resolver
// CHECK: @default_def_with_version_decls = weak_odr ifunc i32 (), ptr @default_def_with_version_decls.resolver
//.
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@explicit_default.default
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 0
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@explicit_default._Mjscvt
// CHECK-SAME: () #[[ATTR1:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 1
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@explicit_default._Mdotprod
// CHECK-SAME: () #[[ATTR2:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 2
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@explicit_default._Mlse
// CHECK-SAME: () #[[ATTR3:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 2
//
//
// CHECK-LABEL: define {{[^@]+}}@explicit_default.resolver() comdat {
// CHECK-NEXT:  resolver_entry:
// CHECK-NEXT:    call void @__init_cpu_features_resolver()
// CHECK-NEXT:    [[TMP0:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP1:%.*]] = and i64 [[TMP0]], 1048576
// CHECK-NEXT:    [[TMP2:%.*]] = icmp eq i64 [[TMP1]], 1048576
// CHECK-NEXT:    [[TMP3:%.*]] = and i1 true, [[TMP2]]
// CHECK-NEXT:    br i1 [[TMP3]], label [[RESOLVER_RETURN:%.*]], label [[RESOLVER_ELSE:%.*]]
// CHECK:       resolver_return:
// CHECK-NEXT:    ret ptr @explicit_default._Mjscvt
// CHECK:       resolver_else:
// CHECK-NEXT:    [[TMP4:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP5:%.*]] = and i64 [[TMP4]], 64
// CHECK-NEXT:    [[TMP6:%.*]] = icmp eq i64 [[TMP5]], 64
// CHECK-NEXT:    [[TMP7:%.*]] = and i1 true, [[TMP6]]
// CHECK-NEXT:    br i1 [[TMP7]], label [[RESOLVER_RETURN1:%.*]], label [[RESOLVER_ELSE2:%.*]]
// CHECK:       resolver_return1:
// CHECK-NEXT:    ret ptr @explicit_default._Mrdm
// CHECK:       resolver_else2:
// CHECK-NEXT:    [[TMP8:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP9:%.*]] = and i64 [[TMP8]], 16
// CHECK-NEXT:    [[TMP10:%.*]] = icmp eq i64 [[TMP9]], 16
// CHECK-NEXT:    [[TMP11:%.*]] = and i1 true, [[TMP10]]
// CHECK-NEXT:    br i1 [[TMP11]], label [[RESOLVER_RETURN3:%.*]], label [[RESOLVER_ELSE4:%.*]]
// CHECK:       resolver_return3:
// CHECK-NEXT:    ret ptr @explicit_default._Mdotprod
// CHECK:       resolver_else4:
// CHECK-NEXT:    [[TMP12:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP13:%.*]] = and i64 [[TMP12]], 128
// CHECK-NEXT:    [[TMP14:%.*]] = icmp eq i64 [[TMP13]], 128
// CHECK-NEXT:    [[TMP15:%.*]] = and i1 true, [[TMP14]]
// CHECK-NEXT:    br i1 [[TMP15]], label [[RESOLVER_RETURN5:%.*]], label [[RESOLVER_ELSE6:%.*]]
// CHECK:       resolver_return5:
// CHECK-NEXT:    ret ptr @explicit_default._Mlse
// CHECK:       resolver_else6:
// CHECK-NEXT:    ret ptr @explicit_default.default
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@explicit_default._Mrdm
// CHECK-SAME: () #[[ATTR4:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 3
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@foo
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @explicit_default()
// CHECK-NEXT:    ret i32 [[CALL]]
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@implicit_default._Mjscvt
// CHECK-SAME: () #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 1
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@implicit_default._Mdotprod
// CHECK-SAME: () #[[ATTR2]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 2
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@implicit_default._Mlse
// CHECK-SAME: () #[[ATTR3]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 2
//
//
// CHECK-LABEL: define {{[^@]+}}@implicit_default.resolver() comdat {
// CHECK-NEXT:  resolver_entry:
// CHECK-NEXT:    call void @__init_cpu_features_resolver()
// CHECK-NEXT:    [[TMP0:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP1:%.*]] = and i64 [[TMP0]], 1048576
// CHECK-NEXT:    [[TMP2:%.*]] = icmp eq i64 [[TMP1]], 1048576
// CHECK-NEXT:    [[TMP3:%.*]] = and i1 true, [[TMP2]]
// CHECK-NEXT:    br i1 [[TMP3]], label [[RESOLVER_RETURN:%.*]], label [[RESOLVER_ELSE:%.*]]
// CHECK:       resolver_return:
// CHECK-NEXT:    ret ptr @implicit_default._Mjscvt
// CHECK:       resolver_else:
// CHECK-NEXT:    [[TMP4:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP5:%.*]] = and i64 [[TMP4]], 64
// CHECK-NEXT:    [[TMP6:%.*]] = icmp eq i64 [[TMP5]], 64
// CHECK-NEXT:    [[TMP7:%.*]] = and i1 true, [[TMP6]]
// CHECK-NEXT:    br i1 [[TMP7]], label [[RESOLVER_RETURN1:%.*]], label [[RESOLVER_ELSE2:%.*]]
// CHECK:       resolver_return1:
// CHECK-NEXT:    ret ptr @implicit_default._Mrdm
// CHECK:       resolver_else2:
// CHECK-NEXT:    [[TMP8:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP9:%.*]] = and i64 [[TMP8]], 16
// CHECK-NEXT:    [[TMP10:%.*]] = icmp eq i64 [[TMP9]], 16
// CHECK-NEXT:    [[TMP11:%.*]] = and i1 true, [[TMP10]]
// CHECK-NEXT:    br i1 [[TMP11]], label [[RESOLVER_RETURN3:%.*]], label [[RESOLVER_ELSE4:%.*]]
// CHECK:       resolver_return3:
// CHECK-NEXT:    ret ptr @implicit_default._Mdotprod
// CHECK:       resolver_else4:
// CHECK-NEXT:    [[TMP12:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP13:%.*]] = and i64 [[TMP12]], 128
// CHECK-NEXT:    [[TMP14:%.*]] = icmp eq i64 [[TMP13]], 128
// CHECK-NEXT:    [[TMP15:%.*]] = and i1 true, [[TMP14]]
// CHECK-NEXT:    br i1 [[TMP15]], label [[RESOLVER_RETURN5:%.*]], label [[RESOLVER_ELSE6:%.*]]
// CHECK:       resolver_return5:
// CHECK-NEXT:    ret ptr @implicit_default._Mlse
// CHECK:       resolver_else6:
// CHECK-NEXT:    ret ptr @implicit_default.default
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@implicit_default._Mrdm
// CHECK-SAME: () #[[ATTR4]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 3
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@bar
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CALL:%.*]] = call i32 @implicit_default()
// CHECK-NEXT:    ret i32 [[CALL]]
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@default_def_with_version_decls.default
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 0
//
//
// CHECK: Function Attrs: noinline nounwind optnone
// CHECK-LABEL: define {{[^@]+}}@implicit_default.default
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    ret i32 2
//
//
// CHECK-LABEL: define {{[^@]+}}@default_def_with_version_decls.resolver() comdat {
// CHECK-NEXT:  resolver_entry:
// CHECK-NEXT:    call void @__init_cpu_features_resolver()
// CHECK-NEXT:    [[TMP0:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP1:%.*]] = and i64 [[TMP0]], 1048576
// CHECK-NEXT:    [[TMP2:%.*]] = icmp eq i64 [[TMP1]], 1048576
// CHECK-NEXT:    [[TMP3:%.*]] = and i1 true, [[TMP2]]
// CHECK-NEXT:    br i1 [[TMP3]], label [[RESOLVER_RETURN:%.*]], label [[RESOLVER_ELSE:%.*]]
// CHECK:       resolver_return:
// CHECK-NEXT:    ret ptr @default_def_with_version_decls._Mjscvt
// CHECK:       resolver_else:
// CHECK-NEXT:    [[TMP4:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP5:%.*]] = and i64 [[TMP4]], 16
// CHECK-NEXT:    [[TMP6:%.*]] = icmp eq i64 [[TMP5]], 16
// CHECK-NEXT:    [[TMP7:%.*]] = and i1 true, [[TMP6]]
// CHECK-NEXT:    br i1 [[TMP7]], label [[RESOLVER_RETURN1:%.*]], label [[RESOLVER_ELSE2:%.*]]
// CHECK:       resolver_return1:
// CHECK-NEXT:    ret ptr @default_def_with_version_decls._Mdotprod
// CHECK:       resolver_else2:
// CHECK-NEXT:    [[TMP8:%.*]] = load i64, ptr @__aarch64_cpu_features, align 8
// CHECK-NEXT:    [[TMP9:%.*]] = and i64 [[TMP8]], 128
// CHECK-NEXT:    [[TMP10:%.*]] = icmp eq i64 [[TMP9]], 128
// CHECK-NEXT:    [[TMP11:%.*]] = and i1 true, [[TMP10]]
// CHECK-NEXT:    br i1 [[TMP11]], label [[RESOLVER_RETURN3:%.*]], label [[RESOLVER_ELSE4:%.*]]
// CHECK:       resolver_return3:
// CHECK-NEXT:    ret ptr @default_def_with_version_decls._Mlse
// CHECK:       resolver_else4:
// CHECK-NEXT:    ret ptr @default_def_with_version_decls.default
//
//
// CHECK-NOFMV: Function Attrs: noinline nounwind optnone
// CHECK-NOFMV-LABEL: define {{[^@]+}}@implicit_default
// CHECK-NOFMV-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NOFMV-NEXT:  entry:
// CHECK-NOFMV-NEXT:    ret i32 2
//
//
// CHECK-NOFMV: Function Attrs: noinline nounwind optnone
// CHECK-NOFMV-LABEL: define {{[^@]+}}@bar
// CHECK-NOFMV-SAME: () #[[ATTR0]] {
// CHECK-NOFMV-NEXT:  entry:
// CHECK-NOFMV-NEXT:    [[CALL:%.*]] = call i32 @implicit_default()
// CHECK-NOFMV-NEXT:    ret i32 [[CALL]]
//
//
// CHECK-NOFMV: Function Attrs: noinline nounwind optnone
// CHECK-NOFMV-LABEL: define {{[^@]+}}@default_def_with_version_decls
// CHECK-NOFMV-SAME: () #[[ATTR0]] {
// CHECK-NOFMV-NEXT:  entry:
// CHECK-NOFMV-NEXT:    ret i32 0
//
//.
// CHECK: attributes #[[ATTR0]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="-v9.5a" }
// CHECK: attributes #[[ATTR1]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+fp-armv8,+jsconv,+neon,-v9.5a" }
// CHECK: attributes #[[ATTR2]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+dotprod,+fp-armv8,+neon,-v9.5a" }
// CHECK: attributes #[[ATTR3]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+lse,-v9.5a" }
// CHECK: attributes #[[ATTR4]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+fp-armv8,+neon,+rdm,-v9.5a" }
// CHECK: attributes #[[ATTR5:[0-9]+]] = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+dotprod,+fp-armv8,+neon,-v9.5a" }
// CHECK: attributes #[[ATTR6:[0-9]+]] = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+fp-armv8,+jsconv,+neon,-v9.5a" }
// CHECK: attributes #[[ATTR7:[0-9]+]] = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="-v9.5a" }
// CHECK: attributes #[[ATTR8:[0-9]+]] = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+lse,-v9.5a" }
//.
// CHECK-NOFMV: attributes #[[ATTR0]] = { noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="-fmv" }
//.
// CHECK: [[META0:![0-9]+]] = !{i32 1, !"wchar_size", i32 4}
// CHECK: [[META1:![0-9]+]] = !{!"{{.*}}clang version {{.*}}"}
//.
// CHECK-NOFMV: [[META0:![0-9]+]] = !{i32 1, !"wchar_size", i32 4}
// CHECK-NOFMV: [[META1:![0-9]+]] = !{!"{{.*}}clang version {{.*}}"}
//.
