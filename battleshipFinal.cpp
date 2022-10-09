/*Battleship Final, battleshipFinal.cpp
Programmer: Ray, Stephen
Course: CSC160-500 Computer Science 1
Submission Date: [3/09/2021]
Title screen function for battleship game.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

//======================================================================================================
// GLOBAL VARIABLES
//======================================================================================================

// Declaring constant variables:
// Populate the board with S to signify the presence of a ship
const char shipSymbol = 'S';
// X character signifies that a has made a hit on an enemy ship
const char fireHit = 'X';
// O character signifies that a player has missed
const char fireMiss = 'O';
// * symbol signifies open water
const char openWater = '*';
// constant integer for Columns and Rows of the 10X10 board array
const int MAX_COL = 10;
const int MAX_ROW = 10;
// Const int for the five ship types of this game
const int numShipClasses = 5;
// Declare bool playGame and initialize to false
// This variable will allow the program to keep track of when to start gameplay after ship placement
bool playGame = false;

//======================================================================================================
// OBJECT CLASSES
//======================================================================================================

// Declare class Board
class Board
{
    // The main board, boardArray1 is under public access for all functions
    public:
    char boardArray1[MAX_ROW][MAX_COL];

}user[3];// Declaring array user of size 3 to keep track of each players board

// Declare class GridAxis and provide public access to the integers xCoord and yCoord
// xCoord and yCoord variables hold specific grid coordinates
class GridAxis
{
    public:
    int xCoord;
    int yCoord;
};

// Declare class Ships
class Ships
{
    public:
    // variable shipSize holds how many grid points a ship occupies
    int shipSize;
    // variable shipClass holds the type of ship (submarine, carrier, etc.)
    string shipClass;
    // Exact grid coordinates of where a ship will be placed on the board
    GridAxis gridPosition[5];
    // bool hitMarker returns true or false depending on hit
    bool hitMarker[5];
}shipManip[numShipClasses];

// Enumerated data type shipDirection with the enumerators vertical and horizontal
enum shipDirection {vertical, horizontal};

// Declare class ShipPlacement
class ShipPlacement
{
    public:
    Ships shipID;
    shipDirection shipOrientation;
};

//======================================================================================================
// FUNCTION PROTOTYPES
//======================================================================================================

// Function Prototypes:
void titleScreen();
int menuChoice();
void gameManual();
void gameGrid(int);
void establishShips();
ShipPlacement UserInputShipPlacement();
void getAttackData(int&,int&,int);
int victoryStatus(int);
void cleanBoardArray();
void exitScreen();
void victoryScreen(int);

//======================================================================================================
// CODE BODY
//======================================================================================================

int main()
{
    // Call titleScreen() function to display title
    titleScreen();

    // Menu Selection
    int playTime = menuChoice();

    if (playTime == 2)
    {
        gameManual();
    }
    else if (playTime == 0)
    {
        exitScreen();
    }
    else if (playTime == 1)
    {
        // Calling establishShips and cleanBoardArray functions to prepare the game for a fresh start
        establishShips();
        cleanBoardArray();

        // For loop cycles through players 1 and 2 to allow them to place their ships on their boards.
        for (int player = 1; player < 3; ++player)
        {
            //For loop cycles through each of the ship types (aircraft carrier, battleship, cruiser, submarine, and destroyer)
            for (int currentShip = 0; currentShip < numShipClasses; ++currentShip)
            {
                //Clear the console screen and display the player's board
                system("cls");
                gameGrid(player);

                //Display current player
                cout << "\n"
                     << "\t     SHIP DEPLOYMENT PHASE\n"
                     << "\t     ---------------------\n";
                cout << "\t\tPlayer " << player << " Turn: \n"
                     << "\t\t--------------\n\n";

                // Provide user with information on the current ship being placed
                cout << "Place your " << shipManip[currentShip].shipClass << " with a ship size of " << shipManip[currentShip].shipSize  << " units.\n"
                     << "Your ship will be centered around the coordinate you select.\n";

                //Get input from user and loop until good data is returned
                ShipPlacement locData;
                locData = UserInputShipPlacement();

                //Get ship size and class data from the current ship, assign to locData
                locData.shipID.shipSize = shipManip[currentShip].shipSize;
                locData.shipID.shipClass = shipManip[currentShip].shipClass;

                //This populates the boardArray1 with the user selected grid coordinate as the center of the ship
                user[player].boardArray1[locData.shipID.gridPosition[0].xCoord][locData.shipID.gridPosition[0].yCoord] = shipSymbol;

                // If the current ship being placed is an aircraft carrier or battleship
                if (locData.shipID.shipSize == 5)
                {
                    // This for loop segment builds the right half and bottom half of the ship being placed
                    for (int index = 1; index < 3; index++)
                    {
                        if (locData.shipOrientation == horizontal)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord + 1;
                        }
                        if (locData.shipOrientation == vertical)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord + 1;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord;
                        }
                        //Populate the player's board with the rest of the ship
                        user[player].boardArray1[locData.shipID.gridPosition[index].xCoord][locData.shipID.gridPosition[index].yCoord] = shipSymbol;
                    }
                    // This for loop segment builds the left half and top half of the ship being placed
                    for (int index = 1; index < 3; index++)
                    {
                        if (locData.shipOrientation == horizontal)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord - 1;
                        }
                        if (locData.shipOrientation == vertical)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord - 1;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord;
                        }
                        //Populate the player's board with the rest of the ship
                        user[player].boardArray1[locData.shipID.gridPosition[index].xCoord][locData.shipID.gridPosition[index].yCoord] = shipSymbol;
                    }
                }
                // If the current ship being placed is a destroyer, escort, or submarine
                else if (locData.shipID.shipSize == 3)
                {
                    // This for loop builds the right half and bottom half of the ship being placed
                    for (int index = 1; index < 2; index++)
                    {
                        if (locData.shipOrientation == horizontal)
                        {
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord + 1;
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord;
                        }
                        if (locData.shipOrientation == vertical)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord + 1;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord;
                        }
                        //Populate the player's board with the rest of the ship
                        user[player].boardArray1[locData.shipID.gridPosition[index].xCoord][locData.shipID.gridPosition[index].yCoord] = shipSymbol;
                    }
                    // This for loop builds the left half and top half of the ship being placed
                    for (int index = 1; index < 2; index++)
                    {
                        if (locData.shipOrientation == horizontal)
                        {
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord - 1;
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord;
                        }
                        if (locData.shipOrientation == vertical)
                        {
                            locData.shipID.gridPosition[index].yCoord = locData.shipID.gridPosition[index - 1].yCoord - 1;
                            locData.shipID.gridPosition[index].xCoord = locData.shipID.gridPosition[index - 1].xCoord;
                        }
                        //Populate the player's board with the rest of the ship
                        user[player].boardArray1[locData.shipID.gridPosition[index].xCoord][locData.shipID.gridPosition[index].yCoord] = shipSymbol;
                    }
                }
            }
        }
        // Ship Deployment Phase has ended and the players will begin firing at each other
        playGame = true;
        int nowPlayer = 1;
        do
        {
            // Display the opponent's board while making an attack, this will allow the player to see where their hits and misses are
            int opponent;
            if (nowPlayer == 1) opponent = 2;
            if (nowPlayer == 2) opponent = 1;
            system("cls");
            gameGrid(opponent);

            //Call getAttackData to receive player input for fire coordinates
            int x,y;
            getAttackData(x,y,nowPlayer);

            //Check the opponent board and assign either a hit or miss for the attack
            if (user[opponent].boardArray1[x][y] == shipSymbol) user[opponent].boardArray1[x][y] = fireHit;
            if (user[opponent].boardArray1[x][y] == openWater) user[opponent].boardArray1[x][y] = fireMiss;

            // After the attack, check to see if all of the opponent's ships have been sunk
            int aWin = victoryStatus(opponent);
            if (aWin != 0)
            {
                playGame = false;
                break;
            }
            //Switch nowPlayer and oppoonent using ternary operator
            nowPlayer = (nowPlayer == 1) ? 2 : 1;

        } while (playGame); // Continue the do-while loop as long as both players still have ships on the board

        victoryScreen(nowPlayer);
    }
	return 0;
}

void titleScreen()
{
   cout << "****************************************************************************************\n"
        << "****************************************************************************************\n"
        << "**  ||||||   |||||  |||||||| |||||||| ||      |||||||  ||||||| ||   || || ||||||      **\n"
        << "**  ||   || ||   ||    ||       ||    ||      ||      ||       ||   || || ||   ||     **\n"
        << "**  ||||||  |||||||    ||       ||    ||      |||||    |||||   ||||||| || ||||||      **\n"
        << "**  ||   || ||   ||    ||       ||    ||      ||           ||  ||   || || ||          **\n"
        << "**  ||||||  ||   ||    ||       ||    ||||||| ||||||| |||||||  ||   || || ||          **\n"
        << "****************************************************************************************\n"
        << "****************************************************************************************\n";
}

int menuChoice()
{
    int playerEntry;

    cout << "Welcome to the BATTLESHIP experience!\n"
         << "Make your selection now.\n"
         << "Press 1 to play the game\n"
         << "Press 2 for the game manual\n"
         << "Press 0 to exit\n";
    cin >> playerEntry;
    while (cin.fail() || playerEntry != 1 && playerEntry != 0 && playerEntry != 2)
    {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "You have made an invalid selection.\n"
              << "Press the number one to play the game, press the number two for the game manual or press the number zero to exit.\n";
          cin >> playerEntry;
    }
    return playerEntry;
}

// Game Manual function displays detailed instructions and description of the game
void gameManual()
{
    system("cls");

    cout <<   "#####                                                                              \n"
         << "#     #    ##    #    #  ######      ##   ##    ##    #    #  #    #    ##    #      \n"
         << "#         #  #   ##  ##  #           # # # #   #  #   ##   #  #    #   #  #   #      \n"
         << "#  ####  #    #  # ## #  #####       #  #  #  #    #  # #  #  #    #  #    #  #      \n"
         << "#     #  ######  #    #  #           #     #  ######  #  # #  #    #  ######  #      \n"
         << "#     #  #    #  #    #  #           #     #  #    #  #   ##  #    #  #    #  #      \n"
         << " #####   #    #  #    #  ######      #     #  #    #  #    #   ####   #    #  ###### \n"
         << "************************************************************************************\n";

    cout << "Battleship is a two player game in which the objective is to hit and sink all of the opposing players ships.\n"
         << "Each player has access to two game boards.  The first game board is a target grid that helps the player keep\ntrack of hits and misses against their opponents ships."
         << "  The second board is a layout grid that allows players to select the grid locations of their ships at the start of the game.\n"
         << "Player turns will alternate until one player loses all of their ships.\n"
         << "************************************************************************************\n\n\n";

    cout << "\t\t\t\t***********************\n"
         << "\t\t\t\t*SETTING UP YOUR SHIPS*\n"
         << "\t\t\t\t***********************\n"
         << "\tEach player will have five ships to deploy on their main game board.\n"
         << "\tThe ships occupy a consecutive number of spaces either horizontally or vertically.\n"
         << "\tShips cannot be deployed diagonally and cannot overlap each other.\n";
}

void gameGrid(int setPlayer)
{//Draws the board for a player (thisPlayer)
	cout << "\tTACTICAL BOARD\n"
         << "\t   PLAYER " << setPlayer << endl;
	cout << "--------------------------------\n";
	cout << "  | ";

    for (char a = 'A'; a <= 'J'; a++)//This is the top of the game board A-J
    {
        if (a < 'J')
        {
           cout << a;
           cout << "  ";
        }
        else
        {
            cout << a;
        }
    }

    cout << "\n";
    cout << "--------------------------------";
    cout << "\n";

	//Loop through each grid point and display to console
	for (int h = 1; h <= MAX_ROW; ++h)
    {
		for (int w = 0; w < MAX_COL; ++w)
        {
			//If this is the FIRST (left) grid point, number the grid first
			if (w == 0)
            {
                if (h < 10)
                {
                    cout << " " << h << "|";
                }
                else if (h >= 10)
                {
                    cout << h << "|";
                }
            }
			//If h was 1 character long, add an extra space to keep numbers lined up
            if (w < 10 && w == 0) cout << " ";
			//Display contents of this grid (if game isn't running yet, we are placing ships
			//so display the ships
			if (playGame == false) cout << user[setPlayer].boardArray1[w][h] << "  ";
			//Don't show ships, BUT show damage if it's hit
			if (playGame == true && user[setPlayer].boardArray1[w][h] != shipSymbol)
			{cout << user[setPlayer].boardArray1[w][h] << "  ";}
			else if (playGame == true && user[setPlayer].boardArray1[w][h] == shipSymbol)
			{cout << openWater << "  ";}
			//If we have reached the border.. line feed
			if (w == MAX_ROW - 1) cout << "\n";
		}
	}
}

// victoryStatus() function checks the opponent's board for any remaining ships.  If there are no ships left on an opponent's board, the game is concluded
int victoryStatus(int opponent)
{
	int gameOverStatus = 1;
	// Cycle through the opponents board with a for loop
	for (int l = 0; l < MAX_ROW; l++)
    {
        for (int n = 0; n < MAX_COL; n++)
        {
			// gameOverStatus is set to 0 if there are still shipSymbols on the opponent's board
			if (user[opponent].boardArray1[l][n] = shipSymbol)
			{
				gameOverStatus = 0;
				return gameOverStatus;
			}
        }
    }
	// Return gameOverStatus of 1 if there were no shipSymbols remaining on the opponents board
	return gameOverStatus;
}

void getAttackData(int& x, int& y, int nowPlayer)
{
    int charCounter = 0;
    char boardLetter;

	cout << "\nPlayer " << nowPlayer << ", Input grid coordinates to fire upon.\n";
	cout << "Enter the column letter of the grid coordinate.\n";
	cin >> boardLetter;

	// Input validation for boardLetter variable
	while(cin.fail() || boardLetter < 'A' || boardLetter > 'J')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter a capitalized letter between A and J.\n"
             << "Please reenter a valid column letter of the grid coordinate.\n";
        cin >> boardLetter;
    }

	for (char a = 'A'; a <= 'J'; a++)
    {
        if (boardLetter > a)
        {
            charCounter++;
        }
    }

    x = charCounter;
    cout << "Enter the row number of the grid coordinate.\n";
    cin >> y;

    // Input validation for y variable
	while(cin.fail() || y < 1 || y > 10)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter a row number between 1 and 10.\n"
             << "Please reenter a valid row number.\n";
        cin >> y;
    }
}

ShipPlacement UserInputShipPlacement()
{
    char boardLetter;
    int charCounter = 0;

	int d, x, y;

	ShipPlacement val;

	//Get 3 integers from user
	cout << "\nEnter the vertical or horizontal direction of the ship.\n"
         << "Enter 0 for vertical alignment and 1 for horizontal alignment.\n";
	cin >> d;

	// Input validation for d variable
	while(cin.fail() || d != 0 && d != 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter 0 or 1 for the direction of the ship.\n"
             << "Please reenter a valid direction. Enter 0 for vertical alignment and 1 for horizontal alignment.\n";
        cin >> d;
    }

	cout << "Enter the column letter of the grid coordinate.\n";
	cin >> boardLetter;

	// Input validation for boardLetter variable
	while(cin.fail() || boardLetter < 'A' || boardLetter > 'J')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter a capitalized letter between A and J.\n"
             << "Please reenter a valid column letter of the grid coordinate.\n";
        cin >> boardLetter;
    }

	for (char a = 'A'; a <= 'J'; a++)
    {
        if (boardLetter > a)
        {
            charCounter++;
        }
    }

    x = charCounter;
    cout << "Enter the row number of the grid coordinate.\n";
    cin >> y;

    // Input validation for d variable
	while(cin.fail() || y < 1 || y > 10)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter a row number between 1 and 10.\n"
             << "Please reenter a valid row number.\n";
        cin >> y;
    }
    // Storing data
    // Using shipDirection enumeration for horizontal or vertical
	val.shipOrientation = (shipDirection)d;
	// Assigning val.shipID.gridPosition[].xCoord/yCoord to x and y input respectively
	val.shipID.gridPosition[0].xCoord = x;
	val.shipID.gridPosition[0].yCoord = y;
	// Return val once user input has been assigned
	return val;
}

// establishShips() function assigns a size and name to each ship in the game
void establishShips()
{
	// Establish the names and sizes of each ship in the game using shipManip[numShipClasses(5)]
	shipManip[0].shipClass = "Aircraft Carrier";
	shipManip[1].shipClass = "Battleship";
	shipManip[2].shipClass = "Cruiser";
	shipManip[3].shipClass = "Submarine";
	shipManip[4].shipClass = "Destroyer";
	// Aircraft Carrier and Battleship are a size of 5 units
	shipManip[0].shipSize = 5;
	shipManip[1].shipSize = 5;
	// Cruiser, Sub, and Destroyer are a size of 3 units
	shipManip[2].shipSize = 3;
	shipManip[3].shipSize = 3;
	shipManip[4].shipSize = 3;
}

void cleanBoardArray()
{
	//For loop used to cycle through each player
	for (int index = 1; index < 3; index++)
	{
		//Cycle through the boardArray1 and populate it with openWater * symbol
		for (int l = 0; l < MAX_ROW; l++)
        {
            for (int n = 0; n < MAX_COL; n++)
            {
                user[index].boardArray1[l][n] = openWater;
            }
        }
	}
}

// Display exit message
void exitScreen()
{
    cout << "Goodbye!\n";
}

void victoryScreen(int nowPlayer)
{
    //Clear screen to display victory message
    system("cls");
    cout << "PLAYER " << nowPlayer << " IS VICTORIOUS!\n";
}
