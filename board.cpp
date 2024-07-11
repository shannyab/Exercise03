/*
323858324
shannya08@gmail.com
 */
#include <iostream>
#include <vector>
#include "board.hpp"
#include <map>
using std::cout;
using std::endl;

Board::Board() {
	verteces.resize(54);

	initBoard();

}
Board::~Board() {

}

void Board::createEdges() {
	const int NUMBER_EDGES = 72;
	edges.reserve(NUMBER_EDGES);

	edges.emplace_back(verteces[0], verteces[1]);
	edges.emplace_back(verteces[1], verteces[2]);
	edges.emplace_back(verteces[2], verteces[3]);
	edges.emplace_back(verteces[3], verteces[4]);
	edges.emplace_back(verteces[4], verteces[5]);
	edges.emplace_back(verteces[5], verteces[6]);
	edges.emplace_back(verteces[0], verteces[8]);
	edges.emplace_back(verteces[2], verteces[10]);
	edges.emplace_back(verteces[4], verteces[12]);
	edges.emplace_back(verteces[6], verteces[14]);
	edges.emplace_back(verteces[7], verteces[8]);
	edges.emplace_back(verteces[8], verteces[9]);
	edges.emplace_back(verteces[9], verteces[10]);
	edges.emplace_back(verteces[10], verteces[11]);
	edges.emplace_back(verteces[11], verteces[12]);
	edges.emplace_back(verteces[12], verteces[13]);
	edges.emplace_back(verteces[13], verteces[14]);
	edges.emplace_back(verteces[14], verteces[15]);
	edges.emplace_back(verteces[7], verteces[17]);
	edges.emplace_back(verteces[9], verteces[19]);
	edges.emplace_back(verteces[11], verteces[21]);
	edges.emplace_back(verteces[13], verteces[23]);
	edges.emplace_back(verteces[15], verteces[25]);
	edges.emplace_back(verteces[16], verteces[17]);
	edges.emplace_back(verteces[17], verteces[18]);
	edges.emplace_back(verteces[18], verteces[19]);
	edges.emplace_back(verteces[19], verteces[20]);
	edges.emplace_back(verteces[20], verteces[21]);
	edges.emplace_back(verteces[21], verteces[22]);
	edges.emplace_back(verteces[22], verteces[23]);
	edges.emplace_back(verteces[23], verteces[24]);
	edges.emplace_back(verteces[24], verteces[25]);
	edges.emplace_back(verteces[25], verteces[26]);
	edges.emplace_back(verteces[16], verteces[27]);
	edges.emplace_back(verteces[18], verteces[29]);
	edges.emplace_back(verteces[20], verteces[31]); 
	edges.emplace_back(verteces[22], verteces[33]);
	edges.emplace_back(verteces[24], verteces[35]);
	edges.emplace_back(verteces[26], verteces[37]);
	edges.emplace_back(verteces[27], verteces[28]);
	edges.emplace_back(verteces[28], verteces[29]);
	edges.emplace_back(verteces[29], verteces[30]);
	edges.emplace_back(verteces[30], verteces[31]);
	edges.emplace_back(verteces[31], verteces[32]);
	edges.emplace_back(verteces[32], verteces[33]);
	edges.emplace_back(verteces[33], verteces[34]);
	edges.emplace_back(verteces[34], verteces[35]);
	edges.emplace_back(verteces[35], verteces[36]);
	edges.emplace_back(verteces[36], verteces[37]);
	edges.emplace_back(verteces[28], verteces[38]);
	edges.emplace_back(verteces[30], verteces[40]);
	edges.emplace_back(verteces[32], verteces[42]);
	edges.emplace_back(verteces[34], verteces[44]);
	edges.emplace_back(verteces[36], verteces[46]);
	edges.emplace_back(verteces[38], verteces[39]);
	edges.emplace_back(verteces[39], verteces[40]);
	edges.emplace_back(verteces[40], verteces[41]);
	edges.emplace_back(verteces[41], verteces[42]);
	edges.emplace_back(verteces[42], verteces[43]);
	edges.emplace_back(verteces[43], verteces[44]);
	edges.emplace_back(verteces[44], verteces[45]);
	edges.emplace_back(verteces[45], verteces[46]);
	edges.emplace_back(verteces[39], verteces[47]);
	edges.emplace_back(verteces[41], verteces[49]);
	edges.emplace_back(verteces[43], verteces[51]);
	edges.emplace_back(verteces[45], verteces[53]);
	edges.emplace_back(verteces[47], verteces[48]);
	edges.emplace_back(verteces[48], verteces[49]);
	edges.emplace_back(verteces[49], verteces[50]);
	edges.emplace_back(verteces[50], verteces[51]);
	edges.emplace_back(verteces[51], verteces[52]);
	edges.emplace_back(verteces[52], verteces[53]);
	
	
	
	
}
void Board::createTiles() {
	const int NUMBER_TILES = 19;
	tiles.reserve(NUMBER_TILES);
	tiles.emplace_back(9, Ground::Forest,
		std::vector<Vertex>{ verteces[0],verteces[1],verteces[2],verteces[8],verteces[9],verteces[10]});
	tiles.emplace_back(2, Ground::Pasture_Land,
		std::vector<Vertex>{ verteces[2],verteces[3],verteces[4],verteces[10],verteces[11],verteces[12]});
	tiles.emplace_back(10, Ground::Mountains,
		std::vector<Vertex>{ verteces[4],verteces[5],verteces[6],verteces[12],verteces[13],verteces[14]});
	tiles.emplace_back(10, Ground::Hills,
		std::vector<Vertex>{ verteces[7],verteces[8],verteces[9],verteces[17],verteces[18],verteces[19]});
	tiles.emplace_back(4, Ground::Pasture_Land,
		std::vector<Vertex>{ verteces[9],verteces[10],verteces[11],verteces[19],verteces[20],verteces[21]});
	tiles.emplace_back(6, Ground::Hills,
		std::vector<Vertex>{ verteces[11],verteces[12],verteces[13],verteces[21],verteces[22],verteces[23]});
	tiles.emplace_back(12, Ground::Agricultural_Land,
		std::vector<Vertex>{ verteces[13],verteces[14],verteces[15],verteces[23],verteces[24],verteces[25]});
		tiles.emplace_back(8, Ground::Mountains,
		std::vector<Vertex>{ verteces[16],verteces[17],verteces[18],verteces[27],verteces[28],verteces[29]});
	tiles.emplace_back(3, Ground::Forest,
		std::vector<Vertex>{ verteces[18],verteces[19],verteces[20],verteces[29],verteces[30],verteces[31]});
		tiles.emplace_back(0, Ground::Desert,
		std::vector<Vertex>{ verteces[20],verteces[21],verteces[22],verteces[31],verteces[32],verteces[33]});
		tiles.emplace_back(11, Ground::Forest,
		std::vector<Vertex>{ verteces[22],verteces[23],verteces[24],verteces[33],verteces[34],verteces[35]});
		tiles.emplace_back(9, Ground::Agricultural_Land,
		std::vector<Vertex>{ verteces[24],verteces[25],verteces[26],verteces[35],verteces[36],verteces[37]});
		tiles.emplace_back(5, Ground::Pasture_Land,
		std::vector<Vertex>{ verteces[28],verteces[29],verteces[30],verteces[38],verteces[39],verteces[40]});
		tiles.emplace_back(4, Ground::Agricultural_Land,
		std::vector<Vertex>{ verteces[30],verteces[31],verteces[32],verteces[40],verteces[41],verteces[42]});
		tiles.emplace_back(3, Ground::Mountains,
		std::vector<Vertex>{ verteces[32],verteces[33],verteces[34],verteces[42],verteces[43],verteces[44]});
		tiles.emplace_back(8, Ground::Forest,
		std::vector<Vertex>{ verteces[34],verteces[35],verteces[36],verteces[44],verteces[45],verteces[46]});
		tiles.emplace_back(11, Ground::Pasture_Land,
		std::vector<Vertex>{ verteces[39],verteces[40],verteces[41],verteces[47],verteces[48],verteces[49]});
		tiles.emplace_back(6, Ground::Agricultural_Land,
		std::vector<Vertex>{ verteces[41],verteces[42],verteces[43],verteces[49],verteces[50],verteces[51]});
		tiles.emplace_back(5, Ground::Hills,
		std::vector<Vertex>{ verteces[43],verteces[44],verteces[45],verteces[51],verteces[52],verteces[53]});
	

}
void Board::createMapVerteces(){
    VertexNeighborVerteces.emplace(0, std::vector<Vertex>{verteces[1],verteces[8]});
	 VertexNeighborVerteces.emplace(1, std::vector<Vertex>{verteces[0],verteces[2]});
	VertexNeighborVerteces.emplace(2, std::vector<Vertex>{verteces[1],verteces[3],verteces[10]});
	VertexNeighborVerteces.emplace(3, std::vector<Vertex>{verteces[4],verteces[2]});
	VertexNeighborVerteces.emplace(4, std::vector<Vertex>{verteces[5],verteces[3],verteces[12]});
	VertexNeighborVerteces.emplace(5, std::vector<Vertex>{verteces[6],verteces[4]});
	VertexNeighborVerteces.emplace(6, std::vector<Vertex>{verteces[14],verteces[5]});
	VertexNeighborVerteces.emplace(7, std::vector<Vertex>{verteces[8],verteces[17]});
	VertexNeighborVerteces.emplace(8, std::vector<Vertex>{verteces[9],verteces[7],verteces[0]});
	VertexNeighborVerteces.emplace(9, std::vector<Vertex>{verteces[10],verteces[8],verteces[19]});
	VertexNeighborVerteces.emplace(10, std::vector<Vertex>{verteces[9],verteces[11],verteces[2]});
	VertexNeighborVerteces.emplace(11, std::vector<Vertex>{verteces[10],verteces[21],verteces[12]});
	VertexNeighborVerteces.emplace(12, std::vector<Vertex>{verteces[4],verteces[11],verteces[13]});
	VertexNeighborVerteces.emplace(13, std::vector<Vertex>{verteces[14],verteces[12],verteces[23]});
	VertexNeighborVerteces.emplace(14, std::vector<Vertex>{verteces[6],verteces[15],verteces[13]});
	VertexNeighborVerteces.emplace(15, std::vector<Vertex>{verteces[25],verteces[14]});
	VertexNeighborVerteces.emplace(16, std::vector<Vertex>{verteces[17],verteces[27]});
	VertexNeighborVerteces.emplace(17, std::vector<Vertex>{verteces[16],verteces[7],verteces[18]});
	VertexNeighborVerteces.emplace(18, std::vector<Vertex>{verteces[19],verteces[17],verteces[29]});
	VertexNeighborVerteces.emplace(19, std::vector<Vertex>{verteces[18],verteces[20],verteces[9]});
	VertexNeighborVerteces.emplace(20, std::vector<Vertex>{verteces[19],verteces[21],verteces[31]});
	VertexNeighborVerteces.emplace(21, std::vector<Vertex>{verteces[20],verteces[22],verteces[11]});
	VertexNeighborVerteces.emplace(22, std::vector<Vertex>{verteces[21],verteces[23],verteces[33]});
	VertexNeighborVerteces.emplace(23, std::vector<Vertex>{verteces[13],verteces[22],verteces[24]});
	VertexNeighborVerteces.emplace(24, std::vector<Vertex>{verteces[23],verteces[25],verteces[35]});
	VertexNeighborVerteces.emplace(25, std::vector<Vertex>{verteces[15],verteces[24],verteces[26]});
	VertexNeighborVerteces.emplace(26, std::vector<Vertex>{verteces[25],verteces[37]});
	VertexNeighborVerteces.emplace(27, std::vector<Vertex>{verteces[28],verteces[16]});
	VertexNeighborVerteces.emplace(28, std::vector<Vertex>{verteces[27],verteces[29],verteces[38]});
	VertexNeighborVerteces.emplace(29, std::vector<Vertex>{verteces[18],verteces[28],verteces[30]});
	VertexNeighborVerteces.emplace(30, std::vector<Vertex>{verteces[31],verteces[40],verteces[29]});
	VertexNeighborVerteces.emplace(31, std::vector<Vertex>{verteces[20],verteces[30],verteces[32]});
	VertexNeighborVerteces.emplace(32, std::vector<Vertex>{verteces[33],verteces[31],verteces[42]});
	VertexNeighborVerteces.emplace(33, std::vector<Vertex>{verteces[22],verteces[34],verteces[32]});
	VertexNeighborVerteces.emplace(34, std::vector<Vertex>{verteces[35],verteces[33],verteces[44]});
	VertexNeighborVerteces.emplace(35, std::vector<Vertex>{verteces[36],verteces[34],verteces[24]});
	VertexNeighborVerteces.emplace(36, std::vector<Vertex>{verteces[35],verteces[37],verteces[46]});
	VertexNeighborVerteces.emplace(37, std::vector<Vertex>{verteces[36],verteces[26]});
	VertexNeighborVerteces.emplace(38, std::vector<Vertex>{verteces[39],verteces[28]});
	VertexNeighborVerteces.emplace(39, std::vector<Vertex>{verteces[38],verteces[40],verteces[47]});
	VertexNeighborVerteces.emplace(40, std::vector<Vertex>{verteces[30],verteces[39],verteces[41]});
	VertexNeighborVerteces.emplace(41, std::vector<Vertex>{verteces[40],verteces[42],verteces[49]});
	VertexNeighborVerteces.emplace(42, std::vector<Vertex>{verteces[32],verteces[41],verteces[43]});
	VertexNeighborVerteces.emplace(43, std::vector<Vertex>{verteces[42],verteces[44],verteces[51]});
	VertexNeighborVerteces.emplace(44, std::vector<Vertex>{verteces[45],verteces[34],verteces[43]});
	VertexNeighborVerteces.emplace(45, std::vector<Vertex>{verteces[44],verteces[46],verteces[53]});
	VertexNeighborVerteces.emplace(46, std::vector<Vertex>{verteces[36],verteces[45]});
	VertexNeighborVerteces.emplace(47, std::vector<Vertex>{verteces[39],verteces[48]});
	VertexNeighborVerteces.emplace(48, std::vector<Vertex>{verteces[47],verteces[49]});
	VertexNeighborVerteces.emplace(49, std::vector<Vertex>{verteces[41],verteces[48],verteces[50]});
	VertexNeighborVerteces.emplace(50, std::vector<Vertex>{verteces[49],verteces[51]});
	VertexNeighborVerteces.emplace(51, std::vector<Vertex>{verteces[43],verteces[50],verteces[52]});
	VertexNeighborVerteces.emplace(52, std::vector<Vertex>{verteces[51],verteces[53]});
	VertexNeighborVerteces.emplace(53, std::vector<Vertex>{verteces[45],verteces[52]});
}
void Board::createMapEdges() {
    VertexNeighborEdges.emplace(0, std::vector<Edge>{edges[0], edges[6]});
    VertexNeighborEdges.emplace(1, std::vector<Edge>{edges[0], edges[1]});
    VertexNeighborEdges.emplace(2, std::vector<Edge>{edges[1], edges[2], edges[7]});
    VertexNeighborEdges.emplace(3, std::vector<Edge>{edges[2], edges[3]});
    VertexNeighborEdges.emplace(4, std::vector<Edge>{edges[3], edges[4], edges[8]});
    VertexNeighborEdges.emplace(5, std::vector<Edge>{edges[4], edges[5]});
    VertexNeighborEdges.emplace(6, std::vector<Edge>{edges[5], edges[9]});
    VertexNeighborEdges.emplace(7, std::vector<Edge>{edges[18], edges[10]});
    VertexNeighborEdges.emplace(8, std::vector<Edge>{edges[6], edges[10], edges[11]});
    VertexNeighborEdges.emplace(9, std::vector<Edge>{edges[11], edges[12], edges[19]});
    VertexNeighborEdges.emplace(10, std::vector<Edge>{edges[7], edges[12], edges[13]});
    VertexNeighborEdges.emplace(11, std::vector<Edge>{edges[13], edges[14], edges[20]});
    VertexNeighborEdges.emplace(12, std::vector<Edge>{edges[8], edges[14], edges[15]});
    VertexNeighborEdges.emplace(13, std::vector<Edge>{edges[15], edges[16], edges[21]});
    VertexNeighborEdges.emplace(14, std::vector<Edge>{edges[9], edges[16], edges[17]});
    VertexNeighborEdges.emplace(15, std::vector<Edge>{edges[17], edges[22]});
    VertexNeighborEdges.emplace(16, std::vector<Edge>{edges[23], edges[33]});
    VertexNeighborEdges.emplace(17, std::vector<Edge>{edges[18], edges[23], edges[24]});
    VertexNeighborEdges.emplace(18, std::vector<Edge>{edges[24], edges[25], edges[34]});
    VertexNeighborEdges.emplace(19, std::vector<Edge>{edges[19], edges[25], edges[26]});
    VertexNeighborEdges.emplace(20, std::vector<Edge>{edges[26], edges[27], edges[35]});
    VertexNeighborEdges.emplace(21, std::vector<Edge>{edges[20], edges[27], edges[28]});
    VertexNeighborEdges.emplace(22, std::vector<Edge>{edges[28], edges[29], edges[36]});
    VertexNeighborEdges.emplace(23, std::vector<Edge>{edges[21], edges[29], edges[30]});
    VertexNeighborEdges.emplace(24, std::vector<Edge>{edges[30], edges[37], edges[31]});
    VertexNeighborEdges.emplace(25, std::vector<Edge>{edges[22], edges[31], edges[32]});
    VertexNeighborEdges.emplace(26, std::vector<Edge>{edges[32], edges[38]});
    VertexNeighborEdges.emplace(27, std::vector<Edge>{edges[33], edges[39]});
    VertexNeighborEdges.emplace(28, std::vector<Edge>{edges[39], edges[40], edges[49]});
    VertexNeighborEdges.emplace(29, std::vector<Edge>{edges[34], edges[40], edges[41]});
    VertexNeighborEdges.emplace(30, std::vector<Edge>{edges[41], edges[42], edges[50]});
    VertexNeighborEdges.emplace(31, std::vector<Edge>{edges[35], edges[42], edges[43]});
    VertexNeighborEdges.emplace(32, std::vector<Edge>{edges[44], edges[43], edges[51]});
    VertexNeighborEdges.emplace(33, std::vector<Edge>{edges[36], edges[44], edges[45]});
    VertexNeighborEdges.emplace(34, std::vector<Edge>{edges[45], edges[46], edges[52]});
    VertexNeighborEdges.emplace(35, std::vector<Edge>{edges[37], edges[46], edges[47]});
    VertexNeighborEdges.emplace(36, std::vector<Edge>{edges[47], edges[48], edges[53]});
    VertexNeighborEdges.emplace(37, std::vector<Edge>{edges[38], edges[48]});
    VertexNeighborEdges.emplace(38, std::vector<Edge>{edges[49], edges[54]});
    VertexNeighborEdges.emplace(39, std::vector<Edge>{edges[54], edges[55], edges[62]});
    VertexNeighborEdges.emplace(40, std::vector<Edge>{edges[50], edges[55], edges[56]});
    VertexNeighborEdges.emplace(41, std::vector<Edge>{edges[56], edges[57], edges[63]});
    VertexNeighborEdges.emplace(42, std::vector<Edge>{edges[51], edges[57], edges[58]});
    VertexNeighborEdges.emplace(43, std::vector<Edge>{edges[58], edges[59], edges[64]});
    VertexNeighborEdges.emplace(44, std::vector<Edge>{edges[52], edges[59], edges[60]});
    VertexNeighborEdges.emplace(45, std::vector<Edge>{edges[60], edges[61], edges[65]});
    VertexNeighborEdges.emplace(46, std::vector<Edge>{edges[53], edges[61]});
    VertexNeighborEdges.emplace(47, std::vector<Edge>{edges[62], edges[66]});
    VertexNeighborEdges.emplace(48, std::vector<Edge>{edges[66], edges[67]});
    VertexNeighborEdges.emplace(49, std::vector<Edge>{edges[63], edges[67], edges[68]});
    VertexNeighborEdges.emplace(50, std::vector<Edge>{edges[68], edges[69]});
    VertexNeighborEdges.emplace(51, std::vector<Edge>{edges[64], edges[69], edges[70]});
    VertexNeighborEdges.emplace(52, std::vector<Edge>{edges[70], edges[71]});
    VertexNeighborEdges.emplace(53, std::vector<Edge>{edges[65], edges[71]});
}





void Board::initBoard(){
		createEdges();

		createTiles();

		createMapVerteces();

		createMapEdges();


} 



void Board::printBoard(){
  std::vector<std::string> board = {
        "       10 (Mountains)   2 (Pasture land)   9 (Forest)",
        "    12 (Agricultural Land)   6 (Hills)   4 (Pasture land)   10 (Hills)",
        "9 (Agricultural land)   11 (Forest)   0 (Desert)   3 (Forest)   8 (Mountains)",
        "     8 (Forest)   3 (Mountains)   4 (Agricultural Land)   5 (Pasture land)",
        "         5 (Hills)   6 (Agricultural Land)   11 (Pasture land)"
    };

    for (const auto& line : board) {
		 std::cout << " " << std::endl;
        std::cout << line << std::endl;
    }
	 std::cout << " " << std::endl;
}


	std::vector<Vertex>& Board::findVertexNeighbors(int index) {

		auto it = VertexNeighborVerteces.find(index);
		return it->second;
	}

	std::vector<Edge> Board::findVertexEdgesNeighbors(int index) const {
    std::vector<Edge> result;
    auto it = VertexNeighborEdges.find(index);
    result = it->second;
    return result;
	}

	std::map<int, std::vector<Vertex>>Board:: GetVertexNeighborVerteces(){
		return VertexNeighborVerteces;
	}
	std::vector<std::pair<Ground,std::vector<Vertex>>> Board::findVertecesAroundTile(int num)const{
	std::vector<std::pair<Ground,std::vector<Vertex>>> result;

	for(const Tile& t : tiles)
	{
		if(t.getTileNum()==num){
			result.emplace_back(t.getTileGround(), t.getTileVerteces());
		}
	}
	return result;
}

void Board::test() const {
	
	auto iter = VertexNeighborEdges.begin();
	for (int i = 0; i < 10; i++)
		iter++;

	auto vecEdges = iter->second;
	for (const Edge& e : vecEdges)
	{
		for (const Vertex& v : e.getVertex())
		{
			cout << v.getNumber() << " , ";
		}
		cout << endl;
	}
}