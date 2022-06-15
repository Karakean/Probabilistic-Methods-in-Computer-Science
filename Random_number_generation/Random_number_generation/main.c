#include <stdio.h>
#include <math.h>
#define C 1
#define N 100000
#define A 69069


//long long generator(long long Xn, long long M);

long long generator(long long Xn, long long M) {
    return (A * Xn + C) % M;
}

int xor(int x, int y) {
    if ((x && !y) || (!x && y))
        return 1;
    return 0;
}

long long convert_array(int* x)
{
    double result = 0;
    for (int i = 0; i < 31; i++)
    {
        if (x[i] == 1)
            result += pow(2.0, 30.0 - (double)i);
    }
    return (long long)result;
}

int main()
{
    //2.2
    long long M = pow(2.0, 31.0) - 1;
    long long x = 2137;
    long long arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        x = generator(x, M);
        arr[10 * x / M]++;
    }
    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
        printf("%d %lld\n", i, i[arr]);
    }
    printf("Combined: %lld\n\n", sum);

    //2.6
    int p = 10;
    int q = 3;
    long long arr2[10];
    int x2[32];
    for (int i = 0; i < 10; i++)
    {
        arr2[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        x2[i] = 0;
    }
    x2[31] = x2[29] = x2[27] = x2[25] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            x2[j] = xor(x2[j + p], x2[j + q]);
        }
        long long tmp = convert_array(x2);
        arr2[(int)(10 * tmp / M)]++;
        for (int j = 0; j < 7; j++)
        {
            x2[25 + j] = x2[j];
        }
    }
    long long sum2 = 0;
    for (int i = 0; i < 10; i++)
    {
        sum2 += arr2[i];
        printf("%d %lld\n", i, i[arr2]);
    }
    printf("Combined: %lld", sum2);
    return 0;
}