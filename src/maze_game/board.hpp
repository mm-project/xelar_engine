#ifndef _board_hpp_
#define _board_hpp_

#include "../skeleton/point.h"

class Maze;
class Player;
class Level_interface;

class Board
{
public:
    Board();
    ~Board();

    void continueGame();
    void reset();

    void changeState(Level_interface*);

    void Level_changed();
    void Win();

public:
    void newGame();



	void keyPressEvent(int);
	void draw();
    

private:
    void loadSettings();
    void generate();
    void renderMaze();
    void renderWin();
    void go_to_next_level();
    bool check_in_bounding_box();

	int m_total_targets;
    Player* m_player;
    Maze* m_maze;
	LePoint m_start;

	unsigned int m_up;
	unsigned int m_down;
	unsigned int m_left;
	unsigned int m_right;

    Level_interface* m_level;
    int level_count;
};

#endif
