all:toy kernel.code

toy: toy.cpp
	g++ -I /opt/rocm/hip/include/ -o $@ $? -L /opt/rocm/hip/lib/ -lamdhip64

kernel.code:kernel.cpp
	hipcc --genco -o $@ $^

clean:
	rm -f toy kernel.code
