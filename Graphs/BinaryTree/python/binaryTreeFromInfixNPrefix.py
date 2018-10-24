##############################################
height = 0
strings = []
def makeTree(inT,posT,level):
    global height
    tree = Node(posT[0],level)
    indRoot = inT.index(tree.root)
    lenL = indRoot
    lenR = len(inT)-1-indRoot
    if(height<(level+1)):
            height = level+1
    if(len(inT)==1 and len(posT)==1):
        return tree
    else:
        try:
            tree.left = makeTree(inT[:indRoot],posT[1:(lenL+1)],level+1)
        except IndexError:
            tree.left = None
        try:
            tree.right = makeTree(inT[(indRoot+1):],posT[(lenL+1):],level+1)
        except:
            tree.right = None
        return tree
##############################################
class Node: 
    def __init__(self,key,level): 
        self.left = None
        self.right = None
        self.root = key
        self.level = level
##############################################
infx = "bac"
prefx = "abc"
tree = makeTree(infx,prefx,0) #tree object is created such as below

'''
   a
  / \
 b   c
'''
