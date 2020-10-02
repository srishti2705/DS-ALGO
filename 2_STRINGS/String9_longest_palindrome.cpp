/*


*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define Loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define loop(n) for(int i = 0; i < n; i++)
#define vin vector<int>
#define w(t) int tc; cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define tab(x) for(int tab = 0; tab < x; tab++) cout << "   ";

int arr[5000000];

string solve_palindrome(string str){
    string s1 = str;
    reverse(s1.begin(), s1.end());
    s1 = str+"#"+s1;
    int a;
    int c = 0;
    int len = s1.length();
    for(int i = 1; i < len; i++){
        while(s1[i] != s1[c] and c != 0){
            c = arr[c-1];
        }
        if(s1[i] == s1[c]) c++;
        arr[i] = c;
    }
    return str.substr(0, c);

}

string get(string str){
    string a = solve_palindrome(str);
    reverse(str.begin(), str.end());
    string b = solve_palindrome(str);
    return a.length() >= b.length() ? a : b;
}

int32_t main(){
    fastio;
    string str, a1;
    int a, len;
    w(t){
        cin >> str;
        len = str.length();
        a = 0;
        loop(len){
            if(str[i] == str[len-i-1]) a++;
            else break;
        }  
        if(a > len/2) cout << str << endl;
        else{
            a1 = str.substr(0, a);
            cout << a1;
            cout << get(str.substr(a, len-2*a));// << endl;
            reverse(a1.begin(), a1.end());
            cout << a1 << endl;
        }
    }

}