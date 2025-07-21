//
// Created by ngixx on 20.07.2025.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashNode.h"

namespace ngixx {
    template<class K, class V>
    class HashTable {
        HashNode<K, V>** table;
        int size = 31;
    public:

        HashTable() {
            table = new HashNode<K, V>*[size];
            for (int i = 0; i < size; i++) {
                table[i] = nullptr;
            }
        }

        ~HashTable() {
            for (int i = 0; i < size; i++) {
                delete table[i];
            }
            delete[] table;
        }

        void add(K key, V value) {
            int index = hash(key);
            auto* newNode = new HashNode<K, V>(key, value);
            HashNode<K,V>* node = table[index];
            if (node == nullptr) {
                table[index] = newNode;
                return;
            }
            while (node->getNext() != nullptr) {
                node = node->getNext();
            }
            node->setNext(newNode);
        }

        V& get(K key) const {
            int index = hash(key);
            auto node = table[index];
            while (node != nullptr) {
                if (node->getKey() == key) {
                    return node->getData();
                }
                node = node->getNext();
            }
            throw std::out_of_range("Key not found");
        }

        const V& operator[](K key) const {
            return get(key);
        }

        V& operator[](K key) {
            try {
                return get(key);
            } catch (std::out_of_range& e) {
                add(key, V());
                return get(key);
            }
        }

    private:
        int hash(K key) const {
            if constexpr (std::is_same_v<K, int>) {
                return key % size;
            }
            if constexpr (std::is_same_v<K, std::string>) {
                const auto castedKey = dynamic_cast<const std::string&>(key);
                return hashStr(castedKey);
            }
            throw std::runtime_error("Invalid key type");
        }
        [[nodiscard]] int hashStr(const std::string& key) const {
            int hash = 0, acc = 0;
            for (int i = 0; i < key.length(); i++) {
                acc += static_cast<int>(key[i]);
            }
            hash = acc % size;
            return hash;
        }
    };
}

#endif //HASHTABLE_H
