//[백준] 14501 : 퇴사

#include <iostream>
#define MAX(a,b) a>b?a:b
 
int main() {
    int N;
    scanf("%d", &N);
 
    int* T = new int[N];
    int* P = new int[N];
    int* S = new int[N];
    //S(salary) : 해당 날에 받을 수 있는 최대 급여
 
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }
 
    int max_salary = 0, max;
    //가장 마지막 날 부터 검사하기
    for (int i = N - 1; i >= 0; i--) {
        max = 0;
        //상담일이 N을 넘는 경우 금액=0
        if (i + T[i] > N) S[i] = 0;
        else {
            //해당 일에 받을 수 있는 급여를 먼저 저장
            S[i] = P[i];
 
            //해당 일에 진행하는 상담이 끝난 후 최대 5일 까지 중에
            //가장 큰 급여 탐색
            for (int j = i + T[i]; j < N && j < i + T[i] + 5; j++)
                max = MAX(max, S[j]);
            
            //찾은 값을 더해주기
            S[i] += max;
        }
 
        //최종적으로 가장 큰 급여인지 확인
        max_salary = MAX(max_salary, S[i]);
    }
 
    //결과 출력
    printf("%d\n", max_salary);
    return 0;
}
