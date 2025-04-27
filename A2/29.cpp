#include <iostream>
#include <vector>

using namespace std;

/*
I'm too lazy to code
for (...) every single file Lol
*/

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

    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= i;j++)
            if (i == 1 || j == 1 || i == n || j == i)
                cout << "0 ";
            else
                cout << "1 "; 
        cout << '\n';
    }
}