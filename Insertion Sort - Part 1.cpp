#include <bits/stdc++.h>
using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int key = arr[n - 1];  // the element to be inserted
    int i = n - 2;         // start checking from second last element

    // shift elements to the right until correct position found
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];  // shift element right
        for (int j = 0; j < n; j++) cout << arr[j] << " ";
        cout << "\n";
        i--;
    }

    arr[i + 1] = key;  // insert the key
    for (int j = 0; j < n; j++) cout << arr[j] << " ";
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    insertionSort1(n, arr);
    return 0;
}
