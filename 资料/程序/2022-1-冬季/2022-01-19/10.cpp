/***
 * @Author: Zi_Gao
 * @Date: 2022-01-17 01:09:20
 * @LastEditTime: 2022-01-19 16:13:47
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <ctime>
using namespace std;
int days;
int prn(int i);
int get_dayofweek();
int get_year();
int get_month(int years);

int main(){
    scanf("%d",&days);
    days++;
    int years=get_year();
    int months=get_month(years);
    int dayofweek=get_dayofweek();
    char weekdays[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	//YYYY-MM-DD
    printf("%d-%d-%d %s\n",years,months,days,weekdays[dayofweek]);
	return 0;
}
int get_dayofweek(){
    return (days+5)%7;
}
int get_year(){
    int years=2000;
    for(;days>(365+prn(years));years++){
        days=days-(365+prn(years));
    }
    return years;
}
int get_month(int years){
    int months=1;
    if(days>31){
		days-=31;
        months++;
	}
	if(days>28+prn(years)){
		days-=(28+prn(years));
        months++;
	}
	if(days>31){
		days-=31;
        months++;
	}
	if(days>30){
		days-=30;
        months++;
	}
	if(days>31){
		days-=31;
        months++;
	}
	if(days>30){
		days-=30;
        months++;
	}
	if(days>31){
		days-=31;
        months++;
	}
	if(days>31){
		days-=31;
        months++;
	}
	if(days>30){
		days-=30;
        months++;
	}
	if(days>31){
		days-=31;
        months++;
	}
	if(days>30){
		days-=30;
        months++;
	}
    return months;
}
int prn(int i){
    if((i%4==0)&&(i%100!=0)||(i%400==0)){
        return 1;
	}else{
        return 0;
	}
}