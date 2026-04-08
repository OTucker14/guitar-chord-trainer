#include <iostream>
#include <string>
#include <vector>
#include <limits> // needed for cin.ignore() and numeric_limits
#include <cctype> // needed for tolower() function
using namespace std;

// A Chord object stores everything about one guitar chord.
class Chord {
private:
    string name; // e.g. "A Major"
    string symbol; // e.g. "A"
    vector<string> notes; // e.g. {"A", "C#", "E"}
    string difficulty; // "Beginner", "Intermediate", "Advanced"
    string fingerPosition; // human-readable fingering hint

public:
    // Constructor
    // Called automatically when we create a Chord object.
    // We take every parameter by const reference (&) to avoid
    // making unnecessary copies of the strings and vector.
    // The ": name(name)..." part is the member initializer list —
    // it sets each private variable before the body {} runs.
    Chord(const string& name, const string& symbol, const vector<string>& notes, const string& difficulty, const string& fingerPosition)
        : name(name), symbol(symbol), notes(notes), difficulty(difficulty), fingerPosition(fingerPosition) {}

    // GETTERS
    // These let outside code read private data without modifying it.
    // The trailing 'const' means this method won't change the object. string getName() const { return name; }
    string getSymbol()        const { return symbol; }
    vector<string> getNotes() const { return notes; }
    string getDifficulty()    const { return difficulty; }
    string getFingerPosition() const { return fingerPosition; }

    // GETNOTESSTRING
    // Returns the notes vector as one readable string, e.g. "A, C#, E"
    // We can't just cout a vector directly, so this method builds
    // the string manually, adding a comma between each note (but not after the last).
    string getNotesString() const {
        string result;
        for (size_t i = 0; i < notes.size(); ++i) {
            result += notes[i];
            if (i < notes.size() - 1)  // Don't add a comma after the final note
                result += ", ";
        }
        return result;
    }

    // DISPLAY
    // Prints a formatted summary of this chord to the console.
    // Calls getNotesString() internally — one method reusing another.
    void display() const {
        cout << "\n  Chord Name : " << name
             << "\n  Symbol     : " << symbol
             << "\n  Notes      : " << getNotesString()
             << "\n  Difficulty : " << difficulty
             << "\n  Fingering  : " << fingerPosition
             << "\n";
    }
};

// Builds and returns the full list of chords the program knows about.
// Returns a vector<Chord> so the rest of the program can loop through it.
vector<Chord> buildChordLibrary() {
    vector<Chord> library;

    // emplace_back constructs a Chord directly inside the vector
    // More efficient than push_back which would make a copy first.

    // --- BEGINNER CHORDS ---
library.emplace_back("A Major", "A",
    vector<string>{"A", "C#", "E"},
    "Beginner",
    "Place fingers 1, 2, 3 on the 2nd fret of strings B, G, D. Strum strings A through high-e.");

library.emplace_back("D Major", "D",
    vector<string>{"D", "F#", "A"},
    "Beginner",
    "Place finger 1 on fret 2 of string G, finger 2 on fret 2 of string high-e, finger 3 on fret 3 of string B. Strum strings D through high-e only.");

library.emplace_back("E Major", "E",
    vector<string>{"E", "G#", "B"},
    "Beginner",
    "Place finger 1 on fret 1 of string G, finger 2 on fret 2 of string A, finger 3 on fret 2 of string D. Strum all 6 strings.");

library.emplace_back("G Major", "G",
    vector<string>{"G", "B", "D"},
    "Beginner",
    "Place finger 1 on fret 2 of string A, finger 2 on fret 3 of string low-E, finger 3 on fret 3 of string high-e. Strum all 6 strings.");

library.emplace_back("C Major", "C",
    vector<string>{"C", "E", "G"},
    "Beginner",
    "Place finger 1 on fret 1 of string B, finger 2 on fret 2 of string D, finger 3 on fret 3 of string A. Avoid strumming low-E.");

library.emplace_back("E Minor", "Em",
    vector<string>{"E", "G", "B"},
    "Beginner",
    "Place finger 1 on fret 2 of string A, finger 2 on fret 2 of string D. Strum all 6 strings.");

library.emplace_back("A Minor", "Am",
    vector<string>{"A", "C", "E"},
    "Beginner",
    "Place finger 1 on fret 1 of string B, finger 2 on fret 2 of string D, finger 3 on fret 2 of string G. Strum strings A through high-e.");

// --- INTERMEDIATE CHORDS ---
library.emplace_back("D Minor", "Dm",
    vector<string>{"D", "F", "A"},
    "Intermediate",
    "Place finger 1 on fret 1 of string high-e, finger 2 on fret 2 of string G, finger 3 on fret 3 of string B. Strum strings D through high-e only.");

library.emplace_back("B Minor", "Bm",
    vector<string>{"B", "D", "F#"},
    "Intermediate",
    "Barre finger 1 across all strings at fret 2. Place finger 2 on fret 3 of string G, finger 3 on fret 4 of string A, finger 4 on fret 4 of string D. Strum strings A through high-e.");

library.emplace_back("F Major", "F",
    vector<string>{"F", "A", "C"},
    "Intermediate",
    "Barre finger 1 across all strings at fret 1. Place finger 2 on fret 2 of string G, finger 3 on fret 3 of string A, finger 4 on fret 3 of string D. Strum all 6 strings.");

library.emplace_back("C Major 7", "Cmaj7",
    vector<string>{"C", "E", "G", "B"},
    "Intermediate",
    "Place finger 1 on fret 1 of string B, finger 2 on fret 2 of string D, finger 3 on fret 3 of string A. Leave string G open. Avoid strumming low-E.");

library.emplace_back("G Major 7", "Gmaj7",
    vector<string>{"G", "B", "D", "F#"},
    "Intermediate",
    "Place finger 1 on fret 2 of string A, finger 2 on fret 2 of string high-e, finger 3 on fret 3 of string low-E. Leave strings D, G, B open. Strum all 6 strings.");

// --- ADVANCED CHORDS ---
library.emplace_back("A Dominant 7", "A7",
    vector<string>{"A", "C#", "E", "G"},
    "Advanced",
    "Place finger 1 on fret 2 of string D, finger 2 on fret 2 of string B. Leave strings G and high-e open. Strum strings A through high-e.");

library.emplace_back("E Dominant 7", "E7",
    vector<string>{"E", "G#", "B", "D"},
    "Advanced",
    "Place finger 1 on fret 1 of string G, finger 2 on fret 2 of string A. Leave all other strings open. Strum all 6 strings.");

library.emplace_back("D Suspended 2", "Dsus2",
    vector<string>{"D", "E", "A"},
    "Advanced",
    "Place finger 1 on fret 2 of string G, finger 2 on fret 3 of string B. Leave strings D and high-e open. Strum strings D through high-e only.");

    return library;
}

// Prints a horizontal line of dashes to visually separate sections.
void printLine() {
    cout << string(60, '-') << "\n"; // string(60, '-') creates a string of 60 dash characters
}

// Prints a title centred between two lines of '=' characters.
// Calculating padding makes it look neat no matter the title length.
void printBanner(const string& text) {
    cout << string(60, '=') << "\n";
    int padding = (60 - (int)text.size()) / 2;
    cout << string(padding, ' ') << text << "\n";
    cout << string(60, '=') << "\n";
}

// Case-insensitive string comparison
// The user can type "am" or "AM" or "Am" and all count as correct answers.
// Compares character by character after converting both to lowercase.
bool iequals(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (tolower(a[i]) != tolower(b[i])) return false;
    return true;
}

// Pauses the program until the user presses Enter, so they have time to read the output before the console closes.
void pause () {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer in case the user typed something before pressing Enter
    cin.get(); // Wait for the user to press Enter
}

// Displays the main menu and prompts the user for their choice.
void printMainMenu() {
    cout << "\n";
    printBanner(" Guitar Chord Trainer ");
    cout << "\n";
    cout << "1. Learn Chords\n";
    cout << "2. Practice Mode\n";
    cout << "3. View Score History\n";
    cout << "4. Exit\n\n";
    printLine();
    cout << "\nEnter your choice: ";
}

//
void learnMode(const vector<Chord>& library) {
    cout << "\n";
    pause();
}

//
void practiceMode(const vector<Chord>& library) {
    cout << "\n";
    pause();
}

//
void showHistory() {
    cout << "\n";
    pause();
}

// Shown once when the program starts.
// cin.get() waits for the user to press Enter before continuing.
void showWelcome() {
    cout << "\n\n";
    cout << string(56, '*') << "\n";
    cout << "*                                                      *\n";
    cout << "*          WELCOME TO GUITAR CHORD TRAINER             *\n";
    cout << "*                                                      *\n";
    cout << "*  Learn chord names, notes, and fingering tips.       *\n";
    cout << "*  Test yourself in Practice Mode and track scores.    *\n";
    cout << "*                                                      *\n";
    cout << string(56, '*') << "\n";
    cout << "\n  Press Enter to begin...";
    cin.get();
}

int main() {
    // Build the chord library once — every mode shares this same vector
    vector<Chord> library = buildChordLibrary();

    // Show the welcome screen once at startup
    showWelcome();

    // 'running' controls the main loop — set to false to exit
    bool running = true;

    while (running) {
        // Print the menu and get the user's choice
        printMainMenu();

        // getline reads the whole line including spaces,
        // safer than cin >> choice which can leave newlines in the buffer
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            learnMode(library);
        } else if (choice == "2") {
            practiceMode(library);
        } else if (choice == "3") {
            showHistory();
        } else if (choice == "4") {
            cout << "\n  Thanks for practicing! Keep strumming!\n\n";
            running = false;      // exits the while loop cleanly
        } else {
            // Any other input lands here
            cout << "\n  Invalid choice. Please enter 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}