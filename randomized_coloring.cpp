//c++ version c++17
//to compile: g++ -o randomized_coloring randomized_coloring.cpp
//run ./randomized_coloring

#include<iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define NODES 20
using namespace std;

int colours[NODES + 1];

//all values initally 0, easier to just change it to 1 if not available even tho it is not intuitive
bool available_colours[NODES + 1];
bool valid = false;
size_t rounds = 0;

//easier to find node neighbours
std::vector<int> adjacency_list[NODES];

//Coloring vertices 
void coloringVertices()
{
   for(int i = 0; i < NODES; i++)
   {
      bool valid = true;
      int random_number = rand() % NODES;

      do
      {
         rounds += 1;
         int random_number = rand() % NODES;
         if(available_colours[random_number])
         {
            valid = false;
         }
         else
         {
            colours[i] = random_number;
            valid = true;
            available_colours[random_number] = 1;
         }

      } while (!valid);
   }
}

//connects vertices
void make_graph(int u, int v)
{
  adjacency_list[u].push_back(v);
  adjacency_list[v].push_back(u);
}

//automized making random graphs
void automizedGraph()
{
      //std::srand(static_cast<unsigned int>(std::time(0)));
      for(int i = 0; i < NODES; i++)
      {
         int random_number_v = rand() % NODES;
         make_graph(i, random_number_v);

      }
}


void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

//prints which color is assigned to which vertex
void printColors(int colours[NODES])
{
   for(int i = 0; i < NODES; i++)
   {
      cout << "Vertex" << " " << i << " " << "has color" << " " << colours[i] << endl;
   }
}


int main()
{
    printf("Colorful");
   
   //5 nodes
   /*make_graph(0,1);
   make_graph(0,2);
   make_graph(1,2);
   make_graph(1,4);
   make_graph(2,4);
   make_graph(2,3);*/

   //10 nodes
   /*make_graph(0,1);
   make_graph(0,4);
   make_graph(0,3);
   make_graph(1,4);
   make_graph(1,5);
   make_graph(1,2);
   make_graph(2,5);
   make_graph(2,6);
   make_graph(3,4);
   make_graph(3,7);
   make_graph(5,8);
   make_graph(5,9);
   make_graph(6,9);
   make_graph(7,8);
   make_graph(8,9);*/


   //20 nodes
   /*make_graph(0,1);
   make_graph(0,2);
   make_graph(0,3);
   make_graph(0,4);
   make_graph(0,19);
   make_graph(1,2);
   make_graph(1,3);
   make_graph(1,4);
   make_graph(1,11);
   make_graph(2,7);
   make_graph(2,6);
   make_graph(2,3);
   make_graph(3,4);
   make_graph(3,5);
   make_graph(3,11);
   make_graph(4,7);
   make_graph(4,5);
   make_graph(7,9);
   make_graph(7,8);
   make_graph(8,9);
   make_graph(9,18);
   make_graph(10,12);
   make_graph(10,13);
   make_graph(11,18);
   make_graph(11,18);
   make_graph(11,18);
   make_graph(12,13);
   make_graph(13,19);
   make_graph(14,11);
   make_graph(14,15);
   make_graph(15,16);
   make_graph(16,17);*/
   
   //change NODES if needed more vertices
   automizedGraph();
   
   cout << "Graph:" << endl;
   printGraph(adjacency_list, NODES);

   cout << " " << endl;

   coloringVertices();

   printColors(colours);

   cout << "------------------------------------------------" << endl;
   

   //Checks again if there are vertices with same color
   sort(colours, colours + NODES);
   for(int i = 0; i < NODES; i++) 
   {
      if (colours[i] == colours[i + 1]) 
      {
          cout << "NOT VALID" << endl;
      }
   }

   cout << "That took" <<  " "  << rounds << " " << "rounds." << endl;


}