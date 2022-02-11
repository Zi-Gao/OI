#include <cstdio>
using namespace std;
int main(){
    freopen("zero.in","r",stdin);
	freopen("zero.out","w",stdout);
	
	int in;
	scanf("%d",&in);
	int zero1=0;
	for(int i=1;i<=in;i++){
		int temp = i;
		while(temp % 5==0){
			temp/=5;
			zero1++;
		}
		
	}
	printf("%d",zero1);

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
