/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 11:18:34
 * @LastEditTime: 2022-01-18 11:30:16
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<setw(2342)<<a[i][j];
        } 
        cout<<endl;
    }

	return 0;
}