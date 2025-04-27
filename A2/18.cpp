#include <iostream>
#include <vector>
#include <map>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, string> mp = {{'R', "Red"}, {'G', "Green"}, {'B', "Blue"}};
    char c;
    int n;
    cin >> c >> n;
    string loop = "RGB";
    while (loop[0] != c)
        rotate(loop.begin(), loop.begin() + 1, loop.end());
    for (int i = 0;i < n;i++)
        cout << mp[loop[i % 3]] << ' ';
    cout << '\n';
}