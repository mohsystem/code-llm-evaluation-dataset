import heapq

class MedianFinder:
    def __init__(self):
        self.small = []  # max-heap (left side)
        self.large = []  # min-heap (right side)

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)  # Add to max-heap (negate for max-heap property)

        # Balance the heaps: ensure len(small) - 1 <= len(large)
        if len(self.small) > len(self.large) + 1:
            val = -heapq.heappop(self.small) 
            heapq.heappush(self.large, val)

        # Further balancing: ensure max(small) <= min(large)
        if self.small and self.large and -self.small[0] > self.large[0]:
            val_small = -heapq.heappop(self.small)
            val_large = heapq.heappop(self.large)
            heapq.heappush(self.small, -val_large)
            heapq.heappush(self.large, val_small)

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0] 
        else:
            return (-self.small[0] + self.large[0]) / 2