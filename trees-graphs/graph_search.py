# Breadth First Search and Depth First Search

def bfs(g, n):
    print g.get_vertex(n)
    g.get_vertex(n).color = 'black'
    bfs_queue = g.get_vertex(n).get_connections()
    while (not len(bfs_queue) == 0):
        v = bfs_queue.pop(0)
        if v.color == 'white':
            print v
            v.color = 'black'
            bfs_queue.extend(v.get_connections())

def dfs(g, n):
    v = g.get_vertex(n)
    if v.color == 'white':
        print v
        v.color = 'black'
        for c in v.get_connections():
            dfs(c.get_key())
