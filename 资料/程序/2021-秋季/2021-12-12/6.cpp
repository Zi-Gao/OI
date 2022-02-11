#include <cstdio>
#include <iostream>
using namespace std;
int main(){

	for(int x=0;x<=10;x++){
		for(int y=0;y<=50;y++){
			int z = 3*(500-x*50-y*10);
			if((x+y+z)==100){
				printf("%d %d %d",x,y,z);
			} 
		}
	}
	
	return 0;
}
