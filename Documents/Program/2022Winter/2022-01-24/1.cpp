/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 15:02:52
 * @LastEditTime: 2022-01-24 15:17:17
 * @LastEditors: Zi_Gao
 * @Description: 二分-快排
 */
#include <cstdio>
#include <algorithm>
using namespace std;
struct student{
    int math,chinese,english;
};
bool cmp(student a,student b){
    if(a.math==b.math){
        if(a.chinese==b.chinese){
            return a.english<b.english;
        }else{
            return a.chinese<b.chinese;
        }
    }else{
        return a.math<b.math;
    }
}
bool compare(int a, int b){
    return a>b;//降序
}
int main(){
    //test sort
    /*rand*/
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    sort(a,a+10);

    printf("sort");
    putchar('\n');
    for(int i=0; i<10; i++){
        printf("%d ",a[i]);
    }

    putchar('\n');

    printf("sort 3降序");
    sort(a,a+10,compare);//compare(a,b,函数指针)
        for(int i=0; i<10; i++){
        printf("%d ",a[i]);
    }

    putchar('\n');

    printf("sort 结构体");
    student s[5]={{1,2,3},{2,3,4},{3,4,5},{4,5,6},{5,6,7}};
    sort(s,s+5,cmp);
    for(int i=0; i<5; i++){
        printf("Math:%d Chinese:%d English:%d\n",s[i].math,s[i].chinese,s[i].english);
    }
}