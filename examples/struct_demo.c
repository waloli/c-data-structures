#include <stdio.h>
#include <string.h>

struct Date {
    int year, month, day;
};

struct Person {
    char name[32];
    int age;
    struct Date dob;               /* nested struct */
};

int main(void)
{
    /* 1. Initialisation and direct access with "." */
    struct Person p = {"Ana", 28, {1997, 3, 2}};
    p.age = 29;                    /* dot */
    strcpy(p.name, "Ben");         /* arrays can't be assigned: use strcpy */
    printf("%s is %d\n", p.name, p.age);

    /* 2. Indirect access through a pointer with "->" */
    struct Person *pp = &p;
    pp->age = 30;                  /* arrow (preferred) */
    (*pp).age = 31;                /* equivalent, less readable */
    printf("%s is now %d\n", pp->name, p.age);

    /* 3. Nested struct: "." for the first level, then "." or "->" again */
    printf("%s born %d-%02d-%02d\n",
           p.name, p.dob.year, p.dob.month, p.dob.day);
    pp->dob.year = 2000;           /* pointer, then nested member */
    printf("Updated year: %d\n", p.dob.year);

    /* 4. Structs are copied by value when assigned or passed */
    struct Person copy = p;
    copy.age = 99;
    printf("original %d, copy %d\n", p.age, copy.age);

    /* 5. Arrays of structs */
    struct Person group[2] = {{"Lina", 20, {2005, 7, 15}}, {"Omar", 22, {2003, 1, 9}}};
    for (int i = 0; i < 2; i++) {
        printf("group[%d]: %s (%d)\n", i, group[i].name, group[i].age);
    }

    return 0;
}
