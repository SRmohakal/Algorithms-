# **Rabin-Karp Algorithm**  

The **Rabin-Karp algorithm** is a powerful **string matching algorithm** that uses **hashing** to efficiently find a pattern in a text. It is particularly useful when searching for multiple patterns or when exact string matching is required in large texts.

---

## **1. Why Rabin-Karp?**
- The **naïve approach** takes **O(m.n)** time, which is inefficient for large texts.
- **Rabin-Karp uses hashing** to compare substrings quickly, achieving an average time complexity of **O(n)**.
- It is **ideal for multiple pattern searching** (e.g., plagiarism detection, digital forensics).

---

## **2. How Rabin-Karp Works**
1. **Compute a hash value for the pattern** (small substring to be searched).
2. **Compute the hash value for the first window of text** (same length as the pattern).
3. **Slide the window** across the text, computing the hash for each substring efficiently using a **rolling hash technique**.
4. **Compare hash values**:
   - If **hash values match**, check character-by-character to confirm.
   - If they don't match, slide the window forward and update the hash.

---

## **3.Rolling Hash**
Instead of recalculating the hash from scratch in each step, **rolling hash** allows for quick updates when moving to the next substring.

#### **Hash Function Formula**:
For a substring s[i:i+m] of length m, the hash value is computed as:

hash(s) = (c<sub>1</sub>.d<sup>m-1</sup> + c<sub>2</sub>.d<sup>m-2</sup> + ... + c<sub>m</sub>.d<sup>0</sup>) mod q

Where:
- d = Chosen base (e.g., **256** for ASCII characters).
- q = Prime number (to avoid collisions).

When shifting, update the hash efficiently:
new_hash = ( (old_hash - old_char.d<sup>m-1</sup>).d + new_char ) mod q

This ensures a fast recalculation in **O(1)** time instead of O(m).

---

## **4. Example Walkthrough**
### **Given:**
Text: `"ABCCBAABCCBA"`  
Pattern: `"CBA"`  
Prime q = 101, Base d = 256

### **Initial Hash Computation:**
```
Hash("CBA") = (C * 256^2 + B * 256^1 + A * 256^0) % 101
```
Calculating initial hash for the first three characters of `"ABCCBAABCCBA"`.

### **Matching Process:**
| Text Window | Hash Value | Matches? |
|------------|------------|---------|
| `"ABC"`   | 24  | ✗ No |
| `"BCC"`   | 36  | ✗ No |
| `"CCB"`   | 55  | ✗ No |
| `"CBA"`   | 47  | ✔ Yes (Pattern Found) |
| `"BAA"`   | 29  | ✗ No |
| `"AAB"`   | 25  | ✗ No |
| `"ABC"`   | 24  | ✗ No |
| `"BCC"`   | 36  | ✗ No |
| `"CCB"`   | 55  | ✗ No |
| `"CBA"`   | 47  | ✔ Yes (Pattern Found) |

**Pattern found at indices: 3, 9 🎉**

---

## **6. Complexity Analysis**
| Step | Time Complexity |
|------|---------------|
| Hash Computation | O(m) |
| Hash Update (Rolling Hash) | O(1) |
| Pattern Matching | O(n) (average case) |
| Worst Case | O(n.m) (due to hash collisions) |

- **Best Case (No Hash Collisions)**: O(n)
- **Worst Case (Many Hash Collisions)**: O(n \cdot m)

---

## **7. Applications of Rabin-Karp**
### ✅ **Plagiarism Detection**
- **Fast multiple pattern searches** by hashing phrases in a document.
- Used in tools like **Turnitin** and **Copyscape**.

### ✅ **Spam Detection**
- Used to detect common spam messages by **checking patterns** in emails.

### ✅ **DNA Sequence Matching**
- Efficiently finds **gene patterns** in long DNA sequences.

### ✅ **Intrusion Detection**
- Finds **malware signatures** in system logs by searching multiple patterns.

### ✅ **Database Search**
- Fast search in large **text databases** by precomputing **hash indices**.

---
