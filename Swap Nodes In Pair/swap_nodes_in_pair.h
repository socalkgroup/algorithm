#include "pch.h"

//==============================================================================
// swap_nodes_in_pair
//==============================================================================
namespace swap_nodes_in_pair {

//==============================================================================
template<typename T>
struct Node {
    T      data;
    Node * next;

    explicit Node (T data)
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

    virtual ~Node (void) {
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
ostream & operator << (ostream & out, const Node<T> & node) {
    for (auto curr = &node; curr;) {
        out << curr->data << " ";
        curr = curr->next;
    }
    return out;
}

//==============================================================================
template<typename T>
Node<T> * swap_nodes_in_pair (
    Node<T> * head
) {
    Node<T> dummy(0);
    auto p     = head;
    auto prev  = &dummy;
    dummy.next = head;

    while (p && p->next) {
        auto q = p->next;
        auto r = p->next->next;
        
        prev->next = q;
        q->next    = p;
        p->next    = r;
        prev       = p;
        p          = r;
    }

    auto out = dummy.next;
    dummy.next = nullptr;
    return out;
}

//==============================================================================
TEST(LinkedList, SwapNodesInPair_01) {
    Node<unsigned> list({1, 2, 3, 4});
    auto out = swap_nodes_in_pair(&list);

    Node<unsigned> expected({2, 1, 4, 3});
    EXPECT_EQ(*out, expected);
}

//==============================================================================
TEST(LinkedList, SwapNodesInPair_02) {
    Node<unsigned> list({1, 2, 3, 4, 5});
    auto out = swap_nodes_in_pair(&list);

    Node<unsigned> expected({ 2, 1, 4, 3, 5});
    EXPECT_EQ(*out, expected);
}

}; // end of namespace swap_nodes_in_pair