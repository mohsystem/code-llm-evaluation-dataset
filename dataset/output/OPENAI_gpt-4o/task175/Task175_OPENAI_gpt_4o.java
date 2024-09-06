class MountainArray {
    private int[] arr;
    private int calls;

    public MountainArray(int[] arr) {
        this.arr = arr;
        this.calls = 0;
    }

    public int get(int index) {
        calls++;
        if (calls > 100) throw new RuntimeException("Too many calls");
        return arr[index];
    }

    public int length() {
        return arr.length;
    }
}

public class Task175_OPENAI_gpt_4o {
    public static int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeakIndex(mountainArr);
        int index = binarySearch(mountainArr, target, 0, peak, true);
        if (index != -1) return index;
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

    private static int findPeakIndex(MountainArray arr) {
        int left = 0, right = arr.length() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    private static int binarySearch(MountainArray arr, int target, int left, int right, boolean ascending) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int value = arr.get(mid);
            if (value == target) return mid;
            if (value < target) {
                if (ascending) left = mid + 1;
                else right = mid - 1;
            } else {
                if (ascending) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        MountainArray mountainArr = new MountainArray(new int[]{1, 2, 3, 4, 5, 3, 1});
        System.out.println(findInMountainArray(3, mountainArr)); // Output: 2
    }
}