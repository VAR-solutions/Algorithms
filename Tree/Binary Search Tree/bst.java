
import java.util.ArrayList;
import java.util.Stack;


public class Bst<Tip extends Comparable> implements Seznam<Tip> {

    class ElementBST {

        public Tip value;
        public ElementBST left, right;

        public ElementBST(Tip e) {
            this(e, null, null);
        }

        public ElementBST(Tip e, ElementBST lt, ElementBST rt) {
            value = e;
            left = lt;
            right = rt;
        }
    }

    ElementBST rootNode;
    private Tip minNodeValue;

    public Bst() {
        rootNode = null;
    }

    private boolean member(Tip e) {
        return member(e, rootNode);
    }

    private boolean member(Tip e, ElementBST node) {
        if (node == null) {
            return false;
        } else if (e.compareTo(node.value) == 0) {
            return true;
        } else if (e.compareTo(node.value) < 0) {
            return member(e, node.left);
        } else {
            return member(e, node.right);
        }
    }

    private void insert(Tip e) {
        rootNode = insertLeaf(e, rootNode);
    }

    private void delete(Tip e) {
        rootNode = delete(e, rootNode);
    }

    private ElementBST insertLeaf(Tip e, ElementBST node) {
        if (node == null) {
            node = new ElementBST(e);
        } else if (e.compareTo(node.value) < 0) {
            node.left = insertLeaf(e, node.left);
        } else if (e.compareTo(node.value) > 0) {
            node.right = insertLeaf(e, node.right);
        } else {
            throw new java.lang.IllegalArgumentException(); //element ze obstaja
        }
        return node;
    }

    private ElementBST delete(Tip e, ElementBST node) {        
        if(e.compareTo(node.value) < 0)
            node.left = delete(e, node.left);
        else if(e.compareTo(node.value) > 0)
            node.right = delete(e, node.right);
        else {
            if(node.left == null)
                return node.right;
            else if(node.right == null)
                return node.left;
            
            node.value = minNode(node.right);
            node.right = delete(node.value, node.right);
        }
        return node;
    }

    private Tip minNode(ElementBST node) {
        Tip min = node.value;
        while(node.left != null) {
            min = node.left.value;
            node = node.left;
        }
        return min;
    }

    private int getDepth(ElementBST node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(getDepth(node.left), getDepth(node.right));
    }

    private int countNodes(ElementBST node) {
        if (node == null) {
            return 0;
        }
        int i = 1 + countNodes(node.left) + countNodes(node.right);
        return i;
    }

    @Override
    public void add(Tip e) {
        insert(e);
    }

    @Override
    public Tip removeFirst() {
        if (this.isEmpty()) {
            throw new java.util.NoSuchElementException();
        }
        Tip el = rootNode.value;
        delete(rootNode.value);
        return el;
    }

    @Override
    public Tip getFirst() {
        if (this.isEmpty()) {
            throw new java.util.NoSuchElementException();
        }
        return rootNode.value;
    }

    @Override
    public int size() {
        int i = countNodes(rootNode);
        return i;
    }

    @Override
    public int depth() {
        return getDepth(rootNode);
    }

    @Override
    public boolean isEmpty() {
        return (rootNode == null);
    }

    @Override
    public Tip remove(Tip e) {
        if (!this.exists(e)) {
            throw new java.util.NoSuchElementException();
        } else {
            delete(e);
        }
        return e;
    }

    @Override
    public boolean exists(Tip e) {
        return member(e);
    }
    
    @Override
    public Tip[] asList() {
        ArrayList list = new ArrayList();
        Stack<Object> stack = new Stack<>();
        ElementBST node = rootNode;
        
        //first node to be visited will be the left one
        while (node != null) {
            stack.push(rootNode);
            node = node.left;
        }
        
        // traverse the tree
        while (stack.size() > 0) {
          
            // visit the top node
            node = (ElementBST) stack.pop();
            list.add(node.value);
            if (node.right != null) {
                node = node.right;
                
                // the next node to be visited is the leftmost
                while (node != null) {
                    stack.push(node);
                    node = node.left;
                }
            }
        }
        String[] r = (String[]) list.toArray(new String[list.size()]);
        System.out.println(list.toString());
        return (Tip[]) r;
    }
}
