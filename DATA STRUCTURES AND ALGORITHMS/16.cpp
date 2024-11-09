#include <iostream>
using namespace std;

#define maxNodes 8

void initializeGraph(int matrix[maxNodes][maxNodes], int vertexValues[maxNodes]) {
    // Set all values in the adjacency matrix to 0
    for (int i = 0; i < maxNodes; i++) {
        for (int j = 0; j < maxNodes; j++) {
            matrix[i][j] = 0;
        }
    }
    cout << "Provide the Vertex values: ";
    for (int i = 0; i < maxNodes; i++) {
        cin >> vertexValues[i];
    }
}

void addEdge(int matrix[maxNodes][maxNodes], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1; // Undirected graph
}

void updateNodeValue(int vertexValues[maxNodes], int nodeIndex, int newValue) {
    if (nodeIndex >= 0 && nodeIndex < maxNodes) {
        vertexValues[nodeIndex] = newValue;
    } else {
        cout << "Invalid node index!" << endl;
    }
}

void displayGraph(int matrix[maxNodes][maxNodes], int vertexValues[maxNodes]) {
    for (int i = 0; i < maxNodes; i++) {
        cout << "Vertex " << vertexValues[i] << ":";
        for (int j = 0; j < maxNodes; j++) {
            if (matrix[i][j] == 1) {
                cout << " -> " << vertexValues[j];
            }
        }
        cout << endl;
    }
}

void enqueue(int queue[], int &rear, int value) {
    if (rear < maxNodes - 1) {
        queue[++rear] = value;
    } else {
        cout << "Queue is full, cannot add more" << endl;
    }
}

int dequeue(int queue[], int &front, int rear) {
    if (front > rear) {
        return -1; // Indicating the queue is empty
    }
    return queue[front++];
}

bool isEmpty(int front, int rear) {
    return front > rear;
}

void bfs(int matrix[maxNodes][maxNodes], int values[maxNodes], int initialNode) {
    int queue[maxNodes];
    int front = 0;
    int rear = -1;
    bool visitedArr[maxNodes] = {false};

    enqueue(queue, rear, initialNode);
    visitedArr[initialNode] = true;
    cout << "BFS traversal: ";

    while (!isEmpty(front, rear)) {
        int currentVertex = dequeue(queue, front, rear);
        cout << values[currentVertex] << " ";

        for (int i = 0; i < maxNodes; i++) {  
            if (matrix[currentVertex][i] == 1 && !visitedArr[i]) {
                enqueue(queue, rear, i);
                visitedArr[i] = true;
            }
        }
    }
    cout << endl;
}
void helperforDFS(int matrix[maxNodes][maxNodes], bool visitedArr[maxNodes], int currentVertex, int values[maxNodes]) {

    visitedArr[currentVertex] = true;
    cout << values[currentVertex] << " ";
    for (int i = 0; i < maxNodes; i++) {
        if (matrix[currentVertex][i] == 1 && !visitedArr[i]) {
            helperforDFS(matrix, visitedArr, i, values);
        }
    }
}

void dfs(int matrix[maxNodes][maxNodes], int values[maxNodes], int initialNode) {
    bool visitedArr[maxNodes] = {false}; 
    cout << "DFS traversal: ";
    helperforDFS(matrix, visitedArr, initialNode, values);
    cout << endl;
}

int main() {
    int matrix[maxNodes][maxNodes];
    int vertexValues[maxNodes];
    initializeGraph(matrix, vertexValues);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a new edge\n";
        cout << "2. Update a new node's value\n";
        cout << "3. Display the graph\n";
        cout << "4. Perform BFS\n"; // Updated menu option for BFS
        cout << "5. Exit\n"; // Exiting option
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v;
                cout << "Enter the vertices (0 to " << maxNodes - 1 << ") to connect: ";
                cin >> u >> v;
                if (u >= 0 && u < maxNodes && v >= 0 && v < maxNodes) {
                    addEdge(matrix, u, v);
                    cout << "Edge added between " << vertexValues[u] << " and " << vertexValues[v] << "." << endl;
                } else {
                    cout << "Invalid vertex numbers!" << endl;
                }
                break;
            }
            case 2: {
                int nodeIndex, newValue;
                cout << "Enter the node index (0 to " << maxNodes - 1 << ") to update: ";
                cin >> nodeIndex;
                cout << "Enter the new value: ";
                cin >> newValue;
                updateNodeValue(vertexValues, nodeIndex, newValue);
                cout << "Node value updated." << endl;
                break;
            }
            case 3: {
                displayGraph(matrix, vertexValues);
                break;
            }
            case 4: {  // BFS option
                int start;
                cout << "Provide the node from where you want to start BFS: ";
                cin >> start;
                if (start >= 0 && start < maxNodes) {
                    bfs(matrix, vertexValues, start);
                } else {
                    cout << "Invalid starting node!" << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
