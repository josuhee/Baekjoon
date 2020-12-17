//[백준] 4228 : The Dragon of Loowater

import java.util.*;
 
public class Q_4228{
    static void doom() {
        System.out.println("Loowater is doomed!");
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //우선순위 큐
        PriorityQueue<Integer> dragon = new PriorityQueue<Integer>();
        PriorityQueue<Integer> knight = new PriorityQueue<Integer>();
        
        int n, m, tmp, coin;
        while(true) {
            coin=0;
            n=sc.nextInt();//드래곤
            m=sc.nextInt();//기사
            if(n==0 && m==0) break;
            
            //dragon의 머리크기
            for(int i=0;i<n;i++) {
                tmp=sc.nextInt();
                dragon.add(tmp);
            }
            
            //knight의 키
            for(int i=0;i<m;i++) {
                tmp=sc.nextInt();
                knight.add(tmp);
            }
            
            /*결과*/
            //드래곤의 머리수가 기사보다 많은 경우
            //실패!
            if(n>m) {
                doom();
                continue;
            }
            //드래곤의 머리수보다 기사가 더 많거나 같을 경우
            else {
                while(true) {
                    //큐에 드래곤과 기사가 없거나 드래곤의 머리가 없는 경우
                    //성공!
                    if(knight.isEmpty()&&dragon.isEmpty() || dragon.isEmpty()) {
                        System.out.println(coin);
                        break;
                    }
                    //큐에 기사가 없는 경우
                    //실패!
                    else if(knight.isEmpty()) {
                        doom();
                        break;
                    }
                    //드래곤 머리의 지름이 기사의 키보다 작거나 같은 경우
                    //토벌 가능.
                    if(dragon.peek() <= knight.peek()) {
                        coin+=knight.poll();
                        dragon.poll();
                    }
                    //드래곤 머리의 지름이 기사의 키보다 큰 경우
                    //토벌 불가능. 다음 기사로
                    else {
                        knight.poll();
                    }
                }
            }
            //큐의 내용 비우기
            dragon.clear();
            knight.clear();
        }
    }
}
