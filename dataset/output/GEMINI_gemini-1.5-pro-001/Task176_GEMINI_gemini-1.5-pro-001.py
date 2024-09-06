class ProductOfNumbers:

    def __init__(self):
        self.prefix_products = [1]  # Initialize with 1 for empty subarrays

    def add(self, num: int) -> None:
        if num == 0:
            self.prefix_products = [1]  # Reset prefix products when encountering 0
        else:
            self.prefix_products.append(self.prefix_products[-1] * num)

    def getProduct(self, k: int) -> int:
        n = len(self.prefix_products)
        if k >= n:
            return 0  # Not enough elements for the product
        return self.prefix_products[-1] // self.prefix_products[n - k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)