// writted by YTC
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
#define M 300005
#define K(a,b) (dis[(a)]<dis[(b)])
using namespace std;
static inline int re(){int ff=0;bool fu=false;char ch=getchar();while(ch<'0'||ch>'9')fu|=(ch=='-'),ch=getchar();while('0'<=ch&&ch<='9')ff=(ff<<3)+(ff<<1)+(ch^'0'),ch=getchar();return fu?-ff:ff;}
int n,m,fir[N],dis[N],il[N],tot,goi[N];bool ins[N];
struct xy{int v,w,nt;}e[M];
static inline void addl(int u,int v,int w){e[++tot]=(xy){v,w,fir[u]};fir[u]=tot;}
struct spfa{
	static int h[N],siz;
	static inline void gup(int u){for(register int i=u;i>1&&K(h[i],h[i>>1]);i>>=1)std::swap(il[h[i]],il[h[i>>1]]),std::swap(h[i],h[i>>1]);}
	static inline int son(int u){return ((((u<<1)|1)>siz)?(u<<1):((K(h[(u<<1)|1],h[u<<1]))?((u<<1)|1):(u<<1)));}
	static inline void dow(int u){for(register int i=u,t=son(i);t<=siz&&K(h[t],h[i]);i=t,t=son(i))std::swap(il[h[i]],il[h[t]]),std::swap(h[i],h[t]);}
	static inline void iol(int x){h[++siz]=x;ins[x]=true;il[x]=siz;gup(siz);}
	static inline void dol(){ins[h[1]]=false;std::swap(il[h[1]],il[h[siz]]);std::swap(h[1],h[siz]);--siz;dow(1);}
}rt;
bool work_spfa(int s){
	memset(goi,0,sizeof goi);
	int u;register int i;
	for(i=1;i<=n;++i) dis[i]=1000000000;
	dis[s]=0;rt.iol(s);
	while(rt.siz>0){
		u=rt.h[1];rt.dol();
		for(i=fir[u];i>0;i=e[i].nt){
			if (dis[u]+e[i].w<dis[e[i].v]){
				dis[e[i].v]=dis[u]+e[i].w;
				if (ins[e[i].v]){
					rt.gup(il[e[i].v]);
					rt.dow(il[e[i].v]);
				}else rt.iol(e[i].v),++goi[e[i].v];
				if (goi[e[i].v]>=n) return true;
			}
		}
	}return false;
}
int main(){
	freopen("spfa.in","r",stdin);
	freopen("w.out","w",stdout);
	int x,y,z,s;
	n=re();m=re();
	register int i,j;
	for(i=1;i<=m;++i){
		x=re();y=re();z=re();
		addl(x,y,z);
	}long long ans;
	for(i=1;i<=n;++i)
	addl(n+1,i,0);
	if (work_spfa(n+1)){
		printf("-1");
		return 0;
	}
	for(i=1;i<=n;++i){
		ans=0;work_spfa(i);
		for(j=1;j<=n;++j)
		ans+=(long long)((long long)j*(long long)dis[j]);
		printf("%lld\n",ans);
	}
	return 0;
}
