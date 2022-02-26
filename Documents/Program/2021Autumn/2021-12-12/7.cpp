#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for(int a='x';a<='z';a++){
		 for(char b='x';b<='z'&&b!=a;b++){
		 	char c='x'+'y'+'z'-a-b;
		 	if((a!='x')&&(c=='y')){
		 		printf("a:%c,b:%c,c:%c\n",a,b,c);
		 	}
		 }
	}
	
	return 0;
}
