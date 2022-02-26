/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 08:27:28
 * @LastEditTime: 2022-01-24 08:36:59
 * @LastEditors: Zi_Gao
 * @Description: matrix*matrix
 */
#include <cstdio>
int main(){
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    int m,p,n;
    scanf("%d %d %d",&m,&p,&n);
    //read matrix
    int matrix_1[m][p];
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            scanf("%d",&matrix_1[i][j]);
        }
    }
    //read matrix
    int matrix_2[p][n];
    for(int i=0;i<p;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix_2[i][j]);
        }
    }
    //matrix_1*matrix_2=matrix_3
    int matrix_3[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix_3[i][j]=0;
            for(int k=0;k<p;k++){
                matrix_3[i][j]+=matrix_1[i][k]*matrix_2[k][j];
            }
        }
    }
    //output matrix_3
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix_3[i][j]);
        }
        printf("\n");
    }
}