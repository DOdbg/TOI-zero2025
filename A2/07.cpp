#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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

const int N = 303;

vector<vector<int>> adj;
vector<int> pa, parent, have;

void init(int n){
    adj.assign(n + 1, vector<int>());
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
    parent.resize(n + 1);
    have.resize(n + 1);
}

int f(int i){
    if (pa[i] == i) return i;
    return pa[i] = f(pa[i]);
}

bool untie(int u, int v){
    int fu = f(u), fv = f(v);
    if (fu == fv) return false;
    pa[fv] = fu;
    return true;
}

pair<int, int> dfs(int u, int k){
    // cout << "u, k : " << u << ' ' << k << '\n'; 
    int cnt = have[u];
    for (auto v:adj[u]){
        pair<int, int> c = dfs(v, k);
        if (c.first != -1) return c;
        cnt += c.second;
    }
    if (cnt == k) return {u, cnt};
    return {-1, cnt};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    init(n);

    vector<int> l(n + 1), r(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> l[i] >> r[i];
        
    for (int i = 1;i <= n;i++){
        pa[i] = i;
        for (int j = i - 1;j >= 1;j--){
            if (l[j] < l[i] && r[j] > r[i]){
                adj[j].push_back(i);
                untie(j, i);
                break;
            }
        }
    }
        
    vector<int> poi(m), ans;
    for (auto &e:poi){
        cin >> e;
        have[e] = 1;
    }

    int j = 0;
    for (int i = 0;i < m;i = j + 1){
        // cout << "i = " << i << '\n';    
        j = i;
        while (j < m && f(poi[i]) == f(poi[j + 1]))
            j++;
        int op = j - i + 1;
        int u = dfs(f(poi[i]), op).first; // dfs from root
        ans.push_back(u);
    }

    cout << ans.size() << '\n';
    for (auto e:ans)
        cout << e << ' ';
    cout << '\n';
}