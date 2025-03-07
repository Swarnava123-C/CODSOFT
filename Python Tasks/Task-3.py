import random
import string

# Function to generate a random password
def generate_password(length):
    if length < 4:
        return "❌ Password length should be at least 4 characters!"

    # Define the character set for the password
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

# Main function
def main():
    print("\n🔐 Random Password Generator")

    try:
        length = int(input("Enter desired password length: "))
        password = generate_password(length)
        print(f"✅ Generated Password: {password}")
    except ValueError:
        print("❌ Invalid input! Please enter a valid number.")

# Run the program
if __name__ == "__main__":
    main()
  # Output:
# 🔐 Random Password Generator
# Enter desired password length: 4
# ✅ Generated Password: +Hh=
