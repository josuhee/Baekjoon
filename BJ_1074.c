//[백준] 1074 : Z

#include <stdio.h>
#include <math.h>
 
int func(int N, int r, int c) {
    if (N < 1) return 0;
 
    int mid = (int)pow(2, N - 1);
 
    if (r < mid && c < mid) {
        //printf("1사분면\n");
        return func(N - 1, r, c);
    }
    else if (r < mid && c >= mid) {
        //printf("2사분면\n");
        return mid * mid + func(N - 1, r, c - mid);
    }
    else if (r >= mid && c < mid) {
        //printf("3사분면\n");
        return mid * mid * 2 + func(N - 1, r - mid, c);
    }
    else {
        //printf("4사분면\n");
        return mid * mid * 3 + func(N - 1, r - mid, c - mid);
    }
}
 
 
int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
 
    int result = func(N, r, c);
    printf("%d\n", result);
 
    return 0;
}
