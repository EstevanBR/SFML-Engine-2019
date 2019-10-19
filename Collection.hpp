#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <vector>
#include <memory>

template <class T>
class Collection {
private:
    void removeObject(T& t) {
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
    std::vector<T> objects;
    T& getObject(size_t idx) {
        return objects[idx];
    }
    size_t createObject() {
        objects.push_back(T());
        return objects.size()-1;
    }
};

#endif