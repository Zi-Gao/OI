/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
inline bool cmp(string a,string b){
	return a+b<b+a;
}
inline int read();
int main(){
	freopen("strcat.in","r",stdin);
	freopen("strcat.out","w",stdout);
	string arr[1000];
	int n=read();
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	
    return 0;
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
