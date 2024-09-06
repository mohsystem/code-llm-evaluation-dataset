class Solution:
    def findSecretWord(self, wordlist, master):
        for _ in range(10):
            guess = random.choice(wordlist)
            res = master.guess(guess)
            if res == 6:
                return
            wordlist = [w for w in wordlist if sum(c1 == c2 for c1, c2 in zip(guess, w)) == res]