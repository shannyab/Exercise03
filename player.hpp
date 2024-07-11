
/*
323858324
shannya08@gmail.com
 */
#pragma once
#include "board.hpp"
#include "CTools.hpp"

class Player {
	std::string name;
	Resources resources;
	int points;
	std::vector<std::pair<std::vector<int>,Constructions>>locationOfConstructions;
	PlayerCards playerCards;

public:
	Player(const std::string& playerName);
	~Player();
	bool canBuyTown();
	bool canBuyCity();
	bool canBuyRoad();
	bool canBuyDevelopmentCard();
	int rollDice()const;
	void printPoints();
	PlayerCards& getPlayersCardsRef();
	int getNumberOfResources() const;
	int getPoints() const;
	void setPoints(int addPoints);
	std::vector<std::pair<std::vector<int>,Constructions>> getvectorConstructions()const;
	Resources getResources()const;
	Resources& getResourcesRef();
	std::string getName();
	void buildConstrucions(const Constructions& c, const std::vector<int> &indeces);
	bool hasEnoughResource(const Ground& resource, int amount);
};