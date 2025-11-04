#include <bits/stdc++.h>
// #include <string.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    int hour = stoi(s.substr(0,2));
    string m = s.substr(8,2);
    
    if((m == "AM") && (hour == 12)){
        hour = 0;
    }
    
    if((m=="PM") && (hour!=12)){
        hour += 12;
    }
    
    stringstream result;
    result << setw(2) << setfill('0') << hour << s.substr(2, 6);
    return result.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
