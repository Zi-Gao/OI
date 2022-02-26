#include <cstdio>
using namespace std;
int main(){
    freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	int in;
	int a[5]={0,0,0,0,0};
	int i=1;
	scanf("%d",&in);
	for(int w1=1;w1>=-1;w1--){
		for(int w2=1;w2>=-1;w2--){
			for(int w3=1;w3>=-1;w3--){
				for(int w4=1;w4>=-1;w4--){
					for(int w5=1;w5>=-1;w5--){
						if(w1+w2*3+w3*9+w4*27+w5*81 == (0-in)){
							if(w5 == 1){
								a[i]=81;
								i++;
							}
							if(w4 == 1){
								a[i]=27;
								i++;
							}
							if(w3 == 1){
								a[i]=9;
								i++;
							}
							if(w2 == 1){
								a[i]=3;
								i++;
							}
							if(w1 == 1){
								a[i]=1;
								i++;
							}
							
							if(w1 == -1){
								a[i]=-1;
								i++;
							}
							if(w2 == -1){
								a[i]=-3;
								i++;
							}
							if(w3 == -1){
								a[i]=-9;
								i++;
							}
							if(w4 == -1){
								a[i]=-27;
								i++;
							}
							if(w5 == -1){
								a[i]=-81;
								i++;
							}
							break;
						}
					}
				}
			}
		}
	}
	for(int j=1;j<=i-1;j++){
		if(j+1==i){
			printf("%d",a[j]);
		}else{
			printf("%d ",a[j]);
		}
	}

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
