.PHONY: compile-openmp
compile-openmp:
	@g++ -o open_mp -fopenmp open_mp.cpp

.PHONY: run-openmp
run-openmp:
	@OMP_NUM_THREADS=8 ./open_mp
