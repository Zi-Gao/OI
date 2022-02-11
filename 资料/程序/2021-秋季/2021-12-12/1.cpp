#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for(int i1=123;i1<=333;i1++){
		int i2=2*(i1);
		int i3=3*(i1);
		int a,b,c,d,e,f,g,h,i;
		a=i1%10;
		b=(i1/10)%10;
		c=i1/100;
		d=i2%10;
		e=(i2/10)%10;
		f=i2/100;
		g=i3%10;
		h=(i3/10)%10;
		i=i3/100;
		if(a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i
				  && b != c && b != d && b != e && b != f && b != g && b != h && b != i
				  		    && c != d && c != e && c != f && c != g && c != h && c != i
						              && d != e && d != f && d != g && d != h && d != i
							 		            && e != f && e != g && e != h && e != i
							 		            		  && f != g && f != h && f != i
							 		            		  			&& g != h && g != i
							 		            		  					  && h != i){
			printf("%d%d%d %d%d%d %d%d%d\n",a,b,c,d,e,f,g,h,i);
		}
	}

	return 0;
}
