#include <vector>
#include <string>
#include <strings.h>
#include "LinkedList.cpp"

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;

  int hashfunction (int hashitem) { // hash function
    return hashitem % table.size();
  }

public:

    HashTable (int size) {
        table.resize (size); // resize vector to support size elements.
  }

  //destructor
  ~HashTable() {
      for (int i = 0; i < table.size(); i++)
        table[i].makeEmpty();
  }

  int size() {
    return table.size();
  }

  //ascii function for a string; returns the sum
  int ascii(const char* str) {
    int sum = 0;
    int i = 0;

    for(int i = 0; str[i]!= '\0'; i++){
        sum = sum + (int)str[i];
    }
    return sum;
    }

  void insert (T newItem) {
    int location = hashfunction(ascii(newItem.c_str())); //call hashfunction (hash key with has value)
    table[location].insertFront(newItem); // use linked list(chaining)to handle collision
  }

  bool retrieve (T & target) { // search target
    int location = hashfunction(ascii(target.c_str()));
    if(table[location].find(target)) //compare with elements in the linked list
        return true; //if found
    else
        return false;
  }

  //retrieve location of a string in the hashtable
  int retrieveLocation (T & target) {
    int location = hashfunction(ascii(target.c_str()));
    if(table[location].find(target))
        return location;
    else
        return false;
  }

  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
