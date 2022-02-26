#include <cstdio>
using namespace std;
int main(){
	freopen("a+b.in","r",stdin);
	freopen("a+b.out","w",stdout);
	
	int a,b;
	
	scanf("%d %d",&a,&b);
	printf("%d",a+b);
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}
