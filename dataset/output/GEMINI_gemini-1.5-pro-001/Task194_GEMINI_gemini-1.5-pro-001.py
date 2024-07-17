# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        n = len(words)
        self.H = [[0] * n for _ in range(n)]
        for i, w1 in enumerate(words):
            for j in range(i, n):
                w2 = words[j]
                matches = sum(a == b for a, b in zip(w1, w2))
                self.H[i][j] = self.H[j][i] = matches

        possible = list(range(n))
        matches = 0
        while possible and master.guess(words[possible[0]]) != 6:
            guess = random.choice(possible)
            matches = master.guess(words[guess])
            possible = [j for j in possible if self.H[guess][j] == matches]