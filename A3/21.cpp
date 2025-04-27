#include <iostream>
#include <vector>
#include <algorithm>

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

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> runner(n);
    cin >> runner;
    ll mn = *min_element(runner.begin(), runner.end()), t = mn * k;
    int ans = count_if(runner.begin(), runner.end(), [&](ll a){
        return t <= a * (k - 1ll);
    });
    cout << n - ans << '\n';
}