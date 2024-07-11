/*
323858324
shannya08@gmail.com
 */
#pragma once
class Resources {
	int wood, brick, wool, oats, iron;
	int numberOfResources;

public:
	Resources(): wood(0), brick(0), wool(0), oats(0), iron(0), numberOfResources(0) {}
	~Resources(){}

	int getWood() const { return wood; }
	int getBrick() const { return brick; }
	int getWool() const { return wool; }
	int getOats() const { return oats; }
	int getIron() const { return iron; }
	int getNumberOfResources() const { return numberOfResources; }

	void setWood(int addWood) { wood += addWood; updateNumber(); }
	void setBrick(int addBrick) { brick += addBrick; updateNumber(); }
	void setWool(int addWool) { wool += addWool; updateNumber(); }
	void setOats(int addOats) { oats+= addOats; updateNumber(); }
	void setIron(int addIron) { iron += addIron; updateNumber(); }

	void updateNumber() {
		numberOfResources = wood + brick + wool + iron + oats;
	}
}; 
class CardsBank {
	 int Monopoly,RoadBuilding,Plenty, Abir,bonusPoints ,BiggestArmy;

public:
	CardsBank(): Monopoly(2),RoadBuilding(2),Plenty(2), Abir(3),bonusPoints(2),BiggestArmy(1) {}
	~CardsBank(){}

	int getMonopoly() const { return Monopoly; }
	int getRoadBuilding() const { return RoadBuilding; }
	int getPlenty() const { return Plenty; }
	int getAbir() const { return Abir; }
	int getBiggestArmy() const { return BiggestArmy; }
	int getbonusPoints() const { return bonusPoints; }
	void setMonopoly(int addMonopoly) { Monopoly += addMonopoly;}
	void setRoadBuilding(int addRoadBuilding) { RoadBuilding += addRoadBuilding;}
	void setPlenty(int addPlenty) { Plenty += addPlenty;}
	void setAbir(int addAbir) { Abir+= addAbir; }
	void setBiggestArmy(int addBiggestArmy) { BiggestArmy += addBiggestArmy; }
	void setbonusPoints(int addbonusPoints){bonusPoints+=addbonusPoints;}

};
class PlayerCards {
	 int Monopoly,RoadBuilding,Plenty, Abir,bonusPoints ,BiggestArmy;

public:
	PlayerCards(): Monopoly(0),RoadBuilding(0),Plenty(0), Abir(0),bonusPoints(0),BiggestArmy(0) {}
	~PlayerCards(){}

	int getMonopoly() const { return Monopoly; }
	int getRoadBuilding() const { return RoadBuilding; }
	int getPlenty() const { return Plenty; }
	int getAbir() const { return Abir; }
	int getBiggestArmy() const { return BiggestArmy; }
	int getbonusPoints() const { return bonusPoints; }
	void setMonopoly(int addMonopoly) { Monopoly += addMonopoly;}
	void setRoadBuilding(int addRoadBuilding) { RoadBuilding += addRoadBuilding;}
	void setPlenty(int addPlenty) { Plenty += addPlenty;}
	void setAbir(int addAbir) { Abir+= addAbir; }
	void setBiggestArmy(int addBiggestArmy) { BiggestArmy += addBiggestArmy; }
	void setbonusPoints(int addbonusPoints){bonusPoints+=addbonusPoints;}

};




class Constructions {
protected:
	Resources price;
	int pointValue;
	std::string name;

public:
	Constructions() { pointValue = 0; }
	Resources getPrice() const {
		return price;
	}	
	int getPointValue() const {
		return pointValue;
	}
	std::string getName()const{
		return name;
	}
};

class Road : public Constructions {
public:
	Road() {
		price.setWood(1);
		price.setBrick(1);

		pointValue = 0;
		name="Road";
	}
};

class Town : public Constructions {
public:

	Town() {
		price.setWood(1);
		price.setBrick(1);
		price.setWool(1);
		price.setOats(1);

		pointValue = 1;
		name ="Town";
	}
};

class City : public Constructions {
public:

	City() {
		price.setOats(2);
		price.setIron(3);	

		pointValue = 2;
		name="City";
	}
};


class DevelopmentCard {
protected:
	std::string name;
    Resources price;
	int pointValue;

public:
    DevelopmentCard() {
	price.setOats(1);
	price.setIron(1);	
	price.setWool(1);
	pointValue=0;
    }

	Resources getPrice() const {
		return price;
	}	
	int getPointValue() const {
		return pointValue;
	}
	std::string getName()const{
		return name;
	}

};

class Monopoly: public DevelopmentCard {
public:

	Monopoly() {
		name="Monopoly";
	}
};
class RoadsBuilding: public DevelopmentCard {
public:

	 RoadsBuilding() {
		name="RoadsBuilding";
	}
};

class Plenty: public DevelopmentCard {
public:

	 Plenty() {
		name="Plenty";
	}
};

class Abir: public DevelopmentCard {
public:

	 Abir() {
		name="Abir";
	}
};


class BonusPoints: public DevelopmentCard {
public:

	 BonusPoints() {
		name="BonusPoints";
		pointValue=1;
	}
};
class BiggestArmy: public DevelopmentCard {
public:

	BiggestArmy() {
		name="BiggestArmy";
		pointValue=2;
	}
};





