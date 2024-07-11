/*
323858324
shannya08@gmail.com
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"

using namespace std;

int main()
{
    std::cout<<"starting the game!!!! good luck"<<std::endl;

    Catan catan(3,"Amit","Yossi","Dana");
    
    Board b=catan.getBoard();

    std::cout << std::endl;

    std::cout<<" printing the Board:"<<std::endl;
    b.printBoard(); 
    std::cout<<"first round  of every player placing one Town and one Road"<<std::endl;
    std::cout << std::endl;
    //starting player-Amit
    catan.CurrentPlayer();// should print the name of the starting player, Amit.
     std::vector<Player>& players = catan.getPlayers();

	catan.placeTown({4},true);//true because its the starting of the game

    catan.placeRoad({4,5},true);//true because its the starting of the game
    
    catan.endTurn();//moving to the next player Yossi
     std::cout << std::endl;
    //second player-Yossi
     catan.CurrentPlayer();// should print the name of the current player, Yossi.

     catan.placeTown({21},true);

    catan.placeRoad({21,22},true);

    catan.endTurn();//moving to the next player
    std::cout << std::endl;
    //third player-Dana
     catan.CurrentPlayer();// should print the name of the current player, Dana.

    catan.placeTown({35},true);

    catan.placeRoad({35,36},true);

    catan.endTurn();

    std::cout<<"second round of every player placing one Town and one Road"<<std::endl;
    //first player-Amit
    catan.CurrentPlayer();

    catan.placeTown({49},true);

    catan.placeRoad({49,50},true);

    catan.endTurn();
     std::cout << std::endl;
    //second player-Yossi
    catan.CurrentPlayer();

    catan.placeTown({39},true);

    catan.placeRoad({39,40},true);

    catan.endTurn();
     std::cout << std::endl;
    //third player-Dana
    catan.CurrentPlayer();
       try{
        catan.placeTown({49},true); // Dana tries to place a town but this vertex is already taken
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    catan.placeTown({32},true);

    catan.placeRoad({32,31},true);

    catan.endTurn(); 
     std::cout<<""<<std::endl;
     std::cout<<"Amit resources"<<std::endl;
    std::cout<<"Brick"<<players[0].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[0].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[0].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[0].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[0].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Yossi resources"<<std::endl;
    std::cout<<"Brick"<<players[1].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[1].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[1].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[1].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[1].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
     std::cout<<"Dana resources"<<std::endl;
    std::cout<<"Brick"<<players[2].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[2].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[2].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[2].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[2].getResourcesRef().getIron()<<std::endl;
     std::cout<<""<<std::endl;


    
    std::cout<<"Giving Resources to players for the first time"<<std::endl;

    catan.startResourcesToPlayers(); 
    std::cout<<"Amit resources"<<std::endl;
    std::cout<<"Brick"<<players[0].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[0].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[0].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[0].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[0].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Yossi resources"<<std::endl;
    std::cout<<"Brick"<<players[1].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[1].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[1].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[1].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[1].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
     std::cout<<"Dana resources"<<std::endl;
    std::cout<<"Brick"<<players[2].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[2].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[2].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[2].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[2].getResourcesRef().getIron()<<std::endl;
     std::cout<<""<<std::endl;



    //first player-Turn-Amit
    catan.CurrentPlayer();
    int roll1=catan.playerRollDice();
     std::cout<<"the result of the roll is: "<< roll1<<std::endl;
      std::cout<<""<<std::endl;
    catan.givingResourcesToPlayers(roll1);
       try{
        catan.placeTown({50},false); // Amit tries to place a town but he doesnt have enough resources
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    catan.endTurn();

    //second player-Yossi
    catan.CurrentPlayer();
    int roll2=catan.playerRollDice();
     std::cout<<"the result of the roll is: "<< roll2<<std::endl;
 std::cout<<"Giving Resources to players "<<std::endl;
    catan.givingResourcesToPlayers(roll2);

       std::cout<<"Amit resources"<<std::endl;
    std::cout<<"Brick"<<players[0].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[0].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[0].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[0].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[0].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Yossi resources"<<std::endl;
    std::cout<<"Brick"<<players[1].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[1].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[1].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[1].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[1].getResourcesRef().getIron()<<std::endl;
    std::cout<<""<<std::endl;
     std::cout<<"Dana resources"<<std::endl;
    std::cout<<"Brick"<<players[2].getResourcesRef().getBrick()<<std::endl;
    std::cout<<"wool"<<players[2].getResourcesRef().getWool()<<std::endl;
    std::cout<<"wood"<<players[2].getResourcesRef().getWood()<<std::endl;
    std::cout<<"oats"<<players[2].getResourcesRef().getOats()<<std::endl;
    std::cout<<"Iron"<<players[2].getResourcesRef().getIron()<<std::endl;
     std::cout<<""<<std::endl;



   try{
       catan.trade("Dana",players[2],Ground::Pasture_Land,Ground::Forest,1,3,true);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
     catan.trade("Dana",players[2],Ground::Pasture_Land,Ground::Forest,1,1,true);
    std::cout<<"Yossi "<<std::endl;
    std::cout<<"wood"<<players[1].getResourcesRef().getWood()<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Dana"<<std::endl;
    std::cout<<"wool"<<players[2].getResourcesRef().getWool()<<std::endl;

     std::cout<<""<<std::endl;
      try{
        catan.placeRoad({32,31},false);//trying to  place on an  not Free Edge  
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

   try{
        catan.placeRoad({40,41},false); 
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
catan.endTurn();
//third player-Dana
catan.CurrentPlayer();
int roll3= catan.playerRollDice();
std::cout<<"the result of the roll is: "<< roll2<<std::endl;
 std::cout<<"Giving Resources to players "<<std::endl;
    catan.givingResourcesToPlayers(roll3);

std::string type =catan.buyDevelopmentCard();
 if (type == "Monopoly") {
    std::cout << "using a Monopoly card" << std::endl;
		catan.usingMonopoly(Ground::Agricultural_Land);
    } 
	else if (type == "RoadBuilding") {
    try{
       catan.placeRoad({35,34},true);
       catan.placeRoad({30,31},true);
    }
  catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    }
    else if (type == "plenty") {
    std::cout << "using a plenty card" << std::endl;
        catan.usingPlenty(Ground::Mountains,Ground::Forest);

    }
	 else {
        std::cout << " " << std::endl;
    }
catan.endTurn();
std::cout<<"The number of points of Amit is:  "<<players[0].getPoints()<<std::endl;
std::cout<<"The number of points of Yossi is:  "<<players[1].getPoints()<<std::endl;
std::cout<<"The number of points of Dana is:  "<<players[2].getPoints()<<std::endl;
catan.printWinner();//Should print No winner because no player reached 10 points.
}