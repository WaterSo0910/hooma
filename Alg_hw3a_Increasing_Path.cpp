#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	long long weight;
	long long edge;
	Node(long long w, long long e)
		:weight(w), edge(e) {
	}
	~Node() {}


};

void isbest(bool &flag,long long t, vector<long long> &parent, vector<vector<Node>> &adj, vector<long long> &height) {

	for (auto j = adj[parent[t]].begin(); j != adj[parent[t]].end(); j++) {
		if ((*j).edge == t) {
			if ((*j).weight < height[t])
			{
				//cout << "w: " << (*j).weight << "\nh: " << height[t] << endl;
				flag = false;
				return;
			}
		}
	}
	if (parent[t] == t) {
		return;
	}
	else {
		isbest(flag,parent[t], parent, adj, height);
	}

}
void find_path(long long t, vector<long long> &parent) {
	if (parent[t] == t) {
		cout << t << " ";
		return;
	}
	find_path(parent[t], parent);
	cout << t << " ";
}
bool isgood = false;
void BFS(long long n, long long s, long long t, vector<vector<Node>> &adj, vector<bool> &visit, vector<long long> &parent, vector<long long> &height)
{
	queue<long long> q;
	isgood = false;

	// 一、把起點放入queue。
	q.push(s);
	visit[s] = true;
	parent[s] = s;
	height[s] = 0;

	// 二、重複下述兩點，直到queue裡面沒有東西為止：
	while (!q.empty())
	{
		// 甲、從queue當中取出一點。
		long long i = q.front();
		q.pop();

		// 乙、找出跟此點相鄰的點，並且尚未遍歷的點
		//     依照編號順序通通放入queue。

		for (auto j = adj[i].begin(); j != adj[i].end(); j++)
			if (!visit[(*j).edge] && (*j).weight >= height[i] + 1)
			{
				q.push((*j).edge);
				visit[(*j).edge] = true;
				parent[(*j).edge] = i;
				height[(*j).edge] = height[i] + 1;
				if ((*j).edge == t) {
					isgood = true;
					return;
				}
			}

	}

}
void BFS0(long long n, long long s, long long t, vector<vector<Node>> &adj, vector<bool> &visit0, vector<long long> &parent0, vector<long long> &height0)
{
	queue<long long> q;

	// 一、把起點放入queue。
	q.push(s);
	visit0[s] = true;
	parent0[s] = s;
	height0[s] = 0;

	// 二、重複下述兩點，直到queue裡面沒有東西為止：
	while (!q.empty())
	{
		// 甲、從queue當中取出一點。
		long long i = q.front();
		q.pop();

		// 乙、找出跟此點相鄰的點，並且尚未遍歷的點
		//     依照編號順序通通放入queue。

		for (auto j = adj[i].begin(); j != adj[i].end(); j++)
			if (!visit0[(*j).edge])
			{
				q.push((*j).edge);
				visit0[(*j).edge] = true;
				parent0[(*j).edge] = i;
				height0[(*j).edge] = height0[i] + 1;
				if ((*j).edge == t) {
										return;
				}
			}

	}

}
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long x;
	cin >> x;
	while (x > 0) {
		x--;
		long long n, m, s, t;
		cin >> n >> m >> s >> t;

	
		vector<vector<Node>> adj(n);
		vector<bool> visit(n);
		vector<long long> parent(n);
		vector<long long> height(n);		
		vector<bool> visit0(n);
		vector<long long> parent0(n);
		vector<long long> height0(n);
		for (long long i = 0; i < n; i++)
		{
			visit[i] = false;
			parent[i] = -1;
			height[i] = 0;			
			visit0[i] = false;
			parent0[i] = -1;
			height0[i] = 0;
		}

		for (long long i = 0; i < m; i++)
		{
			long long u, v, we;
			cin >> u >> v >> we;

			adj[u].push_back(Node(we, v));
		}

		if (s == t) {
			cout << t << "\n";
			continue;
		}

		BFS(n, s, t, adj, visit, parent, height);
		BFS0(n, s, t, adj, visit0, parent0, height0);
		bool flag= true;
		if (!isgood) {
			cout << -1 << "\n";
		}
		else {
			//isbest(flag,t, parent, adj, height);
			if (height[t]==height0[t]) {
				find_path(t, parent);
				cout << "\n";
			}
			else {
				cout << -1 << "\n";
			}

		}
	}
	system("pause");
	return 0;
}




