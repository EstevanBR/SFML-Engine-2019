#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <vector>
#include <memory>

template <class T1>
class Collection {
private:
    void removeObject(T1 &t) {
        objects.erase(
            std::remove(
                objects.begin(),
                objects.end(),
                t
            ),
            objects.end()
        );
    }
    
public:
    ~Collection() {}
    Collection() {}
    std::vector<T1> objects;
    T1& getObject(size_t idx) {
        return objects[idx];
    }

    size_t createObject() {
        objects.push_back(T1());
        return objects.size()-1;
    }
};

#endif