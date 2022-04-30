#include<iostream>
#include<string.h>
using namespace std;

int findStr(char s[], char t[])
{
    int count = 0;
    int len_s=strlen(s);
    int len_t=strlen(t);
    // char z[100000];
    int s_ptr = 0, t_ptr = 0;
    int flag;
    while(true){
        if(t_ptr==len_t) break;
        flag = 0;// to see if there is any match
        for (s_ptr = 0; s_ptr < len_s; s_ptr++)
        {
            if(t_ptr==len_t) break;
            if(s[s_ptr]==t[t_ptr]){
                flag=1;// there is partly match 
                t_ptr++;
            }
        }
        if (flag) count++;
        else break;

    }
    return (t_ptr==len_t)?  count: -1;
}
int main(){
    int n;
    char s[100000], t[100000];
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> s >> t;
        cout << findStr(s, t) << endl;
    }

    return 0;
}