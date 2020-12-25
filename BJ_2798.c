//[백준] 2798 : 블랙잭

#include <stdio.h>
 
int main() {
    int N, M, i, j, k, card[100], max = 0;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
        scanf("%d", &card[i]);
 
    for (i = 0; i < N - 2; i++) {
        for (j = i+1; j < N - 1; j++) {
            for (k = j+1; k < N; k++) {
                int tmp = card[i] + card[j] + card[k];
                if (max < tmp && tmp <= M) max = tmp;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
