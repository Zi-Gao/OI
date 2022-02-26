#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(){
	for(int i=1;;i++){
		for(int j=0;j<=i;j++){
			printf("-");
			Sleep(1);
		}
		printf("H");
		Sleep(100);
		system("cls");
	}
	
	return 0;
}
