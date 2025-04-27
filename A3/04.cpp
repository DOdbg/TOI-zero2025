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

    int n;
    cin >> n;
    vector<int> pointx(n), pointy(n);
    cin >> pointx >> pointy;

    
}