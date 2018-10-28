# leetcode 208

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.word_end = False
        self.children = [None] * 26


    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        if (word == None):
            return
        node = self
        for i in word:
            index = (ord(i) - ord('a'))
            if(node.children[index] == None):
                node.children[index] = Trie()
            node = node.children[index]
        node.word_end = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        if (word == None):
            return False
        node = self
        for i in word:
            index = (ord(i) - ord('a'))
            if(node.children[index] == None):
                return False

            node = node.children[index]
        return(node.word_end)

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        if (prefix == None):
            False

        node = self
        for i in prefix:
            index = (ord(i) - ord('a'))
            if(node.children[index] == None):
                return False
            node = node.children[index]
        return True


trie = Trie();
trie.insert("apple");
print trie.search("apple");   # returns true
print trie.search("app");     # returns false
print trie.startsWith("app"); # returns true
trie.insert("app");
print trie.search("app");     # returns true
