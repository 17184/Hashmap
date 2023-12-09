#include "hashmap.h"

const double HashMap::loadFactor = 0.7;

HashMap::HashMap() : m_size(0), table(initialSize){};

int HashMap::HF(const std::string& key) const {
	int hash = 0;
	for(char c : key) {
		hash += static_cast<int>(c);
	}
	return hash % table.size();//vector-i size
}

void HashMap::rehash() {
	int newSize = table.size() * 2;
	std::vector<slot> newTable(newSize);
	 for (const auto& slot : table) {
        for (const auto& pair : slot) {
            int newIndex = HF(pair.key);
            newTable[newIndex].push_front(pair);
        }
    }

    table = std::move(newTable);
}

void HashMap::insert(const std::string& key, int value) {
    int index = HF(key);
    table[index].push_front({key, value});
    ++m_size;

    double currentLoadFactor = static_cast<double>(m_size) / table.size();
    if (currentLoadFactor > loadFactor) {
        rehash();
    }
}
int HashMap::get(const std::string& key) const {
    int index = HF(key);
    for (const auto& pair : table[index]) {
        if (pair.key == key) {
            return pair.val;
        }
    }
      return 0;
}
void HashMap::remove(const std::string& key) {
    int index = HF(key);
    auto& slot = table[index];

	auto prev = slot.before_begin();
    auto current = slot.begin();

    while (current != slot.end()) {
        if (current->key == key) {
            current = slot.erase_after(prev);
            --m_size;
            return;
        }

        ++current;
        ++prev;
    }
}
void HashMap::print() const {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << "Slot " << i << ": ";
        for (const auto& pair : table[i]) {
            std::cout << "{" << pair.key << ": " << pair.val<< "} ";
        }
        std::cout << std::endl;
    }
}



