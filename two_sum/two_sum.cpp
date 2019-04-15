#include <unordered_map>
#include <iostream>

using std::unordered_map;
using std::cout;

void call_emplace() {
  unordered_map<int, int> mp;

  // insert elements in random order
  mp.emplace(2, 30);
  mp.emplace(1, 40);
  mp.emplace(2, 20);
  mp.emplace(1, 50);
  mp.emplace(4, 50);

  // prints the elements
  for (auto it = mp.begin(); it != mp.end(); it++)
    cout << it->first << "==>>" << it->second << "\n";
}

int array_size(int array[]) {
  int size = 0;
  while (*array) {
    *array++;
    size++;
  }

  return size;
}

int *two_sum(int needle, int haystack[]) {
  int size = array_size(haystack);

  int *indexes = new int[2];
  unordered_map<int, int> lookup;

  for (int i = 0; i < size; ++i) {
    lookup.emplace(haystack[i], i);
  }

  for (int i = 0; i < size; ++i) {
    int subtracted = needle - haystack[i];
    auto search = lookup.find(subtracted);

    if (search != lookup.end()) {
      int first_index = i;
      int second_index = lookup.at(search->first);
      indexes[0] = first_index;
      indexes[1] = second_index;
    }
  }

  return indexes;
}
