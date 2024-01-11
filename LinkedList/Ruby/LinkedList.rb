class LinkedList
    def initialize
        @head = nil
    end

    def addToFront(value)
        if @head
            new_head = Node.new(value)
            new_head.next = @head
            @head = new_head
        else
            @head = Node.new(value)
        end
    end
            
    
    def addToBack(value)
        if @head
            find_tail.next = Node.new(value)
        else
            @head = Node.new(value)
        end
    end

    # Inserts node at the specified index
    def add_at(index, item)
        if size > index
            puts "Index is out of bounds"
            return nil
        elsif @head
            if (index==0)
                new_node = Node.new(value)
                @head = new_node
            elsif (index>0)
                ind = index-1
                before_insert = @head
                ind.times do
                    before_insert = before_insert.next
                end
                after_insert = before_insert.next

                new_node = Node.new(value)
                new_node.next = after_insert
                before_insert = new_node
            end        
        else
            new_node = Node.new(value)
            @head = new_node
        end
    end

    # Returns last node in LinkedList
    def find_tail
        node = @head
        return node if !node.next
        return node if !node.next while (node = node.next)
    end

    # Adds node after first occurrence of specified value
    def append_after(target, value)
        node           = find(target)
        return unless node
        old_next       = node.next
        node.next      = Node.new(value)
        node.next.next = old_next
    end

    # Helper functinon returning the first occurrence of a node with the target value
    def find(value)
        current_node = @head
        return false if !current_node
        return current_node  if current_node.value == value
        while (current_node = current_node.next)
            return current_node if current_node.value == value
        end
    end

    # Removes first node from LinkedList without returning anything
    def removeFromFront
        if @head
            old_head = @head
            @head = old_head.next
            old_head.next = nil
        else
            puts "The LinkedList is empty"
        end 
    end
    
    # Removes last node from LinkedList without returning anything
    def removeFromBack
        if @head
            if @head.next
                current_node = @head
                while current_node.next.next != nil
                    current_node = current_node.next
                end
                current_node.next = nil
            else
                @head = nil
            end
        else
            puts "The LinkedList is empty"
        end
    end 

    def size
        if @head
            count = 1
            current_node = @head
            while current_node.next != nil
                current_node = current_node.next
                count += 1
            end
        else
            count = 0
        end
        count
    end

    # Returns the node at a given index
    def node_at(index)

        if size >= index
            puts "Index is out of bounds"
            return nil
        end

        current=@head
        index.times do
            current=current.next_node
        end
        return current
    end

    # Removes node at specified index without returning anything
    def remove(index)

        if size >= index
            puts "Index is out of bounds"
            return nil
        elsif @head
            if (index==0)
                old_head = @head
                @head = @head.next
                old_head.next = nil
            elsif (index>0)
                before_current = node_at(index-1)
                current_node = before_current.next
                before_current.next = current_node.next
                current_node.next = nil
            end
        else
            puts "The LinkedList is empty"
        end
    end

    # delete first occurrence of value
    def delete(value)
        if @head.value == value
            @head = @head.next
            return
        end
        node      = find_before(value)
        node.next = node.next.next
    end

    # Helper function that returns the node before a specific value
    def find_before(value)
        node = @head
        return false if !node.next
        return node  if node.next.value == value
        while (node = node.next)
            return node if node.next && node.next.value == value
        end
    end

    def print
        node = @head
        puts node
        while (node = node.next)
            puts node
        end
    end

    class Node
        attr_accessor :next
        attr_reader   :value
        def initialize(value)
            @value = value
            @next  = nil
        end
        def to_s
            "Node with value: #{@value}"
        end
    end
end