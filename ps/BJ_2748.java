//[백준] 2748 : 피보나치 수 2

import java.util.Scanner;
 
public class Main {
    int n;
    
    public Main(int n) {
        this.n = n;
    }
    
    void fibo() {
        long arr[]=new long[91];
 
        //0번째와 1번째 수는 지정해준다.
        arr[0]=0;
        arr[1]=1;
        
        //피보나치 수열을 계산하는 반복문
        for(int i=2;i<=n;i++) {
            arr[i]=arr[i-1]+arr[i-2];
        }
        
        //n번째 숫자를 
        System.out.println(arr[n]);
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        new Main(n).fibo();
    }
}