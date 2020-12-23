//[백준] 1475 : 방 번호

#include <stdio.h>
#include <string.h>
#define MAX(a,b) a>b?a:b
 
char N[1000001];
int main() {
    int set = 0, num[10] = { 0 };
    scanf("%s", N);
    //0~9 각각 개수 count
    for (int i = 0; i < strlen(N); i++)
        num[N[i] - '0']++;
 
    //6과 9를 제외한 숫자들 중 가장 높은 빈도수
    for (int i = 0; i < 10; i++) 
        if (i != 6 && i != 9)     set = MAX(num[i], set);
 
    //결과
    set = MAX((num[6] + num[9] + 1) / 2, set);
 
    printf("%d\n", set);
    return 0;
}
