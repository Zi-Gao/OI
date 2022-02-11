/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 19:06:13
 * @LastEditTime: 2022-01-19 19:10:50
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
double n(){
    char str[100];
    cin>>str;
    switch(str[0]){
        case '+': return n()+n();
        case '-': return n()-n();
        case '*': return n()*n();
        case '/': return n()/n();
        default: return atof(str);
    }
}
int main(){
    printf("%f",n());
	return 0;
}