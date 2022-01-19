#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
void toggle(char* s);

int main()
{
    int n;
    char str[100];
    gets(str);
    toggle(str);
    cout<<str;
    return 0;
}
void toggle(char* str){
    for(int i=0; i<strlen(str);i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] = str[i]+32;
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i] = str[i]-32;
        }
    }
}