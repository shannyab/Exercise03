/*
323858324
shannya08@gmail.com
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"

TEST_CASE("Board Initialization") {
    Catan catan(3,"Amit","Yossi","Dana");
    Board b=catan.getBoard();
    std::vector<Vertex> verteces=b.getVerteces();
    std::cout<<" printing the Board:"<<std::endl;
    b.printBoard(); 
    CHECK(b.getTiles().size()==19);
    CHECK(b.getEdges().size()==72);
    CHECK(b.getVerteces().size()==54);
    
}
TEST_CASE("Catan players Initialization") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    CHECK(players[0].getName()=="Amit");
     CHECK(players[1].getName()=="Yossi");
     CHECK(players[2].getName()=="Dana");
} 

TEST_CASE("endTurn ") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();

    CHECK(players[catan.getPlayerTurn()].getName()=="Amit");
    catan.endTurn();
     CHECK(players[catan.getPlayerTurn()].getName()=="Yossi");
      catan.endTurn();
     CHECK(players[catan.getPlayerTurn()].getName()=="Dana");
} 
TEST_CASE("Cards Bank Initialization") {
    Catan catan(3,"Amit","Yossi","Dana");
    CardsBank& bank = catan.getNumOfCards();
    CHECK(bank.getBiggestArmy()==1);
    CHECK(bank.getbonusPoints()==2);
    CHECK(bank.getAbir()==3);
    CHECK(bank.getMonopoly()==2);
    CHECK(bank.getPlenty()==2);
     CHECK(bank.getRoadBuilding()==2);
} 
TEST_CASE("isVertexFree") {
    Catan catan(3,"Amit","Yossi","Dana");
    bool isfree=catan.isVertexfree(6);
    CHECK(isfree==true);
    CHECK(catan.placeTown({6},true)==true);
     CHECK(catan.isVertexfree(6)==false);
} 
TEST_CASE("isEdgeFree") {
    Catan catan(3,"Amit","Yossi","Dana");
    bool isfree=catan.isEdgeFree({30,31});
    CHECK(isfree==true);
} 
TEST_CASE("hasCityOrTownNeigbor") {
    Catan catan(3,"Amit","Yossi","Dana");
    CHECK(catan.placeTown({8},true)==true);
     CHECK(catan.hasCityOrTownNeighbor({7,8})==true);//there is a town at 8 so this edge has a town neighbor
    CHECK(catan.hasCityOrTownNeighbor({30,31})==false);//this edge doesnt have a town or a city neighbor
} 
TEST_CASE("hasRoadNeighbor") {
    Catan catan(3,"Amit","Yossi","Dana");
     catan.placeTown({7},true);
    CHECK(catan.placeRoad({7,8},true)==true);
    CHECK(catan.hasRoadNeighbor({30,31})==false);//there isnt a road neighbor
} 
TEST_CASE("addResources") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    Resources& resources1= players[1].getResourcesRef();
    Resources& resources2= players[2].getResourcesRef();
     CHECK(resources0.getWood()==0);
    catan.addResources(resources0,Ground::Forest,3);
    CHECK(resources0.getWood()==3);
    CHECK(resources1.getOats()==0);
    catan.addResources(resources1,Ground::Agricultural_Land,1);
    CHECK(resources1.getOats()==1);
    CHECK(resources2.getIron()==0);
    catan.addResources(resources1,Ground::Mountains,60);
    CHECK(resources1.getIron()==60);
} 


TEST_CASE("givingResourcesToPlayers when the roll res is 7") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    resources0.setBrick(10);
    resources0.setWood(2);
    CHECK(resources0.getNumberOfResources()==12);
    catan.givingResourcesToPlayers(7);
     CHECK(resources0.getWood()==0);
    CHECK(resources0.getBrick()==6);
      CHECK(resources0.getNumberOfResources()==6);
} 

TEST_CASE("PlaceTown sucssesfully") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    catan.CurrentPlayer();
    //updating the resourcce of Amit so he can buy a Town
    resources0.setWood(6);
	resources0.setBrick(1);
	resources0.setWool(3);
	resources0.setOats(1);
    CHECK(catan.placeTown({30}, false)==true);
    //checking if the resources get reduced
     CHECK(resources0.getWood()==5);
    CHECK(resources0.getOats()==0);
    CHECK(resources0.getWool()==2);
    CHECK(resources0.getIron()==0);
    CHECK(resources0.getBrick()==0);
    CHECK(players[0].getPoints()==1);//because he has a town now
} 
TEST_CASE("PlaceTown but hasnt enough resources") {
    Catan catan(3,"Amit","Yossi","Dana");
    catan.CurrentPlayer();
    CHECK_THROWS(catan.placeTown({40}, false));//dont have enough resources to buy a town
} 
 TEST_CASE("trying PlaceTown but cant on this vertex") {
    Catan catan(3,"Amit","Yossi","Dana");
    catan.CurrentPlayer();//Amit
    catan.placeTown({40}, true);
    catan.endTurn();
     catan.CurrentPlayer();//Yossi
    CHECK_THROWS(catan.placeTown({40}, true));
} 
TEST_CASE("PlaceRoad sucssesfully") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    catan.CurrentPlayer();//Amit
    resources0.setWood(6);
	resources0.setBrick(1);
    catan.placeTown({21},true);
    CHECK(catan.placeRoad({21,22},false)==true);
}
TEST_CASE("PlaceCity sucssesfuly ") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources2= players[2].getResourcesRef();
    catan.CurrentPlayer();
    catan.endTurn();
    catan.CurrentPlayer();
    catan.endTurn();
    catan.CurrentPlayer();//Dana
    catan.placeTown({40}, true);
    resources2.setOats(2);
    resources2.setIron(3);
    CHECK(catan.placeCity({40}, false));//can place city
      CHECK(players[2].getPoints()==3);//has Town and City =3 points
} 

TEST_CASE("trying PlaceCity but there isnt a Town on this vertex") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
     Resources& resources0= players[0].getResourcesRef();
    catan.CurrentPlayer();//Amit
    resources0.setOats(2);
	resources0.setIron(3);
    CHECK_THROWS(catan.placeCity({40}, false));//cannot place city 
} 
TEST_CASE("trying PlaceCity but dont have enough resources ") {
    Catan catan(3,"Amit","Yossi","Dana");
    catan.CurrentPlayer();
    CHECK_THROWS(catan.placeCity({40}, false));//cannot place city because dont have enough resources
} 

TEST_CASE("trying PlaceRoad but dont have enough resources ") {
    Catan catan(3,"Amit","Yossi","Dana");
    catan.CurrentPlayer();
    CHECK_THROWS(catan.placeRoad({40,41}, false));//cannot place road because dont have enough resources
} 

TEST_CASE("trade failed ") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    Resources& resources2= players[2].getResourcesRef();
    catan.CurrentPlayer();//Amit
    resources0.setOats(5);
    resources0.setBrick(3);
    resources2.setWool(7);
    CHECK_THROWS(catan.trade("Dana",players[2],Ground::Agricultural_Land,Ground::Forest,1,3,true));//cannot trade because Dana dont have enough wood;
} 
TEST_CASE("trade sucssesfuly ") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    Resources& resources0= players[0].getResourcesRef();
    Resources& resources2= players[2].getResourcesRef();
    catan.CurrentPlayer();//Amit
    resources0.setOats(5);
    resources0.setBrick(3);
    resources2.setWool(7);
     resources2.setWood(7);
    CHECK(catan.trade("Dana",players[2],Ground::Agricultural_Land,Ground::Forest,3,3,true));
    CHECK(resources0.getOats()==2);
    CHECK(resources0.getBrick()==3);
    CHECK(resources2.getWool()==7);
     CHECK(resources2.getWood()==4);
} 
TEST_CASE("cant buy Development card") {
    Catan catan(3,"Amit","Yossi","Dana");
    catan.CurrentPlayer();//Amit
   CHECK_THROWS(catan.buyDevelopmentCard());

} 

TEST_CASE("has3Abirs") {
    Catan catan(3,"Amit","Yossi","Dana");
    std::vector<Player>& players = catan.getPlayers();
    PlayerCards& playerCards0= players[0].getPlayersCardsRef();//Amit
    playerCards0.setAbir(3);
    CHECK(catan.checking3Abirs()==true);
    catan.has3Abirs();
    CHECK(playerCards0.getBiggestArmy()==1);
     CHECK(players[0].getPoints()==2);

} 





   






