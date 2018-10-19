import unittest

# a special kind of stack that remembers values
# that were popped off the stack, by storing them in 
# a history list. It then can use these nodes in 
# the history to restore previsouly popped values. 
class TimeTravelStack():
    
    def __init__(self):
        self.list = []
        self.history = []

    # pushs the given value onto the list
    def push(self, x):
        self.list.append(x)

    # pops a value from the list and push's it onto the history list
    def pop(self):
        lastPopped = self.list.pop()
        self.history.append(lastPopped)
        return lastPopped

    # pops a value from the history list and push's it back onto the main list
    def restore(self):
        lastPoppedHistory = self.history.pop()
        self.list.append(lastPoppedHistory)


class TimeTravelStackTest(unittest.TestCase):

    # tests TimeTravelStack's push and pop method
    def test_push_and_pop(self):
        x = TimeTravelStack()
        x.push(5)
        x.push(6)
        self.assertEqual(6, x.pop())
    
    # tests TimeTravelStack's restore method
    def test_restore(self):
        x = TimeTravelStack()
        x.push(7)
        x.push(8)
        x.pop()
        x.restore()
        self.assertEqual(x.pop(), 8)
        


if __name__ == "__main__":
    unittest.main()    


