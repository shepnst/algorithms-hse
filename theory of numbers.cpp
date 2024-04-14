#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int s, f;
    scanf_s("%d", &s);
    scanf_s("%d", &f);
    int size = f - s + 1;
    int* arr = (int*)malloc((f + 1) * sizeof(int));
    int limit = sqrt(size);
    int flag = 0;
    int prime = 0;
    printf("Start and finish: %d %d\n", s, f);

    for (int i = 0; i <= f; i++) {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    if (s == 0 || s == 1) {
        s = 2;
    }
    int count = 0;
    int print = 0;
    for (int i = 2; i <= f; i++) {
        if (arr[i] == 1) {
            prime = 0;
            print = 0;
            count++;
            for (int j = s; j <= f; j++) {
                if (j % i == 0 && arr[j] == 1) {
                    prime = 1;
                    break;
                }
            }
            if (prime == 1) {
                for (int j = i * 2; j <= f; j += i) {
                    if (arr[j] == 1) {
                        if (j >= s) {
                            if (print == 0) {
                                printf("Iteration : %d\n", count);
                                print = 1;
                            }
                            printf("%d ", j);
                        }
                        arr[j] = 0;
                    }
                }
                if (print == 1) {
                    printf("\n");
                }
            }
        }
    }
    int there_is_prime = 0;
    for (int i = s; i <= f; i++) {
        if (arr[i] == 1) {
            there_is_prime = 1;
            break;
        }
    }
    if (there_is_prime) {
        printf("Primes : \n");
        for (int i = s; i <= f; i++) {
            if (arr[i] == 1) {
                printf("%d ", i);
            }
        }
    }
    else {
        printf("Primes : \n");
        printf("No primes");
    }

}
