#include <bits/stdc++.h>
using namespace std;

vector<int> calc_ps(string pattern,int p_len) {
    vector<int> lps(p_len);
    lps[0]=0;
    int length = 0;
    int i = 1;
    while (i < p_len) {
        if (pattern[i] == pattern[length]){
            lps[i] = length + 1;
            length++; i++;
        }
        else {
            if (length != 0)
                length = lps[length - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp (string str, string pattern,
            int p_len,int s_len,int& foundAt) {

    vector<int> lps = calc_ps(pattern,p_len);

    int i = 0, j = 0;

    while (i < s_len) {
        if (str[i] == pattern[j]){
            i++; j++;
        }
        else {
            if (j != 0) 
                j = lps[j - 1];
            else 
                i++;
        }

        if (j == p_len) {
            foundAt = i-p_len;
            return true;
        }
    }
    return false;
}

int main() {
    string str="ACBAACBACA";
    string pattern="ACBAC";
    int p_len = pattern.length();
    int s_len = str.length();
    int foundAt;
    bool isFound = kmp(str, pattern,p_len,s_len,foundAt);
    if(isFound){
        cout<<"Found at index "<<foundAt<<" to "<<foundAt+p_len-1;
    }
    else{
        cout<<"Not Found";
    }

    return 0;
}