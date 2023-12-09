#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <vector>
#include <forward_list>
#include <string>
class HashMap{
private:
static const int initialSize = 10;
static const double loadFactor;
	struct KeyValuePair{
		std::string key;
		int val;
	};

	using slot = std::forward_list<KeyValuePair>;
	std::vector<slot> table;
	int m_size;

	int HF(const std::string&) const;
	void rehash();
public:
	HashMap();
	void insert(const std::string& key, int value);
    int get(const std::string& key) const;
    void remove(const std::string& key);
    void print() const;
};
#endif //HASHMAP_H
