#include <cstdio>
using namespace std;
long long int a[1000010];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,out=0;
	scanf("%d",&n);	
	//模拟解 
	for(int i=2;i<=n;i++){
		for(int j=1;j*i<=n;j++){
			if(a[j*i]==0){
				a[j*i]=1;
			}else{
				a[j*i]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			out++;
		}
	}
	
	printf("%d",out);
	//规律解
	/*
	背面朝上的
	 
	4
	9
	16
	25
	... 
	*/

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
