#include <iostream>
#include <vector>

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

    int n, m;
    cin >> n >> m;
    vector<string> grid(n), ans(n);
    for (auto &s:grid)
        cin >> s;

    auto calc = [&](char a, char b) -> char {
        if (a == '-') // -, - => - || -, x => x
            return b;
        if (a == '+' && b == 'x')
            return '*';
        return '+'; // case +, - => + 
    };

    for (int i = 0;i < n;i++){
        string s;
        cin >> s;
        for (int j = 0;j < m;j++)
            ans[i] += calc(grid[i][j], s[j]);
    }
    for (auto s:ans)
        cout << s << '\n';
}