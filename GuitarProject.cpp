#include <iostream>
#include <string>
#include <vector>
#include <limits> // needed for cin.ignore() and numeric_limits
#include <cctype> // needed for tolower() function
#include <algorithm> // needed for shuffle and iota
#include <random> // needed for mt19937 random number generator
#include <chrono> // needed for seeding the random number generator
#include <iomanip> // needed for setw and setprecision when displaying scores
#include <numeric> // needed for iota
#include <fstream>  // needed for reading and writing files
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
    // The trailing 'const' means this method won't change the object. 
    string getName() const { return name; }
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
void printLine(char ch = '-') {
    cout << string(56, ch) << "\n";
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

// Removes leading and trailing whitespace from a string.
// Protects against accidental spaces when the user types their answer.
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    // If only whitespace was found, return an empty string
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
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

//Stores the result of a practice session
//Using a struct instead of a class since we just want a simple data container without methods or encapsulation.
struct SessionResult{
int correct = 0;
int total = 0;
string difficulty;
string timestamp;
};

// Saves a single session result to scores.txt.
// We use 'append' mode (ios::app) so each new result is added
// to the end of the file rather than overwriting previous ones.
void saveResult(const SessionResult& r) {
    ofstream file("scores.txt", ios::app);  // open in append mode

    if (!file.is_open()) {
        cout << "\n  Warning: could not save score to file.\n";
        return;
    }

    // Write one line per session in a simple format we can read back later
    // We separate each field with a | character so we can split it when loading
    file << r.timestamp << "|"
         << r.difficulty << "|"
         << r.correct << "|"
         << r.total << "\n";

    file.close();
}

// Loads all previously saved sessions from scores.txt.
// Called once at startup so history persists between runs.
vector<SessionResult> loadHistory() {
    vector<SessionResult> history;

    ifstream file("scores.txt");  // open in read mode

    // If the file doesn't exist yet that's fine —
    // it just means no sessions have been saved yet
    if (!file.is_open()) return history;

    string line;
    // Read the file one line at a time
    while (getline(file, line)) {
        if (line.empty()) continue;  // skip blank lines

        // Split the line by '|' to get each field back
        // find() locates the '|' and substr() cuts the string at that point
        SessionResult r;
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);

        // Make sure all separators were found before reading
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
            continue;  // skip any malformed lines

        r.timestamp  = line.substr(0, p1);
        r.difficulty = line.substr(p1 + 1, p2 - p1 - 1);

        // stoi converts the string back to an integer
        try {
            r.correct = stoi(line.substr(p2 + 1, p3 - p2 - 1));
            r.total   = stoi(line.substr(p3 + 1));
        } catch (...) {
            continue;  // skip lines with bad number data
        }

        history.push_back(r);
    }

    file.close();
    return history;
}

// Learn Mode allows the user to browse all chords, filter by difficulty, or search by name/symbol.
void learnMode(const vector<Chord>& library) {
    // 'back' controls the learn mode loop — set to true to return to main menu
    bool back = false;

    while (!back) {
        cout << "\n";
        printBanner(" Learn Mode ");
        cout << "\n";
        cout << " [1] Browse all chords\n";
        cout << " [2] Filter by difficulty\n";
        cout << " [3] Search by name or symbol\n";
        cout << " [4] Back to Main Menu\n\n";
        printLine();
        cout << "\nEnter your choice: ";

        string input;
        getline(cin, input);
        input = trim(input);

        if (input =="1") {
            // Browse all chords
            cout << "\n";
            printLine('=');
            cout << " All Chords (" << library.size() << " total)\n";
            printLine('=');
            for (const Chord& chord : library) {
                chord.display();
                printLine('-');
            }
            pause();

        } else if (input == "2") {
            // Filter by difficulty
            cout << "\n [1] Beginner [2] Intermediate [3] Advanced\n" << " Choice ";
            string dc; // difficulty choice
            getline(cin, dc);
            dc = trim(dc);

            // Map user input to difficulty string
            string filter;
            if (dc == "1") filter = "Beginner";
            else if (dc == "2") filter = "Intermediate";
            else if (dc == "3") filter = "Advanced";
            else {
                cout << "\n Invalid choice. Returning to Learn Mode menu.\n";
                continue; // back to difficulty menu
            }

            cout << "\n";
            printLine('=');
            cout << " " << filter << " Chords\n";
            printLine('=');

            bool found = false;
            for (const Chord& chord : library) {
                // Only display chords that match the selected difficulty
                if (chord.getDifficulty() == filter) {
                    chord.display();
                    printLine();
                    found = true;
                }
            }
            if (!found) cout << " No chords found.\n";
            pause();

        } else if (input == "3") {
            // Search
            cout << " Enter chord name or symbol: ";
            string query;
            getline(cin, query);
            query = trim(query);

            cout << "\n";
            printLine('=');
            cout << " Results for \"" << query << "\"\n";
            printLine('=');

            bool found = false;
            for (const Chord& chord : library) {
                // Check if the query matches the symbol exactly (case-insensitive)
                // OR if the query appears anywhere inside the full name
                bool matchesSymbol = iequals(chord.getSymbol(), query);
                bool matchesName   = chord.getName().find(query) != string::npos; // case-sensitive substring search

                if (matchesSymbol || matchesName) {
                chord.display();
                printLine();
                found = true;
                }
            }
            if (!found) cout << " No chords found.\n";
            pause();

        } else if (input == "4") {
            back = true; // exit the learn mode loop and return to main menu

        } else {
            cout << "\n Invalid choice. Returning to Learn Mode menu.\n";
        }
    }
}

// Returns a SessionResult so main() can store it in the history vector
SessionResult practiceMode(const vector<Chord>& library) {
    SessionResult result;

    // CHOOSE DIFFICULTY 
    cout << "\n";
    printBanner(" Practice Mode ");
    cout << "\n"
         << "  [1] Beginner only\n"
         << "  [2] Intermediate only\n"
         << "  [3] Advanced only\n"
         << "  [4] All chords mixed\n\n"
         << "  Choice: ";

    string dc;
    getline(cin, dc);
    dc = trim(dc);

    string diffFilter;
    if      (dc == "1") diffFilter = "Beginner";
    else if (dc == "2") diffFilter = "Intermediate";
    else if (dc == "3") diffFilter = "Advanced";
    else                diffFilter = "All";
    result.difficulty = diffFilter;

    // BUILD SUBSET
    // Filter the library down to only chords matching the chosen difficulty
    vector<Chord> subset;
    for (const auto& c : library) {
        if (diffFilter == "All" || c.getDifficulty() == diffFilter)
            subset.push_back(c);
    }

    if (subset.empty()) {
        cout << "\n  No chords available for that difficulty.\n";
        return result;  // return early with empty result
    }

    //HOW MANY QUESTIONS? 
    cout << "  How many questions? (1-" << subset.size() << "): ";
    string qs;
    getline(cin, qs);
    int numQuestions = 0;
    // stoi converts a string to an integer — we wrap in try/catch
    // in case the user types something that isn't a number
    try { numQuestions = stoi(trim(qs)); } catch (...) { numQuestions = 5; }
    // Clamp to valid range so user can't ask for 0 or more than we have
    numQuestions = max(1, min(numQuestions, (int)subset.size()));

    // SHUFFLE
    // Seed the random generator with the current time so it's
    // different every run — same seed = same shuffle every time
    unsigned seed = (unsigned)chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);

    // Build a list of indices [0, 1, 2, ...] then shuffle them
    // so we pick chords in a random order without repeating
    vector<int> indices(subset.size());
    iota(indices.begin(), indices.end(), 0);  // fills with 0, 1, 2, 3...
    shuffle(indices.begin(), indices.end(), rng);
    indices.resize(numQuestions);  // only keep as many as we need

    // PRACTICE LOOP 
    cout << "\n";
    printLine('=');
    cout << "  " << numQuestions << " question(s) | Difficulty: " << diffFilter << "\n";
    printLine('=');
    cout << "\n  Tip: type the chord symbol (e.g. Am, G, Cmaj7)\n\n";

    for (int i = 0; i < numQuestions; ++i) {
        const Chord& chord = subset[indices[i]];

        cout << "  Question " << (i + 1) << "/" << numQuestions << "\n";
        printLine('-');
        cout << "  Notes: " << chord.getNotesString() << "\n\n";
        cout << "  Your answer: ";

        string answer;
        getline(cin, answer);
        answer = trim(answer);

        // Accept either the symbol ("Am") or full name ("A Minor")
        bool correct = iequals(answer, chord.getSymbol()) ||
                       iequals(answer, chord.getName());

        if (correct) {
            ++result.correct;
            cout << "\n  Correct! Well done.\n\n";
        } else {
            cout << "\n  Not quite. The answer was: "
                 << chord.getName() << " (" << chord.getSymbol() << ")\n"
                 << "  Fingering: " << chord.getFingerPosition() << "\n\n";
        }
    }

    result.total = numQuestions;

    // SESSION SUMMARY 
    double pct = (result.total > 0) ? 100.0 * result.correct / result.total : 0.0;

    cout << "\n";
    printBanner(" Session Complete ");
    cout << "\n"
         << "  Score    : " << result.correct << " / " << result.total << "\n"
         << "  Accuracy : " << fixed << setprecision(1) << pct << "%\n";

    // Give different feedback based on score
    string grade;
    if      (pct == 100.0) grade = "Perfect! You're a chord master!";
    else if (pct >= 80.0)  grade = "Great job! Keep strumming!";
    else if (pct >= 60.0)  grade = "Good effort. Practice makes perfect!";
    else if (pct >= 40.0)  grade = "Keep at it - you're learning!";
    else                   grade = "Don't give up - review Learn Mode!";

    cout << "  Feedback : " << grade << "\n\n";
    printLine('=');

    // TIMESTAMP 
    // Record when this session happened for the history screen
    auto now = chrono::system_clock::now();
    auto t   = chrono::system_clock::to_time_t(now);
    tm tm_buf{};
    localtime_s(&tm_buf, &t);  // Windows-safe version of localtime
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_buf);
    result.timestamp = buf;
    
    // Save this session to file before returning
    saveResult(result);

    pause();
    return result;
}

// Takes the full session history and displays it as a table.
// 'const' means we're just reading the history, not changing it.
void showHistory(const vector<SessionResult>& history) {
    cout << "\n";
    printBanner(" Score History ");

    if (history.empty()) {
        cout << "\n  No sessions played yet.\n";
        pause();
        return;
    }

    // Print table header — setw() sets the column width for alignment
    cout << "\n  "
         << left << setw(22) << "Timestamp"
         << setw(14) << "Difficulty"
         << setw(10) << "Score"
         << "Accuracy\n";
    printLine();

    int totalCorrect = 0, totalQuestions = 0;
    for (const auto& r : history) {
        double pct = (r.total > 0) ? 100.0 * r.correct / r.total : 0.0;
        cout << "  "
             << left  << setw(22) << r.timestamp
             << setw(14) << r.difficulty
             << r.correct << "/" << r.total
             << "     "
             << fixed << setprecision(1) << pct << "%\n";
        totalCorrect   += r.correct;
        totalQuestions += r.total;
    }

    // Overall totals across all sessions
    printLine();
    double overallPct = (totalQuestions > 0)
                        ? 100.0 * totalCorrect / totalQuestions : 0.0;
    cout << "\n  Overall: " << totalCorrect << "/" << totalQuestions
         << "  (" << fixed << setprecision(1) << overallPct << "%)\n";
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
    vector<Chord> library = buildChordLibrary();

    // Load saved history from file so scores persist between runs
    // If no file exists yet, loadHistory() returns an empty vector
    vector<SessionResult> history = loadHistory();

    showWelcome();

    bool running = true;
    while (running) {
        printMainMenu();

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            learnMode(library);
        } else if (choice == "2") {
            // Store the returned result in history
            SessionResult r = practiceMode(library);
            // Only save if the user actually answered questions
            if (r.total > 0) history.push_back(r);
        } else if (choice == "3") {
            // Pass history in so showHistory() can display it
            showHistory(history);
        } else if (choice == "4") {
            cout << "\n  Thanks for practicing! Keep strumming!\n\n";
            running = false;
        } else {
            cout << "\n  Invalid choice. Please enter 1, 2, 3, or 4.\n";
        }
    }
    return 0;
}