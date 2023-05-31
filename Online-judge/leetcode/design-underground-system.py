from collections import defaultdict


class UndergroundSystem:

    def __init__(self):
        self.journey = defaultdict()
        self.history = defaultdict()
        
    def checkIn(self, id: int, startStation: str, t: int) -> None:
        self.journey[id] = (startStation, t)
        

    def checkOut(self, id: int, endStation: str, endTime: int) -> None:
        startStation, startTime = self.journey.pop(id)
        key = (startStation, endStation)
        allTime, allCount = self.history.get(key, (0, 0))
        self.history[key] = (allTime + (endTime - startTime), allCount + 1)
        
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = (startStation, endStation)
        allTime, allCount = self.history.get(key, (0, 0))
        return allTime / allCount


# Your UndergroundSystem object will be instantiated and called as such:
obj = UndergroundSystem()
obj.checkIn(1, "dhaka", 23)
obj.checkOut(1, "kishoreganj", 30)
t = obj.getAverageTime("dhaka", "kishoreganj")
print(t)