#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXT = 10000000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    /*
        type:
        0 -> small
        1 -> ai = bi
        2 -> full random
        3 -> full overlap
    */

    int type = opt<int>("type");

    int n, k;

    if (type == 0) {
        n = rnd.next(1, 1000);
        k = rnd.next(1, 1000);
    }
    else {
        n = rnd.next(50000, 100000);
        k = rnd.next(50000, 100000);
    }

    cout << n << ' ' << k << '\n';

    vector<pair<int,int>> segs;
    segs.reserve(n);

    if (type == 0) {

        for (int i = 1; i <= n; i++) {

            int a = rnd.next(1, 10000);
            int b = rnd.next(a, 10000);

            cout << a << ' ' << b << '\n';

            segs.push_back({a, b});
        }
    }

    else if (type == 1) {

        for (int i = 1; i <= n; i++) {

            int x = rnd.next(1, MAXT);

            cout << x << ' ' << x << '\n';

            segs.push_back({x, x});
        }
    }

    else if (type == 2) {

        for (int i = 1; i <= n; i++) {

            int a = rnd.next(1, MAXT);

            int len = rnd.next(0, 100000);

            int b = min(MAXT, a + len);

            cout << a << ' ' << b << '\n';

            segs.push_back({a, b});
        }
    }

    else {

        int center = rnd.next(100000, MAXT - 100000);

        for (int i = 1; i <= n; i++) {

            int l = max(1, center - rnd.next(0, 50000));
            int r = min(MAXT, center + rnd.next(0, 50000));

            cout << l << ' ' << r << '\n';

            segs.push_back({l, r});
        }
    }

    for (int i = 1; i <= k; i++) {

        int c;

        if (rnd.next(0, 99) < 80) {

            auto [l, r] = segs[rnd.next(0, n - 1)];

            c = rnd.next(l, r);
        }
        else {

            c = rnd.next(1, MAXT);
        }

        cout << c;

        if (i != k) cout << ' ';
    }

    cout << '\n';

    return 0;
}