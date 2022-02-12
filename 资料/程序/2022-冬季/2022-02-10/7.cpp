/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 16:09:21
 * @LastEditTime: 2022-02-10 16:44:13
 * @LastEditors: Zi_Gao
 * @Description: 
 */
int n;
#include <cstdio>
int number(int a,int b,int c,int d){
    int arr[20000]={0};
    for(int x1=0;x1<=n;x1++){
        for(int x2=0;x2<=n-x1;x2++){
            for(int x3=0;x3<=n-x1-x2;x3++){
                for(int x4=0;x4<=n-x1-x2-x3;x4++){
                    arr[a*x1+b*x2+c*x3+d*x4]=1;
                }
            }
        }
    }
    int MAX=0;
    while(arr[MAX]){
        MAX++;
    }
    return MAX-1;
}
int main(){

    scanf("%d",&n);
    int a=1,b,c,d;
    int MAX=0;
    for(b=a+1;b<=n*a+1;b++){
        for(c=b+1;c<=n*b+1;c++){
            for(d=c+1;d<=n*c+1;d++){
                int t=number(a,b,c,d);
                if(t>MAX){
                    MAX=t;
                    printf("%d %d %d %d MAX=%d\n",a,b,c,d,t);
                }
            }
        }
    }
}