#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Master {
public:
    Master(const std::string& secret) : secret(secret), guess_count(0) {}

    int guess(const std::string& word) {
        guess_count++;
        if (std::find(words.begin(), words.end(), word) == words.end()) {
            return -1;
        }
        int matches = 0;
        for (size_t i = 0; i < secret.size(); ++i) {
            if (secret[i] == word[i]) {
                matches++;
            }
        }
        return matches;
    }
private:
    std::string secret;
    int guess_count;
};

int match(const std::string& word1, const std::string& word2) {
    int matches = 0;
    for (size_t i = 0; i < word1.size(); ++i) {
        if (word1[i] == word2[i]) {
            matches++;
        }
    }
    return matches;
}

void findSecretWord(std::vector<std::string>& words, Master& master, int allowedGuesses) {
    int attempts = 0;
    srand(time(0));
    while (attempts < allowedGuesses) {
        std::string guess_word = words[rand() % words.size()];
        int matches = master.guess(guess_word);
        if (matches == 6) {
            std::cout << "You guessed the secret word correctly." << std::endl;
            return;
        }
        std::vector<std::string> filtered_words;
        for (const auto& word : words) {
            if (match(word, guess_word) == matches) {
                filtered_words.push_back(word);
            }
        }
        words = filtered_words;
        attempts++;
    }
    std::cout << "Either you took too many guesses, or you did not find the secret word." << std::endl;
}

int main() {
    std::string secret = "hamada";
    std::vector<std::string> words = {"hamada", "khaled"};
    int allowedGuesses = 10;
    Master master(secret);
    findSecretWord(words, master, allowedGuesses);
    return 0;
}