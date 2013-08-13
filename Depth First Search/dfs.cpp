#include<iostream>
using namespace std;

#include<stdio.h>
#include"stack.h"

class graphNode
{
public:
	int y;
	int weight;
	graphNode *next;
	
};

class graph
{
	private:
		//const int MAX_NODES = 10;
		static const int NV =0;
		static const int DIS =1;
		static const int PROC =2;
		
		graphNode **AdjMatrix;
		int *parent; // keeps the parent index only we can find the parent from the adjancy matrix 
		int *visited_status;
		int *degree; 
		int nVertices;
		int edgesCount;
		int startNode;
	public:
		graph()
		{
			AdjMatrix = NULL;
			parent = NULL;
			visited_status = NULL;
			degree = NULL;
			nVertices=0;
			edgesCount=0;
			startNode =0;
		}
		void readGraph()
		{
			cout<<"Enter the no of vertices and the edges ";
			cin>>nVertices>>edgesCount;
			AdjMatrix = new graphNode*[nVertices];
			parent = new int[nVertices];
			visited_status = new int[nVertices];
			degree = new int[nVertices]; 
			for(int i=0;i<nVertices;i++)
			{
				AdjMatrix[i] = NULL;
				parent[i] = -1;
				visited_status[i] = NV;
				degree[i] = 0;
			}
			cout<<endl<<"Enter the edges of the graph";
			for(int i=0;i<edgesCount;i++)
			{
				int x, y;
				cin>>x>>y;
				insertEdgeInGraph(x,y);
			}
		}
		void insertEdgeInGraph(int x, int y)
		{
			graphNode *t = new graphNode;
			t->y = y;
			t->weight =0;
			t->next = AdjMatrix[x];
			AdjMatrix[x] = t;
			degree[x]++;
		}
		
		void recursive_dfs1(int n)
		{
			startNode =n;
			parent[n] =n;
			recursive_dfs(n);
		}
		
		void recursive_dfs(int n)
		{
			if(visited_status[n]==NV)
			{
				cout<<"visited node "<<n<<endl;
				visited_status[n] = DIS; // this is required as we can reach the node again if the graph is cyclic 
				graphNode *p = AdjMatrix[n];
				while(p!=NULL)
				{
					if(p->y!=startNode && visited_status[p->y] == NV)
					{
						parent[p->y] = n; 
						/* cout<<"Parent of "<<p->y<<" is set as "<<n; */ 
					}
					recursive_dfs(p->y);
					p = p->next;
				}
				visited_status[n] = PROC;
			}
		}
		void stackBased_dfs(int n, stack s)
		{
			startNode = n;
			s.push(n);
			while(!s.isEmpty())
			{
				int x= s.pop();
				visited_status[x] = DIS;
				cout<<"visited node: "<<x<<endl;
				graphNode *p = AdjMatrix[x];
				while(p!=NULL)
				{
					if(visited_status[p->y] == NV)
					{
						s.push(p->y);
						if(p->y!=startNode)
						   parent[p->y] =x;
					}
					p=p->next;
				}
				visited_status[x] = PROC;
			
			}
		}
		void resetVisitedInfo()
		{
			for(int i=0;i<nVertices;i++)
			{
				visited_status[i] = NV;
				degree[i] = 0;
				parent[i] = -1;
			}
			parent[startNode] = startNode;
		}
		void print_path_taken(int n)
		{
			if(parent[n] == n)
			{
				cout<<n<<" ";
				return;
			}
			//cout<<" parent = "<<parent[n];
			print_path_taken(parent[n]);
			cout<<n<<" ";
		}
		
};

int main(int argc, char **argv)
{
	graph g;
	stack s;
	g.readGraph();
	cout<<endl<<"******** Recursive DFS ************"<<endl;
	int x;
	cout<<"Enter the start node :";
	cin>>x;
	cout<<endl <<"Starting recursive Dfs from node "<< x<<endl;
	g.recursive_dfs1(x);
	while(1)
	{
		cout<<"Enter the node whose path to be printed -1 to exit : ";
		int x ;
		cin>>x;
		if(x==-1)
			break;
		cout<<endl<<"Printing path taken for node in dfs "<<x<<" : ";
		g.print_path_taken(x);
		cout<<endl;
	}
	
	g.resetVisitedInfo();
	cout<<endl<<"******** Stack Based DFS ************"<<endl;
	g.stackBased_dfs(0,s);
	g.print_path_taken(3);
	return 0;
}