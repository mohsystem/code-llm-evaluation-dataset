int getSum(int a, int b) {
  return (a == b) ? a : (a + b) * (abs(a - b) + 1) / 2;
}