#include <bits/stdc++.h>
using namespace std;
void dijkstra(long long n,long long source, vector<vector<long long>> &w, vector<long long> &parent, vector<long long> &d, vector<bool> &visit)
{
	for (long long i = 0; i < n; i++) visit[i] = false;
	for (long long i = 0; i < n; i++) d[i] = 1e9;
	for (long long i = 0; i < n; i++) parent[i] = -1;


	d[source] = 0;
	parent[source] = source;

	for (long long k = 0; k < n; k++)
	{
		long long a = -1, b = -1, min = 1e9;
		for (long long i = 0; i < n; i++)
			if (!visit[i] && d[i] < min)
			{
				a = i;  // 記錄這一條邊
				min = d[i];
			}

		if (a == -1) break;     // 起點有連通的最短路徑都已找完

		visit[a] = true;

		// 以邊ab進行relaxation
		for (b = 0; b < n; b++)
			if (!visit[b] && d[a] + w[a][b] < d[b] && w[a][b]>=d[a]-d[parent[a]])
			{
				d[b] = d[a] + w[a][b];
				parent[b] = a;
			}
	}
}
void find_path(long long x,vector<long long> &parent)   // 印出由起點到x點的最短路徑
{
	if (x == parent[x])
	{
		cout << x << " ";
	}
	if (x != parent[x]) // 先把之前的路徑都印出來
	{	
		if (parent[x] == -1) {
			cout << -1 << endl;
			return;
		}
		find_path(parent[x], parent);
		cout << x << " ";  // 再把現在的位置印出來
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t > 0) {
		long long n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<vector<long long>> w(n);
		for (long long i = 0; i < n; i++)
		{
			w[i].resize(n);
		}
		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < n; j++)
			{
				w[i][j] = 1e9;
			}
		}
		vector<long long> parent(n);
		vector<long long> d(n);
		vector<bool> visit(n);


		for (long long i = 0; i < m; i++)
		{
			long long u, v, we;
			cin >> u >> v >> we;
			w[u][v] = we;
		}


		dijkstra(n, s, w, parent, d, visit);
		//find_path(t, parent);
		t--;
	}


	system("pause");
	return 0;
}