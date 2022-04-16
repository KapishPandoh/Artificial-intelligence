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

        void beam_search(char start ,char goal ,int beamW)
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

               priority_queue<pr,vector<pr>,greater<pr>>temp;
               for(auto it : graph[node])
               {
                  temp.push({hn[it] ,it});
               }


               int beta=0;
               while(!temp.empty())
               {
                   if(beta==beamW)
                      break;

                   auto it = (temp.top()).second;
                   if(!vis[it])
                   {
                      vis[it]=true;
                      pq.push(temp.top());
                      beta++;
                   }
                   temp.pop();
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
    int b;

    cout<<"Enter Start Node : "; cin>>start;  //A
    cout<<"Enter Goal Node  : "; cin>>goal;   //J
    cout<<"Enter Beam Width : "; cin>>b;

    g.beam_search(start,goal,b);

}
