#include<bits/stdc++.h>
using namespace std;

int maxFlow(vector<vector<int>> &capacity, int source, int sink, int n, int m, vector<vector<pair<int, char>>> &input);
/*
# PART 1: ��l��
	1. Ū�iinput[n][m]�C�@�Ӥ����O�@�i�P�A��pair<int,char>�s (�Ʀr,�^��)
			(��n+1�|�P)
	2. ��inputŪ�icapacity[2n+2][2n+2]
	3. ���]:
		�_�I: 0 (�_�I�s�V�Ҧ���i)
		��i�|�P����j�Ʀr�P: capacity[i][j+n]
		i�d��: 1->n
		j�d��: n+1->2n
		���I: 2n+1  (�Ҧ���j�s�V���I)

# PART 2: �D���u������: �Ʀr->�^�� 
	�i���R�j�q�_�I�}�l�n����@����}�l�O? Ans: �ɶq�q�]�t�Ʀr�̤p�Φr��ǳ̤p���}�l����
	1. �u��: �Ʀr->�^�� (2 for-loop)
	2. �qinput[n][m]�̭���ŦX���^��μƦr (�w�g���u���ǤF)
	3. ��줧��⨺����Q��i�h (�N�⨺����R��!)
	4. �o�ɭ�
		a. �p�GMaximum Flow == �ѤU�������ƶq -> �N��o����T�w�O�̨θѪ��@����
		b. �p�GMaximum Flow != �ѤU�������ƶq -> fail -> ���n��o����A����R���o���䪺�ʧ@���_��
 	
	
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
				if (!visited[h]) {		//visited = true�N���|�P�w�g���X�L�F
					
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