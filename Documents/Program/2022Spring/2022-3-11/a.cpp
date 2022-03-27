/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
4
7 9 3 6 4 2 5 3
 */
#include <bits/stdc++.h>
using namespace std;
inline int read();
int qpow(int a, int b) {
    int ans = 1;
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ans=qpow(a,b/2);
        ans=ans*ans;
    }else{
        ans=qpow(a,b-1);
        ans=ans*a;
    }
    return ans;
}
int main(){
	getch('a');
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
