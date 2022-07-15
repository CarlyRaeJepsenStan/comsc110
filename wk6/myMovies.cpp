// Objective: make a simple movie guessing game
// Name: Aaron Shey 2027142
// Course: COMSC-110-5003
// Compiler: g++ - GNU C and C++ compiler
// Editor: vim

// libraries
#include <deque>
#include <fstream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
// Programmer defined data types
struct Movie {
  string title;
  int year;
};

// Special compiler dependent definitions
// NONE

// global constants/variables
// NONE

// Programmer defined functions
void introduction(string objective, string instructions);
deque<Movie> inputMovies();
void askMovie(deque<Movie> morbin);

// main program

int main() {
  // user introduction
  string objective = "make a simple movie guessing game";
  string instructions = "type the year you think the film was released";
  introduction(objective, instructions);

cout << "mark";
  deque<Movie> morbin = inputMovies();
cout << "mark";
  char sentinel = 'y';
  do {
    askMovie(morbin);

    cout << "Do you want to play again? [y/n]: ";
    cin >> sentinel;
    cin.ignore(1000, 10);
  } while (tolower(sentinel) == 'y');
}  // main

void introduction(string objective, string instructions) {
  cout << "Objective: " << objective << "\n";
  cout << "Programmer: Aaron\n";
  cout << "Editor(s) used: geany\n";
  cout << "Compiler(s) used: g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Instructions: " << instructions << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}  // introduction

deque<Movie> inputMovies() {
  int i = 0;
  deque<Movie> output;
  ifstream movieData;
  movieData.open("movieData.txt");

  while (movieData.good()) {
    if (!movieData.good()) {
      break;
    } else {
string temp;
      getline(movieData, temp);
output[i].title = temp;
cout << "Title: " << output[i].title;
int tempie;
      movieData >> tempie;
output[i].year = tempie;
cout << "Year: " << output[i].year;
      movieData.ignore(1000, 10);
      movieData.ignore(1000, 10);
      i++;
      // cout << name << ": " << year << "\n";
    }  // else
  }    // while
  return output;
}  // inputMovies

void askMovie(deque<Movie> morbin) {
  int guess;
  srand(time(0));
  Movie selection = morbin[rand() % morbin.size()];
  cout << "What year was\"" << selection.title << "\"released?\n";
  cin >> guess;
  cin.ignore(1000, 10);
  if (guess == selection.year) {
    cout << "Good job, that's correct!\n";
  } else {
    cout << "Oops, its actually " << selection.year << "\n";
  }
}
