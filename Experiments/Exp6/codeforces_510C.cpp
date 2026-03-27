#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    // Graph: adjacency list
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);

    // Step 1: Build graph
    for (int i = 0; i < n - 1; i++) {
        string s = names[i];
        string t = names[i + 1];

        int len = min(s.size(), t.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                int u = s[j] - 'a';
                int v = t[j] - 'a';

                adj[u].push_back(v);
                indegree[v]++;
                found = true;
                break;
            }
        }

        // Edge case: prefix issue
        if (!found && s.size() > t.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // Step 2: Topological sort (Kahn's Algorithm)
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    string result = "";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        result += (char)(u + 'a');

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Step 3: Check cycle
    if (result.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}