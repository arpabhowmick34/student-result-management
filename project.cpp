#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Grade Function
pair<string,double> getGrade(int marks) {
    if(marks >= 80) return {"A+",4.00};
    if(marks >= 75) return {"A",3.75};
    if(marks >= 70) return {"A-",3.50};
    if(marks >= 65) return {"B+",3.25};
    if(marks >= 60) return {"B",3.00};
    if(marks >= 55) return {"B-",2.75};
    if(marks >= 50) return {"C",2.50};
    if(marks >= 40) return {"D",2.00};
    return {"F",0.00};
}

//  Course Structure
struct Course {
    string name;
    float credit;
    int year;
    string semester;
};

//  Student Structure
struct Student {
    string id;
    string name;
    int year;
    string semester;
    vector<pair<string,int>> courseMarks;
};

//  Quick Sort
int partition(vector<Student>& students, int low, int high) {
    string pivot = students[high].id;
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(students[j].id < pivot){
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i+1], students[high]);
    return i+1;
}

void quickSort(vector<Student>& students, int low, int high){
    if(low < high){
        int pi = partition(students, low, high);
        quickSort(students, low, pi-1);
        quickSort(students, pi+1, high);
    }
}

// Binary Search
int binarySearch(vector<Student>& students, string key) {
    int left = 0;
    int right = students.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(students[mid].id == key) {
            return mid;
        }
        else if(students[mid].id < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

// Print Student Result
void printResult(Student &student, vector<Course> &allCourses) {
    // student basic info
    cout << "\n===== STUDENT RESULT =====\n";
    cout << "ID       : " << student.id << "\n";
    cout << "Name     : " << student.name << "\n";
    cout << "Year     : " << student.year << "\n";
    cout << "Semester : " << student.semester << "\n";

    double totalPoints = 0;
    int totalCredits = 0;

    cout << "\n--- Marks & Grades ---\n";

    //  course marks
    for(auto &cm : student.courseMarks) {
        string courseName = cm.first;
        int marks = cm.second;
        int credit = 0;

        // course credit
        for(auto &c : allCourses) {
            if(c.name == courseName) {
                credit = c.credit;
                break;
            }
        }

        // grade and grade point
        pair<string, double> gradeInfo = getGrade(marks);
        string grade = gradeInfo.first;
        double point = gradeInfo.second;

        // course info
        cout << courseName << " : " << marks << " (" << grade << ", " << point << ")"
             << ", Credit: " << credit << "\n";


        totalPoints += point * credit;
        totalCredits += credit;
    }

    // GPA
    double gpa = 0;
    if(totalCredits > 0) {
        gpa = totalPoints / totalCredits;
    }

    cout << "\nFinal GPA : " << gpa << "\n";

}

int main(){
    vector<Student> students;
    vector<Course> courses;

    int choice;
    do {
        cout << "\n  STUDENT RESULT SYSTEM  \n";
        cout << "1. Add Courses for Semester + Year\n";
        cout << "2. Add Student\n";
        cout << "3. Search Result by ID + Year + Semester\n";
        cout << "4. Edit Student Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        if(choice==1){
            string sem;
            int year;
            cout << "\nEnter Year: ";
            cin >> year;
            cout << "Enter Semester: ";
            cin >> sem;

            int n;
            cout << "How many courses do you want to add for this Semester + Year? ";
            cin >> n;

            for(int i=1;i<=n;i++){
                string cname;
                float credit;
                cout << "\nCourse " << i << " Name: ";
                cin >> cname;
                cout << "Credit for " << cname << ": ";
                cin >> credit;

                // check duplicate
                bool found=false;
                for(auto &c: courses){
                    if(c.name==cname && c.year==year && c.semester==sem){
                        found=true;
                        cout << "Course already exists! \n";
                        break;
                    }
                }
                if(!found){
                    courses.push_back({cname, credit, year, sem});
                }
            }
            cout << "\nCourses added successfully for " << sem << " " << year << "\n";

        }
        else if(choice==2){
            Student s;
            cout << "\nEnter ID: ";
            cin >> s.id;

            int idx = binarySearch(students, s.id);
            if(idx != -1){
                cout << "\nID already exists! Cannot add student.\n";
                continue;
            }

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter Year: ";
            cin >> s.year;
            cout << "Enter Semester: ";
            cin >> s.semester;


            vector<Course> semCourses;
            for(auto &c : courses){
                if(c.year==s.year && c.semester==s.semester){
                    semCourses.push_back(c);
                }
            }

            if(semCourses.empty()){
                cout << "\nNo courses defined for this semester! Add courses first.\n";
                continue;
            }

            cout << "\nEnter marks for the following courses:\n";
            for(auto &c : semCourses){
                int marks;
                cout << c.name << " (Credit: " << c.credit << "): ";
                cin >> marks;
                s.courseMarks.push_back({c.name, marks});
            }

            students.push_back(s);
            quickSort(students, 0, students.size()-1);
            cout << "\nStudent added successfully!\n";
        }
        else if(choice==3){
            if(students.empty()){
                cout << "\nNo students in database!\n";
                continue;
            }
            string id, semester;
            int year;
            cout << "\nEnter Student ID: ";
            cin >> id;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Semester: ";
            cin >> semester;

            int idx = binarySearch(students, id);
            if(idx==-1) cout << "\nStudent Not Found!\n";
            else{
                if(students[idx].year==year && students[idx].semester==semester)
                    printResult(students[idx], courses);
                else
                    cout << "\n not found!\n";
            }
        }
        else if(choice==4){
            if(students.empty()){
                cout << "\nNo students in database!\n";
                continue;
            }
            string id;
            cout << "\nEnter Student ID to edit: ";
            cin >> id;
            int idx = binarySearch(students, id);
            if(idx==-1){
                cout << "\nStudent not found!\n";
                continue;
            }

            Student &s = students[idx];
            cout << "\nEditing Student: " << s.name << " (" << s.id << ")\n";

            // Edit Name
            cout << "Enter new Name (or same to keep): ";
            cin.ignore();
            string newName;
            getline(cin, newName);
            if(!newName.empty()) s.name = newName;

            // Edit Year
            cout << "Enter new Year (or same to keep): ";
            int newYear; cin >> newYear;
            // Edit Semester
            cout << "Enter new Semester (or same to keep): ";
            string newSem; cin >> newSem;

            // Update year/semester
            vector<Course> semCourses;
            for(auto &c: courses){
                if(c.year==newYear && c.semester==newSem){
                    semCourses.push_back(c);
                }
            }

            if(!semCourses.empty()){
                s.year = newYear;
                s.semester = newSem;

                //  edit marks
                for(auto &cm : s.courseMarks){
                    cout << "Current marks for " << cm.first << ": " << cm.second << ". Enter new marks (or -1 to keep): ";
                    int m; cin >> m;
                    if(m != -1) cm.second = m;
                }

                // Add new courses
                cout << "\nDo you want to add a new course for this student? (y/n): ";
                char ch; cin >> ch;
                while(ch=='y' || ch=='Y'){
                    string cname;
                    int credit, marks;
                    cout << "Enter Course Name: "; cin >> cname;
                    cout << "Enter Credit: "; cin >> credit;
                    cout << "Enter Marks: "; cin >> marks;
                    s.courseMarks.push_back({cname, marks});
                    courses.push_back({cname, credit, newYear, newSem});
                    cout << "Add another course? (y/n): "; cin >> ch;
                }

                // Delete courses
                cout << "\nDo you want to delete a course for this student? (y/n): ";
                cin >> ch;
                while(ch=='y' || ch=='Y'){
                    string cname;
                    cout << "Enter Course Name to delete: "; cin >> cname;
                    bool found=false;
                    for(int i=0;i<s.courseMarks.size();i++){
                        if(s.courseMarks[i].first==cname){
                            s.courseMarks.erase(s.courseMarks.begin()+i);
                            found=true;
                            cout << cname << " deleted.\n";
                            break;
                        }
                    }
                    if(!found) cout << "Course not found for this student.\n";
                    cout << "Delete another course? (y/n): "; cin >> ch;
                }
            } else {
                cout << "\nNo courses found for this Year/Semester! Keeping old Year/Semester.\n";
            }

            quickSort(students, 0, students.size()-1);
            cout << "\nStudent updated successfully!\n";
        }
        else if(choice==0){
            cout << "\nExiting!\n";
        }
        else{
            cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice!=0);

    return 0;
}
