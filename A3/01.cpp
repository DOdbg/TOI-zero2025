#include <iostream>
#include <vector>
#include <array>

using namespace std;

template<typename T> istream &operator >> (istream &in, vector<T> &v){
    for (auto &e:v)
        in >> e;
    return in;
}

template<typename T> ostream &operator << (ostream &out, vector<T> &v){
    for (auto &e:v)
        out << e << ' ';
    return out;
}

int ans = 0;

int dfs(vector<vector<pair<int, int>>> adj, int u){
    int mx = 0, cnt = 0;
    array<int, 2> child = {0, 0};
    for (auto [t, v]:adj[u]){
        if (t == 1)
            child[cnt++] = v;
        else
            child[cnt++] = dfs(adj, v);
    }
    ans += abs(child[0] - child[1]);
    return 2 * max(child[0], child[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1;i <= n;i++){
        int a, wa, b, wb;
        cin >> a >> wa >> b >> wb;
        adj[i].push_back({a, wa});
        adj[i].push_back({b, wb});
    }
    dfs(adj, 1);
    cout << ans << '\n';
}
