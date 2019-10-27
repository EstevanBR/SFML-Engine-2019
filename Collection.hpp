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
    // template<class D>
    // std::shared_ptr<D> getObject(size_t idx) {
    //     return std::static_pointer_cast<D>(objects[idx]);
    // }

    void addObject(std::shared_ptr<T> t) {
        
        objects.push_back(t);
        //return objects.size()-1;
    }

    // size_t createObject() {
    //     objects.push_back(std::shared_ptr<T>(new T));
    //     return objects.size()-1;
    // }

    // template<class D>
    // std::shared_ptr<D> createObject() {
    //     objects.push_back(std::static_pointer_cast<T>(std::shared_ptr<D>(new D)));
    //     return std::dynamic_pointer_cast<D>(objects[objects.size()-1]);
    // }
};

#endif