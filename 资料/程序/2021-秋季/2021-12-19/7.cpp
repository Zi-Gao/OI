#include <cstdio>
#include <cstdlib>
#include <cmath>
double power(double a,int n);
double arctanx(double x);

using namespace std;
int main(){
	printf("%d",arctanx(sqrt(3)));
	
	return 0;
}

double arctanx(double x){
	double out=0;
	bool flat=true;
	for(int i=1;(power(x,i)/i)>0.00001;i+=2){
		printf("%d",(power(x,i)/i));
		if(flat){
			out+=power(x,i)/i;
			flat=false;
		}else{
			out-=power(x,i)/i;
			flat=true;
		}
	}
	return out;
}

double power(double a,int n){
	if(n==1){
		return a;
	}
	return a*power(a,n-1);
}
