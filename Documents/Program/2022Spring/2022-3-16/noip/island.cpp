#include<cstdio>
#include<algorithm>
#include <cstring>
/*
50
4
10 100
50 30
7 34
87 100
*/
using namespace std;
struct tg{
	int v;
	int w;
	double a;
};

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
	freopen("island.in","r",stdin);
	freopen("island.out","w",stdout);
	int N=read();
	while(N){
		int n,w;
		tg gifts[1000];
		memset(gifts,0,sizeof(gifts));
		w=read();
		n=read();
		
		for(int i=0;i<n;i++){
			gifts[i].w=read();
			gifts[i].v=read();
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
		printf("%.2lf\n",cntv);
		N--;
	}
	
}
