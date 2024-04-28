#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
char* x;
char* y;


int opt(int i, int j){
    if(i == m){
        return 2 * (n  - j);
    }
    else if(j == n){
        return 2 * (m - i);
    }
    else{
        int penalty;
        if(x[i] == y[j]){
            penalty = 0;
        }
        else{
            penalty = 1;
        }
        return min({opt(i + 1, j + 1) + penalty, opt(i + 1, j) + 2, opt(i, j + 1) + 2});
    }

}

int optDP() {
    // Create a 2D array to store computed values
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize the base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][n] = 2 * (m - i);
    }
    for (int j = 0; j <= n; ++j) {
        dp[m][j] = 2 * (n - j);
    }

    // Bottom-up dynamic programming
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int penalty;
            if (x[i] == y[j]) {
                penalty = 0;
            } else {
                penalty = 1;
            }
            dp[i][j] = min({dp[i + 1][j + 1] + penalty, dp[i + 1][j] + 2, dp[i][j + 1] + 2});
        }
    }

    // Return the optimal alignment score
    return dp[0][0];
}



int main(){
    m = 6;
    n = 7;

    x = new char[m] {'C', 'A', 'C', 'A', 'T', 'A'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T', 'A', 'G'};

    int result = opt(0, 0);

    cout << result;

    result = optDP();

    cout << result;

    delete[] x;
    delete[] y;


    return 0;
}