#include <cstdio>
using namespace std;
int main(){
//    freopen("maxnum.in","r",stdin);
//	freopen("maxnum.out","w",stdout);
    
    int a,b,c,d,e,f,g;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    f = a;
    if(b>f){
    	f = b;
    }
    if(c>f){
    	f = c;
    }
    if(d>f){
    	f = d;
    }
    if(e>f){
    	f = e;
    }
    
    g=a;
    
    if(b<g){
    	g = b;
    }
    if(c<g){
    	g = c;
    }
    if(d<g){
    	g = d;
    }
    if(e<g){
    	g = e;
    }
    printf("max=%d\n",f);
    printf("min=%d",g);
    
    fclose(stdin);
	fclose(stdout); 
	return 0;
}
