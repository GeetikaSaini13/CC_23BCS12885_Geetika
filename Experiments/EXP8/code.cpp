#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxEle = 0;

            // try all partitions of size <= k
            for (int j = i; j > 0 && j >= i - k + 1; j--) {
                maxEle = max(maxEle, arr[j - 1]);
                dp[i] = max(dp[i], dp[j - 1] + maxEle * (i - j + 1));
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << sol.maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}