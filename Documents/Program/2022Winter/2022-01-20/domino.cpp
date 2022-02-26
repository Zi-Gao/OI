/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:11:49
 * @LastEditTime: 2022-01-20 11:41:48
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;

int main(){
    freopen("domino.in","r",stdin);
    freopen("domino.out","w",stdout);
    unsigned long long in;
    scanf("%lld",&in);
	unsigned long long arr[0xFFFFULL]={0,1,2,4};
	for(unsigned long long i=1;i<=in;i++){
		if(i==1){
			arr[i]=1;
			continue;
		}
		if(i==2){
			arr[i]=2;
			continue;
		}
		if(i==3){
			arr[i]=4;
			continue;
		}
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
	}
	printf("%lld",arr[in]);
}
