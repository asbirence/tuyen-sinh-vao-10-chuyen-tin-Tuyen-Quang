#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int64 SMALL = (int64)1e7;
const int64 BIG   = (int64)1e15;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int type = opt<int>("type");

    int64 a, b;

    if (type == 0) {
        a = rnd.next(10LL, SMALL);
        b = rnd.next(a, SMALL);
    }

    else if (type == 1) {
        vector<pair<int64,int64>> tc = {
            {10, 10},
            {10, 90},
            {10, 100},
            {10, 23},
            {98, 102},
            {9999990, 10000000},
            {1234567, 1234999}
        };

        auto p = tc[rnd.next(0, (int)tc.size() - 1)];
        a = p.first;
        b = p.second;
    }

    else if (type == 2) {
        a = rnd.next(0LL, BIG - (int64)1e12);
        int64 len = rnd.next((int64)1e11, (int64)1e12);
        b = min(BIG, a + len);
    }
    else if (type == 3) {
        vector<pair<int64,int64>> tc = {
            {0, BIG},
            {BIG - 1000, BIG},
            {999999999999990LL, BIG},
            {123456789012345LL, 123456789099999LL}
        };

        auto p = tc[rnd.next(0, (int)tc.size() - 1)];
        a = p.first;
        b = p.second;
    }

    else if (type == 4) {
        a = rnd.next(0LL, SMALL);
        b = a;
    }

    else {
        a = rnd.next(0LL, BIG);
        b = a;
    }

    cout << a << ' ' << b << '\n';

    return 0;
}