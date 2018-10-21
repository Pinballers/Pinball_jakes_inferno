#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;
class b2RevoluteJoint;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:

	//Background 
	PhysBody*			background = nullptr;

	//Top static elements
	PhysBody*			left_piece1 = nullptr;
	PhysBody*			right_piece1 = nullptr;
	PhysBody*			left_piece2 = nullptr;
	PhysBody*			right_piece2 = nullptr;
	PhysBody*			left_wheel_piece = nullptr;
	PhysBody*			right_wheel_piece = nullptr;

	//Bot static elements
	PhysBody*			left_piece1_bot = nullptr;
	PhysBody*			right_piece1_bot = nullptr;
	PhysBody*			left_piece2_bot = nullptr;
	PhysBody*			right_piece2_bot = nullptr;

	//Action elements
	PhysBody*			circle1 = nullptr;
	PhysBody*			circle2 = nullptr;
	PhysBody*			circle3 = nullptr;
	PhysBody*			circle4 = nullptr;
	PhysBody*			circle5 = nullptr;
	PhysBody*			circle6 = nullptr;
	PhysBody*			circle7 = nullptr;
	PhysBody*			circle8 = nullptr;
	PhysBody*			circle9 = nullptr;
	PhysBody*			circle10 = nullptr;
	PhysBody*			circle11 = nullptr;

	//Flippers
	PhysBody*			left_flipper = nullptr;
	PhysBody*			right_flipper = nullptr;
	PhysBody*			left_flipper_bot = nullptr;
	PhysBody*			right_flipper_bot = nullptr;
	b2RevoluteJoint*	right_flipper_joint = nullptr;
	b2RevoluteJoint*	left_flipper_joint = nullptr;
	b2RevoluteJoint*	right_flipper_bot_joint = nullptr;
	b2RevoluteJoint*	left_flipper_bot_joint = nullptr;


	//Sprites
	SDL_Texture*		background_tex = nullptr;
	SDL_Texture*		left_piece1_tex = nullptr;
	SDL_Texture*		right_piece1_tex = nullptr;
	SDL_Texture*		left_piece2_tex = nullptr;
	SDL_Texture*		right_piece2_tex = nullptr;
	SDL_Texture*		left_wheel_piece_tex = nullptr;
	SDL_Texture*		right_wheel_piece_tex = nullptr;

	SDL_Texture*		circle_tex = nullptr;

	SDL_Texture*		left_flipper_tex = nullptr;
	SDL_Texture*		right_flipper_tex = nullptr;


	//Audio
	uint flipper_sound;
};
