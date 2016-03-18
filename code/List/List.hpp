#include "core.h"

template <typename T>
class List
{
    struct Node
    {
        T data;

        Node *p_next;
        Node *p_prev;
        Node(T t_data, Node* n, Node* p) : data(t_data), p_next(n), p_prev(p){}
    };

    Node *p_begin, *p_end;
    int m_size;
public:
    List(): p_begin(NULL), p_end(NULL), m_size(0)
    {
        std::cout << "Empty constructor was called " << this << std::endl;
    }

    List(T data) : p_begin(new Node(data, NULL, NULL)),
                   p_end(p_begin),
                   m_size(1)
    {
        std::cout << "Single data constructor was called "
                  << this
                  << ". Size is "
                  << m_size
                  << "."
                  << std::endl;
    }

//    List(List &someList);
    ~List()
    {
        Node* index = p_begin;
        while(index != NULL)
        {
            Node* buf = index;
            index = index->p_next;
            delete buf;
        }
        std::cout << "Destructor for " << this << " worked OK." << std::endl;
    }

    int getSize()
    {
        return m_size;
    }

    void push_back(T data)
    {
        Node* node = new Node(data, NULL, p_end);
        p_end->p_next = node;
        p_end = node;
        ++m_size;
        std::cout << "push_back put in the back of list with addr "
                  << node
                  << std::endl;
    }

    void pop_back()
    {

        Node* del = p_end;
        if (m_size > 1)
        {
            p_end->p_prev->p_next = NULL;
            p_end = p_end->p_prev;
        } else if (m_size == 1)
        {
            p_begin = NULL;
            p_end   = NULL;
        }
        --m_size;
        std::cout << "pop_back deletes node from the back of list with addr "
                  << del
                  << std::endl;
        delete del;
    }

    void push_front(T data)
    {
        Node* node = new Node(data, p_begin, NULL);
        p_begin->p_prev = node;
        p_begin = node;
        ++m_size;
        std::cout << "push_front put in front of the list with addr "
                  << node
                  << std::endl;
    }

    void pop_front()
    {
        Node* del = p_begin;
        if (m_size > 1)
        {
            p_begin->p_next->p_prev = NULL;
            p_begin = p_begin->p_next;
        } else if (m_size == 1)
        {
            p_begin = NULL;
            p_end   = NULL;
        }
        --m_size;
        std::cout << "pop_front deletes node from the front of list with addr "
                  << del
                  << std::endl;
        delete del;
    }

    class iterator
    {
        Node* node;
    public:
        iterator() : node(NULL) {}
        iterator(Node* l_node) : node(l_node) {}

        T& operator*() const
        {
            return node;
        }
        T* operator->() const
        {
            return *node;
        }

        iterator& operator++()
        {
            node = node->p_next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator* tmp = *this;
            node = node->p_next;
            return tmp;
        }

        friend bool operator==(iterator a, iterator b)
        {
            return a.node == b.node;
        }
        friend bool operator!=(iterator a, iterator b)
        {
            return a.node != b.node;
        }
    };
//    void insert(Node* data, int place);
//    Node* search(); //?????????????
//    void deleteNode();
//    void Sort();
//    void show();
//write iterator
};
