#include <cstdio>
#include <vector>
#define MAX 16

using namespace std;

int N, M, max_level;
vector<vector<int>> adj(MAX);
vector<vector<int>> ancestors(MAX);
vector<int> levels(MAX, 0);

void make_tree(int root) {
    for(int i=0; i<adj[root].size(); ++i) {
        int child = adj[root][i];
        if (root != 1 && ancestors[root][0] == child)
            continue;
        ancestors[child].push_back(root);
        levels[child] = levels[root] + 1;
        max_level = max(levels[child], max_level);
        make_tree(child);
    }
}

void fill_ancestors() {
    int k = 1;
    ancestors[1].push_back(0);
    while((1<<k) < max_level) {
        for(int i=1; i<=N; ++i) {
            if (ancestors[i][k-1] <= 0)
                ancestors[i].push_back(0);
            else
                ancestors[i].push_back(ancestors[ancestors[i][k-1]][k-1]);
        }
        k += 1;
    }
}

int find_lca(int a, int b) {
    int diff = levels[a] - levels[b], k = 0;
    while (diff > 0) {
        if(diff % 2)
            a = ancestors[a][k];
        diff /= 2;
        k++;
    }

    if (a == b)
        return a;

    // find_lca
    int max_k = 0;
    while ((1<<max_k) < max_level) {
        max_k += 1;
    }
    for(int k=max_k-1; k>=0; k--) {
        if(ancestors[a][k] != 0 && ancestors[a][k] != ancestors[b][k]) {
            a = ancestors[a][k];
            b = ancestors[b][k];
        }
    }

    return ancestors[a][0];
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // make_tree
    levels[1] = 1;
    make_tree(1);
    fill_ancestors();

    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        // a가 b보다 아래에 있도록 swap
        if(levels[a] < levels[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        printf("%d\n", find_lca(a, b));
    }
    return 0;
}
