import sys
from collections import deque

# 1. TO GET THE INPUT AND CONSTRUCT A GRAPH

node_count, edge_count = map(int, sys.stdin.readline().split())

graph = [[0 for nodeB in range(node_count)] for nodeA in range(node_count)]
capacity = [[0 for nodeB in range(node_count)] for nodeA in range(node_count)]
flow = [[0 for nodeB in range(node_count)] for nodeA in range(node_count)]

for edge in range(edge_count):
    nodeA, nodeB = map(int, sys.stdin.readline().split())
    nodeA -= 1
    nodeB -= 1

    graph[nodeA][nodeB] = 1
    capacity[nodeA][nodeB] += 1
    graph[nodeB][nodeA] = 1

# 2. EDMOND-KARP

ans = 0
source = 0
sink = 1

while True:

    # The array marks the parent of each node if the node is visited.

    parent = [-1 for node in range(node_count)]

    # BFS to find the shortest possible path

    queue = deque([source])
    while queue and parent[sink] == -1:
        now_node = queue.popleft()
        for next_node in range(node_count):
            if graph[now_node][next_node] and capacity[now_node][next_node] > flow[now_node][next_node] and parent[
                next_node] == -1:
                queue.append(next_node)
                parent[next_node] = now_node

    # If there is no possible path, terminate.

    if parent[sink] == -1:
        break

    # Find a bottleneck

    amount = float('inf')
    node = sink
    while node != source:
        amount = min(amount, capacity[parent[node]][node] - flow[parent[node]][node])
        node = parent[node]

    # Flow

    node = sink
    while node != source:
        flow[parent[node]][node] += amount
        flow[node][parent[node]] -= amount
        node = parent[node]
    ans += amount

print(ans)