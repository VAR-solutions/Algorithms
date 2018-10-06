import unittest
import queue

class QueueTest(unittest.TestCase):

    def setUp(self):
        self.queue = queue.Queue()     

    def test_enqueue(self):
        self.queue.enqueue(23)
        self.assertFalse(self.queue.isEmpty())

    def test_empty(self):
        self.assertTrue(self.queue.isEmpty())
        self.queue.enqueue(42)
        self.assertFalse(self.queue.isEmpty())
        
    def test_error_when_queue_empty(self):
        with self.assertRaises(AssertionError):
            self.queue.dequeue()

    def test_multiple_enqueue_dequeue(self):
        elements = ['hi', 1, 'hu']

        for element in elements:
            self.queue.enqueue(element)
        
        for element in elements:
            self.assertEqual(self.queue.dequeue(), element)

if __name__ == "__main__":
    unittest.main()