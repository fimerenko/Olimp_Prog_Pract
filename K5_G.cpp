#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll v, ll cnt1, ll cnt2, ll x, ll y) {
    // A: numbers not divisible by x and not by y
    // B: divisible by x, but not by y
    // C: divisible by y, but not by x
    ll xy = x * y; // x and y are prime, but still use product
    ll A = v - v / x - v / y + v / xy;
    ll B = v / x - v / xy;
    ll C = v / y - v / xy;

    if (A + C < cnt1) return false; // not enough numbers for first set
    if (A + B < cnt2) return false; // not enough numbers for second set

    // We need to take numbers from A to cover shortages in each set.
    ll needA = max(0LL, cnt1 - C) + max(0LL, cnt2 - B);
    return needA <= A;
}

int main() {
    ll cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    ll l = cnt1 + cnt2; // minimum possible v
    ll r = 2 * (cnt1 + cnt2) * y + 10; // safe upper bound

    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid, cnt1, cnt2, x, y))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
    return 0;
}
