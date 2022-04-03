#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
/*
12
*/
using namespace std;
int arr[300];
int n=0;
int m;
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
//	freopen("delete.in","r",stdin);
//	freopen("delete.out","w",stdout);

	
	char temp;
	temp=getchar();
	
	for(int i=0;temp!='\n';i++){
		arr[i]=temp-'0';
		temp=getchar();
		n++;
	}
	
	m=read();
	int cnt=0;
	while(1){
		for(int i=1;i<n;i++){
			if(cnt==m){
				goto loop;
			}
			if(arr[i]<arr[i-1]){
				arr[i]=-1;
				cnt++;
			}else{
				
			}
		}
	}
	loop:

	bool flag1=true;	
	for(int i=0;arr[i]!=0;i++){
		if(arr[i]==-1){
			continue;
		}
		printf("%d",arr[i]);
	}
}
