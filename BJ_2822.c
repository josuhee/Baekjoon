//[백준] 2822 : 점수 계산

#include <stdio.h>

struct quiz {
    int n;
    int score;
};

int main() {
    struct quiz p[8];
    struct quiz tmp;
    int i, j, max, min, sum = 0;
    //인덱스와 score 삽입
    for (i = 0; i < 8; i++) {
        p[i].n = i + 1;
        scanf("%d", &p[i].score);
    }
    //최대 5개까지 정렬, score기준
    for (i = 0; i < 5; i++) {
        max = i;
        for (j = i + 1; j < 8; j++) {
            if (p[max].score < p[j].score) max = j;
        }
        if (i != max) {
            tmp = p[i];
            p[i] = p[max];
            p[max] = tmp;
        }
    }
    //5개 정렬, n기준
    for (i = 0; i < 4; i++) {
        min = i;
        for (j = i + 1; j < 5; j++) {
            if (p[min].n > p[j].n) min = j;
        }
        if (i != min) {
            tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
        //정렬된 부분 더해주기
        sum += p[i].score;
    }
    printf("%d\n", sum + p[4].score);
    for (i = 0; i < 5; i++)
        printf("%d ", p[i].n);
    printf("\n");
    return 0;
}
