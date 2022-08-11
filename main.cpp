#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "find.h"
using namespace std;

typedef map<string, int> word_count;

int main(int argc, char *argv[]) {
  string word;
  string f_name = argv[1];
  ifstream myFile;
  myFile.open(f_name);
  int numCount = count(argc, argv);
  traverse(myFile, numCount);
  return 0;
}
