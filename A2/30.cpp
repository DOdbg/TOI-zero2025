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

    int n = 5;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> grid[i][j];

    auto check = [&](int row, int col) -> bool {
        int cnt_row = 0, cnt_col = 0;
        for (int i = 0;i < n;i++){
            cnt_row += grid[row][i];
            cnt_col += grid[i][col];;
        }
        return (cnt_row & 1) && (cnt_col & 1);
    };

    for (int i = 0;i < n;i++){
        int row = 0, col = 0;
        for (int j = 0;j < n;j++){
            if (check(i, j)){
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    cout << "-1 -1\n";
}