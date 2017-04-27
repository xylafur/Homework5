"""
    Okay so all we need to do is traverse a graph that we are given.

    The input is in the form of
        
        (current node)  (node it links to)  (if non zero this means it connects)

    SO the methodology that I think I will implement is something like:
        keep a list of node objects, each node will have a list of pointers to
                all nodes it can reach
        after this it should be relativelty simple to traverse the graph
            Start with the origin node and just search each node for where it
                can go
            make a list of all the results and sort it
"""

class Node:
    def __init__(self, val):
        self.nodes = []
        self.val = val

    def addNode(self, node):
        self.nodes.append(node)

class Graph:
    def __init__(self):
        self.nodes = []
    
    def addEntry(self, str):
        L = [ int(s) for s in str.split() ]
        
        if L[2] == 0 or L[1] == L[0]:
            return

        origin = None; destination = None
        for node in self.nodes:
            if node.val == L[0]:
                origin = node
            if node.val == L[1]:
                destination = node

        if not origin:
            origin = Node( L[0] )
            self.nodes.append( origin )
        if not destination:
            destination = Node( L[1] )
            self.nodes.append( destination )

        origin.addNode( destination )

    def getReachable(self, val):
        origin = [ node for node in self.nodes if node.val == val][0]
        reachable = []

        def recurs(reachable, node):
            for nde in node.nodes:
                if nde not in reachable and nde.val != val:
                    reachable.append( nde )
                    recurs(reachable, nde)
        
        recurs(reachable, origin)
        vals = [ node.val for node in reachable ]
        return sorted(vals)

fi = open('inputF.txt')
g = Graph()
for line in fi:
    g.addEntry( line )
print( g.getReachable(1) )
