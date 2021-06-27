//[백준] 10872 : 팩토리얼

/*재귀x*/
#include <stdio.h>
 
int main() {
    int N, fact = 1;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
        fact *= i;
    printf("%d\n", fact);
    return 0;
}


/*재귀 함수 사용*/
/*
#include <stdio.h>
 
int fact(int n) {
    if (n > 1)
        return n * fact(n - 1);
    else return 1;
}
 
int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", fact(N));
    return 0;
}
*/