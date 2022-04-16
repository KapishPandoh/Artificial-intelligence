#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map<char ,list<pair<char,int>> >graph;
        unordered_map<char,int> hn;
        unordered_map<char,int>dist;

        void addNode(char x ,char y ,int cost ,int heuristic)
        {
            graph[x].push_back({y,cost});
            hn[y] = heuristic;
            dist[x] = INT_MAX;
            dist[y] = INT_MAX;
        }

        void a_star_algo(char start ,char goal)
        {
            unordered_map<char,char>parent;
            unordered_map<char,bool>vis;      // closed list
            set<pair<int,char>> open;         // open list
            stack<char> path;

            open.insert({0,start});
            parent[start]=start;
            dist[start]=0;

            while(!open.empty())
            {
                auto n = *(open.begin());
                char node = n.second;
                open.erase(open.begin());

                if(node==goal)
                {
                   while(parent[node]!=node)
                   {
                       path.push(node);
                       node = parent[node];
                   }
                   path.push(start);

                   break;
                }

                for(auto it : graph[node])
                {
                   int v = it.first;
                   int cost = it.second;

                   if(dist[v]>dist[node]+cost)
                   {
                      auto fnd = open.find({dist[v]+hn[v],v});
                      if(fnd!=open.end())
                        open.erase(fnd);

                      parent[v] = node;
                      dist[v]   = dist[node]+cost;
                      open.insert({dist[v]+hn[v],v});
                   }
                 }
            }

            if(path.empty())
            {
                cout<<"No Available Path"<<endl;
                return;
            }

            cout<<"Path : ";
            while(!path.empty())
            {
                cout<<path.top()<<" ";
                path.pop();
            }
            cout<<" ,with total cost of : "<<dist[goal]+hn[goal]<<endl;
        }
};


int main()
{
    Graph g;

    // ADD NODE
    g.addNode('S','B',4,12);
    g.addNode('S','C',3,11);
    g.addNode('B','F',5,11);
    g.addNode('B','E',12,4);
    g.addNode('C','E',10,4);
    g.addNode('C','D',7,6);
    g.addNode('D','E',2,4);
    g.addNode('F','G',16,0);
    g.addNode('E','G',5,0);


    char start,goal;

    cout<<"Enter Start Node : "; cin>>start;  //S
    cout<<"Enter Goal Node  : "; cin>>goal;   //G

    g.a_star_algo(start,goal);

}
