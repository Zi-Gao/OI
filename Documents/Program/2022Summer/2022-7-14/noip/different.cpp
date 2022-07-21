#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read();
int arr[200000+100];
int book[2000000+100];
int main(){
	freopen("different.in","r",stdin);
	freopen("different.out","w",stdout);

	int n=read();
	int m=read();
	

	
	for(int i=0;i<n;i++){
		arr[i]=read()+1000010;
	}
	
	for(int i=0;i<m;i++){
		int l=read();
		int r=read();
		int best=0;

		memset(book,0,sizeof(book));
		int cnt=0;
		for(int k=l;k<=r;k++){
			if(!book[arr[k]]){
				book[arr[k]]=k+1;
				cnt++;
			}else{
				best=max(best,cnt);
				k=book[arr[k]]-1;
				memset(book,0,sizeof(book));
				cnt=0;
			}
		}
		best=max(best,cnt);
		
		if(best==0){
			printf("0\n");
		}else{
			printf("%d\n",best);
		}
		
	}

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
