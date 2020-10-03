#include<string> 
using namespace std;

template <typename V>
class mapNode {
public:
	string key;
	V value;
	mapNode *next;

	mapNode(string key, V value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~mapNode() {
		delete next;
	}
};

template <typename V>
class ourMap {
	mapNode<V> **buckets;
	int count;
	int numBucket;

public:
	ourMap() {
		count = 0;
		numBucket = 5;
		buckets = new mapNode<V>*[numBucket];
		for(int i = 0; i < numBucket; i++) {
			buckets[i] = NULL;
		}
	}

	~ourMap() {
		for(int i = 0; i < numBucket; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	float getLoadFactor() {
		return (1.0 * count) / numBucket;
	}

private:
	int getBucketIndex(string key) {
		int hashCode = 0;
		int currentCoeff = 1;
		for(int i = key.length() - 1; i >= 0; i++) {
			hashCode += currentCoeff * key[i];
			hashCode %= numBucket;
			currentCoeff *= 37;
			currentCoeff %= numBucket;
		}
		return hashCode % numBucket;
	}

	void rehash() {
		
	}

public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V> *head = buckets[bucketIndex];
		while(head != NULL) {
			if(head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		mapNode<V> *node = new mapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
		float loadFactor = (1.0 * count) / numBucket;
		if(loadFactor > 0.7) {
			rehash();
		}
	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V> *head = buckets[bucketIndex];
		mapNode<V> *prev = NULL;
		while(head != NULL) {
			if(head->key == key) {
				if(prev == NULL) {
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
				head->next = NULL;
				V temp = head->value;
				delete head;
				count--;
				return temp;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V> *head = buckets[bucketIndex];
		while(head != NULL) {
			if(head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}
};
