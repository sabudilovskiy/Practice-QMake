#ifndef LIST_H
#define LIST_H


#include <stdexcept>
#include <functional>

template <class INFO>
class List {
    template<class INFO_NODE>
    struct Node{
        Node<INFO_NODE>* prev;
        Node<INFO_NODE>* next;
        INFO info;
        Node(Node<INFO_NODE> *prev, Node<INFO_NODE> *next, const INFO& info) : prev(prev), next(next), info(info) {}
        Node(Node<INFO_NODE> *prev, Node<INFO_NODE> *next) : prev(prev), next(next) {}
        Node(): prev(nullptr), next(nullptr){}
    };
    Node<INFO>* _first = nullptr;
    Node<INFO>* _last = nullptr;
    int _size = 0;
public:
    template<class INFO_NODE>
    class Iterator{
        Node<INFO_NODE>* node;
    public:
        friend List<INFO_NODE>;
        Iterator(Node<INFO_NODE> *node) : node(node) {}
        INFO_NODE* operator->(){
            return &(node->info);
        }
        const INFO_NODE& operator*(void) const{
            return node->info;
        }
        INFO_NODE& operator*(void){
            return node->info;
        }
        void operator++(int){
            if (node){
                node = node->next;
            }
            else throw std::out_of_range("");
        }
        void operator--(int){
            if (node){
                node = node->prev;
            } else throw std::out_of_range("");
        }

        bool operator==(const Iterator &rhs) const {
            return node == rhs.node;
        }
        bool operator!=(const Iterator &rhs) const {
            return !(rhs == *this);
        } };
    List(){
        _first = _last = new Node<INFO>(nullptr, nullptr);
    }
    void put_begin(const INFO& info){
        _first = new Node<INFO> (nullptr, _first);
        _first->next->prev = _first;
        _first->info = info;
        if (_size==0){
            _last = _first->next;
        }
        _size++;
    }
    void put_after(const INFO& info, std::function<bool(const INFO& from_list, const INFO& added)> pred){
        Iterator<INFO> it = begin(), end = this->end();
        while (it != end && pred(*it, info)){
            it++;
        }
        it.node->next = new Node<INFO> (it.node, it.node->next, *it);
        *it = info;
        if (it.node==_last){
            _last = it.node->next;
        }
        _size++;
    }
    void put_before(const INFO& info, std::function<bool(const INFO& from_list, const INFO& added)> pred){
        Iterator<INFO> it = begin(), end = this->end();
        while (it != end && !pred(*it, info)){
            it++;
        }
        it.node->next = new Node<INFO> (it.node, it.node->next, *it);
        *it = info;
        if (it==_last){
            _last = it.node->next;
        }
        _size++;
    }
    void clear(){
        auto it = _first->next;
        while (it){
            auto next = it->next;
            delete it;
            it = next;
        }
        _first->next = nullptr;
        _last = _first;
        _size = 0;
    }
    ~List(){
        clear();
        delete _first;
    }
    auto begin(){
        return Iterator<INFO>(_first);
    }
    auto end(){
        return Iterator<INFO>(_last);
    }
};
#endif // LIST_H
