public class ArrayList<T> {

    private Object[] array;
    private int size;

    public ArrayList() {
        this.array = new Object[0];
        this.size = 0;
    }

    public void add(Object toAdd) {
        insert(toAdd, size);
    }

    public void insert(Object toAdd, int position) {
        if(position > size)
            position = size;
        Object[] array = new Object[size + 1];
        for(int i = 0, arrayIndex = 0; i < array.length; i++, arrayIndex++) {
            if(i == position) {
                array[arrayIndex] = toAdd;
                arrayIndex++;
            }
            if(i < this.array.length)
                array[arrayIndex] = this.array[i];
        }
        this.array = array;
        this.size++;
    }

    /**
     * @param object the object you wish to know the index of
     * @return the index of the object, or -1 if the object is not in the array
     */
    public int indexOf(Object object) {
        for (int i = 0; i < this.size; i++) {
            if(this.array[i] == object) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @param toDelete the object to delete
     * @return the object that was deleted from the arraylist, or null if the object is not in the arraylist
     */
    public Object delete(T toDelete) {
        int position = -1;
        for (int i = 0; i < this.size; i++) {
            if(this.array[i] == toDelete) {
                position = i;
                break;
            }
        }
        return delete(position);
    }

    /**
     * @param positionToDelete the index of the object to delete
     * @return the object that was deleted from the arraylist, or null if the object is not in the arraylist
     */
    public Object delete(int positionToDelete) {
        Object deleted = null;
        if(positionToDelete > -1) {
            Object[] array = new Object[size - 1];
            for (int i = 0, arrayIndex = 0; i < this.size; i++, arrayIndex++) {
                if (i == positionToDelete) {
                    deleted = this.array[i];
                    arrayIndex--;
                }
                else {
                    array[arrayIndex] = this.array[i];
                }
            }
            this.array = array;
            size--;
        }
        return deleted;
    }

    public Object[] getArray() {
        return array;
    }

    public int size() {
        return size;
    }
}
