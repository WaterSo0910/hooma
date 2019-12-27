
#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class city
{
	public:
		city(long long A, long long X, long long Y)
		{
			a = A;
			x = X;
			y = Y;
		}
		city()
		{
			a = -1;
			x = y = -1;
		}
		long long a, x, y;
	private:
};


long long MST( vector<vector<long long>> &con, int n)
{
	
	vector<bool> v(n + 1, false);
	vector<long long> disto_root(n + 1, 10000000000);
	disto_root[0] = 0;

	for (int i = 1; i <= n; i++) 
	{
		int vertex_now = -1;
		long long min_cost = 10000000000;

		for (int j = 0; j <= n; j++)
		{
			if (!v[j] && disto_root[j] < min_cost)
			{
				min_cost = disto_root[j];
				vertex_now = j;
			}
		}

		if (vertex_now == -1)
			break;

		v[vertex_now] = true;

		for (int vertex_next = 0; vertex_next <= n; vertex_next++)
		{
			if (!v[vertex_next] && con[vertex_now][vertex_next] < disto_root[vertex_next])
				disto_root[vertex_next] = con[vertex_now][vertex_next];
		}
	}
	
	long long cost = 0;

	for (int i = 0; i <= n; i++)
	{
		cost += disto_root[i];
	}
	return cost;
}

int main()
{
	int n;
	cin >> n;
	vector<city> c(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].a;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].x >> c[i].y;
	}
	
	vector < vector<long long>> connection(n + 1, vector<long long>(n + 1, -1));

	for (int i = 1; i <= n; i++)
	{
		connection[i][0] = c[i].a;
		connection[0][i] = c[i].a;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				connection[i][j] = c[i].a;
				continue;
			}
			connection[i][j] = abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y);
		}
	

	cout << MST(connection, n);

	return 0;
}

