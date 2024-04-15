// Author: Ashton Herrick
// Program: HW5
// Date Created: April 15, 2024
// Date Last Modified: April 15, 2024
//
// Problem: Implement a linked list data structure with insert and delete operations.
//
// Implemented a template class Node for individual list elements and a class MyList for list management.
// Added functions for inserting at the head, deleting from the head, searching, and displaying the list.
// Utilized a Profile struct to store data from a file into the list.

#include <iostream>
#include <fstream>
#include <sstream>
#include "MyList.h"

using namespace std;

// Defining a struct for storing profile information
struct Profile{
    string fullname;
    string state;

    // Overloading the equality operator for Profile
    bool operator==(const Profile& rhs) const{
        return fullname == rhs.fullname;
    }

    // Overloading the inequality operator for Profile
    bool operator!=(const Profile& rhs) const{
        return fullname != rhs.fullname;
    }
};
// Overloading the stream insertion operator for Profile
ostream& operator<<(ostream& out, const Profile& user){
    out<<user.fullname<<"--"<<user.state;
    return out;
}

int main(){
    MyList<Profile> pMyList;    // Create an instance of MyList to store profiles
    ifstream file("presidentsWstates.txt"); // Open the file containing profiles
    string line;
    Profile temp;   // Temporary variable to store profile data while reading from file

    // Check if the file is open and ready for reading
    if (file.is_open()){
        // Read each line from the file
        while (getline(file, line)){
            stringstream ss(line);  // Create a stringstream to parse each line
            getline(ss, temp.fullname, '\t');   // Extract fullname from the line
            getline(ss, temp.state, '\t');  // Extract state from the line
            pMyList.insertHead(temp);   // Insert the profile at the beginning of the list
        }
    }

    // Display the list of profiles
    pMyList.display();

    return 0;
}
