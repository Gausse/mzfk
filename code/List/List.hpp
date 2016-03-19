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
    struct iterator
    {
        Node* node;
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

        Node* node = new Node(data, NULL, NULL);
        if (m_size > 0)
        {
            node->p_prev = p_end;
            p_end->p_next = node;
            p_end = node;
        } else if (m_size == 0)
        {
            p_begin = p_end = node;
        }
        ++m_size;
        std::cout << "push_back put in the back of list with addr "
                  << node
                  << std::endl;
    }

    void pop_back()
    {
        if (m_size > 0)
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
    }

    void push_front(T data)
    {
        Node* node = new Node(data, p_begin, NULL);
        if (m_size > 0)
        {
            node->p_next = p_begin;
            p_begin->p_prev = node;
            p_begin = node;
        } else if (m_size == 0)
        {
            p_begin = p_end = node;
        }
        ++m_size;
        std::cout << "push_front put in front of the list with addr "
                  << node
                  << std::endl;
    }

    void pop_front()
    {
        if (m_size > 0)
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
    }

    iterator begin()
    {
        return iterator(p_begin);
    }

    iterator end()
    {
        return iterator(p_end);
    }

    iterator rbegin()
    {
        return iterator(p_end);
    }

    iterator rend()
    {
        return iterator(p_begin);
    }

    void insert(T data, int place)
    {
        if (place > m_size)
        {
            push_back(data);
            return;
        }
        iterator it = begin();
        iterator null_it;
        int index = 0;
        while(it != null_it)
        {
            if (index == place)
            {
                Node* node = new Node(data, it.node, it.node->p_prev);
                it.node->p_prev->p_next = node;
                it.node->p_prev = node;
                ++m_size;
                return;
            }
            ++it;
            ++index;
        }
    }
    //ask about what return when search failed
    iterator search(T data, bool(*qualifier)(T, T))
    {
        for(iterator it = begin(), l_end = end(); it != l_end; ++it)
        {
            if (qualifier(it.node->data, data))
                return it;
        }
        return iterator();
    }

    void remove(int place)
    {
        if (place == 0)
        {
            pop_front();
            return;
        } else if (place == m_size - 1)
        {
            pop_back();
            return;
        }
        if ((place <= m_size-1) && (place > 0))
        {
            int index = 1;
            for(iterator it = ++begin(), l_end = end(); it != l_end; ++it)
            {
                if (index == place)
                {
                    it.node->p_prev->p_next = it.node->p_next;
                    it.node->p_next->p_prev = it.node->p_prev;

                    delete it.node;
                    --m_size;
                    return;
                }
                ++index;
            }
        }
    }

    iterator at(int place)
    {
        if (place < m_size)
        {
            int index = 0;
            for(iterator it = begin(); it.node != NULL; ++it)
            {
                if (index == place)
                {
                    return it;
                }
                ++index;
            }
        }
        return NULL;
    }

    void sort(bool(*qualifier)(T,T))
    {
        for (int i = 0; i < m_size; ++i)
        {
            Node nMin = *at(i).node;
            int iMinInd = i;
            for (int j = i + 1; j < m_size; ++j)
            {
                if (qualifier(at(j).node->data, nMin.data))
                {
                    nMin = *at(j).node;
                    iMinInd = j;
                }
            }
            at(iMinInd).node->data = at(i).node->data;
            at(i).node->data = nMin.data;
        }
    }

    void show(void (*shower)(T))
    {
        for(iterator it = begin(); it.node != NULL; ++it)
        {
            shower(it.node->data);
        }
    }

//    void Sort();
};
