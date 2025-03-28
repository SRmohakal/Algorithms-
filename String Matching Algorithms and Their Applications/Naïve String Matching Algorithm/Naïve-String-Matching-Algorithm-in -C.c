```
---

## **✅ C Implementation**
```c
#include <stdio.h>
#include <string.h>

void naiveApproach(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= n - m; i++) { // Sliding over text
        int match = 1;
        for (int j = 0; j < m; j++) { // Checking each character
            if (text[i + j] != pattern[j]) {
                match = 0;
                break; // If mismatch found then break
            }
        }
        if (match) {
            printf("Pattern found at index %d.\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found.\n");
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    naiveApproach(text, pattern);
    return 0;
}
```
---
