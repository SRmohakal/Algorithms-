# **Rolling Hash Explained with Example**  

---

## **1. Hash Function Formula**  
For a substring s[i:i+m] of length m , the hash function is:  

hash(s) = (c<sub>1</sub> . d<sup>(m-1)</sup> + c<sub>2</sub> . d<sup>(m-2)</sup> + ... + c<sub>m</sub> . d<sup>0,/sup>) mod q

### **Where:**
- d = **Chosen base** (e.g., **256** for ASCII characters)
- q = **A prime number** (to reduce collisions)
- c<sub>1</sub>, c<sub>2</sub>, ... c<sub>m</sub> = **Character values** (e.g., ASCII values)

---

## **2. Efficient Hash Update (Rolling Hash Formula)**
When shifting the window by one character, the new hash is updated using:

new_hash = ((old_hash - old_char . d<sup>(m-1)</sup>) . d + new_char) mod q

### **Why use this formula?**
- The old character (leaving the window) is **removed** from the hash.
- The new character (entering the window) is **added** to the hash.
- Hash is updated in **O(1) time**, instead of recomputing in **O(m) time**.

---

## **3. Example Step-by-Step**  
Let's search for **"AB"** in **"ABABDABAB"** using **Rolling Hash (Rabin-Karp algorithm).**

### **Given Data:**
- **Text:** `"ABABDABAB"`
- **Pattern:** `"AB"`
- **Base d  = 256 (for ASCII)**
- **Prime q  = 101 (to reduce collisions)**

---

### **Step 1: Compute Initial Hash Values**  
#### **Hash of the first window of text "AB"**  

Using the formula:

hash}(s) = (c<sub>1</sub> . d<sup>(m-1)</sup> + c<sub>2</sub> . d<sup>0</sup>) mod q

For `"AB"`:
- ASCII of `'A'` = **65**, `'B'` = **66**
- d = 256, q = 101
- Hash of `"AB"`:

hash("AB") = (65 . 256^1 + 66 . 256^0) mod 101
= (65 . 256 + 66) mod 101
= (16640 + 66) mod 101
= 16706 mod 101
= 57

Thus, **Pattern Hash = 57**  
Similarly, **Hash of first window in text "AB" = 57**

---

### **Step 2: Slide the Window & Update Hash**  
Now, slide the window one position at a time and update the hash using:

new_hash = ((old_hash - old_char . d<sup>(m-1)</sup>) . d + new_char) mod q

#### **Window shifts:**
1️⃣ **Window = `"AB"` (i = 0, Hash = 57)** ✅ **Match found at index 0**  
2️⃣ **Next window = `"BA"` (i = 1)**
   - **Old char:** `'A'`, **New char:** `'A'`
   - **Old Hash = 57**
   - Compute **New Hash**:

new_hash = ((57 - 65 . 256^1) . 256 + 65) mod 101
= (57 - 16640) . 256 + 65) mod 101
= (-16583 . 256 + 65) mod 101
= 92

**(No match, move to next window)**  

3️⃣ **Next window = `"AB"` (i = 2, Hash = 57)** ✅ **Match found at index 2**  
4️⃣ **Next window = `"BD"` (i = 3, Hash ≠ 57, No match, move forward)**  
5️⃣ **Next window = `"DA"` (i = 4, Hash ≠ 57, No match, move forward)**  
6️⃣ **Next window = `"AB"` (i = 5, Hash = 57)** ✅ **Match found at index 5**  
7️⃣ **Next window = `"BA"` (i = 6, Hash ≠ 57, No match, move forward)**  
8️⃣ **Next window = `"AB"` (i = 7, Hash = 57)** ✅ **Match found at index 7**  

---

## **Final Output**
```
Pattern found at index 0
Pattern found at index 2
Pattern found at index 5
Pattern found at index 7
```

---

---

# **Rolling Hash & Rabin-Karp Algorithm Explained with Example**  

## **1. Introduction to Rolling Hash**  
Rolling Hash is a technique used in string searching algorithms, like **Rabin-Karp**, to efficiently compute hash values of substrings. Instead of recomputing the hash from scratch, **it updates the hash in constant time** \( O(1) \) when shifting the window in the text.

---

## **2. Hash Function Formula**  
For a substring \( s[i:i+m] \) of length \( m \), the hash function is:  

\[
\text{hash}(s) = (c_1 \cdot d^{m-1} + c_2 \cdot d^{m-2} + ... + c_m \cdot d^0) \mod q
\]

### **Where:**
- \( d \) = **Chosen base** (e.g., **256** for ASCII characters)
- \( q \) = **A prime number** (to reduce collisions)
- \( c_1, c_2, ... c_m \) = **Character values** (e.g., ASCII values)

---

## **3. Efficient Hash Update (Rolling Hash Formula)**
When shifting the window by one character, the new hash is updated using:

\[
\text{new\_hash} = ((\text{old\_hash} - \text{old\_char} \cdot d^{m-1}) \cdot d + \text{new\_char}) \mod q
\]

### **Why use this formula?**
- The old character (leaving the window) is **removed** from the hash.
- The new character (entering the window) is **added** to the hash.
- Hash is updated in **O(1) time**, instead of recomputing in **O(m) time**.

---

## **4. Example Step-by-Step**  
Let's search for **"AB"** in **"ABABDABAB"** using **Rolling Hash (Rabin-Karp algorithm).**

### **Given Data:**
- **Text:** `"ABABDABAB"`
- **Pattern:** `"AB"`
- **Base \( d \) = 256 (for ASCII)**
- **Prime \( q \) = 101 (to reduce collisions)**

---

### **Step 1: Compute Initial Hash Values**  
#### **Hash of the first window of text ("AB")**  

Using the formula:

\[
\text{hash}(s) = (c_1 \cdot d^{m-1} + c_2 \cdot d^0) \mod q
\]

For `"AB"`:
- ASCII of `'A'` = **65**, `'B'` = **66**
- \( d = 256 \), \( q = 101 \)
- Hash of `"AB"`:

\[
\text{hash}("AB") = (65 \cdot 256^1 + 66 \cdot 256^0) \mod 101
\]

\[
= (65 \cdot 256 + 66) \mod 101
\]

\[
= (16640 + 66) \mod 101
\]

\[
= 16706 \mod 101
\]

\[
= 57
\]

Thus, **Pattern Hash = 57**  
Similarly, **Hash of first window in text ("AB") = 57**

---

### **Step 2: Slide the Window & Update Hash**  
Now, slide the window one position at a time and update the hash using:

\[
\text{new\_hash} = ((\text{old\_hash} - \text{old\_char} \cdot d^{m-1}) \cdot d + \text{new\_char}) \mod q
\]

#### **Window shifts:**
1️⃣ **Window = `"AB"` (i = 0, Hash = 57)** ✅ **Match found at index 0**  
2️⃣ **Next window = `"BA"` (i = 1)**
   - **Old char:** `'A'`, **New char:** `'A'`
   - **Old Hash = 57**
   - Compute **New Hash**:

\[
\text{new\_hash} = ((57 - 65 \cdot 256^1) \cdot 256 + 65) \mod 101
\]

\[
= (57 - 16640) \cdot 256 + 65) \mod 101
\]

\[
= (-16583 \cdot 256 + 65) \mod 101
\]

\[
= 92
\]

**(No match, move to next window)**  

3️⃣ **Next window = `"AB"` (i = 2, Hash = 57)** ✅ **Match found at index 2**  
4️⃣ **Next window = `"BD"` (i = 3, Hash ≠ 57, No match, move forward)**  
5️⃣ **Next window = `"DA"` (i = 4, Hash ≠ 57, No match, move forward)**  
6️⃣ **Next window = `"AB"` (i = 5, Hash = 57)** ✅ **Match found at index 5**  
7️⃣ **Next window = `"BA"` (i = 6, Hash ≠ 57, No match, move forward)**  
8️⃣ **Next window = `"AB"` (i = 7, Hash = 57)** ✅ **Match found at index 7**  

---

## **Final Output**
```
Pattern found at index 0
Pattern found at index 2
Pattern found at index 5
Pattern found at index 7
```

---

## **5. Why Rolling Hash is Efficient?**
### ✅ **Naive Approach vs. Rolling Hash**
| Approach | Hash Computation | Time Complexity |
|----------|----------------|----------------|
| Naïve (Brute Force) | Recalculates hash for each window | **O(m * n)** |
| Rolling Hash | Uses old hash to compute new in **O(1)** | **O(n + m)** |

This **significantly speeds up** pattern matching.

---

## **6. Summary**
🔹 **Rolling Hash updates the hash in O(1) time** instead of recomputing it in O(m).  
🔹 **Hash formula uses a prime number** to reduce collisions.  
🔹 **Used in the Rabin-Karp algorithm** for fast pattern matching.  
🔹 **Sliding window + modular arithmetic** ensures efficiency.  

---

## 🚀 **Next Steps**
Would you like:
1️⃣ **A Python implementation of Rabin-Karp?**  
2️⃣ **Comparison with other string matching algorithms?**  
3️⃣ **Visualization of how the hash values change?**  

Let me know what interests you! 😊
