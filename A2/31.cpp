#include <iostream>
#include <vector>

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

bool match(char a, char b){
    if (a == 'A')
        return b == 'T';
    if (a == 'T')
        return b == 'A';
    if (a == 'C')
        return b == 'G';
    return b == 'C'; // case a == 'G';
}

int main()
{
    // ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    char dna[2][n];
    for (int i = 0;i < 2;i++)
        for (int j = 0;j < n;j++)
            cin >> dna[i][j];

    int q;
    cin >> q;
    while (q--){
        int t, idx;
        char c;
        cin >> t >> idx >> c;
        dna[t - 1][idx] = c;
    }

    for (int i = 0;i < 2;i++){
        for (int j = 0;j < n;j++)
            cout << dna[i][j] << ' ';
        cout << '\n';
    }

    int ans = 0;
    for (int i = 0;i < n;i++)
        ans += !match(dna[0][i], dna[1][i]);
    cout << ans << '\n';
}