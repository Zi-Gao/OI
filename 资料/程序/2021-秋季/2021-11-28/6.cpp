#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(){
	for(int i=1;true;i++){
		for(int j=1;j<=i/80;j++){
			printf("\n");
			printf("\n");
			printf("\n");
		}

		if(i/80%2 == 0){
			for(int j=4;j<=i%80;j++){
				printf(" ");
			}
			printf(" O\n");
			for(int j=4;j<=i%80;j++){
				printf(" ");
			}
			printf("/H\\\n");
			for(int j=4;j<=i%80;j++){
				printf(" ");
			}
			printf("II");
			Sleep(10);
			system("cls");
		}else{
			for(int j=76;j>=i%80;j--){
				printf(" ");
			}
			printf(" O\n");
			for(int j=76;j>=i%80;j--){
				printf(" ");
			}
			printf("/H\\\n");
			for(int j=76;j>=i%80;j--){
				printf(" ");
			}
			printf("II");
//			Sleep(1);
			system("cls");
		}
	}
	
	return 0;
}
