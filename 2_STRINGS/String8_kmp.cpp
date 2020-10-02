#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a; 
    int len = a.size();
    int k[len];
    int i = 1; 
    int j = 0;
    k[0] = 0;
    while(i < len)
    {
        if(a[i] == a[j])
        {
            k[i] = j+1;
            i++;
            j++;
        }
        else if(j == 0)
        {
            k[i] = 0;
            i++;
        }
        else
        {
            j = k[j-1];
        }
    }
    for(int i = 0; i < len; i++)
        cout << k[i] << " ";
    cout << endl;
}