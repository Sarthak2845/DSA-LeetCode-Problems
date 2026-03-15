#include <bits/stdc++.h>
using namespace std;

class Fancy {
    vector<long long> arr;
    vector<long long> mulArr; // cumulative multiplier when each element was appended
    vector<long long> addArr; // cumulative addition when each element was appended
    long long cumMul = 1;
    long long cumAdd = 0;
    const long long MOD = 1e9 + 7;

    // Modular exponentiation for modular inverse
    long long modInverse(long long x) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        arr.push_back(val);
        mulArr.push_back(cumMul);
        addArr.push_back(cumAdd);
    }

    void addAll(int inc) {
        cumAdd = (cumAdd + inc) % MOD;
    }

    void multAll(int m) {
        cumMul = (cumMul * m) % MOD;
        cumAdd = (cumAdd * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;

        long long val = arr[idx];
        long long prevMul = mulArr[idx];
        long long prevAdd = addArr[idx];

        long long inv = modInverse(prevMul);
        long long currVal = (val * (cumMul * inv % MOD)) % MOD;
        currVal = (currVal + (cumAdd - prevAdd * (cumMul * inv % MOD) % MOD + MOD) % MOD) % MOD;

        return (int)currVal;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */