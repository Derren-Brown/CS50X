class Jar:
    def __init__(self, capacity):
        if capacity > -1:
            self.capacity = capacity
        else:
            raise ValueError()

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        self._size += n

    def withdraw(self, n):
        if self._size >= n:
            self._size -= n
        else:
            raise ValueError()
    _size = 0
    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, val):
        self._capacity = val

    @property
    def size(self):
        return self._size

def main():
    jar = Jar(12)
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))

main()