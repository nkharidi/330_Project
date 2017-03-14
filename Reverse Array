#include <QCoreApplication>
#include <iostream>
using namespace std;

void printArray( int i, int arr[], int count) //recursive function to print the array before reverse
{
    if(i >= count)
    {
        return; //if i is less than or equal to count do nothing
    }
    cout<<arr[i] << " "; //prints the number
    printArray(i+1,arr, count); //then increments the number and then calls itself to print


}


void reverse(int i,int arr[], int count, int value) //function to reverse elements in the array
{
    if(i > count)
    {
        return; //if i is less than or equal to count do nothing
    }

    reverse(i+1, arr , count, arr[i+1]);//function calls itself to increment

    arr[count-i-1] = value;

    //cout<< value <<" "; //then prints the number

}


int main ()
{
    const int SIZE = 10;
    int arr [SIZE] = {10,9,8,7,6,5,4,3,2,1};
    int i=0;
    //int value;
    cout<<"Before reverse\n";
    printArray(0,arr, SIZE); //calls the funtion to print the array
    cout<<endl<<"After reverse\n";
    reverse(0,arr, SIZE, arr[i]); //calls the function to print the reversed array


    for(int i=0; i<SIZE; i++)
    {
        cout << arr[i]<<" ";
    }

    //cout<< value <<" "; //then prints the number
    return 0;
}


