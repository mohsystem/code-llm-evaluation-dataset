class ProductOfNumbers:
    def __init__(self):
        self.nums = []
        self.prefix_products = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.nums = []
            self.prefix_products = [1]
        else:
            self.nums.append(num)
            self.prefix_products.append(self.prefix_products[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.prefix_products):
            return 0
        return self.prefix_products[-1] // self.prefix_products[-1 - k]

# Example usage
productOfNumbers = ProductOfNumbers()
productOfNumbers.add(3)
productOfNumbers.add(0)
productOfNumbers.add(2)
productOfNumbers.add(5)
productOfNumbers.add(4)
print(productOfNumbers.getProduct(2))  # 20
print(productOfNumbers.getProduct(3))  # 40
print(productOfNumbers.getProduct(4))  # 0
productOfNumbers.add(8)
print(productOfNumbers.getProduct(2))  # 32