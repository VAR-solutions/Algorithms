#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string a = s.substr(0,1);
    int t = stoi(a);
    string b = s.substr(8,9);
    string c = s.substr(2,7);
    if(b=="AM"&& t==12) a="00";
    else if(b=="PM"&& t!=12) {t=t+12;
                              a= to_string(t);}
    string r= a + c;
    return r;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    //fout.close();

    return 0;
}
