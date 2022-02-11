/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:28:10
 * @LastEditTime: 2022-01-20 08:32:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int wt[35][35][35];
int a,b,c;
int w(int ,int ,int);
int main()
{
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		printf("w(%d,%d,%d)=%d",a,b,c,w(a,b,c));
	}
	return 0;
} 
int w(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return w(20,20,20);
	if(wt[a][b][c])
		return wt[a][b][c];
	if(a<b&&b<c)
		return wt[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	return wt[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
