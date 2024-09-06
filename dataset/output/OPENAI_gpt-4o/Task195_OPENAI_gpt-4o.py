class MedianFinder:
    def __init__(self):
        self.nums = []
    
    def addNum(self, num: int) -> None:
        from bisect import insort
        insort(self.nums, num)
    
    def findMedian(self) -> float:
        n = len(self.nums)
        if n % 2 == 1:
            return float(self.nums[n // 2])
        else:
            return (self.nums[n // 2 - 1] + self.nums[n // 2]) / 2.0

medianFinder = MedianFinder()
medianFinder.addNum(1)
medianFinder.addNum(2)
print(medianFinder.findMedian())  # 1.5
medianFinder.addNum(3)
print(medianFinder.findMedian())  # 2.0