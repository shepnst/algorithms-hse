#include <stdio.h>
#include <stdlib.h>

void printArray(int* ans, int c, int s) {
    for (int i = c - 1; i >= 0; i--) {
            if (ans[i] != s) {
                printf("%d", ans[i]);
                s = ans[i];
            }
            else {
                s = -1;
            }
    }
}

void printArray2(int* ans, int c, int s) {
    for (int i = 0; i < c; i++) {
        if (ans[i] != s) {
            printf("%d", ans[i]);
            s = ans[i];
        }
        else {
            s = -1;
        }
    }
}


int* func(long long int n, int* ans, int i) {
    if (n == 0) {
        return ans;
    }
    ans[i] = n % 2;
    return func(n / 2, ans, i + 1);
}

int getting(long long int n) {
    int c = 0;
    while (n > 0) {
        c += 1;
        n /= 2;
    }
    return c;
}

void getting2(int* ans, int c) {
    for (int i = 0; i < c; i++) {
        ans[i] = -1;
    }
}

int main()
{
    long long int n;
    scanf_s("%lli", &n);
    int* ans = NULL;
    int c = getting(n);
    ans = (int*)calloc(c, sizeof(int));
    getting2(ans, c);
    ans = func(n, ans, 0);
    int s = -1;
    printArray(ans, c, s);
    s = -1;
    printf("\n");
    printArray2(ans, c, s);

}

