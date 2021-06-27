//[백준] 1912 : 연속합

#include <stdio.h>
#include <limits.h>
#define MAX(a,b) a>b?a:b
 
int main() {
    int n, num, result = INT_MIN, part_sum = 0;
    scanf("%d", &n);
 
    //n개의 정수
    while (n--) {
        scanf("%d", &num);
        part_sum = (MAX(part_sum, 0)) + num;
        result = MAX(part_sum, result);
    }
    printf("%d\n", result);
    
    return 0;
}