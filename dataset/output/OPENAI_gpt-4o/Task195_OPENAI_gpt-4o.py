import heapq

class MedianFinder:
    def __init__(self):
        self.small = []
        self.large = []
        
    def addNum(self, num: int) -> None:
        heapq.heappush(self.large, -heapq.heappushpop(self.small, -num))
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))
            
    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2

# Example Usage
medianFinder = MedianFinder()
medianFinder.addNum(1)    
medianFinder.addNum(2)
print(medianFinder.findMedian()) # Output: 1.5
medianFinder.addNum(3)
print(medianFinder.findMedian()) # Output: 2.0