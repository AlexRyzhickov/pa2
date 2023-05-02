#include <stdio.h>
#include <omp.h>
#include <cstdint>

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

int main() {
    int n = 200;
    int m = 17;
    printf("num_threads %d\n", m);
    omp_set_num_threads(m);

    long int count = 0;
#pragma omp parallel
    {
        long int v = calc(n - m, omp_get_thread_num() + 1);
#pragma omp atomic
        count = count + v;
    }
    printf("%ld\n", count);
    return 0;
}
