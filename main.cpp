#include "hashmap.h"

int main() {
    HashMap hsh;

    hsh.insert("one", 1);
    hsh.insert("two", 2);
	hsh.insert("three", 3);
  
    std::cout << "Original HashMap:" << std::endl;
    hsh.print();

    std::cout << "Value for key 'three': " << hsh.get("three") << std::endl;

    hsh.remove("two");

    std::cout << "HashMap after removing key 'two':" << std::endl;
    hsh.print();

    return 0;
}

