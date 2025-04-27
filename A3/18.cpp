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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, n;
    cin >> l >> n;
    vector<int> pf;
    pf.push_back(0);
    for (int i = 1;i <= 100;i++)
        pf.push_back(i * i + pf.back());
    int k = lower_bound(pf.begin(), pf.end(), n) - pf.begin();
    cout << l - k + (pf[k] != n) << '\n';
}