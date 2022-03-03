#include <iostream>         // CPP 2022
#include<string>

using namespace std;
// Below are solutions to exercises that are designed to help you prepare for
// your Mini CA Quizzes and also for the upcoming CA1 Lab Test.
// Make sure to attempt the exercise sheet yourself, and then compare your
// answers with the ones presented here.


//Q1    -- using pointer notation to access arrays
bool allEqualTest(int *ptr_array1, int *ptr_array2, int size1, int size2) {

    if (size1 != size2) return false;

    for (int i = 0; i < size1; i++) {
        if (*ptr_array1 != *ptr_array2)
            return false;   // arrays are not equal

        ptr_array1++; // move the pointer to the next element
        ptr_array2++;
    }
    // if we finish the above for loop, that no unequal elements were encountered,
    // so the elements must be the same, so return true;

    return true;
}

// Q2
int calculateTotalLength(string *ptr_str, int size) {
    int length = 0;
    for (int i = 0; i < size; i++) {
        //cout << *ptr_str;
        length = length + (*ptr_str).size();    // dereference pointer to get string object, then call size()
        ptr_str++;
    }
    return length;
}

//Q3
int findFirstDuplicate(string *array_ptr, int size) {
    string firstElement = (*array_ptr); // take copy of first element

    array_ptr++;    // increment pointer to point at second element
    for (int i = 1; i < size; i++) {  // skip first element by setting i=1
        if (firstElement.compare(*array_ptr) == 0) {// if equal
            return i;   // using i as index location
        }
        array_ptr++;    // move on to next element
    }
    return 0;   // means no duplicate found
}

// Q4
int count1and3(int* array_ptr, int size){
    int count=0;
    for(int i=0; i<size; i++)
    {
        if((*array_ptr)==1 || (*array_ptr)==3)
            count++;

        array_ptr++;
    }
    return count;
}

int main() {
    std::cout << "Quiz 2 - Preparation Exercises" << std::endl;

    // Question 1

    int array1[] = {10, 20, 30};
    int array2[] = {10, 20, 55};
    int size1 = sizeof(array1) / sizeof(int); // calculates number of elements in array
    int size2 = sizeof(array2) / sizeof(int); // calculates number of elements in array
    // size of the whole array in bytes divided by size of an element gives number of elements

    // are all corresponding elements equal?
    bool allEqual = allEqualTest(array1, array2, size1, size2);

    cout << "Q1 all elements equal? = " << allEqual << endl;

    // Question 2
    string array[] = {"belt", "hat", "jelly", "bubble gum"};

    int size = sizeof(array) / sizeof(string);

    int totalLength = calculateTotalLength(array, size);
    cout << "Q2 totalLength = " << totalLength << endl;

    // Question 3
    string words[] = {"alpha", "beta", "gamma", "delta", "alpha", "psi", "pi"};
    size = sizeof(words) / sizeof(string);

    int index = findFirstDuplicate(words, size);
    cout << "Q3 - index position returned = " << index << endl;

    // Q4 count 1s and 3s

    int numbers[] = {1,4,5,3,1,3,9};
    size = sizeof(numbers)/sizeof(int);
    int count = count1and3(numbers,size);
    cout << "Q4 - count of 1's and 3's = " << count << endl;
    return 0;
}
