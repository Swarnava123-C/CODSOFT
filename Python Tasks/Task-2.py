# Function to perform addition
def add(x, y):
    return x + y

# Function to perform subtraction
def subtract(x, y):
    return x - y

# Function to perform multiplication
def multiply(x, y):
    return x * y

# Function to perform division
def divide(x, y):
    if y == 0:
        return "❌ Error: Division by zero!"
    return x / y

# Main calculator function
def calculator():
    while True:
        # Display menu options
        print("\n🖩 Simple Calculator")
        print("1️⃣ Addition (+)")
        print("2️⃣ Subtraction (-)")
        print("3️⃣ Multiplication (×)")
        print("4️⃣ Division (÷)")
        print("5️⃣ Exit")

        # Get user choice
        choice = input("Enter your choice (1-5): ")

        # Exit condition
        if choice == "5":
            print("👋 Exiting calculator. Have a great day!")
            break

        # Check if the choice is valid
        if choice in ["1", "2", "3", "4"]:
            try:
                # Get input numbers from the user
                num1 = float(input("Enter first number: "))
                num2 = float(input("Enter second number: "))
            except ValueError:
                print("❌ Invalid input! Please enter numbers only.")
                continue

            # Perform the selected operation
            if choice == "1":
                print(f"✅ Result: {num1} + {num2} = {add(num1, num2)}")
            elif choice == "2":
                print(f"✅ Result: {num1} - {num2} = {subtract(num1, num2)}")
            elif choice == "3":
                print(f"✅ Result: {num1} × {num2} = {multiply(num1, num2)}")
            elif choice == "4":
                print(f"✅ Result: {num1} ÷ {num2} = {divide(num1, num2)}")
        else:
            print("❌ Invalid choice! Please enter a number between 1-5.")

# Run the calculator
if __name__ == "__main__":
    calculator()
  # Output:
# 🖩 Simple Calculator
# 1️⃣ Addition (+)
# 2️⃣ Subtraction (-)
# 3️⃣ Multiplication (×)
# 4️⃣ Division (÷)
# 5️⃣ Exit
# Enter your choice (1-5): 1
# Enter first number: 1
# Enter second number: 2
# ✅ Result: 1.0 + 2.0 = 3.0
# 🖩 Simple Calculator
# 1️⃣ Addition (+)
# 2️⃣ Subtraction (-)
# 3️⃣ Multiplication (×)
# 4️⃣ Division (÷)
# 5️⃣ Exit
# Enter your choice (1-5): 5
# 👋 Exiting calculator. Have a great day!
