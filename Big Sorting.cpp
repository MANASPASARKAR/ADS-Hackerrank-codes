#include <bits/stdc++.h>
using namespace std;

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](const string &a, const string &b) {
        if (a.size() == b.size())
            return a < b;           // lexicographic compare if same length
        return a.size() < b.size(); // shorter number is smaller
    });
    return unsorted;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);
    for (int i = 0; i < n; i++) getline(cin, unsorted[i]);

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1)
            fout << "\n";
    }
    fout << "\n";
    fout.close();
    return 0;
}
