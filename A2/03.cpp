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

    vector<int> v(n);
    cin >> v;

    v.insert(v.begin(), 0);
    v.push_back(0);

    int ans = 0;
    for (int i = 1;i <= n;i++)
        ans += (v[i - 1] < v[i]) && (v[i] > v[i + 1]);
    cout << ans << '\n';
}