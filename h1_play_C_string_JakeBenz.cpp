/*
 ====================================================================================
 Course: Harper CSC211-248 by Mr. Jin Guo, Summer 2019
 Student Name: <Jake Benz>
 
 Program Name: Play with C string
 Program Description:
 This program is for you to understand some of the C string operations.
 Even though C++ <string> class offers many utilities for string
 manipulation, programmers sometimes have to go to C string to do some
 string operations not offerred by C++ <string>. Another advantage
 about user-defined operations on C strings is less overhead for function
 calling. In this program, I implemented some operations C++ <string>
 doesn't offer.
 
 Instructions:
 1. Understand and run the given program without any change.
 2. Implement the function strReversed_v1(). Replace cout with printf. DONE
 3. Refer to s08_play_pointer_address.cpp and s09a_reverse_arrray.cpp.
 4. Understand the definitions of other functions. This should be helpful
 for you to implement strReversed_v1()
 5. Insert your code below wherever is marked "Your code below...".
 6. By doing this homework, you are required to understand well
 the following:
 1) "call by pointer" and "call by value".
 2) Some basic functions to process C strings: strcpy(), strlen(),
 strcat(), isalpha(), etc..
 3) Undertand that a C string contans a hidden null: '\0'.
 4) Understand that a C string is an array of chars.
 7. Submit only the .cpp file with your change. Rename your file properly
 with your login, e.g, h1_play_C_string_j_smith.cpp
 Notes:
 1. size_t is an unsigned integral type, commonly used for size and position.
 2. Use strcpy() or strcpy_s() from <cstring>. The _s versions
 are only available for VC++. With g++ compiler on ares, use only strcpy().
 With C string, you cannot do str = "abcd".
 3. "new" is an operator used to allocate memory dynamically.
 4. If a C string is declared without being initialized, its contents are
 garbage.
 
 Created:     9/8/2007 by Jin Guo
 Updated:    3/7/2102 by Jin Guo. Minor fix, new char[sz+1].
 Updated:    10/7/2014 by Jin Guo. Customized for Haper.
 Updated:    3/1/2015 by Jin Guo. Minor format and output change.
 Updated:    6/5/2019 by Jin Guo. Adapted for CSC211.
 =====================================================================================
 */
#include <iostream>
#include <cstring>        // for strlen(), strcpy_s(), etc.
#include <cctype>        // for isalpha() and toupper()
#include <algorithm>    // swap()

using namespace std;

/*
 =========================
 Print length and contents of a C string with size info, etc.
 
 @param str: the string to be printed.
 */
void printCString(const char* str);

/*
 =========================
 A new C string is returned as the result of concatenating
 two C strings.
 
 @param str1: the first string to be concatenated.
 @param str2: the second string to be concatenated.
 @return: the concatenated result.
 */
char* myStrCat(const char* str1, const char* str2);

/*
 =========================
 Convert contents of a C string into upper case
 
 @param str: all chars in the string will be changed to upper case.
 */
void strToUpperCase(char* str);

/*
 =========================
 A C string is passed in and passed out with the result of
 the contents reserved.
 
 @param str: the string will have its chars to be reversed.
 */
void strReversed_v1(char* str);

/*
 =========================
 A new C string is returned as the result of reversing letters
 in a C string whose contents are reserved.
 
 @param str: the string will have its chars to be reversed.
 @return: the reversed result string is returned.
 */
char* strReversed_v2(const char* str);

int main()
{
    // Print header.
    printf ("=============================================================\n");
    printf ("Harper CSC211-248 by Mr. Jin Guo: Assignment #1, Summer 2019 \n");
    printf ("Student: <Jake Benz>\n\n");
    printf ("This program is for exercising some of C string operations.\n");
    printf ("=============================================================\n\n");
    
    char str1[50], str2[50];
    
    // str3 is initialized. '\0' indicates ending of a string.
    char str3[100] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
    
    //strcpy_s( str1, "Global warming" );    // only for VC++
    //strcpy_s( str2, " is coming. " );        // only for VC++
    strcpy( str1, "Global warming" ); // str1 are assigned with "Global warming"
    strcpy( str2, " is coming. " );   // str1 are assigned with " is coming. "
    
    printf ("---- At the beginning ----\n");
    printf ("str1 (a string is copied into): ");
    printCString(str1);
    printf ("str2 (a string is copied into): ");
    printCString(str2);
    printf ("str3 (initialized when declared): ");
    printCString(str3);
    
    str3[3] = '\0'; // anything after '\0' in the str3 is ignored.
    printf ("\n---- After str3[3] = '\\0' ----\n");
    printf ("str3: ");
    printCString(str3);
    
    /**
     Use string concatenation function from <cstring>. This will cause str1
     to store the result after concatenation. str2 is not changed.
     */
    //strcat_s( str1, str2 ); // only for VC++
    strcat( str1, str2 );
    printf ("\n---- After strcat(str1, str2) ----\n");
    printf ("str1: ");
    printCString(str1);
    printf ("str2: ");
    printCString(str2);
    
    // Change the contents of str3
    //strcpy_s(str3, "Polar bear is in danger."); // only for VC++
    strcpy(str3, "Polar bear is in danger.");
    printf ("\n---- After changing the contents of str3 by strcpy()----\n");
    printf ("str3: ");
    printCString(str3);
    
    /**
     Call user-defined myStrCat(). The original contents of str1 and str3
     are reserved and a new C string is returned. str4 is just a
     pointer to char.
     */
    char* str4;
    
    str4 = myStrCat(str1, str3);
    printf ("\n---- After str4 = myStrCat(str1, str3) ----\n");
    printf ("str1: ");
    printCString(str1);
    printf ("str3: ");
    printCString(str3);
    printf ("str4: ");
    printCString(str4);
    
    // Change every letter to upper case for a given string.
    strToUpperCase(str1);
    printf ("\n---- After converting str1 into uppercase ---\n");
    printf ("str1: ");
    printCString(str1);
    
    str4 = strReversed_v2(str1);
    
    /**
     Call strReversed_v2() to reverse letters in a given string.
     and a new C string is returned. The original one is not changed.
     */
    printf ("\n---- After str4 = strReversed_v2(str1) ----\n");
    printf ("str1: ");
    printCString(str1);
    printf ("str4: ");
    printCString(str4);
    
    /*
     =========================================
     <<<<<< Your code below... >>>>>
     =========================================
     */
    printf ("\n========== My job blow...============\n");
    printf ("\n---- Using strReversed_v1(str2) ----\n");
    printf ("Before reversing--\n");
    printf ("str2: ");
    printCString(str2);
    
    // Uncomment the line below after you finished strReversed_v1()
    strReversed_v1(str2);
    printf ("After reversing--\n");
    printf ("str2: ");
    printCString(str2);
    printf ("");
    
    return 0;
}

// =====================================================================

char* myStrCat(const char* str1, const char* str2)
{
    size_t sz1, sz2, sz, i;
    
    sz1 = strlen(str1);
    sz2 = strlen(str2);
    sz = sz1 + sz2;
    char* new_str = new char[sz+1];
    
    for (i = 0; i <sz; i++)
    {
        if (i < sz1)
            new_str[i] = str1[i];
        else
            new_str[i] = str2[i - sz1];
    }
    new_str[i] = '\0'; // add ending \0.
    
    return new_str;
}

void strToUpperCase(char* str)
{
    size_t i, sz = strlen(str);
    
    for (i = 0; i < sz; i++)
    {
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);
    }
}

char* strReversed_v2(const char* str)
{
    size_t i, sz = strlen(str);
    char* new_char = new char[sz + 1]; // get memory for new_char.
    
    // Put contents of string into new_char in reversed order.
    for (i = 0; i < sz; i++)
        new_char[i] = str[sz - 1 - i];
    new_char[i] = '\0'; // null char is added to the end, new_cahr[sz];
    
    return new_char;
}

void printCString(const char* str)
{
    cout << "\"" << str << "\" | Size: " << strlen(str) << endl;
}

/*
 =========================================
 <<<<<< Your code below... >>>>>
 =========================================
 */
void strReversed_v1(char* str)
{
    int c;
    char *begin, *end, temp;
    
    strlen(str);
    begin = str;
    end = str;
    
    for (c = 0; c < strlen(str) - 1; c++)
        end++;
    
    for (c = 0; c < strlen(str) / 2; c++)
    {
        temp = *end;
        *end = *begin;
        *begin = temp;
        
        begin++;
        end--;
    }
}

/*
 ************************************************
 * (C) Copyright - by Jin Guo
 *
 * This program is free for my class students.
 * For any other purpose of using this program,
 * please ask for permisson by sending email to:
 * taiji.guo@gmail.com
 ************************************************
 */
