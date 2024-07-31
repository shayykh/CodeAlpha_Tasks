#include <iostream>
#include <vector>
using namespace std;

// Function to convert grade to grade point
double gradeToPoint(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<int> credits(numCourses);
    vector<char> grades(numCourses);
    double totalCredits = 0.0, totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter the credits for course " << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter the grade (A, B, C, D, F) for course " << i + 1 << ": ";
        cin >> grades[i];

        totalCredits += credits[i];
        totalGradePoints += credits[i] * gradeToPoint(grades[i]);
    }

    double CGPA = totalGradePoints / totalCredits;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << CGPA << endl;

    return 0;
}