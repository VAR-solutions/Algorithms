import unittest
import stack

class StackTest(unittest.TestCase):

    def setUp(self):
        self.stack = Stack()

    def test_can_push(self):
        self.stack.push(1)
        self.assertFalse(self.stack.isEmpty())
        
    def test_is_empty(self):
        self.assertTrue(self.stack.isEmpty())
        self.stack.push(23)
        self.assertFalse(self.stack.isEmpty())
        
    def test_error_when_pop_empty(self):
        with self.assertRaises(AssertionError):
            self.stack.pop()
            
    def test_multiple_push_and_pop(self):
        elements = ['tea', 42, 'roof']
        
        for element in elements:
            self.stack.push(element)
        
        elements.reverse()
        for element in elements:
            self.assertEqual(element, self.stack.pop())
        
        
if __name__ == "__main__": 
    unittest.main()