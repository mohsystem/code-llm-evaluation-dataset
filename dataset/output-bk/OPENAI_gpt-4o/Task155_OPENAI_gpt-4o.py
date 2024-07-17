import ctypes

class JavaHeapSort:
    # Java code as a string
    java_code = """
    import java.util.Scanner;

    public class JavaHeapSort {
        public void sort(int arr[]) {
            int n = arr.length;
            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);
            for (int i = n - 1; i >= 0; i--) {
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                heapify(arr, i, 0);
            }
        }
        
        void heapify(int arr[], int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;
            if (largest != i) {
                int swap = arr[i];
                arr[i] = arr[largest];
                arr[largest] = swap;
                heapify(arr, n, largest);
            }
        }
        
        public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter number of elements in array:");
            int n = sc.nextInt();
            int arr[] = new int[n];
            System.out.println("Enter elements:");
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            JavaHeapSort ob = new JavaHeapSort();
            ob.sort(arr);
            System.out.println("Sorted array is:");
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
        }
    }
    """