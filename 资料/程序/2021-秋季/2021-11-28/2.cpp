#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
int main(){
	int s=120;
	
	while(s>=0){
		printf("%d:%02d",s/60,s%60);
		Sleep(1000); 
		system("cls");
		s--;
	}
	 
	return 0;
}
