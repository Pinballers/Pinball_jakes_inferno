#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
class PhysBody;
class b2MouseJoint;
class b2RevoluteJoint;

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void StopBall(int type);
	void PlayBall(int type);
	void RestartBall();
	void RestartGame();

public:
	
	
	int					ball_position_x = 340;
	int					ball_position_y = 980;
	int					random = 2;

	PhysBody*			ball = nullptr;
	bool				ball_created = false;

	//Close_Piece
	PhysBody*			close_piece = nullptr;
	bool				close_piece_created = false;

	//Springy
	PhysBody*			springy = nullptr;
	b2MouseJoint*		springy_joint = nullptr;
	uint				dead_cont = 120;

	//Flippers
	PhysBody*			left_flipper = nullptr;
	PhysBody*			right_flipper = nullptr;
	PhysBody*			left_flipper_bot = nullptr;
	PhysBody*			right_flipper_bot = nullptr;
	b2RevoluteJoint*	right_flipper_joint = nullptr;
	b2RevoluteJoint*	left_flipper_joint = nullptr;
	b2RevoluteJoint*	right_flipper_bot_joint = nullptr;
	b2RevoluteJoint*	left_flipper_bot_joint = nullptr;


	//Textures
	SDL_Texture*		ball_tex = nullptr;
	SDL_Texture*		left_flipper_tex = nullptr;
	SDL_Texture*		right_flipper_tex = nullptr;
	SDL_Texture*		close_piece_tex = nullptr;
	SDL_Texture*		springy_tex = nullptr;
	


	//Audio
	uint				flipper_sound;
	uint				ball_sound;
	uint				dead_sound;
	
};