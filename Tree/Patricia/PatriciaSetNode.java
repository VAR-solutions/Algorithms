package aps2.patricia;

import java.awt.List;
import java.util.LinkedList;

/**
 * @author matevz
 *
 */
public class PatriciaSetNode {
	/**
	 * Label on the incoming edge.
	 * The length of label is always greater than 0, except for the root node,
	 * where the label is empty.
	 */
	private String label;
	
	/**
	 * True, if the node is terminal node (ie. the node corresponding to the inserted key)
	 */
	private boolean terminal;
	
	/**
	 * The parent node.
	 */
	PatriciaSetNode parent;
	
	/**
	 * Linked list of children ordered by their labels.
	 */
	public LinkedList<PatriciaSetNode> list = new LinkedList<PatriciaSetNode>();
	public PatriciaSetNode firstChild;
	public PatriciaSetNode nextSibling;
	
	public String tmp = "";
	
	PatriciaSetNode(String label, boolean terminal) {
		this.label = label;
		this.terminal = terminal;
		this.parent = null;
	}
	
	/**
	 * Adds a given node as a new child.
	 * If a child with the same first outgoing character already exists, insertion
	 * fails. Otherwise returns True.
	 */
	public boolean addChild(PatriciaSetNode node) {
		if (node.terminal) {
			if (list.isEmpty()) {
				list.add(node);
				node.setParent(this);
				this.firstChild = node;
				tmp += node.getLabel().charAt(0);
				return true;
			} else {
				for (int i = 0; i < tmp.length(); i++) {
					if (tmp.charAt(i) == node.getLabel().charAt(0)) {
						return false;
					}
				}
				list.add(node);
				node.setParent(this);
				for (int j = 0; j < list.size(); j++) {
					if (list.get(j).getLabel().compareToIgnoreCase(node.getLabel()) > 0 && list.size() < 3) {
						node.nextSibling = this.firstChild;
						this.firstChild = node;
					} else if (list.get(j).getLabel().compareToIgnoreCase(node.getLabel()) > 0) {
						node.nextSibling = this.firstChild.nextSibling;
						this.firstChild.nextSibling = node;

					}
				}

				tmp += node.getLabel().charAt(0);

				return true;
			}

		}
		return false;
	}
	/**
	 * Removes a child with the given first outgoing character. Returns true, if
	 * a child was removed; otherwise false.
	 */
	public boolean removeChild(char c) {
		for(int i = 0; i < list.size(); i++) {
			if(list.get(i).getLabel().charAt(0) == c) {
				list.remove(i);
				return true;
			}
		}return false;
	}
	
	/**
	 * Returns the child with the given first character on its label or null, if
	 * such a child doesn't exist.
	 */
	public PatriciaSetNode getChild(char c) {
		for(int i = 0; i < list.size(); i++)
			if(list.get(i).getLabel().charAt(0) == c)
				return list.get(i);
		return null;
	}
	
	/**
	 * Returns the number of children.
	 */
	public int countChildren() {
		return list.size();
	}
	
	public String getLabel() {
		return label;
	}
	
	public void setLabel(String l) {
		this.label = l;
	}
	
	public boolean isTerminal() {
		return this.terminal;
	}
	
	public void setTerminal(boolean t) {
		this.terminal = t;
	}
	
	public PatriciaSetNode getParent() {
		return this.parent;
	}
	
	public void setParent(PatriciaSetNode parent) {
		this.parent = parent;
	}
}
