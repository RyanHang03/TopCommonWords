//
// Created by ryanh on 4/19/2022.
//

#ifndef TOPCOMMONWORDS__FIND_H_
#define TOPCOMMONWORDS__FIND_H_
#include <vector>

void traverse (std::ifstream& file, int numCount);
int count (int argc, char *argv[]);
std::vector<int> vect_copy (std::map<std::string, int> map);
void printNWords (std::map<std::string, int>& count_list, std::vector<int>& counts, int numCount);
class find {

};

#endif //TOPCOMMONWORDS__FIND_H_
