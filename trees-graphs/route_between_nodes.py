# Given directed graph, find whether there is a route between 2 nodes

from directed_graph import Vertex, Graph

def dfs(g, m, n):
    v = g.get_vertex(m)
    if v.color == 'white':
        if v.get_key() == n:
            return True
        v.color = 'black'
        for c in v.get_connections():
            if dfs(g, c.get_key(), n):
                return True


def route_between_nodes(g, start, end):
    if dfs(g, start, end): return True
    else: return False


def main():
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 5)
    # g.add_edge(1, 2)
    # g.add_edge(2, 3)
    g.add_edge(3, 4)
    g.add_edge(3, 5)
    g.add_edge(4, 0)
    g.add_edge(5, 4)
    # g.add_edge(5, 2)
    print route_between_nodes(g, 3, 5)

if __name__ == "__main__":
    main()
