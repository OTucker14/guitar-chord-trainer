# Guitar Chord Trainer

A C++ console application to help users learn and practice guitar chords.
Built as a class project to demonstrate object-oriented programming, vectors, file I/O, and functions in C++.

## Features

- **Learn Mode** — Browse all chords, filter by difficulty, or search by name and symbol
- **Practice Mode** — Get quizzed on random chords and receive instant feedback
- **Score Tracking** — Scores are saved to a file and persist between runs
- **Three Difficulty Levels** — Beginner, Intermediate, and Advanced chords
- **15 Chords** — Covers essential open chords, barre chords, seventh chords, and more

## How to Compile

Make sure you have a C++ compiler installed that supports C++17.

```bash
g++ -std=c++17 -Wall -o guitar guitar_chords.cpp
```

## How to Run

```bash
./guitar
```

On Windows:
```bash
guitar.exe
```

## How to Use

When the program starts you will see the main menu:

- **Option 1** — Enter Learn Mode to study chords at your own pace
- **Option 2** — Enter Practice Mode to test yourself
- **Option 3** — View your score history across all sessions
- **Option 4** — Exit the program

In Practice Mode you will be shown the notes of a chord and asked to identify it.
You can type either the chord symbol (e.g. `Am`) or the full name (e.g. `A Minor`).

## Chord Library

| Difficulty | Chords |
|---|---|
| Beginner | A, D, E, G, C, Em, Am |
| Intermediate | Dm, Bm, F, Cmaj7, Gmaj7 |
| Advanced | A7, E7, Dsus2 |

## Project Structure

- `guitar_chords.cpp` — All source code in one file
- `scores.txt` — Auto-generated file that stores your session history
- `.gitignore` — Excludes the compiled binary from version control

## Concepts Demonstrated

- Classes with private members, constructors, and methods
- Vectors and the STL
- Functions and program flow
- File I/O with fstream
- Random number generation
- String manipulation and input handling
