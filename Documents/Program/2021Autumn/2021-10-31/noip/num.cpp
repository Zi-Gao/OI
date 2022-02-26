#include <cstdio>
using namespace std;
int main(){
    freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	
    int a,t;
    scanf("%d",&a);
    
    printf("%d",a%10);
    t=a/10;
    printf("%d",t%10);
    t=a/100;
    printf("%d",t%10);
    t=a/1000;
    printf("%d",t%10);
    t=a/10000;
    printf("%d",t);
    
    fclose(stdin);
	fclose(stdout); 
	return 0;
}
