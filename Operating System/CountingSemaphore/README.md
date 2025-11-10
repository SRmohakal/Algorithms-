## 🧵 Counting Semaphore Simulation in Python

This project demonstrates the working of a **Counting Semaphore** using Python.
A semaphore is a synchronization mechanism used to control access to shared resources in a concurrent system such as a multitasking operating system.

This implementation simulates multiple **processes** trying to enter a **critical section**.
The counting semaphore ensures that only a limited number of processes (defined by its initial value) can enter the critical section at a time, while others wait in a queue.

---

### ⚙️ Features

* Simulates multiple processes with states: `inactive`, `Running`, `Blocked`, and `Ready`.
* Demonstrates the **wait (P)** and **signal (V)** operations of semaphores.
* Prints clear logs showing which process enters, waits, or gets unblocked.
* Uses Python classes and queues (`collections.deque`) to represent semaphore behavior.
* Easy to modify — simply change the initial semaphore value to control concurrency.

---

### 🧩 Code Structure

```
CountingSemaphore/
│
├── semaphore.py        # Main Python script (contains Process & CountingSemaphore classes)
└── README.md           # Project documentation
```

---

### 🚀 How to Run

1. **Clone the repository**

   ```bash
   git clone https://github.com/<SRmohakal>/CountingSemaphore.git
   cd CountingSemaphore
   ```

2. **Run the program**

   ```bash
   python semaphore.py
   ```

3. **Observe the output**
   You’ll see logs showing which processes enter the critical section, get blocked, or are released.

---

### 🧠 Sample Output

```
Process-1(inactive) tries to enter critical section.
Process-1(Running) entered critical section. (Available slots: 1)
Process-2(inactive) tries to enter critical section.
Process-2(Running) entered critical section. (Available slots: 0)
Process-3(inactive) tries to enter critical section.
Process-3(Blocked) is blocked and added to queue. (Queue size: 1)
Process-4(inactive) tries to enter critical section.
Process-4(Blocked) is blocked and added to queue. (Queue size: 2)
Process-3(Ready) is unblocked and ready to enter critical section.
Process-4(Ready) is unblocked and ready to enter critical section.
No process is waiting. Slot freed. (Available slots: 1)
```

---

### 🧮 Concept Recap

| Type                         | Description                                       | Typical Use                                                        |
| ---------------------------- | ------------------------------------------------- | ------------------------------------------------------------------ |
| **Binary Semaphore (Mutex)** | Allows only **one** process in critical section   | Mutual exclusion                                                   |
| **Counting Semaphore**       | Allows **multiple** processes up to a fixed count | Managing a pool of limited resources (e.g., printers, connections) |

---

### 🧑‍💻 Author

**Shourov Roy**
📧 [[shourovcsesust@gmail.com](mailto:your-email@example.com)]
🌐 [https://github.com/SRmohakal](https://github.com/your-username)

---

### 🪪 License

This project is released under the **MIT License** — free to use, modify, and distribute.

---
