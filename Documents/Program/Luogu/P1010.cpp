/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:28:10
 * @LastEditTime: 2022-01-20 08:32:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
void wxt(int);
int wxt2(int,int);
int step;
int main()
{
	int n;
	cin>>n;
	wxt(n);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
void wxt(int n)
{
	for(int i=14;i>=0;i--)
	{
		if(wxt2(2,i)<=n)
		{
			if(i==0){
				cout<<"2(0)";
				return;
			}
				
			if(i==1)
			{
				cout<<"2";
			}
			else
			{
				cout<<"2(";
				wxt(i);
				cout<<")";
			}
			n-=wxt2(2,i);
			if(n!=0)
				cout<<"+";
			
					
		}
		
	}
	return ;
}
int wxt2(int x,int n)
{
	int t=1,a=x;
	while(n){
		if(n&1) t*=a;
		a*=a;
		n>>=1;
	}
	return t;
}
