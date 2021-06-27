//[백준] 2749 : 피보나치 수 3

#include <stdio.h>
 
int fibo[1500000];
 
int main() {
    long long int n;
    scanf("%lld", &n);
 
    fibo[0] = 0;
    fibo[1] = 1;
 
    for (int i = 2; i < 1500000; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;
 
    printf("%d\n", fibo[n % 1500000]);
    return 0;
}
