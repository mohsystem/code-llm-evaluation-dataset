class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def delete(self, key):
        current = self.head
        prev = None

        while current and current.data != key:
            prev = current
            current = current.next

        if current is None:
            return

        if prev is None:
            self.head = current.next
        else:
            prev.next = current.next

    def search(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def display(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(current.data)
            current = current.next
        print("LinkedList:", nodes)

if __name__ == "__main__":
    sll = SinglyLinkedList()
    sll.insert(1)
    sll.insert(2)
    sll.insert(3)
    sll.display()
    sll.delete(2)
    sll.display()
    print(sll.search(3))
    print(sll.search(2))