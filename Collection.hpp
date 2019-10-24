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
    
public:
    ~Collection() {}
    Collection() {}
    std::vector<std::shared_ptr<T>> objects;
    std::shared_ptr<T> getObject(size_t idx) {
        return objects[idx];
    }
    template<class D>
    std::shared_ptr<D> getObject(size_t idx) {
        return std::static_pointer_cast<D>(getObject(idx));
    }

    size_t createObject() {
        objects.push_back(std::shared_ptr<T>(new T));
        return objects.size()-1;
    }

    template<class D>
    size_t createObject() {
        objects.push_back(std::shared_ptr<T>(static_cast<T *>(new D)));
        return objects.size()-1;
    }
};

#endif