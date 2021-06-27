//[백준] 2217 : 로프

#include <stdio.h>
#include <algorithm>
#define MAX(a,b) a>b?a:b
using namespace std;
 
int arr[100000];
 
//내림차순
bool desc(int a, int b) {
    return a > b;
}
 
int main() {
    int N;
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
 
    //내림차순으로 정렬
    sort(arr, arr + N, desc);
 
    //최대 중량 구하기
    int max = 0;
    for (int i = 0; i < N; i++) {
        int tmp = arr[i] * (i + 1);
        max = MAX(max, tmp);
    }
 
    //결과값 출력
    printf("%d\n", max);
    return 0;
}