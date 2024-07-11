/*
323858324
shannya08@gmail.com
 */
#pragma once
#include "board.hpp"
#include "player.hpp"
#include <algorithm> // For std::shuffle
#include <random> // For std::random_device and std::mt19937


class Catan {
private:
	std::vector<Player> players; //	Player p1, p2, p3;
	int numberPlayers;
	int playerTurn;
	Board board;
	CardsBank numofEveryCard;
	std::vector<std::string> bankOfCards;

public:
	Catan(const int numberOfPlayers,std::string name1,std::string name2,std::string name3){ 
		numberPlayers = numberOfPlayers; 
		players.reserve(3);
		players.emplace_back(name1);
		players.emplace_back(name2);
		players.emplace_back(name3);
		playerTurn = 0;
		numberPlayers=numberOfPlayers;
		bankOfCards={"Monopoly","RoadBuilding","Abir","bonusPoints","plenty","RoadBuilding","Abir","Monopoly","Abir","bonusPoints","plenty"};
		 std::random_device rd;
   		 std::mt19937 rng(rd());

    // Shuffle the vector
    std::shuffle(bankOfCards.begin(), bankOfCards.end(), rng);
	}

	~Catan(){
		
	}
	void SetPlayerTurn(int v);
	void CurrentPlayer();
	Board getBoard() const;
	CardsBank& getNumOfCards();
	std::vector<std::string>& getbankOfCards();
	void printWinner();
	void endTurn();
	int getPlayerTurn() const;
	int playerRollDice()const;
	void addResources(Resources& playerResources, const Ground& ground, const int addNumber);
	void givingResourcesToPlayers(int num);
	void startResourcesToPlayers();
	bool isVertexfree(int indexOfVertex);
	bool isEdgeFree(const std::vector<int> indexOfEdge);
	bool checkingFreeNeighbors(int indexOfVertex);
	bool buildConstructions(const Constructions& c, std::vector<int> locations);
	bool canPlaceRoad(std::vector<int> locations);
	bool isCurrPEdgeFree(const Edge& edge);
	bool hasCityOrTownNeighbor(std::vector<int> locations);
	bool hasRoadNeighbor(std::vector<int> locations);
	bool placeTown(const std::vector<int> location, bool start);
	bool placeCity(const std::vector<int> location, bool start);
	bool placeRoad(const std::vector<int> location,bool start);
	std::string buyDevelopmentCard();
	void handleTypeOfCard(std::string type);
	bool trade(const std::string PlayerName,Player& otherPlayer, const Ground& FirstResource, const Ground& secondResource, int firstAmount, int secondAmount,bool accepted);
	std::vector<Player>& getPlayers();
	void checkAndReduceResources();
	void usingMonopoly(Ground ground);
	void usingPlenty(Ground ground,Ground ground1);
	void printVector();
	bool checking3Abirs();
	void has3Abirs();
};