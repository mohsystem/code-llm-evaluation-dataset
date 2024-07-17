import random

class Master:
    def __init__(self, secret: str):
        self.secret = secret
        self.guess_count = 0
    
    def guess(self, word: str) -> int:
        self.guess_count += 1
        if word not in words:
            return -1
        return sum(s == w for s, w in zip(self.secret, word))

def findSecretWord(words, master):
    def match(word1, word2):
        return sum(1 for x, y in zip(word1, word2) if x == y)
    
    attempts = 0
    while attempts < allowedGuesses:
        guess_word = random.choice(words)
        matches = master.guess(guess_word)
        if matches == 6:
            print("You guessed the secret word correctly.")
            return
        words = [w for w in words if match(w, guess_word) == matches]
        attempts += 1
    print("Either you took too many guesses, or you did not find the secret word.")

secret = "hamada"
words = ["hamada","khaled"]
allowedGuesses = 10
master = Master(secret)
findSecretWord(words, master)