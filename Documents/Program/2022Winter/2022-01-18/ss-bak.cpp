/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:25:48
 * @LastEditTime: 2022-01-19 09:43:21
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include<cmath>
#include<ctime>
#include<cstdio>
using namespace std;
int main()
{
	clock_t start_time, end_time;
	start_time = clock();
	int sum = 0, a[10000] = { 0 };
	int iMax=sqrt(10000.0);
	for (int i = 2; i < iMax; i++)
	{
		sum = i;
		if (a[sum] == 0)
		{
			while (sum < 10000)
			{
				sum = sum + i;
				if (sum < 10000) a[sum] = 1;
			}
		}
	}
	// for (int i = 2; i < 10000; i++)
	// {
	// 	if (a[i] == 0) cout << i << " ";
	// }
	end_time = clock();     //获取结束时间
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%f seconds\n", Times);
	return 0;
}

