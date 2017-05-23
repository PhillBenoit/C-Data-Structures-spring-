#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <list>
#include <stack>
#include <iterator>

using namespace std;

#include "genBST.h"

#ifndef DISTINCTREPRESENTATIVES
#define DISTINCTREPRESENTATIVES

class VertexArrayRec;
class LocalTree;
class Network;

class Vertex {
public:
	Vertex() {
	}
	Vertex(int id, int c, int ef, bool f, Vertex *t = 0) {
		idNum = id; capacity = c; edgeFlow = ef; forward = f; twin = t;
	}
	bool operator== (const Vertex& v) const {
		return idNum == v.idNum;
	}
	bool operator!= (const Vertex& v) const { // required
		return idNum != v.idNum;
	}
	bool operator< (const Vertex& v) const {  // by the compiler;
		return idNum < v.idNum;
	}
	bool operator> (const Vertex& v) const {
		return idNum > v.idNum;
	}
private:
	int idNum, capacity, edgeFlow;
	bool forward;	// direction;
	Vertex *twin;	// edge in the opposite direction;
	friend class Network;
	friend ostream& operator<< (ostream&, const Vertex&);
};

class NetTreeNode {
public:
	NetTreeNode(VertexArrayRec **v = 0) {
		verticesPtr = v;
		adjacent = new list<Vertex>;
	}
	bool operator<  (const NetTreeNode& tr) const {
		return strcmp(idName, tr.idName) < 0;
	}
	bool operator== (const NetTreeNode& tr) const {
		return strcmp(idName, tr.idName) == 0;
	}
private:
	int idNum;
	char *idName;
	VertexArrayRec **verticesPtr;
	list<Vertex> *adjacent;
	friend class Network;
	friend class LocalTree;
	friend ostream& operator<< (ostream&, const NetTreeNode&);
};

class VertexArrayRec {
public:
	VertexArrayRec() {
		adjacent = 0;
	}
private:
	char *idName;
	int vertexFlow;
	bool labeled;
	int parent;
	Vertex *corrVer;   	    // corresponding vertex: vertex on parent's
	list<Vertex> *adjacent; // list of adjacent vertices with the same
	friend class Network;   // idNum as the cell's index;
	friend class LocalTree;
	friend ostream& operator<< (ostream&, const Network&);
};

#endif