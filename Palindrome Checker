#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
   string palindromeInput;
   int cnt;

   while(palindromeInput != "-1")
   {
       cout << "Enter a string, enter -1 to stop:" << endl;
   cin >> palindromeInput;


    cnt =  palindromeInput.length()/2;

   stack *ourstack = new stack();
   //Node *currentNode;


   for(int x=0; x<cnt; x++)
    {
        ourstack->Push(palindromeInput[x]);

    }

   if(palindromeInput.length() % 2 != 0)
   {
       cnt++;
   }

    for(int x=cnt; x<palindromeInput.length(); x++)
    {
        if(ourstack->Pop()->GetData() != palindromeInput[x] )
        {
            cout << "Not a palindrome" << endl;
            break;
        }

    }

    cout << "Palindrome!" << endl;

   }

}
