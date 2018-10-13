//created by insane-abhi
#ifndef AVL_HPP
#define AVL_HPP 1
template <class Key, class Value>
class AVLnode
{
public:
    Key key;
    Value val;
    AVLnode<Key,Value> * left,* right;
    int height;
    /*Default constructor. Should assign the default value to key and value
     */
    AVLnode();
    /*This contructor should assign the key and val from the passed parameters
     */
    AVLnode(Key key, Value value);
};
template <class Key, class Value>
class AVL {
protected:
    AVLnode<Key,Value>* root = nullptr;
public:
    virtual void put(const Key& key, const Value& value);
    virtual void remove(const Key& key);
    virtual void print_pre_order();
    virtual Value get(const Key& key);
    virtual bool has(const Key& key);
    virtual void print_in_order();
    virtual void print_post_order();
    virtual Key minimum();
    virtual Key maximum();
    virtual Key successor(const Key& key);
    virtual Key predecessor(const Key& key);
    virtual int getHeight();
    virtual int size();
    virtual void print();
    Value que_1(Key& key, Value& val);
    Value que_2(Key& key, Value& val);
};

#endif /* ifndef AVL_HPP */