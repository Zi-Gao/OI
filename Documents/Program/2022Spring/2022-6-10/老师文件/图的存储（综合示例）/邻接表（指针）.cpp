#include <bits/stdc++.h>
using namespace std;
int n, m;

struct node {
	int val;
	int to;
	node* next;	
} tree[15];  

void addEdge(int a, int b, int w) {
	node* p = new node();
	p->to = b;
	p->val = w;
	p->next = tree[a].next;
	tree[a].next = p;
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
		node* p = tree[i].next;
		while(p) {
			cout << p->to << " ";
			p = p->next;
		}
		cout<<endl;
	}
}


int main() {
	freopen("shu_in.txt","r",stdin);
	readData();
	printEdge();
	return 0;
} 
