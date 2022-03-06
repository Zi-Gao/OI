#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
/*
12
*/
using namespace std;
char arr[300];int n=0;int m;
int MAX;
bool flag[100];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
void dfs(int step){
	if(step==m){
		char temp[10000]={0};
		int j=0;
		bool flag1=true;
		for(int i=0;i<n;i++){
			if(flag[i]==0){
				if(flag1){
					if(arr[i]=='0'){
						continue;
					}else{
						flag1=false;
					}
				}
				temp[j]=arr[i];
				j++;
			}
		}
		
		int temp1111=0;
		for(int i=0;i<j;i++){
			temp1111=temp1111*10+temp[i]-'0';
		}
		if(temp1111<MAX){
			MAX=temp1111;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(flag[i]==0){
			flag[i]=1;
			dfs(step+1);
			flag[i]=0;
		}
	}
}
int main(){
//	freopen("delete.in","r",stdin);
//	freopen("delete.out","w",stdout);

	
	char temp;
	temp=getchar();
	
	for(int i=0;temp!='\n';i++){
		arr[i]=temp;
		temp=getchar();
		n++;
	}
	
	m=read();

//1	
//	
//	
//	MAX=0x7FFF;
//	
//	dfs(0);
//	
//	bool flag=true;
//	
//	printf("%d",MAX);

//2
//	for(int i=0;MAX[i]==0;i++){
//		if(flag){
//			if(MAX[i]=='0'){
//				continue;
//			}else{
//				flag=false;
//			}
//		}
//		printf("%c",MAX[i]);
//	}
	
//	sort(arr,arr+n);
	
//3
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt==m){
			break;
		}
		if(arr[i]<arr[i-1]){
			flag[i]=true;
			cnt++;
		}
		
	}

	bool flag1=true;	
	for(int i=0;arr[i]!=0;i++){
		if(flag[i]){
			continue;
		}
		if(flag1){
			if(arr[i]=='0'){
				continue;
			}else{
				flag1=false;
			}
		}
		printf("%c",arr[i]);
	}
}
