#include <stdio.h>
#include <omp.h>
#include <cstdint>

long int b(int n, int m) {
    if (m > n) {
        return 0;
    }
    if (m == 1) {
        return 1;
    }
    if (n == m) {
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
    return b(n - m, m) + b(n - 1, m - 1);
}

int main() {
    int n = 200;
    int m = 17;
    long int count = b(n, m);
    printf("%ld\n", count);
    return 0;
}