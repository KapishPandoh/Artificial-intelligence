#include<bits/stdc++.h>
using namespace std;

typedef pair<int,char> pr;

class Graph
{
    public:
        unordered_map<char ,list<char> >graph;
        unordered_map<char,int> hn;

        void addNode(char x ,char y)
        {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        void addHeuristicValue(char node ,int heuristic)
        {
           hn[node] = heuristic;
        }

        void best_first_search(char start ,char goal)
        {
            unordered_map<char,bool>vis;
            priority_queue<pr ,vector<pr> ,greater<pr> >pq;

            vis[start]=true;
            pq.push({hn[start],start});

            cout<<"Path : ";
            while(!pq.empty())
            {
               char node = (pq.top()).second;
               pq.pop();

               cout<<node<<" ";

               if(node==goal)
                 break;

               for(auto it : graph[node])
               {
                   if(!vis[it])
                   {
                      vis[it]=true;
                      pq.push({hn[it],it});
                   }
               }
            }
        }
};


int main()
{
    Graph g;

    // ADD NODE
    g.addNode('A','B');
    g.addNode('A','C');
    g.addNode('A','D');
    g.addNode('B','G');
    g.addNode('B','H');
    g.addNode('D','E');
    g.addNode('D','F');
    g.addNode('E','I');
    g.addNode('E','J');

    // ADD Heuristic VALUE
    g.addHeuristicValue('A',10);
    g.addHeuristicValue('B',5);
    g.addHeuristicValue('C',6);
    g.addHeuristicValue('D',1);
    g.addHeuristicValue('E',4);
    g.addHeuristicValue('F',6);
    g.addHeuristicValue('G',6);
    g.addHeuristicValue('H',5);
    g.addHeuristicValue('I',10);
    g.addHeuristicValue('J',0);

    char start,goal;

    cout<<"Enter Start Node : "; cin>>start;  //A
    cout<<"Enter Goal Node  : "; cin>>goal;   //J

    g.best_first_search(start,goal);

}
