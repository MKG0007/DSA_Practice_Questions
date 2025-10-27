
class LRUCache {
public:
    class node {
    public:
        int key, value;
        node* prev;
        node* next;

        node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int, node*> m;
    node* head;
    node* tail;
    int limit;

    // Helper to remove a node from the linked list
    void deletenode(node* ele) {
        ele->prev->next = ele->next;
        ele->next->prev = ele->prev;
    }

    // Helper to insert a node right after head (MRU position)
    void addnode(node* ele) {
        node* temp = head->next;
        head->next = ele;
        ele->prev = head;
        ele->next = temp;
        temp->prev = ele;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* ele = m[key];
            int val = ele->value;

            // move this node to front
            deletenode(ele);
            addnode(ele);

            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* ele = m[key];
            ele->value = value;

            // move to front
            deletenode(ele);
            addnode(ele);
        }
        else {
            if ((int)m.size() == limit) {
                // remove LRU node
                node* lru = tail->prev;
                m.erase(lru->key);
                deletenode(lru);
                delete lru;
            }

            node* newnode = new node(key, value);
            addnode(newnode);
            m[key] = newnode;
        }
    }
};

/**
 * Example usage:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
