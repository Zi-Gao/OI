#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for(int a=1;a<=5;a++){
		for(int b=1;b<=5;b++){
			for(int c=1;c<=5;c++){
				if(a!=b&&a!=c&&b!=c){
					if(a==1){
						printf("red ");
					}
					if(a==2){
						printf("orange ");
					}
					if(a==3){
						printf("yellow ");
					}
					if(a==4){
						printf("green ");
					}
					if(a==5){
						printf("blue ");
					}
					
					if(b==1){
						printf("red ");
					}
					if(b==2){
						printf("orange ");
					}
					if(b==3){
						printf("yellow ");
					}
					if(b==4){
						printf("green ");
					}
					if(b==5){
						printf("blue ");
					}
					
					if(c==1){
						printf("red ");
					}
					if(c==2){
						printf("orange ");
					}
					if(c==3){
						printf("yellow ");
					}
					if(c==4){
						printf("green ");
					}
					if(c==5){
						printf("blue ");
					}
					putchar('\n');
				}
				
				
			}
		}
	}
	putchar('\n');
	for(int a=1;a<=5;a++){
		for(int b=1;b<=5;b++){
			for(int c=1;c<=5;c++){
				if(a!=b&&a!=c&&b!=c&&a<b&&b<c){
					if(a==1){
						printf("red ");
					}
					if(a==2){
						printf("orange ");
					}
					if(a==3){
						printf("yellow ");
					}
					if(a==4){
						printf("green ");
					}
					if(a==5){
						printf("blue ");
					}
					
					if(b==1){
						printf("red ");
					}
					if(b==2){
						printf("orange ");
					}
					if(b==3){
						printf("yellow ");
					}
					if(b==4){
						printf("green ");
					}
					if(b==5){
						printf("blue ");
					}
					
					if(c==1){
						printf("red ");
					}
					if(c==2){
						printf("orange ");
					}
					if(c==3){
						printf("yellow ");
					}
					if(c==4){
						printf("green ");
					}
					if(c==5){
						printf("blue ");
					}
					putchar('\n');
				}
				
			}
		}
	}
	return 0;
}
//int C(int n,m){
//	return 
//}
//long long int jiechen(int a){
//	long long int o;
//	for(int i;i<=a;i++){
//		o*=i;
//	}
//	return o;
//}
