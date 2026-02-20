#include <bits/stdc++.h>
using namespace std;

int sumBitDifferences(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    long long n = arr.size();
    long long total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int x = arr[i] ^ arr[j];

            int count = 0;

            while (x > 0) {
               if(x&1){count++;}
               n=n>>1;
            }

            total = (total + count) % MOD;
        }
    }

    return total;
}

int main() {
    vector<int> arr = {1, 3, 5};
    cout << sumBitDifferences(arr);
}