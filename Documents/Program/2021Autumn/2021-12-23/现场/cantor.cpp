#include <cstdio>
using namespace std;

int main(){
    freopen("cantor.in","r",stdin);
	freopen("cantor.out","w",stdout);
	
	int in;
	scanf("%d",&in);
	int j=in;
	int i=1;
	for(;i<j;i++){
		j-=i;
	}
	int x,y;
	if(i%2==0){
		x=i;
		y=1;
		x-=j-1;
		y+=j-1;
	}else{
		x=1;
		y=i;
		x+=j-1;
		y-=j-1;
	}
	printf("%d/%d",y,x);
	

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
