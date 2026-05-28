#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int MAXA = 1e9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int type = opt<int>("type");

    int n, k;

    if (type == 0) {
        n = rnd.next(1, 1000);
        k = rnd.next(1, 1000);
    }

    else if (type == 1) {
        n = rnd.next(100000, 1000000);
        k = rnd.next(1, 1000000);
    }

    else if (type == 2) {
        n = rnd.next(5000000, 8000000);
        k = rnd.next(1, 1000000);
    }

    else {
        n = rnd.next(5000000, 8000000);

        vector<int> specialK = {
            2, 3, 5, 7,
            64, 128, 256,
            999983,
            1000000
        };

        k = specialK[rnd.next(0, (int)specialK.size() - 1)];
    }

    cout << n << ' ' << k << '\n';

    if (type != 3) {

        for (int i = 1; i <= n; i++) {

            int x = rnd.next(1, MAXA);

            cout << x;

            if (i != n) cout << ' ';
        }
    }

    else {
        int base = rnd.next(1, k);

        for (int i = 1; i <= n; i++) {

            int t = rnd.next(0, 1000000);

            int x = 1LL * t * k + base;

            x %= MAXA;

            if (x == 0) x = k;

            cout << x;

            if (i != n) cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}