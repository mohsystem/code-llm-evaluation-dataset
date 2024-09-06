# Python code
class Solution:
    def findSecretWord(self, words, master):
        def get_matches(a, b):
            return sum(x == y for x, y in zip(a, b))

        def find_secret_word(possible_words):
            if not possible_words:
                return
            if len(possible_words) == 1:
                return master.guess(possible_words[0])

            # Choose a word with the least number of matches with other words
            word_count = [0] * len(possible_words)
            for i in range(len(possible_words)):
                for j in range(i + 1, len(possible_words)):
                    matches = get_matches(possible_words[i], possible_words[j])
                    word_count[i] += matches
                    word_count[j] += matches
            min_count = min(word_count)
            guess = possible_words[word_count.index(min_count)]

            matches = master.guess(guess)
            if matches == 6:
                return

            # Filter out words that don't match the number of matches with the guess
            possible_words = [word for word in possible_words if get_matches(word, guess) == matches]
            return find_secret_word(possible_words)

        find_secret_word(words)