# Implement binary min heap with insert and extract_min functions

class MinHeap:
    def __init__(self):
        self.heap_list = [0]
        self.heap_size = 0

    def bubble_up(self, i):
        while i/2 > 0:
            if self.heap_list[i] < self.heap_list[i/2]:
                temp = self.heap_list[i/2]
                self.heap_list[i/2] = self.heap_list[i]
                self.heap_list[i] = temp
            i /= 2

    def insert(self, x):
        self.heap_list.append(x)
        self.heap_size += 1
        self.bubble_up(self.heap_size)

    def min(self):
        if self.heap_size > 0:
            return self.heap_list[1]

    def min_child(self, i):
        if (2 * i + 1) > self.heap_size:
            return 2 * i
        else:
            if self.heap_list[2 * i] < self.heap_list[2 * i + 1]:
                return 2 * i
            else:
                return 2 * i + 1

    def bubble_down(self, i):
        while i <= (self.heap_size/2):
            mc = self.min_child(i)
            if self.heap_list[i] > self.heap_list[mc]:
                temp = self.heap_list[i]
                self.heap_list[i] = self.heap_list[mc]
                self.heap_list[mc] = temp
            i = mc

    def extract_min(self):
        minval = self.heap_list[1]
        self.heap_list[1] = self.heap_list.pop()
        self.heap_size -= 1
        self.bubble_down(1)
        return minval


def main():
    my_heap = MinHeap()
    my_heap.insert(14)
    my_heap.insert(12)
    my_heap.insert(5)
    my_heap.insert(9)
    my_heap.insert(2)
    my_heap.insert(8)
    print my_heap.extract_min()
    print my_heap.extract_min()
    print my_heap.extract_min()
    print my_heap.extract_min()


if __name__ == "__main__":
    main()
