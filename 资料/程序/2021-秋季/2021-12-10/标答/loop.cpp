//����ʱ������ 0.5 �룬ֱ�Ӽ�����۲Ų��ᳬʱ 
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
