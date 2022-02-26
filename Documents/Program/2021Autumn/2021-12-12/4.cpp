#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for(int i;i<=4;i++){
		if((i!=1)+(i==3)+(i==4)+(i==3)==3){
			
			if(i == 1){
				printf("¼×");	
			}
			if(i == 2){
				printf("ÒÒ");
			}
			if(i == 3){
				printf("±û");
			}
			if(i == 4){
				printf("¶¡");
			}
			printf("ÊÇÐ¡Íµ"); 
		}
	}

	return 0;
}
