/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 08:33:45
 * @LastEditTime: 2022-01-25 10:00:32
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 16:10:47
 * @LastEditTime: 2022-01-25 08:20:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int n,cows;
int a[100100]={0};
bool check(int dis){
    int cnt=1,place=0;
    for(int i=1;i<n;i++){
        if(a[i]-a[place]>=dis){
            cnt++;place=i;
        }
    }
    if(cnt>=cows){
        return true;
    }else{
        return false;
    }
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
    n=read();
    cows=read();
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    sort(a,a+n);
    int l=0,r=a[n-1]-a[0];
    int ans=0;
    while(l<r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid;
        }
    }
    printf("%d",ans);
}