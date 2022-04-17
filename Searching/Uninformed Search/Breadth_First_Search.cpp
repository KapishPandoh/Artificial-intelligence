#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map<string ,list<string> >graph;

        void addNode(string x ,string y)
        {
            graph[x].push_back(y);
        }

        void breadthFirstSearch(string start ,string goal)
        {
            unordered_map<string,bool> vis;
            queue<string> qu;

            qu.push(start);
            vis[start]=true;

            cout<<"Path : ";
            while(!qu.empty())
            {
                string node = qu.front();
                qu.pop();

                cout<<node<<" ";

                if(node==goal)
                    break;

                for(auto it : graph[node])
                {
                    if(!vis[it])
                    {
                        vis[it]=true;
                        qu.push(it);
                    }
                }
            }
        }
};


int main()
{
    Graph g;

    g.addNode("A","B");
    g.addNode("A","C");

    g.addNode("B","D");
    g.addNode("B","E");

    g.addNode("C","F");
    g.addNode("C","G");

    g.addNode("D","H");
    g.addNode("D","I");

    g.addNode("E","J");
    g.addNode("E","K");

    g.addNode("F","L");
    g.addNode("F","M");

    g.addNode("G","N");
    g.addNode("G","O");


    string start,goal;
    cout<<"Enter Start Node : "; cin>>start;    //A
    cout<<"Enter Goal Node : "; cin>>goal;      //G

    g.breadthFirstSearch(start,goal);
}
