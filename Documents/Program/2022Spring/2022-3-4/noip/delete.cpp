#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct _char{
	int a,b;
};

_char arr[300];
_char temp2[300];
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
	return a.a>b.a;
}
inline bool cmp2(_char a,_char b){
	return a.b<b.b;
}
int main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);

	int n=0;
	char temp;
	temp=getchar();
	
	for(int i=0;temp!='\n';i++){
		arr[i].a=temp-'0';
		arr[i].b=i;
		temp=getchar();
		n++;
	}
	
	int m=read();
	
	sort(arr,arr+n,cmp);
	
	int j=0;
	for(int i=m;i<n;i++){
		temp2[j]=arr[i];
		j++;
	}
	
	sort(temp2,temp2+n-m,cmp2);
	bool flag=true;
	for(int i=0;i<n-m;i++){
		if(flag){
			if(temp2[i].a==0){
				continue;
			}else{
				flag=false;
			}
		}
		printf("%d",temp2[i].a);
	}
	
//	sort(arr,arr+n);
	

}
