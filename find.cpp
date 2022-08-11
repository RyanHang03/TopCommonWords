//
// Created by ryanh on 4/19/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include "find.h"
using namespace std;

typedef map<string, int> word_count;

int count (int argc, char *argv[]) {
  if (argc == 2) {
    return 10;
  } else {
    int i = atoi(argv[2]);
    return i;
  }
}

vector<int> vect_copy (map<string, int> map) {
  vector<int> values;
  for(auto elem : map)
    values.push_back(elem.second);
  return values;
}

void printNWords (map<std::string, int>& count_list, vector<int>& counts, int numCount) {
  for (int i = 0; i < numCount; i++) {
    string output;
    string words;
    auto x = count_list.begin();
    for (x = count_list.begin(); x != count_list.end(); x++) {
      if (counts[i] == 0) { return; }
      if (x->second == counts[i]) {
        words += x->first + ", ";
      }
    }
    string beginning = to_string((i + 1)) + ".) ";
    string numTimes = to_string(counts[i]);
    output.append(beginning);
    output.append("These words appeared ");
    output.append(numTimes);
    output.append(" times: {");
    output.append(words);
    output.append("}");

    //taking care of the any combo of ", "
    if (output[output.size() - 3] == ',') {
      output.erase(output.end()-2);
      output.erase(output.end()-2);
    }
    cout << output << endl;
  }
}

void traverse (std::ifstream& myFile, int numCount) {
  int index;
  string word;
  word_count count_list;
  vector<int> counts;
  while (myFile >> word) {
    if (word.empty()) {
      continue;
    }
    while ((index = word.find_first_of(",.:;\"|!@#$%^&*()_+-=[]{}<>?/~`")) != string::npos) { //removed '
      word.erase(index, 1);
    }
    while ((index = word.find_first_of('\\')) != string::npos) { 
      word.erase(index, 1);
    }
    if (word[0] == '\'') {
      word.erase(0, 1);
    }
    if (word[word.size()-1] == '\'') {
      word.erase(word.size()-1, 1);
    }
    for (char& i : word) {
      i = tolower(i);
    }
    if (count_list[word] == 0) {
      count_list[word] = 1;
    } else {
      count_list[word] += 1;
    }
  }

  counts = vect_copy(count_list);
  sort(counts.begin(), counts.end(), greater<int>());
  counts.erase( unique( counts.begin(), counts.end() ), counts.end() );
  printNWords(count_list, counts, numCount);
}

