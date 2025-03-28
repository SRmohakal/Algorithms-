## **Fractional Knapsack**  
The **Fractional Knapsack Problem** is an optimization problem where we are given:  
1. A set of items, each with a **weight** and **value**.  
2. A **knapsack** with a maximum weight capacity.  
3. The goal is to maximize the **total value** that can be carried in the knapsack.  

🔹 **Fractional Part Allowed**: Unlike the **0/1 Knapsack Problem**, where items are either taken completely or not at all, in the **Fractional Knapsack Problem**, we can take a fraction of an item.

---

## **Greedy Approach**
### **Steps of the Algorithm**:
1. **Calculate the value-to-weight ratio** for each item.  
   \[
   \text{Ratio} = \frac{\text{Value}}{\text{Weight}}
   \]
2. **Sort items** in descending order based on the ratio.  
3. **Pick items greedily**:
   - Take as much as possible from the highest ratio item.
   - If the knapsack is not full, move to the next item.
   - If the item cannot fit completely, take a fraction of it to fill the remaining capacity.
4. **Repeat until the knapsack is full**.

---

## **Example Walkthrough**
Let's say we have the following **items**:

| Item | Value | Weight | Value/Weight |
|------|-------|--------|--------------|
| 1    | 60    | 10     | 6.0          |
| 2    | 100   | 20     | 5.0          |
| 3    | 120   | 30     | 4.0          |

### **Step 1: Sorting by Value/Weight**
After sorting, the order remains the same:
1. **Item 1** (6.0)
2. **Item 2** (5.0)
3. **Item 3** (4.0)

We also have a **knapsack capacity** of **50**.

---

### **Step 2: Processing the Items**
#### ✅ **Take Item 1 Completely**  
- Weight: **10** (fits in capacity **50**)  
- Value: **60**  
- **Remaining Capacity = 50 - 10 = 40**  
- **Total Value = 60**  

#### ✅ **Take Item 2 Completely**  
- Weight: **20** (fits in capacity **40**)  
- Value: **100**  
- **Remaining Capacity = 40 - 20 = 20**  
- **Total Value = 60 + 100 = 160**  

#### 🔴 **Take a Fraction of Item 3**  
- Remaining capacity: **20**, but Item 3’s weight is **30**  
- Take **(20/30) = 2/3** of Item 3  
- Value taken: **(2/3) × 120 = 80**  
- **Total Value = 160 + 80 = 240**  

---

## **Time Complexity**
- **Sorting the items:** O(N log N)
- **Iterating through the items:** O(N) 
- **Overall Complexity:** **O(N log N)**

---

## **When to Use the Greedy Approach?**
✅ **Use Greedy (Fractional Knapsack)** if items can be divided (e.g., liquids, grains).  
❌ **Use Dynamic Programming (0/1 Knapsack)** if items cannot be split (e.g., laptops, books).  
