#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long int n, i, j; //n的最大值已经超出了整型范围，因此定义为长整型
	freopen("cantor.in", "r", stdin);
	freopen("cantor.out", "w", stdout);
	scanf("%lld", &n);
	i = 0;  //斜线序编号初始化
	j = n;  //第 n项的位置 j 初始化
	do{ //确定所在的斜行
		i++;
		j -= i;		
	}while(j > 0);
	j += i; //　修正 j
    if(i % 2 == 0) //根据编号确定斜线的方向
		printf("%lld/%lld\n", j , i + 1 - j);   // 第n项在偶数号斜线上
	else 
        printf("%lld/%lld\n", i + 1 - j, j) ;  //第n项在奇数号斜线上
    fclose(stdin);
    fclose(stdout);

	return 0;
}

