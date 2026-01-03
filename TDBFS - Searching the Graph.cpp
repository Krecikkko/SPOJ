#include <iostream>
#include <vector>

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
public:
    ~Graph() {
        for (Node* n : nodes) {
            delete n;
        }
    }

    void add(Node* node) {
        this->nodes.push_back(node);
    }

    Node* getNode(int idx) {
        if (idx < 0 || idx >= (int)nodes.size()) {
            return new Node(0);
        }
        return nodes[idx];
    }

    void getString() {
        for (Node* n : nodes) {
            n->getString();
        }
    }
};

int main() {
    Graph* graph = nullptr;

    // Number of graphs
    int t;
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

        graph->getString();

        delete graph;
    }
}