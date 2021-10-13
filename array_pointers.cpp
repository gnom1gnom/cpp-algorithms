#include <cstdio>

struct College
{
    char name[256];
    int age;
};

void print_names(College *colleges, size_t n_colleges)
{
    for (size_t i = 0; i < n_colleges; i++)
    {

        printf("%s College\n", colleges[i].name);
    }
}

int main()
{
    College oxford[] = {{"Magdalen", 21}, {"Nuffield", 24}, {"Kellogg", 33}};
    print_names(oxford, sizeof(oxford) / sizeof(College));
}