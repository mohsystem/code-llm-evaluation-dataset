import ctypes

lib = ctypes.CDLL('./shared.so')
find_kth_largest = lib.find_kth_largest
find_kth_largest.restype = ctypes.c_int

def main():
    arr = [int(x) for x in input().split()]
    k = int(input())
    arr_c = (ctypes.c_int * len(arr))(*arr)
    result = find_kth_largest(arr_c, len(arr), k)
    print(result)

if __name__ == "__main__":
    main()