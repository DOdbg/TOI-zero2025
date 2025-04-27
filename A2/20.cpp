#include <iostream>
#include <vector>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> pa(n);
    vector<bool> vis(n + 1, false);
    cin >> pa;
    pa.insert(pa.begin(), 0);

    int ans = 0;
    for (int i = 1;i <= n;i++){
        if (vis[i]) continue;
        int now = pa[i], cnt = 1;
        while (now != i){
            vis[now] = true;
            cnt++;
            now = pa[now];
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}