#ifndef _board_hpp_
#define _board_hpp_

#include "../skeleton/point.h"
#include "../skeleton/rect.h"
#include "../skeleton/image_object.h"

#include <string>

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


    void mouseMoveEvent(unsigned x, unsigned y);
	void keyPressEvent(int);
	void draw();
    void init();
    void update(unsigned int);
    

private:
    LeImageObject up_btn;
    LeImageObject down_btn;
    LeImageObject left_btn;
    LeImageObject right_btn;
    
private:
    void move_player_left();
    void move_player_right();
    void move_player_up();
    void move_player_down();
    void player_move();


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
    
	bool first;
    //std::vector<std::pair<int,int>> tmp;
    
    std::string cheesepic;
    std::string mousepic;
    LeRect rect;
    
    bool m_need_update;
    unsigned int m_last_upd_time;
    int m_update_freq;
    
   
    int m_move_where;

    
    
};

#endif
