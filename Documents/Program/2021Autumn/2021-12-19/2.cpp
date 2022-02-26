#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int a[3][4],x=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			a[i][j]=x++;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
