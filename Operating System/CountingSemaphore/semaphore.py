import threading
import time
from collections import deque

class Process:
    def __init__(self, pid):
        self.pid = pid
        self.state = "inactive"
    
    def __repr__(self):
        return f"Process-{self.pid}({self.state})"

class CountingSemaphore:
    def __init__(self, value):
        self.value = value
        self.queue = deque()
    
    def wait(self, process):
        print(f"{process} tries to enter critical section.")
        if self.value > 0:
            self.value -= 1
            process.state = "Running"
            print(f"{process} entered critical section. (Available slots: {self.value})")
        else:
            process.state = "Blocked"
            self.queue.append(process)
            print(f"{process} is blocked and added to queue. (Queue size: {len(self.queue)})")
    
    def signal(self):
        if len(self.queue) == 0:
            self.value += 1
            print(f"No process is waiting. Slot freed. (Available slots: {self.value})")
        else:
            q = self.queue.popleft()
            q.state = "Ready"
            print(f"{q} is unblocked and ready to enter critical section.")
        

if __name__ == "__main__":
    # Create processes
    p1 = Process(1)
    p2 = Process(2)
    p3 = Process(3)
    p4 = Process(4)

    # Counting semaphore allows 2 processes at once
    sem = CountingSemaphore(2)

    sem.wait(p1)
    sem.wait(p2)
    sem.wait(p3)
    sem.wait(p4)

    sem.signal()
    sem.signal()
    sem.signal()
