//[백준] 3040 : 백설 공주와 일곱 난쟁이

#include <stdio.h>
 
int main() {
    int arr[9];
    int check[9] = { 0, };
    int sum = 0;
 
    //각 난쟁이의 숫자를 입력받고, 
    //총 합계를 구함.
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
 
    //총합에서 100만큼 빼주기
    sum -= 100;
 
    //두명의 합이 sum과 같은지 확인
    int find = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            //찾으면 해당 인덱스를 표시하고 종료
            if (arr[i] + arr[j] == sum) {
                check[i] = check[j] = 1;
                find = 1;
                break;
            }
        }
        if (find) break;
    }
 
    //결과출력
    for (int i = 0; i < 9; i++) {
        if (!check[i]) printf("%d\n", arr[i]);
    }
 
    return 0;
}
