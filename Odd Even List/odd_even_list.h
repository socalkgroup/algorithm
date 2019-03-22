#include "pch.h"

//==============================================================================
// odd_even_list
//==============================================================================
namespace odd_even_list {

//==============================================================================
template<typename T>
struct Node {
    T      data;
    Node * next;

    explicit Node(T data)
        : data(data)
        , next(nullptr)
    {}

    explicit Node(const vector<T> & items)
        : next(nullptr)
    {
        if (!items.empty()) {
            data = items[0];

            auto ** prev = &next;
            for (auto i = 1u; i < items.size(); ++i) {
                *prev = new Node(items[i]);
                prev = &((*prev)->next);
            }
        }
    }

    virtual ~Node(void) {
        if (next)
            delete next;
    }

    Node & operator << (T data) {
        auto curr = this;
        while (curr->next)
            curr = curr->next;
        curr->next = new Node(data);
        return *this;
    }

    bool operator == (const Node & node) const {
        auto l = this;
        auto r = &node;
        while (l && r) {
            if (l->data != r->data)
                return false;

            l = l->next;
            r = r->next;
        }

        return !l && !r;
    }
};

//==============================================================================
template<typename T>
Node<T> * odd_even_list (
    Node<T> * head
) {
    if (!head)
        return nullptr;

    auto odd      = head;
    auto even     = head->next;
    auto evenhead = even;
    while (even && even->next) {
        odd->next  = even->next;
        odd        = odd->next;
        even->next = odd->next;
        even       = even->next;
    }

    odd->next = evenhead;
    return head;
}

//==============================================================================
TEST(LinkedList, OddEvenList_01) {
    Node<unsigned> list({1, 2, 3, 4});
    auto out = odd_even_list(&list);

    Node<unsigned> expected({1, 3, 2, 4});
    EXPECT_EQ(*out, expected);
}

//==============================================================================
TEST(LinkedList, OddEvenList_02) {
    Node<unsigned> list({1, 2, 3, 4, 5});
    auto out = odd_even_list(&list);

    Node<unsigned> expected({1, 3, 5, 2, 4});
    EXPECT_EQ(*out, expected);
}

}; // end of namespace odd_even_list