#include <iostream>
using namespace std;

// Function to calculate BMI
void calculateBMI() {
    float weight, height, bmi;
    
    cout << "\nEnter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (m): ";
    cin >> height;
    
    bmi = weight / (height * height);

    cout << "\nYour BMI is: " << bmi << endl;
    cout << "Category: ";
    
    if (bmi < 18.5)
        cout << "Underweight" << endl;
    else if (bmi >= 18.5 && bmi < 25)
        cout << "Normal weight" << endl;
    else if (bmi >= 25 && bmi < 30)
        cout << "Overweight" << endl;
    else
        cout << "Obese" << endl;
}

// Function to suggest daily water intake
void waterIntake() {
    int age;
    float weight, waterNeeded;
    
    cout << "\nEnter your age: ";
    cin >> age;
    cout << "Enter your weight (kg): ";
    cin >> weight;
    
    if (age < 30)
        waterNeeded = weight * 40;
    else if (age >= 30 && age <= 55)
        waterNeeded = weight * 35;
    else
        waterNeeded = weight * 30;
    
    cout << "Recommended daily water intake: " << waterNeeded / 1000 << " liters" << endl;
}

// Function to give exercise recommendations
void exerciseAdvice() {
    int exerciseTime;
    
    cout << "\nEnter your daily exercise time (minutes): ";
    cin >> exerciseTime;
    
    if (exerciseTime < 30)
        cout << "Try to exercise more!" << endl;
    else if (exerciseTime >= 30 && exerciseTime <= 60)
        cout << "Good job! Keep going." << endl;
    else
        cout << "Great! Don't overdo it." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== Health Tracker =====";
        cout << "\n1. BMI Calculator";
        cout << "\n2. Water Intake Reminder";
        cout << "\n3. Exercise Recommendations";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: calculateBMI(); break;
            case 2: waterIntake(); break;
            case 3: exerciseAdvice(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again!\n";
        }

    } while (choice != 4);
    
    return 0;
}
