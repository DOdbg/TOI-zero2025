#include <iostream>
#include <vector>
#include <algorithm>

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

struct Car {
    int price, val;
    bool operator < (const Car &o) const {
        return val < o.val;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Car> v(n);
    for (auto &[a, b]:v)
        cin >> a >> b;

    sort(v.rbegin(), v.rend());
    int ans = 0, price = 1e9;
    for (int i = 0;i < n;i++){
        if (v[i].price >= price) continue;
        ans++;
        price = v[i].price;
    }
    cout << n - ans << '\n';
}