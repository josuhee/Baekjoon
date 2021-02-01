//[백준] 11399 : ATM

#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    scanf("%d", &N);
 
    int* arr = new int[N];
 
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
 
    //정렬
    sort(arr, arr + N);
 
    //대기시간 구하기
    int time = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += arr[i];
        time += tmp;
    }
    printf("%d\n", time);
    return 0;
}