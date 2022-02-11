/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:08:44
 * @LastEditTime: 2022-01-19 08:17:12
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
    char a[8]={'C','o','m','p','u','t','e','r'};
    char b[]="Computer";//\0的位置
    cout << a << endl;
    cout << b << endl;

	return 0;
}