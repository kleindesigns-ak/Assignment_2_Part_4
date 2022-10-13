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
// ********************************************************************************************************* //

#include <iostream>
using namespace std;

// /////////////////////////////////////////////////////////////
// /////////////////  FUNCTION PROTOTYPES  /////////////////////
// /////////////////////////////////////////////////////////////

void initArray(const char* originalArray, char* resetMe);
void modify_working_message(int * int_ptr_working_message, int key);
void print_message(char *char_ptr_working_message, int key);

// /////////////////////////////////////////////////////////////
// /////////////////////  MAIN PROGRAM  ////////////////////////
// /////////////////////////////////////////////////////////////

int main()
{
    // Original original_message
    const char original_message[17] = {',', 'v', 't', 'a',
                                       'N', 'm', ' ', 'a',
                                       '_', '"', 'd', 'a',
                                       'b', 'p', '!', '!' };        // [17] = 16 elements + \n
    const char *char_ptr_original_message = &original_message[0];   // Assign location to the pointer

    char working_message[17];
    char* char_ptr_working_message = &working_message[0];
    int* int_ptr_working_message = (int *)working_message;

    // Check the output for all possibilities of the decryption key
    for (int ascii = 0; ascii >= -500; ascii--) {
        // number between 1 and 500 -> negative because we are decrypting
        int key = ascii;
        // Separate array is used to test solutions as to not write over the secret message
        initArray(char_ptr_original_message, char_ptr_working_message);
        // Copy of original array is used to test keys
        modify_working_message(int_ptr_working_message, key);
        // Print results of each key and the key itself
        print_message(char_ptr_working_message, key);
    }

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

void modify_working_message(int * int_ptr_working_message, int key)
{
    int* x = int_ptr_working_message;

    for (int i = 0; i < 4; i++) {
        x = int_ptr_working_message + i;
        *x += key;
    }
}

void print_message(char *char_ptr_working_message, int key)
{
    for (int ch = 0; ch < 16; ch++) {
        cout << *char_ptr_working_message;
        char_ptr_working_message ++;
    }
    cout << key << endl;
}