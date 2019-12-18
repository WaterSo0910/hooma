#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int destination, cost;
};

vector<int> Dijkstra(const vector<vector<Edge>>& dist, const int& n_vertex, const int& source) {
    // Adjacency_List 版本 O((V + E)logV)
    vector<int> dist_from_source(n_vertex, 0x2fffffff);
    vector<bool> visited(n_vertex, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reachable;  // min_heap

    dist_from_source[source] = 0;  // 假設原地不動是 0 cost
    reachable.push({0, source});   // 起點放進 Heap

    for (int i = 0; i < n_vertex; i++) {
        int vertex_now = -1;
        while (!reachable.empty()) {
            vertex_now = reachable.top().second;  // 取出距離最近的點
            if (!visited[vertex_now])             // 檢查是否走過 (避免走成環)
                break;
            reachable.pop();  // 走過了
        }

        if (vertex_now == -1)
            break;  // 無路可走，剩下的點無法抵達

        visited[vertex_now] = true;

        for (const auto& edge : dist[vertex_now])
            if (!visited[edge.destination] and dist_from_source[vertex_now] + edge.cost < dist_from_source[edge.destination]) {
                dist_from_source[edge.destination] = dist_from_source[vertex_now] + edge.cost;
                reachable.push({dist_from_source[edge.destination], edge.destination});
            }
    }
    return dist_from_source;
}

vector<int> Dijkstra(const vector<vector<int>>& dist, const int& n_vertex, const int& source) {
    // Adjacency_Matrix 版本 O(V^2logV)
    vector<int> dist_from_source(n_vertex, 0x2fffffff);
    vector<bool> visited(n_vertex, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reachable;

    dist_from_source[source] = 0;  // 假設原地不動是 0 cost
    reachable.push({0, source});   // 起點放進 Heap

    for (int i = 0; i < n_vertex; i++) {
        int vertex_now = -1;

        while (!reachable.empty()) {
            vertex_now = reachable.top().second;  // 取出距離最近的點
            if (!visited[vertex_now])             // 檢查是否走過 (避免走成環)
                break;
            reachable.pop();  // 走過了
        }

        if (vertex_now == -1)
            break;  // 無路可走，剩下的點無法抵達

        visited[vertex_now] = true;

        for (int vertex_next = 0; vertex_next < n_vertex; vertex_next++)
            // 更新周圍節點距離
            if (!visited[vertex_next] and dist_from_source[vertex_now] + dist[vertex_now][vertex_next] < dist_from_source[vertex_next]) {
                dist_from_source[vertex_next] = dist_from_source[vertex_now] + dist[vertex_now][vertex_next];
                reachable.push(pair<int, int>(dist[vertex_now][vertex_next], vertex_next));
            }
    }

    return dist_from_source;
}

vector<int> Bellman_Ford(const vector<vector<int>>& dist, const int& n_vertex, const int& source) {
    // Adjacency_Matrix 版本 O(V^3)
    vector<int> dist_from_source(n_vertex, 0x2fffffff);
    vector<bool> visited(n_vertex, false);
    dist_from_source[source] = 0;

    for (int k = 1; k < n_vertex; k++)
        for (int i = 0; i < n_vertex; i++)
            for (int j = 0; j < n_vertex; j++)
                dist_from_source[j] = min(dist_from_source[j], dist_from_source[i] + dist[i][j]);

    for (int i = 0; i < n_vertex; i++)
        for (int j = 0; j < n_vertex; j++)
            if (dist_from_source[i] + dist[i][j] < dist_from_source[j])
                cerr << "The graph has negative cycle!\n";

    return dist_from_source;
}

vector<int> Bellman_Ford(const vector<vector<Edge>>& dist, const int& n_vertex, const int& source) {
    // Adjacency_List 版本 O(V * E)
    vector<int> dist_from_source(n_vertex, 0x2fffffff);
    vector<bool> visited(n_vertex, false);
    dist_from_source[source] = 0;

    for (int k = 1; k < n_vertex; k++)
        for (int i = 0; i < n_vertex; i++)
            for (const auto edge : dist[i])
                dist_from_source[edge.destination] = min(dist_from_source[edge.destination], dist_from_source[i] + edge.cost);

    for (int i = 0; i < n_vertex; i++)
        for (const auto edge : dist[i])
            if (dist_from_source[i] + edge.cost < dist_from_source[edge.destination])
                cerr << "The graph has negative cycle!\n";

    return dist_from_source;
}

vector<vector<int>> Floyd_Warshall(vector<vector<int>> dist, int n_vertex) {
    // O(V^3)
    for (int i = 0; i < n_vertex; i++)
        for (int j = 0; j < n_vertex; j++)
            for (int k = 0; k < n_vertex; k++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

int main() {
    int n_vertex, m, start, end, cost;
    cin >> n_vertex >> m;
    vector<vector<int>> dist(n_vertex, vector<int>(n_vertex, 0x2fffffff));
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        dist[start][end] = cost;
        dist[end][start] = cost;  // Undirected Graph
    }
}
