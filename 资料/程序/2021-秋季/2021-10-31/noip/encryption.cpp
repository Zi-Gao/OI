#include <cstdio>
using namespace std;
int main(){
    freopen("encryption.in","r",stdin);
	freopen("encryption.out","w",stdout);
    
    char a,b,c,d,e;
    scanf("%c",&a);
    scanf("%c",&b);
    scanf("%c",&c);
    scanf("%c",&d);
    scanf("%c",&e);
    printf("%c",a+4);
    printf("%c",b+4);
    printf("%c",c+4);
    printf("%c",d+4);
    printf("%c",e+4);
    
    fclose(stdin);
	fclose(stdout); 
	return 0;
}
