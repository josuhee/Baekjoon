//[백준] 4949 : 균형잡힌 세상

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

//스택에 데이터를 집어넣는다.
int push(char ch) {
    if (top >= MAX - 1) return -1;
    return stack[++top] = ch;
}

//스택에서 데이터를 뽑는다.
int pop() {
    if (top < 0) return -1;
    return stack[top--] = '\0';
}

//스택 상단의 내용을 읽는다.
char peek() {
    return stack[top];
}

//균형잡힌 문자열인지를 판단
void Result(char* ch, int size) {
    for (int i = 0; i < size; i++) {
        if (ch[i] == '(' || ch[i] == ')' || ch[i] == '[' || ch[i] == ']') {
            //top가 -1이라면 무조건 push
            if (top == -1) push(ch[i]);
            else {
                //짝이라면 pop
                if (peek() == '(' && ch[i] == ')') pop();
                else if (peek() == '[' && ch[i] == ']') pop();
                //그 외 push
                else push(ch[i]);
            }
        }
    }
    //top가 -1이면 균형잡힌 문자열
    if (top == -1) printf("yes\n");
    else printf("no\n");
}

int main() {
    char str[MAX];
    while (1) {
        top = -1;
        gets(str);
        if (strcmp(str, ".") == 0) break;
        Result(str, strlen(str));
    }
    return 0;
}
