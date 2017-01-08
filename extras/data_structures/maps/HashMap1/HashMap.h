#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <iostream>
#include <vector>
using namespace std;

class HashMap {
  private:
    struct HashEntry {
      string key;
      int val;
      HashEntry *next;
      HashEntry(string key) : key(key), val(0), next(0) { }
    };

    vector<HashEntry*> v;
    unsigned cap;
    unsigned sz;
    
  public:
    HashMap(unsigned cap) : cap(cap), v(cap, 0), sz(0) { }

    // TODO // 
    int &operator[](const string &);
    void remove(const string &);
    unsigned count(const string &); //Should either be 1 or 0 if we have or don't have the key/val pair
    
    unsigned size() {
        return sz;
    }

    
  private:
    unsigned long long hash(const string &key) { 
      unsigned long long hash = 5381;
      for (size_t i = 0; i < key.size(); ++i) {
        hash = hash * 33 + key.at(i);
      }
      return hash;
    }

};

#endif