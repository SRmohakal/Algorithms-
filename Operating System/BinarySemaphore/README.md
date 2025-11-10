## 🔒 Binary Semaphore Simulation in Python

This project demonstrates the working of a **Binary Semaphore (Mutex Semaphore)** using Python.
A binary semaphore is a synchronization mechanism that ensures **mutual exclusion**, meaning **only one process can access the critical section at a time**, while others must wait.

This simple simulation shows how multiple processes request a lock, get blocked if the mutex is already held, and are later unblocked when the lock is released.

---

### ⚙️ Features

* Implements a **binary semaphore** mechanism from scratch in Python.
* Simulates multiple processes using a custom `Process` class.
* Demonstrates **wait (P)** and **signal (V)** operations clearly.
* Uses a queue (`collections.deque`) to manage blocked processes.
* Prints process state transitions: `Inactive`, `Running`, `Blocked`, and `Ready`.

---

### 🧩 Code Structure

```
BinarySemaphore/
│
├── semaphore.py        # Main program file (contains classes and logic)
└── README.md           # Project documentation
```

---

### 🚀 How to Run

1. **Clone the repository**

   ```bash
   git clone https://github.com/SRmohakal/BinarySemaphore.git
   cd BinarySemaphore
   ```

2. **Run the program**

   ```bash
   python semaphore.py
   ```

3. **Observe the Output**
   The console will show how each process requests the lock, gets blocked, and becomes ready again when the mutex is released.

---

### 🧠 Sample Output

```
Process-1 is (Inactive). is requesting lock.
Process-1 is (Running). is acquired lock.
Process-2 is (Inactive). is requesting lock.
Process-2 is (Blocked). is bocked. Mutex is locked.
Process-3 is (Inactive). is requesting lock.
Process-3 is (Blocked). is bocked. Mutex is locked.
Process-2 is (Ready). is unblocked and ready for lock.
Process-3 is (Ready). is unblocked and ready for lock.
Mutex is realesed.
```

---

### 🔍 Concept Recap

| Concept                      | Description                                                             |
| ---------------------------- | ----------------------------------------------------------------------- |
| **Binary Semaphore (Mutex)** | Semaphore that takes values 0 or 1. Used for mutual exclusion.          |
| **wait() / P()**             | Decrements the semaphore. If it becomes 0, other processes are blocked. |
| **signal() / V()**           | Increments the semaphore or wakes up a waiting process.                 |
| **Critical Section**         | The part of the code where shared resources are accessed.               |

---

### 🧑‍💻 Author

**Shourov Roy**
📧 [shourovcsesust@gmail.com](mailto:your-email@example.com)
🌐 [https://github.com/SRmohakal](https://github.com/your-username)

---

### 🪪 License

This project is licensed under the **MIT License** — feel free to use, modify, and share it for learning purposes.

---
