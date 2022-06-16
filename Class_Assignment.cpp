#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
//https://github.com/apaarkamal/launchpad_summer_2k19/blob/master/18.%20Doubt%20class%203/class%20assignment.cpp
//Class Assignment
int32_t main()
{
    int t, z = 1; cin >> t; while (t--) {
        int n;
        cin >> n;
        // 0 means a , 1 means b
        int dp[n + 1][2];
        dp[1][0] = 1; //number with 1 digit of length 1
        dp[1][1] = 1; //number with 1 digit of length 1
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
        cout << "#" << z << " : ";
        z++;
        cout << dp[n][0] + dp[n][1] << '\n' ;
    }
}