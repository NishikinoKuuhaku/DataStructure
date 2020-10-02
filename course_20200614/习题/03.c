#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {6, 5, 4, 3, 2, 1};
    int x = 10;
    int n = 5;

    // x^5 + 2x^4 + 3x^3 + 4x^2 + 5x + 6
    // ans = 123456

    int k = 0;
    for (int i = 5; i >= 0; i--)
    {
        k = (k * x + a[i]) % 100007;
    }

    printf("%d", k);

    return 0;
}

// 4 % 3 == 1;
// 2 % 3 == 2;
// (4 * 2) % 3 == (1 * 2) % 3;

// 6 % 4 == 2;
// 11 % 4 == 3;
// (6 * 11) % 4 == 2 == (2 * 3) % 4;

// x % b = p;
// x = k1 * b + p;
// y % b = q;
// y = k2 * b + q;
// x * y == (k1 * b + p) * (k2 * b + q);
// (x *y) % b == (k1 * k2 * b * b + k1 * q * b + k2 * p * b + pq) % b == pq % b;
