
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
        int n = products.size();
        return k < n ? products.get(n - 1) / products.get(n - k - 1) : 0;
    }
}
