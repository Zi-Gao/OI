#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	for(int a=4;a<=100;a+=2){
		bool flag_b = true;
		for(int b=2;b<a;b++){
			for(int i=2;i<sqrt(b);i++){
				if(b%i==0){
					flag_b=false;
					break;
				}
			}
			if(flag_b){
				bool flag_c = true;
				int c=a-b;
				for(int i=2;i<sqrt(c);i++){
					if(c%i==0){
						flag_c=false;
						break;
					}
				}
				if(flag_c){
					cout << a << "=" << b << "+" << c << endl; 
				}
			}
		}
		
	} 
	
	
	return 0;
}
