import threading
import time
from collections import deque

class Process:
    def __init__(self, pid):
        self.pid = pid
        self.state = "Inactive"

    def __repr__(self):
        return f"Process-{self.pid} is ({self.state})."

class Semaphore:
    def __init__(self, value):
        self.value = value
        self.queue = deque()
    
    def wait(self, process):
        print(f"{process} is requesting lock.")
        if self.value == 1:
            self.value = 0
            process.state = "Running"
            print(f"{process} is acquired lock.")
        else:
            process.state = "Blocked"
            self.queue.append(process)
            print(f"{process} is bocked. Mutex is locked.")
    
    def signal(self):
        if len(self.queue) == 0:
            self.value = 1
            print(f"Mutex is realesed.")
        else:
            p = self.queue.popleft()
            p.state = "Ready"
            print(f"{p} is unblocked and ready for lock.")



if __name__ == "__main__":
    p1 = Process(1)
    p2 = Process(2)
    p3 = Process(3)

    #here 1 ensure binary semaphore
    cnt = Semaphore(1)
    cnt.wait(p1)
    cnt.wait(p2)
    cnt.wait(p3)

    cnt.signal()
    cnt.signal()
    cnt.signal()
