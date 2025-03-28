## **Knuth-Morris-Pratt (KMP) Algorithm: A Deep Dive**  

The **Knuth-Morris-Pratt (KMP) algorithm** is a powerful and efficient pattern-matching algorithm that improves search speed by avoiding unnecessary comparisons.

---

### **1. Why KMP?**
The naïve string matching approach checks every possible position in the text, making it inefficient (\(O(m \cdot n)\)). The KMP algorithm improves efficiency by using a **preprocessing step** that helps skip redundant comparisons, reducing the complexity to **\(O(n + m)\)**.

---

### **2. How KMP Works**
The KMP algorithm consists of two main phases:

1. **Preprocessing (Building the LPS Array)**  
   - The **LPS (Longest Prefix Suffix) array** stores information about the pattern itself.  
   - It helps determine how much the pattern can be shifted when a mismatch occurs, instead of rechecking from the beginning.

2. **Pattern Searching (Using the LPS Array)**  
   - Compares the pattern with the text while skipping redundant checks using the LPS array.

---

### **3. KMP Algorithm Steps**
#### **Step 1: Construct the LPS Array**
The **LPS array** is used to avoid unnecessary re-evaluations of already matched characters.  
Each entry **LPS[i]** indicates the longest proper prefix which is also a suffix for the substring \(P[0..i]\).  

Example:  
Pattern: `"ABABCABAB"`  
LPS Array: `[0, 0, 1, 2, 0, 1, 2, 3, 4]`  

#### **Step 2: Search the Pattern in Text**
- Compare characters of **text** and **pattern**.  
- If characters match, move to the next character.  
- If a mismatch occurs, shift the pattern using the LPS array instead of restarting from scratch.

---

### **4. KMP Implementation in Python**
```python
def compute_lps(pattern):
    m = len(pattern)
    lps = [0] * m  
    j = 0  # Length of the previous longest prefix suffix
    i = 1  # Start from second character

    while i < m:
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
            i += 1
        else:
            if j != 0:
                j = lps[j - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    lps = compute_lps(pattern)

    i = 0  # Index for text
    j = 0  # Index for pattern

    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1

        if j == m:  # Match found
            print(f"Pattern found at index {i - j}")
            j = lps[j - 1]  # Use LPS to avoid redundant comparisons

        elif i < n and pattern[j] != text[i]:  # Mismatch
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

# Example Usage
text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
kmp_search(text, pattern)
```

---

### **5. Example Walkthrough**
#### **Given:**
Text: `"ABABDABACDABABCABAB"`  
Pattern: `"ABABCABAB"`

#### **Step-by-step Matching**
| Text Position | Pattern | Match? | LPS Used? |
|--------------|--------|--------|------------|
| 0-4  | ABABD | ✗ No  | Shift using LPS |
| 5-8  | ABABC | ✔ Yes | Continue |
| 9-16 | ABABCABAB | ✔ Found! | Report Index |

Pattern found at **index 10**.

---

### **6. Complexity Analysis**
- **Preprocessing LPS Array**: \(O(m)\)
- **Pattern Searching**: \(O(n)\)
- **Total Complexity**: **\(O(n + m)\)** (Much better than naïve \(O(m \cdot n)\))

---

### **7. Applications of KMP Algorithm**
- **Text Searching** (e.g., searching keywords in documents).
- **Spam Detection** (detecting repeated patterns in emails).
- **DNA Sequence Matching** (finding genetic patterns).
- **Plagiarism Detection** (identifying repeated text in papers).
- **Network Security** (pattern-based intrusion detection).

---

### **8. Why is KMP Better than Naïve Approach?**
| Feature | Naïve Algorithm | KMP Algorithm |
|---------|---------------|--------------|
| Best Case | \(O(n)\) | \(O(n)\) |
| Worst Case | \(O(m \cdot n)\) | \(O(n + m)\) |
| Redundant Comparisons | Yes | No |
| Preprocessing Needed | No | Yes (LPS) |

---

### **9. Conclusion**
- The **KMP Algorithm** is an efficient pattern matching approach.
- It avoids unnecessary re-evaluations by utilizing the **LPS array**.
- It is widely used in real-world applications requiring fast and efficient search.

Would you like me to explain another algorithm, or do you have any questions on KMP? 😊
