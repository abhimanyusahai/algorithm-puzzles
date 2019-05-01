# Implementation of Directed Graph using Adjacency List

class Vertex:
    def __init__(self, key):
        self.id = key
        self.connected_to = {}
        self.color = 'white'

    def get_key(self):
        return self.id

    def get_weight(self, nbr):
        if nbr in self.connected_to:
            return self.connected_to[nbr]

    def add_neighbor(self, nbr, weight = 0):
        self.connected_to[nbr] = weight

    def __str__(self):
        return str(self.id)

    def get_connections(self):
        return self.connected_to.keys()


class Graph:
    def __init__(self):
        self.vertex_list = {}
        self.num_vertices = 0

    def add_vertex(self, key):
        new_vertex = Vertex(key)
        self.vertex_list[key] = new_vertex
        self.num_vertices += 1
        return new_vertex

    def get_vertex(self, n):
        if n in self.vertex_list:
            return self.vertex_list[n]
        else:
            return None

    def __contains__(self, n):
        return n in self.vertex_list

    def add_edge(self, f, t, weight = 0):
        if f not in self.vertex_list:
            fv = self.add_vertex(f)
        if t not in self.vertex_list:
            tv = self.add_vertex(t)
        self.vertex_list[f].add_neighbor(self.vertex_list[t], weight)

    def get_vertices(self):
        return self.vertex_list.keys()

    def __iter__(self):
        return iter(self.vertex_list.values())
