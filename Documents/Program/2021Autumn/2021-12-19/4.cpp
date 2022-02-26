#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int SIZE=100;
int main(){
	srand((unsigned int)time(NULL));
	int a[SIZE];
	for(int i=0;i<SIZE;i++){
		a[i]=rand()%(SIZE/10)+1;
	}
	for(int i=0;i<SIZE-1;i++){
		for(int j=i+1;j<SIZE;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	
	for(int i=0;i<SIZE;i++){
		
		printf("%d ",a[i]);
	}
	printf("\n");
	int cnt=1;
	for(int i=1;i<SIZE;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			printf("%d:%d\n",a[i-1],cnt);
			cnt=1;
		}
		
	}

	return 0;
}
