class ProductOfNumbers:
    def __init__(self):
        self.products = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.products = [1]
        else:
            self.products.append(self.products[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.products):
            return 0
        return self.products[-1] // self.products[-k-1]

# Example usage:
productOfNumbers = ProductOfNumbers()
productOfNumbers.add(3)
productOfNumbers.add(0)
productOfNumbers.add(2)
productOfNumbers.add(5)
productOfNumbers.add(4)
print(productOfNumbers.getProduct(2))  # return 20
print(productOfNumbers.getProduct(3))  # return 40
print(productOfNumbers.getProduct(4))  # return 0
productOfNumbers.add(8)
print(productOfNumbers.getProduct(2))  # return 32