# Dining Philosopher Problem — Operating System Simulation (Python)

The **Dining Philosopher Problem** is a classic **synchronization problem** introduced by **Edsger Dijkstra**.  
It illustrates how processes (philosophers) compete for limited shared resources (chopsticks/forks) without causing **deadlock** or **starvation**.

This Python program demonstrates a **no busy-wait solution** using **semaphores** and **threads**, simulating philosophers alternately **thinking** and **eating** at a shared table.

## Problem Description
There are five philosophers sitting around a circular table.  
Each philosopher alternates between:
- **Thinking**
- **Eating**

To eat, a philosopher must pick up **two forks** — one on the left and one on the right.  
However, forks are shared with neighbors, so synchronization is needed to ensure that:
- No two philosophers use the same fork at the same time.
- No deadlock or starvation occurs.

## Solution Concept
- **Each fork** is represented by a `threading.Semaphore(1)`.
- A shared `mutex` semaphore ensures that console output and shared actions are safe.
- Philosophers pick up forks in an **asymmetric order** (left–right or right–left based on their index) to **avoid circular waiting** and hence **prevent deadlock**.

## Key Concepts
| Concept | Description |
|----------|-------------|
| **Process** | Each philosopher represents a process. |
| **Resource** | Forks are shared resources. |
| **Critical Section** | The “eating” part of code. |
| **Mutual Exclusion** | Ensured via semaphores. |
| **Deadlock Avoidance** | Achieved by asymmetric fork picking order. |

## How to Run

### Prerequisites

* Python 3.x installed
* Basic understanding of threads and semaphores

### Steps

1. Clone this repository:

   ```bash
   git clone https://github.com/SRmohakal/Dining-Philosopher-Problem.git
   ```
2. Navigate to the project folder:

   ```bash
   cd Dining-Philosopher-Problem
   ```
3. Run the program:

   ```bash
   python dining_philosophers.py
   ```

You will see console output showing philosophers alternately **thinking** and **eating**, without any deadlock.

---

## Sample Output

```
Philosopher 0 is hungry.
Philosopher 0 starts eating
Philosopher 0 finishes eating and starts thinking
Philosopher 3 is hungry.
Philosopher 3 starts eating
...
```

---

## Concepts Illustrated

* Mutual Exclusion
* Process Synchronization
* Deadlock Avoidance
* Starvation Freedom
* Semaphore-based Resource Control

---

## References

* E. W. Dijkstra, “Cooperating Sequential Processes,” 1965.
* A. Silberschatz, P. Galvin, G. Gagne, *Operating System Concepts*, 10th Edition.
* Python `threading` and `semaphore` documentation.

---

## Author

**Shourov Roy**
B.Sc. in Computer Science Student
📍 Shahjalal University of Science and Technology, Bangladesh
🗓️ Year: 2025
⭐ *Feel free to fork this repo and give it a star if you found it useful!*

---

`#OperatingSystem` `#Python` `#Semaphore` `#Synchronization` `#Deadlock` `#Threading` `#OSProject`

```
