/* Project Name : CppTypingMaster

CppTypingMaster is a C++ console-based Typing Speed Test that measures 
a user’s typing speed (WPM) and accuracy using Object-Oriented Programming concepts.” */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// ---------- USER CLASS ----------
class User {
private:
    string name;
public:
    User(string n="Guest") : name(n) {}
    void setName(string n) { 
	name = n;
	 }
    string getName() { 
	return name;
	 }
};

// ---------- TEST BASE CLASS ----------
class Test {
protected:
    string text;
    float timeTaken;
    float speed;
    float accuracy;

public:
    virtual void startTest() = 0; // Pure Virtual

    float calculateSpeed(int words, float seconds) {
        return (words / (seconds / 60)); // words per minute
    }

    float calculateAccuracy(string input) {
        int correct = 0;
        for(size_t i=0; i<input.size() && i<text.size(); i++) {
            if(input[i] == text[i]) correct++;
        }
        return ((float)correct / text.size()) * 100;
    }
};

// ---------- EASY TEST ----------
class EasyTest : public Test {
public:
    EasyTest() {
        text = "The quick brown fox jumps over the lazy dog";
    }
    void startTest() override {
        cout << "\nTyping Test (EASY):\n" << text << "\n\nStart typing:\n";

        clock_t start = clock();
        string input;
        getline(cin, input);
        clock_t end = clock();

        timeTaken = float(end - start) / CLOCKS_PER_SEC;

        int words = input.size() / 5; // average word length
        speed = calculateSpeed(words, timeTaken);
        accuracy = calculateAccuracy(input);

        cout << "\nTime: " << timeTaken << " sec";
        cout << "\nSpeed: " << speed << " WPM";
        cout << "\nAccuracy: " << accuracy << "%\n";
    }
};

// ---------- HARD TEST ----------
class HardTest : public Test {
public:
    HardTest() {
        text = "Object oriented programming in C++ allows classes, inheritance and polymorphism to create reusable code.";
    }
    void startTest() override {
        cout << "\nTyping Test (HARD):\n" << text << "\n\nStart typing:\n";

        clock_t start = clock();
        string input;
        getline(cin, input);
        clock_t end = clock();

        timeTaken = float(end - start) / CLOCKS_PER_SEC;

        int words = input.size() / 5;
        speed = calculateSpeed(words, timeTaken);
        accuracy = calculateAccuracy(input);

        cout << "\nTime: " << timeTaken << " sec";
        cout << "\nSpeed: " << speed << " WPM";
        cout << "\nAccuracy: " << accuracy << "%\n";
    }
};

// ---------- MAIN ----------
int main() {
    string username;
    cout << "Enter your name: ";
    getline(cin, username);

    User u(username);

    int choice;
    do {
        cout << "\nHello, " << u.getName() << "! Choose Test Mode:";
        cout << "\n1. Easy Test\n2. Hard Test\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore(); // to clear buffer

        if(choice == 1) {
            EasyTest et;
            et.startTest();
        }
        else if(choice == 2) {
            HardTest ht;
            ht.startTest();
        }
        else if(choice == 3) {
            cout << "Goodbye, " << u.getName() << "! ??\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}

