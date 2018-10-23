#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;
class b2Contact;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB, b2Contact* contact);

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

	PhysBody*			left_piece2_action = nullptr;
	PhysBody*			right_piece2_action = nullptr;
	PhysBody*			left_piece2_bot_action = nullptr;
	PhysBody*			right_piece2_bot_action = nullptr;

	PhysBody*			green_light_off_1 = nullptr;
	PhysBody*			green_light_off_2 = nullptr;
	PhysBody*			green_light_off_3 = nullptr;
	PhysBody*			green_light_off_4 = nullptr;
	PhysBody*			green_light_off_5 = nullptr;
	PhysBody*			green_light_off_6 = nullptr;
	PhysBody*			green_light_off_7 = nullptr;
	PhysBody*			green_light_off_8 = nullptr;
	PhysBody*			green_light_off_9 = nullptr;
	PhysBody*			green_light_off_10 = nullptr;
	PhysBody*			green_light_off_11 = nullptr;
	PhysBody*			green_light_off_12 = nullptr;
	PhysBody*			green_light_off_13 = nullptr;
	PhysBody*			green_light_off_14 = nullptr;
	PhysBody*			green_light_off_15 = nullptr;
	PhysBody*			green_light_off_16 = nullptr;
	PhysBody*			green_light_off_17 = nullptr;
	PhysBody*			green_light_off_18 = nullptr;

	


	//Sprites
	SDL_Texture*		background_tex = nullptr;
	SDL_Texture*		left_piece1_tex = nullptr;
	SDL_Texture*		right_piece1_tex = nullptr;
	SDL_Texture*		left_piece2_tex = nullptr;
	SDL_Texture*		left_piece2_on_tex = nullptr;
	SDL_Texture*		right_piece2_tex = nullptr;
	SDL_Texture*		right_piece2_on_tex = nullptr;
	SDL_Texture*		left_wheel_piece_tex = nullptr;
	SDL_Texture*		right_wheel_piece_tex = nullptr;
	

	SDL_Texture*		circle_tex = nullptr;

	SDL_Texture*		circle_tex_green = nullptr; 
	SDL_Texture*		circle_tex_green_on = nullptr;

	SDL_Texture*		piece3_tex = nullptr;
	SDL_Texture*		piece3_on_tex = nullptr;

	//Audio
	uint				bumper_sound;


private:
	int					circle_radio = 13;
	int					circle_radio_green = 8;

	bool				left_piece2_activated = false;
	bool				right_piece2_activated = false;
	bool				left_piece2_bot_activated = false;
	bool				right_piece2_bot_activated = false;

	bool				green_light_off_activated_1 = false;
	bool				green_light_off_activated_2 = false;
	bool				green_light_off_activated_3 = false;
	bool				green_light_off_activated_4 = false;
	bool				green_light_off_activated_5 = false;
	bool				green_light_off_activated_6 = false;
	bool				green_light_off_activated_7 = false;
	bool				green_light_off_activated_8 = false;
	bool				green_light_off_activated_9 = false;
	bool				green_light_off_activated_10 = false;
	bool				green_light_off_activated_11 = false;
	bool				green_light_off_activated_12 = false;
	bool				green_light_off_activated_13 = false;
	bool				green_light_off_activated_14 = false;
	bool				green_light_off_activated_15 = false;
	bool				green_light_off_activated_16 = false;
	bool				green_light_off_activated_17 = false;
	bool				green_light_off_activated_18 = false;


	bool				piece3_1_activated = false;
	bool				piece3_2_activated = false;
	bool				piece3_3_activated = false;
	bool				piece3_4_activated = false;
	bool				piece3_5_activated = false;
	bool				piece3_6_activated = false;
	bool				piece3_7_activated = false;
	bool				piece3_8_activated = false;

	int					cont_left_piece2 = 20;
	int					cont_right_piece2 = 20;
	int					cont_left_piece2_bot = 20;
	int					cont_right_piece2_bot = 20;
	int					cont_piece3_1 = 20;
	int					cont_piece3_2 = 20;
	int					cont_piece3_3 = 20;
	int					cont_piece3_4 = 20;
	int					cont_piece3_5 = 20;
	int					cont_piece3_6 = 20;
	int					cont_piece3_7 = 20;
	int					cont_piece3_8 = 20;


	uint				circle_force = 20;
	uint				piece3_force = 5;
	uint				piece2_force = 5;

	//int					cont_green_light_off_1 = 20;

};




