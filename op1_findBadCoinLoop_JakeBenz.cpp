#include <iostream>
#include <cstdlib>    // for srand() and rand()
#include <time.h>    // for time()
#include <string>    // for getline()

using namespace std;

void pickUpBadNumAndWeight(int &badNum, int &badWeight);
void setUpBadCoin(int badnum, int badWeight, int array[]);
void findTheBadCoin(int array[]);
void printOutCoins(int array[]);

int main()
{
    // Print header.
    cout << "==================================================================\n";
    cout << "Harper CSC211-248 by Mr. Jin Guo: Optional #1 Summer 2019 \n";
    cout << "Student: <Your Name>\n\n";
    cout << "There are 12 coins and one of them is bad. It's either lighter or \n";
    cout << "heavier. First specify the bad one and its weight. Then find the \n";
    cout << "bad and print out the list of coins to verify it.\n";
    cout << "==================================================================\n";
    
    //int n = 12;
    //int array[11];
    int badNum;
    int badWeight; // 9 is used for lighter and 11 for heavier.
    string choice;
    
    do
    {
        // Set 10 as good weight for every coine at the beginning.
        int array[12] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        
        pickUpBadNumAndWeight(badNum, badWeight);
        
        // Set up the bad coin.
        setUpBadCoin(badNum, badWeight, array);
        
        cout << "Find the secret bad coin...\n\n";
        findTheBadCoin(array);
        
        cout << "\n==> To veriy the answer, here is the list of coins:\n";
        printOutCoins(array);
        
        cin.ignore(256, '\n'); // this may be needed to clear the buffer
        cout << "\nDo you want to play this again?\n";
        cout << "(yes/YES to continue) ==> ";
        cin >> ws;
        getline(cin, choice);
    } while (choice.substr(0, 3) == "yes" || choice.substr(0, 3) == "YES");
    
    cout << endl;
    
    return 0;
}

void pickUpBadNumAndWeight(int &badNum, int &badWeight)
{
    char ch;
    
    cout << "\n------------------------------------------------\n";
    cout << "Do you want to choose which coin is bad? (y/n): ";
    cin >> ch;
    
    if (ch == 'y' || ch == 'Y')
    {
        cout << "Please enter the bad coin (1-12): ";
        cin >> badNum;
        cout << "\nPlease specify bad coin to lighter or heavier (l or h): ";
        cin >> ch;
        badWeight = (ch == 'l') ? 9 : 11;
    }
    else
    {
        cout << "OK, computer will randomly choose a bad lighter or heavier coin...\n";
        
        // Seed the rand() by using the time function.
        int t = (int)(time(0));    // convert to int to avoid a warning
        srand(t);                    // seed random number generator
        
        badNum = 1 + rand() % 12;            // randomly choose a bad coin.
        badWeight = (rand() % 2) ? 9 : 11;    // randomly choose ligher or heavier.
    }
}

void setUpBadCoin(int badNum, int badWeight, int array[])
{
    switch (badNum)
    {
        case 1: array[0] = badWeight; break;
        case 2: array[1] = badWeight; break;
        case 3: array[2] = badWeight; break;
        case 4: array[3] = badWeight; break;
        case 5: array[4] = badWeight; break;
        case 6: array[5] = badWeight; break;
        case 7: array[6] = badWeight; break;
        case 8: array[7] = badWeight; break;
        case 9: array[8] = badWeight; break;
        case 10: array[9] = badWeight; break;
        case 11: array[10] = badWeight; break;
        case 12: array[11] = badWeight; break;
            
        default:
            cout << "Something wrong! Debug your program!\n\n";
    }
}

void printOutCoins(int array[])
{
    cout << "A1 = " << array[0] << ", \t";
    cout << "A2 = " << array[1] << ", \t";
    cout << "A3 = " << array[2] << ", \t";
    cout << "A4 = " << array[3] << ", \t\n";
    cout << "A5 = " << array[4] << ", \t";
    cout << "A6 = " << array[5] << ", \t";
    cout << "A7 = " << array[6] << ", \t";
    cout << "A8 = " << array[7] << ", \t\n";
    cout << "A9 = " << array[8] << ", \t";
    cout << "A10 = " << array[9] << ", \t";
    cout << "A11 = " << array[10] << ", \t";
    cout << "A12 = " << array[11] << " \t\n";
}

void findTheBadCoin(int array[])
{
    int sum1_4 = array[0] + array[1] + array[2] + array[3]; //1 + 2 + 3 + 4 array addresses
    int sum5_8 = array[4] + array[5] + array[6] + array[7]; //5 + 6 + 7 + 8 array addresses
    //int sum9_12 = array[8] + array[9] + array[10] + array[11]; //9 + 10 + 11 + 12 array addresses
    
    if (sum1_4 == sum5_8) //Bad is A9-12
    {
        cout << "Weigh #1: A1 + A2 + A3 + A4 = A5 + A6 + A7 + A8." << endl;
        cout << "==> Found the bad coin is in A9 through A12." << endl;
        cout << endl;
        
        if ((array[0] + array[8]) == (array[9] + array[10])) // 1 + 9 = 10 + 11
        {
            cout << "Weigh #2: A1 + A9 = A10 + A11." << endl;
            cout << "==> Found A12 is the bad coin." << endl;
            cout << endl;
            cout << "Weigh #3: A1 (Good Coin) vs A12." << endl;
            
            if (array[0] == array[11])
                cout << "==> Error. Not Possible." << endl;
            else if (array[0] > array[11])
                cout << "==> Found that A12 is the bad coin and it's lighter." << endl;
            else
                cout << "==> Found that A12 is the bad coin and it's heavier." << endl;
        }
        
        else if ((array[0] + array[8]) < (array[9] + array[10])) // 1 + 9 < 10 + 11
        {
            cout << "Weigh #2: A1 + A9 < A10 + A11." << endl;
            cout << "==> Found the bad coin in A9 though A11." << endl;
            cout << endl;
            cout << "Weigh #3: A10 vs A11." << endl;
            if (array[9] == array[10])
                cout << "==> Found that A9 is the bad coin and it's lighter." << endl;
            else if (array[9] < array[10])
                cout << "==> Found that A11 is the bad coin and it's heavier." << endl;
            else
                cout << "==> Found that A10 is the bad coin and it's heavier." << endl;
        }
        
        else // 1 + 9 > 10 + 11
        {
            cout << "Weigh #2: A1 + A9 > A10 + A11." << endl;
            cout << "==> Found the bad coin in A9 though A11." << endl;
            cout << endl;
            cout << "Weigh #3: A10 vs A11." << endl;
            if (array[9] == array[10])
                cout << "==> Found that A9 is the bad coin and it's heavier." << endl;
            else if (array[9] < array[10])
                cout << "==> Found that A10 is the bad coin and it's lighter." << endl;
            else
                cout << "==> Found that A11 is the bad coin and it's lighter." << endl;
        }
    }
    else if (sum1_4 > sum5_8)
    {
        cout << "Weigh #1: A1 + A2 + A3 + A4 > A5 + A6 + A7 + A8." << endl;
        cout << "==> Found the bad coin is in A1 through A8." << endl;
        cout << endl;
        
        if ((array[0] + array[1] + array[4]) == (array[2] + array[5] + array[11]))
        {
            cout << "Weigh #2: A1 + A2 + A5 = A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A7 + A8." << endl;
            if (array[6] == array[7])
                cout << "==> Found that A4 is the bad coin and it's heaiver." << endl;
            else if (array[6] < array[7])
                cout << "==> Found that A7 is the bad coin and it's lighter." << endl;
            else //array6 > array7
                cout << "==> Found that A8 is the bad coin and it's lighter." << endl;
        }
        
        else if ((array[0] + array[1] + array[4]) < (array[2] + array[5] + array[11]))
        {
            cout << "Weigh #2: A1 + A2 + A5 < A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A3 + A12." << endl;
            if (array[2] == array[11])
                cout << "==> Found that A5 is the bad coin and it's lighter." << endl;
            else if (array[2] < array[11])
                cout << "Error. Not Possible." << endl;
            else //array6 > array7
                cout << "==> Found that A3 is the bad coin and it's heavier." << endl;
        }
        
        else
        {
            cout << "Weigh #2: A1 + A2 + A5 > A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A1 + A2." << endl;
            if (array[0] == array[1])
                cout << "==> Found that A6 is the bad coin and it's lighter." << endl;
            else if (array[0] < array[1])
                cout << "==> Found that A2 is the bad coin and it's heavier." << endl;
            else //array6 > array7
                cout << "==> Found that A1 is the bad coin and it's heavier." << endl;
        }
    }
    else
    {
        cout << "Weigh #1: A1 + A2 + A3 + A4 < A5 + A6 + A7 + A8." << endl;
        cout << "==> Found the bad coin is in A1 through A8." << endl;
        cout << endl;
        
        if ((array[0] + array[1] + array[4]) == (array[2] + array[5] + array[11]))
        {
            cout << "Weigh #2: A1 + A2 + A5 = A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A7 + A8." << endl;
            if (array[6] == array[7])
                cout << "==> Found that A4 is the bad coin and it's lighter." << endl;
            else if (array[6] < array[7])
                cout << "==> Found that A8 is the bad coin and it's heavier." << endl;
            else //array6 > array7
                cout << "==> Found that A7 is the bad coin and it's heavier." << endl;
        }
        
        else if ((array[0] + array[1] + array[4]) < (array[2] + array[5] + array[11]))
        {
            cout << "Weigh #2: A1 + A2 + A5 < A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A1 + A2." << endl;
            if (array[0] == array[1])
                cout << "==> Found that A6 is the bad coin and it's heavier." << endl;
            else if (array[0] < array[1])
                cout << "==> Found that A1 is the bad coin and it's lighter." << endl;
            else //array6 > array7
                cout << "==> Found that A2 is the bad coin and it's lighter." << endl;
        }
        
        else
        {
            cout << "Weigh #2: A1 + A2 + A5 > A3 + A6 + A12." << endl;
            cout << "==> Found the bad coin A1 through A8." << endl;
            cout << endl;
            cout << "Weigh #3: A3 + A12." << endl;
            if (array[2] == array[11])
                cout << "==> Found that A5 is the bad coin and it's heavier." << endl;
            else if (array[2] < array[11])
                cout << "==> Found that A3 is the bad coin and it's lighter." << endl;
            else //array6 > array7
                cout << "==> Error. Not Possible." << endl;
        }
    }
}
