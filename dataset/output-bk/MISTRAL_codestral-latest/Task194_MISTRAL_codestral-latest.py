# Python
class Solution:
    def findSecretWord(self, words, master):
        for _ in range(10):
            guess = random.choice(words)
            matches = master.guess(guess)
            if matches == 6:
                return "You guessed the secret word correctly."
            words = [word for word in words if self.match(word, guess, matches)]
        return "Either you took too many guesses, or you did not find the secret word."

    def match(self, word, guess, matches):
        return sum(w == g for w, g in zip(word, guess)) == matches