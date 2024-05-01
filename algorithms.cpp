#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

int m, n;
char* x;
char* y;
long basicOps;

int opt(int i, int j) {
    basicOps += 2;
    if (i == m) {
        basicOps += 4;
        return 2 * (n - j);
    }
    else if (j == n) {
        basicOps += 5;
        return 2 * (m - i);
    }
    else {
        int penalty;
        if (x[i] == y[j]) {
            penalty = 0;
            basicOps += 1;
        }
        else {
            penalty = 1;
        }
        basicOps += 10;
        return min({opt(i + 1, j + 1) + penalty, opt(i + 1, j) + 2, opt(i, j + 1) + 2});
    }
}

int optDP() {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    basicOps += 2;

    for (int i = 0; i <= m; i++) {
        dp[i][n] = 2 * (m - i);
        basicOps += 3;
    }
    for (int j = 0; j <= n; j++) {
        dp[m][j] = 2 * (n - j);
        basicOps += 3;
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int penalty;
            basicOps += 2;
            if (x[i] == y[j]) {
                penalty = 0;
                basicOps++;
            }
            else {
                penalty = 1;
            }
            basicOps += 10;
            dp[i][j] = min({dp[i + 1][j + 1] + penalty, dp[i + 1][j] + 2, dp[i][j + 1] + 2});
        }
        basicOps += 2;
    }

    basicOps++;
    return dp[0][0];
}

int main() {
    cout << fixed << setprecision(12);

    m = 5;
    n = 5;

    x = new char[m] {'C', 'A', 'C', 'A', 'T'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T'};

    basicOps = 0;
    auto start = high_resolution_clock::now();
    int result = opt(0, 0);
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<duration<double>>(end - start);
 
    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    basicOps = 0;
    start = high_resolution_clock::now();
    result = optDP();
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);

    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    delete[] x;
    delete[] y;

    m = 10;
    n = 10;

    x = new char[m] {'C', 'A', 'C', 'A', 'T', 'A', 'G', 'A', 'A', 'G'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T', 'A', 'T', 'A', 'A', 'T'};
    
    basicOps = 0;
    start = high_resolution_clock::now();
    result = opt(0, 0);
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);
 
    cout<< '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    basicOps = 0;
    start = high_resolution_clock::now();
    result = optDP();
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);

    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();
    
    delete[] x;
    delete[] y;
    
    
    m = 12;
    n = 12;

    x = new char[m] {'C', 'A', 'C', 'A', 'T', 'A', 'G', 'A', 'A', 'G', 'C', 'G'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T', 'A', 'T', 'A', 'A', 'T', 'C', 'G'};
    
    basicOps = 0;
    start = high_resolution_clock::now();
    result = opt(0, 0);
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);
 
    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    basicOps = 0;
    start = high_resolution_clock::now();
    result = optDP();
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);

    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();
    
    delete[] x;
    delete[] y;

    m = 13;
    n = 13;

    x = new char[m] {'C', 'A', 'C', 'A', 'T', 'A', 'G', 'A', 'A', 'G', 'C', 'G', 'C'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T', 'A', 'T', 'A', 'A', 'T', 'C', 'G', 'T'};
    
    basicOps = 0;
    start = high_resolution_clock::now();
    result = opt(0, 0);
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);
 
    cout<< '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    basicOps = 0;
    start = high_resolution_clock::now();
    result = optDP();
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);

    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();
    
    delete[] x;
    delete[] y;
    
    m = 14;
    n = 14;

    x = new char[m] {'C', 'A', 'C', 'A', 'T', 'A', 'G', 'A', 'A', 'G', 'C', 'G', 'C', 'A'};
    y = new char[n] {'C', 'A', 'G', 'C', 'T', 'A', 'T', 'A', 'A', 'T', 'C', 'G', 'T', 'G'};
    
    basicOps = 0;
    start = high_resolution_clock::now();
    result = opt(0, 0);
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);
 
    cout<< '\n' << result << '\n' << basicOps << '\n' << elapsed.count();

    basicOps = 0;
    start = high_resolution_clock::now();
    result = optDP();
    end = high_resolution_clock::now();
    elapsed = duration_cast<duration<double>>(end - start);

    cout << '\n' << result << '\n' << basicOps << '\n' << elapsed.count();
    
    delete[] x;
    delete[] y;

    return 0;
}
