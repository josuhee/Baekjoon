//[백준] 1874 : 스택 수열

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
 
char result[SIZE * 2];
int stack[SIZE];
int top = -1;
 
int main() {
    int n;
    scanf("%d", &n);
 
    //목표 수열 입력
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    int num = 1;
    int idx = 0, result_idx = 0;
    while (1) {
        //스택에 있는 수가 목표 수 보다 낮은 경우
        //push(+)
        if (top == -1 || stack[top] < arr[idx]) {
            stack[++top] = num++;
            result[result_idx++] = '+';
        }
        //스택 상단부분의 수가 목표 수와 같은 경우
        //pop(-)
        else if (stack[top] == arr[idx]) {
            top--;
            result[result_idx++] = '-';
            idx++;
        }
        //스택의 상단부분의 수가 목표 수 보다 높은경우
        //원하는 수열을 만들 수 없음
        else {
            printf("NO\n");
            return 0;
        }
        if (result_idx == n * 2) break;
    }
    
    //결과 출력
    for (int i = 0; i < result_idx; i++)
        printf("%c\n", result[i]);
 
    return 0;
}
