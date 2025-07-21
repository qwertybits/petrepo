//
// Created by ngixx on 20.07.2025.
//

#ifndef HASHNODE_H
#define HASHNODE_H

namespace ngixx {
    template<class K, class V>
    class HashNode {
        K key;
        V data;
        HashNode<K, V> *next = nullptr;
    public:
        HashNode(K key, V value) : key(key), data(value) {}
        ~HashNode() {
            delete next;
        }
        HashNode<K,V> *getNext() {
            return next;
        }
        void setNext(HashNode<K, V> *next) {
            this->next = next;
        }
        K getKey() {
            return key;
        }
        V& getData() {
            return data;
        }
    };
}

#endif //HASHNODE_H
