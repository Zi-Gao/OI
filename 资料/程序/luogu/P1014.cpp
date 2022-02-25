/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:07:25
 * @LastEditTime: 2022-01-21 08:08:54
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <iostream>
using namespace std;

int main()
{
	long long int n, i, j;
	scanf("%lld", &n);
	i = 0;
	j = n;
	do{
		i++;
		j -= i;
	}while(j > 0);
	j += i;
    if(i % 2 == 0)
		printf("%lld/%lld\n", j , i + 1 - j);
	else
        printf("%lld/%lld\n", i + 1 - j, j) ;

	return 0;
}
