#include <cstdio>
using namespace std;



int daysofmonths[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void print(int day){
	int year,month;
	day+=244;
	year=2013;
	month=1;
	
	while(true){//year
		if(day>(((year%400==0)||((year&3)==0)&&(year%100!=0))?366:365)){
			day-=(((year%400==0)||((year&3)==0)&&(year%100!=0))?366:365);
			++year;
		}else{
			break;
		}
	}
	
	while(true){//year
		if((month==2&&((year%400==0)||((year&3)==0)&&(year%100!=0)))){
			if(day>29){
				day-=29;
				++month;
			}else{
				break;
			}
		}else if(day>daysofmonths[month]){
			day-=daysofmonths[month];
			++month;
		}else{
			break;
		}
//		if(month==13){
//			month=0;
//		}
	}
	
	printf("%d-",year);
	if(month<10){
		putchar('0');
	}
	printf("%d-",month);
	if(day<10){
		putchar('0');
	}
	printf("%d",day);
};

int main(){
	freopen("shower.in","r",stdin);
	freopen("shower.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	print(7*n);
	
	
	return 0;
}
