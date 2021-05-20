#include <hip/hip_runtime.h>

extern "C" __global__ void vecadd(float* C, float* A, float* B) {
    int i = hipBlockDim_x * hipBlockIdx_x + hipThreadIdx_x;
    C[i] = A[i] + B[i];
}

