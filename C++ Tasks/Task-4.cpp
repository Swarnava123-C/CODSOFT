#include <iostream>
#include <vector>

using namespace std;

// Structure to hold task details
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Vector to store tasks
vector<Task> tasks;

// Function to add a task
void addTask() {
    string taskDesc;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, taskDesc);
    tasks.push_back(Task(taskDesc));
    cout << "Task added successfully!\n";
}

// Function to display tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[✔] " : "[ ] ") << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted() {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }

    int taskNum;
    viewTasks();
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[taskNum - 1].completed = true;
    cout << "Task marked as completed!\n";
}

// Function to remove a task
void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }

    int taskNum;
    viewTasks();
    cout << "Enter the task number to remove: ";
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + taskNum - 1);
    cout << "Task removed successfully!\n";
}

// Function to display menu
void showMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting... Have a productive day!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
//Output:
/*To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 1
Enter the task description: Swarnava
Task added successfully!

To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 1
Enter the task description: Srabanti
Task added successfully!

To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 2

To-Do List:
1. [ ] Swarnava
2. [ ] Srabanti

To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 3

To-Do List:
1. [ ] Swarnava
2. [ ] Srabanti
Enter the task number to mark as completed: 1
Task marked as completed!

To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 4

To-Do List:
1. [✔] Swarnava
2. [ ] Srabanti
Enter the task number to remove: 2
Task removed successfully!

To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Remove Task
5. Exit
Enter your choice: 5
Exiting... Have a productive day! */
