//[백준] 1822 : 차집합

import java.util.*;
 
public class Q_1822 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //TreeSet
        TreeSet<Integer> A = new TreeSet<Integer>();
        
        //원소 삽입
        int a = sc.nextInt();
        int b = sc.nextInt();
        int i, num;
        for(i=0;i<a;i++)
            A.add(sc.nextInt());
        for(i=0;i<b;i++) {
            num=sc.nextInt();
            //A에 포함된 요소면 삭제
            if(A.contains(num)) A.remove(num);
        }
        
        //결과 출력
        System.out.println(A.size());
        for(int n : A)
            System.out.print(n+" ");
        sc.close();
    }
}
