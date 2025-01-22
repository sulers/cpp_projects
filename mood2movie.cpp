#include <iostream>
#include <string>
using namespace std;

void giveSuggestionAndAdvice(string mood, string preference) {
    // Suggestions based on mood and preference
    cout << "\nSuggested Entertainment:\n";
    
    if (mood == "happy") {
        if (preference == "movie") {
            cout << "- A good movie like 'The Pursuit of Happyness'.\n";
        } else if (preference == "cartoon") {
            cout << "- Watch something cheerful like 'SpongeBob SquarePants'.\n";
        } else if (preference == "comedy") {
            cout << "- Watch a stand-up comedy show like 'Kevin Hart'.\n";
        }
        cout << "- Keep spreading that joy and share with friends!\n";
    }
    else if (mood == "sad") {
        if (preference == "movie") {
            cout << "- Watch an uplifting movie like 'The Secret Life of Walter Mitty'.\n";
        } else if (preference == "cartoon") {
            cout << "- Watch a funny cartoon like 'Tom & Jerry'.\n";
        } else if (preference == "comedy") {
            cout << "- Watch some stand-up like 'John Mulaney'.\n";
        }
        cout << "- It's okay to feel sad, but remember, it gets better.\n";
    }
    else if (mood == "angry") {
        if (preference == "movie") {
            cout << "- Watch an action-packed movie like 'Mad Max'.\n";
        } else if (preference == "cartoon") {
            cout << "- Try 'The Simpsons' for some comic relief.\n";
        } else if (preference == "comedy") {
            cout << "- Watch a comedy movie like 'The Hangover'.\n";
        }
        cout << "- Take a deep breath, and let go of that anger.\n";
    }
    else if (mood == "stressed") {
        if (preference == "movie") {
            cout << "- Watch a relaxing movie like 'The Secret Garden'.\n";
        } else if (preference == "cartoon") {
            cout << "- Try something lighthearted like 'The Adventures of Paddington'.\n";
        } else if (preference == "comedy") {
            cout << "- Try watching 'The Office' for a light laugh.\n";
        }
        cout << "- Take a break, do some deep breathing, and relax.\n";
    }
    else {
        cout << "- Mood not recognized. Try again later.\n";
    }
}

int main() {
    int moodChoice;
    string mood, preference;

    // Display mood options and ask the user to select a mood
    while (true) {
        cout << "\n==== Mood Selection ====\n";
        cout << "1. Happy\n";
        cout << "2. Sad\n";
        cout << "3. Angry\n";
        cout << "4. Stressed\n";
        cout << "Select your mood (1-4): ";
        cin >> moodChoice;

        // Validate the input
        if (moodChoice == 1) {
            mood = "happy";
            break;
        } else if (moodChoice == 2) {
            mood = "sad";
            break;
        } else if (moodChoice == 3) {
            mood = "angry";
            break;
        } else if (moodChoice == 4) {
            mood = "stressed";
            break;
        } else {
            cout << "Invalid input! Please select a valid mood number (1-4).\n";
        }
    }

    // Ask for entertainment preference
    while (true) {
        cout << "\nWhat type of entertainment would you like? (1. Movie, 2. Cartoon, 3. Comedy): ";
        int entertainmentChoice;
        cin >> entertainmentChoice;

        if (entertainmentChoice == 1) {
            preference = "movie";
            break;
        } else if (entertainmentChoice == 2) {
            preference = "cartoon";
            break;
        } else if (entertainmentChoice == 3) {
            preference = "comedy";
            break;
        } else {
            cout << "Invalid input! Please select a valid entertainment type (1-3).\n";
        }
    }

    // Call the function to give suggestion and advice
    giveSuggestionAndAdvice(mood, preference);

    return 0;
}
