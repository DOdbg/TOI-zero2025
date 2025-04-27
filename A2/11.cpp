#include <iostream>
#include <vector>
#include <unordered_map>

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

    const int n = 10;
    vector<int> v(n);
    unordered_map<int, bool> mark;
    for (auto &e:v)
        cin >> e;
    for (int i = 0;i < n;i++){
        if (mark.count(v[i])) continue;
        mark[v[i]] = true;
        cout << v[i] << ' ';
    }
    cout << '\n';
}