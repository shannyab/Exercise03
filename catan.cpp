/*
323858324
shannya08@gmail.com
 */
#include <iostream>
#include <vector>
#include "catan.hpp"
#include <typeinfo> 
#include <ctime> 


void Catan::CurrentPlayer() {
	std::cout<<"current player is:"<<players[playerTurn].getName()<<std::endl;
}

Board Catan::getBoard() const {
	return board;
}
CardsBank& Catan::getNumOfCards(){
	return numofEveryCard;
}
std::vector<std::string>& Catan::getbankOfCards(){
	return bankOfCards;
}
void Catan::printWinner() {
	
	int maxPoints=players[0].getPoints();
    int winnerIndex=0;

    for (int i =1; i < numberPlayers; ++i) {
        if (players[i].getPoints() > maxPoints) {
            maxPoints = players[i].getPoints();
            winnerIndex = i;
        }
	}
	if(maxPoints>=10){
		std::cout<<"The Winner is: "<<players[winnerIndex].getName()<<std::endl;
		return;
	}
	else {
        std::cout << "No winner yet." << std::endl;
    }
}
std::vector<Player>& Catan::getPlayers() {
    return players;
}
void Catan::printVector(){
    for (const auto& item : bankOfCards) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int Catan::getPlayerTurn() const {
	return playerTurn;
}
void Catan::SetPlayerTurn(int v) {
	playerTurn=v;
}

int Catan::playerRollDice() const{
	return players[playerTurn].rollDice();
}

void Catan::endTurn(){
	playerTurn = (++playerTurn) % numberPlayers; 
}
bool Catan::isVertexfree(int indexOfVertex){
	bool isFree = true;
	for ( const auto& player : players) {

		const auto&  playerConstruction= player.getvectorConstructions();
		if(playerConstruction.empty())
		{
			continue;
		}

		for(const auto& pairLocationAndConstruction : playerConstruction){

			if(pairLocationAndConstruction.second.getName() == "Road"){
				continue;
			}
				// else
			if(indexOfVertex == pairLocationAndConstruction.first[0])
			{
				isFree=false;
				break;
			}
		}
	 if (!isFree) {
            break;  // Exit the outer loop if the vertex is found occupied
        }
    }
    return isFree;
}

bool Catan::isEdgeFree(const std::vector<int> indexOfEdge) {
    bool isFree = true;
    for (const auto& player : players) {
        const auto& playerConstructions = player.getvectorConstructions();
        if (playerConstructions.empty())
            continue;

        for (const auto& pairLocationAndConstruction : playerConstructions) {
            if (pairLocationAndConstruction.second.getName() !="Road") {
                continue;  // Skip if the construction is not a Road
            }

            // Check if the edge is occupied
            if (indexOfEdge == pairLocationAndConstruction.first) {
                isFree = false;
                break;
            }
        }

        if (!isFree) {
            break;  // Exit the inner loop if the edge is found occupied
        }
    }

    return isFree;
}
bool Catan::isCurrPEdgeFree(const Edge& edge) {
    bool isFreeEdge = true;
	std::vector<int> indecesOfEdge= edge.getVertexints();
	 auto ConstructionsCurrPlayer = players[playerTurn].getvectorConstructions();
        for (const auto& pairLocationAndConstruction : ConstructionsCurrPlayer) {
			if (pairLocationAndConstruction.second.getName() != "Road") {
                continue;  // Skip if the construction is not a Road
			}
            if ((pairLocationAndConstruction.second.getName() == "Road")&&(indecesOfEdge==pairLocationAndConstruction.first)) {
				isFreeEdge=false;
				break;
			}
		}
		return isFreeEdge;
}
bool Catan::hasCityOrTownNeighbor(std::vector<int> locations){
	 bool hasCityOrTownNeighbor=false;
	  auto ConstructionsCurrPlayer = players[playerTurn].getvectorConstructions();
        for (const auto& pairLocationAndConstruction : ConstructionsCurrPlayer) {
            if (pairLocationAndConstruction.second.getName() == "Road") {
                continue;  
            }

            if ( locations[0] == pairLocationAndConstruction.first[0]||locations[1] == pairLocationAndConstruction.first[0]) {
                hasCityOrTownNeighbor = true;
                break;
            }
        }
	return hasCityOrTownNeighbor;
}
bool Catan:: hasRoadNeighbor(std::vector<int> locations){
	std::vector<Edge> EdgesNeighbors0=board.findVertexEdgesNeighbors(locations[0]);
	for(const auto& edge : EdgesNeighbors0){
		if(edge.getVertexints()!=locations&&(!isCurrPEdgeFree(edge))){
			return true;
		}
	}
	std::vector<Edge> EdgesNeighbors1=board.findVertexEdgesNeighbors(locations[1]);
	for(const auto& edge : EdgesNeighbors1){
		if(edge.getVertexints()!=locations&&(!isCurrPEdgeFree(edge))){
			return true;
		}
	}
	return false;
}
	


bool Catan::canPlaceRoad(std::vector<int> locations) {
	 if (isEdgeFree(locations)) {
        if (hasCityOrTownNeighbor(locations) || hasRoadNeighbor(locations)) {
            return true;
        }
    }
    return false;
}

bool Catan::checkingFreeNeighbors(int indexOfVertex){ 
	bool allNeighborsFree=true;
	std::vector<Vertex>& vertexNeighbors= board.findVertexNeighbors(indexOfVertex);
	for(const auto& vertex : vertexNeighbors){
		if(!isVertexfree(vertex.getNumber())){
			allNeighborsFree=false;
		}
	}
	return allNeighborsFree;
}
void Catan::addResources(Resources& playerResources, const Ground& ground, const int addNumber){
	 switch (ground)
		{
		case Ground::Forest:
			playerResources.setWood(addNumber);
			break;
		case Ground::Hills:
			playerResources.setBrick(addNumber);
			break;
		case Ground::Mountains:
			playerResources.setIron(addNumber);
			break;
		case Ground::Agricultural_Land:
			playerResources.setOats(addNumber);
			break;
		case Ground::Pasture_Land:
			playerResources.setWool(addNumber);
			break;
		default:
			break;
		}
}



void Catan::startResourcesToPlayers(){
	std::vector<Tile> Tiles=board.getTiles();
	for ( auto& player : players) {
         auto locationOfConstructionsP = player.getvectorConstructions();


         for (const auto& intConstruction : locationOfConstructionsP) {
            std::vector<int> constructionVertex = intConstruction.first;
			const Constructions& construction = intConstruction.second;
			if(construction.getName() == "Road"){
				continue;
			}
			for(const Tile& t : Tiles){
				std::vector<Vertex> tileVertices=t.getTileVerteces();
				Ground g= t.getTileGround();
				for(const auto& vertex : tileVertices){
					if(vertex.getNumber()==constructionVertex[0]){
						addResources(player.getResourcesRef(),g,1);
					}
				}
			}
	
	}
}

}

void Catan::checkAndReduceResources() {
    for (auto& player : players) {
        Resources& resources = player.getResourcesRef();
        
        // Calculate the total number of resources
        int totalResources = resources.getNumberOfResources();
        
        // If the total resources are more than 7, reduce them by half
        if (totalResources > 7) {
            int resourcesToReduce = totalResources / 2;
            std::cout << "Player " << player.getName() << " has " << totalResources 
                      << " resources. Reducing by " << resourcesToReduce << "." << std::endl;

            int currentWood = resources.getWood();
            int currentBrick = resources.getBrick();
            int currentWool = resources.getWool();
            int currentOats = resources.getOats();
            int currentIron = resources.getIron();

            // Reduce resources in the order of wood, brick, wool, oats, iron
            if (resourcesToReduce > 0 && currentWood > 0) {
                int woodToReduce = std::min(currentWood, resourcesToReduce);
                resources.setWood(-woodToReduce);
                resourcesToReduce -= woodToReduce;
            }
            if (resourcesToReduce > 0 && currentBrick > 0) {
                int brickToReduce = std::min(currentBrick, resourcesToReduce);
                resources.setBrick(-brickToReduce);
                resourcesToReduce -= brickToReduce;
            }
            if (resourcesToReduce > 0 && currentWool > 0) {
                int woolToReduce = std::min(currentWool, resourcesToReduce);
                resources.setWool(-woolToReduce);
                resourcesToReduce -= woolToReduce;
            }
            if (resourcesToReduce > 0 && currentOats > 0) {
                int oatsToReduce = std::min(currentOats, resourcesToReduce);
                resources.setOats(-oatsToReduce);
                resourcesToReduce -= oatsToReduce;
            }
            if (resourcesToReduce > 0 && currentIron > 0) {
                int ironToReduce = std::min(currentIron, resourcesToReduce);
                resources.setIron(-ironToReduce);
                resourcesToReduce -= ironToReduce;
            }
            std::cout << "His New resources: Wood=" << resources.getWood() << ", Brick=" << resources.getBrick()
                      << ", Wool=" << resources.getWool() << ", Oats=" << resources.getOats() 
                      << ", Iron=" << resources.getIron() << std::endl;
        }
    }
}

void Catan::givingResourcesToPlayers(int num) {
	if(num==7){
		  std::cout << "The rollDice turns out to be the number 7 so we will reduce half of cards of each player that has more than 7"<< std::endl;

		checkAndReduceResources();

		return;
	}
    const auto tilesGroundsVerteces = board.findVertecesAroundTile(num);

    // Iterate over all players
    for ( auto& player : players) {
        // Get the constructions map of the player
         auto locationOfConstructionsP = player.getvectorConstructions();

        // Iterate over each construction location
         for (const auto& intConstruction : locationOfConstructionsP) {
            std::vector<int> constructionVertex = intConstruction.first;
			const Constructions& construction = intConstruction.second;
			if(construction.getName() == "Road"){
				continue;
			}
            // Check if the construction vertex is around the tile
            for (const auto& pair : tilesGroundsVerteces) {
                const auto& vertices = pair.second;
				  const Ground& ground = pair.first;
                for (const auto& vertex : vertices) {
                    if (constructionVertex[0] == vertex.getNumber()) {
                          if (construction.getPointValue()==1) {
                                // Add appropriate resource to player
									addResources(player.getResourcesRef(), ground,1);
						  }
								 if (construction.getPointValue()==2) {
                                // Add appropriate resource to player
                                addResources(player.getResourcesRef(), ground,2);
                            
                        }
                    }
                }
            }
        }
    }
}
bool Catan::buildConstructions(const Constructions& c, std::vector<int> locations){

	if(c.getName() == "Town"){
		const int verLoc = locations[0];
		bool checkA=isVertexfree(verLoc);
		bool checkB = checkingFreeNeighbors(verLoc);

		if((checkA)&&(checkB)){
			players[playerTurn].buildConstrucions(c, locations);
			std::cout<<"Town placed on vertex "<< locations[0]<<" successfully"<<std::endl;
			return true;
		}
		else{
			 throw std::runtime_error("Cannot place a Town on this vertex");
			 return false;
		}
	}
			
	if (c.getName() == "City") {
        auto ConstructionsCurrPlayer = players[playerTurn].getvectorConstructions();
        for (const auto& locationConstruction : ConstructionsCurrPlayer) {
            std::vector<int> constructionInt = locationConstruction.first;
            if ((locationConstruction.second.getName()=="Town")&& (constructionInt == locations)) {
                players[playerTurn].buildConstrucions(c, locations);
                std::cout << "City placed on vertex " << locations[0] << " successfully" << std::endl;
                return true;
            }
        }
        throw std::runtime_error("Could not place city on vertex " + std::to_string(locations[0]));
    }
	 if (c.getName()=="Road" ){
        if (canPlaceRoad(locations)) {
            players[playerTurn].buildConstrucions(c, locations);
            std::cout << "Road placed on Edge {" << locations[0] << "," << locations[1] << "} successfully" << std::endl;
            return true;
        } else {
            throw std::runtime_error("Cannot place Road on this Edge");
        }
    }
	   throw std::runtime_error("Unknown construction type");
    return false;
}
bool Catan::placeTown(const std::vector<int> locations,bool start){
	std::cout<<"trying to place a Town"<<std::endl;
	const int townCost=1;
    if (start||players[playerTurn].canBuyTown()){
		std::cout << "can buy town"<< std::endl;
		Town t;
 		if(buildConstructions(t, locations))
		{
		if(!start){
		 players[playerTurn].getResourcesRef().setWood(-townCost);
        players[playerTurn].getResourcesRef().setBrick(-townCost);
        players[playerTurn].getResourcesRef().setWool(-townCost);
       	players[playerTurn].getResourcesRef().setOats(-townCost);
		players[playerTurn].setPoints(1);
		  return true;
		}
		players[playerTurn].setPoints(1);
		return true;
		}
		else{
		return false;
		}
	}
		 throw std::runtime_error("doesnt have enough resources to buy a town");
		return false;
	}
	
  

bool Catan::placeCity(const std::vector<int> location,bool start){
	std::cout<<"trying to place a city"<<std::endl;
    if (start||players[playerTurn].canBuyCity()==true){
		City c;
 		if(buildConstructions(c, location))
		{
		if(!start){
        players[playerTurn].getResourcesRef().setIron(-3);
       	players[playerTurn].getResourcesRef().setOats(-2);
		players[playerTurn].setPoints(2);
		  return true;
		}
		players[playerTurn].setPoints(2);
		return true;
	}
	else{
    	return false;
		}
 	} 
	 throw std::runtime_error("doesnt have enough resources to buy a city");
	return false;
}
bool Catan::placeRoad(const std::vector<int> location,bool start){
	std::cout<<"trying to place a Road"<<std::endl;
    if (start||players[playerTurn].canBuyRoad()==true){
		Road r;
 		if(buildConstructions(r, location))
		{
		if(!start){
		players[playerTurn].getResourcesRef().setWood(-1);
       	players[playerTurn].getResourcesRef().setBrick(-1);
		return true;
		}
		return true;
		}
		else{
    	return false;
		}

	}
	 throw std::runtime_error("doesnt have enough resources to buy a Road");
	return false;

}
	bool Catan::trade(const std::string PlayerName,Player& otherPlayer, const Ground& FirstResource, const Ground& secondResource, int firstAmount, int secondAmount,bool accepted){
		if(!accepted){
			std::cout<<PlayerName<<"didn't accepted the trade"<<std::endl;
			 throw std::runtime_error("Trade failed: Player did not accept the trade.");
		}
	Resources& currentPlayerResources = players[playerTurn].getResourcesRef();
    Resources& otherPlayerResources = otherPlayer.getResourcesRef();
			if(otherPlayer.hasEnoughResource(secondResource,secondAmount)){
				addResources(otherPlayerResources,secondResource,-secondAmount);
				addResources(currentPlayerResources,secondResource,secondAmount);
				addResources(currentPlayerResources,FirstResource,-firstAmount);
				addResources(otherPlayerResources,FirstResource,firstAmount);
				std::cout<<"the trade was successfull"<<std::endl;
				return true;
			}
			else{
			 throw std::runtime_error("Trade failed: Other player does not have enough resources.");
			}
	}

std::string Catan::buyDevelopmentCard(){
 	std::cout<<"trying to buy a DevelopmentCard"<<std::endl;
    if (players[playerTurn].canBuyDevelopmentCard()){
		std::cout << "can buy DevelopmentCard"<< std::endl;
		std::string developmentCard = bankOfCards.back();
    	bankOfCards.pop_back();
		handleTypeOfCard(developmentCard);
		players[playerTurn].getResourcesRef().setOats(-1);
       	players[playerTurn].getResourcesRef().setIron(-1);
		players[playerTurn].getResourcesRef().setWool(-1);
		return developmentCard;
		}
	 throw std::runtime_error("doesnt have enough resources to buy a card");
		return" ";
	}
void Catan::handleTypeOfCard(std::string type){
	 if (type == "Monopoly") {
        std::cout << "Received a Monopoly card" << std::endl;
    } 
	else if (type == "RoadBuilding") {
        std::cout << "Received a RoadBuilding card" << std::endl;
    }
	 else if (type == "Abir") {
        std::cout << "Received an Abir card" << std::endl;
		std::cout << "Adding an abir to the cards" << std::endl;
		players[playerTurn].getPlayersCardsRef().setAbir(1);
		if(checking3Abirs()){
		std::cout << "Adding the card BiggestArmy to the cards" << std::endl;
		players[playerTurn].getPlayersCardsRef().setBiggestArmy(1);
		std::cout << "Adding 2 points" << std::endl;
		players[playerTurn].setPoints(2);
		}
		else{
			std::cout << "doesnt have 3 Abirs" << std::endl;
		}

     } 
	else if (type == "bonusPoints") {
        std::cout << "Received a bonusPoints card" << std::endl;
		players[playerTurn].getPlayersCardsRef().setbonusPoints(1);
		players[playerTurn].setPoints(1);
		
    } 
	else if (type == "plenty") {
        std::cout << "Received a plenty card" << std::endl;
    } else {
        std::cout << "Unknown card type" << std::endl;
    }
}

void Catan::usingMonopoly(Ground ground){
	Resources& currentPlayerResources = players[playerTurn].getResourcesRef();
	PlayerCards& currentPlayerCards=players[playerTurn].getPlayersCardsRef();
	currentPlayerCards.setMonopoly(-1);
	 switch (ground)
		{
		case Ground::Forest:
		for (auto& player : players) {
        Resources& otherresources = player.getResourcesRef();
		if(otherresources.getWood()>0){
			addResources(currentPlayerResources,ground,1);
			addResources(otherresources,ground,-1);
			}
		}
		break;
		case Ground::Hills:
		for (auto& player : players) {
        Resources& otherresources = player.getResourcesRef();
		if(otherresources.getBrick()>0){
			addResources(currentPlayerResources,ground,1);
			addResources(otherresources,ground,-1);
			}
		}
		break;
		case Ground::Mountains:
		for (auto& player : players) {
        Resources& otherresources = player.getResourcesRef();
		if(otherresources.getIron()>0){
			addResources(currentPlayerResources,ground,1);
			addResources(otherresources,ground,-1);
			}
		}
		break;
		case Ground::Agricultural_Land:
		for (auto& player : players) {
        Resources& otherresources = player.getResourcesRef();
		if(otherresources.getOats()>0){
			addResources(currentPlayerResources,ground,1);
			addResources(otherresources,ground,-1);
			}
		}
		break;
		case Ground::Pasture_Land:
		for (auto& player : players) {
        Resources& otherresources = player.getResourcesRef();
		if(otherresources.getWool()>0){
			addResources(currentPlayerResources,ground,1);
			addResources(otherresources,ground,-1);
			}
		}
		break;
		default:
			break;
		}

}
void Catan::usingPlenty(Ground ground,Ground ground1){
Resources& currentPlayerResources = players[playerTurn].getResourcesRef();
PlayerCards& currentPlayerCards=players[playerTurn].getPlayersCardsRef();
	currentPlayerCards.setPlenty(-1);
	addResources(currentPlayerResources,ground,1);
	addResources(currentPlayerResources,ground1,1);
}
bool Catan::checking3Abirs(){
std::cout<<"checking if has 3 Abirs"<<std::endl;
PlayerCards& currentPlayerCards = players[playerTurn].getPlayersCardsRef();
if(currentPlayerCards.getAbir()==3){
	return true;
}
return false;
}

void Catan::has3Abirs(){
std::cout << "Adding the card BiggestArmy to the cards" << std::endl;
		players[playerTurn].getPlayersCardsRef().setBiggestArmy(1);
		std::cout << "Adding 2 points" << std::endl;
		players[playerTurn].setPoints(2);
}

	
