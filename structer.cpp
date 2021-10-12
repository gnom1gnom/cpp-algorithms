#include <cstdio>
#include <iostream>

using namespace std;

struct Book {
  string name;
  int year;
  int pages;
  bool hardcover;
};

int main() {
  Book neuromancer; 
  neuromancer.pages = 271; 
  neuromancer.name = "dupa";
  printf("Neuromancer has %d pages.\n", neuromancer.pages); 
  printf("Neuromancer has %s name.\n", neuromancer.name.c_str()); 

  // initialization of struct in one line
  Book bible = {"Biblia naszego Pana Jezusa Chrystusa Króla Wszechsiawiata i Zaświata", 0, 2343, true};
  cout << bible.name << " powstała w " << bible.year << " roku. Ma " << bible.pages << " storn, opowiadających o miłosierdzi naszego Pana.\n";
}