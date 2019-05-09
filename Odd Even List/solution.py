class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def oddEvenList(self, head):
        if not head:
            return None

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
        return head

root = ListNode(1)
cur = root
for i in range(2,6):
    cur.next = ListNode(i)
    cur = cur.next

solution = Solution()
root = solution.oddEvenList(root)

while root:
    print(root.val)
    root = root.next


