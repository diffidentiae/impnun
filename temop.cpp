#include <iostream>
#include <stack>

class Vertex
{
	int vertexNum;
	int linkCounter;
	int degreeMax;

	Vertex** linkToVertex;
public:
	Vertex()
	{
		vertexNum = 0;
		linkCounter = 0;
		degreeMax = 1;
		linkToVertex = new Vertex * [degreeMax];
	}

	Vertex(int Num, Vertex * link)
	{
		vertexNum = Num;
		linkCounter = 1;
		degreeMax = 1;
		linkToVertex = new Vertex * [degreeMax];
		linkToVertex[1] = link;
	}


};

int main()
{
	
}
