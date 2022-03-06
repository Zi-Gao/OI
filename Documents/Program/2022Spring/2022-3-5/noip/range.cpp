#include<cstdio>
#include<algorithm>
using namespace std;
bool num[10005][10005];
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
//	freopen("range.in","r",stdin);
//	freopen("range.out","w",stdout);

	int n=read();
	int max=0;
	for(int i=0;i<n;i++){
		int t1=read(),t2=read();
		if(t2>max){
			max=t2;
		}
		for(int j=t1;j<=t2;j++){
			num[i][j]=true;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=20;j++){
			printf("%d ",num[i][j]);
		}
		putchar('\n');
	}
	
	for(int i=0;i<max;i++){//长度 
		for(int j=0;j<=max-i;j++){//起始线 
			bool flag[10005]={0};
			for(int k=j;k<=j+i;k++){//开始扫 
				for(int l=0;l<=n;l++){
					if(num[l][k]){
						flag[l]=true;
					}
				}
			}
			bool flag1=true;
			for(int l=0;l<n;l++){
				if(flag[l]==false){
					flag1=false;
					break;
				}
			}

			if(flag1){
				printf("%d",i);
//				printf("%d %d",i,j);
				goto loop;
			}
		}
	}
	loop:return 0;
}
