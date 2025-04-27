#include <iostream>
#include <vector>
#include <map>
#include <array>

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

    map<char, array<int, 3>> mp;
    mp['H'] = {5, 0, 0}; mp['O'] = {3, 0, 0}; mp['J'] = {2, 0, 0};
    mp['R'] = {12, 18, 25}; mp['T'] = {15, 20, 30}; mp['M'] = {10, 15, 20};
    char T1, T2;
    int a, b, c;
    cin >> T1 >> a >> T2 >> b >> c;
    cout << (a * mp[T1][0]) + (c * mp[T2][b - 1]) << '\n';
}