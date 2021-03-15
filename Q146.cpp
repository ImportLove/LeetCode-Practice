// 146. LRU Cache (Medium)

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:

    LRUCache(int capacity) {
		max_vol = capacity;
    }
    
    int get(int key) {
		if (!index.count(key))
			return -1;
		auto it = index[key];
		int k = it->first;
		int value = it->second;
		index.erase(key);

		info.erase(it);
		info.push_front(make_pair(k, value));
		index[key] = info.begin();
		
		return value;
    }
    
    void put(int key, int value) {
		if (index.count(key)){
			auto it = index[key];
			index.erase(key);

			int k = it->first;

			info.erase(it);
			info.push_front(make_pair(k, value));
			index[key] = info.begin();
			
		}
		else {
			if (info.size() == max_vol){
				int k = info.back().first;
				info.pop_back();
				index.erase(k);
			}

			info.push_front(make_pair(key,value));
			index[key] = info.begin();
		}

    }

private:
	int max_vol;
	list<pair<int, int>> info;
	unordered_map<int, list<pair<int,int>>::iterator> index;
};