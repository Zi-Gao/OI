/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 20:00:04
 * @LastEditTime: 2022-01-21 09:26:45
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
bool primeNumberDetermination(int num){
    int iMAX=sqrt(num);
    for(int i=2;i<=iMAX;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
	int in;
    scanf("%d",&in);
	for(int i=2;i<=in;i++){
		if(in%i==0&&primeNumberDetermination(i)){
			printf("%d\n",in/i);
			break;
		}
	}
	return 0;
}