#include <iostream>
#include <vector>

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, now;
    cin >> n >> now;
    vector<int> pa(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (int i = 1;i <= n;i++){
        cin >> pa[i];
        if (pa[i] == 0)
            pa[i] = i;
    }

    int ans = 0;
    for (int i = 1;i <= n && !vis[now];i++){
        ans++;
        vis[now] = true;
        now = pa[now];
    }
    cout << ans << '\n';
}