class Heap {
    constructor(compareFunc) {
        this.values = [null];
        this.compareFunc = compareFunc || ((x, y) => x < y);
    }

    get top() {
        return this.values[1];
    }

    get count() {
        return this.values.length - 1;
    }

    get isEmpty() {
        return this.count === 0;
    }

    add(value) {
        let index = this.values.length;
        this.values.push(value);

        while (index > 1 && this.compareFunc(value, this.values[index >> 1])) {
            this.values[index] = this.values[index >> 1];
            index >>= 1;
        }

        this.values[index] = value;
    }

    removeTop() {
        const value = this.values[this.values.length - 1];
        this.values.pop();

        if (!this.isEmpty) {
            this._heapifyDown(1, value);
        }
    }

    _heapifyDown(index, value) {
        while (index * 2 + 1 < this.values.length) {
            const isFirstChildBetter =
                this.compareFunc(
                    this.values[index * 2],
                    this.values[index * 2 + 1]
                );

            const smallerChildIndex = isFirstChildBetter ?
                index * 2 :
                index * 2 + 1;
            if (this.compareFunc(this.values[smallerChildIndex], value)) {
                this.values[index] = this.values[smallerChildIndex];
                index = smallerChildIndex;
            } else {
                break;
            }
        }

        if (index * 2 < this.values.length) {
            const smallerChildIndex = index * 2;
            if (this.compareFunc(this.values[smallerChildIndex], value)) {
                this.values[index] = this.values[smallerChildIndex];
                index = smallerChildIndex;
            }
        }

        this.values[index] = value;
    }
}
