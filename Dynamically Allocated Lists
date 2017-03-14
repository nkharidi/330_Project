#include <QCoreApplication>
#include <string>
#include <iostream>
#include <typeinfo>
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

string getDataType(string x)
{

    string retString;

    int i = 0;


    bool isAcharacter = false;
    bool isAnumber = false;
    bool isAdecimal = false;

    if(x.length()>0)
    {

        for( i=0; i<x.length();i++)
        {

            if (    (    (x[i] >= 65  &&  x[i] <= 90) | (x[i] >= 97  &&  x[i] <= 122)   )    )
            {
                isAcharacter = true;
            }
            else if(     (x[i]>=48)   &&   (x[i]<=57)     )
            {
                isAnumber = true;
            }
            else if(x[i] == 46)
            {
                isAdecimal = true;
            }
            else
            {
                cout << "not an option" <<endl;
            }

        }

    }

    if (isAnumber == true && isAcharacter == false && isAdecimal == false)
    {
        retString = "Integer";
    }
    else if (isAnumber == true && isAdecimal == true && isAcharacter == false)
    {
        retString = "Double";
    }
    else if (x.length() < 2 && isAcharacter == true)
    {
        retString = "Character";
    }
    else if(x.length() > 1)
    {
        retString = "String";
    }
    return retString;
}


int main()
{
    //This is how you create a list for integers
    List<int> *int_list = new List<int>;
    List<double> *double_list = new List<double>;
    List<char> *char_list = new List<char>;
    List<string> *string_list = new List<string>;

    string strInt;
    string strDouble;
    string strCharacter;
    string strString;
    string strVal;
    char x[256];
    cout << "Enter your input ";
    cin >> x;



    while(string(x) != "-1")
    {
        strVal = getDataType(x);

        if (strVal == "Integer")
        {
            int_list->addNode(atoi(x));
        }

        else if (strVal == "String")
        {
            string_list->addNode(x);
        }

        else if (strVal == "Character")
        {
            char_list->addNode(x[0]);

        }

        else if(strVal == "Double")
        {
            double_list->addNode(atof(x));

        }

        cout << "Integer:";
        int_list->printListBeautify();

        cout << "Double:";
        double_list->printListBeautify();

        cout << "Character:";
        char_list->printListBeautify();

        cout << "String:";
        string_list->printListBeautify();

        cout <<" "<<endl;

        cout << "Enter your input ";
        cin >> x;
    }
}



