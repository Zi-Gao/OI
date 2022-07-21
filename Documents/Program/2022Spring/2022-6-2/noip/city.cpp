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
���Ǵӵ�һ�п�ʼ��һ��һ�еĴ��� 
height[i] ����¼��ǰ�е� i ��ȫ�ǡ�1������Ŀ; 
left[i] ����¼����ߵ����� j����������ڴ� j �� i ���κ����� k������ height[k] >= height[i]; 
right[i] ����¼���ұߵ����� j����������ڴ� i �� j ���κ����� k ������ height[k] >= height[i];
�ӵ� 1 �е� i �е���ǰ�к͵� i �е����������� =max((height[i] * (right[i] - left[i])))
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
        for(int j = 0; j < n; j++) { // ����߶� height 
            if(matrix[i][j] == 'F') height[j]++; 
            else height[j] = 0;
        }
        for(int j = 0; j < n; j++) { // ���� left 
            if(matrix[i][j] == 'F') left[j] = max(left[j], cur_left);
            else { left[j] = 0; cur_left = j + 1; }
        }
        // ���� right 
        for(int j = n - 1; j >= 0; j--) {
            if(matrix[i][j] == 'F') right[j] = min(right[j], cur_right);
            else {right[j] = n; cur_right = j;}    
        }
        // ���������� 
        for(int j = 0; j < n; j++)
            maxA = max(maxA, (right[j] - left[j]) * height[j]);
    }
    return maxA;
}

/*
���룺 
10100
10111
11111
10010

����� 
6
*/

