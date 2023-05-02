#include <stdio.h>
#include <ctime>
#include <cstdlib>

long int calc(int n, int m) {
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
    return calc(n - m, m) + calc(n - 1, m - 1);
}

int main() {
    time_t start, end;
    int n = 200;
    int m = 17;
    time(&start);
    long int count = calc(n, m);
    time(&end);
    printf("%ld\n", count);
    printf("The time: %f seconds\n", difftime(end, start));
    return 0;
}