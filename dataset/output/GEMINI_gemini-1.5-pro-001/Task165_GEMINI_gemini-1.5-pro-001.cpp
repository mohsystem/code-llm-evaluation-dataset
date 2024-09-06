#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool checkFlush(vector<string> table, vector<string> hand) {
  unordered_map<char, int> suits;
  suits['S'] = 0;
  suits['H'] = 0;
  suits['D'] = 0;
  suits['C'] = 0;
  for (string card : table) {
    suits[card.back()]++;
  }
  for (string card : hand) {
    suits[card.back()]++;
  }
  for (auto it = suits.begin(); it != suits.end(); it++) {
    if (it->second >= 5) {
      return true;
    }
  }
  return false;
}