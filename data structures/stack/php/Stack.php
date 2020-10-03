<?php

/**
 * Stack class that implements the Stack ADT and its basic functionality using
 * an array as the underlying data structure
 */

class Stack {

    private $items = [];

    // inserts element to the top of the stack
    public function push($item) {
        array_push($this->items, $item);
    }

    // returns and removes the element at the top of the stack
    public function pop() {
        return array_pop($this->items);
    }

    // returns the element at the top of the stack
    public function peek() {
        return $this->items[count($this->items)-1];
    }

    // returns TRUE if the stack is empty, and FALSE otherwise
    public function isEmpty() {
        return count($this->items) === 0;
    }
}