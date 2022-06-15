#define C 1
#define N 100000
#define A 69069
#include <stdio.h>
#include <stdlib.h>

int main() {
    int p[] = { 0.2, 0.4, 0.15, 0.25 };
    int arr[4] = { 0, 0, 0, 0 };
    double sum[4] = { 0.2, 0.6, 0.75, 1.0 };
    for (int i = 0; i < N; i++) {
        double result = (double)rand() / (double)RAND_MAX;     
        //printf("%lf\n", result);
        for (int j = 0; j < sizeof(p) / sizeof(int); j++) {
            if (result < sum[j]) {
                arr[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d: %d\n", i + 1, arr[i]);
    }

    int result[100];
    for (int i = 0; i < 100; i++)
        result[i] = 0;
    for (int i = 0; i < N; i++) {
        double tmp = (double)(100.0 * (double)((double)rand() / (double)RAND_MAX)) + 50.0;
        int value = (int)tmp;
        if(value < 150)
            result[value-50]++;
    }
    for (int i = 0; i < 100; i++)
        printf("%d: %d\n", i + 50, result[i]);
    return 0;
}