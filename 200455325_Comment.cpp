//James Sieben 200455325
//CS350 A2 Question 10.3
//Program "Slash.cpp" detects the strings "/*" and "*/", prompts the user for characters, stores them as a string, and prints that string

#include <iostream>
using namespace std;

char getCharacter()             //Function prompts user for a character and returns that character
{
    char c;
    cout << "Enter a character: ";
    cin >> c;
    return c;
}

string getComment()             //Function saves user entered characters as a comment. 
{                               //Returns ERROR if comment format is wrong or returns the comment.
    string comment("/");        //Initializes the comment as a slash

    cout << "Hint: Enter '*' next to create a comment. While making a comment, enter '*' followed by '/' to stop." << endl;

    char c = getCharacter();    //Variable c is used to store the user entered character
    comment += c;               //Append the character to the comment string

    if (c != '*')               //If c is not *, the comment format is wrong, return an error
        return "ERROR: '*' wasn't entered after '/'";
    else 
    {
        while (c != '/') 
        {
            c = getCharacter();
            if (c == '/' && comment.back() == '*')  //If "*/"" is entered, the comment is finished, break from the loop
            {
                comment += c;
                break;
            } 
            else
                comment += c;

            while (c != '*')    //If * is entered, temporarily exit the loop to check for end of comment
            {
                c = getCharacter();
                comment += c;
            }
        }

        return comment;         //Return the finished comment
    }
}

int main()
{
    string comment;             //Stores user entered comment

    cout << "Enter '/' to start." << endl;
    char c = getCharacter();

    if (c == '/')               //If user enters '/' start the comment, else return an error
    {
        comment = getComment();
        cout << "The comment looks like: " << comment << endl;  //Print finished comment
    }
    else
        cout << "ERROR: '/' was not entered." << endl;  //Error if '/' is not entered first (i.e. no comment started)

    return 0;
}
 