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
				a = i;  // �O���o�@����
				min = d[i];
			}

		if (a == -1) break;     // �_�I���s�q���̵u���|���w�䧹

		visit[a] = true;

		// �H��ab�i��relaxation
		for (b = 0; b < n; b++)
			if (!visit[b] && d[a] + w[a][b] < d[b] && w[a][b]>=d[a]-d[parent[a]])
			{
				d[b] = d[a] + w[a][b];
				parent[b] = a;
			}
	}
}
void find_path(long long x,vector<long long> &parent)   // �L�X�Ѱ_�I��x�I���̵u���|
{
	if (x == parent[x])
	{
		cout << x << " ";
	}
	if (x != parent[x]) // ���⤧�e�����|���L�X��
	{	
		if (parent[x] == -1) {
			cout << -1 << endl;
			return;
		}
		find_path(parent[x], parent);
		cout << x << " ";  // �A��{�b����m�L�X��
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