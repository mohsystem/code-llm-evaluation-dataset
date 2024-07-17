import java.util.ArrayList;
import java.util.List;

class ProductOfNumbers {
    private List<Integer> nums;
    private List<Integer> prefixProducts;

    public ProductOfNumbers() {
        nums = new ArrayList<>();
        prefixProducts = new ArrayList<>();
        prefixProducts.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            nums.clear();
            prefixProducts.clear();
            prefixProducts.add(1);
        } else {
            nums.add(num);
            prefixProducts.add(prefixProducts.get(prefixProducts.size() - 1) * num);
        }
    }

    public int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        }
        return prefixProducts.get(prefixProducts.size() - 1) / prefixProducts.get(prefixProducts.size() - 1 - k);
    }

    public static void main(String[] args) {
        ProductOfNumbers productOfNumbers = new ProductOfNumbers();
        productOfNumbers.add(3);
        productOfNumbers.add(0);
        productOfNumbers.add(2);
        productOfNumbers.add(5);
        productOfNumbers.add(4);
        System.out.println(productOfNumbers.getProduct(2));  // 20
        System.out.println(productOfNumbers.getProduct(3));  // 40
        System.out.println(productOfNumbers.getProduct(4));  // 0
        productOfNumbers.add(8);
        System.out.println(productOfNumbers.getProduct(2));  // 32
    }
}