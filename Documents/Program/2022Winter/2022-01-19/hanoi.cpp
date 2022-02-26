/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 17:01:04
 * @LastEditTime: 2022-01-19 19:46:39
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
void h(int i,char a,char b,char c){
    if(i==1){
        printf("%d %c %c\n",i,a,c);
    }else{
        h(i-1,a,c,b);
        printf("%d %c %c\n",i,a,c);
        h(i-1,b,a,c);
    }
}
int main(){
    freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);

    int in;
    scanf("%d",&in);
    h(in,'A','C','B');

    fclose(stdin);
	fclose(stdout); 
    return 0;
}