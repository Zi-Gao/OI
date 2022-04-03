#include<cstdio>
#include<algorithm>
/*
4 15
100 4
412 8
266 7
591 2
1193.0
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
	bool operator < (const work & a) const
	{
		if(T!=a.T){
			return T<a.T;
		}
		return V>a.V;
	}
}works[1000];
int C,R,N,F;
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
	F=read();
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
	}
	
	sort(works,works+N);
	
	putchar('\n');
	
	for(int i=0;i<N;i++){
		printf("A:%d B:%d T:%d U:%d V:%d W:%d X:%d\n",works[i].A,works[i].B,works[i].T,works[i].U,works[i].V,works[i].W,works[i].X);
	}
	
	for(int t=0;t<=F;t++){
		for(int i=0;i<N;i++){
			if()
		}
	}
}
