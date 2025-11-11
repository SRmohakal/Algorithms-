import threading
import time
import random

class DiningPhilosophers:
    def __init__(self, n=5):
        self.n = n
        self.forks = [threading.Semaphore(1) for _ in range(n)]
        self.mutex = threading.Semaphore(1)

    def wants_to_eat(self, philosopher):
        left = philosopher
        right = (philosopher + 1) % self.n

        with self.mutex:
            print(f"Philosopher {philosopher} is hungry.")

        # Pick forks (order matters to avoid deadlock)
        first, second = (left, right) if philosopher % 2 == 0 else (right, left)

        self.forks[first].acquire()
        self.forks[second].acquire()

        with self.mutex:
            print(f"Philosopher {philosopher} starts eating 🍝")

        time.sleep(random.uniform(1, 3))

        with self.mutex:
            print(f"Philosopher {philosopher} finishes eating and starts thinking 💭")

        self.forks[first].release()
        self.forks[second].release()

def philosopher_thread(philosopher, dining_table):
    while True:
        time.sleep(random.uniform(1, 3))
        dining_table.wants_to_eat(philosopher)

if __name__ == "__main__":
    dining_table = DiningPhilosophers(5)
    philosophers = [threading.Thread(target=philosopher_thread, args=(i, dining_table)) for i in range(5)]

    for p in philosophers:
        p.start()
