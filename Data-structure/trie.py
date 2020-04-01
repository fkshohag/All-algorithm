class Node:
    def __init__(self, letter):
        self.letter = letter
        self.childs = list()
        self.terminal = 0
        self.count = 0


class Trie:
    def __init__(self):
        self.root = Node('')
        self.curr = self.root

    def __insert_letter(self, head, letter):
        for child in head.childs:
            if child.letter == letter:
                return child
        else:
            n = Node(letter)
            head.childs.append(n)
            return n

    def insert(self, word):
        self.curr = self.root
        for letter in word:
            self.curr = self.__insert_letter(self.curr,letter)
        self.curr.terminal = True
        self.curr.count += 1


    def has_word(self, word):
        self.curr = self.root
        for letter in word:
            for child in self.curr.childs:
                if child.letter == letter:
                    self.curr = child
                    break
            else:
                return False
        if self.curr.terminal:
            return True
        else:
            return False

    def count(self, word):
        self.curr = self.root
        for letter in word:
            for child in self.curr.childs:
                if child.letter == letter:
                    self.curr = child
                    break
            else:
                return 0
        if self.curr.terminal:
            return self.curr.count
        else:
            return 0
            
                

t = Trie()
t.insert("shohag")   
t.insert("shohag")
t.insert("shohag")
print(t.has_word("shohag"))
x = t.count('shohag')
print(x)
