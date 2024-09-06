import heapq

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small = []  # the larger half of the list, min heap
        self.large = []  # the smaller half of the list, max heap

    def addNum(self, num: int) -> None:
        if len(self.small) == len(self.large):
            heapq.heappush(self.small, -heapq.heappushpop(self.large, num))
        else:
            heapq.heappush(self.large, -heapq.heappushpop(self.small, -num))

    def findMedian(self) -> float:
        if len(self.small) == len(self.large):
            return float(self.small[0] - self.large[0]) / 2.0
        else:
            return float(self.small[0])