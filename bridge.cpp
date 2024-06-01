#include <iostream>
#include <ctime> //for generate random number
#include <chrono> //for pause between iteration
#include <thread> //for pause function
#include <iomanip> //for list of bets
#include <vector> // For storing bridges

using namespace std::chrono;
using namespace std;

struct Bridge 
{
    int start;
    int end;
};

// Function to display track and update racer's position
void display_track1(int position1, int position2, int position3)
{
    const int width = 45;
    const int height = 17;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';
    char soullessone_char = 'z';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 4; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 4; j < width; j = j + 4) // Loop through each 3 column in the current row
        track[1][j] = '|';

    //Left and right tracks - vertical lines top part
    for (int i = 3; i < height - 8; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][4] = '|';
        track[i][8] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
        //track design
        track[5][width - 17] = '|';
        track[5][width - 13] = '|';
        track[5][width - 9] = '|';
        track[7][width - 17] = '|';
        track[7][width - 13] = '|';
        track[7][width - 5] = ' ';
        track[7][width - 1] = ' ';
        track[5][8] = '|';
        track[5][12] = '|';
        track[5][16] = '|';
        track[5][20] = '|';
        track[5][24] = '|';
        track[7][12] = '|';
        track[7][16] = '|';
        track[7][20] = '|';
        track[7][24] = '|';
    }
    //Left and right tracks - vertical lines bottom part
    for (int i = 9; i < height - 3; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 5] = '|';
        track[i][width - 9] = '|';
        //track design
        track[9][0] = ' ';
        track[9][4] = ' ';
        track[9][20] = '|';
        track[9][24] = '|';
        track[9][28] = '|';
        track[9][32] = '|';
        track[11][8] = '|';
        track[11][12] = '|';
        track[11][16] = '|';
        track[11][20] = '|';
        track[11][24] = '|';
    }
    //Left track - horizontal lines top part
    for (int i = 4; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][4] = '+';
        track[i][5] = '-';
        track[i][6] = '-';
        track[i][7] = '-';
        track[i][8] = '+';
        //track design
        track[i][9] = '-';
        track[i][10] = '-';
        track[i][11] = '-';
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
        track[i][17] = '-';
        track[i][18] = '-';
        track[i][19] = '-';
        track[i][20] = '+';
        track[i][21] = '-';
        track[i][22] = '-';
        track[i][23] = '-';
        track[i][24] = '+';
        track[i][25] = '-';
        track[i][26] = '-';
        track[i][27] = '-';
        track[i][28] = '+';
        track[i][29] = '-';
        track[i][30] = '-';
        track[i][31] = '-';
        track[i][32] = '+';
        track[i][33] = '-';
        track[i][34] = '-';
        track[i][35] = '-';
        track[i][36] = '+';
        track[i][37] = '-';
        track[i][38] = '-';
        track[i][39] = '-';
        track[4][9] = ' ';
        track[4][10] = ' ';
        track[4][11] = ' ';
        track[4][25] = ' ';
        track[4][26] = ' ';
        track[4][27] = ' ';
        track[6][25] = ' ';
        track[6][26] = ' ';
        track[6][27] = ' ';
        track[8][25] = ' ';
        track[8][26] = ' ';
        track[8][27] = ' ';
        track[8][17] = ' ';
        track[8][18] = ' ';
        track[8][19] = ' ';
    }
    //Left track - horizontal lines bottom part
    for (int i = 10; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
        //track design
        track[i][5] = '-';
        track[i][6] = '-';
        track[i][7] = '-';
        track[i][8] = '+';
        track[i][9] = '-';
        track[i][10] = '-';
        track[i][11] = '-';
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
        track[i][17] = '-';
        track[i][18] = '-';
        track[i][19] = '-';
        track[i][20] = '+';
        track[i][21] = '-';
        track[i][22] = '-';
        track[i][23] = '-';
        track[i][24] = '+';
        track[10][28] = '+';
        track[10][29] = '-';
        track[10][30] = '-';
        track[10][31] = '-';
        track[10][32] = '+';
        track[10][33] = '-';
        track[10][34] = '-';
        track[10][35] = '-';
    }
    //Right track - horizontal lines top part
    for (int i = 4; i < height - 10; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 5] = '+';
        track[i][width - 4] = '-';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }
    //Right track - horizontal lines bottom part
    for (int i = 8; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 9] = '+';
        track[i][width - 8] = '-';
        track[i][width - 7] = '-';
        track[i][width - 6] = '-';
        track[i][width - 5] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 0; j < width - 5; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 5] = '+';
    }

    for (int j = 0; j < width - 4; j = j + 4) // Loop through each 3 column of the track
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    //Go up
    case 0:
        track[height - 2][1] = xwing_char;
        break;
    case 1:
        track[height - 4][1] = xwing_char;
        break;
    case 2:
        track[height - 6][1] = xwing_char;
        break;
    //Go right
    case 3:
        track[height - 6][5] = xwing_char;
        break;
    case 4:
        track[height - 6][9] = xwing_char;
        break;
    case 5:
        track[height - 6][13] = xwing_char;
        break;
    case 6:
        track[height - 6][17] = xwing_char;
        break;
    case 7:
        track[height - 6][21] = xwing_char;
        break;
    //Go up
    case 8:
        track[height - 8][21] = xwing_char;
        break;
    case 9:
        track[height - 10][21] = xwing_char;
        break;
    case 10:
        track[height - 12][21] = xwing_char;
        break;
    //Go left
    case 11:
        track[height - 12][17] = xwing_char;
        break;
    case 12:
        track[height - 12][width - 32] = xwing_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 32] = xwing_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 36] = xwing_char;
        break;
    case 15:
        track[height - 10][width - 40] = xwing_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 40] = xwing_char;
        break;
    case 17:
        track[height - 14][width - 40] = xwing_char;
        break;
    case 18:
        track[1][width - 40] = xwing_char;
        break;
    //Go right
    case 19:
        track[1][width - 36] = xwing_char;
        break;
    case 20:
        track[1][width - 32] = xwing_char;
        break;
    case 21:
        track[1][width - 28] = xwing_char;
        break;
    case 22:
        track[1][width - 24] = xwing_char;
        break;
    case 23:
        track[1][width - 20] = xwing_char;
        break;
    case 24:
        track[1][width - 16] = xwing_char;
        break;
    case 25:
        track[1][width - 12] = xwing_char;
        break;
    case 26:
        track[1][width - 8] = xwing_char;
        break;
    case 27:
        track[1][width - 4] = xwing_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 4] = xwing_char;
        break;
    case 29:
        track[height - 12][width - 4] = xwing_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 8] = xwing_char;
        break;
    case 31:
        track[height - 12][width - 12] = xwing_char;
        break;
    case 32:
        track[height - 12][width - 16] = xwing_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 16] = xwing_char;
        break;
    case 34:
        track[height - 8][width - 16] = xwing_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 12] = xwing_char;
        break;
    case 36:
        track[height - 8][width - 8] = xwing_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 8] = xwing_char;
        break;
    case 38:
        track[height - 4][width - 8] = xwing_char;
        break;
    case 39:
        track[height - 2][width - 8] = xwing_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 12] = xwing_char;
        break;
    case 41:
        track[height - 2][width - 16] = xwing_char;
        break;
    case 42:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 43:
        track[height - 2][width - 24] = xwing_char;
        break;
    case 44:
        track[height - 2][width - 28] = xwing_char;
        break;
    case 45:
        track[height - 2][width - 32] = xwing_char;
        break;
    case 46:
        track[height - 2][width - 36] = xwing_char;
        break;
    case 47:
        track[height - 2][width - 40] = xwing_char;
        break;
    case 48:
        track[height - 2][width - 44] = xwing_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 50:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 51:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 52:
        track[height - 2][width - 44] = xwing_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    //Go up
    case 0:
        track[height - 2][2] = tiefighter_char;
        break;
    case 1:
        track[height - 4][2] = tiefighter_char;
        break;
    case 2:
        track[height - 6][2] = tiefighter_char;
        break;
    //Go right
    case 3:
        track[height - 6][6] = tiefighter_char;
        break;
    case 4:
        track[height - 6][10] = tiefighter_char;
        break;
    case 5:
        track[height - 6][14] = tiefighter_char;
        break;
    case 6:
        track[height - 6][18] = tiefighter_char;
        break;
    case 7:
        track[height - 6][22] = tiefighter_char;
        break;
    //Go up
    case 8:
        track[height - 8][22] = tiefighter_char;
        break;
    case 9:
        track[height - 10][22] = tiefighter_char;
        break;
    case 10:
        track[height - 12][22] = tiefighter_char;
        break;
    //Go left
    case 11:
        track[height - 12][18] = tiefighter_char;
        break;
    case 12:
        track[height - 12][width - 31] = tiefighter_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 31] = tiefighter_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 35] = tiefighter_char;
        break;
    case 15:
        track[height - 10][width - 39] = tiefighter_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 39] = tiefighter_char;
        break;
    case 17:
        track[height - 14][width - 39] = tiefighter_char;
        break;
    case 18:
        track[1][width - 39] = tiefighter_char;
        break;
    //Go right
    case 19:
        track[1][width - 35] = tiefighter_char;
        break;
    case 20:
        track[1][width - 31] = tiefighter_char;
        break;
    case 21:
        track[1][width - 27] = tiefighter_char;
        break;
    case 22:
        track[1][width - 23] = tiefighter_char;
        break;
    case 23:
        track[1][width - 19] = tiefighter_char;
        break;
    case 24:
        track[1][width - 15] = tiefighter_char;
        break;
    case 25:
        track[1][width - 11] = tiefighter_char;
        break;
    case 26:
        track[1][width - 7] = tiefighter_char;
        break;
    case 27:
        track[1][width - 3] = tiefighter_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 3] = tiefighter_char;
        break;
    case 29:
        track[height - 12][width - 3] = tiefighter_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 7] = tiefighter_char;
        break;
    case 31:
        track[height - 12][width - 11] = tiefighter_char;
        break;
    case 32:
        track[height - 12][width - 15] = tiefighter_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 15] = tiefighter_char;
        break;
    case 34:
        track[height - 8][width - 15] = tiefighter_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 11] = tiefighter_char;
        break;
    case 36:
        track[height - 8][width - 7] = tiefighter_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 7] = tiefighter_char;
        break;
    case 38:
        track[height - 4][width - 7] = tiefighter_char;
        break;
    case 39:
        track[height - 2][width - 7] = tiefighter_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 11] = tiefighter_char;
        break;
    case 41:
        track[height - 2][width - 15] = tiefighter_char;
        break;
    case 42:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 43:
        track[height - 2][width - 23] = tiefighter_char;
        break;
    case 44:
        track[height - 2][width - 27] = tiefighter_char;
        break;
    case 45:
        track[height - 2][width - 31] = tiefighter_char;
        break;
    case 46:
        track[height - 2][width - 35] = tiefighter_char;
        break;
    case 47:
        track[height - 2][width - 39] = tiefighter_char;
        break;
    case 48:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 50:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 51:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 52:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    }

    //Assign racer 3 symbol
    switch (position3)
    {
    //Go up
    case 0:
        track[height - 2][3] = soullessone_char;
        break;
    case 1:
        track[height - 4][3] = soullessone_char;
        break;
    case 2:
        track[height - 6][3] = soullessone_char;
        break;
    //Go right
    case 3:
        track[height - 6][7] = soullessone_char;
        break;
    case 4:
        track[height - 6][11] = soullessone_char;
        break;
    case 5:
        track[height - 6][15] = soullessone_char;
        break;
    case 6:
        track[height - 6][19] = soullessone_char;
        break;
    case 7:
        track[height - 6][23] = soullessone_char;
        break;
    //Go up
    case 8:
        track[height - 8][23] = soullessone_char;
        break;
    case 9:
        track[height - 10][23] = soullessone_char;
        break;
    case 10:
        track[height - 12][23] = soullessone_char;
        break;
    //Go left
    case 11:
        track[height - 12][19] = soullessone_char;
        break;
    case 12:
        track[height - 12][width - 30] = soullessone_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 30] = soullessone_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 34] = soullessone_char;
        break;
    case 15:
        track[height - 10][width - 38] = soullessone_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 38] = soullessone_char;
        break;
    case 17:
        track[height - 14][width - 38] = soullessone_char;
        break;
    case 18:
        track[1][width - 38] = soullessone_char;
        break;
    //Go right
    case 19:
        track[1][width - 34] = soullessone_char;
        break;
    case 20:
        track[1][width - 30] = soullessone_char;
        break;
    case 21:
        track[1][width - 26] = soullessone_char;
        break;
    case 22:
        track[1][width - 22] = soullessone_char;
        break;
    case 23:
        track[1][width - 18] = soullessone_char;
        break;
    case 24:
        track[1][width - 14] = soullessone_char;
        break;
    case 25:
        track[1][width - 10] = soullessone_char;
        break;
    case 26:
        track[1][width - 6] = soullessone_char;
        break;
    case 27:
        track[1][width - 2] = soullessone_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 2] = soullessone_char;
        break;
    case 29:
        track[height - 12][width - 2] = soullessone_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 6] = soullessone_char;
        break;
    case 31:
        track[height - 12][width - 10] = soullessone_char;
        break;
    case 32:
        track[height - 12][width - 14] = soullessone_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 14] = soullessone_char;
        break;
    case 34:
        track[height - 8][width - 14] = soullessone_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 10] = soullessone_char;
        break;
    case 36:
        track[height - 8][width - 6] = soullessone_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 6] = soullessone_char;
        break;
    case 38:
        track[height - 4][width - 6] = soullessone_char;
        break;
    case 39:
        track[height - 2][width - 6] = soullessone_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 10] = soullessone_char;
        break;
    case 41:
        track[height - 2][width - 14] = soullessone_char;
        break;
    case 42:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 43:
        track[height - 2][width - 22] = soullessone_char;
        break;
    case 44:
        track[height - 2][width - 26] = soullessone_char;
        break;
    case 45:
        track[height - 2][width - 30] = soullessone_char;
        break;
    case 46:
        track[height - 2][width - 34] = soullessone_char;
        break;
    case 47:
        track[height - 2][width - 38] = soullessone_char;
        break;
    case 48:
        track[height - 2][width - 42] = soullessone_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 50:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 51:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 52:
        track[height - 2][width - 42] = soullessone_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++) // Loop through each row of the track
    {
        for (int j = 0; j < width; j++) // Loop through each column of the track
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

// Function to generate random steps within a range for each racer
int generateRandomSteps(int minSteps, int maxSteps) 
{
    return rand() % (maxSteps - minSteps + 1) + minSteps;
}

bool apply_bridge(int &position, const vector<Bridge> &bridges) {
    for (const auto &bridge : bridges) {
        if (position == bridge.start) {
            position = bridge.end;
            return true;
        }
    }
    return false; // Ensure the function returns false if no bridge was used
}

int main()
{
    srand(time(0)); // Seed for random number generation
    int xwing_SpeedMin = 2;
    int xwing_SpeedMax = 4;
    int tiefighter_SpeedMin = 1;
    int tiefighter_SpeedMax = 5;
    int soullessone_SpeedMin = 3;
    int soullessone_SpeedMax = 6;
    int xwing_position = 0;
    int tiefighter_position = 0;
    int soullessone_position = 0;
    int race_rounds = 0;
    int turn_of_race = 1;
    int xw = 0, tw = 0, sw = 0;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)
    vector<Bridge> bridges;
    int num_bridges;

    // Get number of bridges from user
    do {
        cout << "Enter the number of bridges (3-5): ";
        cin >> num_bridges;
    } while (num_bridges < 3 || num_bridges > 5);

    cout << "Enter number of rounds for the race: ";
    cin >> race_rounds;

    // Get start and end positions for each bridge
    for (int i = 0; i < num_bridges; ++i) {
        Bridge bridge;
        cout << "Enter start location for bridge " << i + 1 << ": ";
        cin >> bridge.start;
        cout << "Enter end location for bridge " << i + 1 << ": ";
        cin >> bridge.end;
        bridges.push_back(bridge);
    }

    for (int round = 1; round <= race_rounds; ++round)
    {
        // Reset positions for each new round
        xwing_position = 0;
        tiefighter_position = 0;
        soullessone_position = 0;
        turn_of_race = 1;

        // Display initial track for each round
        cout << "\nRound " << round << endl;


        display_track1(xwing_position, tiefighter_position, soullessone_position);


        while (true)
        {
            // Increment turn of the race
            turn_of_race++;

            // Generate random steps for the racers in each iteration
            int xwing_Steps = generateRandomSteps(xwing_SpeedMin, xwing_SpeedMax);
            int tiefighter_Steps = generateRandomSteps(tiefighter_SpeedMin, tiefighter_SpeedMax);
            int soullessone_Steps = generateRandomSteps(soullessone_SpeedMin, soullessone_SpeedMax);

            // Move each racer forward randomly
            xwing_position += xwing_Steps;
            tiefighter_position += tiefighter_Steps;
            soullessone_position += soullessone_Steps;

            // Display turn of the race
            cout << "Turn " << turn_of_race << endl << endl;

            // Mention number of steps each racer moved
            cout << "X Wing moved " << xwing_Steps << " steps" << endl;
            cout << "Tie Fighter moved " << tiefighter_Steps << " steps" << endl;
            cout << "Soulless One moved " << soullessone_Steps << " steps" << endl;

            // Apply bridges
            bool bridge_used1 = apply_bridge(xwing_position, bridges);
            bool bridge_used2 = apply_bridge(tiefighter_position, bridges);
            bool bridge_used3 = apply_bridge(soullessone_position, bridges);

            if (bridge_used1) {
                cout << "Racer x used a bridge!" << endl;
            }
            if (bridge_used2) {
                cout << "Racer y used a bridge!" << endl;
            }
            if (bridge_used3) {
                cout << "Racer z used a bridge!" << endl;
            }

            display_track1(xwing_position, tiefighter_position, soullessone_position);

            // Check if any racer has reached the end of the track
            if (xwing_position >= 49 && tiefighter_position >= 49 && soullessone_position >= 49)
            {
                cout << "It's a tie for this round!\n" << endl;
                break; // Exit the loop for this round
            }
            else if (xwing_position >= 49)
            {
                cout << "X Wing wins the race for this round!\n" << endl;
                xw++;
                break; // Exit the loop for this round
            }
            else if (tiefighter_position >= 49)
            {
                cout << "Tie Fighter wins the race for this round!\n" << endl;
                tw++;
                break; // Exit the loop for this round
            }
            else if (soullessone_position >= 49)
            {
                cout << "Soulless One wins the race for this round!\n" << endl;
                sw++;
                break; // Exit the loop for this round
            }

            // Pause before next iteration
            this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
        }
    }

    cout << "Game Over" << endl;
    cout << "\nThe score is:";
    cout << "\nxwing:" << xw << "\ntiefigther:" << tw << "\nsoullessone:" << sw <<endl;

    // Display the list of bridges
    cout << "Bridges:" << endl;
    for (int i = 0; i < bridges.size(); ++i) {
        cout << "Bridge " << i + 1 << ": Start = " << bridges[i].start << ", End = " << bridges[i].end << endl;
    }

    return 0;
}