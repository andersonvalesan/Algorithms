#include <iostream>

using namespace std;

void printArray(int array[4]){
    for( int i=0; i < 4; i++ ){
        cout << array[i] << " ";
    }
}

string assertEquals(int arrayToCompare[4]){
    int sortedArray[4] = {1,5,8,10};
    int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);

    for( int i=0; i < arraySize; i++ ){
        if(sortedArray[i] != arrayToCompare[i]){
            return "false";
        }
    }

    return "true";
}

int main()
{
    int unsortedArray[4] = {5,10,8,1};
    int arraySize = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    cout << "Original array: " << endl;
    printArray(unsortedArray);

    //SelectionSort Algorithm
    for( int i = 0; i < arraySize ;i++ ){
        int j = i+1;
        int minValue = unsortedArray[i];
        int minIndex = i;
        while(j!=arraySize){
            if(unsortedArray[j]<minValue){
                minValue = unsortedArray[j];
                minIndex = j;
            }
            j++;
        }
        unsortedArray[minIndex] = unsortedArray[i];
        unsortedArray[i] = minValue;
    }

    //Testing array
    cout << "\n" << assertEquals(unsortedArray) << endl;

    cout << "Sorted array: " << endl;
    printArray(unsortedArray);
    
    return 0; 
}