#include <iostream>
#include <vector>
#include <functional>

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

using ll = long long;

/*
f(n, l) = number of flower in bar n

f(1, 1) = 1
f(2, 1) = 1 + 1
f(3, 1) = 1 + f(2)
f(4, 1) = 1 * 1 + f(3)
..
f(n) = 1 * 1 + f(n - 1)

f(1, l) = l * (l + 1) / 2
f(2, l) = l * l + l * (l + 1) / 2
f(3, l) = l * l + f(2, l)
...
f(n - 1, l) = l * l + f(n - 2)
f(n, l) = l * l + l * l + f(n - 2)
use math to solve
f(n, l) = (n - 1)(l * l) + l * (l + 1) / 2

p(n, l) = f(1, l) + f(2, l) + ... + f(n, l)
p(n, l) = p(n - 1, l) + f(n, l)
p(n, l) = number of flower in bar 1 -> n
if p(n, l) > number of flower than n - 1 is answer
*/

/*
f(n, l) = l * l + f(n - 1, l)
f(1, l) = l * (l + 1) / 2
*/
ll f(ll n, ll l){
    if (n == 1) 
    return l * (l + 1) / 2;
    return l * l + f(n - 1, l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, n;
    cin >> l >> n;

    ll pf = 0ll, i = 1ll;
    while (pf < n){
        pf += (i - 1ll) * (l * l) + l * (l + 1ll) / 2ll;
        i++;
    }
    cout << i - 1ll << '\n';
}