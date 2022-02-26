/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 09:01:51
 * @LastEditTime: 2022-01-23 09:24:28
 * @LastEditors: Zi_Gao
 * @Description: 高精度加法
 */
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a1[100],b1[100];
  	int a[100],b[100],c[100],lena,lenb,lenc,i,x;
  	memset(a,0,sizeof(a));
  	memset(b,0,sizeof(b));
  	memset(c,0,sizeof(c));
  	gets(a1);
 	gets(b1);                                                     	//输入加数与被加数
  	lena=strlen(a1);
  	lenb=strlen(b1);
  	for (i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;    	//加数放入a数组
	for (i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;  //加数放入b数组
  	lenc =1;
  	x=0;
  	while (lenc <=lena||lenc <=lenb)
	{
		c[lenc]=a[lenc]+b[lenc]+x;     //两数相加
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}

	while ((c[lenc]==0)&&(lenc>1)) lenc--;   //最高位的0不输出　　  
	for (i=lenc;i>=1;i--)
		printf("%d",c[i]);
	putchar('\n');

	return 0;
}