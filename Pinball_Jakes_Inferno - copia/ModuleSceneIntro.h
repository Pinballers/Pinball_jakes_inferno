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
	p2List<PhysBody*>	background;
	PhysBody*			left_flipper = nullptr;
	b2RevoluteJoint*	right_flipper_joint = nullptr;
	b2RevoluteJoint*	left_flipper_joint = nullptr;


	//Sprites
	SDL_Texture*		background_tex = nullptr;
	SDL_Texture*		left_flipper_tex = nullptr;
	SDL_Texture*		right_flipper_tex = nullptr;


	//Audio
	uint flipper_sound;
};
