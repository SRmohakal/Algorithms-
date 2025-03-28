# **Naïve String Matching Algorithm**  

The **Naïve String Matching Algorithm** is the simplest approach to finding a pattern in a text. It works by checking every possible position in the text to see if the pattern matches.  

---

## **1. How It Works**
1. Start at the first character of the text.
2. Compare the pattern with the text **character by character**.
3. If a mismatch occurs, shift the pattern **one position** to the right and repeat.
4. If all characters match, record the index where the pattern is found.
5. Continue until the end of the text.

---

## **2. Example**
### **Text:** `"AABAACAADAABAABA"`  
### **Pattern:** `"AABA"`  

#### **Step-by-step Matching Process**
| Position | Text Window  | Match? |
|----------|------------|--------|
| 0        | AABA       | ✅ Yes (Pattern found at index 0) |
| 1        | ABAA       | ❌ No |
| 2        | BAAC       | ❌ No |
| 3        | AACA       | ❌ No |
| 4        | ACAD       | ❌ No |
| 5        | CAAD       | ❌ No |
| 6        | AADA       | ❌ No |
| 7        | ADAA       | ❌ No |
| 8        | DAAB       | ❌ No |
| 9        | AABA       | ✅ Yes (Pattern found at index 9) |
| 10       | ABAA       | ❌ No |
| 11       | BAAB       | ❌ No |
| 12       | AABA       | ✅ Yes (Pattern found at index 12) |

### **Output:**  
Pattern found at **indices 0, 9, and 12**.

---

## **3. Time Complexity Analysis**
| Case | Time Complexity |
|------|---------------|
| **Best Case (Mismatch on first character each time)** | \(O(n)\) |
| **Worst Case (Pattern matches many times or at the end)** | \(O(m \cdot n)\) |

- **Best Case Example:**  
  - **Text:** `"ABCDEFGHIJK"`  
  - **Pattern:** `"XYZ"` (Mismatch at first character every time → \(O(n)\)).  

- **Worst Case Example:**  
  - **Text:** `"AAAAAAAAAA"`  
  - **Pattern:** `"AAA"` (Overlapping matches → \(O(m \cdot n)\)).  

---

## **4. When to Use the Naïve Algorithm?**
✅ **Small Texts:** Works well for **short texts** and patterns.  
✅ **Simple Applications:** Quick and easy to implement.  
❌ **Inefficient for Large Texts:** **Slower than KMP or Boyer-Moore** for long texts.  

---

## **5. Comparison with Other String Matching Algorithms**
| Algorithm | Best Case | Worst Case | Suitable For |
|-----------|----------|------------|--------------|
| **Naïve Algorithm** | \(O(n)\) | \(O(m \cdot n)\) | Small datasets |
| **KMP Algorithm** | \(O(n)\) | \(O(n + m)\) | Large texts |
| **Boyer-Moore** | \(O(n/m)\) | \(O(n \cdot m)\) | Long texts |
| **Rabin-Karp** | \(O(n)\) | \(O(m \cdot n)\) | Multiple patterns |

---

## **6. Applications**
- **Basic text searching** in small texts.  
- **Introductory algorithm** for understanding pattern matching.  
- **Simple log file searching.**  
