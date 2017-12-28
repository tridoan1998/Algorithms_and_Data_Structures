//Program to return the sum of all elements in the array.
#include <iostream>
using namespace std;

//function to make the array
void sum();

int main()
{
    sum();
    return 0;
}

void sum()
{
    int size;           //create the size for the array
    cout << "Enter the size of the array: ";
    cin >> size;    // input size
    int *numberlist;    //create the array with the input size
    numberlist = new int[size];

    int counter = 0;
    while(counter < size)
    {
        int element;
        cout  << "Enter the element for spot #" << counter+ 1 << " in the array: ";
        cin >> element;
        numberlist[counter] = element;
        counter++;
    }
    for (int i = 0; i < size; i++)
        cout << "Element in spot #" << i + 1 << " is " << numberlist[i] << endl;
    delete[] numberlist;

}
