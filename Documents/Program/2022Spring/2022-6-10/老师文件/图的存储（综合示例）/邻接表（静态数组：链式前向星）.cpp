#include <bits/stdc++.h>
using namespace std;
int n, m;
int head[15];

struct node {
	int to;
	int val;
	int next; 
} edge[50]; 

void addEdge(int i, int a, int b, int w) {
	edge[i].to = b;
	edge[i].val = w;
	edge[i].next = head[a];
	head[a] = i;
}

void readData() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		addEdge(i, a, b, w);
		//˫��ͼ������������i+m 
		//��Ȼ�ᵼ�µ�i���߱�������Σ����ݱ����� 
		addEdge(i + m, b, a, w);
	}	
}

void printEdge() {
	for(int i = 1; i <= n; i++) {
		cout << i << " : ";
		int p = head[i];
		while(p) {
			cout << edge[p].to << " ";
			p = edge[p].next;
		}
		cout << endl;
	}
}

int main() {
	freopen("shu_in.txt", "r", stdin);
	readData();
	printEdge();
	return 0;
} 
