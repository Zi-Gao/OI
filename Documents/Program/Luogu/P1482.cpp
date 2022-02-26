/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 09:38:05
 * @LastEditTime: 2022-01-21 09:48:50
 * @LastEditors: Zi_Gao
 * @Description: Cantor表
 */
#include <cstdio>
int gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int main(){
    int a_1,a_2,b_1,b_2;
    scanf("%d/%d\n%d/%d",&a_1,&a_2,&b_1,&b_2);
    int x=a_1*b_1;
    int y=a_2*b_2;
    int g=gcd(x,y);
    printf("%d %d",y/g,x/g);
}