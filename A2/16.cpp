#include <iostream>
#include <vector>
#include <cmath>

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

    char A, B;
    string a, b;
    cin >> A >> a >> B >> b;

    if (A == B && a == b){
        cout << int(1e6) << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 4;i >= 0;i--)
        if (a[i] == b[i])
            cnt++;
        else
            break;
    if (cnt == 5){
        cout << 1e5 << '\n';
        return 0;
    }
    cnt = min(3, cnt);
    if (cnt <= 1){
        if (A == B) 
            cout << "20\n";
        else
            cout << "0\n";
        return 0;
    }
    cout << (2000 / ((cnt == 2)?2:1)) / ((A == B)?1:10) << '\n';
}