//[백준] 2292 : 벌집

#include <stdio.h>
 
int main(){
    int N,x=1, cnt=1;
    scanf("%d",&N);
    
    //무한루프
    while(1){
        //N이 누적된 벌집의 수 보다 작거나 같을 경우
        if(N-x<=0) break;
        
        //cnt번째에 생성된 방의 갯수 빼기
        N-=x;
        
        //다음 번째에 생성되는 방의 갯수 계산
          x=cnt*6;
        
        //cnt증가
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
