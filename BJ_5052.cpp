//[백준] 5052 : 전화번호 목록

#include <iostream>
using namespace std;
int par[100000];

int main() {
   int a, b;
   int N;

   cin >> N;
   for (int i = 1; i <= N - 1; i++)
   {
      cin >> a >> b;
      if (a == 1) {
         par[b] = a; // 1 6 입력시 1이 6의 부모로 저장
      }
      else if (b == 1) {
         par[a] = b;
      }
      else if (par[a]!=0) {//a에게 저장된 부모가 있다면,
         par[b] = a; //a가 b의 부모로 저장됨
      }
      else {
         par[a] = b; 
      }
   }
   for (int i = 2; i <= N; i++) {
      cout << par[i] << endl;
   }

   return 0;
}