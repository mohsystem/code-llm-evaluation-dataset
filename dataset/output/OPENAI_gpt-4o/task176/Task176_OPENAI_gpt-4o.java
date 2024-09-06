import java.util.ArrayList;
import java.util.List;

class ProductOfNumbers {
    private List<Integer> products;

    public ProductOfNumbers() {
        products = new ArrayList<>();
        products.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            products = new ArrayList<>();
            products.add(1);
        } else {
            products.add(products.get(products.size() - 1) * num);
        }
    }

    public int getProduct(int k) {
        if (k >= products.size()) {
            return 0;
        }
        return products.get(products.size() - 1) / products.get(products.size() - k - 1);
    }

    public static void main(String[] args) {
        ProductOfNumbers productOfNumbers = new ProductOfNumbers();
        productOfNumbers.add(3);
        productOfNumbers.add(0);
        productOfNumbers.add(2);
        productOfNumbers.add(5);
        productOfNumbers.add(4);
        System.out.println(productOfNumbers.getProduct(2));  // return 20
        System.out.println(productOfNumbers.getProduct(3));  // return 40
        System.out.println(productOfNumbers.getProduct(4));  // return 0
        productOfNumbers.add(8);
        System.out.println(productOfNumbers.getProduct(2));  // return 32
    }
}