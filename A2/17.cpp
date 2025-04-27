#include <iostream>
#include <vector>
#include <map>

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

    map<char, map<char, int>> mp;
    mp['S'].insert({'R', 60}); mp['S'].insert({'T', 80});
    mp['M'].insert({'R', 80}); mp['M'].insert({'T', 100});
    mp['L'].insert({'R', 100}); mp['L'].insert({'T', 120});
    char a, b, c;
    int n;
    cin >> a >> b >> c;
    if (c == 'N'){
        cout << mp[a][b] << '\n';
        return 0;
    }
    cin >> n;
    cout << mp[a][b] + (n * ((c == 'P')?15:10)) << '\n';
}