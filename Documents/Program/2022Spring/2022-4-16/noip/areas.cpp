#include <cstdio>
#include <stack>
#include <set>
#include <con>
using namespace std;
char in[20000];
int arr[20000];
int main(){
	//read
	int n=1;
	
	stack <pair<int,int> > s;
	pair<int,int> t;
	int h=0;
	
	while(true){
		in[n]=getchar();
		if(in[n]==EOF){
			break;
		}
		if(in[n]=='\\'){
			arr[n]=arr[n-1]-1;
		}else if(in[n]=='/'){
			arr[n]=arr[n-1]+1;
		}else if(in[n]=='_'){
			arr[n]=arr[n-1];
		}
		++n;
	}
	n-=2;
	
	for(int i=0;i<=n;i++){
		arr[i]+=20000;
	}
	
	//run
	for(int i=0;i<=n;){
		int cnt=0;
//		if(in[i]=='\\'&&in[i]=='/'){
//			cnt+=1;
//		}
		int j=i+1;
		for(;j<n;j++){
//			if(in[j]=='\\'||in[j]=='/'){
//				cnt+=1;
//			}
			if(arr[j]>=arr[i]){
				printf("%d ",cnt/2);
				i=j;
				goto loop;
			}
			cnt+=(arr[i]-arr[j])*2;
		}
		arr[i]--;
		loop:;
	}
}
