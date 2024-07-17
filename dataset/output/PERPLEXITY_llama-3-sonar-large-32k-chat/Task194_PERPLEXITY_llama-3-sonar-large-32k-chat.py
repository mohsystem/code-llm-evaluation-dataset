class Solution:
    def findSecretWord(self, wordlist, master):
        for _ in range(10):
            guess = random.choice(wordlist)
            result = master.guess(guess)
            if result == 6:
                return
            wordlist = [word for word in wordlist if self.match(word, guess) == result]