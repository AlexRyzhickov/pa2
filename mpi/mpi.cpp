#include <stdio.h>
#include <iostream>
#include "mpi.h"

long int calc(long int n, long int m) {
    if (m > n) {
        return 0;
    }
    if (m == 1) {
        return 1;
    }
    if (n == m) {
        return 1;
    }
    if (m == 2) {
        return n / 2;
    }
    if (m == 3) {
        return (n * n + 3) / 12;
    }
    return calc(n - m, m) + calc(n - 1, m - 1);
}

int main(int argc, char *argv[]) {

    int n = 200;
    int m = 17;

    int ProcNum, ProcRank;
    long int RecvRank;
    MPI_Status Status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
    double time = MPI_Wtime();
    if (ProcRank == 0) {
        long int v = calc(n - m, ProcRank + 1);
        for (int i = 1; i < ProcNum; i++) {
            MPI_Recv(&RecvRank, 1, MPI_LONG, MPI_ANY_SOURCE, i, MPI_COMM_WORLD, &Status);
            v = v + RecvRank;
        }
        printf("Count: %ld\n", v);
    } else {
        long int v = calc(n - m, ProcRank + 1);
        MPI_Send(&v, 1, MPI_LONG, 0, ProcRank, MPI_COMM_WORLD);
    }

    if (ProcRank == 0) {
        printf("time: %.10lf\n", MPI_Wtime() - time);
    }


    MPI_Finalize();
    return 0;
}