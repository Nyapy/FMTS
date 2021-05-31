#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int row, col;
    cin >> row >> col;
    string s = "";
    for(int i = 0; i < row; i++)
    {
        string sub;
        cin >> sub;
        s += sub;
    }
    int n;
    cin >> n;
    string temp;
    cin >> temp;
    for(int i = 0; i <= row * col - n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(s[i + j] == temp[j]) cnt++;
        if(cnt == n)
            cout << "(" << (i / col) << "," << (i % col) << ")\n";
    }
}