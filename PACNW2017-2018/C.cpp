#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define nl '\n'

ll sum_from_a_to_b(ll a, ll b) {
    ll sum_to_a = (a * (a + 1)) / 2;
    ll sum_to_b = (b * (b + 1)) / 2;
    return sum_to_b - sum_to_a;
}

ll fn(ll b) {
    ll top = (ll) ceil(sqrt(b));
    ll sum = 0;
    if (b == 1) {
        return 1;
    }

    for (ll i = 1; i <= top; i++) {
        ll x = b / i;
        sum += (x * i);

        ll firstAmount = top*i+1;
        while (firstAmount % i != 0) {
            firstAmount++;
        }

        ll lastAmount = b - (b % i);

        sum += sum_from_a_to_b(firstAmount/i, lastAmount/i);
    }
    return sum;
}

int main() {
    ll a, b;
    cin >> a >> b;

    cout << fn(b) - fn(a-1) << nl;

    return 0;
}
