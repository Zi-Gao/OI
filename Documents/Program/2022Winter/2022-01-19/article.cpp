/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 10:13:59
 * @LastEditTime: 2022-01-19 11:00:05
 * @LastEditors: Zi_Gao
 * @Description: 统计单词
 */
#include<cstdio>
int main(){
    freopen("article.in","r",stdin);
	freopen("article.out","w",stdout);
    char ch;
    char a[10005];
    bool flag = true;
    int word=0;
    int uppercase=0;
    int lowercase=0;
    int digit=0;
    int space = 0;
    int other = 0;
    while((ch=getchar())!=EOF){
        if(ch==' '||ch=='\n'){
            if(flag){
                word++;
                flag = false;
            }
        }else{
            flag = true;
        }
        if(ch>=65&&ch<=90){
            uppercase++;
        }else if(ch>=97&&ch<=122){
            lowercase++;
        }else if(ch>='0'&&ch<='9'){
            digit++;
        }else if(ch==' '){
            space++;
        }else{
            other++;
        }
    }
    if(flag){
        word++;
        flag = false;
    }
    printf("uppercase:%d",uppercase);
    printf("\nlowercase:%d",lowercase);
    printf("\ndigit:%d",digit);
    printf("\nspace:%d",space);
    printf("\nother:%d",other);
    printf("\nword:%d",word);
    return 0;
}