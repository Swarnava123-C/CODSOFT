import random

# Function to determine the winner
def determine_winner(user, computer):
    if user == computer:
        return "🤝 It's a tie!"
    elif (user == "rock" and computer == "scissors") or \
         (user == "scissors" and computer == "paper") or \
         (user == "paper" and computer == "rock"):
        return "🎉 You win!"
    else:
        return "😢 You lose!"

# Function to play the game
def play_game():
    user_score = 0
    computer_score = 0

    while True:
        print("\n✊ Rock-Paper-Scissors Game ✋✂️")
        print("Choose: rock, paper, or scissors (or type 'exit' to quit)")

        # Get user input
        user_choice = input("Your choice: ").lower()

        if user_choice == "exit":
            print("\nFinal Score:")
            print(f"🏆 You: {user_score} | 🤖 Computer: {computer_score}")
            print("👋 Thanks for playing! Have a great day!")
            break

        # Validate user input
        if user_choice not in ["rock", "paper", "scissors"]:
            print("❌ Invalid choice! Please enter rock, paper, or scissors.")
            continue

        # Computer makes a choice
        computer_choice = random.choice(["rock", "paper", "scissors"])

        # Display choices
        print(f"🤖 Computer chose: {computer_choice}")

        # Determine winner
        result = determine_winner(user_choice, computer_choice)
        print(result)

        # Update scores
        if "win" in result:
            user_score += 1
        elif "lose" in result:
            computer_score += 1

        # Display current score
        print(f"🏆 Score: You - {user_score} | 🤖 Computer - {computer_score}")

# Run the game
if __name__ == "__main__":
    play_game()
# Output:
# ✊ Rock-Paper-Scissors Game ✋✂️
# Choose: rock, paper, or scissors (or type 'exit' to quit)
# Your choice: rock
# 🤖 Computer chose: scissors
# 🎉 You win!
# 🏆 Score: You - 1 | 🤖 Computer - 0
# ✊ Rock-Paper-Scissors Game ✋✂️
# Choose: rock, paper, or scissors (or type 'exit' to quit)
# Your choice: paper
# 🤖 Computer chose: paper
# 🤝 It's a tie!
# 🏆 Score: You - 1 | 🤖 Computer - 0
# ✊ Rock-Paper-Scissors Game ✋✂️
# Choose: rock, paper, or scissors (or type 'exit' to quit)
# Your choice: exit
# Final Score:
# 🏆 You: 1 | 🤖 Computer: 0
# 👋 Thanks for playing! Have a great day!
