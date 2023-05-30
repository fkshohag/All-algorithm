from collections import defaultdict


class MyHashSet:

    def __init__(self):
        self.dict = defaultdict(int)


    def add(self, key: int) -> None:
        self.dict[key] = True
        

    def remove(self, key: int) -> None:
        if key in self.dict.keys():
            del self.dict[key]
        

    def contains(self, key: int) -> bool:
        if key in self.dict.keys():
            return True
        else:
            return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)