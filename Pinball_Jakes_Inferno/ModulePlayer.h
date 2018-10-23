#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
class b2MouseJoint;

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture *		ball_tex = nullptr;
	uint				ball_sound;
	int					ball_position_x;
	int					ball_position_y;

	PhysBody*			ball = nullptr;
	bool				ball_created = false;

	//Springy
	PhysBody*			springy = nullptr;
	b2MouseJoint*		springy_joint = nullptr;
	
};