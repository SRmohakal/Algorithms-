#include <bits/stdc++.h>
#include <string>
using namespace std;

void naiveApproach(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++) { // Sliding over text
        bool match = true;
        for (int j = 0; j < m; j++) { // Checking each character
            if (text[i + j] != pattern[j]) {
                match = false;
                break; // If mismatch found then break
            }
        }
        if (match) {
            cout << "Pattern found at index " << i << "." << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Pattern not found." << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    naiveApproach(text, pattern);
    return 0;
}
