ROCM_PATH?=/opt/rocm

all:toy kernel.code

toy:toy.cpp
	g++ -I $(ROCM_PATH)/include -o $@ $? -L $(ROCM_PATH)/lib -lamdhip64

kernel.code:kernel.cpp
	hipcc --genco -o $@ $?

clean:
	rm -f toy kernel.code

