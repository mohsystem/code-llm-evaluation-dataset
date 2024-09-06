from threading import Semaphore, Barrier, Thread

class H2O:
    def __init__(self):
        self.hydrogen_semaphore = Semaphore(2)
        self.oxygen_semaphore = Semaphore(0)
        self.barrier = Barrier(3)

    def hydrogen(self, releaseHydrogen):
        self.hydrogen_semaphore.acquire()
        self.barrier.wait()
        releaseHydrogen()
        self.hydrogen_semaphore.release()
        self.oxygen_semaphore.release()
       
    def oxygen(self, releaseOxygen):
        self.oxygen_semaphore.acquire()
        self.barrier.wait()
        releaseOxygen()

# Simulation
def releaseHydrogen():
    print("H", end='')

def releaseOxygen():
    print("O", end='')

water = "HOH"
h2o = H2O()
threads = []

for molecule in water:
    if molecule == 'H':
        threads.append(Thread(target=h2o.hydrogen, args=(releaseHydrogen,)))
    else:
        threads.append(Thread(target=h2o.oxygen, args=(releaseOxygen,)))

for t in threads:
    t.start()
for t in threads:
    t.join()