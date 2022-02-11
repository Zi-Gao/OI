#include <cstdio>
using namespace std;
void swap(int &a,int &b){
	a+=b;
	b=a-b;
	a=a-b;
}
void f(int &a,int &b,int &c,int &d){
    
    for(int i=1;i<=4;i++){
    	if(a>b){
    		swap(a,b);
    	}
    	if(b>c){
    		swap(b,c);
    	}
    	if(c>d){
    		swap(c,d);
    	}
    }
}
int main(){
    freopen("blackhole.in","r",stdin);
	freopen("blackhole.out","w",stdout);
	
	int in;
	scanf("%d",&in);
	int a,b,c,d;
	a=in%10;
	b=in/10%10;
	c=in/100%10;
	d=in/1000;
	int i;
	for(i=0;in!=6174;i++){
		a=in%10;
		b=in/10%10;
		c=in/100%10;
		d=in/1000;
		f(a,b,c,d);
		in=(a+b*10+c*100+d*1000)-(d+c*10+b*100+a*1000);
		
	}
	printf("%d",i);
//	printf("%d%d%d%d",d,c,b,a);
	

    fclose(stdin);
	fclose(stdout); 
	return 0;
}

