#include <stdio.h>
#include <string.h>

void computeLPS(char *pattern, int m, int *lps) {
    int length = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0, j = 0;
    int found = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
            found = 1;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    KMP(text, pattern);
    return 0;
}
