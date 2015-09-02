#include<iostream>
using namespace std;

#include "queue.h"

#define MAX 100
 

class graphNode
{
  public:
	int neighNode;
	int weight;
	graphNode *next;
	
};

class graph
{
	private:
		graphNode *nodes[MAX];
		int degree[MAX];
		int nVertices;
		int edgesCount;
	public:
		graph()
		{
			for(int i=0;i<MAX;i++)
				nodes[i]=NULL,degree[i]=0;
			nVertices =0;	
		}
		void readGraph()
		{
			cout<<"Enter the no of Vertices and edges: "; 
			cin>>nVertices>>edgesCount;
			cout<<endl<<"Enter the edges pairs "<<endl;
			for(int i=0;i<edgesCount;i++)
			{
				int x,y;
				cin>>x>>y;
				insertAtHead(x,y);
			}
			
		}
		void insertAtHead(int x,int y)
		{
			graphNode *n = new graphNode();
			n->neighNode = y;
			n->weight =0;
			n->next = nodes[x];
			nodes[x] = n;
			degree[x]++;
		}
		graphNode *getNodeAtIndex(int index)
		{
			return nodes[index];
		}
		int getVerticesCount()
		{
			return nVertices;
		}
};

class Bfs
{
		static const int NV = 0;
		static const int DIS =1;
		static const int PROC =2;
		Queue Q; 
		int *visited_Status;
	public:
		Bfs(int nVertices)
		{
			visited_Status = new int[nVertices];
			for(int i=0;i<nVertices;i++)
				visited_Status[i] = NV;
		}
		void transverse_graph(graph g, int root)
		{
			visited_Status[root] = DIS;
			Q.enQueue((root));
			visited_Status[root] = DIS;
			while(!Q.isEmpty())
			{
				int n = Q.deQueue();
				cout<<"Visited node "<<n<<endl;
				graphNode *p = g.getNodeAtIndex(n);
				// we are storing in the graph only the next nodes so p is used instead of p->next in the condition 
				while(p!=NULL)
				{
					int nIndex = p->neighNode;
					if(visited_Status[nIndex] == NV)
					{
						Q.enQueue(nIndex);
						visited_Status[nIndex] = DIS;
					}
					p = p->next;
				}
				visited_Status[n] = PROC;
			}
		}
};

int main()
{
	graph g;
	g.readGraph();
	Bfs b(g.getVerticesCount());
	b.transverse_graph(g,0);
	return 0;
}

