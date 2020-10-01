class Node:
    def __init__(self,data=None,next=None):
        self.data=data
        self.next=next


def CheckPalindrome(head):
    l=[]
    while head:
        l.append(head.data)
        head = head.next

    if l==l[::-1]:
        return True
    else:
        return False

def construct():

    first = Node(1)
    second = Node(2)
    third = Node(3)

    head = first
    first.next=second
    second.next=third

    return head


head = construct()
print(CheckPalindrome(head))