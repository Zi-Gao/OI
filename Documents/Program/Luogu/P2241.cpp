/***
 * @Author: Zi_Gao
 * @Date: 2022-02-18 22:09:33
 * @LastEditTime: 2022-02-18 22:24:06
 * @LastEditors: Zi_Gao
 * @Description: 
 */
//sum=n(n+1)/2+m(m+1)/2
//squ=Cm,1*Cn,1+Cm,2*Cn,2+...Cm,n*Cn,n
#include <cstdio>
using namespace std;
int N,M;
int C(int n,int m);
int main(){
    scanf("%d %d",&N,&M);
    int sum=N*(N+1)/2*M*(M+1)/2;
    int squ=0;
    for(int i=1;i<=N;i++){
        squ+=C(M,i)*C(N,i);
    }
    printf("%d ",squ-1);
    printf("%d",sum-squ+1);
}
int C(int n,int m){
    long long s1=n-m+1;
    int ans=1;
    for(int i=1;i<=m;i++)
    {
        ans*=s1;
        ans/=i;
        s1++;
    }
    return ans;
}