import ctypes

class Sorting:
    @staticmethod
    def heapify(arr, n, i):
        largest = i 
        l = 2 * i + 1     
        r = 2 * i + 2     

        if l < n and arr[i] < arr[l]:
            largest = l

        if r < n and arr[largest] < arr[r]:
            largest = r

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            Sorting.heapify(arr, n, largest)

    @staticmethod
    def heapSort(arr):
        n = len(arr)
        for i in range(n // 2 - 1, -1, -1):
            Sorting.heapify(arr, n, i)
        for i in range(n-1, 0, -1):
            arr[i], arr[0] = arr[0], arr[i]
            Sorting.heapify(arr, i, 0)

class Main:
    @staticmethod
    def main():
        arr = [4, 10, 3, 5, 1]
        Sorting.heapSort(arr)
        print("Sorted array is:", arr)

Main.main()