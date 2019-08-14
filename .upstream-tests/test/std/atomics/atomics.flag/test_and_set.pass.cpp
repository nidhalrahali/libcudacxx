//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads, pre-sm-60

// <cuda/std/atomic>

// struct atomic_flag

// bool test_and_set(memory_order = memory_order_seq_cst);
// bool test_and_set(memory_order = memory_order_seq_cst) volatile;

#include <cuda/std/atomic>
#include <cuda/std/cassert>

int main(int, char**)
{
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set() == 0);
        assert(f.test_and_set() == 1);
    }
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_relaxed) == 0);
        assert(f.test_and_set(cuda::std::memory_order_relaxed) == 1);
    }
#ifndef __INTEL_COMPILER
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_consume) == 0);
        assert(f.test_and_set(cuda::std::memory_order_consume) == 1);
    }
#endif
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_acquire) == 0);
        assert(f.test_and_set(cuda::std::memory_order_acquire) == 1);
    }
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_release) == 0);
        assert(f.test_and_set(cuda::std::memory_order_release) == 1);
    }
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_acq_rel) == 0);
        assert(f.test_and_set(cuda::std::memory_order_acq_rel) == 1);
    }
    {
        cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_seq_cst) == 0);
        assert(f.test_and_set(cuda::std::memory_order_seq_cst) == 1);
    }
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set() == 0);
        assert(f.test_and_set() == 1);
    }
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_relaxed) == 0);
        assert(f.test_and_set(cuda::std::memory_order_relaxed) == 1);
    }
#ifndef __INTEL_COMPILER
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_consume) == 0);
        assert(f.test_and_set(cuda::std::memory_order_consume) == 1);
    }
#endif
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_acquire) == 0);
        assert(f.test_and_set(cuda::std::memory_order_acquire) == 1);
    }
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_release) == 0);
        assert(f.test_and_set(cuda::std::memory_order_release) == 1);
    }
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_acq_rel) == 0);
        assert(f.test_and_set(cuda::std::memory_order_acq_rel) == 1);
    }
    {
        volatile cuda::std::atomic_flag f;
        f.clear();
        assert(f.test_and_set(cuda::std::memory_order_seq_cst) == 0);
        assert(f.test_and_set(cuda::std::memory_order_seq_cst) == 1);
    }

  return 0;
}
