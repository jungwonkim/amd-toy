#define __HIP_PLATFORM_AMD__
#include <hip/hip_runtime.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int TARGET = argc > 1 ? atoi(argv[1]) : 0;

  hipDevice_t dev;
  hipModule_t module;
  char name[256];
  int ndevs;

  hipError_t err;

  printf("[%s:%d] err[%d] means SUCCESS\n", __FILE__, __LINE__, hipSuccess);
  err = hipInit(0);
  printf("[%s:%d] err[%d]\n", __FILE__, __LINE__, err);
  err = hipGetDeviceCount(&ndevs);
  printf("[%s:%d] err[%d] ndevs[%d]\n", __FILE__, __LINE__, err, ndevs);

  err = hipDeviceGet(&dev, TARGET);
  printf("[%s:%d] err[%d] TARGET[%d]\n", __FILE__, __LINE__, err, TARGET);

  err = hipDeviceGetName(name, sizeof(name), dev);
  printf("[%s:%d] err[%d] dev[%d] name[%s]\n", __FILE__, __LINE__, err, TARGET, name);

  err = hipSetDevice(TARGET);
  printf("[%s:%d] err[%d] dev[%d]\n", __FILE__, __LINE__, err, TARGET);

  err = hipModuleLoad(&module, "kernel.code");
  printf("[%s:%d] err[%d] dev[%d]\n", __FILE__, __LINE__, err, TARGET);

  return 0;
}

