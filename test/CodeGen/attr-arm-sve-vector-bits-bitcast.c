// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -mvscale-min=1 -mvscale-max=1 -O1 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-128
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -mvscale-min=2 -mvscale-max=2 -O1 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-256
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -mvscale-min=4 -mvscale-max=4 -O1 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-512

// REQUIRES: aarch64-registered-target

#include <arm_sve.h>

#define N __ARM_FEATURE_SVE_BITS

typedef svint64_t fixed_int64_t __attribute__((arm_sve_vector_bits(N)));
typedef svfloat64_t fixed_float64_t __attribute__((arm_sve_vector_bits(N)));
typedef svbfloat16_t fixed_bfloat16_t __attribute__((arm_sve_vector_bits(N)));
typedef svbool_t fixed_bool_t __attribute__((arm_sve_vector_bits(N)));

#define DEFINE_STRUCT(ty)   \
  struct struct_##ty {      \
    fixed_##ty##_t x, y[3]; \
  } struct_##ty;

DEFINE_STRUCT(int64)
DEFINE_STRUCT(float64)
DEFINE_STRUCT(bfloat16)
DEFINE_STRUCT(bool)

//===----------------------------------------------------------------------===//
// int64
//===----------------------------------------------------------------------===//

// CHECK-128-LABEL: @read_int64(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    [[TMP0:%.*]] = load <2 x i64>, ptr [[Y]], align 16, !tbaa [[TBAA2:![0-9]+]]
// CHECK-128-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.insert.nxv2i64.v2i64(<vscale x 2 x i64> undef, <2 x i64> [[TMP0]], i64 0)
// CHECK-128-NEXT:    ret <vscale x 2 x i64> [[CAST_SCALABLE]]
//
// CHECK-256-LABEL: @read_int64(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    [[TMP0:%.*]] = load <4 x i64>, ptr [[Y]], align 16, !tbaa [[TBAA2:![0-9]+]]
// CHECK-256-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.insert.nxv2i64.v4i64(<vscale x 2 x i64> undef, <4 x i64> [[TMP0]], i64 0)
// CHECK-256-NEXT:    ret <vscale x 2 x i64> [[CAST_SCALABLE]]
//
// CHECK-512-LABEL: @read_int64(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    [[TMP0:%.*]] = load <8 x i64>, ptr [[Y]], align 16, !tbaa [[TBAA2:![0-9]+]]
// CHECK-512-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.insert.nxv2i64.v8i64(<vscale x 2 x i64> undef, <8 x i64> [[TMP0]], i64 0)
// CHECK-512-NEXT:    ret <vscale x 2 x i64> [[CAST_SCALABLE]]
//
svint64_t read_int64(struct struct_int64 *s) {
  return s->y[0];
}

// CHECK-128-LABEL: @write_int64(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[CAST_FIXED:%.*]] = tail call <2 x i64> @llvm.vector.extract.v2i64.nxv2i64(<vscale x 2 x i64> [[X:%.*]], i64 0)
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    store <2 x i64> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    ret void
//
// CHECK-256-LABEL: @write_int64(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[CAST_FIXED:%.*]] = tail call <4 x i64> @llvm.vector.extract.v4i64.nxv2i64(<vscale x 2 x i64> [[X:%.*]], i64 0)
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    store <4 x i64> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    ret void
//
// CHECK-512-LABEL: @write_int64(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[CAST_FIXED:%.*]] = tail call <8 x i64> @llvm.vector.extract.v8i64.nxv2i64(<vscale x 2 x i64> [[X:%.*]], i64 0)
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    store <8 x i64> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    ret void
//
void write_int64(struct struct_int64 *s, svint64_t x) {
  s->y[0] = x;
}

//===----------------------------------------------------------------------===//
// float64
//===----------------------------------------------------------------------===//

// CHECK-128-LABEL: @read_float64(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    [[TMP0:%.*]] = load <2 x double>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x double> @llvm.vector.insert.nxv2f64.v2f64(<vscale x 2 x double> undef, <2 x double> [[TMP0]], i64 0)
// CHECK-128-NEXT:    ret <vscale x 2 x double> [[CAST_SCALABLE]]
//
// CHECK-256-LABEL: @read_float64(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    [[TMP0:%.*]] = load <4 x double>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x double> @llvm.vector.insert.nxv2f64.v4f64(<vscale x 2 x double> undef, <4 x double> [[TMP0]], i64 0)
// CHECK-256-NEXT:    ret <vscale x 2 x double> [[CAST_SCALABLE]]
//
// CHECK-512-LABEL: @read_float64(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    [[TMP0:%.*]] = load <8 x double>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x double> @llvm.vector.insert.nxv2f64.v8f64(<vscale x 2 x double> undef, <8 x double> [[TMP0]], i64 0)
// CHECK-512-NEXT:    ret <vscale x 2 x double> [[CAST_SCALABLE]]
//
svfloat64_t read_float64(struct struct_float64 *s) {
  return s->y[0];
}

// CHECK-128-LABEL: @write_float64(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[CAST_FIXED:%.*]] = tail call <2 x double> @llvm.vector.extract.v2f64.nxv2f64(<vscale x 2 x double> [[X:%.*]], i64 0)
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    store <2 x double> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    ret void
//
// CHECK-256-LABEL: @write_float64(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[CAST_FIXED:%.*]] = tail call <4 x double> @llvm.vector.extract.v4f64.nxv2f64(<vscale x 2 x double> [[X:%.*]], i64 0)
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    store <4 x double> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    ret void
//
// CHECK-512-LABEL: @write_float64(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[CAST_FIXED:%.*]] = tail call <8 x double> @llvm.vector.extract.v8f64.nxv2f64(<vscale x 2 x double> [[X:%.*]], i64 0)
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    store <8 x double> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    ret void
//
void write_float64(struct struct_float64 *s, svfloat64_t x) {
  s->y[0] = x;
}

//===----------------------------------------------------------------------===//
// bfloat16
//===----------------------------------------------------------------------===//

// CHECK-128-LABEL: @read_bfloat16(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    [[TMP0:%.*]] = load <8 x bfloat>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.v8bf16(<vscale x 8 x bfloat> undef, <8 x bfloat> [[TMP0]], i64 0)
// CHECK-128-NEXT:    ret <vscale x 8 x bfloat> [[CAST_SCALABLE]]
//
// CHECK-256-LABEL: @read_bfloat16(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    [[TMP0:%.*]] = load <16 x bfloat>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.v16bf16(<vscale x 8 x bfloat> undef, <16 x bfloat> [[TMP0]], i64 0)
// CHECK-256-NEXT:    ret <vscale x 8 x bfloat> [[CAST_SCALABLE]]
//
// CHECK-512-LABEL: @read_bfloat16(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    [[TMP0:%.*]] = load <32 x bfloat>, ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.insert.nxv8bf16.v32bf16(<vscale x 8 x bfloat> undef, <32 x bfloat> [[TMP0]], i64 0)
// CHECK-512-NEXT:    ret <vscale x 8 x bfloat> [[CAST_SCALABLE]]
//
svbfloat16_t read_bfloat16(struct struct_bfloat16 *s) {
  return s->y[0];
}

// CHECK-128-LABEL: @write_bfloat16(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[CAST_FIXED:%.*]] = tail call <8 x bfloat> @llvm.vector.extract.v8bf16.nxv8bf16(<vscale x 8 x bfloat> [[X:%.*]], i64 0)
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 16
// CHECK-128-NEXT:    store <8 x bfloat> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    ret void
//
// CHECK-256-LABEL: @write_bfloat16(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[CAST_FIXED:%.*]] = tail call <16 x bfloat> @llvm.vector.extract.v16bf16.nxv8bf16(<vscale x 8 x bfloat> [[X:%.*]], i64 0)
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 32
// CHECK-256-NEXT:    store <16 x bfloat> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    ret void
//
// CHECK-512-LABEL: @write_bfloat16(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[CAST_FIXED:%.*]] = tail call <32 x bfloat> @llvm.vector.extract.v32bf16.nxv8bf16(<vscale x 8 x bfloat> [[X:%.*]], i64 0)
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 64
// CHECK-512-NEXT:    store <32 x bfloat> [[CAST_FIXED]], ptr [[Y]], align 16, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    ret void
//
void write_bfloat16(struct struct_bfloat16 *s, svbfloat16_t x) {
  s->y[0] = x;
}

//===----------------------------------------------------------------------===//
// bool
//===----------------------------------------------------------------------===//

// CHECK-128-LABEL: @read_bool(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 2
// CHECK-128-NEXT:    [[TMP0:%.*]] = load <2 x i8>, ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i8> @llvm.vector.insert.nxv2i8.v2i8(<vscale x 2 x i8> undef, <2 x i8> [[TMP0]], i64 0)
// CHECK-128-NEXT:    [[TMP1:%.*]] = bitcast <vscale x 2 x i8> [[CAST_SCALABLE]] to <vscale x 16 x i1>
// CHECK-128-NEXT:    ret <vscale x 16 x i1> [[TMP1]]
//
// CHECK-256-LABEL: @read_bool(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 4
// CHECK-256-NEXT:    [[TMP0:%.*]] = load <4 x i8>, ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i8> @llvm.vector.insert.nxv2i8.v4i8(<vscale x 2 x i8> undef, <4 x i8> [[TMP0]], i64 0)
// CHECK-256-NEXT:    [[TMP1:%.*]] = bitcast <vscale x 2 x i8> [[CAST_SCALABLE]] to <vscale x 16 x i1>
// CHECK-256-NEXT:    ret <vscale x 16 x i1> [[TMP1]]
//
// CHECK-512-LABEL: @read_bool(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 8
// CHECK-512-NEXT:    [[TMP0:%.*]] = load <8 x i8>, ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    [[CAST_SCALABLE:%.*]] = tail call <vscale x 2 x i8> @llvm.vector.insert.nxv2i8.v8i8(<vscale x 2 x i8> undef, <8 x i8> [[TMP0]], i64 0)
// CHECK-512-NEXT:    [[TMP1:%.*]] = bitcast <vscale x 2 x i8> [[CAST_SCALABLE]] to <vscale x 16 x i1>
// CHECK-512-NEXT:    ret <vscale x 16 x i1> [[TMP1]]
//
svbool_t read_bool(struct struct_bool *s) {
  return s->y[0];
}

// CHECK-128-LABEL: @write_bool(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[TMP0:%.*]] = bitcast <vscale x 16 x i1> [[X:%.*]] to <vscale x 2 x i8>
// CHECK-128-NEXT:    [[CAST_FIXED:%.*]] = tail call <2 x i8> @llvm.vector.extract.v2i8.nxv2i8(<vscale x 2 x i8> [[TMP0]], i64 0)
// CHECK-128-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 2
// CHECK-128-NEXT:    store <2 x i8> [[CAST_FIXED]], ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-128-NEXT:    ret void
//
// CHECK-256-LABEL: @write_bool(
// CHECK-256-NEXT:  entry:
// CHECK-256-NEXT:    [[TMP0:%.*]] = bitcast <vscale x 16 x i1> [[X:%.*]] to <vscale x 2 x i8>
// CHECK-256-NEXT:    [[CAST_FIXED:%.*]] = tail call <4 x i8> @llvm.vector.extract.v4i8.nxv2i8(<vscale x 2 x i8> [[TMP0]], i64 0)
// CHECK-256-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 4
// CHECK-256-NEXT:    store <4 x i8> [[CAST_FIXED]], ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-256-NEXT:    ret void
//
// CHECK-512-LABEL: @write_bool(
// CHECK-512-NEXT:  entry:
// CHECK-512-NEXT:    [[TMP0:%.*]] = bitcast <vscale x 16 x i1> [[X:%.*]] to <vscale x 2 x i8>
// CHECK-512-NEXT:    [[CAST_FIXED:%.*]] = tail call <8 x i8> @llvm.vector.extract.v8i8.nxv2i8(<vscale x 2 x i8> [[TMP0]], i64 0)
// CHECK-512-NEXT:    [[Y:%.*]] = getelementptr inbounds i8, ptr [[S:%.*]], i64 8
// CHECK-512-NEXT:    store <8 x i8> [[CAST_FIXED]], ptr [[Y]], align 2, !tbaa [[TBAA2]]
// CHECK-512-NEXT:    ret void
//
void write_bool(struct struct_bool *s, svbool_t x) {
  s->y[0] = x;
}
