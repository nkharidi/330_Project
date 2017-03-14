#include <QCoreApplication>
#include <iostream>
using namespace std;

#define STRING_SIZE 1000 //limits string characters
#define CAPITAL_LETTERS "/Users/school/Documents/capitallettersmessage.txt"

//Recursive function that will extract capital letters from a string
void extractCaps(char firstString[], char secondString[], unsigned long fsPosition, int ssPosition)
{
    if (fsPosition < strlen(firstString))
    {
        if((firstString[fsPosition] >= 65 && firstString[fsPosition] <= 90)) //if the letter at this index is capital (ASCII codes for A and Z)
        {
            secondString[ssPosition] = firstString[fsPosition]; //Assign the value at fsPosition to ssPosition
            extractCaps(firstString, secondString, fsPosition + 1, ssPosition + 1); //if there is a capital letter increment the index of fsPosition and ssPosition

        }
        else
            extractCaps(firstString, secondString, fsPosition + 1, ssPosition);//if not capital just increment fsPosition

    }
}


int main()
{
    //Create an array that can hold  characters
    char firstString[STRING_SIZE] = { 0 };
    char secondString[STRING_SIZE] = { 0 };

    FILE *fp = NULL;//Opens the text file
    fp = fopen(CAPITAL_LETTERS, "r"); //r means "read only"

    //Scan string from the file
    fscanf(fp, "%s", firstString); //%s, tells what the data type of firstString is


    extractCaps(firstString, secondString, 0, 0);//Call the function and pass the string from the file as the parameter, and set fsPosition and ssPosition to 0

    cout<<secondString;
    return 0;
}

