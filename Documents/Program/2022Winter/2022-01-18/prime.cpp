#include<iostream> 
#include<cmath>  
using namespace std;  
int sum = 0;
 const int _max = 1000000000 + 5;
//const int _max = 100 + 5;
char a[_max] = { 0 };
int main()
{
	 freopen("prime.in", "r", stdin);
	 freopen("prime.out", "w", stdout);

	int sqrt_max=sqrt(_max);

	for (int i = 2; i < sqrt_max; i++)
	{
		sum = i;
		if (a[sum] == 0)
		{
			while (sum < _max)
			{
				sum = sum + i;
				if (sum < _max) a[sum] = 1;
			}
		}
	}
	for (int i = 2; i < _max; i++)
	{
		printf("%d,",a[i]);
	}
	return 0;
}

