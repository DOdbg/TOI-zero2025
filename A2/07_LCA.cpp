#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

template<typename T> istream &operator >> (istream &in, vector<T> &v){
    for (auto &e:v)
        in >> e;
    return in;
}
template<typename T> ostream &operator << (ostream &out, vector<T> v){
    for (auto &e:v)
        out << e << ' ';
    return out;
}

const int LOG = 10;

vector<vector<int>> pa;
vector<int> depth;

void init(int n){
    pa.assign(LOG, vector<int>(n + 1));
    depth.resize(n + 1);
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 0;(1 << i) <= d;i++)
        if (d & (1 << i))
            u = pa[i][u];
        
    if (u == v) return u;
        
    for (int i = LOG - 1;i >= 0;i--){
        if (pa[i][u] != pa[i][v]){
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    init(n);
    stack<int> st;
    
    vector<int> l(n + 1), r(n + 1);
    
    for (int i = 1;i <= n;i++){
        cin >> l[i] >> r[i];
        while (!st.empty() && l[i] > r[st.top()])
            st.pop();
        int dep = st.size();
        if (dep == 0) pa[0][i] = 0;
        else pa[0][i] = st.top();
        depth[i] = dep;
        st.push(i);
    }
    
    for (int i = 1;i < LOG;i++)
        for (int j = 1;j <= n;j++)
            pa[i][j] = pa[i - 1][pa[i - 1][j]];
            
    vector<int> poi(m);
    for (auto &e:poi)
        cin >> e;
    
    vector<int> ans;
    int j = 0;
    for (int i = 0;i < m;i = j){
        if (i == m - 1){
            ans.push_back(poi[i]);
            break;
        }
        int u = lca(poi[i], poi[i + 1]);
        j = i + 1;
        while (j < m && lca(u, poi[j]) != 0){
            u = lca(u, poi[j]);
            j++;
        }
        if (u == 0) u = poi[i];
        ans.push_back(u);
    }
    cout << ans.size() << '\n';
    for (auto e:ans)
        cout << e << ' ';
    cout << '\n';
    
    return 0;
}