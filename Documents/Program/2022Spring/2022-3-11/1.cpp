/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
4
7 9 3 6 4 2 5 3
 */
#include <cstdio>
using namespace std;
inline int read();
int main(){
	int N=read()*2;
	int arr[1000]={0};
	int sumJ=0,sumO=0;
	
	for(int i=1;i<=N;i++){
		arr[i]=read();
		if(i%2==0){
			sumO+=arr[i];
		}else{
			sumJ+=arr[i];
		}
	}
	
	
	
	if(sumJ>sumO){
		int i=1,j=N;
		while(i<j){
			if(i%2==1){
				printf("%d\n",arr[i]);
				i++;
			}else{
				printf("%d\n",arr[j]);
				j--;
			}
			
			if(arr[i]>=arr[j]){
				printf("L %d\n",arr[i]);
				i++;
			}else{
				printf("R %d\n",arr[j]);
				j--;
			}
		}
		printf("%d\n",sumJ);
		printf("%d",sumO);
	}else{
		int i=1,j=N;
		while(i<j){
			if(i%2==1){
				printf("%d\n",arr[j]);
				j--;
			}else{
				printf("%d\n",arr[i]);
				i++;
			}
			
			if(arr[i]>=arr[j]){
				printf("L %d\n",arr[i]);
				i++;
			}else{
				printf("R %d\n",arr[j]);
				j--;
			}
		}
		printf("%d\n",sumO);
		printf("%d",sumJ);
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
