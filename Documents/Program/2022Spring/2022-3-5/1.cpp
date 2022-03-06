#include<cstdio>
#include<algorithm>
/*
4 15
100 4
412 8
266 7
591 2
1193.0
*/
using namespace std;
struct tg{
	int v;
	int w;
	double a;
}gifts[1000];
int n,w;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
inline bool cmp(tg a,tg b){
	return a.a>b.a;
}
int main(){
	n=read();
	w=read();
	
	for(int i=0;i<n;i++){
		gifts[i].v=read();
		gifts[i].w=read();
		gifts[i].a=gifts[i].v*1.0/gifts[i].w;
	}
	
	sort(gifts,gifts+n,cmp);
	
	double cntv=0;
	double cntw=0;
	for(int i=0;i<n;i++){
		if(cntw>w){
			break;
		}
		if(w-cntw>gifts[i].w){
			cntv+=gifts[i].v;
			cntw+=gifts[i].w;
		}else{
			cntv+=gifts[i].a*(w-cntw);
			break;
		}
	}
	
	printf("%.1lf",cntv);
	
	
}
