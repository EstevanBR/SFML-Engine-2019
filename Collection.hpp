#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <vector>
#include <memory>

template <class T>
class Collection {
private:
    void removeObject(std::shared_ptr<T> t) {
        objects.erase(
            std::remove(
                objects.begin(),
                objects.end(),
                t
            ),
            objects.end()
        );
    }
protected:
    std::vector<std::shared_ptr<T>> objects;
public:
    ~Collection() {}
    Collection() {}
    
    std::shared_ptr<T> getObject(size_t idx) {
        return objects[idx];
    }

    void addObject(std::shared_ptr<T> t) {
        
        objects.push_back(t);
    }
};

#endif