class ZeroEvenOdd {
public:
  ZeroEvenOdd(int n) : n(n), count(0) {}

  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this] { return count % 2 == 0; });
      printNumber(0);
      count++;
      if (count % 2 == 1)
        cv.notify_one();
      else
        cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this] { return count % 2 == 1; });
      printNumber(i);
      count++;
      if (count % 2 == 1)
        cv.notify_one();
      else
        cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this] { return count % 2 == 1; });
      printNumber(i);
      count++;
      if (count % 2 == 1)
        cv.notify_one();
      else
        cv.notify_all();
    }
  }

private:
  int n;
  int count;
  mutex m;
  condition_variable cv;
};