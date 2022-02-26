/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 14:59:16
 * @LastEditTime: 2022-02-14 15:27:50
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
struct hw{
    int ti,pi;
};
inline int read();
inline bool cmp(hw a,hw b);
inline void dfs(int step,int n,int last);
int N,K,sum=0,no;
hw arr[1000];
bool flagarr[1000]={0};
bool FLAG=false;
int main(){
    freopen("Homework.in","r",stdin);
    freopen("Homework.out","w",stdout);
    K=read();
    N=read();

    for(int i=0;i<N;i++){
        arr[i].ti=read();
        arr[i].pi=read();
        sum+=arr[i].ti;
    }
    no=sum-K;
    sort(arr,arr+N,cmp);
    for(int i=1;i<=N;i++){
        dfs(0,i,-1);
        if(FLAG){
            int out=0;
            for(int i=0;i<N;i++){
                if(flagarr[i]==1){
                    out+=arr[i].pi;
                    // break;
                }
            }
            printf("%d\n",out);
            break;
        }
    }
    return 0;
}
inline void dfs(int step,int n,int last){
    if(step==n){
        int temp=0;
        for(int i=0;i<N;i++){
            if(flagarr[i]==0){
                temp+=arr[i].ti;
                // break;
            }
            if(temp>K){
                return;
            }
        }
        FLAG=true;
        return;
    }
    if(FLAG){
        return;
    }
    for(int i=last+1;i<N;i++){
        if(flagarr[i]==0){
            flagarr[i]=1;
            dfs(step+1,n,i);
            if(FLAG){
                return;
            }
            flagarr[i]=0;
        }
    }
}
inline bool cmp(hw a,hw b){
    if(a.pi!=b.pi){
        return a.pi<b.pi;
    }else{
        return a.ti<b.ti;
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