import threading

class ZeroEvenOdd:
  def __init__(self, n):
    self.n = n
    self.count = 0
    self.z = threading.Semaphore(1)
    self.e = threading.Semaphore(0)
    self.o = threading.Semaphore(0)

  def zero(self, printNumber):
    for i in range(self.n):
      self.z.acquire()
      printNumber(0)
      self.count += 1
      if self.count % 2 == 0:
        self.e.release()
      else:
        self.o.release()

  def even(self, printNumber):
    for i in range(2, self.n+1, 2):
      self.e.acquire()
      printNumber(i)
      self.z.release()

  def odd(self, printNumber):
    for i in range(1, self.n+1, 2):
      self.o.acquire()
      printNumber(i)
      self.z.release()