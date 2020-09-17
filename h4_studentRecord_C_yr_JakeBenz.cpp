#include <cstdio>    // for printf
#include <cstdlib>    // for malloc
#include <string.h>

struct Student
{
    char*       name;           // for student's name.Use char*.
    double      gpa;            // for student's gpa.
    unsigned    age : 5;        // for student's age. Use 5 bits
    unsigned    year : 3;       // grade of year: 1,2,3 or 4. Use 3 bits
};

typedef struct Student Student;

Student* constructStudent(char* name, double gpa, unsigned age, unsigned year);
void printInfo(const Student* pt);

int main()
{
    printf ("==========================================================\n");
    printf ("Harper CSC211-248 by Mr. Jin Guo: Program #4, Summer 2019\n");
    printf ("Student: <Jake Benz>\n");
    printf ("This program replaces C++ class Student wiht C struture.\n");
    printf ("==========================================================\n\n");
    
    Student* st_1 = constructStudent("", 0.0, 0, 0);
    printInfo(st_1);
    printf ("\n");
    
    Student* st_2 = constructStudent("John Smith", 3.45, 24, 2);
    printInfo(st_2);
    printf ("\n");
    
    return 0;
}

Student* constructStudent (char* name_val, double gpa_val, unsigned age_val, unsigned year_val)
{
    Student* pt;
    pt = (Student*)malloc(sizeof(Student));
    //scanf ("%s%lf%d%d", name_val, &gpa_val, &age_val, &year_val); //i dont know why I need "" for this to function properly
    pt-> name = (char*)malloc(80);
    strcpy (pt->name, name_val);
    pt-> gpa = gpa_val;
    pt-> age = age_val;
    pt-> year = year_val;
    return pt;
}

void printInfo(const Student* pt)
{
    printf ("Name: %10s \n", pt->name);
    printf ("Age: %i \n", pt->age); //depsite being unsigned, I have to use i instead of x because it gives me the wrong number
    printf ("Year: %i \n", pt->year);
    printf ("GPA: %.2f \n", pt->gpa);
}
