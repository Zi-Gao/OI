/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
//#define file
#define int long long
using namespace std;
inline int read();



struct node{
	int x,y,z;
	bool operator < (const node in) const{
		if(z!=in.z){
			return z<in.z;
		}else if(x!=in.x){
			return x<in.x;
		}else{
			return y<in.y;
		}
	}
};

node arr_f[1010];
int n,h,r;

#define MAX_SIZE 1010
struct fa{
	int arr[MAX_SIZE];

	fa(){
		for(int i=0;i<=MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}

	inline int find(int x){
		return x==arr[x]?x:(arr[x]=find(arr[x]));
	}

	inline void merge(int i,int j){
		if(arr_f[i].z>arr_f[j].z){
			arr[find(j)]=find(i);
		}else{
			arr[find(i)]=find(j);
		}

		return;
	}

	void clear(){
		for(int i=0;i<=MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
};



bool check(node a,node b){
	return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-(r<<1))<=0;
}

fa f;

signed main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int T=read();
	bool flag;


/*
1
5 1060 300
634 586 1008
756 332 385
570 40 776
428 176 380
695 1028 36
*/
	while(T--){
		f.clear();
		memset(arr_f,0,sizeof(arr_f));
		n=read();
		h=read();
		r=read();

		for(int i=0;i<n;i++){
			arr_f[i].x=read();
			arr_f[i].y=read();
			arr_f[i].z=read();
		}

		sort(arr_f,arr_f+n);

		if(arr_f[n-1].z+r<h){
			puts("No");
		}else{
			for(int i=n-1;i>=0;i--){
				for(int j=n-1;j>=0;j--){
					if(f.find(i)!=f.find(j)&&check(arr_f[i],arr_f[j])){
						f.merge(i,j);
						printf("%f\n",sqrt((arr_f[i].x-arr_f[j].x)*(arr_f[i].x-arr_f[j].x)+(arr_f[i].y-arr_f[j].y)*(arr_f[i].y-arr_f[j].y)+(arr_f[i].z-arr_f[j].z)*(arr_f[i].z-arr_f[j].z))-r*2);
					}
				}
			}

			for(int i=0;i<n;i++){
				if((i==f.find(i))&&(arr_f[i].z-r<=0)&&(arr_f[i].z+r>=h)){
					puts("Yes");
					goto loop;
				}
				if((i!=f.find(i))&&(arr_f[i].z-r<=0)&&(arr_f[f.find(i)].z+r>=h)){
					// printf("i:%d find:%d\nh:%d r:%d\nix:%d iy:%d iz:%d\nfindx:%d findy:%d findz:%d\n",i,f.find(i),h,r,arr_f[i].x,arr_f[i].y,arr_f[i].z,arr_f[f.find(i)].x,arr_f[f.find(i)].y,arr_f[f.find(i)].z);
					puts("Yes");
					goto loop;
				}
			}
			puts("No");
			loop:;
		}

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
