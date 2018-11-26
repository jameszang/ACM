#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define nl '\n'

long long fib(int n) {
    static map<int, long long> data = { {1, 1} , {2, 1} };

    auto it = data.find(n);
    if (it != data.end()) {
        return it->second;
    } else {
        long long val = fib(n-1) + fib(n-2);
        data[n] = val;
        return val;
    }
}

long long log2(long long n) {
    return floor(log(n) / log(2));
}

int isBad(long long n) {
    return (n ^ (n*2) ^ (n*3) == 0) ? 1 : 0;
}
/*
long long f(long long n) {
    if (n <= 2) {
        return n;
    }
    int j = n-pow(2,log2(n));
    //cout<<fib(log2(n)+1)<<nl;
    if(n-pow(2,log2(n))-pow(2,log2(n)-1)>0){
        j=n-pow(2,log2(n))-pow(2,log2(n)-1);
    }
cout<<"j: "<<j<<nl;
    return fib(log2(n) +1) + f(j)+1;
}
*/
int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long l, r;
        cin >> l >> r;
        
        long long ans = 0;
        long long logR = log2(r);
        long long logL = log2(l) + 1;
        for (int i = logR; i >= logL; i--) {
            ans += fib(i);
        }
        for (int i = pow(2, logR); i < r; i++) {
            ans += isBad(i);
        }
        cout << ((r - l + 1) - ans) << nl;
        //cout <<r<<" "<<"s: "<< f(r) << nl;
    }
    return 0;
}
