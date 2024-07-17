class ProductOfNumbers {
    private List<Integer> prefixProducts;

    public ProductOfNumbers() {
        prefixProducts = new ArrayList<>();
        prefixProducts.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            prefixProducts = new ArrayList<>();
            prefixProducts.add(1);
        } else {
            prefixProducts.add(prefixProducts.get(prefixProducts.size() - 1) * num);
        }
    }

    public int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        }
        return prefixProducts.get(prefixProducts.size() - 1) / prefixProducts.get(prefixProducts.size() - 1 - k);
    }
}