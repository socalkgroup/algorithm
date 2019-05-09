# [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)
* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes. You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

```
Example #1:
* input:  1 → 2 → 3 → 4 → 5 → nullptr
* output: 1 → 3 → 5 → 2 → 4 → nullptr

Example #2:
* input:  2 → 1 → 3 → 5 → 6 → 4 → 7 → nullptr
* output: 2 → 3 → 6 → 7 → 1 → 5 → 4 → nullptr
```

## 솔루션
* odd 와 even lists들을 나눠서 노드들을 연결하다가 노드의 마지막까지 오면 odd even 리스트들을 연결하면 된다
```py
    odd_list = head
    odd_cur = odd_list
    even_list = head.next
    even_cur = even_list

    cur = even_list
    while cur:
        cur = cur.next
        if cur:
            odd_cur.next = cur
            odd_cur = odd_cur.next

        cur = cur.next if cur else None
        even_cur.next = cur if cur else None
        even_cur = even_cur.next

    odd_cur.next = even_list
```