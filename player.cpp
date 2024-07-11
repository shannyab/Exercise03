/*
323858324
shannya08@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include <random> 
#include <typeinfo> 


Player::Player(const std::string& playerName) {
	name = playerName;
	points = 0;
}
Player::~Player() {

}

void Player::buildConstrucions(const Constructions& c, const std::vector<int>& indeces) {
    if (c.getName()=="City"){
        // Search for a Town at the same indices
        for (auto it = locationOfConstructions.begin(); it != locationOfConstructions.end(); ++it) {
            std::vector<int> constructionInt = it->first;
            Constructions& construct=it->second;
            if (construct.getName()=="Town" && (constructionInt == indeces)) {
                locationOfConstructions.erase(it);  // Remove the Town
                locationOfConstructions.emplace_back(std::make_pair(indeces, c));  // Add the City
                return;  // Exit the function after replacement
            }
        }
    } 
	else {
        locationOfConstructions.emplace_back(std::make_pair(indeces, c)); // Add other constructions (non-City)
    }
}


int Player::rollDice()const {
	// random twice from 1 to 6
int random1=(rand()%6)+1;
int random2=(rand()%6)+1;
int num=random1+random2;
return num;
}



void Player::printPoints() {
	std::cout<<"the number of points is:"<<points<<std::endl;

}


int Player::getNumberOfResources() const {
	return resources.getNumberOfResources();
}
PlayerCards& Player::getPlayersCardsRef() {
	return playerCards;
}

int Player::getPoints() const {
	return points;
}
void Player::setPoints(int addPoints) {
	points += addPoints;
}
std::vector<std::pair<std::vector<int>,Constructions>> Player::getvectorConstructions()const{
		return locationOfConstructions;
	}
Resources Player::getResources()const{
		return resources;
}
Resources& Player::getResourcesRef(){
		return resources;
}

std::string Player::getName(){
		return name;
}
bool Player::canBuyDevelopmentCard(){
const int townCost = 1; 
    if (resources.getIron() >= townCost &&
        resources.getWool() >= townCost &&
        resources.getOats() >= townCost){
			return true;
		}
		return false;

}
bool Player::canBuyTown(){
	const int townCost = 1; 
    if (resources.getWood() >= townCost &&
        resources.getBrick() >= townCost &&
        resources.getWool() >= townCost &&
        resources.getOats() >= townCost){
			return true;
		}
		return false;

}
bool Player::canBuyCity(){
    if (resources.getOats() >= 2 &&
        resources.getIron() >= 3){
			return true;
		}
		return false;

}
bool Player::canBuyRoad(){
	if (resources.getWood() >= 1 &&
        resources.getBrick() >= 1){
			return true;
		}
		return false;

}
bool Player::hasEnoughResource(const Ground& resource, int amount){
    switch (resource) {
        case Ground::Forest:
            return resources.getWood() >= amount;  
        case Ground::Hills:
            return resources.getBrick() >= amount; 
        case Ground::Mountains:
            return resources.getIron() >= amount;  
        case Ground::Agricultural_Land:
            return resources.getOats() >= amount;  
        case Ground::Pasture_Land:
            return resources.getWool() >= amount;  
        default:
            return false;  
    }
}

	