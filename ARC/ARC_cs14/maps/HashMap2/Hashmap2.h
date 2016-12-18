
#ifndef __HASH_MAP__
#define __HASH_MAP__

#include <vector>
#include <functional>

template <class K, class V>
class HashMap {
  private:
    struct HashEntry {
      const K key;
      V val;
      HashEntry *next;
      HashEntry(const K &key) : key(key), val(), next(0) { }
    };

    std::vector<HashEntry*> v;
    unsigned cap;
    unsigned sz;
    
  public:
    HashMap(unsigned cap) : v(cap, 0), cap(cap), sz(0) { }

    // TODO // 
    V &operator[](const K &);
    void remove(const K &);
    unsigned count(const K &); //Should either be 1 or 0 if we have or don't have the key/val pair
    
    unsigned size() {
        return sz;
    }
    
    ~HashMap() { /*write me!*/ }
  private:
    size_t hash(const K &key) { 
        std::hash<K> hash_fn;
        return hash_fn(key);
    }

};

#endif //__HASH_MAP__