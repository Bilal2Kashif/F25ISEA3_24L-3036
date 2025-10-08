#include <iostream> 
#include <string>
#include<conio.h>
#include <cctype>  

using namespace std;

bool isPalindrome(const string& str) {
    string cleaned = str;
    int length = cleaned.length();
    int palindrome = 0;

    for (int i = 0; i < length; i++) {
        cleaned[i] = tolower(cleaned[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (cleaned[i] == cleaned[length - i - 1])
        {
            palindrome++;
        }
    }
    if (palindrome == length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() 
{
    cout << "===== Palindrome Checker =====" << endl;
    while (true) {
        cout << "Enter a word: ";
        string word;
        cin >> word;

        if (isPalindrome(word))
        {
            cout << "Palindrome" << endl;
        }
        else
        {
            cout << "Not Palindrome" << endl;
        }

        cout << "\nPress any key to check another word or press Spacebar to clear screen or ESC to quit..." << endl;
        char ch = _getch();
        if (ch == 27)
        {
            break;
        }
        if (ch == 32)
        {
            system("cls");
        }
        cout << endl;
    }

    cout << "\nProgram terminated." << endl;
    return 0;
}
