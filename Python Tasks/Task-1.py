# Simple To-Do List (No File Storage)
tasks = []

def view_tasks():
    if not tasks:
        print("No tasks available.")
        return
    print("\n📋 To-Do List:")
    for index, task in enumerate(tasks, start=1):
        status = "[✔]" if task["completed"] else "[ ]"
        print(f"{index}. {status} {task['description']}")

def add_task():
    description = input("Enter task description: ").strip()
    if description:
        tasks.append({"description": description, "completed": False})
        print("✅ Task added successfully!")

def mark_completed():
    view_tasks()
    if not tasks:
        return
    try:
        index = int(input("Enter task number to mark as completed: ")) - 1
        if 0 <= index < len(tasks):
            tasks[index]["completed"] = True
            print("✅ Task marked as completed!")
        else:
            print("❌ Invalid task number!")
    except ValueError:
        print("❌ Please enter a valid number.")

def remove_task():
    view_tasks()
    if not tasks:
        return
    try:
        index = int(input("Enter task number to remove: ")) - 1
        if 0 <= index < len(tasks):
            removed_task = tasks.pop(index)
            print(f"🗑️ Task '{removed_task['description']}' removed!")
        else:
            print("❌ Invalid task number!")
    except ValueError:
        print("❌ Please enter a valid number.")

def main():
    while True:
        print("\n📌 To-Do List Menu:")
        print("1️⃣ Add Task")
        print("2️⃣ View Tasks")
        print("3️⃣ Mark Task as Completed")
        print("4️⃣ Remove Task")
        print("5️⃣ Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            add_task()
        elif choice == "2":
            view_tasks()
        elif choice == "3":
            mark_completed()
        elif choice == "4":
            remove_task()
        elif choice == "5":
            print("👋 Exiting... Have a productive day!")
            break
        else:
            print("❌ Invalid choice! Please enter a number between 1-5.")

if __name__ == "__main__":
    main()
# Output:
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 1
# Enter task description: Swarnava
# ✅ Task added successfully!
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 1
# Enter task description: Malakar
# ✅ Task added successfully!
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 2
# 📋 To-Do List:
# 1. [ ] Swarnava
# 2. [ ] Malakar
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 3
# 📋 To-Do List:
# 1. [ ] Swarnava
# 2. [ ] Malakar
# Enter task number to mark as completed: 2
# ✅ Task marked as completed!
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 4
#📋 To-Do List:
# 1. [ ] Swarnava
# 2. [✔] Malakar
# Enter task number to remove: 2
# 🗑️ Task 'Malakar' removed!
# 📌 To-Do List Menu:
# 1️⃣ Add Task
# 2️⃣ View Tasks
# 3️⃣ Mark Task as Completed
# 4️⃣ Remove Task
# 5️⃣ Exit
# Enter your choice: 5
# 👋 Exiting... Have a productive day!

