// Chris Schultz
// COSC 2030
// Lab 01
// 18 September 2017

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

int main(){
    // declaring the needed variables
    string fileName;
    ifstream numFile;
    int count = 2;
    double num1, num2, num3, num4;

    // while loop to check for a valid file name
    while (!numFile.is_open()){
        cout << "Please enter file name to read from. ";
        getline(cin, fileName);
        numFile.open(fileName.c_str());
        if (!numFile){
            cout << "Could not open file. ";
        }
    }

    // reads in first two numbers
    numFile >> num1 >> num2;

    // increments count past 2 and reads in last number as the last value
    while ((!numFile.eof()) && (numFile >> num4)){
        count ++;
    }

    // clears stream and points to beginning of the file
    numFile.clear();
    numFile.seekg(0, numFile.beg);

    // reads in values until it gets to second to last number
    for (int i = 0; i < count - 1; i++){
        numFile >> num3;
    }

    // close the file, we don't need it anymore
    numFile.close();

    // displays the count, first two, and last two numbers
    cout << "The count of the numbers in the file is " << count << "!" << endl;
    cout << "The first two values in the file are " << num1 << " and " << num2 << "!" << endl;
    cout << "The last two values in the file are " << num3 << " and " << num4 << "!" << endl;

    return 0;
}
