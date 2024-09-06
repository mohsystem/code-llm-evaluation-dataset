import heapq

class MedianFinder:
    def __init__(self):
        self.small = []  # max-heap (store smaller half)
        self.large = []  # min-heap (store larger half)

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)  # Add to small heap (negated for max-heap)

        # Balance heaps (ensure small heap size is at most 1 greater than large heap)
        if len(self.small) > len(self.large) + 1:
            heapq.heappush(self.large, -heapq.heappop(self.small))

        # Adjust heaps if an element in small heap is larger than an element in large heap
        if self.small and self.large and -self.small[0] > self.large[0]:
            heapq.heappush(self.large, -heapq.heappop(self.small))
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        else:
            return (-self.small[0] + self.large[0]) / 2