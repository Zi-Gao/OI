/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 09:01:51
 * @LastEditTime: 2022-01-23 09:21:27
 * @LastEditors: Zi_Gao
 * @Description: �߾��ȳ���1
 */
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char a1[100],c1[100];
  	int a[100],c[100],lena,i,x=0,lenc,b;
  	memset(a,0,sizeof(a));
  	memset(c,0,sizeof(c));
  	gets(a1);
  	scanf("%d",&b);
  	lena=strlen(a1);
  	for (i=0;i<=lena-1;i++)
		a[i+1]=a1[i]-48;
	for (i=1;i<=lena;i++)                               //��λ���
	{
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lenc=1;
	while (c[lenc]==0&&lenc<lena)
	lenc++;                                      //ɾ��ǰ��0
	for (i=lenc;i<=lena;i++)
		printf("%d",c[i]);
	putchar('\n');

	return 0;
}

