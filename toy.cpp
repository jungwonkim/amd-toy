#define __HIP_PLATFORM_AMD__
#include <hip/hip_runtime.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int TARGET = argc > 1 ? atoi(argv[1]) : 0;
  hipDevice_t dev;
  hipModule_t module;
  int ndevs;

  hipError_t err;

  hipInit(0);
  hipGetDeviceCount(&ndevs);
  printf("[%s:%d] ndevs[%d] TARGET[%d]\n", __FILE__, __LINE__, ndevs, TARGET);

  char name[256];
  int version;

  hipDeviceGet(&dev, TARGET);

  err = hipDeviceGetName(name, sizeof(name), dev);
  printf("[%s:%d] err[%d] dev[%d] name[%s]\n", __FILE__, __LINE__, err, TARGET, name);

  err = hipSetDevice(TARGET);
  printf("[%s:%d] err[%d] dev[%d]\n", __FILE__, __LINE__, err, TARGET);

  err = hipModuleLoad(&module, "kernel.code");
  printf("[%s:%d] err[%d] dev[%d]\n", __FILE__, __LINE__, err, TARGET);

  return 0;
}

