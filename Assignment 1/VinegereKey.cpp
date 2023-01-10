/**
 * @file VinegereKey.cpp
 * @author David Todorov
 * @brief A program which encrypts and decrypts a message using Vinegere Key
 */
#include <iostream>
using namespace std;

char decryption(char vKey, char passChar)
{ /* Decrypting the message*/
    if (vKey == ' ')
    {
        return ' '; /*Returns space if orgChar is space*/
    }

    int asciiOfKey = int(vKey);
    int asciiOfPassChar = int(passChar);

    int asciiOfOrgText = asciiOfKey - (asciiOfPassChar - 65);
    if (asciiOfOrgText < 65)
    {
        asciiOfOrgText = 91 - (65 - asciiOfOrgText);
    }

    return char(asciiOfOrgText + 32); /*Returns the character in lower case*/
}

char encryption(char orgChar, char passChar)
{ /*Encrypting the message*/
    if (orgChar == ' ')
    { /*Returns space if orgChar is space*/
        return ' ';
    }
    else
    {
        int asciiOfResult = (int(orgChar) - 32) + ((int(passChar) - 65));
        if (asciiOfResult > 90)
        {
            asciiOfResult = 64 + (asciiOfResult % 90); /*If the ofse is too much we start again from letter a*/
        }
        return char(asciiOfResult);
    }
}

/**
 * @brief Testing the program
 */
int main()
{
    string orgText = "vigenere quadrat"; /*Inputted data*/
    string password = "PASSWORT PASSWOR";
    cout << "Original text -> " << orgText << endl;
    cout << "Password -> " << password << endl;
    string encr = "";
    for (int i = 0; i < orgText.length(); i++)
    {
        char orgChar = orgText[i];
        char passChar = password[i];
        encr += encryption(orgChar, passChar); /*Creating the encrypted message*/
    }
    cout << "Encrypted message -> " << encr << endl;
    string decr = "";
    for (int i = 0; i < encr.length(); i++)
    {
        char encrChar = encr[i];
        char passChar = password[i];

        decr += decryption(encrChar, passChar); /*Creating the decrypted message*/
    }
    cout << "decrypted message -> " << decr << endl;
}