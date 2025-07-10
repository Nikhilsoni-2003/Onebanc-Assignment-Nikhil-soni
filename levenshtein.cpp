#include <iostream>
#include <vector>
#include <iomanip>  // for setw()

using namespace std;

int main() {
    string str1, str2;

    // Input strings
    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int m = str1.length();
    int n = str2.length();

    // Create matrix (dp) of size (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize first row and column
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // Fill the matrix using DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // no change
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }

    // Print the matrix
    cout << "\nEdit Distance Matrix:\n\n   ";

    // Print header for str2
    cout << "  ";
    for (char ch : str2)
        cout << setw(3) << ch;
    cout << "\n";

    for (int i = 0; i <= m; i++) {
        // Print row label (str1 chars or space for first row)
        if (i == 0)
            cout << " ";
        else
            cout << str1[i - 1];

        for (int j = 0; j <= n; j++) {
            cout << setw(3) << dp[i][j];
        }
        cout << "\n";
    }

    // Final output
    cout << "\nMinimum Edit Distance = " << dp[m][n] << "\n";

    return 0;
}
