/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:28:10
 * @LastEditTime: 2022-01-20 08:32:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <iostream>
#include <cstdio>
#define M 10000005
using namespace std;
int sh41[M][2];//二维数组 
int sh(void);
int main(){
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	int z = sh();//变量名 

	sh41[1][0] = 9,sh41[1][1] = 1;//统一 
	
	for(int i = 2; i <= z - 1; i++){
		sh41[i][0] = sh41[i - 1][0] * 9 + sh41[i - 1][1];
		// 枚举，公式 
		sh41[i][0] = sh41[i][0] % 12345;
		//对12345进行取余 
		sh41[i][1] = sh41[i - 1][1] * 9 + sh41[i - 1][0];
		//公式得到取余 
		sh41[i][1] = sh41[i][1] % 12345;
		//继续取余 
	}
	cout << (sh41[z - 1][0] * 8 + sh41[z - 1][1]) % 12345;
	//输出部分 
	return 0;
}
int sh(void)
{//副函数 
	int sh1 = 0, sh2 = 1;
	
	char c = getchar();
	//字符输入getchar() 
	while('0' > c || '9' < c)	c == '-'?sh2 = - 1 : 1,c = getchar ();
	//快读 
	while('0' <= c && c <= '9')	sh1 = (sh1 << 3)+(sh1 << 1)+(c ^ 48), c = getchar ();
	//快读 
	return sh1 * sh2;
}//返回值 

