/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <stack>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <set>
//#define file
using namespace std;
inline int read();
struct p{
	int a,b;
	bool operator < (const p & x) const{
		return b<x.b&&a!=x.a;
	}
	bool operator > (const p & x) const{
		return b<x.b&&a!=x.a;
	}
};
p in[500000];
p temp,bg;
int n,q,l,r,cnt;
int main(){
	#ifdef file
	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);
	#endif

	n=read();
	q=read();
	
	for(int i=0;i<n;i++){
		in[i].a=read();
	}
	
	for(int i=0;i<n;i++){
		in[i].b=read();
	}
	
	for(int i=0;i<q;i++){
		temp.a=0;
		temp.b=0;
		bg.a=0;
		bg.b=0;
		cnt=0;
		multiset<p> s;
		l=read()-1;
		r=read();
		//push
		for(int j=l;j<r;j++){
			//find
			if(s.empty()){
				s.insert(in[j]);
				cnt++;
				continue;
			}
			temp=*s.upper_bound(in[j]);
			//delet
			bg=*s.begin(); 
			while((!s.empty())&&(bg.a!=temp.a)&&(bg.b!=temp.b)){
				s.erase(s.begin());
				bg=*s.begin();
			}
//			while((!s.empty())&&(begin.a==in[j].a)){
//				s.erase(s.begin());
//				begin=*s.begin();
//			}
			//push
			s.insert(in[j]);
			//size
			if(s.size()==1){
				cnt++;
			}
		}
//		p b;
//		b.a=1;
//		b.b=1;
//		p a=*s.upper_bound(b);
		printf("%d\n",cnt );
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
