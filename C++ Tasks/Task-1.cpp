#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Seed for random number generation
    int randomNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    std::cout << "Guess the number (between 1 and 100): ";

    while (true) {
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again: ";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
            break;
        }
    }

    return 0;
}
// Output:
/* Guess the number (between 1 and 100): 45
 Congratulations! You guessed the correct number: 45

 Guess the number (between 1 and 100): 56
 Too low! Try again: */
