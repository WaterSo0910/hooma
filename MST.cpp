#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Disjoint_set {
    vector<int> parents;
    vector<int> rank;

   private:
    int get_parent(const int& vertex) {
        if (parents[vertex] == vertex)
            return vertex;
        parents[vertex] = get_parent(parents[vertex]);  // 路徑壓縮
        return parents[vertex];
    }

   public:
    void Union(const int& x, const int& y) {
        int x_parent = get_parent(x), y_parent = get_parent(y);
        if (x_parent != y_parent)
            parents[x_parent] = y_parent;
    }

    bool same(const int& x, const int& y) {
        return get_parent(x) == get_parent(y);  // 有共同祖先就是同一個集合
    }

    Disjoint_set(int n) {
        parents.reserve(n);
        for (int i = 0; i < n; i++)
            parents.push_back(i);
        rank = vector<int>(n, 0);
    }
};

struct Edge {
    int from, to, cost;
    Edge(int f, int t, int c) {
        from = f;
        to = t;
        cost = c;
    }
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int kruskal(const vector<Edge>& edges, const int n_vertex) {
    int weight = 0, e = 0;

    Disjoint_set mst(n_vertex);

    for (const auto edge : edges)
        if (!mst.same(edge.from, edge.to)) {
            mst.Union(edge.from, edge.to);
            weight += edge.cost;
            if (++e == n_vertex - 1)
                break;
        }
    return weight;
}

int prim(const vector<vector<int>>& dist, const int n_vertex) {
    vector<bool> visited(n_vertex, false);
    vector<int> dist_from_tree(n_vertex, 0x2fffffff);

    dist_from_tree[0] = 0;

    for (int i = 0; i < n_vertex; i++) {
        int vertex_now = -1, min_cost = 0x2fffffff;

        for (int j = 0; j < n_vertex; j++)
            if (!visited[j] and dist_from_tree[j] < min_cost) {
                min_cost = dist_from_tree[j];
                vertex_now = j;
            }

        if (vertex_now == -1)
            break;

        visited[vertex_now] = true;

        for (int vertex_next = 0; vertex_next < n_vertex; vertex_next++)
            if (!visited[vertex_next] and dist[vertex_now][vertex_next] < dist_from_tree[vertex_next])
                dist_from_tree[vertex_next] = dist[vertex_now][vertex_next];
    }

    int weight = 0;

    for (const auto& i : dist_from_tree)
        weight += i;

    return weight;
}

int main() {
    int n_vertex, m, start, end, cost;
    cin >> n_vertex >> m;
    vector<Edge> edges;
    vector<vector<int>> dist(n_vertex, vector<int>(n_vertex, 0x2fffffff));
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        dist[start][end] = cost;
        dist[end][start] = cost;
        edges.emplace_back(start, end, cost);
    }

    sort(edges.begin(), edges.end());

    cout << kruskal(edges, n_vertex) << "\n";
    cout << prim(dist, n_vertex) << "\n";
}

/*
9 12
2 4 -1
4 1 -3
4 5 0
4 8 5
1 0 5
5 0 1
5 8 2
5 7 1
8 7 4
0 3 3
7 6 3
3 6 5

Answer is 6.
*/