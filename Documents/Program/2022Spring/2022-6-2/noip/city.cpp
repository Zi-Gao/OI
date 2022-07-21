#include <iostream>
#include <cstdio>
#include <vector>
#include <stack> 
#include <algorithm>
using namespace std;
int maximalRectangle(vector<vector<char> >& matrix);

int main(){
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	
	vector<char> ma;
	vector<vector<char> > matrix;
	char ch;
	int i = 0, j = 0;
	scanf("%d %d",&i,&j);
	getchar();
	while(~scanf("%c", &ch)) {		
		if(ch == '\n' || ch == '\r'){
			if(!ma.empty()){
				matrix.push_back(ma);
				ma.clear();	
			}
		}
		else if(ch == 'F' || ch == 'R'){
			ma.push_back(ch);			
		}				
	}
	if(!ma.empty()){
		matrix.push_back(ma);
		ma.clear();	
	}	
	cout << maximalRectangle(matrix)*3;
	return 0;
}


/*
我们从第一行开始，一行一行的处理： 
height[i] ：记录当前行第 i 列全是‘1’的数目; 
left[i] ：记录最左边的索引 j，它满足对于从 j 到 i 的任何索引 k，满足 height[k] >= height[i]; 
right[i] ：记录最右边的索引 j，它满足对于从 i 到 j 的任何索引 k ，满足 height[k] >= height[i];
从第 1 行第 i 列到当前行和第 i 列的最大矩形区域 =max((height[i] * (right[i] - left[i])))
*/ 
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];  
    fill_n(left, n, 0); fill_n(right, n, n); fill_n(height, n, 0);
    int maxA = 0;
    for(int i = 0; i < m; i++) {
        int cur_left = 0, cur_right = n; 
        for(int j = 0; j < n; j++) { // 计算高度 height 
            if(matrix[i][j] == 'F') height[j]++; 
            else height[j] = 0;
        }
        for(int j = 0; j < n; j++) { // 计算 left 
            if(matrix[i][j] == 'F') left[j] = max(left[j], cur_left);
            else { left[j] = 0; cur_left = j + 1; }
        }
        // 计算 right 
        for(int j = n - 1; j >= 0; j--) {
            if(matrix[i][j] == 'F') right[j] = min(right[j], cur_right);
            else {right[j] = n; cur_right = j;}    
        }
        // 计算最大矩形 
        for(int j = 0; j < n; j++)
            maxA = max(maxA, (right[j] - left[j]) * height[j]);
    }
    return maxA;
}

/*
输入： 
10100
10111
11111
10010

输出： 
6
*/

