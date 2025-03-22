#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  int row, column;
  std::cin >> row >> column;

  while (row && column) {
    // 'C','D','E','G','A' Hash map
    std::unordered_map<char, int> alphaTable{
        {'C', 0}, {'D', 0}, {'E', 0}, {'G', 0}, {'A', 0},
    };
    // Input matrix and count
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        // Temp variable to store input
        char temp;
        std::cin >> temp;

        // And then add count to hashmap
        const auto findResult = alphaTable.find(temp);
        if (findResult == alphaTable.end()) {
          std::cout << "Not found! \n";
          return 1;
        }

        findResult->second++;
      }
    }

    // Then extract from hashmap into a vector and sort using custom algorithm
    std::vector<std::pair<char, int>> sortingTable;
    for (const auto &pair : alphaTable) {
      sortingTable.push_back(pair);
    }

    // Sort
    std::sort(sortingTable.begin(), sortingTable.end(),
              [&](const std::pair<char, int> &p1,
                  const std::pair<char, int> &p2) -> bool {
                if (p1.second == p2.second) {
                  return p1.first < p2.first;
                }
                return p1.second > p2.second;
              });

    // Print result
    for (int i = 0; i < sortingTable.size(); i++) {
      std::cout << sortingTable[i].first << ' ' << sortingTable[i].second
                << " \n"[i == sortingTable.size() - 1];
    }

    // Input again
    std::cin >> row >> column;
  }

  return 0;
}