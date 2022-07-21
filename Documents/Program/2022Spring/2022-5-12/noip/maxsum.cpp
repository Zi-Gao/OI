/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
int main(){
	#ifdef file
	freopen("maxsum.in", "r", stdin);
	freopen("maxsum.out", "w", stdout);
	#endif
	
	int T=read();
	int n,s,f,now,best,bests,bestf,nowbest;
	for(int i=1;i<=T;++i){
		printf("Case %d:\n",i);
		n=read();
		s=0,f=0,bests=0,bestf=0;
		best=-2000;
		nowbest=-2000;
		for(int j=0;j<n;j++){
			now=read();
			if(nowbest+now<now){
				nowbest=now;
				s=j;
				f=j;
			}else{
				nowbest=nowbest+now;
				f=j;
			}
			if(nowbest>best){
				best=nowbest;
				bests=s;
				bestf=f;
			}
		}
		printf("%d %d %d\n\n",best,bests+1,bestf+1);
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
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
