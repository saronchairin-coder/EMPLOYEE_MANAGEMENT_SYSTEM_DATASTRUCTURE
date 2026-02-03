#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// ---------------- Employee Class ----------------
class Employee {
    // Sort by ID

private:
    int id;
    string name;
    string gender;
    int age;
    string dob;
    string address;
    string phoneEmail;
    string position;
    string department;
    double salary;
    

public:
    Employee(){
        id = 0;
        name = "Null";
        gender = "Null";
        age = 0;
        dob = "Null";
        address = "Null";
        phoneEmail = "Null";
        position = "Null";
        department = "Null";
        salary = 0.0;
    }
    Employee(int i, string n, string g, int a, string d, string ad, string pe, string p, string dep, double s){
        id = i;
        name = n;
        gender = g;
        age = a;
        dob = d;
        address = ad;
        phoneEmail = pe;
        position = p;
        department = dep;
        salary = s;
    }


    //function input
    void input() {
        cout << "Enter ID           : "; cin >> id; cin.ignore();
        cout << "Enter Name         : "; getline(cin, name);
        cout << "Enter Gender       : "; getline(cin, gender);
        cout << "Enter Age          : "; cin >> age; cin.ignore();
        cout << "Enter DOB          : "; getline(cin, dob);
        cout << "Enter Address      : "; getline(cin, address);
        cout << "Enter Phone/Email  : "; getline(cin, phoneEmail);
        cout << "Enter Position     : "; getline(cin, position);
        cout << "Enter Department   : "; getline(cin, department);
        cout << "Enter Salary       : "; cin >> salary; cin.ignore();
    }

    //function display
    void display() const {
    cout << left
         << setw(15) << id
         << setw(20) << name
         << setw(15) << gender
         << setw(15) << age
         << setw(15) << dob
         << setw(20) << address
         << setw(20) << phoneEmail
         << setw(15) << position
         << setw(15) << department
         << fixed << setprecision(2) << setw(15) << salary
         << endl;
}

      //header on Display Function
    void Header(){
    cout << left
         << setw(15) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Gender"
         << setw(15) << "Age"
         << setw(15) << "DOB"
         << setw(20) << "Address"
         << setw(20) << "Phone/Email"
         << setw(15) << "Position"
         << setw(15) << "Department"
         << fixed << setprecision(2) 
         << setw(15) << "Salary" << endl;
}

    int getId() const { return id; }

    string getName() const { return name; }

    //function update
    void update() {
        cout<<"Update ID            : "; cin >> id; cin.ignore();
        cout<<"Update Name          : "; getline(cin, name);
        cout<<"Update Gender        : "; getline(cin, gender);
        cout<<"Update Age           : "; cin >> age; cin.ignore();         
        cout<<"Update DOB           : "; getline(cin, dob);
        cout<<"Update Address       : "; getline(cin, address);
        cout<<"Update Phone/Email   : "; getline(cin, phoneEmail);
        cout<<"Update Position      : "; getline(cin, position);
        cout<<"Update Department    : "; getline(cin, department);
        cout<<"Update Salary        : "; cin >> salary; cin.ignore();
    }

    // File handling functions
    void writeToFile(ofstream &out) const {

        

            //new
             out << id << '\n' << name << '\n' << gender << '\n' << age << '\n'
            << dob << '\n' << address << '\n' << phoneEmail << '\n'
            << position << '\n' << department << '\n' << salary << '\n';
        // out <<left<<
        //         setw(20)<<id<<
        //         setw(20)<<name<<
        //         setw(20)<<gender<<
        //         setw(20)<<age<<
        //         setw(20)<<dob<<
        //         setw(20)<<address<<
        //         setw(20)<<phoneEmail<<
        //         setw(20)<<position<<
        //         setw(20)<<department<<
        //         setw(20)<<salary<<endl;

    }

    //function read from file
    void readFromFile(ifstream &in) {
        in >> id; in.ignore();
        getline(in, name);
        getline(in, gender);
        in >> age; in.ignore();
        getline(in, dob);
        getline(in, address);
        getline(in, phoneEmail);
        getline(in, position);
        getline(in, department);
        in >> salary; in.ignore();
    }
}emp;


    // function header for display in file
void HeaderFile(ofstream &out)  {
    
   out <<  left<<
               setw(20) <<"| ID      |" <<
               setw(20)<<"Name       |" <<
               setw(20)<<"Gender     |" <<
               setw(20)<<"Age        |" <<
               setw(20)<<"DOB        |" <<
               setw(20)<<"Address    |"   <<
               setw(20)<<"Phone/Email     |"<<
               setw(20)<<"Position    |"<<
               setw(20)<<"Department    |"<<
               setw(20)<<"Salary     |"<<endl;
    }


 //Function for delete file
    void deleteFile(const string &filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Error deleting file.\n";
    }
}

// ---------------- File Handling Functions ----------------
void saveToFile(const vector<Employee> &emps, const string &filename) {
    ofstream out(filename);
    if (!out) { cout << "Error opening file for writing.\n"; return; }
    out << emps.size() << '\n';
    for (const auto & e : emps)
        e.writeToFile(out);
    cout << "Data saved to file successfully.\n";
}

void loadFromFile(vector<Employee> &emps, const string &filename) {
    ifstream in(filename);
    if (!in) return;   // file does not exist yet
    size_t n;
    in >> n; in.ignore();
    emps.clear();
    for (size_t i = 0; i < n; ++i) {
        Employee e;
        e.readFromFile(in);
        emps.push_back(e);
    }
}
//=================menu Fucntion ===================
void addEmployee(vector<Employee> &emps) {
    int n;
    cout << "How many employees to add? "; cin >> n; cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "\nEmployee #" << (i + 1) << ":\n";
        Employee e;
        e.input();
        emps.push_back(e);
    }
    //show result after input 
    // if(!emps.empty()){
    //     cout << "\n===Employee List===\n";
    //     emps[0].Header();   // header 1 time
    //     for (const auto &e : emps)
    //         e.display();
    // }
}

void viewEmployees(const vector<Employee> &emps) {
    if (emps.empty()) { cout << "No employees found.\n"; return; }
    Employee temp;
    temp.Header();
    for (const auto &e : emps) e.display();
}

void searchEmployee(const vector<Employee> &emps) {
    int choice;
    do {
        cout << "\n--- SEARCH MENU ---\n";
        cout << "1. Search by ID\n";
        cout << "2. Search by Name\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                cout << "Enter ID to search: "; cin >> id; cin.ignore();
                bool found = false;
                for (const auto &e : emps) {
                    if (e.getId() == id) {
                        emp.Header();
                        e.display();
                        found = true;
                    }
                }
                if (!found) cout << "Employee with ID " << id << " not found.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter Name to search: "; getline(cin, name);
                bool found = false;
                for (const auto &e : emps) {
                    if (e.getName() == name) {
                         emp.Header();
                        e.display();
                        found = true;
                    }
                }
                if (!found) cout << "Employee with Name \"" << name << "\" not found.\n";
                break;
            }
            case 3:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
}

// void updateEmployee(vector<Employee> &emps) {
//     int id; string name;
//     cout << "Update by ID (-1 to skip): "; cin >> id; cin.ignore();
//     if (id != -1) {
//         for (auto &e : emps)
//             if (e.getId() == id) e.update();
//     }
//     cout << "Update by Name (empty to skip): "; getline(cin, name);
//     if (!name.empty()) {
//         for (auto &e : emps)
//             if (e.getName() == name) e.update();
//     }
// }
void updateEmployee(vector<Employee> &emps) {
    int choice;
    do {
        cout << "\n--- UPDATE MENU ---\n";
        cout << "1. Update by ID\n";
        cout << "2. Update by Name\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                cout << "Enter ID to update: "; cin >> id; cin.ignore();
                bool found = false;
                for (auto &e : emps) {
                    if (e.getId() == id) {
                        e.update();
                        found = true;
                        cout << "Employee updated successfully.\n";
                    }
                }
                if (!found) cout << "Employee with ID " << id << " not found.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter Name to update: "; getline(cin, name);
                bool found = false;
                for (auto &e : emps) {
                    if (e.getName() == name) {
                        e.update();
                        found = true;
                        cout << "Employee updated successfully.\n";
                    }
                }
                if (!found) cout << "Employee with Name \"" << name << "\" not found.\n";
                break;
            }
            case 3:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
}

// void deleteEmployee(vector<Employee> &emps) {
//     int id; string name;
//     cout << "Delete by ID (-1 to skip): "; cin >> id; cin.ignore();
//     if (id != -1) {
//         for (auto it = emps.begin(); it != emps.end(); ) {
//             if (it->getId() == id) it = emps.erase(it);
//             else ++it;
//         }
//     }
//     cout << "Delete by Name (empty to skip): "; getline(cin, name);
//     if (!name.empty()) {
//         for (auto it = emps.begin(); it != emps.end(); ) {
//             if (it->getName() == name) it = emps.erase(it);
//             else ++it;
//         }
//     }
// }

void deleteEmployee(vector<Employee> &emps) {
    int choice;
    do {
        cout << "\n--- DELETE MENU ---\n";
        cout << "1. Delete by ID\n";
        cout << "2. Delete by Name\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                cout << "Enter ID to delete: "; cin >> id; cin.ignore();
                bool found = false;
                for (auto it = emps.begin(); it != emps.end(); ) {
                    if (it->getId() == id) {
                        it = emps.erase(it);
                        found = true;
                        cout << "Employee deleted successfully.\n";
                    } else ++it;
                }
                if (!found) cout << "Employee with ID " << id << " not found.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter Name to delete: "; getline(cin, name);
                bool found = false;
                for (auto it = emps.begin(); it != emps.end(); ) {
                    if (it->getName() == name) {
                        it = emps.erase(it);
                        found = true;
                        cout << "Employee deleted successfully.\n";
                    } else ++it;
                }
                if (!found) cout << "Employee with Name \"" << name << "\" not found.\n";
                break;
            }
            case 3:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
}


//============ Sort Functions==========

// Sort by ID
   bool compareById(const Employee &a, const Employee &b) {
    return a.getId() < b.getId();
    }   

// Sort by Name
bool compareByName(const Employee &a, const Employee &b) {
    return a.getName() < b.getName();
    }
//Function Sort Employee
void sortEmployees(vector<Employee> &emps) {
    int choice;
//  

    do {
        cout << "\n--- SORT MENU ---\n";
        cout << "1. Sort by ID\n";
        cout << "2. Sort by Name\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        switch(choice) {
            case 1:
                sort(emps.begin(), emps.end(), compareById);   // sort by ID

                // sort(emps.begin(), emps.end(), [](const Employee &a, const Employee &b){
                //     return a.getId() < b.getId();
                // });
                cout << "Employees sorted by ID successfully.\n";
                break;
            case 2:
                sort(emps.begin(), emps.end(), compareByName); // sort by Name

                // sort(emps.begin(), emps.end(), [](const Employee &a, const Employee &b){
                //     return a.getName() < b.getName();
                // });
                cout << "Employees sorted by Name successfully.\n";
                break;
            case 3:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
}



//=====Insert Employee at specific position==========
void insertEmployee(vector<Employee> &emps) {
    int choice;
    do {
        cout << "\n--- INSERT MENU ---\n";
        cout << "1. Insert by Position\n";
        cout << "2. Insert after ID\n";
        cout << "3. Insert after Name\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: "; cin >> choice; cin.ignore();

        switch (choice) {
            case 1: {
                int pos;
                cout << "Enter position to insert (1-based index): "; cin >> pos; cin.ignore();
                if (pos < 1 || pos > emps.size() + 1) {
                    cout << "Invalid position!\n";
                    break;
                }
                Employee e;
                cout << "Enter employee details:\n";
                e.input();
                emps.insert(emps.begin() + (pos - 1), e);
                cout << "Employee inserted at position " << pos << ".\n";
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID to insert after: "; cin >> id; cin.ignore();
                int index = -1;
                for (size_t i = 0; i < emps.size(); ++i) {
                    if (emps[i].getId() == id) { index = i; break; }
                }
                if (index == -1) {
                    cout << "ID not found!\n";
                    break;
                }
                Employee e;
                cout << "Enter employee details:\n";
                e.input();
                emps.insert(emps.begin() + index + 1, e);
                cout << "Employee inserted after ID " << id << ".\n";
                break;
            }
            case 3: {
                string name;
                cout << "Enter Name to insert after: "; getline(cin, name);
                int index = -1;
                for (size_t i = 0; i < emps.size(); ++i) {
                    if (emps[i].getName() == name) { index = i; break; }
                }
                if (index == -1) {
                    cout << "Name not found!\n";
                    break;
                }
                Employee e;
                cout << "Enter employee details:\n";
                e.input();
                emps.insert(emps.begin() + index + 1, e);
                cout << "Employee inserted after Name \"" << name << "\".\n";
                break;
            }
            case 4:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
}

// ---------------- Main Function ----------------
int main() {
    vector<Employee> empList;
    vector<Employee> employees;
    loadFromFile(employees, "employees.txt");

    int choice;
    int num;
    do {
          cout << "\n∏❀=❀=❀=❀=❀=❀=❀=❀=⎛EMPLOYEE MANAGEMENT SYSTEM⎞=❀=❀=❀=❀=❀=❀=❀=❀=❀=❀=❀∏\n";
            cout << "⎮  1. ADD    EMPLOYEE                                              ⎮\n";
            cout << "⎮  2. VIEW   Employees                                             ⎮\n";
            cout << "⎮  3. SEARCH Employee                                              ⎮\n";
            cout << "⎮  4. UPDATE Employee                                              ⎮\n";
            cout << "⎮  5. DELETE Employee                                              ⎮\n";
            cout << "⎮  6. SORT   Employees                                             ⎮\n";
            cout << "⎮  7. INSERT Employee at Position                                  ⎮\n";
            cout << "⎮  8. SAVE & EXIT                                                  ⎮\n";
            cout << "∐❄︎-❄︎-❄︎-❄︎--❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎-❄︎∐\n";
            cout << "Enter your choice: "; cin >> choice; cin.ignore();        
    //     if (choice == 1) {
    //         //add multiple employees 
    //            int numEmployees;
    //     cout << "How many employees do you want to add? ";
    //     cin >> numEmployees;
    //     cin.ignore(); // clear newline from input buffer
    // for (int i = 0; i < numEmployees; i++) {
    //     cout << "\nEnter details for Employee #" << (i + 1) << ":\n";
    //     Employee e;
    //     e.input();
    //     employees.push_back(e);
    //  }
    // }
    //     else if (choice == 2) {
    //         cout << "\n--- Employee List ---\n";
    //          emp.Header();
    //         for (const auto & e : employees)
    //               e.display();   
    //     }
    //     else if (choice == 3) {
    //         int id; string name;
    //         cout << "Search by ID (enter -1 to skip): "; cin >> id; cin.ignore();
    //         if (id != -1) {
    //             for (const auto & e : employees)
    //                 if (e.getId() == id) e.display();
    //         }
    //         cout << "Search by Name (enter empty to skip): "; getline(cin, name);
    //         if (!name.empty()) {
    //             for (const auto & e : employees)
    //                 if (e.getName() == name) e.display();
    //         }
    //     }
    //     else if (choice == 4) {
    //         int id; string name;
    //         cout << "Update by ID (enter -1 to skip): "; cin >> id; cin.ignore();
    //         if (id != -1) {
    //             for (auto & e : employees)
    //                 if (e.getId() == id) e.update();
    //         }
    //         cout << "Update by Name (empty to skip): "; getline(cin, name);
    //         if (!name.empty()) {
    //             for (auto & e : employees)
    //                 if (e.getName() == name) e.update();
    //         }
    //     }
    //     else if (choice == 5) {
    //         int id; string name;
    //         cout << "Delete by ID (enter -1 to skip): "; cin >> id; cin.ignore();
    //         if (id != -1) {
    //             for (auto it = employees.begin(); it != employees.end(); ) {
    //                 if (it->getId() == id) it = employees.erase(it);
    //                 else ++it;
    //             }
    //         }
    //         cout << "Delete by Name (empty to skip): "; getline(cin, name);
    //         if (!name.empty()) {
    //             for (auto it = employees.begin(); it != employees.end(); ) {
    //                 if (it->getName() == name) it = employees.erase(it);
    //                 else ++it;
    //             }
    //         }
    //     }
    //     else if (choice == 6) {
    //         saveToFile(employees, "employees.txt");
    //         cout << "Exiting...\n";
    //     }
    //     else {
    //         cout << "Invalid choice!\n";
    //     }

     switch(choice){
        case 1: addEmployee(employees); break;
        case 2: viewEmployees(employees); break;
        case 3: searchEmployee(employees); break;
        case 4: updateEmployee(employees); break;
        case 5: deleteEmployee(employees); break;
        case 6: sortEmployees(employees); break;
        case 7: insertEmployee(employees); break;
        // case 8: saveToFile(employees, "employees.txt");
        //         cout << "Exiting...\n"; break;
        case 8: {
    char ans;
    saveToFile(employees, "employees.txt");
    // saveToNewFile(employees);

    cout << "Do you want to delete the file? (y/n): ";
    cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        deleteFile("employees.txt");
    }

    cout << "Exit program.\n";
    break;
}
        default: cout << "Invalid choice! Try again.\n";
     }
    } while (choice != 8);

    return 0;
}