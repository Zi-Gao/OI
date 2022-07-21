/***
 * @Author: Zi_Gao
 * @Description: 
 */
/*
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
*/
#include <cstdio>
#include <list>
#define file
using namespace std;
inline int read();
list<int> l;
int main(){
	#ifdef file
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout);
	#endif

	int n,m,x,y,op,cas=0;
	long long cnt;
	list<int>::iterator itx,ity,it;
	char flagx,flagy,flag;

	while(~scanf("%d %d",&n,&m)){
		++cas;
		l.clear();
		for(int i=1;i<=n;i++){
			l.push_back(i);
		}
		for(int i=0;i<m;i++){
			op=read();
			if(op==1){
				x=read();
				y=read();
				it=l.begin();
				itx=it;
				ity=it;
				flagx=false;
				flagy=false;
				for(;it!=l.end();it++){
					if(!flagx&&*it==x){
						itx=it;
						flagx=true;
					}
					if(!flagy&&*it==y){
						ity=it;
						flagy=true;
					}
					if(flagx&&flagy){
						break;
					}
				}
				l.erase(itx);
				l.insert(ity,x);
			}else if(op==2){
				x=read();
				y=read();
				it=l.begin();
				itx=it;
				ity=it;
				flagx=false;
				flagy=false;
				for(;it!=l.end();it++){
					if(!flagx&&*it==x){
						itx=it;
						flagx=true;
					}
					if(!flagy&&*it==y){
						ity=it;
						flagy=true;
					}
					if(flagx&&flagy){
						break;
					}
				}
				l.erase(itx);
				l.insert(++ity,x);
			}else if(op==3){
				x=read();
				y=read();
				it=l.begin();
				itx=it;
				ity=it;
				flagx=false;
				flagy=false;
				for(;it!=l.end();it++){
					if(!flagx&&*it==x){
						itx=it;
						flagx=true;
					}
					if(!flagy&&*it==y){
						ity=it;
						flagy=true;
					}
					if(flagx&&flagy){
						break;
					}
				}
				l.insert(itx,y);
				l.insert(ity,x);
				l.erase(itx);
				l.erase(ity);
			}else if(op==4){
				l.reverse();
			}
//			for(it=l.begin();it!=l.end();it++){
//				printf("%d ",*it);
//			}
//			putchar('\n');
		}
		cnt=0;
		for(it=l.begin();it!=l.end();it++){
			if(flag){
				cnt+=*it;
				flag=false;
			}else{
				flag=true;
			}
		}
		printf("Case %d:%lld\n",cas,cnt);
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
