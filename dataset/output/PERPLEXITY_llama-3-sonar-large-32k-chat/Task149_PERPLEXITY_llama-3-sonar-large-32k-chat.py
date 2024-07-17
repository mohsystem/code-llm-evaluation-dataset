class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def peek(self):
        if len(self.queue) < 1:
            return None
        return self.queue[0]

q = Queue()
q.enqueue("Apple")
q.enqueue("Banana")
q.enqueue("Cherry")
print(q.dequeue())  # Apple
print(q.peek())  # Banana