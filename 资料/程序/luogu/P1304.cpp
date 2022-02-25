/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:12:39
 * @LastEditTime: 2022-01-21 14:20:08
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
int main(){
    int in;
    scanf("%d",&in);
    int sum = 0;
    int a[in]={0};
	int iMax=sqrt(in);
	for (int i = 2; i <= iMax; i++)
	{
		sum = i;
		if (a[sum] == 0)
		{
			while (sum <= in)
			{
				sum = sum + i;
				if (sum <= in) a[sum] = 1;
			}
		}
	}
    for(int i = 4; i <= in; i+=2){
        for(int j = 2; j <=i; j++){
            if(a[j] == 0&&a[i-j] == 0){
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            }
        }
    }
    return 0;
}