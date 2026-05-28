#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    long long min_n = atoll(argv[1]);
    long long max_n = atoll(argv[2]);
    int type = 0;
    if (argc > 3) {
        type = atoi(argv[3]);
    }
    long long n = rnd.next(min_n, max_n);
    if (type == 1) {
        n = (n / 60) * 60;
        if (n < min_n) n += 60;
        if (n > max_n) n -= 60;
    }
    println(n);

    return 0;
}