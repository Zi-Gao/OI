/***
 * @Author: Zi_Gao
 * @Date: 2022-01-17 01:09:20
 * @LastEditTime: 2022-01-17 15:02:17
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
char inttochar(int n){
	char keys[11]={"0123456789"};
	return keys[n];
}
int prn(int i){
    if((i%4==0)&&(i%100!=0)||(i%400==0)){
        return 1;
	}else{
        return 0;
	}
}
int main(){
    int days=time(NULL)/86400+1;
    int years=1970;
    int months=1;
    for(;days>(365+prn(years));years++){
        days=days-(365+prn(years));
    }
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
	//YYYY-MM-DD
	char a[17]={'m','k','d','i','r',' ',inttochar(years/1000),inttochar(years/100%10),inttochar(years/10%10),inttochar(years%10),'-',inttochar(months/10),inttochar(months%10),'-',inttochar(days/10),inttochar(days%10),'\0'};
	system(a);
	return 0;
}