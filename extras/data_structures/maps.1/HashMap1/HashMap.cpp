#include "HashMap.h"
#include <string>
#include <iostream>

using namespace std;

/*
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
*/


 int& HashMap::operator[](const string &str)
 {
    unsigned long long ull = hash(str);
    int spot = ull % this->cap;
    
    if(v.at(spot) == 0) // empty slot
    {
      HashEntry* smash = new HashEntry(str);
      v.at(spot) = smash;
      sz++;
      return smash->val;
    }
    else //
    {
       HashEntry* ip = v.at(spot);
       for( ; ip->next != 0; ip = ip->next)
       {
          if(ip->key == str)
          {
             return ip->val;
          }
       }
       
      if(ip->key == str)
      {
         return ip->val;
      }
       
       ip->next = new HashEntry(str);
       ip = ip->next;
       return ip->val;
    }
    
 }
 
 void HashMap::remove(const string &)
 {
    
 }
 
