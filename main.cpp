// This program is to generate a series of tasks after a sale is made. These tasks are used to ensure all steps are followed through the completion of the project.

// Libraries
#include <vector>
#include <iostream>
using namespace std;
// Include Task file to use Class and Functions
#include "Task.cpp"

// Program Menu Options
int menu()
{
    cout << "\n--- TASK ASSIGNMENT PORTAL ---\n";
    cout << "\nChoose an Option: \n";
    cout << "1. Create pre-install tasks \n";
    cout << "2. Create post-install tasks \n";
    cout << "3. Add a custom task \n";
    cout << "4. Mark a task complete \n";
    cout << "5. Print task list \n";
    cout << "6. Save tasks to a file\n";
    cout << "7. Exit \n\n";

    // Variable to store users response
    int response;
    cin >> response;
    return response;
}

// Run the Program and Respond to User Input
int main()
{
    // Save all tasks in this Vector (list)
    vector<Task> taskList;

    int choice;
    do
    {
        choice = menu(); // calls the menu and saves the response to the "choice" variable
        string customer;

        // Only options 1-3 require a customer name for task assignment
        if (choice < 4)
        {
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customer);
        }

        // Run functions based on user input
        switch (choice)
        {
        case 1:
            createPreinstallTasks(taskList, customer);
            break;
        case 2:
            createPostinstallTasks(taskList, customer);
            break;
        case 3:
            createCustomTask(taskList, customer);
            break;
        case 4:
            int selectedTask;
            printTaskList(taskList);
            cout << "\nWhich task was finished? ";
            cin >> selectedTask;
            markTaskComplete(taskList, selectedTask - 1);
            cout << "The task has been marked completed.\n\n";
            break;
        case 5:
            printTaskList(taskList);
            break;
        case 6:
            saveToFile(taskList, "tasks.txt");
            break;
        case 7:
            cout << "\nYou have exited the program.\n\n";
            break;
        default:
            cout << "\nThat is not an option. Try again.\n\n";
        }
    } while (choice != 7);

    return 0;
}