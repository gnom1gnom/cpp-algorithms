#include <cstdio>
#include <iostream>

using namespace std;

void pointerFuncA(int *iptr, string pointer_name)
{
    /*Print the value pointed to by iptr*/
    printf("Value:  %d\n", *iptr);

    /*Print the address pointed to by iptr*/
    printf("address pointed to by the %s pointer:  %p\n", pointer_name.c_str(), iptr);

    /*Print the address of iptr itself*/
    printf("address of the %s pointer itself:  %p\n\n", pointer_name.c_str(), &iptr);
}

int main()
{
    int gettysburg{123};
    printf("original gettysburg: %d\n", gettysburg);

    // żeby pointer zainicjować zmienną trzeba przekazać jej adres
    // tak samo jest z klasami
    // ClockOfTheLongNow clock;
    // ClockOfTheLongNow* clock_ptr = &clock
    int *gettysburg_address = &gettysburg;

    pointerFuncA(gettysburg_address, "gettysburg_address");

    gettysburg = 654;
    int *gettysburg2_address = &gettysburg;
    pointerFuncA(gettysburg2_address, "gettysburg_address2");

    // stawiając gwiazdkę przed pointerem możan dostać się do obiektu do którego on sie odnosi
    // w ten sposób jeśli obiekt ma metody zamiast pisać pionter->metoda, można zrobić *pointer.metoda
    *gettysburg2_address = 17325;
    pointerFuncA(gettysburg2_address, "gettysburg_address2");

    printf("original gettysburg: %d\n", gettysburg);
}
