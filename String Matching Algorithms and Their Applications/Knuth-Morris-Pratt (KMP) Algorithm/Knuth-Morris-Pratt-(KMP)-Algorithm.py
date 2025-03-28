def computeLPS(pattern):
    m = len(pattern)
    lps = [0] * m
    length = 0  
    i = 1  

    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def KMP(text, pattern):
    n = len(text)
    m = len(pattern)
    lps = computeLPS(pattern)

    i = 0  # index for text
    j = 0  # index for pattern
    found = False  

    while i < n:
        if text[i] == pattern[j]:  # Match
            i += 1
            j += 1

        if j == m:  # Full pattern matched
            print(f"Pattern found at index {i - j}")
            j = lps[j - 1]
            found = True

        elif i < n and text[i] != pattern[j]:  # Mismatch
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

    if not found:
        print("Pattern not found in the text.")

if __name__ == "__main__":
    text = input("Enter the text: ")
    pattern = input("Enter the pattern: ")
    
    print("LPS Array:", computeLPS(pattern))
    KMP(text, pattern)
