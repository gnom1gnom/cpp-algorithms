#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long hashKey(char *key)
{
    const int p = 31;
    const long m = 1e9 + 9;
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for (char c = *key; c; c = *++key)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main(int argc, char const *argv[])
{
    int products_count = 3;
    char **products = (char **)malloc(products_count * sizeof(char *));

    products[0] = "cheese";
    products[1] = "milk";
    products[2] = "honey";

    float productPrices[] = {1, 2, 3};

    int productSold_count = 2;
    char **productSold = (char **)malloc(products_count * sizeof(char *));

    productSold[0] = "cheese";
    productSold[1] = "milk";

    float soldPrice[] = {1, 4};

    int errors = 0;

    int dictsize = products_count * 1000;
    float dict[dictsize];

    printf("dict size: %d\n", dictsize);

    for (int i = 0; i < products_count; i++)
    {
        long index = hashKey(products[i]) % dictsize;
        dict[index] = productPrices[i];
        printf("%s [%d]: %f\n", products[i], index, productPrices[i]);
    }

    for (int i = 0; i < productSold_count; i++)
    {
        long index = hashKey(productSold[i]) % dictsize;
        if (dict[index] != soldPrice[i])
            errors++;
    }

    printf("errors: %d\n", errors);

    return 0;
}
