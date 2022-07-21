#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100005
//using namespace std;
inline int re(){int ff=0;bool fu=false;char ch=getchar();while(ch<'0'||ch>'9')fu|=(ch=='-'),ch=getchar();while('0'<=ch&&ch<='9')ff=(ff<<3)+(ff<<1)+(ch^'0'),ch=getchar();return fu?-ff:ff;}
int n,q,fir[N],tot,dl[N],f[N][33];long long dis[N][33];
struct xy{int v;long long w;int nt;}e[N<<1];
inline void addl(int u,int v,long long w){e[++tot]=(xy){v,w,fir[u]};fir[u]=tot;}
void dfs(int u,int pre){
	register int i;
	int nl=log2(dl[u]);
	for(i=1;i<=nl;++i){
		f[u][i]=f[f[u][i-1]][i-1];
		dis[u][i]=dis[u][i-1]+dis[f[u][i-1]][i-1];	
	}
	for(i=fir[u];i>0;i=e[i].nt)
	if (e[i].v!=pre){
		dl[e[i].v]=dl[u]+1;
		f[e[i].v][0]=u;
		dis[e[i].v][0]=e[i].w;
		dfs(e[i].v,u);
	}
}
inline void work(int x,int y){
	if (dl[x]<dl[y]) std::swap(x,y);
	int ndl=dl[x]-dl[y];long long ans=0;
	register int i=0;
	while(ndl){if (ndl&1)ans+=dis[x][i],x=f[x][i];++i;ndl>>=1;}i=0;
	while(x!=y){
		if (f[x][i]==f[y][i]){
			if (!i){
				ans+=dis[x][i]+dis[y][i];
				x=f[x][i];
				break;
			}
			ans+=dis[x][i-1]+dis[y][i-1];
			x=f[x][i-1];y=f[y][i-1];i=0;
		}else ++i;
	}printf("%d\n",ans);
}
int main(){
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	n=re();q=re();
	int x,y;long long z;
	register int i;
	for(i=1;i<n;++i){
		x=re();y=re();z=re();
		addl(x,y,z);
		addl(y,x,z);
	}dfs(1,0);
	for(i=1;i<=q;++i){
		x=re();y=re();
		work(x,y);
	}
	return 0;
}
