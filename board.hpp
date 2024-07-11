/*
323858324
shannya08@gmail.com
 */
#pragma once
#include <map>
#include "CTools.hpp"


enum class Ground {
	Desert = 0,
	Forest, // Resources.wood -> 1 / 2
	Hills,
	Mountains,
	Agricultural_Land,
	Pasture_Land
};

static int vertexNumber = 0;

class Vertex {
	int number;

public:

	Vertex() {
		number = vertexNumber++;
	}
	~Vertex() {}

	int getNumber() const {
		return number;
	}
};

class Edge {
	Vertex v1, v2;

public:
	Edge(const Vertex& _v1, const Vertex& _v2) {
		v1 = _v1;
		v2 = _v2;
	}
	~Edge() {

	}

	std::vector<Vertex> getVertex() const {
		return std::vector<Vertex>{v1, v2};
	}
	std::vector<int> getVertexints() const {
		return std::vector<int>{v1.getNumber(), v2.getNumber()};
	}
};

class Tile {
	int number;
	Ground ground;
	std::vector<Vertex> verteces;

public:
	int getTileNum()const{
		return number;
	}
	Ground getTileGround()const{
		return ground;
	}
	std::vector<Vertex> getTileVerteces()const{
		return verteces;
	}
	Tile(const int num, const Ground g, const std::vector<Vertex>& v) {
		number = num;
		ground = g;
		verteces = v;
	}
	~Tile() {}

};

class Board {
	std::vector<Tile> tiles;
	std::vector<Vertex> verteces;
	std::vector<Edge> edges;

	std::map<int, std::vector<Vertex>> VertexNeighborVerteces;
	std::map<int, std::vector<Edge>> VertexNeighborEdges;

	void createEdges();
	void createTiles();
	void createMapVerteces();
	void createMapEdges();
public:

	Board();
	~Board();

	void initBoard();
	void printBoard();
	std::vector<std::pair<Ground,std::vector<Vertex>>>findVertecesAroundTile(int num)const;
	std::map<int, std::vector<Vertex>> GetVertexNeighborVerteces();
	std::vector<Vertex>& findVertexNeighbors(int index) ;
	std::vector<Edge> findVertexEdgesNeighbors(int index) const;
	std::vector<Tile> getTiles() const{return tiles;}
	std::vector<Vertex> getVerteces() const {return verteces;}
	std::vector<Edge> getEdges() const{return edges;}
	void test() const;
};