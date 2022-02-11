#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE=10;
int main(){
	int a[SIZE][SIZE]={0};
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(i==0){
				a[i][j]=1;
			}else if(j==0){
				a[i][j]=1;
			}else if(i==j){
				a[i][j]=1;
				break;  
			}else{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
	}
	for(int i=0;i<SIZE;i++){
		for(int k=i;k<SIZE;k++){
			printf("  ");
		}
		for(int j=0;j<SIZE;j++){
			
			printf("%4d",a[i][j]);
			if(i==j){
				break;
			}
		}
		printf("\n");
	}

	return 0;
}
