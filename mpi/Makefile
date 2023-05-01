.PHONY: compile-mpi
compile-mpi:
	@mpic++ mpi.cpp -o mpi

.PHONY: run-mpi
run-mpi:
	@mpiexec --oversubscribe -n 17 ./mpi