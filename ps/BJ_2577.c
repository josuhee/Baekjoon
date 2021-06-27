//[백준] 2577 : 숫자의 개수

#include <stdio.h>
 
int main() {
    int a, b, c;
    int num[10] = { 0 };
    scanf("%d %d %d", &a, &b, &c);
    int result = a * b * c;
    
    while (result > 0) {
        num[result % 10]++;
        result /= 10;
    }
 
    for (int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}