#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);  // n empty arrays
    int lastAnswer = 0;
    vector<int> result;

    for (auto q : queries) {
        int type = q[0];
        int x = q[1];
        int y = q[2];

        int idx = (x ^ lastAnswer) % n;  

        if (type == 1) {
            arr[idx].push_back(y);  
        } 
        else if (type == 2) {
            int size = arr[idx].size();
            lastAnswer = arr[idx][y % size];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> result = dynamicArray(n, queries);

    for (int val : result) cout << val << endl;

    return 0;
}
