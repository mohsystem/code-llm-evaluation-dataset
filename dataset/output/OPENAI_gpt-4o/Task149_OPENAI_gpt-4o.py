class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        return None

    def peek(self):
        if not self.is_empty():
            return self.queue[0]
        return None

    def is_empty(self):
        return len(self.queue) == 0

# Test the queue
q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q.peek())  # Output: 1
print(q.dequeue())  # Output: 1
print(q.dequeue())  # Output: 2
q.enqueue(4)
print(q.peek())  # Output: 3
print(q.dequeue())  # Output: 3
print(q.dequeue())  # Output: 4