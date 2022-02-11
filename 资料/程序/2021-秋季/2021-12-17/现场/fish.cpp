#include <cstdio>
using namespace std;
int main(){
    freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);

	int y,m,d;
	scanf("%d %d %d",&y,&m,&d);
	int day=0;
	for(int i=1990;i<y;i++){
		if((i%4==0)&&(i%100!=0)||(i%400==0)){
			day+=366;
//			printf("rrr");
		}else{
			day+=365;
//			printf("ppp");
		}
	}

	if(m>1){
		day+=31;
	}
	if(m>2){
		if((y%4==0)&&(y%100!=0)||(y%400==0)){
			day+=29;
		}else{
			day+=28;
		}
	}
	if(m>3){
		day+=31;
	}
	if(m>4){
		day+=30;
	}
	if(m>5){
		day+=31;
	}
	if(m>6){
		day+=30;
	}
	if(m>7){
		day+=31;
	}
	if(m>8){
		day+=31;
	}
	if(m>9){
		day+=30;
	}
	if(m>10){
		day+=31;
	}
	if(m>11){
		day+=30;
	}
	if(m>12){
		day+=31;
	}
	day+=d;
	if((day%5==1)||(day%5==2)||(day%5==3)){
		printf("fish");
	}else{
		printf("sleep");
	}
//	printf("%d",day);

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
