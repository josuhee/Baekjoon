//[백준] 1806 : 부분합

#include <stdio.h>
#define MIN(x,y) x<y?x:y
 
int arr[100000];
 
int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
 
    int sum = arr[0];
    int left, right, length = N + 1;
    left = right = 0;
 
    while (left <= right && right < N) {
        //합이 S보다 작으면 다음 인덱스의 값과 더해준다.
        if (sum < S) {
            sum += arr[++right];
        }
        //합이 S보다 크거나 같으면
        //length의 길이를 저장하고 제일 왼쪽의 인덱스를 빼준다.
        else{
            length = MIN(length, right - left + 1);
            sum -= arr[left++];
        }
    }
 
    if (length == N + 1) printf("0\n");
    else printf("%d\n", length);
    return 0;
}
