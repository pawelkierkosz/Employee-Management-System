#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

// Abstract class Utils with pure virtual methods
class Utils {
public:
    // Pure virtual method to wait for Enter key press
    virtual void waitForEnter() = 0;

    // Pure virtual method to center text in console
    virtual void centerText(const string& text) = 0;
};

class Employee : public Utils {
private:
    string id, firstName, secondName, designation, address, phoneNumber;
    int age, yearsOfExperience, ctc;
    map<string, map<int, int>> hoursWorked; // Map to store hours worked by employees

public:
    // Default constructor initializing member variables
    Employee() {
        id = "";
        firstName = "";
        secondName = "";
        designation = "";
        address = "";
        phoneNumber = "";
        age = 0;
        yearsOfExperience = 0;
        ctc = 0;
    }

    // Method to set employee data using provided parameters
    void setEmployeeData(const string& empId, const string& fName, const string& sName, const string& desig,
                         const string& addr, const string& phone, int empAge, int exp, int salary) {
        id = empId;
        firstName = fName;
        secondName = sName;
        designation = desig;
        address = addr;
        phoneNumber = phone;
        age = empAge;
        yearsOfExperience = exp;
        ctc = salary;
    }

    // Getter methods to retrieve individual employee data
    string getEmployeeId() const {
        return id;
    }

    string getFirstName() const {
        return firstName;
    }

    string getSecondName() const {
        return secondName;
    }

    string getDesignation() const {
        return designation;
    }

    string getAddress() const {
        return address;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    int getAge() const {
        return age;
    }

    int getYearsOfExperience() const {
        return yearsOfExperience;
    }

    int getCTC() const {
        return ctc;
    }

    // Overridden method to wait for user to press Enter
    void waitForEnter() override {
        cout << "\n\nPress enter to continue...";
        cin.clear(); // Clearing input stream state flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoring previous input, ensuring clean buffer
        cin.get(); // Waiting for Enter key press
    }

    // Overridden method to center text in the console
    void centerText(const string& text) override {
        int width = 80; // Total width of the console
        int length = text.length(); // Length of the text to be centered
        int spaces = (width - length) / 2; // Calculating spaces for centering

        cout << setw(spaces + length) << text; // Outputting text centered within spaces
    }

    void addEmployee() {
        system("cls"); // Clears the console screen

        Employee newEmployee; // Creates a new Employee object

        // Prompting user to input employee details
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Second Name: ";
        cin >> secondName;
        cout << "Enter Designation: ";
        cin >> designation;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cout << "Enter Years of Experience: ";
        cin >> yearsOfExperience;
        cout << "Enter CTC: ";
        cin >> ctc;
        cout << "Employee added successfully." << endl;

        // Setting employee data using the provided inputs
        newEmployee.setEmployeeData(id, firstName, secondName, designation, address, phoneNumber, age, yearsOfExperience, ctc);

        // Writing employee details to a file named employees.txt
        ofstream employeeFile("employees.txt", ios::app);
        if (employeeFile.is_open()) {
            // Writing employee data to the file
            employeeFile << "ID: " << newEmployee.getEmployeeId() << ", First Name: " << newEmployee.getFirstName()
                         << ", Second Name: " << newEmployee.getSecondName() << ", Designation: " << newEmployee.getDesignation()
                         << ", Age: " << newEmployee.getAge() << ", Address: " << newEmployee.getAddress()
                         << ", Phone Number: " << newEmployee.getPhoneNumber() << ", Years of Experience: "
                         << newEmployee.getYearsOfExperience() << ", CTC: " << newEmployee.getCTC() << endl;
            employeeFile.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void removeEmployee() {
        system("cls");
        string idRemove;
        cout << "Enter the ID of the employee to remove: ";
        cin >> idRemove;

        ifstream inputFile("employees.txt");
        ofstream tempFile("temp.txt");

        if (!inputFile.is_open() || !tempFile.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        bool found = false;
        string line;

        // Copying all employee records except the one to be removed to a temporary file
        while (getline(inputFile, line)) {
            if (line.find("ID: " + idRemove) != string::npos) {
                found = true;
                continue;
            }
            tempFile << line << endl;
        }

        inputFile.close();
        tempFile.close();

        if (found) {
            // Removing original file and renaming the temporary file to replace it
            remove("employees.txt");
            rename("temp.txt", "employees.txt");
            cout << "Employee with ID " << idRemove << " removed." << endl;
        } else {
            remove("temp.txt");
            cout << "Employee with ID " << idRemove << " not found." << endl;
        }
    }

    void displayEmployeeInfo() {
        system("cls");
        string idDisplay;
        cout << "Enter the ID of the employee to display info: ";
        cin >> idDisplay;

        ifstream employeeFile("employees.txt");
        if (employeeFile.is_open()) {
            string line;
            bool found = false;

            // Searching for the employee by ID and displaying their information if found
            while (getline(employeeFile, line)) {
                if (line.find("ID: " + idDisplay) != string::npos && idDisplay.size() == 4) {

                    stringstream ss(line);
                    string t;
                    vector<string> infos;

                    // Parsing the employee details and displaying each piece of information
                    while (getline(ss, t, ',')) {
                        infos.push_back(t);
                    }

                    for (const auto& info : infos) {
                        centerText(info);
                        cout << endl;
                    }

                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Employee with ID " << idDisplay << " not found." << endl;
            }
            employeeFile.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void displayEmployeeList() {
        system("cls");
        ifstream employeeFile("employees.txt");
        if (employeeFile.is_open()) {

            // Displaying formatted table headers for employee information
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << left << "|" << setw(15) << "ID" << "|" << setw(15) << "First Name" << "|" << setw(15) << "Second Name"
                 << "|" << setw(15) << "Designation" << "|" << setw(15) << "Age" << "|" << setw(15) << "Address"
                 << "|" << setw(15) << "Phone Number" << "|" << setw(15) << "Experience" << "|" << setw(15) << "CTC" << "|" << endl;

            string line;

            while (getline(employeeFile, line)) {
                stringstream ss(line);
                string t;
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

                // Parsing each line of employee details and displaying values
                while (getline(ss, t, ',')) {
                    size_t position = t.find(":");
                    if (position != string::npos) {
                        cout << left << "|" << setw(15) << t.substr(position + 2); // Displaying only values
                    }
                }

                cout << "|" << endl;
            }
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            employeeFile.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void editEmployeeDetails() {
        system("cls"); // Clears the console screen

        string idEdit;
        cout << "Enter the ID of the employee to edit details: ";
        cin >> idEdit;

        ifstream inputFile("employees.txt"); // Opens the employee file for reading
        ofstream tempFile("temp.txt"); // Creates a temporary file for modifications

        // Checks if both input and temporary files are open
        if (!inputFile.is_open() || !tempFile.is_open()) {
            cout << "Unable to open file." << endl;
            return;
        }

        bool found = false; // Tracks if the employee is found in the file
        string line;
        while (getline(inputFile, line)) {
            if (line.find("ID: " + idEdit) != string::npos) {
                found = true;
                Employee updatedEmployee;

                // Prompts user to enter updated employee details
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Second Name: ";
                cin >> secondName;
                cout << "Enter Designation: ";
                cin >> designation;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Phone Number: ";
                cin >> phoneNumber;
                cout << "Enter Years of Experience: ";
                cin >> yearsOfExperience;
                cout << "Enter CTC: ";
                cin >> ctc;

                // Sets the updated employee data
                updatedEmployee.setEmployeeData(id, firstName, secondName, designation, address, phoneNumber, age, yearsOfExperience, ctc);

                // Writes the updated employee data to the temporary file
                tempFile << "ID: " << updatedEmployee.getEmployeeId() << ", First Name: " << updatedEmployee.getFirstName()
                         << ", Second Name: " << updatedEmployee.getSecondName() << ", Designation: " << updatedEmployee.getDesignation()
                         << ", Age: " << updatedEmployee.getAge() << ", Address: " << updatedEmployee.getAddress()
                         << ", Phone Number: " << updatedEmployee.getPhoneNumber() << ", Experience: "
                         << updatedEmployee.getYearsOfExperience() << ", CTC: " << updatedEmployee.getCTC() << endl;
            } else {
                // If the employee is not the one to edit, copy the line to the temporary file
                tempFile << line << endl;
            }
        }

        inputFile.close(); // Closes the input file
        tempFile.close(); // Closes the temporary file

        if (found) {
            remove("employees.txt"); // Removes the original file
            rename("temp.txt", "employees.txt"); // Renames the temporary file to replace the original
            cout << "Employee details updated for ID " << idEdit << endl;
        } else {
            remove("temp.txt"); // Removes the temporary file if employee is not found
            cout << "Employee with ID " << idEdit << " not found." << endl;
        }
    }

    void hoursWorkedInAMonth() {
        system("cls");
        string employeeID;
        cout << "Enter the ID of the employee to see how many hours he worked in a month: ";
        cin >> employeeID;

        ifstream employeeFile("employees.txt");
        bool employeeExists = false;

        // Checking if the employee ID exists in the employees file
        if (employeeFile.is_open()) {
            string line;
            while (getline(employeeFile, line)) {
                if (line.find("ID: " + employeeID) != string::npos) {
                    employeeExists = true;
                    break;
                }
            }
            employeeFile.close();
        } else {
            cout << "Unable to open employees file." << endl;
            return;
        }

        // If the employee does not exist, display a message and return
        if (!employeeExists) {
            cout << "Employee with ID " << employeeID << " does not exist." << endl;
            return;
        }

        ifstream inputFile("hours_worked.txt");
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                istringstream iss(line);
                string id;
                iss >> id;
                if (id == employeeID) {
                    int day, hours;

                    // Fetching hours worked data for the employee from the file
                    while (iss >> day >> hours) {
                        hoursWorked[id][day] = hours;
                    }
                    inputFile.close();

                    // Displaying the hours worked for each day in the previous month
                    cout << "Hours worked in the previous month for employee " << employeeID << ":\n";
                    for (const auto &day : hoursWorked[employeeID]) {
                        cout << "Day " << day.first << ": ";
                        for (int i = 0; i < day.second; ++i) {
                            cout << "|";
                        }
                        cout << endl;
                    }

                    int totalHours = 0;
                    // Calculating the total hours worked in the previous month
                    for (const auto &day : hoursWorked[employeeID]) {
                        totalHours += day.second;
                    }
                    cout << "Total hours worked in the previous month: " << totalHours << " hours.\n";

                    return;
                }
            }
            inputFile.close();
        }

        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);

        // Calculating the start date of the previous month
        if (currentTime->tm_mon == 0) {
            currentTime->tm_year -= 1;
            currentTime->tm_mon = 11;
        } else {
            currentTime->tm_mon -= 1;
        }

        currentTime->tm_mday = 1;
        currentTime->tm_hour = 0;
        currentTime->tm_min = 0;
        currentTime->tm_sec = 0;

        srand(time(nullptr));

        int previousMonth = currentTime->tm_mon;
        // Generating random hours worked for each day in the previous month
        while (currentTime->tm_mon == previousMonth) {
            int dayOfWeek = currentTime->tm_wday;
            int workedHours = 0;

            if (dayOfWeek != 0 && dayOfWeek != 6) {
                workedHours = (rand() % 8) + 1; // Randomizing hours worked (1 to 8 hours)
            }

            hoursWorked[employeeID][currentTime->tm_mday] = workedHours;
            currentTime->tm_mday++;
            mktime(currentTime);
        }

        // Writing generated data to file for future reference
        ofstream outputFile("hours_worked.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << employeeID << " ";
            for (const auto& day : hoursWorked[employeeID]) {
                outputFile << day.first << " " << day.second << " ";
            }
            outputFile << endl;
            outputFile.close();
        }

        // Displaying generated hours worked for each day in the previous month
        cout << "Hours worked in the previous month for employee " << employeeID << ":\n";
        for (const auto& day : hoursWorked[employeeID]) {
            cout << "Day " << day.first << ": ";
            for (int i = 0; i < day.second; ++i) {
                cout << "|";
            }
            cout << endl;
        }

        // Calculating and displaying the total hours worked in the previous month
        int totalHours2 = 0;
        for (const auto &day : hoursWorked[employeeID]) {
            totalHours2 += day.second;
        }
        cout << "Total hours worked in the previous month: " << totalHours2 << " hours.\n";
    }
};

class Menu: public Employee{
private:
    string userName;
    string password;
    bool loggedIn;

public:
    Menu(){
        loggedIn = false; // Setting initial login status to false
    }

    // Method to start the program and display the main menu
    void startProgram(Employee& employee) {
        system("cls");
        centerText("Welcome to EMPLOYEE MANAGEMENT SYSTEM\n");
        int choice;

        // Displaying menu options
        centerText("1. Register\n");
        centerText("2. Login\n");
        centerText("3. Exit\n");
        centerText("Enter your choice: ");
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(); // Initiating user registration
                waitForEnter(); // Waiting for user to press Enter
                displayMenu(employee); // Displaying menu after registration
                if (login()) { // If successful login after registration, display menu again
                    displayMenu(employee);
                }
                break;
            case 2:
                if (login()) { // If login is successful, display menu
                    displayMenu(employee);
                }
                break;
            case 3:
                cout << "Exiting..." << endl; // Exiting the program
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl; // Handling invalid input
                break;
        }
    }

    void registerUser() {
        system("cls");
        ofstream userFile("users.txt", ios::app);
        if (userFile.is_open()) {
            centerText("Enter your name: ");
            cin >> userName; // Prompting user to input their name

            centerText("Set a password: ");
            char ch;
            string password = "";
            while (true) {
                ch = _getch(); // Capture character without displaying it
                if (ch == 13) // If Enter is pressed, stop capturing characters
                    break;
                password += ch; // Append character to the password
                cout << '*'; // Display asterisk on the screen
            }

            userFile << userName << " " << password << endl; // Storing username and password in the file
            cout << endl;
            centerText("Registration successful!");
            userFile.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    bool login() {
        system("cls");
        ifstream userFile("users.txt");
        if (userFile.is_open()) {
            string enteredUserName, enteredPassword;
            centerText("Log in to your account :)");
            cout << endl;
            centerText("Enter your name: ");
            cin >> enteredUserName; // Prompting user for username

            centerText("Enter password: ");
            char ch;
            string password = "";
            while (true) {
                ch = _getch(); // Capture character without displaying it
                if (ch == 13) // If Enter is pressed, stop capturing characters
                    break;
                password += ch; // Append character to the password
                cout << '*'; // Display asterisk on the screen
            }

            string userNameFromFile, passwordFromFile;
            bool found = false;
            while (userFile >> userNameFromFile >> passwordFromFile) {
                if (enteredUserName == userNameFromFile && password == passwordFromFile) {
                    cout << "\nLogin successful!" << endl;
                    userName = enteredUserName;
                    loggedIn = true;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nInvalid username or password. Login failed." << endl;
            }

            userFile.close();
            return loggedIn; // Returning login status
        } else {
            cout << "User database file does not exist." << endl;
            return false;
        }
    }


    void displayMenu(Employee& employee) {
        if (loggedIn) { // Checking if the user is logged in
            bool exitProgram = false;

            while (!exitProgram) { // Looping until the user chooses to exit
                system("cls");
                int choice;
                cout << endl;
                centerText("Welcome, " + userName + "!\n");
                centerText("1. Add Employee\n");
                centerText("2. Remove Employee\n");
                centerText("3. Display Employee Details\n");
                centerText("4. Display Employee List\n");
                centerText("5. Edit Employee Details\n");
                centerText("6. Hours Worked In A Month\n");
                centerText("7. Exit\n");
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        employee.addEmployee(); // Calling the function to add an employee
                        waitForEnter();
                        break;
                    case 2:
                        employee.removeEmployee(); // Calling the function to remove an employee
                        waitForEnter();
                        break;
                    case 3:
                        employee.displayEmployeeInfo(); // Calling the function to display employee details
                        waitForEnter();
                        break;
                    case 4:
                        employee.displayEmployeeList(); // Calling the function to display the list of employees
                        waitForEnter();
                        break;
                    case 5:
                        employee.editEmployeeDetails(); // Calling the function to edit employee details
                        waitForEnter();
                        break;
                    case 6:
                        employee.hoursWorkedInAMonth(); // Calling the function to display hours worked in a month
                        waitForEnter();
                        break;
                    case 7:
                        exitProgram = true; // Exiting the loop and program
                        break;
                    default:
                        cout << "Invalid choice. Please enter a valid option." << endl;
                        break;
                }
            }
        }
    }
};

int main() {
    Employee employee; // Creating an instance of the Employee class
    Menu menu; // Creating an instance of the Menu class
    menu.startProgram(employee); // Starting the program by invoking the startProgram method from the Menu class, passing the Employee instance
    return 0;
}
