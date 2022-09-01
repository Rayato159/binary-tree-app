class Node:
    def __init__(self):
        self.data = 0
        self.next = None
        
class LinkedLists:
    def __init__(self):
        self.head = None
        self.last = None
    
    def insert_last(self, data):
        t = Node()
        t.data = data
        t.next = None
        
        if self.head == None:
            self.head = t
            self.head.next = None
            self.last = self.head
        else:
            self.last.next = t
            self.last = t
    
    def display(self):
        p = self.head
        while(p != None):
            print(p.data, end = ' ')
            p = p.next
        print()

def main():
    l = LinkedLists()
    l.insert_last(10)
    l.insert_last(20)
    l.insert_last(30)
    l.display()

if __name__ == '__main__':
    main()