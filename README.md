# Dijkstra-and-Floyd-Implementation-
Write a C++ program that implements Dijkstra's and Floyd's algorithms for finding the shortest path between pairs of nodes in a directed graph.

Input Format

The program must read a number  followed by  non-negative integer values representing an adjacency matrix of a directed graph.

The first number represents the number of nodes, the following values in the matrix, the value at position  represents the weight of the arc from node  to node . If there is no arc between node and node , the value in the matrix must be .

Constraints

 followed by a matrix with size , where each value in at position  is a weight  of the arc from node  to node .  if there si no arc between  and .

Output Format

The output of the program is, first with Dijkstra's algorithm the distance from node  to node  for all nodes, and then, the resulting matrix for Floyd's algorithm.

Sample Input 0

4
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0
Sample Output 0

Dijkstra:
node 1 to node 2 : 2
node 1 to node 3 : 3
node 1 to node 4 : 3
node 2 to node 1 : 3
node 2 to node 3 : 1
node 2 to node 4 : 5
node 3 to node 1 : 2
node 3 to node 2 : 3
node 3 to node 4 : 5
node 4 to node 1 : 3
node 4 to node 2 : 5
node 4 to node 3 : 4

Floyd:
0 2 3 3
3 0 1 5
2 3 0 5
3 5 4 0
Sample Input 1

4
0 -1 16 -1
47 0 34 -1
36 -1 0 34
17 42 -1 0
Sample Output 1

Dijkstra:
node 1 to node 2 : 92
node 1 to node 3 : 16
node 1 to node 4 : 50
node 2 to node 1 : 47
node 2 to node 3 : 34
node 2 to node 4 : 68
node 3 to node 1 : 36
node 3 to node 2 : 76
node 3 to node 4 : 34
node 4 to node 1 : 17
node 4 to node 2 : 42
node 4 to node 3 : 33

Floyd:
0 92 16 50
47 0 34 68
36 76 0 34
17 42 33 0
