/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 09:01:51
 * @LastEditTime: 2022-01-23 09:25:17
 * @LastEditors: Zi_Gao
 * @Description: 高精度减法
 */
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[256],b[256],c[256],lena,lenb,lenc,i;
	char n[256],n1[256],n2[256];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
    printf("Input minuend:");    gets(n1);   //输入被减数
	printf("Input subtrahend:"); gets(n2);   //输入减数
 	if (strlen(n1)<strlen(n2)||(strlen(n1)==strlen(n2)&&strcmp(n1,n2)<0))
			//strcmp()为字符串比较函数，当n1==n2, 返回0;   n1>n2时，返回正整数；n1<n2时，返回负整数
	{                                        //处理被减数和减数，交换被减数和减数
		strcpy(n,n1);                //将n1数组的值完全赋值给n数组
		strcpy(n1,n2);
		strcpy(n2,n);
		putchar('-');                    //交换了减数和被减数，结果为负数
	}

	lena=strlen(n1); lenb=strlen(n2);
	for (i=0;i<=lena-1;i++) a[lena-i]=int(n1[i]-'0');  //被减数放入a数组
	for (i=0;i<=lenb-1;i++) b[lenb-i]=int(n2[i]-'0');  //减数放入b数组
    i=1;
	while (i<=lena||i<=lenb)
	{
		if (a[i]<b[i])
		{
			a[i]+=10;               //不够减，那么向高位借1当10
			a[i+1]--;
		}
		c[i]=a[i]-b[i];                        //对应位相减
		i++;
	}
	lenc=i;
	while ((c[lenc]==0)&&(lenc>1)) lenc--;   //最高位的0不输出　　  
	for (i=lenc;i>=1;i--) printf("%d",c[i]);               //输出结果
	putchar('\n');

	return 0;
}

