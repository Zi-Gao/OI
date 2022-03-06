#include<cstdio>
#include<algorithm>
#include<cstring>
/*
https://vjudge.net/problem/ZOJ-1012
10
4 256 3
1 16 2 3 10 5 6
2 128 2 4 30 10 5
2 128 2 4 20 10 5
*/
using namespace std;
struct work{
	int A,B,T,U,V,W,X,f;//A:CPU B:RAM T:start U:finish V:money W:+monety/h X:-money/h
	int finish;
	bool operator < (const work & a) const
	{
		if(finish){
			return false;
		}
		if(a.finish){
			return true;
		}
		if(T!=a.T){
			return T<a.T;
		}
		return V>a.V;
	}
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
int main(){
	for(int i=1;true;++i){
		int C,R,N,F,money;
		work works[1000];
		memset(works,0,sizeof(work));
		F=read();
		if(F==0){
			break;
		}
		C=read();
		R=read();
		N=read();

		for(int i=0;i<N;i++){
			works[i].A=read();
			works[i].B=read();
			works[i].T=read();
			works[i].U=read();
			works[i].V=read();
			works[i].W=read();
			works[i].X=read();
			works[i].finish=-1;
		}

		sort(works,works+N);

		for(int t=0;t<=F;t++){
			for(int i=0;i<N;i++){
				if(works[i].finish==t){
					//释放资源
					C+=works[i].A;
					R+=works[i].B;
				}
				if(works[i].finish<t){
					continue;
				}
				if(works[i].T>t){
					continue;
				}
				if(works[i].A<=C&&works[i].B<=R){
					//占用资源
					C-=works[i].A;
					R-=works[i].B;
					works[i].finish=t+1;
					//计算费用
					if(works[i].finish<=works[i].U){
						money+=works[i].V+works[i].W*(works[i].U-works[i].finish);
					}else{
						money+=works[i].V-works[i].X*(works[i].finish-works[i].U);
					}
				}
				sort(works,works+N);
			}
		}

		for(int i=0;i<N;i++){
			if(works[i].finish==-1&&works[i].U<=F){
				money-=works[i].X*(works[i].finish-works[i].U);
			}
		}
		printf("Case %d: %d",i,money);
	}
}
