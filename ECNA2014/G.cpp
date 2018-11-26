#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define dt 0.25

int main() {
    for (int tt = 1; tt <= 50; tt++) {
        long long l, s, d, n;
        cin >> l >> s >> d >> n;

        if (l == 0 && l == 0 && d == 0 && n == 0) {
            break;
        }

        vector<pair<long long, long long>> cars(n, pair<long long, long long>(0,0));
        vector<bool> carsIsPassing(n, false);
        for (int i = 0; i < n; i++) {
            double ltemp;
            long long stemp;
            cin >> ltemp >> stemp;

            cars[i] = make_pair(ltemp, stemp);
        }

        double time = 0;
        double pos = (double) l;
        while (pos < d) {
            // update Anna's speed
            long long sum = 0;
            long long count = 0;
            for (int i = 0; i < n; i++) {
                    cerr << "CAR " << i << "  POS: " << cars[i].first << nl;
                if (pos - cars[i].first <= 1) {
                    if (!carsIsPassing[i]) {
                        sum += cars[i].second;
                        count++;
                        carsIsPassing[i] = true;
                    } 
                } else {
                    carsIsPassing[i] = false;
                }
            }
            if (count != 0) {
                sum += s;
                count++;
                s = sum / count;
                    cerr << "SPEED CHANGED!!!!!!@@@@@@@@" << nl;
            }
            
            // check for finish line condition
            if (pos + s*dt > d) {
                break;
            }

            // move Anna's car
            pos += s*dt;
                //cerr << pos << " " << s << " ";

            // move all other cars
            for (int i = 0; i < n; i++) {
                cars[i].first += cars[i].second/4.0;
            }

            // update time
            time += dt;
            cerr << pos << " " << s << " " << time << nl;
        }

        double newdt = 0.00001;
        while (pos < d) {
            // move Anna's car
            pos += s*newdt;
                //cerr << pos << " " << d << nl;
                
            // move all other cars
            /*
            for (int i = 0; i < n; i++) {
                cars[i].first += cars[i].second/100000;
            }
            */

            // update time
            time += newdt;
            //cerr << pos << " " << d << " " << time << nl;
        }

        cout << "Case " << tt << ": Anna reaches her destination at time " << time << " at a speed of " << s << nl;
    }

    return 0;
}
