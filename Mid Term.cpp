#include <stdio.h>
#include <cstdio>    // for printf
#include <cstdlib>    // for malloc
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    //printf("This is a %c%c%c%c\n", 0x54, 0x65, 0x73, 0164);
    
    //int k = 55;
    //int* pt = &k;
    //printf ("%d", sizeof pt);
    
    //char str1[] = "abc";
    //char str2[] = {'a', 'b', 'c'};
    //char str3[] = {'a', 'b', 'c', '\0'};

    //printf ("%s \n", str1);
    //printf ("%s", str2);
    //printf ("%s \n", str3);
    
    //char str[20] = {'q','3','w','4','\0','a','b'};
    //cout << str << endl;
    
    /*int m = 88, k = 99;
    int* ptr = &m; int &a = k;
    ptr = &k;
    cout << *ptr + 2;
    cout << a - 2;*/
    
    /*char s1[] = "A C string";
    string s2("A C++ string");
    
    printf ("Length of String 1 is %d\n", sizeof(s1));
    printf ("Length of String 2 is %d\n", sizeof(s2));*/
    
    /*double sum = 88; double n = 10;
    double average = sum / n;

    printf("Average is %.2f \n", average);*/
    
    /*double x = 2.5, y = 3.6;
    int i = 12, j = 5;

    cout << pow(2.0, 3) << endl;*/
    
    /*char s1[] = "hello world! \n";
    char s2[30];
    strcpy(s2, s1);
    printf(s2);*/
    
    int x = 0b10101100;
    int y = 0b11110000;
    int temp;
    
    temp = x & y;
    cout << temp << endl;
}
