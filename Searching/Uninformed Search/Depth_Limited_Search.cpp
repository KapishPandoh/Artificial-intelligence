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

        bool findPath(string start ,string goal ,int limit ,vector<string>& path)
        {
            stack<string> st;

            st.push(start);
            int depth=0;

            while(!st.empty())
            {
                cout<<st.top()<<" ";
                if(depth<=limit)
                {
                    string node = st.top();
                    st.pop();
                    path.push_back(node);

                    depth++;

                    if(node==goal)
                    {
                        cout<<"\n\nGoal node found";
                        return true;
                    }

                    for(auto it:graph[node])
                        st.push(it);
                }

                else
                {
                    cout<<"\n\nGoal Node not found within depth limit";
                    return false;
                }
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
    int limit;
    cout<<"Enter Start Node : "; cin>>start;        //A
    cout<<"Enter Goal Node  : "; cin>>goal;          //G
    cout<<"Enter Limit      : "; cin>>limit;

    vector<string> path;
    bool result = g.findPath(start,goal,limit,path);
    if(result)
    {
       cout<<"\nPath Available"<<endl;
       for(int i=0;i<path.size()-1;i++) cout<<path[i]<<" -> ";
       cout<<path[path.size()-1]<<"\n\n";
    }
    else
        cout<<"\nNo Path Available"<<"\n\n";
}
