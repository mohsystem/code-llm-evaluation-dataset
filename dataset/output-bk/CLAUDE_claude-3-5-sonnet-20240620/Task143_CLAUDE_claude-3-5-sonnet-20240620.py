
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def main():
    input_str = input("Enter integers separated by spaces: ")
    arr = list(map(int, input_str.split()))
    bubble_sort(arr)
    print("Sorted array:", " ".join(map(str, arr)))

if __name__ == "__main__":
    main()
