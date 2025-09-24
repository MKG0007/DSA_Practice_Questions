class SpecialQueue {
    multiset<int> l;
    queue<multiset<int>::iterator> q;

  public:

    void enqueue(int x) {
        auto it = l.insert(x);
        q.push(it);
    }

    void dequeue() {
        auto it = q.front();
        l.erase(it);
        q.pop();
    }

    int getFront() {
        auto it = q.front();
        return *it;
    }

    int getMin() {
        auto it = l.begin();
        return *it;
    }

    int getMax() {
        auto it = l.end();
        it--;
        return *it;
    }
};