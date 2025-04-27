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

    int n, q;
    cin >> n >> q;
    vector<int> v(n), mx(n + 1, 0), ans(n + 1, 0);
    cin >> v;
    v.insert(v.begin(), 0);
    for (int i = 1;i <= n;i++){
        mx[i] = max(mx[i - 1], v[i]);
        if (mx[i] == v[i])
            ans[i] = mx[i - 1] == mx[i];
        else
            ans[i] = mx[i] + 1 - v[i];
    }
    while (q--){
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}