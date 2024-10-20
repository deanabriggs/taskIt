// Libraries
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

// Create a new Class for Tasks
class Task
{
public:
    // Attributes of the class
    string customer;
    string description;
    string department;
    string type;
    int priority;
    bool completed;

    // Constructor
    Task(string cust, string desc, string dept, string type, int priority = 1, bool done = false)
        : customer(cust), description(desc), department(dept), type(type), priority(priority), completed(done) {}

    // Method to Display Task
    void displayTask()
    {
        string done = completed ? "[X]" : "[ ]";
        cout << done << " " << priority << " - " << type << " - " << customer << " - " << department << " - " << description << "\n";
    }

    // Method to Mark Task Completed
    void markComplete()
    {
        completed = true;
    }
};

// Creates this pre-defined list of tasks for a specific customer
void createPreinstallTasks(vector<Task> &taskList, string cust)
{
    taskList.push_back(Task(cust, "Confo Email", "Admin", "Pre"));
    taskList.push_back(Task(cust, "Order Equip", "Admin", "Pre"));
    taskList.push_back(Task(cust, "Invoice Down Payment", "Accounting", "Pre"));
    taskList.push_back(Task(cust, "Collect Down Payment", "Accounting", "Pre"));
    taskList.push_back(Task(cust, "Prep Install Paperwork", "Admin", "Pre"));
    taskList.push_back(Task(cust, "Appointment Reminder", "Admin", "Pre"));
    taskList.push_back(Task(cust, "Project Review", "Tech", "Pre"));
    taskList.push_back(Task(cust, "Pick Up Equip", "Tech", "Pre"));

    cout << "Pre-install tasks have been added for " << cust << "\n\n";
}

// Creates this pre-defined list of tasks for a specific customer
void createPostinstallTasks(vector<Task> &taskList, string cust)
{
    taskList.push_back(Task(cust, "Customer Training", "Tech", "Post"));
    taskList.push_back(Task(cust, "Complete Install Docs", "Tech", "Post"));
    taskList.push_back(Task(cust, "Invoice for Final Payment", "Accounting", "Post"));
    taskList.push_back(Task(cust, "Collect Final Payment", "Tech", "Post"));
    taskList.push_back(Task(cust, "Setup Re-occuring Payment Schedule", "Accounting", "Post"));
    taskList.push_back(Task(cust, "Customer Satisfaction Call", "Admin", "Post"));
    taskList.push_back(Task(cust, "Request a Good Review", "Admin", "Post"));
    taskList.push_back(Task(cust, "Update Database and Files", "Admin", "Post"));

    cout << "Post-install tasks have been added for " << cust << "\n\n";
}

// Prompts for input to create a custom task for a specific customer
void createCustomTask(vector<Task> &taskList, string cust)
{
    string desc;
    cout << "Task description: ";
    getline(cin, desc);

    string type;
    cout << "Type of task (pre/post/other): ";
    getline(cin, type);

    string dept;
    cout << "Department responsibility: ";
    getline(cin, dept);

    taskList.push_back(Task(cust, desc, dept, type));
    cout << "The custom task has been added for " << cust << "\n\n";
}

// Prints the entire task list to the terminal
void printTaskList(vector<Task> &taskList)
{
    "\n --- TASK LIST ---\n";
    for (size_t i = 0; i < taskList.size(); ++i)
    {
        cout << i + 1 << ". ";
        taskList[i].displayTask();
    }
}

// Updates a specific task from a list as complete
void markTaskComplete(vector<Task> &taskList, int taskIndex)
{
    taskList[taskIndex].markComplete();
}

// Saves the entire list to a file (will override an existing list with the same name)
void saveToFile(const vector<Task> &taskList, const string &filename)
{
    ofstream file(filename); // open file

    for (const Task &task : taskList)
    {
        file << (task.completed ? "[X]" : "[ ]") << " "
             << task.priority << " - "
             << task.type << " - "
             << task.customer << " - "
             << task.department << " - "
             << task.description << "\n";
    }

    file.close();
    cout << "Tasks have been saved to " << filename << ".\n\n";
}