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

        bool findPath(string start ,string goal ,stack<string>& path)
        {
            path.push(start);
            if(start==goal)
                return true;

            for(auto it:graph[start])
            {
               if(findPath(it,goal,path))
                 return true;
               path.pop();
            }
          return false;
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
    cout<<"Enter Start Node : "; cin>>start;        //A
    cout<<"Enter Goal Node : "; cin>>goal;          //G

    stack<string> path;
    bool result = g.findPath(start,goal,path);
    if(result)
    {
       cout<<"\n\t\t\tPath Available"<<endl;
       string res="";
       while(!path.empty())
       {
          res+=path.top();
          path.pop();
       }

       cout<<"\t\t\tPath : ";
       reverse(res.begin(),res.end());
       for(int i=0;i<res.size()-1;i++) cout<<res[i]<<" -> ";
       cout<<res[res.size()-1]<<"\n\n";
    }
    else
        cout<<"\n\t\t\tNo Path Available"<<"\n\n";
}
