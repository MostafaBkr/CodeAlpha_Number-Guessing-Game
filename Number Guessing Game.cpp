/*
MIT License

Copyright (c) 2024 CodeAlpha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";

int main() {
    srand(static_cast<unsigned>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        int difference = abs(secretNumber - guess);
        if (guess > secretNumber) {
            if (difference > 20) {
                cout << RED << "Too high!" << RESET << endl;
            } 
            else if (difference > 10) {
                cout << RED << "High!" << RESET << endl;
            } 
            else {
                cout << YELLOW << "Less high!" << RESET << endl;
            }
        } 
        else if (guess < secretNumber) {
            if (difference > 20) {
                cout << RED << "Too low!" << RESET << endl;
            } 
            else if (difference > 10) {
                cout << RED << "Low!" << RESET << endl;
            } 
            else {
                cout << YELLOW << "Less low!" << RESET << endl;
            }
        } 
        else {
            cout << GREEN << "Congratulations! You've guessed the correct number!" << RESET << endl;
            cout << GREEN << "It took you " << attempts << " attempts." << RESET << endl;
        }
    } while (guess != secretNumber);
    return 0;
}

