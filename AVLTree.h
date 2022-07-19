#ifndef AVLTREE_H
#define AVLTREE_H
#include <QObject>
#include <stdexcept>
using byte = unsigned char;
template <class INFO>
class AVLTree
{
protected:
    template<class INFO>
    struct Node // структура для представления узлов дерева
    {
        INFO key;
        byte h;
        Node* left;
        Node* right;

        template<class... Args>
        Node(Args... args) : key(std::forward<INFO>(args)...){
            left = right = 0;
            h = 1;
        }
        Node(INFO&& k) { key = k; left = right = 0; h = 1; }
        Node(const INFO& k) { key = k; left = right = 0; h = 1; }
        ~Node(){
            if (left) delete left;
            if (right) delete right;
        }

    };
    void clear(Node<INFO>*& p){
        if (p){
            delete p;
            p = nullptr;
        }
    }
    byte height(Node<INFO>* p)
    {
        if (p){
            return p->h;
        }
        else return 0;
    }
    int bfactor(Node<INFO>* p)
    {
        return height(p->right)-height(p->left);
    }
    void fixheight(Node<INFO>* p)
    {
        byte hl = height(p->left);
        byte hr = height(p->right);
        p->h = std::max(hl, hr) + 1;
    }
    Node<INFO>* rotateright(Node<INFO>* p) // правый поворот вокруг p
    {
        Node<INFO>* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }
    Node<INFO>* rotateleft(Node<INFO>* q) // левый поворот вокруг q
    {
        Node<INFO>* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }
    Node<INFO>* balance(Node<INFO>* p) // балансировка узла p
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->right) < 0 )
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p; // балансировка не нужна
    }
    Node<INFO>* insert(Node<INFO>* p, const INFO& k, bool need_balance = true) // вставка ключа k в дерево с корнем p
    {
        if( !p ) {
            return new Node(k);
        }
        if( k<p->key ) p->left = insert(p->left,k, need_balance);
        else if (k==p->key){
            throw std::invalid_argument("");
        }
        else p->right = insert(p->right,k, need_balance);
        if (need_balance) {
            return balance(p);
        }
        else {
            return p;
        }
    }
    Node<INFO>* insert(Node<INFO>* p, INFO&& k, bool need_balance = true) // вставка ключа k в дерево с корнем p
    {
        if( !p ) {
            return new Node(std::forward<INFO>(k));
        }
        if( k<p->key ) p->left = insert(p->left,std::forward<INFO>(k), need_balance);
        else if (k==p->key){
            throw std::invalid_argument("");
        }
        else p->right = insert(p->right,std::forward<INFO>(k), need_balance);
        if (need_balance) {
            return balance(p);
        }
        else {
            return p;
        }
    }
    Node<INFO>* findmin(Node<INFO>* p) // поиск узла с минимальным ключом в дереве p
    {
        if (p->left){
            return findmin(p->left);
        }
        else return p;
    }
    Node<INFO>* removemin(Node<INFO>* p) // удаление узла с минимальным ключом из дерева p
    {
        if(!p->left) return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }
    Node<INFO>* remove(Node<INFO>* p, INFO&& k) // удаление ключа k из дерева p
    {
        if (!p) return 0;
        if (k < p->key)
            p->left = remove(p->left, k);
        else if (k > p->key)
            p->right = remove(p->right, k);
        else //  k == p->key
        {
            Node<INFO> *q = p->left;
            Node<INFO> *r = p->right;
            delete p;
            if (!r) return q;
            Node<INFO> *min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }
    Node<INFO>* root = nullptr;
    void copy(Node<INFO>* old_root){
        if (old_root->left) copy(old_root->left);
        if (old_root->right) copy(old_root->right);
        root = insert(root, old_root->key);
    }
public:
    void clear(){
        delete root;
        root = nullptr;
    }
    ~AVLTree(){
        clear();
    }
    void add(INFO&& k, bool need_balance = true){
        root = insert(root, std::forward<INFO>(k), need_balance);
    }
    void add(const INFO& k, bool need_balance = true){
        root = insert(root, k, need_balance);
    }
    const Node<INFO>* const get_root() const{
        return root;
    }
};

#endif // AVLTREE_H
