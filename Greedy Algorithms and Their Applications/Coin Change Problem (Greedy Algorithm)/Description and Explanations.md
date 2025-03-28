### **Coin Change Problem (Greedy Algorithm)**
The **Coin Change Problem** involves finding the minimum number of coins required to make a given amount using a set of denominations. 

🔹 **Greedy Approach:**  
1. Pick the highest denomination coin that does not exceed the remaining amount.
2. Subtract its value from the remaining amount.
3. Repeat until the amount becomes zero.

💡 **Note:** The greedy algorithm **only works correctly** for certain coin systems (e.g., U.S. currency: {1, 5, 10, 25}) but **fails** for arbitrary denominations like {1, 3, 4}.

---

### **Example**
**Input:**  
- Denominations: `{1, 5, 10, 25}`  
- Amount: `63`

**Greedy Steps:**
1. Take `25` → Remaining = `38`
2. Take `25` → Remaining = `13`
3. Take `10` → Remaining = `3`
4. Take `1` → Remaining = `2`
5. Take `1` → Remaining = `1`
6. Take `1` → Remaining = `0`

**Output:** `{25, 25, 10, 1, 1, 1}` (Total: 6 coins)

---

### **When Greedy Fails**
For denominations `{1, 3, 4}`, trying to make `6`:
- Greedy picks: `{4, 1, 1}` → Total: `3` coins ❌
- Optimal solution: `{3, 3}` → Total: `2` coins ✅
