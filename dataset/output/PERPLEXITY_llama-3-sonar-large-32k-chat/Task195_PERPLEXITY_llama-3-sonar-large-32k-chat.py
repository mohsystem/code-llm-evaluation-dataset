class MedianFinder:

    def __init__(self):
        self.lower = []
        self.higher = []

    def addNum(self, num: int) -> None:
        if not self.lower or num <= -self.lower[0]:
            heapq.heappush(self.lower, -num)
        else:
            heapq.heappush(self.higher, num)
        
        if len(self.lower) > len(self.higher) + 1:
            heapq.heappush(self.higher, -heapq.heappop(self.lower))
        elif len(self.higher) > len(self.lower):
            heapq.heappush(self.lower, -heapq.heappop(self.higher))

    def findMedian(self) -> float:
        if len(self.lower) == len(self.higher):
            return (-self.lower[0] + self.higher[0]) / 2
        else:
            return -self.lower[0]