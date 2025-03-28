#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void rabin_karp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    if (m > n) {
        printf("Pattern is longer than the text.\n");
        return;
    }

    int h = 1, p_hash = 0, t_hash = 0;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p_hash = (d * p_hash + pattern[i]) % q;
        t_hash = (d * t_hash + text[i]) % q;
    }

    int match_found = 0;
    for (int i = 0; i <= n - m; i++) {
        if (p_hash == t_hash) {
            int j;
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m) {
                printf("Pattern found at index %d\n", i);
                match_found = 1;
            }
        }

        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;
            if (t_hash < 0)
                t_hash += q;
        }
    }

    if (!match_found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    rabin_karp(text, pattern);
    return 0;
}
