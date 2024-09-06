
class Master:
    def __init__(self, secret):
        self.secret = secret
        self.guesses = 0

    def guess(self, word):
        self.guesses += 1
        return sum(a == b for a, b in zip(self.secret, word))

def findSecretWord(words, master):
    n = len(words)
    for i in range(10):
        guess = words[n // 2]
        matches = master.guess(guess)
        if matches == 6:
            return
        words = [w for w in words if sum(a == b for a, b in zip(guess, w)) == matches]
        n = len(words)

# Example usage
secret = "acckzz"
words = ["acckzz", "ccbazz", "eiowzz", "abcczz"]
master = Master(secret)
findSecretWord(words, master)
print("You guessed the secret word correctly." if master.guesses <= 10 else "Either you took too many guesses, or you did not find the secret word.")
