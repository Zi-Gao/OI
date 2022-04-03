#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
struct p{
	int t,num;
};
inline bool cmp(p a,p b){
	if(a.t!=b.t){
		return a.t<b.t;
	}else{
		return a.num<b.num;
	}
	
}
p arr[1100]={0};
int main(){
//	freopen("order.in","r",stdin);
//	freopen("order.out","w",stdout);

	int n=read();
	
	for(int i=0;i<n;i++){
		cin>>arr[i].t;
		arr[i].num=i+1;
	}
	
	stable_sort(arr,arr+n,cmp);
	
	double j=0;
	for(int i=0;i<n;i++){
		printf("%d ",arr[i].num);
		j+=arr[i].t*(n-i-1);
	}
	
	printf("\n%.2lf",j/n);	
}
