<?php

declare(strict_types=1);

/**
 * Class Node
 */
class Node
{
    protected $data;
    protected $next;

    /**
     * Node constructor.
     * @param int $data
     */
    public function __construct(int $data)
    {
        $this->data = $data;
        $this->next = null;
    }

    /**
     * Set next node
     * @param Node|null $next
     */
    public function setNext($next)
    {
        $this->next = $next;
    }

    /**
     * Get next node
     * @return Node|null
     */
    public function getNext()
    {
        return $this->next;
    }

    /**
     * Set data of Node
     * @param int $data
     */
    public function setData(int $data)
    {
        $this->data = $data;
    }

    /**
     * Get data of Node
     * @return int
     */
    public function getData()
    {
        return $this->data;
    }
}

/**
 * Class LinkedList
 *
 * Implementation of Linked List in PHP
 */
class LinkedList
{
    protected $size;
    protected $head;

    /**
     * LinkedList constructor.
     * @param int $data
     */
    public function __construct(int $data)
    {
        $this->head = new Node($data);
        $this->size = 1;
    }

    /**
     * Add data to the head of the list
     *
     * @param int $data
     */
    public function addAtHead(int $data)
    {
        $current = $this->head;
        $this->head = new Node($data);
        $this->head->setNext($current);
        $this->size++;
    }

    /**
     * Add data to the end of the list
     *
     * @param int $data
     */
    public function add(int $data)
    {
        $current = $this->head;
        while (!empty($current->getNext())) {
            $current = $current->getNext();
        }

        $current->setNext(new Node($data));
        $this->size++;
    }

    /**
     * Add data an specific index of the list
     *
     * @param int $data
     * @param int $index
     */
    public function addAtIndex(int $data, int $index)
    {
        $temp = $this->head;
        for ($i = 0; $i < ($index-1); $i++) {
            $temp = $temp->getNext();
        }

        $holder = $temp->getNext();
        $temp->setNext(new Node($data));
        $temp->getNext()->setNext($holder);
        $this->size++;
    }

    /**
     * Get data of item at index
     *
     * @param int $index
     * @return int|null
     */
    public function get(int $index)
    {
        if ($index < 0) {
            return null;
        }

        $current = null;

        if (!empty($this->head)) {
            $current = $this->head;

            for ($i = 0; $i < $index; $i++) {
                if (empty($current->getNext())) {
                    return null;
                }

                $current = $current->getNext();
            }

            return $current->getData();
        }

        return $current;
    }

    /**
     * Remove head of the list
     *
     * @return bool
     */
    public function removeHead()
    {
        if (empty($this->head->getNext())) {
            return false;
        }

        $next = $this->head->getNext();
        $this->head = $next;
        $this->size--;

        return true;
    }

    /**
     * Remove last item of the list
     *
     * @return bool
     */
    public function removeLast()
    {
        if (empty($this->head->getNext())) {
            $this->head = null;
            $this->size--;
            return true;
        }

        $current = $this->head;
        while (!empty($current->getNext()->getNext())) {
            $current = $current->getNext();
        }

        $current->setNext(null);
        $this->size--;
        return true;
    }

    /**
     * Remove a specific item at index
     *
     * @param int $index
     * @return bool
     */
    public function remove(int $index)
    {
        if ($index == 0) {
            return $this->removeHead();
        }

        if ($index == $this->size-1) {
            return $this->removeLast();
        }

        $current = $this->head;
        for ($i = 0; $i < $index; $i++) {
            if (empty($current->getNext())) {
                return false;
            }
            $current = $current->getNext();
        }

        $temp = $current->getNext();
        $current->setNext($temp->getNext());
        $this->size--;

        return true;
    }

    /**
     * Get size of the list
     *
     * @return int
     */
    public function getSize()
    {
        return $this->size;
    }

    /**
     * Print all itens of the list
     * 
     * @return string
     */
    public function __toString()
    {
        $output = '';

        $current = $this->head;
        while (!empty($current)) {
            $output .= '['. $current->getData(). ']';
            $current = $current->getNext();
        }

        return $output;
    }
}

echo "Create Linked List in PHP\n\n";

echo "Inserting number 1...\n";
$linkedList = new LinkedList(1);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Inserting number 3...\n";
$linkedList->add(3);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Inserting number 5...\n";
$linkedList->add(5);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Inserting number 8 at index 1...\n";
$linkedList->addAtIndex(8, 1);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Inserting number 9...\n";
$linkedList->add(9);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Inserting number 13 at head...\n";
$linkedList->addAtHead(13);
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Removing last item of list...\n";
$linkedList->removeLast();
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Removing first item of list...\n";
$linkedList->removeHead();
echo $linkedList .PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Removing item at index 1...\n";
$linkedList->remove(1);
echo $linkedList . PHP_EOL;
echo "Size: ". $linkedList->getSize() . "\n\n";

echo "Get data of the first item of the list...". PHP_EOL;
$data = $linkedList->get(0);
echo "Data: ". $data . PHP_EOL;