class Solution {

    struct Edge {
        int node;
        double prob;
    };

    struct Node {
        int node;
        double prob;

        bool operator<(const Node& other) const {
            return prob < other.prob;
        }
    };
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        std::vector<std::vector<Edge>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[a].push_back({b, prob});
            graph[b].push_back({a, prob});
        }

        std::vector<double> maxProbs(n, 0.0);
        maxProbs[start] = 1.0;

        std::priority_queue<Node> pq;
        pq.push({start, 1.0});

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int currNode = curr.node;
            double currProb = curr.prob;

            if (currNode == end) {
                return currProb;
            }

            if (currProb < maxProbs[currNode]) {
                continue;
            }

            for (const Edge& edge : graph[currNode]) {
                int nextNode = edge.node;
                double nextProb = currProb * edge.prob;

                if (nextProb > maxProbs[nextNode]) {
                    maxProbs[nextNode] = nextProb;
                    pq.push({nextNode, nextProb});
                }
            }
        }

        return 0.0;
    }
};