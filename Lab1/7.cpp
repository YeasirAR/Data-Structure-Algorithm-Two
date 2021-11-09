#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
void conv_to_lower(char* s,int n);
void remove_ws(char * s,int n);

int main()
{
    int n;
    char str[100];
    gets(str);
    int len = strlen(str);
    conv_to_lower(str,len);
    remove_ws(str,len);
    cout<<str;
    return 0;
}
void conv_to_lower(char* s,int n){
    for(int i=0; i<n;i++){
        s[i]=tolower(s[i]);
    }
}
void remove_ws(char * s,int n){
    for(int i=0; i<n; i++){
        if(s[i]==' '){
            for(int j=i; j<n; j++){
                s[j]=s[j+1];
            }
            n--;
        }
    }
}
