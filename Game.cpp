//#include<iostream>
//#include"Game.h"
//#include<cstdlib>
//#include<ctime>
//#include<conio.h>//_getch()
//#include<windows.h>
//#include<chrono>
//#include<fstream>
//#include<string>
//using namespace std;
//using namespace chrono;
//const int row = 15;
//const int col = 55;
//const int numEnemies = 3;
//int countEnemies = 3;
//int player_life = 3;
//int playerX = row - 2;
//int playerY = col / 2;
//int bombX = -1;
//int bombY = -1;
//int score = 0;
//int win = 0;
//int numofObs = 10;
//char grid[row][col];
//bool bombPlaced = false;
//bool bombExploded = false;
//bool enemykilled = false;
//bool explosionVisible;
//bool powerActive = false;
//int twoExplosion = 2;
//bool gamestart = true;//for game start sound only 1 time play
//steady_clock::time_point startTime;
//char input;
//bool enemyDown = false; //flag to check
//int enemyPos[numEnemies][2]; // 2D array for enemy positions
//void nextlevelsound()
//{
//    const wchar_t* soundFilePath = L"nextlevel.wav";
//
//    if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//    }
//}
//void map2() {
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (i == 0 || i == row - 1 ) {
//                grid[i][j] = '='; 
//            }
//            else if ( j == 0 || j == col - 1) {
//                grid[i][j] = '|';
//            }
//            else if ((i % 4 == 0 && j % 3 == 0)) {
//                grid[i][j] = '#'; // Less frequent obstacles
//            }
//            else if ((i + j) % 7 == 0) {
//                grid[i][j] = 'O'; // Less frequent destructible walls
//            }
//            else {
//                grid[i][j] = ' '; // Empty space
//            }
//        }
//    }
//
//    // Place the player on the map
//    grid[playerX][playerY] = 'P';
//
//    // Place the bomb if it exists
//    if (bombX != -1 && bombY != -1) {
//        grid[bombX][bombY] = 'B';
//    }
//
//    // Place the enemies
//    for (int i = 0; i < countEnemies; i++) {
//        if (enemyPos[i][0] != -1 && enemyPos[i][1] != -1) {
//            grid[enemyPos[i][0]][enemyPos[i][1]] = 'E';
//        }
//    }
//
//    // Display the map
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (grid[i][j] == '#') {
//                // Print boundaries '#' in white
//                cout << "\033[37m" << grid[i][j] << "\033[0m";
//            }
//            else if (grid[i][j] == 'P') {
//                // Print 'P' in green
//                cout << "\033[32m" << grid[i][j] << "\033[0m";
//            }
//            else if (grid[i][j] == 'B' || grid[i][j] == 'X') {
//                // Print 'B' and 'X' in orange
//                cout << "\033[38;5;214m" << grid[i][j] << "\033[0m";
//            }
//            else if (grid[i][j] == 'E') {
//                // Print 'E' in red
//                cout << "\033[31m" << grid[i][j] << "\033[0m";
//            }
//            else if (grid[i][j] == '+') {
//                // Print '+' in blue
//                cout << "\033[34m" << grid[i][j] << "\033[0m";
//            }
//            else if (grid[i][j] == 'O') {
//                // Print 'O' in purple
//                cout << "\033[35m" << grid[i][j] << "\033[0m";
//            }
//            else {
//                // Default color for other characters
//                cout << "\033[0m" << grid[i][j];
//            }
//        }
//        cout << endl;
//    }
//
//    // Display game stats
//    cout << "SCORE IS: " << score << endl;
//    cout << "NO. of lives left: " << player_life << endl;
//    cout << "Number of enemies alive: " << countEnemies << endl;
//}
//
//void filehandler(int score) {
//    int scores[3] = { 0, 0, 0 }; // To hold the top 3 scores
//    ifstream inFile("score2.txt");
//
//    // Read the previous scores from the file
//    if (inFile.is_open()) {
//        string temp;
//        getline(inFile, temp); // Skip the heading line
//        for (int i = 0; i < 3; i++) {
//            inFile >> scores[i];
//        }
//        inFile.close();
//    }
//
//    // Update the scores if the new score is higher
//    scores[2] = max(scores[2], score);
//
//    for (int i = 0; i < 3; i++) {
//        for (int j = i + 1; j < 3; j++) {
//            if (scores[i] < scores[j]) {
//                swap(scores[i], scores[j]);
//            }
//        }
//    }
//    ofstream outFile("score2.txt");
//    if (outFile.is_open()) {
//        outFile << "LATEST HIGH SCORES ARE:" << endl;
//        for (int i = 0; i < 3; i++) {
//            outFile << scores[i] << endl;
//        }
//        outFile.close();
//    }
//    else {
//        cerr << "Error: Could not create the file." << endl;
//    }
//
//}
//
//void nextLevel()
//{
//    win = 1;
//    nextlevelsound();
//    initialize_map();
//    countEnemies = 5;
//    map2();
//    initialize_map();
//    moveEnemies();
//    powerup();
//    Sleep(50);
//    update_map();
//    if (countEnemies == 0)
//    {
//        display_menu();
//    }
//}
//
//void gameoversound()
//{
//    const wchar_t* soundFilePath = L"gameover.wav";
//
//    if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//    }
//}
//void looseCondition()
//{
//    if (player_life == 0)
//    {
//        cout << "                 YOU LOST !!!" << endl;
//        gameoversound();
//        Sleep(5000);
//        if (player_life == 0)
//        {
//            display_menu();
//        }
//    }
//}
//
//void winCondition()
//{
//    filehandler(score);
//    if (countEnemies == 0)
//    {
//        cout << "YOU HAVE CLEARED THIS STAGE....HURRAY!!!" << endl;
//       
//        Sleep(5000);
//        system("cls");
//        nextLevel();
//
//    }
//}
//void gamestartsound()
//{ if(gamestart)
//    {
//        const wchar_t* soundFilePath = L"gamestart.wav";
//         if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//            std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//         }
//    }
//gamestart = false;
//    
//}
//void enemyattacksound()
//{
//    const wchar_t* soundFilePath = L"enemyattack.wav";
//
//    if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//    }
//}
//void powerupsound()
//{
//    const wchar_t* soundFilePath = L"powerup.wav";
//
//    if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//    }
//}
//void bombSound()
//{
//    const wchar_t* soundFilePath = L"explosion.wav";
//
//    if (!PlaySound(soundFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Failed to play sound! Please check the file path." << std::endl;
//    }
//}
//void display_menu() {
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                BOMBERMAN           " << endl;
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                1. Start Game" << endl;
//    cout << "                                                                2. Instructions" << endl;
//    cout << "                                                                3. Exit" << endl;
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                Enter your choice: ";
//}
//void display_instructions() {
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                INSTRUCTIONS         " << endl;
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                Use the following keys to play :" << endl;
//    cout << "W to Move Up" << endl;
//    cout << "A to Move Left" << endl;
//    cout << "S to Move Down" << endl;
//    cout << "D to Move Right" << endl;
//    cout << "F to Drop Bomb" << endl;
//    cout << "P to Quit Game" << endl;
//    cout << "====================================================================================================================================================" << endl;
//    cout << "                                                                Press any key to return to the menu..." << endl;
//    _getch();  // wait for user input
//}
//void initializeEnemyPositions() {
//    srand(time(0)); // Seed for randomness
//
//    for (int i = 0; i < numEnemies; i++) {
//        while (true) { 
//            int x = rand() % (row - 2) + 1; 
//            int y = rand() % (col - 2) + 1; 
//            bool validPos = true;
//            for (int j = 0; j < i; j++) {
//                if (enemyPos[j][0] == x && enemyPos[j][1] == y) {
//                    validPos = false;
//                    break;
//                }
//            }
//            if (validPos) { 
//                enemyPos[i][0] = x; 
//                enemyPos[i][1] = y; 
//                break;
//            }
//        }
//    }
//}
//
//void initialize_map() {
//    srand(time(0));
//    int p =rand()%row-2 +1;
//    int q = rand() % col-2 +1 ;
//    int r = rand() % row - 2 + 1;
//    int s = rand() % col - 2 + 1;
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (i == 0 || i == row - 1)
//                grid[i][j] = '=';
//            else if (j == 0 || j == col - 1)
//                grid[i][j] = '||';
//            else if (i == p && j==q || i==r && j==s)
//            {
//                grid[i][j] = '+';
//            }
//            else if (i == row - 2 && j == col / 2 + 1 || i == row - 2 && j == col / 2 - 1)
//            {
//                grid[i][j] = '|';
//            }
//            else
//                grid[i][j] = ' ';
//        }
//    }
//    putobstacles();
//    initializeEnemyPositions(); // Initialize enemy positions
//}
//void putobstacles() {
//    for (int i = 1; i < row - 1; i += 4) {
//        for (int j = 1; j < col - 1; j += 10) {
//            grid[i][j] = '#';
//        }
//    }
//    srand(time(0));
//    int obs_placed = 0;
//    while (obs_placed < numofObs) {
//        int i = rand() % (row - 2) + 1;  // random row within bounds (1 to row - 2)
//        int j = rand() % (col - 2) + 1;  // random column within bounds (1 to col - 2)
//
//        if (grid[i][j] == ' ') {
//            grid[i][j] = 'O';
//            obs_placed++;
//        }
//    }
//}
//void bomb_range_main()
//{
//    // First layer explosion
//    bomb_range(bombX, bombY);
//    bomb_range(bombX - 1, bombY);
//    bomb_range(bombX + 1, bombY);
//    bomb_range(bombX, bombY - 1);
//    bomb_range(bombX, bombY + 1);
//    // Second layer explosion
//    bomb_range(bombX - 2, bombY);
//    bomb_range(bombX + 2, bombY);
//    bomb_range(bombX, bombY - 2);
//    bomb_range(bombX, bombY + 2);
//    bombSound();
//  
//    explosionVisible = true;
//}
//void bomb_range_main_powerup()
//{
//    // First layer explosion
//    bomb_range(bombX, bombY);
//    bomb_range(bombX - 1, bombY);
//    bomb_range(bombX + 1, bombY);
//    bomb_range(bombX, bombY - 1);
//    bomb_range(bombX, bombY + 1);
//    // 2 layer
//    bomb_range(bombX - 2, bombY);
//    bomb_range(bombX + 2, bombY);
//    bomb_range(bombX, bombY - 2);
//    bomb_range(bombX, bombY + 2);
//    //3 layer
//    bomb_range(bombX - 3, bombY);
//    bomb_range(bombX + 3, bombY);
//    bomb_range(bombX, bombY - 3);
//    bomb_range(bombX, bombY + 3);
//    //4 layer
//    bomb_range(bombX - 4, bombY);
//    bomb_range(bombX + 4, bombY);
//    bomb_range(bombX, bombY - 4);
//    bomb_range(bombX, bombY + 4);
//    explosionVisible = true;     // X show hota h ? 
//    bombSound(); 
//}
//void removeBomb() {
//    if (bombX != -1 && bombY != -1) {
//        grid[bombX][bombY] = ' '; // clear the bomb from the grid
//    }
//    bombX = -1;
//    bombY = -1;
//    bombPlaced = false; // it mark bomb as removed
//}
//void powerup()
//{
//    if (grid[playerX][playerY] == '+')
//    {
//        cout << "Power up !!! BOMB RANGE INCREASED" << endl;
//       // bomb_range_main_powerup();
//        powerActive = true; 
//        powerupsound();
//    }
//}
//void isBombPlaced() {
//    input = _getch();
//    if (input == 'f' || input == 'F') {
//        bombPlaced = true;
//        startTime = steady_clock::now();  // start tracking bomb placement time
//        grid[bombX][bombY] = 'B';  
//    }
//}
//void bomb_range(int x, int y) {
//  
//
//        if (x < 0 || x >= row || y < 0 || y >= col) {
//            return; // out of bounds
//        }
//        if (grid[x][y] == '#') {
//            score += 10;
//            return;
//        }
//        else if (grid[x][y] == 'E')
//        {
//            grid[x][y] = 'X';
//            score += 50;
//            countEnemies--;
//            cout << "Enemy destroyed !!! " << endl;
//            enemykilled = true;
//        }
//        else if (grid[x][y] == 'O') {
//            grid[x][y] = 'X';
//        }
//        else if (grid[x][y] == 'P') {
//            player_life--;
//            enemyattacksound();
//           // Sleep(1000);
//            cout << "Player life now is:" << player_life << endl;
//        }
//        else  if (grid[x][y] == ' ' || grid[x][y] == 'B') {
//            grid[x][y] = 'X';
//
//        }
//    
//}
//void setCursorPosition(int x, int y) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//    SetConsoleCursorPosition(hConsole, pos);
//}
//void explode() {
//     explosionVisible = false; // it tracks if the explosion is currently visible
//    if (bombPlaced) {
//        auto currentTime = steady_clock::now();
//        // Trigger explosion after 3 seconds
//        if (!explosionVisible && duration_cast<seconds>(currentTime - startTime).count() >= 3) 
//        {
//            grid[bombX][bombY] = 'X'; // marks explosion at bomb's position
//            if (powerActive && twoExplosion>0)
//            {
//                score += 20;
//                bomb_range_main_powerup();
//                twoExplosion -=1;
//            }
//            else {
//                bomb_range_main();
//            }
//            system("cls");
//            map();//flashing of strriks 
//            removeBomb();
//        }
//        // Clear explosion after 2 second
//        if (explosionVisible && duration_cast<seconds>(currentTime - startTime).count() >= 5) {
//            for (int x = max(0, bombX - 2); x <= min(row - 1, bombX + 2); x++) {
//                for (int y = max(0, bombY - 2); y <= min(col - 1, bombY + 2); y++) {
//                    if (grid[x][y] == 'X' || grid[x][y] == 'B') {
//                        grid[x][y] = ' '; // Clear explosion
//                        system("cls");
//                        map();
//                    }
//                }
//            }
//             explosionVisible = false; // reset explosion visibility
//            bombPlaced = false;
//        }
//    }
//}
//void update_map() {
//    // Clear previous positions
//    setCursorPosition(0,0);
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++)  // reset all cells except boundaries 
//        {
//           
//            if (grid[i][j] != '#' && grid[i][j] != 'O' && grid[i][j] != '=' && grid[i][j] != '|' && grid[i][j]!='+') {
//                grid[i][j] = ' ';
//            }
//        }
//    }
//    grid[playerX][playerY] = 'P';
//    if (bombX != -1 && bombY != -1) {
//        grid[bombX][bombY] = 'B';
//    }
//    if (enemykilled)//no understand just stupid work
//    {
//        enemykilled = false;
//    }
//    for (int i = 0; i < countEnemies; i++)     // to update enemies' positions 
//    {   if (enemyPos[i][0] != -1 && enemyPos[i][1] != -1 ) {
//            grid[enemyPos[i][0]][enemyPos[i][1]] = 'E';
//        }
//    }
//  // cout << "SCORE IS :  " << score << endl;
//}
//void map() {
//    // Set background to black (by default) and print boundaries '#' in white
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (grid[i][j] == '#') {
//                // Print boundaries '#' in white
//                cout << "\033[37m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else if (grid[i][j] == 'P') {
//                // Print 'P' in green
//                cout << "\033[32m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else if (grid[i][j] == 'B' || grid[i][j] == 'X') {
//                // Print 'B' and 'X' in orange (using color code 214)
//                cout << "\033[38;5;214m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else if (grid[i][j] == 'E') {
//                // Print 'E' in red
//                cout << "\033[31m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else if (grid[i][j] == '+') {
//                // Print '+' in blue
//                cout << "\033[34m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else if (grid[i][j] == 'O') {
//                // Print 'O' in purple
//                cout << "\033[35m" << grid[i][j] << "\033[0m";  // Reset to default
//            }
//            else {
//                // Print other characters in the default color (which should be black background)
//                cout << "\033[0m" << grid[i][j]; // Ensures text remains at default
//            }
//        }
//        cout << endl;
//    }
//   // checkwin();
//  cout << "SCORE IS :  "  <<score<<endl;
//  cout << "NO. of lives left :" << player_life << endl;
//  cout << "Number of enemies alive :" << countEnemies << endl;
//}
//
//
//
//void hideCursor() {
//    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_CURSOR_INFO cursorInfo;
//    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
//    cursorInfo.bVisible = false;
//    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
//}
//void spawn_bomb() {
//    bombX = playerX;
//    bombY = playerY + 1;
//    bombPlaced = true; // it mark bomb as placed
//}
//void movePlayer(char direction) {
//    int prevX = playerX;
//    int prevY = playerY;
//    switch (direction) {
//    case 'w':
//        if (playerX > 1 && (grid[playerX - 1][playerY] != '#' && grid[playerX - 1][playerY] != 'O')) {
//            playerX--;
//        }
//        break;
//    case 's':
//        if (playerX < row - 2 && (grid[playerX + 1][playerY] != '#' && grid[playerX + 1][playerY] != 'O')) {
//            playerX++;
//        }
//        break;
//    case 'a':
//        if (playerY > 1 && (grid[playerX][playerY - 1] != '#' && grid[playerX][playerY - 1] != 'O')) {
//            playerY--;
//        }
//        break;
//    case 'd':
//        if (playerY < col - 2 && (grid[playerX][playerY + 1] != '#' && grid[playerX][playerY + 1] != 'O')) {
//            playerY++;
//        }
//        break;
//    case 'f':
//        if (!bombPlaced)
//        {  // Ensure only one bomb is active at a time
//            bombPlaced = true;
//            startTime = steady_clock::now();  // start the bomb timer
//            bombX = playerX;  // set bomb coordinates to player's current position
//            bombY = playerY;
//            grid[bombX][bombY] = 'B';  // Place the bomb on the grid
//            explode();
//        }
//        break;
//    }
//    grid[prevX][prevY] = ' ';
//}
//void moveEnemies() {
//    for (int i = 0; i < numEnemies; i++) {
//        int enemyX = enemyPos[i][0];
//        int enemyY = enemyPos[i][1];
//        int moveDirection = rand() % 8;
//        int newX = enemyX, newY = enemyY;
//        // corners
//        if (enemyX == 1 && enemyY == 1)
//        {
//            if (grid[enemyX + 1][enemyY] == ' ')
//            {
//                enemyX++;
//            }
//        }
//        else if (enemyX == 1 && enemyY == col - 2)
//        {
//            if (grid[enemyX][enemyY - 1] == ' ')
//            {
//                enemyY--;
//            }
//        }
//        else if (enemyX == row - 2 && enemyY == col - 2)
//        {
//            if (grid[enemyX - 1][enemyY] == ' ')
//            {
//                enemyX--;
//            }
//        }
//        else if (enemyX == row - 2 && enemyY == 1)
//        {
//            if (grid[enemyX][enemyY + 1] == ' ')
//            {
//                enemyY++;
//            }
//        }
//        else
//        {
//            switch (moveDirection) {
//            case 0:
//                newX--;//--
//                break;
//            case 1:
//                newX++;//++
//                break;
//            case 2:
//                newY--;
//                break;
//            case 3:
//                newY++;
//                break;
//            default:
//                newX;
//            }
//        }
//       
//        if (newX > 0 && newX < row - 1 && newY > 0 && newY < col - 1) {
//            if (grid[newX][newY] == ' ') {
//                enemyPos[i][0] = newX;
//                enemyPos[i][1] = newY;
//            }
//        }
//    }
//    if (grid[playerX][playerY] == 'E')
//    {
//        Sleep(2000);
//        enemyattacksound();
//        player_life--;
//        cout << "Player life now is:" << player_life << endl;
//    }
//    if (player_life == 0)
//    {
//        gameoversound();
//        cout << "\n\n\n                                        YOU LOSE !!!" << endl;
//        Sleep(10000);
//    }
//}
