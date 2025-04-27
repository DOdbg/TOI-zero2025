#include <iostream>
#include <vector>
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

    int l, n, mx = 0;
    cin >> l >> n;
    array<int, 3> ani = {0, 0, 0}, point = {0, 0, 0};
    cin >> ani[0] >> ani[1] >> ani[2];

    for (int i = 0;i < n;i++){
        int d, p;
        cin >> d >> p;
        for (int j = 0;j < 3;j++)
            if (d % ani[j] == 0){
                point[j] += p;
                mx = max(mx, point[j]);
            }               
    }
    const string name[] = {"Rabbit", "Monkey", "Frog"};
    for (int i = 0;i < 3;i++)
        if (point[i] == mx)
            cout << name[i] << ' ' << mx << '\n';   
}