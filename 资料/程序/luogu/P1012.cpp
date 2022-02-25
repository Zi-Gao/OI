/***
 * @Author: Zi_Gao
 * @Date: 2022-01-28 21:03:40
 * @LastEditTime: 2022-01-28 21:55:45
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline unsigned long long read(){
    unsigned long long x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
bool cmp(const unsigned long long &a,const unsigned long long &b){
    return a>b;
}
int main(){
    unsigned long long n=read();
    unsigned long long arr[n]={0};
    for(unsigned long long i=0;i<n;i++){
        arr[i]=read();
        while(arr[i]/10000000000==0){
            arr[i]=arr[i]*10+9;
        }
    }
    sort(arr,arr+n,cmp);
    for(unsigned long long i=0;i<n;i++){
        while(arr[i]%10==9){
            arr[i]/=10;
        }
        printf("%llu",arr[i]);
    }
    return 0;
}