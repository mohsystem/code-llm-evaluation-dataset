class Master:
    def __init__(self, secret):
        self.secret = secret
        self.guess_count = 0

    def guess(self, word):
        if word not in words:
            return -1
        self.guess_count += 1
        return sum(a == b for a, b in zip(self.secret, word))

def findSecretWord(words, master, allowedGuesses):
    def match_count(w1, w2):
        return sum(a == b for a, b in zip(w1, w2))

    from random import choice
    for _ in range(allowedGuesses):
        guess_word = choice(words)
        matches = master.guess(guess_word)
        if matches == 6:
            print("You guessed the secret word correctly.")
            return
        words = [w for w in words if match_count(w, guess_word) == matches]
    
    print("Either you took too many guesses, or you did not find the secret word.")

# Example Usage
secret = "acckzz"
words = ["acckzz","ccbazz","eiowzz","abcczz"]
allowedGuesses = 10
master = Master(secret)
findSecretWord(words, master, allowedGuesses)