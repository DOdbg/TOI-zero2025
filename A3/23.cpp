/*
I use normal vector and got Execution killed (could be triggered by violating memory limits)
LMAO I really love this
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

class VECTOR {
private:
    int* v = nullptr;
    int sz = 0;
    int cap = 0;
public:
    VECTOR() : sz(0) {}
    ~VECTOR(){
        free(v);
    }
    void pus(int x){
        if (sz == 0){
            cap = 2;
            v = (int*)malloc(cap * sizeof(int));
        } 
        else if (sz >= cap){
            cap *= 2;
            v = (int*)realloc(v, cap * sizeof(int));
        }
        v[sz++] = x;
    }
    int size() const {
        return this->sz;
    }
    int operator[](int idx) const {
        return this->v[idx];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int MX = 3 * b;
    bool *is_prime = new bool[MX + 1];
    for (int i = 0;i <= MX;i++)
        is_prime[i] = true;
    VECTOR *prime = new VECTOR();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2;i <= MX;i++){
        if (!is_prime[i]) continue;
        if (a <= i && i <= MX)
            prime->pus(i);
        for (int j = 2 * i;j <= MX;j+=i)
            is_prime[j] = false;
    }

    delete is_prime;

    int** dp = new int*[4];
    for (int i = 0;i < 4;i++)
        dp[i] = new int[MX + 1];
    dp[0][0] = 1ll;
    for (int i = a;i <= b;i++)
        for (int l = 0;l < 3;l++)
            for (int k = MX;k >= i;k--)
                dp[l + 1][k] += dp[l][k - i];

    ll ans = 0ll;
    for (int i = 0;i < prime->size();i++)
        ans += dp[3][(*prime)[i]];
    delete dp;
    delete prime;
    cout << ans << '\n';
}