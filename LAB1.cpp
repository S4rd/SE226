#include <iostream>
using namespace std;

int main() {
    // question 1
    string name;
    int id;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "Hello "<< name << "!\n";
    cout << "What is your Student ID?" << endl;
    cin >> id;
    cout << "Your ID is " << id << endl;

    // question 2
    int var1;
    int var2;
    cout << "Enter your first var:" << endl;
    cin >> var1;
    cout << "Enter your second var:" << endl;
    cin >> var2;
    int sum = var1 + var2;
    int diff = var1 - var2;
    int prod = var1 * var2;
    cout << var1 << endl;
    cout << var2 << endl;
    cout << sum << endl;
    cout << diff << endl;
    cout << prod << endl;

    // question 3

    int labGrade;
    int midtermGrade;
    int finalGrade;
    int lastScore;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your lab grade?" << endl;
    cin >> labGrade;
    cout << "What is your midterm grade?" << endl;
    cin >> midtermGrade;
    cout << "What is your final grade?" << endl;
    cin >> finalGrade;
    lastScore = (labGrade*0.25+midtermGrade*0.35+finalGrade*0.40);
    cout << "Name: " << name << endl;
    cout << "Lab: " << labGrade << endl;
    cout << "Midterm: " << midtermGrade << endl;
    cout << "Final: " << finalGrade << endl;
    cout << "Last Score: " << lastScore << endl;

    // question 4

    cout << "*" << endl << "**" << endl << "***" << endl << "**" << endl << "*" << endl;





    return 0;
}

