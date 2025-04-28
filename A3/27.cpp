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
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            cin >> grid[i][j];

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (grid[i][j] == '*' || grid[max(0, i - 1)][j] == '*')
                cout << "* ";
            else
                cout << "- ";
        }
        cout << '\n';
    }
    
}