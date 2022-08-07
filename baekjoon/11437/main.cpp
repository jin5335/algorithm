#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>

using namespace std;

void make_tree(
        int root,
        vector<int>& parents,
        vector<int>& levels,
        vector<vector<int>>& adj
){
    for(int i=0; i<adj[root].size(); ++i) {
        if (levels[adj[root][i]] != 0)
            continue;
        parents[adj[root][i]] = root;
        levels[adj[root][i]] = levels[root] + 1;
        make_tree(adj[root][i], parents, levels,adj);
    }
}

int lca(int a, int b, vector<int>& parents, vector<int>& levels){
    while (levels[a] != levels[b]) {
        a = parents[a];
    }

    while (a != b) {
        a = parents[a];
        b = parents[b];
    }

    return a;
}

int main() {
    int N, M;
    scanf("%d", &N);
    vector<vector<int>> adj(N+1);
    for (int i=0; i<N-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parents(N+1, 0), levels(N+1, 0);
    parents[1] = -1, levels[1] = 1;
    make_tree(1, parents, levels, adj);

    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (levels[a] < levels[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        printf("%d\n", lca(a, b, parents, levels));
    }
    return 0;
}
