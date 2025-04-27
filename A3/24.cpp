#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> ostream &operator << (ostream &out, pair<T, T> p){
    return out << '[' << p.first << ", " << p.second << "] ";
}

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

    int n, l;
    cin >> n >> l;
    
    struct A{
        int l, r;
        bool operator < (const A &o) const {
            if (o.r != r)
                return r < o.r;
            return l < o.l;
        }
    };
    vector<A> v(n);
    for (auto &[l, r]:v)
        cin >> l >> r;
    sort(v.begin(), v.end());
    int ans = 0, idx = -1;
    for (auto [l, r]:v)
        if (l > idx){
            ans++;
            idx = r;
        }
    cout << ans << '\n';
}