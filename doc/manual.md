# LibNC Manual Overview

This document summarizes the original LibNC manual written by Fabrice Bellard.

Back to the documentation index: [libnc.md](./libnc.md)

For the exported API reference, see [api_reference.md](./api_reference.md).

## Contents

- [1. What LibNC is](#1-what-libnc-is)
- [2. Original manual overview](#2-original-manual-overview)
  - [2.1 Usage](#21-usage)
  - [2.2 Main concepts](#22-main-concepts)
  - [2.3 Tensor layout](#23-tensor-layout)
  - [2.4 Automatic differentiation engine](#24-automatic-differentiation-engine)
- [3. Implementation details from the original manual](#3-implementation-details-from-the-original-manual)
  - [3.1 Determinism](#31-determinism)
  - [3.2 Reproducibility](#32-reproducibility)
  - [3.3 Compute graph optimization](#33-compute-graph-optimization)
  - [3.4 CUDA backend](#34-cuda-backend)
  - [3.5 BF16 support](#35-bf16-support)

Source notes:
- original manual: `doc/libnc.html` from the 2021 release
- reconstruction status: [IMPLEMENTATION_CHECKLIST.md](https://github.com/Mashinow/libnc/blob/master/IMPLEMENTATION_CHECKLIST.md)
- current code layout: `src/`, `tests/`, `decompile/`

## 1. What LibNC is

LibNC is a C library for tensor manipulation and automatic differentiation. The original project targets machine-learning style workloads such as LSTM and Transformers. The design goals emphasized:

- a small C API
- a shared-library / DLL style deployment model
- define-by-run automatic differentiation
- high performance on CPU and GPU
- optimized float32 and BF16 support
- deterministic behavior
- reproducibility on CPU across platforms
- compute-graph optimization for online learning

This reconstruction follows the same architecture, with a CPU implementation in `src/` and an optional CUDA backend source path.

## 2. Original manual overview

### 2.1 Usage

LibNC is meant to be linked as a shared library or DLL. The public API is pure C, so it can be used from C, C++, and foreign-function interfaces.

The upstream documentation describes the original project as requiring x86 with AVX2, and as offering CUDA support as an optional backend. In this reconstruction:

- the CPU path is the primary implementation
- the CUDA backend is optional
- the shipped tests cover CPU behavior directly and CUDA behavior when the backend is present

### 2.2 Main concepts

- `NCContext` is the library instance. It owns runtime state, devices, random generators, and parallel helpers.
- `NCDevice` represents a compute device, currently CPU or CUDA-compatible.
- `NCTensor` is the main data object. It carries shape, type, buffer, graph links, and gradients.
- `NCTensorBuffer` is the underlying storage that may be shared between tensors.

Most tensor operations require operands on the same device.

### 2.3 Tensor layout

LibNC uses a layout convention where the smallest dimension comes first and matrices are stored in a column-major style. That affects:

- `nc_matmul`
- slicing and concatenation
- permutation and transpose
- serialization

New tensors are contiguous unless a view or alias changes the layout.

### 2.4 Automatic differentiation engine

LibNC uses define-by-run autodiff:

- the graph is built as operations are executed
- user-created tensors normally do not start with a graph parent
- parameter tensors are attached to the graph explicitly
- backward traversal propagates gradients from outputs to inputs

The shipped tests exercise both standard gradients and Hessian-vector style flows.

## 3. Implementation details from the original manual

### 3.1 Determinism

The upstream project emphasizes deterministic outputs: the same computation on the same system should produce the same result across runs. The reconstruction keeps that property for the CPU path used by the tests.

### 3.2 Reproducibility

The manual distinguishes determinism from reproducibility across CPU brands, OSes, and thread counts. The original documentation states that CPU results were intended to be reproducible, while GPU results could differ because of hardware-specific behavior. This reconstruction keeps the same distinction in mind.

### 3.3 Compute graph optimization

LibNC includes graph optimizations such as matrix-product factorization. The original manual specifically mentions `nc_concat_optimization()` for online learning, where sequential evaluation steps can be combined to improve compute-device utilization.

This reconstruction preserves that behavior at the API level, but some graph edge cases are still simplified compared to the original binary. See the implementation checklist for the current status.

### 3.4 CUDA backend

The original documentation describes NVIDIA CUDA support as optional and contained in a separate `libnc_cuda` component. That backend depends on CUDA and cuBLAS. Only Ampere GPUs were originally supported to take advantage of hardware BF16 support.

The reconstructed project keeps the same split:

- `src/libnc_cuda_backend.c` implements the CUDA backend source
- `src/libnc_cuda_loader.c` discovers and loads the backend at runtime
- if the backend is missing, the library falls back to the compatibility path

### 3.5 BF16 support

BF16 is a truncated 16-bit float format derived from float32. The original manual says BF16 is supported on both CPU and GPU, and that the ADAM optimizer keeps the low 16 bits of parameters to avoid precision loss during updates.

This reconstruction follows the same idea:

- BF16 tensors are handled on the CPU path
- BF16 parameters keep a float32 shadow copy for optimizer updates
- the GPU backend has BF16-aware tensor kernels where the backend is present

## 4. Verified status

- Windows 10 has been validated in this reconstruction
- Linux / WSL support is documented and is being checked separately
