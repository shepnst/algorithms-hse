#include <stdio.h>
#include <stdlib.h>


int pow(int a) {
    if (a == 1){
        return 2;
    }
    long p = pow(a / 2);
    if (a % 2 == 0) {
        return p * p;
    }
    else {
        return p * p * 2;
    }


}


int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        
        return pow(20);

    }
    if (a < b && b < c) {
        return f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    }
    if (a == c) {
        return pow(a);
    }
    if (a <= b && b <= c) {
        return pow(a);
    }
    return f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);

}


int main()
{
    int a, b, c;
    scanf_s("%d %d %d", &a, &b, &c);
    printf("%d", f(a, b, c));

}
