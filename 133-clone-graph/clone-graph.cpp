class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> clone;
        queue<Node*> q;

        clone[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            for (Node* nei : curr->neighbors) {
                if (!clone.count(nei)) {
                    clone[nei] = new Node(nei->val);
                    q.push(nei);
                }
                
                clone[curr]->neighbors.push_back(clone[nei]);
            }
        }

        return clone[node];
    }
};
