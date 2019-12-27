
#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void IPath(long long s, long long t, long long n, vector<long long> &h, vector<bool> &v, vector<long long> &p, vector<vector<long long>> &g)
{
	queue<long long> q;
	
	q.push(s);
	v[s] = true;
	p[s] = s;
	//h[s] = 0;

	while (!q.empty())
	{
		long long temp = q.front();
		q.pop();


		for (long long i = 0; i < n; i++)
		{
			if (!v[i] && g[temp][i] >= h[temp] + 1)
			{
				v[i] = true;
				p[i] = temp;
				h[i] = h[temp] + 1;
				q.push(i);
				if (i == t)
				{
					return;
				}
			}
		}
	}
	return;
}

void BFS(long long s, long long t, long long n, vector<long long> &h, vector<bool> &v, vector<vector<long long>> &g)
{
	queue<long long> q;

	q.push(s);
	v[s] = true;
	//p[s] = s;
	//h[s] = 0;

	while (!q.empty())
	{
		long long temp = q.front();
		q.pop();

		for (long long i = 0; i < n; i++)
		{
			if (!v[i] && g[temp][i]>0)
			{
				v[i] = true;
				//p[i] = temp;
				h[i] = h[temp] + 1;
				q.push(i);
				if (i == t)
				{
					return;
				}
			}
		}
	}
	return;
}

void traverse(vector<long long> &p, long t)
{
	if (p[t] == t)
	{
		cout << t << " ";
		return;
	}
	traverse(p, p[t]);
	cout << t << " ";
	return;
}

int main()
{
	long long T;
	cin >> T;

	for (long long i = 0; i < T; i++)
	{
		long long n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<vector<long long>> graph(n, vector<long long> (n ,-1));
		for (long long j = 0; j < m; j++)
		{
			long long u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = max(graph[u][v], w);
		}
		if (s == t)
		{
			cout << t << "\n";
			continue;
		}
		vector<long long> height(n, 0);
		vector<bool> v(n, false);
		vector<long long> p(n, -1);
		
		vector<long long> hBFS(n, 0);
		vector<bool> vBFS(n, false);
		//vector<long long> pBFS(n, 0);
		
		IPath(s, t, n, height, v, p, graph);
		BFS(s, t, n, hBFS, vBFS, graph);
		
		if (height[t] == hBFS[t])
		{
			if (height[t] > 0)
			{
				traverse(p, t);
				cout << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
		
	}

	return 0;
}

