package aps2.patricia;

import java.util.Stack;
import java.awt.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;

/**
 * @author matevz
 *
 */
public class PatriciaSet {
	PatriciaSetNode root;
	ArrayList<String> list = new ArrayList<String>();
	
	PatriciaSet() {
		this.root = new PatriciaSetNode("", false);
	}
	
	public PatriciaSetNode getRoot() {
		return root;
	}
	
	/**
	 * Inserts the given key to PATRICIA tree. Returns false, if such a key
	 * already exists in the tree; otherwise true.
	 */
	public boolean insert(String key) {
		boolean bool = false;
        PatriciaSetNode temp = new PatriciaSetNode(key, false);
        if (this.root.firstChild == null) {
            this.root.firstChild = temp;
            list.add(key);
            return true;
        }
        if (this.root.firstChild.getLabel().equals(key)) {
            return false;
        }        
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals(key)) {
                return false;
            }
            bool = true;
        }  
        list.add(key);
        for (int i = 0; i < this.root.firstChild.getLabel().length(); i++) {  
        	bool = true;
            if (key.charAt(i) != this.root.firstChild.getLabel().charAt(i)) { 
                if (i <= 1) {                       
                    if (this.root.firstChild.getLabel().compareToIgnoreCase(key) > 0) {
                        String firstChild = this.root.firstChild.getLabel().substring(i, this.root.firstChild.getLabel().length());
                        String firstChild2 = this.root.firstChild.firstChild.getLabel().substring(0, this.root.firstChild.firstChild.getLabel().length());
                        String sibiling = this.root.firstChild.firstChild.nextSibling.getLabel().substring(0, this.root.firstChild.firstChild.nextSibling.getLabel().length());
                        temp = new PatriciaSetNode(key.substring(0, i), true);
                        this.root.firstChild = temp;
                        temp = new PatriciaSetNode(key.substring(i, key.length()), true);
                        this.root.firstChild.firstChild = temp;
                        temp = new PatriciaSetNode(firstChild, true);
                        this.root.firstChild.firstChild.nextSibling = temp;
                        temp = new PatriciaSetNode(firstChild2, true);
                        this.root.firstChild.firstChild.nextSibling.firstChild = temp;
                        temp = new PatriciaSetNode(sibiling, true);
                        this.root.firstChild.firstChild.nextSibling.firstChild.nextSibling = temp;
                    }      
                }else{
                    String firstChild = this.root.firstChild.getLabel().substring(i, this.root.firstChild.getLabel().length());
                    temp = new PatriciaSetNode(key.substring(0, i), true);
                    this.root.firstChild = temp;
                    temp = new PatriciaSetNode(key.substring(i, key.length()), true);
                    this.root.firstChild.firstChild = temp;
                    temp = new PatriciaSetNode(firstChild, true);
                    this.root.firstChild.firstChild.nextSibling = temp;
                }                                      
            }              
        }

        return bool;
}
	
	/**
	 * Inserts the given key from PATRICIA tree. Returns false, if a key didn't
	 * exist or wasn't a terminal node; otherwise true.
	 */
	public boolean remove(String key) {
		throw new UnsupportedOperationException("You need to implement this function!");
	}
	
	/**
	 * Returns true, if the given key exists in PATRICIA tree and is a terminal
	 * node; otherwise false.
	 */
	public boolean contains(String key) {
		for(int i = 0; i < this.list.size(); i++) {
			if(this.list.get(i).equals(key)) {
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Returns the longest prefix of the given string which still exists in
	 * PATRICIA tree.
	 */
	public String longestPrefixOf(String s) {
		throw new UnsupportedOperationException("You need to implement this function!");
	}
	
	/**
	 * Returns all stored strings with the given prefix.
	 */
	public Set<String> keysWithPrefix(String s) {
		throw new UnsupportedOperationException("You need to implement this function!");
	}
	
	/**
	 * Returns the node with the largest string-depth which is not a leaf.
	 * String-depth is the sum of label lengths on that root-to-node path.
	 * This node also corresponds to the longest common prefix of at least two
	 * inserted strings.
	 */
	public PatriciaSetNode getLongestPrefixNode() {
		throw new UnsupportedOperationException("You need to implement this function!");
	}

	/**
	 * Computes and returns the longest substring in the given text repeated at
	 * least 2 times by finding the deepest node.
	 */
	public static String longestRepeatedSubstring(String text) {
		throw new UnsupportedOperationException("You need to implement this function!");
	}
}
