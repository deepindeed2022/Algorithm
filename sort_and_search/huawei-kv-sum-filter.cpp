#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <iostream>
using namespace std;

int number(std::vector<std::pair<string,int>> test){
  std::map<std::string,int> count;
  for (auto &p: test){
    if (count.find(p.first)==count.end()){
      count[p.first] = p.second;
    } else {
      count[p.first]+= p.second;
    }
  }
  int res = 0;
  for (auto &c : count){
    if (c.second > 10) res++;
  }

  return res;
}
void split_line(std::string &line, std::string* s, int *value) {
  int len = line.size();
  if (len <= 0) std::cerr << "Error" << std::endl;
  int idx = 0;
  while (line[idx] != ',')
    idx++;
  *s = line.substr(0, idx);
  while (line[idx] == ',')
    idx++;
  *value = std::atoi(line.substr(idx, len).c_str());
}

int main(int argc, char const *argv[]) {
  std::ifstream infile;
  infile.open(argv[1], std::ios::in);
  if (!infile.is_open()) {
    return -1;
  }
  std::string line;
  std::vector<std::pair<std::string, int>> test_data;
  while (!infile.eof()) {
    getline(infile, line, '\n');
    std::string s;
    int value;
    split_line(line, &s, &value);
    test_data.emplace_back(s, value);
  }

  infile.close();
  std::cout << number(test_data) << std::endl;
  return 0;
}