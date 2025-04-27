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

    int w, l, a, b;
    cin >> w >> l >> a >> b;
    int ans = 1e9;
    for (int i = a;i <= b && ans > 0;i++)
        ans = min(ans, (w % i) * (l % i));
    cout << ans << '\n';
}