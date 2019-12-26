#include<bits/stdc++.h>
using namespace std;

int maxFlow(vector<vector<int>> &capacity, int source, int sink, int n, int m, vector<vector<pair<int, char>>> &input);
/*
# PART 1: 初始化
	1. 讀進input[n][m]每一個元素是一張牌，用pair<int,char>存 (數字,英文)
			(第n+1疊牌)
	2. 把input讀進capacity[2n+2][2n+2]
	3. 假設:
		起點: 0 (起點連向所有的i)
		第i疊牌中有j數字牌: capacity[i][j+n]
		i範圍: 1->n
		j範圍: n+1->2n
		終點: 2n+1  (所有的j連向終點)

# PART 2: 挑選優先順序: 數字->英文 
	【分析】從起點開始要選哪一條邊開始呢? Ans: 盡量從包含數字最小及字典序最小的開始選邊
	1. 優先: 數字->英文 (2 for-loop)
	2. 從input[n][m]裡面找符合的英文及數字 (已經有優先序了)
	3. 找到之後把那條邊被選進去 (就把那條邊刪除!)
	4. 這時候
		a. 如果Maximum Flow == 剩下的元素數量 -> 代表這個邊確定是最佳解的一部分
		b. 如果Maximum Flow != 剩下的元素數量 -> fail -> 不要選這條邊，把剛剛刪掉這個邊的動作都復原
 	
	
*/
void solve(vector<vector<int>> &capacity, int n, int m, vector<vector<pair<int, char>>> &input) {

	vector<bool>visited(n, false);

	for (int i = 0; i < n * 2 + 2; i++)
	{
		for (int j = 0; j < n * 2 + 2; j++)
		{
			if (i == 0 && j <= n && j >= 1)capacity[i][j] = 1;
			if (j == 2 * n + 1 && i > n && i <= 2 * n)capacity[i][j] = 1;
			if (i >= 1 && i <= n && j > n&&j <= 2 * n)
			{
				for (int h = 0; h < input[i-1].size(); h++)
				{
					capacity[i][n + input[i - 1][h].first] = 1;
				}
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = int('A'); j<int('A') + m; j++)
		{
			int h;
			bool found = false;
			for (h = 0; h < n; h++)
			{
				if (!visited[h]) {		//visited = true代表那疊牌已經拜訪過了
					
					int k;
					for (k = 0; k < input[h].size(); k++)
					{
						if (input[h][k].first == i + 1 && input[h][k].second == char(j))
						{
							found = true;
							break;
						}

					}
					if (found)break;
				}
			}
			if (found)
			{
				found = false;
				capacity[0][h + 1] = 0;
				for (int k = 0; k < input[h].size(); k++)
				{
					capacity[h + 1][input[h][k].first + n] = 0;
				}
				capacity[n + i + 1][2 * n + 1] = 0;


				if (maxFlow(capacity, 0, n * 2 + 1, n, m, input) == n - i - 1)
				{
					cout << i + 1 << char(j) << " ";
					visited[h] = true;
					break;
				}
				else
				{
					capacity[0][h + 1] = 1;
					for (int k = 0; k < input[h].size(); k++)
					{
						capacity[h + 1][input[h][k].first + n] = 1;
					}
					capacity[n + i + 1][2 * n + 1] = 1;


				}
			}
			
		}
	}

}
bool BFS(vector<vector<int>> &capacity, vector<int> &parent, int source, int sink) {
	vector<bool> visited(capacity.size(), false);
	queue<int> queue;

	queue.push(source);
	visited[source] = true;
	bool foundPath = false;

	//see if we can found augmented path from source to sink
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop();

		for (int v = 0; v < capacity.size(); v++) {
			//explore the vertex only if it is not visited and its residual capacity is
			//greater than 0
			if (!visited[v] && capacity[u][v] > 0) {
				//add in parent map saying v got explored by u
				parent[v] = u;
				//add v to visited
				visited[v] = true;
				//add v to queue for BFS
				queue.push(v);
				//if sink is found then augmented path is found
				if (v == sink) {
					foundPath = true;
					break;
				}

			}
		}
	}
	//returns if augmented path is found from source to sink or not
	//cout << foundAugmentedPath;
	return foundPath;
}
int maxFlow(vector<vector<int>> &capacity, int source, int sink, int n, int m, vector<vector<pair<int, char>>> &input) {
	//declare and initialize residual capacity as total avaiable capacity initially.
	vector<vector<int>>residualCapacity(capacity.size(), vector<int>(capacity.size()));
	for (int i = 0; i < capacity.size(); i++) {
		for (int j = 0; j < capacity[0].size(); j++) {
			residualCapacity[i][j] = capacity[i][j];
		}
	}


	//this is parent map for storing BFS parent
	vector<int> parent(capacity.size());

	//stores all the augmented paths
	//list<list<int>> augmentedPaths;

	//max flow we can get in this network
	int maxFlow = 0;

	//see if augmented path can be found from source to sink.
	while (BFS(residualCapacity, parent, source, sink)) {
		//	list<int> augmentedPath;
		int flow = 1e9;
		//found minimum residual capacity in augmented path
		//also add vertices to augmented path vector
		int v = sink;
		while (v != source) {
			//augmentedPath.push_back(v);
			int u = parent[v];
			if (flow > residualCapacity[u][v]) {
				flow = residualCapacity[u][v];
			}
			v = u;
		}
		//augmentedPath.push_back(source);
		//augmentedPath.reverse();
		//augmentedPaths.push_back(augmentedPath);

		//add min capacity to max flow
		maxFlow += flow;

		//decrease residual capacity by min capacity from u to v in augmented path
		// and increase residual capacity by min capacity from v to u
		v = sink;
		while (v != source) {
			int u = parent[v];
			residualCapacity[u][v] -= flow;
			residualCapacity[v][u] += flow;
			v = u;
		}
	}

	return maxFlow;
}


int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, char>>> input(n, vector<pair<int, char>>(n));
	vector<vector<int>> capacity(2 * n + 2, vector<int>(2 * n + 2, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			pair<int, char>temp;
			cin >> temp.first >> temp.second;
			input[i].push_back(temp);
		}
	}
	solve(capacity, n, m, input);
	system("pause");
	return 0;
}