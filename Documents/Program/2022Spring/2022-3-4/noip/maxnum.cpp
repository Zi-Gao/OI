#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct _char{
	char aaa[100];
};
_char arr[100];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
inline bool cmp(_char a,_char b){
	for(int i=0;a.aaa[i]==0&&b.aaa[i]==0;i++){
		if(a.aaa[i]!=b.aaa[i]){
			return a.aaa[i]>b.aaa[i];
		}	
	}
}
int main(){
//	freopen("maxnum.in","r",stdin);
//	freopen("maxnum.out","w",stdout);

	int n=read();
	
	for(int i=0;i<n;i++){
		cin>>arr[i].aaa;
	}
	
	sort(arr,arr+n,cmp);
	
	for(int i=0;i<n;i++){
		printf("%s",arr[i].aaa);
	}
	
//	sort(arr,arr+n);
	

}
