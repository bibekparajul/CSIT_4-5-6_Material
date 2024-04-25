# -*- coding: utf-8 -*-
"""Lab 2 - Breadth First Search.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/16ApZIsD-SUD40UDCTVSCDUuewwOTfdI1
"""

import queue

print(queue.Queue()._qsize(),"\n\n\n\n\n\n\n\n")
class BreadthFirstSearch:
  """
    Scratch Implementation of Breadth First Search in Python
  """
  def __init__(self, graph):
    self.graph = graph
    self.visited_list = set()
    self.visited = {}     # Status of element
    self.queue = queue.Queue()       # Queue to hold the element to maintain visit sequence
    self.markUnvisited()

  def markUnvisited(self):
    # Set all node as unvisited
    for node in self.getAllNodes():
      self.visited[node] = False

  def getAllNodes(self):
    s = set()
    for key, value in self.graph.items():
      s.add(key)
      for item in value:
        s.add(item)
    
    s = list(s)
    return s


  def isNodeVisited(self, node):
    if (not self.visited[node]):
      return True
    else:
      return False


  def is_child_node(self, node):
    for n, _ in self.graph.items():
      if n == node:
        return False
      
    return True


  def __call__(self, start_node):
    # Push start node to the top of the Queue
    self.queue.put(start_node)

    print("Nodes in Queue: ", self.queue)

    while(self.queue._qsize()):
      # Visit the node in the front of the Queue
      visit_node = self.queue.get()

      print(f"Node {visit_node} has been visited.")
      self.visited[visit_node] = True

      # Once the node has been visited push node to the visited set.
      if visit_node not in self.visited_list:
        print(f"Visited node is {visit_node}")
        # Add visited node to the visited list
        self.visited_list.add(visit_node)

      # Check if node has adjacent node or is a child node
      if not self.is_child_node(visit_node):
        print(f"The {visit_node} is not a child node.")
        # Expand the visited node to its child or adjacent node and push them to the queue
        for adj_node in self.graph[visit_node]:
          if self.isNodeVisited(adj_node):
            self.queue.put(adj_node)
          else:
            print("The node doesn't have any child node.")
      else:
        print(f"visited node {visit_node} is a child node.")
      
      print(self.queue._qsize())
      print("--------------------------------------------------------------------------------------------------")

graph = {
    'A' : ['B', 'C'],
    'B' : ['D', 'E'],
    'C' : ['F', 'G'],
    'E' : ['H', 'I']
}

bfs = BreadthFirstSearch(graph)
print("Before BFS: ", bfs.visited)
bfs("A")
print("After BFS: ", bfs.visited)