//templatetized map built on BST && Nodes


#ifndef __MAP_H__
#define __MAP_H__

#include "BSTree.h"

using namespace std;

//template for key and val
template <class K, class V>
struct Pair 
{
    K key;
    V val;
    Pair() { }
    Pair(K key) : key(key) { }
    Pair(K key, V val) : key(key), val(val) { }
    
    //Comparison operations for Pairs so we can make a tree of them
    bool operator==(const Pair<K, V> &rhs) const
        { 
            return this->key == rhs.key;  
        }        
    bool operator>(const Pair<K, V> &rhs) const
        { 
            return this->key > rhs.key;
        }
    bool operator<(const Pair<K, V> &rhs) const
        { 
            return this->key < rhs.key;
        }
};



//-----------------------------------------------------------------------------------
//template for key and val
template <class K, class V>
class Map : public BSTree<Pair<K, V> > {
    public:
        Map() { } //begin with an empty tree -> calls tree constructor -> inheritance...
        
        V& operator[](const K& key)
        {
            Node<Pair<K, V> > *n = this->_search(this->root, Pair<K, V>(key)); // search w/ dummy pair using only the keys
            
            if(!n)
            { 
                this->insert(Pair<K, V>(key)); 
            }
            
            Node<Pair<K, V> > *q = this->_search(this->root, Pair<K, V>(key));
            
            return q->data.val;
        }
        
        // erase
        
        // size (you may want to add a member variable for this one)
        
        bool empty()
        {
            return this->root == 0;
        }
        
        int count(const K& key) //(your count should either return 1 or 0 if we have or don't have a pair with the key)
        {
            if( !this->search(key) )
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        
        // keys (should return a vector of all keys in the map)
};


//#include "map.cpp"

#endif //__MAP_H__