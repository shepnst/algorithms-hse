#include <stdio.h> 
#include <malloc.h> 
#include <stdbool.h>
long long int pow(unsigned long long base, unsigned long long int exp, unsigned long long mod) {
    unsigned long long int res = 1;
    while (exp)
    {
        if (exp % 2 == 1)
            res = res * base % mod;
        exp >>= 1;
        base = base * base % mod;
    }

    return res;
}


void test_fermat(int n) {
    int  dig= 0, num = 0;
    for (int i = 1; i < n; i++) {
        if (pow(i, n - 1, n) == 1) {
            dig+=1;
        }
        else {
            num+=1;
        }
    }
    printf("Fermat test: ");
    if (num == 0) {
        printf("True ");
    }
    else {
        printf("False ");
    }
    printf("%d %d\n", num, dig);
} 

void miller_rabin(int n) {
    int s = 0, d = 0, c = n;
    int one = 0, two = 0, count = 0;
    int k2 = 0;
    bool flag;
    n = n-1;
    while (n % 2 == 0) {
        s += 1;
        n /= 2;
    }
    d = n;
    n = c;
    for (int i = 1; i < c; i++) {
        flag = false;
        if (pow(i, d, n) == 1) {
            one+=1;
        }
        else {
            for (int k = 0; k < s; k++) {
                k2 = 1;
                for (int j = 0; j < k; j++) {
                    k2 *= 2;
                }
                k2 *= d;
                if (pow(i, k2, n) == (n - 1)) {
                    two+=1;
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                count+=1;
            }
        }
    }
    printf("Miller-Rabin test: ");
    if (count == 0) {
        printf("True ");
    }
    else {
        printf("False ");
    }
    printf("%d %d %d\n", count, one, two);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    miller_rabin(n);
    test_fermat(n);
}
