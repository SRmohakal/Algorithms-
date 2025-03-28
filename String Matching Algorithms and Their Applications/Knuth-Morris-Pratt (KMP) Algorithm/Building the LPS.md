# **Building the LPS (Longest Prefix Suffix) Array in KMP Algorithm**

---

## **1. What is the LPS Array?**
The **LPS array** for a pattern **stores values indicating the longest proper prefix which is also a suffix** at each position in the pattern.

- **Proper Prefix:** A prefix that is **not equal** to the whole string.
- **Proper Suffix:** A suffix that is **not equal** to the whole string.
- **Example:**  
  For the pattern `"ABABAC"`, a proper prefix can be `"A", "AB", "ABA"`, and so on.  
  A proper suffix can be `"B", "AC", "BAC"`, and so on.

---

## **2. Example of an LPS Array**
Consider the pattern **`"ABABAC"`**.

| Index (i) | Pattern Prefix | LPS Value | Explanation |
|-----------|---------------|-----------|-------------|
| 0 | `"A"` | 0 | No prefix equals a suffix |
| 1 | `"AB"` | 0 | No prefix equals a suffix |
| 2 | `"ABA"` | 1 | `"A"` is a prefix and suffix |
| 3 | `"ABAB"` | 2 | `"AB"` is a prefix and suffix |
| 4 | `"ABABA"` | 3 | `"ABA"` is a prefix and suffix |
| 5 | `"ABABAC"` | 0 | No prefix equals a suffix |

### **Final LPS Array:**  
```
LPS = [0, 0, 1, 2, 3, 0]
```

---

## **3. How to Build the LPS Array**
To construct the LPS array efficiently, we use **two pointers:**
1. **i** (iterates over the pattern)
2. **len (ℓ)** (tracks the length of the longest prefix suffix)

#### **Steps:**
1. Initialize **`LPS[0] = 0`** (Single character can’t have a prefix-suffix match).
2. Start from **i = 1** and compare `pattern[i]` with `pattern[len]`.
   - If **they match**, update `LPS[i] = len + 1` and increment `len`.
   - If **they don’t match**, check for the previous LPS value and adjust `len`.
3. Continue until the pattern is fully processed.

---

## **4. LPS Construction in Python**
```python
def compute_lps(pattern):
    m = len(pattern)
    lps = [0] * m  # Initializing LPS array with 0
    length = 0  # Length of previous longest prefix suffix
    i = 1  # Start comparing from index 1

    while i < m:
        if pattern[i] == pattern[length]:  # Match found
            length += 1
            lps[i] = length
            i += 1
        else:  # Mismatch
            if length != 0:  # Checking previous LPS value
                length = lps[length - 1]  # Move back in LPS table
            else:
                lps[i] = 0  # No LPS found
                i += 1  # Move to the next character

    return lps

pattern = "ABABAC"
lps_array = compute_lps(pattern)
print("LPS Array:", lps_array)
```

### **Output:**
```
LPS Array: [0, 0, 1, 2, 3, 0]
```

---

### **Initial Values**
```
pattern = "ABABAC"
LPS = [0, 0, 0, 0, 0, 0]
length = 0, i = 1
```

### **Step-by-Step Computation**
| i | pattern[i] | length | Match? | LPS Update |
|---|-----------|--------|--------|------------|
| 1 | B vs A | 0 | ❌ No | `LPS[1] = 0`, move to i = 2 |
| 2 | A vs A | 0 | ✅ Yes | `LPS[2] = 1`, length = 1, move to i = 3 |
| 3 | B vs B | 1 | ✅ Yes | `LPS[3] = 2`, length = 2, move to i = 4 |
| 4 | A vs A | 2 | ✅ Yes | `LPS[4] = 3`, length = 3, move to i = 5 |
| 5 | C vs B | 3 | ❌ No | Reset `length = LPS[2] = 1`, retry |
| 5 | C vs B | 1 | ❌ No | Reset `length = LPS[0] = 0`, retry |
| 5 | C vs A | 0 | ❌ No | `LPS[5] = 0`, move to i = 6 |

### **Final LPS Array:**
```
LPS = [0, 0, 1, 2, 3, 0]
```

---

## **Walkthrough with Example**
### ✅ **Step 1: Start with `i = 1`**
- `pattern[1] = 'B'`  
- Compare with `pattern[length] = pattern[0] = 'A'`  
- ❌ **Mismatch** → `LPS[1] = 0`
- Move `i = 2`

---

### ✅ **Step 2: Match Found (`i = 2`)**
- `pattern[2] = 'A'`  
- Compare with `pattern[length] = pattern[0] = 'A'`  
- ✅ **Match** → Update `length = 1`  
- `LPS[2] = 1`  
- Move `i = 3`

---

### ✅ **Step 3: Match Found (`i = 3`)**
- `pattern[3] = 'B'`  
- Compare with `pattern[length] = pattern[1] = 'B'`  
- ✅ **Match** → Update `length = 2`  
- `LPS[3] = 2`  
- Move `i = 4`

---

### ✅ **Step 4: Match Found (`i = 4`)**
- `pattern[4] = 'A'`  
- Compare with `pattern[length] = pattern[2] = 'A'`  
- ✅ **Match** → Update `length = 3`  
- `LPS[4] = 3`  
- Move `i = 5`

---

### ❌ **Step 5: Mismatch at `i = 5`**
- `pattern[5] = 'C'`  
- Compare with `pattern[length] = pattern[3] = 'B'`  
- ❌ **Mismatch**  
- **Check LPS value:** Move `length = LPS[2] = 1`  
- Compare `pattern[5] = 'C'` with `pattern[1] = 'B'`  
- ❌ **Mismatch Again**  
- Move `length = LPS[0] = 0`  
- Compare `pattern[5] = 'C'` with `pattern[0] = 'A'`  
- ❌ **Mismatch** → `LPS[5] = 0`
- Move `i = 6`, **end of pattern**.

---

## **Final LPS Array:**
```
[0, 0, 1, 2, 3, 0]
```

---
