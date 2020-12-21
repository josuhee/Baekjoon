//[백준] 10773 : 제로

#include <stdio.h>
#define MAX 100000
 
int stack[MAX];
int top = -1;
 
void push(int data) {
    if (top >= MAX - 1) return;
    stack[++top] = data;
}
 
void pop() {
    if (top < 0) return;
    stack[top--] = 0;
}
 
int main() {
    int K, data, sum = 0;
    scanf("%d", &K);
 
    //데이터 입력
    while (K--) {
        scanf("%d", &data);
        if (data == 0) pop();
        else push(data);
    }
 
    //최종 합 구하기
    for (int i = 0; i <= top; i++)
        sum += stack[i];
    printf("%d\n", sum);
    return 0;
}