class ListNode {
    constructor(value, next = null) {
        this.value = value;
        this.next = next;
    }
}

class LinkedList {
    constructor() {
        this._first = null;
        this._last = null;
        this._length = 0;
    }

    get first() {
        return this._first ? this._first.value : 'undefined';
    }

    get last() {
        return this._last ? this._last.value : 'undefined';
    }

    get length() {
        return this._length;
    }

    append(...elements) {
        elements.forEach((el) => {
            const newNode = new ListNode(el);
            if (this._first === null) {
                this._first = newNode;
                this._last = newNode;
            }
            this._last.next = newNode;
            this._last = newNode;
        });

        this._length += elements.length;

        return this;
    }

    prepend(...elements) {
        elements.reverse().forEach((el) => {
            const newNode = new ListNode(el);
            if (this._first === null) {
                this._first = newNode;
                this._last = newNode;
            }
            newNode.next = this._first;
            this._first = newNode;
        });

        this._length += elements.length;

        return this;
    }

    insert(index, ...elements) {
        if (index < 0 || index > this._length) {
            throw new Error('Invalid index!');
        }

        if (index === 0) {
            return this.prepend(...elements);
        } else if (index === this._length) {
            return this.append(...elements)
        }
        let nodeToInsertAfter = this._nodeAtIndex(index - 1);

        elements.forEach((el) => {
            const newNode = new ListNode(el);
            newNode.next = nodeToInsertAfter.next;
            nodeToInsertAfter.next = newNode;
            nodeToInsertAfter = newNode;
        });

        this._length += elements.length;

        return this;
    }

    at(index, value) {
        this._validateIndex(index);

        let nodeToReturn = this._nodeAtIndex(index);
        if (typeof value === 'undefined') {
            nodeToReturn.value = value;
        }

        return nodeToReturn.value;
    }

    removeAt(index) {
        this._validateIndex(index);

        if (index === 0) {
            const result = this._first.value;
            this._first = this._first.next;

            if (this._length === 1) {
                this._last = null;
            }

            this._length -= 1;

            return result;
        }
        let nodeToRemoveAfter = this._nodeAtIndex(index - 1);
        const result = nodeToRemoveAfter.next.value;
        nodeToRemoveAfter.next = nodeToRemoveAfter.next.next;

        if (index === this._length - 1) {
            this._last = nodeToRemoveAfter;
        }

        this._length -= 1;

        return result;

    }

    *[Symbol.iterator]() {
        let nextNode = this._first;
        while (nextNode !== null) {
            yield nextNode.value;
            nextNode = nextNode.next;
        }
    }

    toArray() {
        return [...this];
    }

    toString() {
        return this.toArray().join(' -> ');
    }

    _validateIndex(index) {
        if (index < 0 || index >= this._length) {
            throw new Error('Invalid index!');
        }
    }

    _nodeAtIndex(index) {
        let node = this._first;
        for (let i = 0; i < index; i++) {
            node = node.next;
        }

        return node;
    }
}

class Queue {
    constructor() {
        this._linkedList = new LinkedList();
    }

    enqueue(value) {
        this._linkedList.append(value);
        return this;
    }

    dequeue() {
        return this._linkedList.length ? this._linkedList.removeAt(0) : null;
    }

    get length() {
        return this._linkedList.length;
    }
}

class Stack {
    constructor() {
        this._linkedList = new LinkedList();
    }

    push(value) {
        this._linkedList.prepend(value);
        return this;
    }

    pop() {
        return this._linkedList.length ? this._linkedList.removeAt(0) : null;
    }

    get length() {
        return this._linkedList.length;
    }
}