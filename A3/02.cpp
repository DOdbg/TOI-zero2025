#include <iostream>
#include <vector>
#include <cmath>

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

    int n, sq;
    cin >> n;
    sq = int(sqrt(n));
    cout << 2 * sq - ((n % 2) == (sq % 2)) - (sq * sq == n) << '\n';
}