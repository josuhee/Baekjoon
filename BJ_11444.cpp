//[백준] 11444 : 피보나치 수 6

#include<iostream>
struct M
{
	long long data[2][2];
};
using namespace std;
long long fibo(long long x);
M divide(M a, long long x);
M multiply(M a, M b);
int main()
{
	long long n;
	cin >> n;
	if (n == 0) { cout << 0 << endl; return 0; }
	cout << fibo(n) << endl;
}

//초기값 설정 및 피보나치 수열 구하기
long long fibo(long long x)
{

	M a;
	a.data[0][0] = 1; a.data[0][1] = 1;
	a.data[1][0] = 1; a.data[1][1] = 0;
	a = divide(a, x);
	return a.data[0][1];
}

//나누기(분할)
M divide(M a, long long  x)
{
	if (x > 1)
	{
		a = divide(a, x / 2);
		a = multiply(a, a);
		if (x % 2 == 1)
		{
			M b;
			b.data[0][0] = 1; b.data[0][1] = 1;
			b.data[1][0] = 1; b.data[1][1] = 0;
			a = multiply(a, b);
		}
	}
	return a;
}

//행렬 곱
M multiply(M a, M b)
{
	M c;
	c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0]) % 1000000007;
	c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1]) % 1000000007;
	c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0]) % 1000000007;
	c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1]) % 1000000007;
	return c;

}