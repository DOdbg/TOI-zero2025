#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<vector<int>>> rev(n + 1);

    for (int i = 1;i <= m;i++){
        int k, next;
        cin >> k;
        vector<int> in(k);
        for (auto &e:in)
            cin >> e;
        cin >> next;
        for (auto e:in)
            adj[e].push_back(next);
        rev[next].push_back(in);
    }
    vector<bool> vis(n + 1, false);
    int ans = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans++;
        for (auto next:adj[u]){
            bool p = false;
            for (auto pre:rev[next]){
                bool ch = true;
                for (auto e:pre){
                    ch &= vis[e];
                    if (!ch) 
                        break;
                }
                p |= ch;
                if (p)
                    break;
            }
            if (p)
                q.push(next);
        }
    }
    cout << ans << '\n';
}