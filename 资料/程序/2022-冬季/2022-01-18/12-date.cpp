/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 17:00:53
 * @LastEditTime: 2022-01-18 17:20:01
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    // freopen("word.in","w",stdout);
    srand((unsigned)time(NULL));
    for(int i=1; i<=2;i++){
        int jMax = rand()%100+1;
        for(int j=0; j<=jMax;j++){
            int Aa=rand()%2;
            int a=rand()%10;
            if(a==0){
                if(!Aa){
                    printf("%c",rand()%25+97);
                }else{
                    printf("%c",rand()%25+65);
                }
            }else{
                printf("%c",rand()%(94-33)+33);
            }
        }
        printf("\n");
    }
	return 0;
}