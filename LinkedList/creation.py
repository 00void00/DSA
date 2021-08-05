class Node:
    def __init__(self, data):
        self.data = data 
        self.next = None

class Linkedlist:
    def __init__(self):
        self.head = None

    # def append (self, data):
    #     node = Node(data)
    def printList(self):
        temp = self.head
        while (temp):
            print (temp.data)
            temp = temp.next

if __name__=='__main__':
    llist = Linkedlist()
    llist.head = Node(3)
    second = Node(7)
    third = Node(19)

    llist.head.next = second;
    second.next = third;
    # third.next = None;

    llist.printList()

