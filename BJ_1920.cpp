//[백준] 1920 : 수 찾기

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int A[100000];
int main() {
    int n;
    //n개의 정수
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A + n);
 
    //확인할 m개의 숫자
    int M;
    scanf("%d", &M);
 
    bool exist;
    int test_case, right, left;
    //배열 A에 해당 숫자가 있는지 확인
    while (M--) {
        exist = false;
        left = 0;
        right = n - 1;
        scanf("%d", &test_case);
        //이분 탐색
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] > test_case)
                right = mid - 1;
            else if (A[mid] < test_case)
                left = mid + 1;
            else {
                //있다면 true
                exist = true;
                break;
            }
        }
        //결과출력
        if (exist) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
