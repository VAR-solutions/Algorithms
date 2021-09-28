<?php

/**
 * Queue class that implements the Queue ADT and its basic functionality using
 * an array as the underlying data structure
 */

class Queue {
    private $items = [];

    // inserts element to back of queue
    public function enqueue($item) {
        array_unshift($this->items, $item);
    }

    // removes and returns the element at the front of the queue
    public function dequeue() {
        return array_pop($this->items);
    }

    // returns TRUE if queue is empty, and FALSE otherwise
    public function isEmpty() {
        return count($this->items) === 0;
    }

    // returns number of elements in the queue
    public function size() {
        return count($this->items);
    }

    // returns element at the front of the queue
    public function front() {
        return $this->items[count($this->items) - 1];
    }

    // returns element at the back of the queue
    public function back() {
        return $this->items[0];
    }
}