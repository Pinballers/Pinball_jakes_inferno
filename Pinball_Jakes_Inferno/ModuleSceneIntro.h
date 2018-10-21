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
	PhysBody*			circle_1 = nullptr;
	PhysBody*			circle_2 = nullptr;
	PhysBody*			circle_3 = nullptr;
	PhysBody*			circle_4 = nullptr;
	PhysBody*			circle_5 = nullptr;
	PhysBody*			circle_6 = nullptr;
	PhysBody*			circle_7 = nullptr;
	PhysBody*			circle_8 = nullptr;
	PhysBody*			circle_9 = nullptr;
	PhysBody*			circle_10 = nullptr;
	PhysBody*			circle_11 = nullptr;
	PhysBody*			piece3_1 = nullptr;
	PhysBody*			piece3_2 = nullptr;
	PhysBody*			piece3_3 = nullptr;
	PhysBody*			piece3_4 = nullptr;
	PhysBody*			piece3_5 = nullptr;
	PhysBody*			piece3_6 = nullptr;
	PhysBody*			piece3_7 = nullptr;
	PhysBody*			piece3_8 = nullptr;

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
	SDL_Texture*		piece3_tex = nullptr;

	SDL_Texture*		left_flipper_tex = nullptr;
	SDL_Texture*		right_flipper_tex = nullptr;


	//Audio
	uint flipper_sound;
};
