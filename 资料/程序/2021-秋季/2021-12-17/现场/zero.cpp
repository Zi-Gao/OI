#include <cstdio>
using namespace std;
int main(){
    freopen("zero.in","r",stdin);
	freopen("zero.out","w",stdout);
	
	int in;
	scanf("%d",&in);
	int zero1=0;
	for(int i=1;i<=in;i++){
		if(((i-1)%10+1) == 5) {//***������������һ������5--->��һ��0 
			zero1+=1;
		}
		if(i%10==0){
			int j;
			for(j=1;;j++){
				int t=1;
				for(int k=1;k<=j;k++){
					t*=10;
				}
				if(i%t!=0){
					break;
				}
			}
			zero1+=j-1;
		}
	}
	printf("%d",zero1);

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
