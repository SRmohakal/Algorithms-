def rabin_karp(text, pattern, d=256, q=101):
    n, m = len(text), len(pattern)

    if m > n:
        print("Pattern is longer than the text.")
        return

    h = pow(d, m - 1) % q  # Precomputed d^(m-1) % q
    p_hash, t_hash = 0, 0 
    match_found = False

    # computing initial hash values
    for i in range(m):
        p_hash = (d * p_hash + ord(pattern[i])) % q
        t_hash = (d * t_hash + ord(text[i])) % q

    # Sliding over text
    for i in range(n - m + 1):
        if p_hash == t_hash and text[i:i + m] == pattern:
            print(f"Pattern found at index {i}")
            match_found = True

        # Rolling Hash
        if i < n - m:
            t_hash = ((t_hash - ord(text[i]) * h) * d + ord(text[i + m])) % q
            if t_hash < 0:
                t_hash += q

    if not match_found:
        print("Pattern not found in the text.")

if __name__ == "__main__":
    text = input("Enter the text: ").strip()
    pattern = input("Enter the pattern: ").strip()

    if text and pattern:
        rabin_karp(text, pattern)
    else:
        print("Pattern and text cannot be empty.")
