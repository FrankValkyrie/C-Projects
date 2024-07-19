#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#define MAX_ATTEMPTS 5
//Franklin Cerball
class HangmanGame {
private:
    std::string secretWord;
    std::string currentWord;
    int attemptsLeft;

public:
    HangmanGame() {
        srand(static_cast<unsigned int>(time(nullptr)));
        secretWord = getRandomWord();
        currentWord = std::string(secretWord.length(), '_');
        attemptsLeft = MAX_ATTEMPTS;
    }

    void play() {
        std::cout << "Welcome to Hangman!" << std::endl;
        std::cout << "Category: Sports" << std::endl;
        std::cout << "You have " << attemptsLeft << " attempts to guess the sport name." << std::endl;

        while (attemptsLeft > 0) {
            displayGameInfo();
            char guess;
            std::cout << "Guess a letter: ";
            std::cin >> guess;

            if (std::isalpha(guess)) {
                guess = std::tolower(guess);
                if (alreadyGuessed(guess)) {
                    std::cout << "You've already guessed that letter." << std::endl;
                } else {
                    bool correctGuess = updateCurrentWord(guess);
                    if (correctGuess) {
                        std::cout << "Good guess!" << std::endl;
                        if (currentWord == secretWord) {
                            displayGameInfo();
                            std::cout << "Nice! You guessed the word: " << secretWord << std::endl;
                            return;
                        }
                    } else {
                        std::cout << "Incorrect guess." << std::endl;
                        attemptsLeft--;
                    }
                }
            } else {
                std::cout << "Invalid input. Please enter a valid letter." << std::endl;
            }
        }

        std::cout << "Out of attempts! The word was: " << secretWord << std::endl;
    }

private:
    std::string getRandomWord() {
        // Replace with your list of words i.e. sports
        std::vector<std::string> words = {"basketball", "soccer", "football", "tennis", "swimming"};
        int randomIndex = rand() % words.size();
        return words[randomIndex];
    }

    bool alreadyGuessed(char letter) {
        return currentWord.find(letter) != std::string::npos;
    }

    bool updateCurrentWord(char guess) {
        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                currentWord[i] = guess;
                correctGuess = true;
            }
        }
        return correctGuess;
    }

    void displayGameInfo() {
        std::cout << "Current word: " << currentWord << std::endl;
        std::cout << "Attempts left: " << attemptsLeft << std::endl;
    }
};

int main() {
    HangmanGame game;
    game.play();
    return 0;
}