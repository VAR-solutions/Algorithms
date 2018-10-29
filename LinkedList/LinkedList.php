<?php

declare(strict_types=1);

class Node
{
    protected $data;
    protected $next;

    public function __construct(int $data)
    {
        $this->data = $data;
        $this->next = null;
    }

    public function setNext(Node $next)
    {
        $this->next = $next;
    }

    public function getNext()
    {
        return $this->next;
    }

    public function setData(int $data)
    {
        $this->data = $data;
    }

    public function getData()
    {
        return $this->data;
    }
}

class LinkedList
{
    protected $size;
    protected $head;

    public function __construct(int $data)
    {
        $this->head = new Node($data);
        $this->size = 1;
    }

    public function addAtHead(int $data)
    {
        $temp = $this->head;
        $this->head = new Node($data);
        $this->head->setNext($temp);
        $this->size++;
    }

    public function add(int $data)
    {
        $temp = $this->head;
        while (!empty($temp->getNext())) {
            $temp = $temp->getNext();
        }

        $temp->setNext(new Node($data));
        $this->size++;
    }

    public function addAtIndex(int $index, int $data)
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

    public function get($index)
    {
        if ($index < 0) {
            return null;
        }

        $nodeCurrent = null;

        if (!empty($this->head)) {
            $nodeCurrent = $this->head->getNext();

            for ($i = 0; $i < $index; $i++) {
                if (empty($nodeCurrent->getNext())) {
                    return null;
                }

                $nodeCurrent = $nodeCurrent->getNext();
            }
            return $nodeCurrent->getData();
        }
        return $nodeCurrent;
    }

    public function pop()
    {
        $next = null;

        $next = $this->head->getNext();

        $this->head = $next;
    }

    public function remove(int $index)
    {
        $temp = $this->head;

    }

    public function getSize()
    {
        return $this->size;
    }

    public function __toString()
    {
        $output = '';

        if (!empty($this->head)) {
            $nodeCurrent = $this->head->getNext();
            while (!empty($nodeCurrent)) {
                $output .= '['. $nodeCurrent->getData(). ']';
                $nodeCurrent = $nodeCurrent->getNext();
            }
        }

        return $output;
    }
}

$linkedList = new LinkedList(1);

$linkedList->add(1);
echo $linkedList .PHP_EOL;
$linkedList->add(5);
echo $linkedList .PHP_EOL;
$linkedList->add(8);
echo $linkedList .PHP_EOL;
$linkedList->add(9);
echo $linkedList .PHP_EOL;

// remove index 2
$linkedList->remove(2);
echo $linkedList . PHP_EOL;