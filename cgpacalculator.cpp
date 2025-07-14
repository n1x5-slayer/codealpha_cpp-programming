#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Convert grade to grade point
float getGradePoint(const string& grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "B-") return 2.7;
    if (grade == "C+") return 2.3;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "C-") return 1.7;
    if (grade == "D") return 1.0;
    if (grade == "F" || grade == "f") return 0.0;
    

}

int main() {
    int numCourses;
    float totalGradePoints = 0.0, totalCredits = 0.0;

    cout << "===== CGPA Calculator =====\n";
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<string> courseGrades(numCourses);
    vector<float> creditHours(numCourses);
    vector<float> gradePoints(numCourses);

    cin.ignore(); // Clear newline left in buffer

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " name: ";
        getline(cin, courseNames[i]);

        cout << "Grade for " << courseNames[i] << " (A, B+, C-, etc.): ";
        cin >> courseGrades[i];

        cout << "Credit hours for " << courseNames[i] << ": ";
        cin >> creditHours[i];

        float point = getGradePoint(courseGrades[i]);
        if (point == -1.0) {
            cout << "? Invalid grade entered. Please restart.\n";
            return 1;
        }

        gradePoints[i] = point;
        totalCredits += creditHours[i];
        totalGradePoints += point * creditHours[i];
        cin.ignore(); // Clear buffer for next subject name
    }

    float semesterGPA = totalGradePoints / totalCredits;

    // Output section
    cout << "\n===== Grade Summary =====\n";
    cout << left << setw(20) << "Subject"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(10) << "Points\n";

    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(20) << courseNames[i]
             << setw(10) << courseGrades[i]
             << setw(15) << creditHours[i]
             << setw(10) << gradePoints[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\n?? Semester GPA: " << semesterGPA << endl;

    // CGPA option
    char calcCGPA;
    cout << "\nDo you want to calculate overall CGPA? (Y/N): ";
    cin >> calcCGPA;

    if (calcCGPA == 'Y' || calcCGPA == 'y') {
        float prevCGPA, prevCredits;
        cout << "Enter previous CGPA: ";
        cin >> prevCGPA;
        cout << "Enter total previous credit hours: ";
        cin >> prevCredits;

        float newCGPA = ((prevCGPA * prevCredits) + totalGradePoints) / (prevCredits + totalCredits);
        cout << " Overall CGPA: " << newCGPA << endl;
    }

    cout << "\n Calculation Complete. Keep up the hard work!\n";
    return 0;
}

