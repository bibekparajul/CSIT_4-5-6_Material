
class GBFS:
    def __init__(self,graph,heuretics,name_of_nodes) -> None:
        self.graph = graph
        self.heuretics = heuretics
        self.names = name_of_nodes
        self.visited = []
        self.__priorityqueue = []
    
    def insert_in_queue(self,node):
        if self.__priorityqueue.__len__() == 0:self.__priorityqueue.append(node)
        else:
            for idx,each in enumerate(self.__priorityqueue):
                if self.heuretics[node]<self.heuretics[each] and node not in self.__priorityqueue:
                    self.__priorityqueue.insert(idx,node)
            if node not in self.__priorityqueue:self.__priorityqueue.append(node)

    def __call__(self,start_node,goal_node=None):
        self.__priorityqueue.append(self.names.index(start_node))
        while(self.__priorityqueue.__len__()):
            node = self.__priorityqueue[0]
            self.visited.append(node)
            
            try:
                if self.names.index(goal_node) in self.visited:break
            except:pass

            self.__priorityqueue.remove(node)
            
            try:
                for each in self.graph[node]:
                    if each not in self.visited:
                        self.insert_in_queue(each)
            except:pass
            
        print("visited nodes are: ",end ="")
        for each in self.visited: print(name_of_nodes[each],end = " ")

graph = {
    0:[1,2,3],
    1:[4,5],
    2:[6,7],
    3:[8]
}
heuretics = [1000,3,8,7,9,8,12,14,7]
name_of_nodes = ["A","B","C","D","E","F","G","H","I"]
bfs = GBFS(graph,heuretics,name_of_nodes)
bfs("A")