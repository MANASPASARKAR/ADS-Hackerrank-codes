#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    
    int length = arr.size();
    int pos_c = 0, neg_c = 0, zero_c = 0;
    
    for(auto it = arr.begin(); it != arr.end(); ++it){
        
        if(*it < 0){
            neg_c++;    
        }else if(*it > 0){
            pos_c++;
        }else{
            zero_c++;
        }
        
    } 
    
    double pos_ratio = (double)pos_c/length;
    double neg_ratio = (double)neg_c/length;
    double zero_ratio = (double)zero_c/length;
    
    // cout<< fixed << setprecision(6) << pos_ratio << endl;
    printf("%.6f\n",pos_ratio); 
    printf("%.6f\n",neg_ratio); 
    printf("%.6f\n",zero_ratio); 
    // cout<< fixed << setprecision(6) << zero_ratio << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
