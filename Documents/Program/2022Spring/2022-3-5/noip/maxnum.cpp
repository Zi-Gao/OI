#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
/*
4
7 13 4 246
*/
struct _char{
	char aaa[100];
};
_char arr[100];
int n;
char MAX[10000];
int book[100];
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
inline bool cmp(_char a,_char b){
	for(int i=0;a.aaa[i]!=0||b.aaa[i]!=0;i++){
		if(a.aaa[i]!=b.aaa[i]){
			return a.aaa[i]>b.aaa[i];
		}	
	}
}
void dfs(int step){
	if(step==n){
		char temp[10000]={0};
		for(int i=0;i<n;i++){
			strcat(temp,arr[book[i]].aaa);
		}
//		printf("YYYY");
//		printf("%s\n",temp);
		if(strcmp(temp,MAX)>0){
			strcpy(MAX,temp);
//			printf("%s\n",MAX);
		}
		return;
	}
	for(int i=1;i<n;i++){
		if(flag[i]==0){
			flag[i]=1;
			book[step]=i;
			dfs(step+1);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("maxnum.in","r",stdin);
	freopen("maxnum.out","w",stdout);

	n=read();
	
	for(int i=0;i<n;i++){
		cin>>arr[i].aaa;
	}

	sort(arr,arr+n,cmp);
	
	book[0]=0;
	
	dfs(1);
	
	printf("%s",MAX);

//	for(int i=0;i<n;i++){
//		printf("%s",arr[i].aaa);
//	}

}
