class LRUCache {
private:
	struct CacheNode {
		int key;
		int value;
		CacheNode* prev;
		CacheNode* next;
		CacheNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
		CacheNode(int k, int v) :key(k), value(v), prev(nullptr), next(nullptr) {}
	};

	void remove_node(CacheNode* node) {
		//cout << node->value << endl;
		node->next->prev = (node->prev) ;
		node->prev->next = (node->next) ;
		//delete node;
	}

	//头部插入节点
	void insert_node(CacheNode* node) {
		node->next = m_head->next;
		node->prev = m_head;
		m_head->next->prev = node;
		m_head->next = node;
	}

	void move_to_head(CacheNode* node) {
		remove_node(node);
		insert_node(node);
	}

	int remove_tail() {
		CacheNode* temp = m_tail->prev;
		remove_node(temp);
		//delete temp;
		return temp->key;
	}

	CacheNode* m_head;
	CacheNode* m_tail;
	std::unordered_map<int, CacheNode*> m_cache_map;
	int m_capacity;



public:
	LRUCache(int capacity) {
		//init list
		m_capacity = capacity;
		m_head = new CacheNode();
		m_tail = new CacheNode();
		m_head->next = m_tail;
		m_tail->prev = m_head;


	}

	int get(int key) {
		auto iter = m_cache_map.find(key);
		if (iter != m_cache_map.end()) {
			move_to_head(iter->second);
			return iter->second->value;
		}
		return -1;
	}


	
	
	void put(int key, int value) {
		auto iter = m_cache_map.find(key);
		if (iter != m_cache_map.end()) {
            move_to_head(iter->second);
			iter->second->value = value;
			return;
		}

		if (m_cache_map.size() >= m_capacity) {
			int tail_key = remove_tail();
			m_cache_map.erase(tail_key);
		}
		
		CacheNode* cur = new CacheNode(key, value);
		m_cache_map.insert({ key,cur });
		insert_node(cur);

		return;

	}
};
