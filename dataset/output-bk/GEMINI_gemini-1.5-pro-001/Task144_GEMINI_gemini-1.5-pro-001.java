import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MergeSortedArrays {
    public static void main(String[] args) {
        int[] arr1 = {1, 3, 5, 7};
        int[] arr2 = {2, 4, 6, 8};
        List<Integer> mergedArray = mergeSortedArrays(arr1, arr2);
        System.out.println(mergedArray);
    }

    public static List<Integer> mergeSortedArrays(int[] arr1, int[] arr2) {
        List<Integer> merged = new ArrayList<>();
        int i = 0;
        int j = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                merged.add(arr1[i]);
                i++;
            } else {
                merged.add(arr2[j]);
                j++;
            }
        }
        while (i < arr1.length) {
            merged.add(arr1[i]);
            i++;
        }
        while (j < arr2.length) {
            merged.add(arr2[j]);
            j++;
        }
        return merged;
    }
}