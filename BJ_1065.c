//[백준] 1065 : 변수

#include <stdio.h>

int main(){
    int N, x=1, cnt=0;
    scanf("%d",&N);
    
    while(x<=N){
        if(x<100) cnt++;
        else if(x/100-x%100/10 == x%100/10-x%10) cnt++;
        x++;
    }
    printf("%d\n",cnt);
    return 0;
}