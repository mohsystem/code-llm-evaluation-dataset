
class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        n = 0
        while n < 6:
            count = [Counter(w[i] for w in words) for i in range(6)]
            guess = max(words, key=lambda w: sum(count[i][c] for i, c in enumerate(w)))
            n = master.guess(guess)
            words = [w for w in words if sum(a == b for a, b in zip(guess, w)) == n]
