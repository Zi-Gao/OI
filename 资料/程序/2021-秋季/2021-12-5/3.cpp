#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	float a,b,c;
	char op;
	
	scanf("%f%c%f",&a,&op,&b);
	switch(op){
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
			c=a*b;
			break;
		case '/':
			c=a/b;
			break;
		default:
			break; 
	} 
	cout << c;
	
	return 0;
}
