#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Global Arrays for Storing Data
string names[50] = {"Noor", "Mariam", "Rahima", "Neha", "Shazeel", "Kainat", "Faiq", "Fateh", "Isra", "Fatima", "Hareem", "Haris", "Isra", "Ishfaq", "Juniad"};
string department[50] = {
    "Computer Science", "Mathematics", "Physics", "Biology", "Chemistry",
    "Mechanical Engineering", "Electrical Engineering", "Civil Engineering",
    "Economics", "History", "Philosophy", "English", "Psychology",
    "Business Administration", "Art" };
int roll_no[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
double marks[50][8]; // Marks for 8 semesters
const double totalMarks = 450.0;
// Initialize Marks Function
void initializeMarks()
{
    for (int i = 0; i < 15; i++)
{
        for (int j = 0; j <8; j++)
{
            marks[i][j] = 350 + (i * 2) + (j * 10); // Generating unique marks for each student
        }
    }
}
// GPA Calculation Functions
double sem_percentage(double marks, double total) {
    return (marks / total) * 100;
}
double sem_GPA(double percentage) {
    return (percentage / 100) * 4;
}
// CREATE: Add a new student record
void createRecord()
 {
    int rollnum;
    cout << "Enter new student's roll number: ";
    cin >> rollnum;
    if(rollnum==0)
    {
    	cout<<"Please, enter valid roll number (1-50)!!"<<endl;
	}
	else
	{
    // Check if roll number already exists
    for (int i = 0; i < 50; i++) {
        if (roll_no[i] == rollnum) {
            cout << "Error: Roll number already exists!" << endl;
            return;
        }
    }

    // Add new student
    for (int i = 0; i < 50; i++)
{
        if (roll_no[i] == 0)
{ // Find an empty spot
            roll_no[i] = rollnum;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, names[i]);
             cout << "Enter Department name: ";
// cin.ignore();
            getline(cin, department[i]);
            for (int j = 0; j < 8; j++)
{

    bool flag=false;
                while(!flag)
{
                cout << "Enter marks for Semester " << (j + 1) << ": ";
                cin >> marks[i][j];
                if((marks[i][j]>=0) && (marks[i][j]<=450))
                flag=true;
                else
                cout<<"Please, enter valid marks (0-450)!!"<<endl;
            }
            }
            cout << "Record added successfully!" << endl;
            return;
        }
    }

    cout << "Error: No space to add more records!" << endl;
	}
	
    
}

// READ: Display all student records in table format
void displayAll() {
    cout << "\n========== All Student Records ==========\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < 50; i++) {
        if (roll_no[i] != 0) { // Display only if roll number exists
            cout << "Roll No : " << roll_no[i] << "\n";
            cout << "Name : " << names[i] << "\n";
            cout << "Department : " << department[i] << "\n";
            cout << "Semester-wise Marks and GPA:\n";
            cout << setw(10) << "Semester" << setw(15) << "Marks" << setw(15) << "Percentage" << setw(10) << "GPA\n";
            cout << string(50, '-') << "\n";

            double totalGPA = 0;

            for (int j = 0; j < 8; j++) {
                double percentage = sem_percentage(marks[i][j], totalMarks);
                double gpa = sem_GPA(percentage);
                totalGPA += gpa;

                cout << setw(10) << (j + 1)
                     << setw(15) << fixed << setprecision(1) << marks[i][j]
                     << setw(15) << fixed << setprecision(2) << percentage << "%"
                     << setw(10) << fixed << setprecision(2) << gpa << "\n";
            }

            cout << "Overall CGPA: " << fixed << setprecision(2) << (totalGPA / 8) << "\n";
            cout << string(50, '=') << "\n"; // Separator between students
        }
    }

    if (roll_no[0] == 0) {
        cout << "No records found!" << endl;
    }
}
// SEARCH: Search for a student by roll number and display details in table
void searchRecord (){
    int rollnum;
    cout << "Enter roll number to search: ";
    cin >> rollnum;
     if(rollnum==0)
    {
     cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;
	}
	else
	{
		
    for (int i = 0; i < 50; i++) {
        if (roll_no[i] == rollnum) {
            cout << "\nStudent Found!\n";
            cout << "Name : " << names[i] << endl;
            cout << "Roll No : " << roll_no[i] << endl;
            cout << "Department : " << department[i] << "\n";
            cout << "\nSemester-wise Marks and GPA:\n";
            cout << setw(10) << "Semester" << setw(15) << "Marks" << setw(15) << "Percentage" << setw(10) << "GPA\n";
            cout << "------------------------------------------------------------\n";
              double totalGPA = 0;
            for (int j = 0; j < 8; j++) {
                double percentage = sem_percentage(marks[i][j], totalMarks);
                double gpa = sem_GPA(percentage);
                totalGPA += gpa;
                cout << setw(10) << (j + 1) << setw(15) << marks[i][j] << setw(15) << fixed << setprecision(2) << percentage << "%" << setw(10) << gpa << "\n";
            }
            cout << "Overall CGPA: " << fixed << setprecision(2) << (totalGPA / 8) << "\n";
            cout << string(50, '=') << "\n"; // Separator between students
            return;
        }
    }

    cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;
	}

}


// UPDATE: Modify an existing student record
void updateRecord() {
    int rollnum;
    cout << "Enter roll number of the student to update: ";
    cin >> rollnum;
    if(rollnum==0)
    {
        cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;
        return ;
	}
	
		 for (int i = 0; i < 50; i++) {
        if (roll_no[i] == rollnum) {
            cout << "Updating record for Roll No: " << rollnum << endl;
            cout << "Current Name: " << names[i] << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, names[i]);
            cout << "Enter new department name: ";
// cin.ignore();
            getline(cin, department[i]);
            for (int j = 0; j < 8; j++) {
             bool flag=false;
                while(!flag){
                cout << "Enter new marks for Semester " << (j + 1) << ": ";
                cin >> marks[i][j];
                 if((marks[i][j]>=0) && (marks[i][j]<=450))
                flag=true;
                else
                cout<<"Plz, enter valid marks (0-450)!!"<<endl;
            }
            }
            cout << "\nSemester-wise Marks and GPA:\n";
            cout << setw(10) << "Semester" << setw(15) << "Marks" << setw(15) << "Percentage" << setw(10) << "GPA\n";
            cout << "------------------------------------------------------------\n";
              double totalGPA = 0;
            for (int j = 0; j < 8; j++) {
                double percentage = sem_percentage(marks[i][j], totalMarks);
                double gpa = sem_GPA(percentage);
                totalGPA += gpa;

                cout << setw(10) << (j + 1)
                     << setw(15) << fixed << setprecision(1) << marks[i][j]
                     << setw(15) << fixed << setprecision(2) << percentage << "%"
                     << setw(10) << fixed << setprecision(2) << gpa << "\n";
                     
            }

            cout << "Overall CGPA: " << fixed << setprecision(2) << (totalGPA / 8) << "\n";
            cout << string(50, '=') << "\n"; // Separator between students
           
            cout << "Record updated successfully!" << endl;
            return;
        }
	}
	
   


    cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;
}


// DELETE: Remove a student record
void deleteRecord() {
    int choice;
    cout << "Press 1 to delete a specific record\nPress 2 to delete all records\n";
    cin >> choice;

    if (choice == 1) {
        int rollnum;
        cout << "Enter roll number of the student to delete: ";
        cin >> rollnum;
     if(rollnum==0)
    {
        cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;
        return ;
	}
        for (int i = 0; i < 50; i++) {
            if (roll_no[i] == rollnum) {
                roll_no[i] = 0;
                names[i] = "";
                department[i]=" ";
                for (int j = 0; j < 8; j++) {
                    marks[i][j] = 0;
                }
                cout << "Record deleted successfully!" << endl;
                return;
            }
        }

        cout << "Error: Student with Roll No " << rollnum << " not found!" << endl;

    } else if (choice == 2) {
        for (int i = 0; i < 15; i++) {
            roll_no[i] = 0;
            names[i] = "";
            for (int j = 0; j < 8; j++) {
                marks[i][j] = 0;
            }
        }
        cout << "All records deleted successfully!" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}

// MENU: Display options to the user
void menu() {
    int action;
    do {
        cout << "\n====== Student Management System ======" << endl;
        cout << "1. Create a New Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Search for a Record" << endl;
        cout << "4. Update a Record" << endl;
        cout << "5. Delete a Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> action;

        switch (action) {
            case 1:
                createRecord();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (action != 6);
}

// Main Function
int main() {
    initializeMarks(); // Initialize default marks
    menu(); // Start the menu
    return 0;
}
