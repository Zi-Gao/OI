/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#define file
using namespace std;
inline int read();
int arr[10010];
int main(){
	#ifdef file
	freopen("nextGreaterElements.in", "r", stdin);
	freopen("nextGreaterElements.out", "w", stdout);
	#endif

	int n=0;
	int t;
	//read
	while(~scanf("%d",&t)){
		arr[n++]=t;
	}
	
	for(int i=0;i<n;i++){//i->n��f(i)���� 
		for(int j=i+1;j!=i;j++){//Ѱ�� �����е�i��Ԫ��֮���һ������ai��Ԫ��--j
			if(j==n){
				j=0;
			} 
			if(arr[j]>arr[i]){//���ajԪ�ش���ai��� 
				printf("%d ",j+1);
				goto loop;//û�ҵ���0�Ĵ��� ˳�����break 
			}
		}
		printf("-1 ");//ûgoto--û�ҵ� 
		loop:;
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
