/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:28:10
 * @LastEditTime: 2022-01-20 08:32:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include<iostream>
#include <cstdio>
using namespace std;
unsigned long long const _max=-1ULL;
unsigned long long n3[69],n4[65];
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int n;
	cin>>n;
	//
	n3[1]=n4[1]=1;
	for(int i=2;i<=65;i++)
		n3[i]=n3[i-1]*2+1;

	for(int i=2;i<=n;i++)
	{
		unsigned long long temp=_max;
		for(int j=1;j<=i-1;j++)
		{
			temp=min(temp,2*n4[j]+n3[i-j]);
		}
		n4[i]=temp;
	}
	
	cout<<n4[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
