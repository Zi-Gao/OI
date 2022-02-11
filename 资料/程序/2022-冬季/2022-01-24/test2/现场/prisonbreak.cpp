/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 09:54:58
 * @LastEditTime: 2022-01-24 11:44:28
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
inline unsigned long long read (){
    //quick read
    unsigned long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch&'-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x*f;
}
unsigned long long qpow(unsigned long long a,unsigned long long b){
    unsigned long long ans = 1;
    while (b){
        if (b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
int main(){
    // freopen("prisonbreak.in","r",stdin);
    // freopen("prisonbreak.out","w",stdout);
    unsigned long long m=read();
    unsigned long long n=read();
    unsigned long long MAX=qpow(m,n);
    printf("%llu\n",qpow(50,9787));
    int room[MAX][n];
    memset(room,0,sizeof(room));
    for(unsigned long long i=1;i<MAX;i++){
        room[i][0]=room[i-1][0]+1;
        if(room[i][0]>=m){
            room[i][1]=room[i][0]/m;
            room[i][0]%=m;
        }
        for(unsigned long long j=1;j<n;j++){
            room[i][j]+=room[i-1][j];
            if(room[i][j]>=m){
                room[i][j+1]+=room[i][j]/m;
                room[i][j]=room[i][j]%m;
            }
        }
    }
    //output room
    unsigned long long out=0;
    for(unsigned long long i=0;i<MAX;i++){
        for(unsigned long long j=0;j<n-1;j++){
            if(room[i][j]==room[i][j+1]){
                out=(out+1)%100003;
                break;
            }
        }
    }
    printf("%llu",out%100003);
}