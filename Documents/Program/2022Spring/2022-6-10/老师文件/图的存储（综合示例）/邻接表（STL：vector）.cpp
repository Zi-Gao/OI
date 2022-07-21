#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
	int to;
	int val;
};

vector<node> vec[15];
int edgeNum[15];

void addEdge(int a, int b, int w) {
	edgeNum[a]++;
	node* p = new node();
	p->to = b;
	p->val = w; 
	vec[a].push_back(*p);
}

void readData() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		addEdge(a, b, w);
		addEdge(b, a, w);
	}	
}

void printEdge() {
	for(int i = 1; i <= n; i++) {
		cout << i << " : ";
		for(int j = 1; j <= edgeNum[i]; j++) {
			node* p = new node();
			*p = vec[i].back();
			vec[i].pop_back();
			cout << p->to << " ";
		}
		cout<<endl;
	}
}

int main() {
	freopen("shu_in.txt", "r", stdin);
	readData();
	printEdge();
	return 0;
} 


