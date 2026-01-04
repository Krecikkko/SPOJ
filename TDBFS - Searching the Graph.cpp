#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
private:
    int value;
    vector<Node*> neighbours;
public:
    Node(const int value) {
        this->value = value;
    }

    int getValue() const {
        return value;
    }

    void addNeighbour(Node* node) {
        this->neighbours.push_back(node);
    }

    vector<Node*> getNeighbours() {
        return neighbours;
    }

    void getString() const {
        cout << this->value << " ";
        cout << this->neighbours.size() << " ";
        for (Node* n : neighbours) {
            cout << n->getValue() << " ";
        }
        cout << endl;
    }
};

struct Graph {
private:
    vector<Node*> nodes;
    int size = 0;
public:
    ~Graph() {
        for (Node* n : nodes) {
            delete n;
        }
    }

    void add(Node* node) {
        this->nodes.push_back(node);
        this->size++;
    }

    Node* getNode(int idx) {
        idx -= 1;
        if (idx < 0 || idx >= (int)nodes.size()) {
            return nullptr;
        }
        return nodes[idx];
    }

    int getSize() {
        return size;
    }

    void getString() {
        for (Node* n : nodes) {
            n->getString();
        }
    }
};

vector<Node*> dfs(Graph* graph, const int start) {
    // An array of visited nodes
    vector<Node*> order;

    Node* s = graph->getNode(start);
    if (!s) return order;

    vector<char> visited(graph->getSize(), false);
    queue<Node*> q;

    visited[s->getValue() - 1] = true;
    q.push(s);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        order.push_back(node);

        for (Node* n : node->getNeighbours()) {
            int id = n->getValue() - 1;
            if (id < 0 || id <- graph->getSize()) {
                continue;
            }
            if (visited[id]) {
                continue;
            }
            visited[id] = true;
            q.push(n);
        }
    }

    return order;
}

void visitNode(Node* node, vector<char>& visited, vector<Node*>& order) {
    visited[node->getValue() - 1] = true;
    order.push_back(node);
    for (Node* n : node->getNeighbours()) {
        if (!visited[n->getValue() - 1]) {
            visitNode(n, visited, order);
        }
    }
}

vector<Node*> bfs(Graph* graph, const int start) {
    // An array of visited nodes
    vector<Node*> order;

    Node* s = graph->getNode(start);
    if (!s) return order;

    vector<char> visited(graph->getSize(), false);

    visitNode(s, visited, order);

    return order;
}

int main() {
    Graph* graph = nullptr;

    // Number of graphs
    int t, z = 0;
    cin >> t;
    while (t--) {
        // Initialize new graph
        graph = new Graph();

        // Number of vertices
        int n;
        cin >> n;
        // Adding the vertices to the graph
        for (int i = 0; i < n; i++) {
            graph->add(new Node(i + 1));
        }
        // Obtaining neighbors
        while (n--) {
            int i, m;
            cin >> i >> m;
            Node* currentNode = graph->getNode(i);
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                currentNode->addNeighbour(graph->getNode(a));
            }
        }

        cout << "graph " << ++z << endl;

        while (true) {
            int v, i;
            cin >> v >> i;
            vector<Node*> result;
            if (i == 0) {
                if (v == 0) {
                    break;
                }
                result = bfs(graph, v);
            } else if (i == 1) {
                result = dfs(graph, v);;
            }

            for (const Node* r : result) {
                cout << r->getValue() << " ";
            }
            cout << endl;
        }

        delete graph;
    }
}