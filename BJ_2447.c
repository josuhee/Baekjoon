//[백준] 2447 : 별 찍기 - 10

#include <stdio.h>
#include <math.h>
 
char arr[2500][2500];
 
//모든 칸을 *로 채워주기
void AllStar(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            arr[i][j] = '*';
    }
}
 
//지정된 점(x,y)부터 가로새로로 3^cnt만큼 공백으로 채우기
void Blank(int x, int y, int cnt) {
    for (int i = x; i < x + (int)pow(3, cnt); i++) {
        for (int j = y; j < y + (int)pow(3, cnt); j++) {
            arr[i][j] = ' ';
        }
    }
}
 
//공백으로 지정할 점(x,y) 찾기
void Pivot(int n, int cnt) {
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //해당 기준점을 공백으로
                Blank((int)pow(3, cnt) + i * (int)pow(3, cnt + 1), 
                    (int)pow(3, cnt) + j * (int)pow(3, cnt + 1), cnt);
            }
        }
        //기준점 이동하기
        Pivot(n / 3, cnt + 1);
    }
}
 
int main() {
    int N;
    scanf("%d", &N);
    AllStar(N);
 
    Pivot(N / 3, 0);
 
    //결과출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
    return 0;
}
