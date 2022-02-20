/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:22:25
 * @LastEditTime: 2022-01-19 08:22:55
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
    int a[8]={1,2,3,4,5,6,7,8};
    cout << a;
	return 0;
}