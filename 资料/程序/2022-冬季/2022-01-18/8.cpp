/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 11:18:34
 * @LastEditTime: 2022-01-18 14:33:13
 * @LastEditors: Zi_Gao
 * @Description:
 */
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    int a[20][12]={0};
    for(int i=0; i<1000000;i++){
        int x=rand()%20;
        int y=rand()%12;
        a[x][y]++;
    }
    for(int i=0; i<20; i++){
        for(int j=0; j<12; j++){
            printf("%d %d:%d\n",i+1,j+1,a[i][j]);
        }
        cout<<endl;
    }
}