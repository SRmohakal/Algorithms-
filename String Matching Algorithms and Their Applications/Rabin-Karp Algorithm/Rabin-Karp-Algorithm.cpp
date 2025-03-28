#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define d 256
#define q 101

void rabin_karp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << "Pattern is longer than the text.\n";
        return;
    }

    int h = 1, p_hash = 0, t_hash = 0;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p_hash = (d * p_hash + pattern[i]) % q;
        t_hash = (d * t_hash + text[i]) % q;
    }

    bool match_found = false;
    for (int i = 0; i <= n - m; i++) {
        if (p_hash == t_hash && text.substr(i, m) == pattern) {
            cout << "Pattern found at index " << i << endl;
            match_found = true;
        }

        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;
            if (t_hash < 0)
                t_hash += q;
        }
    }

    if (!match_found)
        cout << "Pattern not found in the text.\n";
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    rabin_karp(text, pattern);
    return 0;
}
