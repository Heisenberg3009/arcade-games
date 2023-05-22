#include "splashkit.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
std::vector;

const double value = 1;

struct player_data {
    double x; //Location of player x axis
    double y; //Location of player y axis
    bool win; //determines the end of the game
    bool player_up; // Direction vertically, either up or down
    bool player_right; // Direction horizontally, either right or left
}

struct enemy_data {
    double x; //Location of enemy x axis
    double y; //Location of enemy y axis
    bool enemy_up; // Direction vertically, either up or down
    bool enemy_right; // Direction horizontally, either right or left
}

struct gem_data {
    double x; //Location of gem x axis
    double y; //Location of gem y axis
    double value; //Value of the gem
    bool gem_up; // Direction vertically, either up or down
    bool gem_right; // Direction horizontally, either right or left
}

struct 
{
    gem_data gems*; //Array of gems that exist in the current level
    vector<gem_data> current_gems; //vector of gems currently active
    int gems_in_level; //Gems in the current level of the game
    int remaining_gems; //Remaining gems in the current level of the game
    int score = 0; //Score of the player
    bool game_start = false; //True if player has started the game
    bool game_over = false; //True if all levels are complete and no more gems are left
    bool game_won = false; //True if all levels are complete
    int current_level = 1; //Current level [starting level = 1]
    bool next_level = true; //Proceed to next level in the next frame
}game_data;

void end_level(bool successful)
{
    //Executed on successful completion of the game
	if(successful) {
		draw_text("You win! Press R to play again", COLOR_WHITE, font_named("default"), 30, 100, 300);
	}
    //Executed if the player has lost
	else {
		draw_text("You lose!, press R to try again", COLOR_WHITE, font_named("default"), 30, 100, 300);
	}
}

//Create Gem Data
gem_data create_gem(double x, double y){
    gem_data gem;
    gem.x = x;
    gem.y = y;
    return gem;
}

//Create Player Data
player_data create_player(double x, double y, bool up, bool right) {
    player_data player;
    player.x = x;
    player.y = y;
    player.up = up;
    payer.right = right;
    return player;
}

//A function to draw the gems (To be worked at.)
void draw_gems(){
    for(int i = 0; i < game_data.blocks_in_level; i++)
    {
        if ()
    }
}

//A function for the capturing of the gems (To be worked at.)
void gem_capture(){

}

//A function to spawn gems
gem_data *spawn_gems(){

}

//A function to load the resources required for the game
void load_resources(){

}

//Load title screen and start the game
void show_tiltle_screen(){
    clear_screen(COLOR_BLACK);
    draw_bitmap("title", 0, 0);
    draw_text("Press R to start", COLOR_WHITE, font_named("default"), 25, 250, 430);
    if(key_typed(R_KEY)) game_data.game_start = true;
}

void reset_game()
{
	game_data.score = 0;
	game_data.game_over = false;
	game_data.game_won = false;
	game_data.timer = 0;

	//Create gems
	game_data.gems = spawn_gems_level();
	game_data.gems_in_level = GEMS_IN_LEVEL;

	//Create gem in the starting position
	game_data.current_gems.push_back(create_gem(screen_width()/2, 500, true, true));

	//Player starting location
	game_data.player_x = (screen_width()-PLAYER_LENGTH)/2;

	//Draw the environment
	clear_screen(COLOR_BLACK);
	draw_blocks(); // Draw blocks
	draw_bitmap("paddle", game_data.paddle_x, PADDLE_Y); // Draw paddle
}

void check_gem_capture(int i)
{
        //Remove Gem
        game_data.current_gems[i] = game_data.current_gems[game_data.current_gems.size()-1];
        game_data.current_gems.pop_back();
        
        if (game_data.current_gems.size() == 0) 
        {
            //Lose the game if there are no more gems remaining
            game_data.game_won = false;
            game_data.game_over = true;
        }
}