
def odd_or_even(arr):
    if not arr:
        return "even"
    return "even" if sum(arr) % 2 == 0 else "odd"

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input("Enter the elements separated by space: ").split()))
    print(odd_or_even(arr))
