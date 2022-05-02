#include<iostream>
#include<windows.h>
using namespace std;

//function decleration
void shop();
void monster();
void battle(int monsterhealth, char type);

// global variables (BAD)
string items[10] = { "" };
int money = 0;
int turns = 0;
int health = 100;

int main() {

	//local variables
	int room = 1;
	string input;

	cout << "You wake up to a scream and find yourslef in a unfamiliar place. Try to find a way out." << endl;

	do { // beginning of game loop
		cout << "inventory; " << endl;
		for (int i = 0; i < 10; i++)
			cout << items[i] << " | ";
		cout << endl;

		cout << "you have had " << turns << " turns." << endl;
		turns++;
		cout << endl;
		cout << "your health is " << health << endl;
		cout << endl;
		switch (room) {
		case 1:
			cout << "You get up to look around then.. aaahh!" << endl << "an ear peircing scream  comes from an undetectable direction sending shivers down your spine	" << endl;
			cout << "you feel intreged by this Scream" << endl << "there is a path going (north) that you feel like you are being drawn towards towards." << endl;
			cin >> input;
			if (input == "north")
				room = 2;
			else
				cout << " " << endl;

			break;
		case 2:
			monster();
			cout << "you are now in the middle of A forrest" << endl << "you see something reflecting light from one of the sun" << endl;
			cout << "continue down the path up (north) and (pick up) the reflectant object or go back to the start (south)" << endl;
			cin >> input;
			if (input == "north")
				room = 3;
			else if (input == "south")
				room = 1;
			else if (input == "pick up") {
				cout << "you got 3 coins" << endl;
				money += 3;
			}
			else
				cout << "that not valid" << endl;
			break;
		case 3:
			if (money >= 0) {
				cout << "you got 1 coins" << endl;
				money += 1;

			}
			cout << "you have reached the end of the path where you find one more coin" << endl << "you see a house to the west and a Castle to the east" << endl;
			cin >> input;
			if (input == "west")
				if (items[4].compare("key4") != 0)
					cout << " The house is locked, you cant go in. Look for a key." << endl;
				else
					room = 4;

			else if (input == "east")
				room = 5;
			else if (input == "south")
				room = 2;
			else
				cout << "" << endl;
			break;
		case 4:
			if (items[0] != "Dagger") {
				cout << "you got a Dagger" << endl;
				items[0] = "Dagger";

			}
			if (items[6] != "key") {
				cout << "you got a key" << endl;
				items[6] = "key";

			}
			cout << "you enter the House and there is a table that has a shiv and a key" << endl << "you pick them both up" << endl;
			cout << "hmm i wonder what they key goes to" << endl << "the exit is to the east" << endl;
			cin >> input;
			if (input == "east")
				room = 3;
			else
				cout << "" << endl;
			break;
		case 5:
			if (money >= 0) {
				cout << "you got 40 coins" << endl;
				money += 40;

			}
			cout << "A pile of coins is in the middle of the room" << endl << "seems like a trap why would they just be in the middle of the room like that" << endl;
			cout << "You feel a strong urge to grab the coins because its like they are calling your name" << endl << "you hear another loud scream coming from around the corner North. You can go back towards the  front door West" << endl;
			cin >> input;
			if (input == "north")
				room = 6;
			else if (input == "west")
				room = 3;
			else
				cout << "nothing there" << endl;
			break;
		case 6:
			cout << "You find yourself in the courtyard" << endl;
			cout << "you see a small opening on the wall going to a pitch dark room north that you could squeeze trough" << endl << "to the east you see a little creature staring at you, occasionally looking down at the coins you are holding. you can also go back south" << endl;
			cin >> input;
			if (input == "north")
				room = 8;
			else if (input == "east")
				room = 7;
			else if (input == "south")
				room = 5;
			else
				cout << "not a valid choice" << endl;
			break;
		case 7:
			cout << "the creature wispers,i am a treasure goblin and i can trade you items for those coins..." << endl;
			cout << "Would you like to trade with me...? " << endl;
			cout << "You can only go back to big room west" << endl;
			cin >> input;
			if (input == "west")
				room = 6;
			else if (input == "trade")
				shop();
			else
				cout << "not a valid chocie" << endl;
			break;
		case 8:
			if (items[1] == "flashlight") {
				items[4] = "key4";
				cout << "you the got a key to the house" << endl;

			}
			if (items[1] != "flashlight") {
				cout << "you need a flaslight to search in the dark" << endl;

			}
			system("Color 5A");
			cout << "You cant see anything in this room its pitch black" << endl << "you can see light coming from another crack in the wall you can slide through on the other side of the room west, or go back south to courtyard " << endl;
			cin >> input;
			if (input == "west")
				room = 9;
			else if (input == "south")
				room = 6;
			else
				cout << "not a valid choice" << endl;
			break;
		case 9:
			if (money >= 0) {
				cout << "you got 2 coins" << endl;
				money += 2;

			}
			cout << "You are in a small room with a big metal door west" << endl << "Hmm looks like it needs a key" << endl;
			cout << "you can go back east to the dark room" << endl;
			cin >> input;
			if (input == "west")
				if (items[6].compare("key") != 0)
					cout << "Door is locked, cant go in" << endl;
				else
					room = 10;
			else if (input == "east")
				room = 8;
			else
				cout << "not a valid choice" << endl;
			break;
		case 10:
			cout << "as you walk into the room you get a sense of relief as you see a portal leading home" << endl << "finally its over..." << endl;

			cin >> input;
			if (input == "west")
				room = 9;
			else if (input == "north")
				return 0;
			else if (input == "Portal")
				return 0;
			else
				cout << "" << endl;
			break;

		}// end switch
	} while (input != "q"); // end game loop

}

void monster() {
	int num = rand() % 100 + 1;
	if (num < 20) {
		cout << "a psudeodragon flies at you!" << endl;
		battle(30, 's');
	}


	else if (num < 50) {
		cout << "a giant crab crawls up your leg!" << endl;

		battle(10, 'c');
	}
	else if (num < 75) {
		cout << "a big sentinel slashes at you!" << endl;
		battle(50, 'p');
	}
	else
		cout << " nothing appears" << endl;
}
//battle system defenition 
void battle(int monsterhealth, char type) {
	int damage;
	while (monsterhealth > 0 && health > 0) {
		//monsetr attack first
		cout << endl;
		if (type == 'c')
			damage = rand() % 20;
		else if (type == 's')
			damage = rand() % 30;
		else if (type == 'p')
			damage = 40;
		cout << "the creature bites you for " << damage << " damage" << endl;
		health -= damage;
		cout << " you have " << health << " health left" << endl;
		//human atack
		if (items[4] == "Dagger                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ") {
			damage = rand() % 60 + 20;
			cout << "you used your Dagger on the monster" << endl;
		}
		else {
			damage = rand() % 50 + 10;
			cout << "you kicked the creature away" << endl;
		}


		cout << "you hit the monster for " << damage << " damage" << endl;
		monsterhealth -= damage;
		cout << "the creature has " << monsterhealth << " health left" << endl;
	}
	if (monsterhealth <= 0) {
		cout << "you have defeated the monster" << endl;
		cout << endl;
	}
	if (health <= 0) {
		cout << "you died" << endl;
		cout << endl;
	}
}

//funtion defenitions go here
void shop() {
	string input;
	do {
		cout << endl;
		cout << "you have " << money << " coins." << endl;
		cout << endl;
		cout << "i can trade a flashlight for 3 coins, a bandaid for 1 coin, and this mithril necklace for 30 coins.." << endl;
		cout << "press 'q' to quit." << endl;
		cin >> input;
		cout << endl;
		if (input == "flashlight") {
			if (money >= 3) {
				items[1] = "flashlight";
				cout << "you got a flashlight" << endl;
				money -= 3;
			}

		}
		else if (input == "bandaid") {
			if (money >= 1) {
				items[2] = "bandaid";
				cout << "you got a bandaid" << endl;
				money -= 1;
			}

		}
		else if (input == "necklace") {
			if (money >= 6) {
				items[3] = "mithril necklace";
				cout << "you got Mithril Necklace" << endl;
				money -= 30;
			}
		}


	} while (input != "q");
}#include<iostream>
#include<windows.h>
using namespace std;

//function decleration
void shop();
void monster();
void battle(int monsterhealth, char type);

// global variables (BAD)
string items[10] = { "" };
int money = 0;
int turns = 0;
int health = 100;

int main() {

	//local variables
	int room = 1;
	string input;

	cout << "You wake up to a scream and find yourslef in a unfamiliar place. Try to find a way out." << endl;

	do { // beginning of game loop
		cout << "inventory; " << endl;
		for (int i = 0; i < 10; i++)
			cout << items[i] << " | ";
		cout << endl;

		cout << "you have had " << turns << " turns." << endl;
		turns++;
		cout << endl;
		cout << "your health is " << health << endl;
		cout << endl;
		switch (room) {
		case 1:
			cout << "You get up to look around then.. aaahh!" << endl << "an ear peircing scream  comes from an undetectable direction sending shivers down your spine	" << endl;
			cout << "you feel intreged by this Scream" << endl << "there is a path going (north) that you feel like you are being drawn towards towards." << endl;
			cin >> input;
			if (input == "north")
				room = 2;
			else
				cout << " " << endl;

			break;
		case 2:
			monster();
			cout << "you are now in the middle of A forrest" << endl << "you see something reflecting light from one of the sun" << endl;
			cout << "continue down the path up (north) and (pick up) the reflectant object or go back to the start (south)" << endl;
			cin >> input;
			if (input == "north")
				room = 3;
			else if (input == "south")
				room = 1;
			else if (input == "pick up") {
				cout << "you got 3 coins" << endl;
				money += 3;
			}
			else
				cout << "that not valid" << endl;
			break;
		case 3:
			if (money >= 0) {
				cout << "you got 1 coins" << endl;
				money += 1;

			}
			cout << "you have reached the end of the path where you find one more coin" << endl << "you see a house to the west and a Castle to the east" << endl;
			cin >> input;
			if (input == "west")
				if (items[4].compare("key4") != 0)
					cout << " The house is locked, you cant go in. Look for a key." << endl;
				else
					room = 4;

			else if (input == "east")
				room = 5;
			else if (input == "south")
				room = 2;
			else
				cout << "" << endl;
			break;
		case 4:
			if (items[0] != "Dagger") {
				cout << "you got a Dagger" << endl;
				items[0] = "Dagger";

			}
			if (items[6] != "key") {
				cout << "you got a key" << endl;
				items[6] = "key";

			}
			cout << "you enter the House and there is a table that has a shiv and a key" << endl << "you pick them both up" << endl;
			cout << "hmm i wonder what they key goes to" << endl << "the exit is to the east" << endl;
			cin >> input;
			if (input == "east")
				room = 3;
			else
				cout << "" << endl;
			break;
		case 5:
			if (money >= 0) {
				cout << "you got 40 coins" << endl;
				money += 40;

			}
			cout << "A pile of coins is in the middle of the room" << endl << "seems like a trap why would they just be in the middle of the room like that" << endl;
			cout << "You feel a strong urge to grab the coins because its like they are calling your name" << endl << "you hear another loud scream coming from around the corner North. You can go back towards the  front door West" << endl;
			cin >> input;
			if (input == "north")
				room = 6;
			else if (input == "west")
				room = 3;
			else
				cout << "nothing there" << endl;
			break;
		case 6:
			cout << "You find yourself in the courtyard" << endl;
			cout << "you see a small opening on the wall going to a pitch dark room north that you could squeeze trough" << endl << "to the east you see a little creature staring at you, occasionally looking down at the coins you are holding. you can also go back south" << endl;
			cin >> input;
			if (input == "north")
				room = 8;
			else if (input == "east")
				room = 7;
			else if (input == "south")
				room = 5;
			else
				cout << "not a valid choice" << endl;
			break;
		case 7:
			cout << "the creature wispers,i am a treasure goblin and i can trade you items for those coins..." << endl;
			cout << "Would you like to trade with me...? " << endl;
			cout << "You can only go back to big room west" << endl;
			cin >> input;
			if (input == "west")
				room = 6;
			else if (input == "trade")
				shop();
			else
				cout << "not a valid chocie" << endl;
			break;
		case 8:
			if (items[1] == "flashlight") {
				items[4] = "key4";
				cout << "you the got a key to the house" << endl;

			}
			if (items[1] != "flashlight") {
				cout << "you need a flaslight to search in the dark" << endl;

			}
			system("Color 5A");
			cout << "You cant see anything in this room its pitch black" << endl << "you can see light coming from another crack in the wall you can slide through on the other side of the room west, or go back south to courtyard " << endl;
			cin >> input;
			if (input == "west")
				room = 9;
			else if (input == "south")
				room = 6;
			else
				cout << "not a valid choice" << endl;
			break;
		case 9:
			if (money >= 0) {
				cout << "you got 2 coins" << endl;
				money += 2;

			}
			cout << "You are in a small room with a big metal door west" << endl << "Hmm looks like it needs a key" << endl;
			cout << "you can go back east to the dark room" << endl;
			cin >> input;
			if (input == "west")
				if (items[6].compare("key") != 0)
					cout << "Door is locked, cant go in" << endl;
				else
					room = 10;
			else if (input == "east")
				room = 8;
			else
				cout << "not a valid choice" << endl;
			break;
		case 10:
			cout << "as you walk into the room you get a sense of relief as you see a portal leading home" << endl << "finally its over..." << endl;

			cin >> input;
			if (input == "west")
				room = 9;
			else if (input == "north")
				return 0;
			else if (input == "Portal")
				return 0;
			else
				cout << "" << endl;
			break;

		}// end switch
	} while (input != "q"); // end game loop

}

void monster() {
	int num = rand() % 100 + 1;
	if (num < 20) {
		cout << "a psudeodragon flies at you!" << endl;
		battle(30, 's');
	}


	else if (num < 50) {
		cout << "a giant crab crawls up your leg!" << endl;

		battle(10, 'c');
	}
	else if (num < 75) {
		cout << "a big sentinel slashes at you!" << endl;
		battle(50, 'p');
	}
	else
		cout << " nothing appears" << endl;
}
//battle system defenition 
void battle(int monsterhealth, char type) {
	int damage;
	while (monsterhealth > 0 && health > 0) {
		//monsetr attack first
		cout << endl;
		if (type == 'c')
			damage = rand() % 20;
		else if (type == 's')
			damage = rand() % 30;
		else if (type == 'p')
			damage = 40;
		cout << "the creature bites you for " << damage << " damage" << endl;
		health -= damage;
		cout << " you have " << health << " health left" << endl;
		//human atack
		if (items[4] == "Dagger                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ") {
			damage = rand() % 60 + 20;
			cout << "you used your Dagger on the monster" << endl;
		}
		else {
			damage = rand() % 50 + 10;
			cout << "you kicked the creature away" << endl;
		}


		cout << "you hit the monster for " << damage << " damage" << endl;
		monsterhealth -= damage;
		cout << "the creature has " << monsterhealth << " health left" << endl;
	}
	if (monsterhealth <= 0) {
		cout << "you have defeated the monster" << endl;
		cout << endl;
	}
	if (health <= 0) {
		cout << "you died" << endl;
		cout << endl;
	}
}

//funtion defenitions go here
void shop() {
	string input;
	do {
		cout << endl;
		cout << "you have " << money << " coins." << endl;
		cout << endl;
		cout << "i can trade a flashlight for 3 coins, a bandaid for 1 coin, and this mithril necklace for 30 coins.." << endl;
		cout << "press 'q' to quit." << endl;
		cin >> input;
		cout << endl;
		if (input == "flashlight") {
			if (money >= 3) {
				items[1] = "flashlight";
				cout << "you got a flashlight" << endl;
				money -= 3;
			}

		}
		else if (input == "bandaid") {
			if (money >= 1) {
				items[2] = "bandaid";
				cout << "you got a bandaid" << endl;
				money -= 1;
			}

		}
		else if (input == "necklace") {
			if (money >= 6) {
				items[3] = "mithril necklace";
				cout << "you got Mithril Necklace" << endl;
				money -= 30;
			}
		}


	} while (input != "q");
}
