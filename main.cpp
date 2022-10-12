// Author   : Austin Klein
// Date     : 12-OCT-22
// Purpose  : Assignment 2 Part 4
// Details  :
//              Decrypting the enemy message :
//                  * Message : {,vtaNm a_"dabp!!}
//                  * 16 Chars long
//                  * Steps :
//                      -> Original Message
//                      -> treat each 4 bytes as an int
//                      -> add the secret key
//                      -> cast the integer back to a string
//                  * Given         : The secret key is between 1 and 500
//                  * Conjecture    : Since this will be English, we can assume since the last two chars
//                                      are the same, it will be a word or phrase that would have two of
//                                      the same letter at the end.
//
//                                    For ex: ball, off, add, app, boo, egg, inn, tee, and mass
//                                      A good starting point would be to find the difference between
//                                      ASCII '!' and each of the end letters from the mentioned words
//                                      as these are likely keys
// ********************************************************************************************************* //


#include <iostream>
using namespace std;

// /////////////////////////////////////////////////////////////
// /////////////////  FUNCTION PROTOTYPES  /////////////////////
// /////////////////////////////////////////////////////////////

/*void shift_cypher(const int *startAddress, int key, int *shifted_ints);
void print_int_arr(int int_arr[]);
void print_shifted_word(int pInt[], char *message);*/
void initArray(const char* originalArray, char* resetMe);
void printArray(char* arrAddress);


// /////////////////////////////////////////////////////////////
// /////////////////////  MAIN PROGRAM  ////////////////////////
// /////////////////////////////////////////////////////////////

int main()
{
    // Formatting
    cout <<  endl;

    // Allocations @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // Original message
    const char message[17] =    {',', 'v', 't', 'a', // (Hex) 2C 76 74 61 -> (Dec) 745 960 545
                                'N', 'm', ' ', 'a',
                                '_', '"', 'd', 'a',
                                'b', 'p', '!', '!'};    // [17] = 16 elements + \n
    const char* message_location = message;               // Assign location to the pointer

    ////////////////////////////////////////////
    char workingCharArray[17];
    char* workingCharArray_Location = workingCharArray;

    /*char test = 'a';
    char* test_ptr = &test;

    cout << *test_ptr << endl;*/

    int key;

    int exit = 0;
    while (exit == 0)
    {
        /*cout << "Enter a key : ";
        cin >> key;*/
        key = 12;

        initArray(message_location, workingCharArray_Location);

        int* intArr = (int *)workingCharArray;

        for (int i = 0; i < 4; i++) {
            *intArr + i = *intArr + key;
        }
        cout << endl;

        printArray(workingCharArray_Location);

        // Continue Loop Conditional
        cout << "Exit? : ";
        cin >> exit;
    }


    ////////////////////////////////////////////

    /*
    int integer_message[4] =    {0,
                                 0,
                                 0,
                                 0};

    for (int i = 0; i < 4; i++) {
        integer_message =
    }

    int shifted_int_message[4] =    {0,
                                     0,
                                     0,
                                     0};

    int key;
    int exit = 0;

    // Logic @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    while (exit == 0)
    {
        cout << "Key? : " ;
        cin >> key;

        shift_cypher(integer_message, key, shifted_int_message);

        print_int_arr(shifted_int_message);

        message_location = (char *)&shifted_int_message[0];
        print_shifted_word(shifted_int_message, message_location);

        cout << "Exit? : ";
        cin >> exit;
    }

    cout << endl;*/

    return 0;
}


// /////////////////////////////////////////////////////////////
// /////////////////  FUNCTION DEFINITIONS  ////////////////////
// /////////////////////////////////////////////////////////////


void initArray(const char* originalArray, char* resetMe)
{
    for (int element = 0; element < 17; element++) {
        resetMe[element] = originalArray[element];
    }
}

void printArray(char* arrAddress)
{
    for (int i = 0; i < 16; i++) {
        cout << arrAddress[i] ;
    }
    cout << endl;
}


void shift_cypher(const int *startAddress, int key, int *shifted_ints)
{
    for (int number = 0; number < 4; number++) {
        shifted_ints[number] = startAddress[number] + key;
    }
}

void print_int_arr(int int_arr[])
{
    for (int i = 0; i < 4; i++) {
        cout << int_arr[i] << ' ';
    }
}

void print_shifted_word(int pInt[], char *message) {
    cout << endl;
    for (int letter = 0; letter < 16; letter++) {
        cout << *message;
        message ++;
    }
    cout << endl;
}
