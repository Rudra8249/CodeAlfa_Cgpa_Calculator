#include <iostream>
#include <string>
using namespace std;

// Function to convert grade to point
float gradeToPoint(string grade) {
    if (grade == "A+") return 10.0;
    if (grade == "A")  return 9.0;
    if (grade == "B+") return 8.0;
    if (grade == "B")  return 7.0;
    if (grade == "C+") return 6.0;
    if (grade == "C")  return 5.0;
    if (grade == "D")  return 4.0;
    if (grade == "F")  return 0.0;
    return -1.0; // Invalid grade
}

int main() {
    int n;
    const int MAX = 100;
    string grades[MAX];
    int credits[MAX];
    float gradePoints[MAX];

    float totalGradePoints = 0;
    float totalCredits = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << " grade (e.g. A+, A, B+): ";
        cin >> grades[i];

        float point = gradeToPoint(grades[i]);
        while (point < 0) {
            cout << "Invalid grade. Enter again: ";
            cin >> grades[i];
            point = gradeToPoint(grades[i]);
        }

        cout << "Course " << i + 1 << " credit hours: ";
        cin >> credits[i];

        gradePoints[i] = point * credits[i];
        totalGradePoints += gradePoints[i];
        totalCredits += credits[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n--- Results ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1 << ": Grade = " << grades[i]
             << ", Credit = " << credits[i]
             << ", Grade Points = " << gradePoints[i] << "\n";
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "Total Grade Points: " << totalGradePoints;
    cout << "\nFinal CGPA: " << cgpa << "\n";

    return 0;
}
