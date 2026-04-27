#include <bits/stdc++.h>
using namespace std;

int BIT[100];  
int n = 5;


void update(int i, int val) {
    while (i <= n) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}


int main() {
    int arr[] = {0, 1, 2, 3, 4, 5}; 

    
    for (int i = 1; i <= n; i++) {
        update(i, arr[i]);
    }

    cout << query(3)    << endl;      
    cout << query(5) << endl;      

    return 0;
}