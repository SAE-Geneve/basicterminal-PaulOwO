#include <string>
#include <iostream>
//je n'ai pas fais la fonctionalité exit car je viens de voir que j'ai déjà dépasser les 100 lignes.
enum class State
{
	START,
	WAKE_UP,
	DIE,
	FOUND_LAMP,
	ESCAPE,
	WIN,
};

State my_state = State::WAKE_UP;

void win()
{
	std::cout
		<< "Woah you really did it! You get out of the room and run in the forest\n"
		<< "You WIN";
}

void escape()
{
	std::cout
		<< "The <Thing> calm down a litlle.\n"
		<< "When you saw a glimps of the room you saw where a door and a window was.\n"
		<< "What will you do now?\n";
	std::cout
		<< "1: You take a run for the door.\n"
		<< "2: You walk slowly at the door.\n"
		<< "3:You walk slowly at the door\n"
		<< "4:You take a run for the door\n";
	std::string value;
	std::cout << "\n>";
	std::getline(std::cin, value);

	if ((value == "1") || (value == "3") || (value == "4")) {
		my_state = State::DIE;
	}
	else if (value == "2") {
		my_state = State::WIN;
	}
	else if (value > "4") {
		my_state = State::ESCAPE;
	}
}


void found_lamp()
{
	std::cout
		<< "What a coincidence, you find a flashlight!\n"
		<< "As you light the flashlight you here a strange growlling.\n"
		<< "What will you do now?\n";
	std::cout
		<< "1: You shine your flashlight at the sound.\n"
		<< "2: You turn off your flashlight.\n"
		<< "3: You hide under the bed\n";
	std::string value;
	std::cout << "\n>";
	std::getline(std::cin, value);

	if ((value == "1") || (value == "3")) {
		my_state = State::DIE;
	}
	else if (value == "2") {
		my_state = State::ESCAPE;
	}
	else if (value > "3") {
		my_state = State::FOUND_LAMP;
	}
}

void wake_up()
{
	std::cout
		<< "You woke up in a dark room, on a bed, with a huge head heck\n"
		<< "What will you do?\n";
	std::cout
		<< "1: You blindly search something on the bed to help you.\n"
		<< "2: You get of the bed and search the room.\n"
		<< "3: You stay in bed...waiting...\n";
	std::string value;
	std::cout << "\n>";
	std::cin >> value;
	if ((value == "3") || (value == "2")) {
		my_state = State::DIE;
	}
	else if (value == "1") {
		my_state = State::FOUND_LAMP;
	}
	else if (value > "3") {
		my_state = State::WAKE_UP;
	}
}

int main()
{
	std::cout
		<< "You can exit at any point typing <exit>\n"
		<< "Press any buton to continue";
	std::cout << "\n>";
	std::string start;
	std::cin >> start;

	bool playing = true;
	while (playing)
	{                   //Exit//


		switch (my_state)
		{
		case State::DIE:
			playing = false;
			break;
		case State::WAKE_UP:
			wake_up();
			break;
		case State::FOUND_LAMP:
			found_lamp();
			break;
		case State::ESCAPE:
			escape();
			break;
		case State::WIN:
			win();
			break;
		}
	}
	std::cout << "Game Over";
}







	


