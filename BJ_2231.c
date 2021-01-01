//[백준] 2231 : 분해합

#include <stdio.h>
 
int main() {
    int N, tmp, digit = 0, generator = 0;
    scanf("%d", &N);
    tmp = N;
 
    //자릿수 구하기
    while (tmp > 0) {
        tmp /= 10;
        digit++;
    }
 
    //최소범위 구하기
    tmp = N;
    tmp = tmp - digit * 9;
    if (tmp < 0) tmp = 0;
 
    //생성자 찾기
    int num, sum = 0;
    for (int i = tmp; i <= N; i++) {
        num = i;
        //현재 수 더하기
        sum += num;
        //각 자릿수 더하기
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
 
        //생성자를 찾으면 저장하고 break
        if (sum == N) {
            generator = i;
            break;
        }
        sum = 0;
    }
    //결과출력
    printf("%d\n", generator);
    return 0;
}
