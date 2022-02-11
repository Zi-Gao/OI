//本题时间限制 0.5 秒，直接计算结论才不会超时 
#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	long long z = 0, n;
	freopen("loop.in", "r", stdin);
	freopen("loop.out", "w", stdout);	
	cin >> n;
	z = (n + 1) * (n + 1) * n;
	cout << z;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
