#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"
#include "ChainPoints.h"
#include "ModuleWindow.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	


	//Load Textures
	background_tex = App->textures->Load("Sprites/clean_background.png");
	left_piece1_tex = App->textures->Load("Sprites/left_piece1.png");
	right_piece1_tex = App->textures->Load("Sprites/right_piece1.png");
	left_piece2_tex = App->textures->Load("Sprites/left_piece2.png");
	right_piece2_tex = App->textures->Load("Sprites/right_piece2.png");
	left_piece2_on_tex = App->textures->Load("Sprites/left_piece2_on.png");
	right_piece2_on_tex = App->textures->Load("Sprites/right_piece2_on.png");

	left_wheel_piece_tex = App->textures->Load("Sprites/left_wheel_piece.png");
	right_wheel_piece_tex = App->textures->Load("Sprites/right_wheel_piece.png");

	circle_tex = App->textures->Load("Sprites/circle.png");
	piece3_tex = App->textures->Load("Sprites/piece3.png");
	piece3_on_tex = App->textures->Load("Sprites/piece3_on.png");

	circle_tex_green = App->textures->Load("Sprites/green_light_off.png");
	circle_tex_green_on = App->textures->Load("Sprites/green_light_on.png");

	circle_tex_red = App->textures->Load("Sprites/red_light_off.png");
	circle_tex_red_on = App->textures->Load("Sprites/red_light_on.png");

	hole_tex = App->textures->Load("Sprites/empty_hole.png");
	hole_ball_tex = App->textures->Load("Sprites/full_hole.png");


	//Audio
	piece2_sound = App->audio->LoadFx("Audio/piece2.wav");
	piece3_sound = App->audio->LoadFx("Audio/piece3.wav");
	bumper_sound = App->audio->LoadFx("Audio/bumper.wav");
	hole_sound = App->audio->LoadFx("Audio/hole.wav");
	green_light_sound = App->audio->LoadFx("Audio/green_and_red.wav");
	red_light_sound = App->audio->LoadFx("Audio/green_and_red.wav");
	
	music_sound = App->audio->LoadFx("Audio/music.wav");
	
	//Music

	App->audio->PlayFx(music_sound);

	//Adding physic Background 
	background = App->physics->CreateStaticChain(25, 34, background_points, 172);

	//top static elements
	left_piece1 = App->physics->CreateStaticChain(60, 441, left_piece1_points, 18);
	right_piece1 = App->physics->CreateStaticChain(247, 441, right_piece1_points, 16);
	left_piece2 = App->physics->CreateStaticChain(82, 436, left_piece2_points, 18);
	right_piece2 = App->physics->CreateStaticChain(247, 436, right_piece2_points, 18);
	left_wheel_piece = App->physics->CreateStaticChain(67, 90, left_wheel_piece_points, 48);
	right_wheel_piece = App->physics->CreateStaticChain(235, 90, right_wheel_piece_points, 50);

	//bot static elements
	left_piece1_bot = App->physics->CreateStaticChain(59, 940, left_piece1_points, 18);
	right_piece1_bot = App->physics->CreateStaticChain(246, 940, right_piece1_points, 16);
	left_piece2_bot = App->physics->CreateStaticChain(82, 935, left_piece2_points, 18);
	right_piece2_bot = App->physics->CreateStaticChain(247, 935, right_piece2_points, 18);
	

	//Actions elements
	circle_1 = App->physics->CreateStaticCircle(79 + circle_radio, 711 + circle_radio, circle_radio);
	circle_2 = App->physics->CreateStaticCircle(133 + circle_radio, 656 + circle_radio, circle_radio);
	circle_3 = App->physics->CreateStaticCircle(133 + circle_radio, 774 + circle_radio, circle_radio);
	circle_4 = App->physics->CreateStaticCircle(213 + circle_radio, 656 + circle_radio, circle_radio);
	circle_5 = App->physics->CreateStaticCircle(213 + circle_radio, 774 + circle_radio, circle_radio);
	circle_6 = App->physics->CreateStaticCircle(266 + circle_radio, 711 + circle_radio, circle_radio);
	circle_7 = App->physics->CreateStaticCircle(100 + circle_radio, 395 + circle_radio, circle_radio);
	circle_8 = App->physics->CreateStaticCircle(124 + circle_radio, 204 + circle_radio, circle_radio);
	circle_9 = App->physics->CreateStaticCircle(172 + circle_radio, 319 + circle_radio, circle_radio);
	circle_10 = App->physics->CreateStaticCircle(222 + circle_radio, 204 + circle_radio, circle_radio);
	circle_11 = App->physics->CreateStaticCircle(244 + circle_radio, 395 + circle_radio, circle_radio);

	piece3_1 = App->physics->CreateStaticChain(84, 633, piece3_points, 16);
	piece3_2 = App->physics->CreateStaticChain(113, 609, piece3_points, 16);
	piece3_3 = App->physics->CreateStaticChain(246, 609, piece3_points, 16);
	piece3_4 = App->physics->CreateStaticChain(275, 633, piece3_points, 16);
	piece3_5 = App->physics->CreateStaticChain(137, 142, piece3_points, 16);
	piece3_6 = App->physics->CreateStaticChain(164, 126, piece3_points, 16);
	piece3_7 = App->physics->CreateStaticChain(207, 126, piece3_points, 16);
	piece3_8 = App->physics->CreateStaticChain(236, 142, piece3_points, 16);

	green_light_off_1 = App->physics->CreateCircleSensor(73 + circle_radio_green, 333 + circle_radio_green, circle_radio_green);
	green_light_off_2 = App->physics->CreateCircleSensor(73 + circle_radio_green, 352 + circle_radio_green, circle_radio_green);
	green_light_off_3 = App->physics->CreateCircleSensor(73 + circle_radio_green, 372 + circle_radio_green, circle_radio_green);

	green_light_off_4 = App->physics->CreateCircleSensor(280 + circle_radio_green, 333 + circle_radio_green, circle_radio_green);
	green_light_off_5 = App->physics->CreateCircleSensor(280 + circle_radio_green, 352 + circle_radio_green, circle_radio_green);
	green_light_off_6 = App->physics->CreateCircleSensor(280 + circle_radio_green, 372 + circle_radio_green, circle_radio_green);

	green_light_off_7 = App->physics->CreateCircleSensor(81 + circle_radio_green, 832 + circle_radio_green, circle_radio_green);
	green_light_off_8 = App->physics->CreateCircleSensor(81 + circle_radio_green, 852 + circle_radio_green, circle_radio_green);
	green_light_off_9 = App->physics->CreateCircleSensor(81 + circle_radio_green, 872 + circle_radio_green, circle_radio_green);

	green_light_off_10 = App->physics->CreateCircleSensor(280 + circle_radio_green, 832 + circle_radio_green, circle_radio_green);
	green_light_off_11 = App->physics->CreateCircleSensor(280 + circle_radio_green, 852 + circle_radio_green, circle_radio_green);
	green_light_off_12 = App->physics->CreateCircleSensor(280 + circle_radio_green, 872 + circle_radio_green, circle_radio_green);

	green_light_off_13 = App->physics->CreateCircleSensor(178 + circle_radio_green, 695 + circle_radio_green, circle_radio_green);
	green_light_off_14 = App->physics->CreateCircleSensor(178 + circle_radio_green, 750 + circle_radio_green, circle_radio_green);

	green_light_off_15 = App->physics->CreateCircleSensor(95 + circle_radio_green, 600 + circle_radio_green, circle_radio_green);
	green_light_off_16 = App->physics->CreateCircleSensor(125 + circle_radio_green, 580 + circle_radio_green, circle_radio_green);

	green_light_off_17 = App->physics->CreateCircleSensor(261 + circle_radio_green, 598 + circle_radio_green, circle_radio_green);
	green_light_off_18 = App->physics->CreateCircleSensor(230 + circle_radio_green, 580 + circle_radio_green, circle_radio_green);	

	hole_bot = App->physics->CreateCircleSensor(175 + circle_hole, 618 + circle_hole, circle_hole);
	hole_top = App->physics->CreateCircleSensor(181 + circle_hole, 152 + circle_hole, circle_hole);

	hole_left = App->physics->CreateCircleSensor(63 + circle_hole, 406 + circle_hole, circle_hole);
	hole_right = App->physics->CreateCircleSensor(285 + circle_hole, 406 + circle_hole, circle_hole);

	red_light_off_1 = App->physics->CreateCircleSensor(55 + circle_radio_green, 173 + circle_radio_green, circle_radio_green);
	red_light_off_2 = App->physics->CreateCircleSensor(63 + circle_radio_green, 143 + circle_radio_green, circle_radio_green);
	red_light_off_3 = App->physics->CreateCircleSensor(77 + circle_radio_green, 118 + circle_radio_green, circle_radio_green);
	red_light_off_4 = App->physics->CreateCircleSensor(98 + circle_radio_green, 100 + circle_radio_green, circle_radio_green);

	red_light_off_5 = App->physics->CreateCircleSensor(313 + circle_radio_green, 173 + circle_radio_green, circle_radio_green);
	red_light_off_6 = App->physics->CreateCircleSensor(303 + circle_radio_green, 143 + circle_radio_green, circle_radio_green);
	red_light_off_7 = App->physics->CreateCircleSensor(288 + circle_radio_green, 118 + circle_radio_green, circle_radio_green);
	red_light_off_8 = App->physics->CreateCircleSensor(267 + circle_radio_green, 100 + circle_radio_green, circle_radio_green);

	red_light_off_9 = App->physics->CreateCircleSensor(115 + circle_radio_green, 289 + circle_radio_green, circle_radio_green);
	red_light_off_10 = App->physics->CreateCircleSensor(133 + circle_radio_green, 249 + circle_radio_green, circle_radio_green);
	red_light_off_11 = App->physics->CreateCircleSensor(178 + circle_radio_green, 231 + circle_radio_green, circle_radio_green);
	red_light_off_12 = App->physics->CreateCircleSensor(218 + circle_radio_green, 249 + circle_radio_green, circle_radio_green);
	red_light_off_13 = App->physics->CreateCircleSensor(235 + circle_radio_green, 289 + circle_radio_green, circle_radio_green);


	left_piece2_action = App->physics->CreateStaticCircle(107, 465, 16);
	right_piece2_action = App->physics->CreateStaticCircle(270, 465, 16);

	left_piece2_bot_action = App->physics->CreateStaticCircle(107, 965, 16);
	right_piece2_bot_action = App->physics->CreateStaticCircle(270, 965, 16);
	


	return ret;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(background_tex);
	App->textures->Unload(left_piece1_tex);
	App->textures->Unload(right_piece1_tex);
	App->textures->Unload(left_piece2_tex);
	App->textures->Unload(right_piece2_tex);
	App->textures->Unload(left_wheel_piece_tex);
	App->textures->Unload(right_wheel_piece_tex);
	App->textures->Unload(circle_tex_green);
	App->textures->Unload(circle_tex_green_on);
	App->textures->Unload(circle_tex_red);
	App->textures->Unload(circle_tex_red_on);
	App->textures->Unload(hole_tex);
	App->textures->Unload(hole_ball_tex);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{

	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	// All draw functions ------------------------------------------------------
	//Background 
	App->renderer->Blit(background_tex, METERS_TO_PIXELS(background->body->GetPosition().x) - 25, METERS_TO_PIXELS(background->body->GetPosition().y) - 34);

	//Top static elements
	App->renderer->Blit(left_piece1_tex, METERS_TO_PIXELS(left_piece1->body->GetPosition().x), METERS_TO_PIXELS(left_piece1->body->GetPosition().y));
	App->renderer->Blit(right_piece1_tex, METERS_TO_PIXELS(right_piece1->body->GetPosition().x), METERS_TO_PIXELS(right_piece1->body->GetPosition().y));
	App->renderer->Blit(left_piece2_tex, METERS_TO_PIXELS(left_piece2->body->GetPosition().x), METERS_TO_PIXELS(left_piece2->body->GetPosition().y));
	App->renderer->Blit(right_piece2_tex, METERS_TO_PIXELS(right_piece2->body->GetPosition().x), METERS_TO_PIXELS(right_piece2->body->GetPosition().y));

	App->renderer->Blit(left_wheel_piece_tex, METERS_TO_PIXELS(left_wheel_piece->body->GetPosition().x), METERS_TO_PIXELS(left_wheel_piece->body->GetPosition().y));
	App->renderer->Blit(right_wheel_piece_tex, METERS_TO_PIXELS(right_wheel_piece->body->GetPosition().x), METERS_TO_PIXELS(right_wheel_piece->body->GetPosition().y));

	App->renderer->Blit(hole_tex, METERS_TO_PIXELS(hole_left->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_left->body->GetPosition().y) - circle_hole);
	App->renderer->Blit(hole_tex, METERS_TO_PIXELS(hole_right->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_right->body->GetPosition().y) - circle_hole);

	//Bot static elements
	App->renderer->Blit(left_piece1_tex, METERS_TO_PIXELS(left_piece1_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece1_bot->body->GetPosition().y));
	App->renderer->Blit(right_piece1_tex, METERS_TO_PIXELS(right_piece1_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece1_bot->body->GetPosition().y));

	
	//Circles
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_1->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_1->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_2->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_2->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_3->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_3->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_4->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_4->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_5->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_5->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_6->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_6->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_7->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_7->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_8->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_8->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_9->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_9->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_10->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_10->body->GetPosition().y) - circle_radio);
	App->renderer->Blit(circle_tex, METERS_TO_PIXELS(circle_11->body->GetPosition().x) - circle_radio, METERS_TO_PIXELS(circle_11->body->GetPosition().y) - circle_radio);
	

	//ACTION ELEMENTS
	//Piece2-----------------------------------
	if (left_piece2_activated) {
		App->renderer->Blit(left_piece2_on_tex, METERS_TO_PIXELS(left_piece2->body->GetPosition().x), METERS_TO_PIXELS(left_piece2->body->GetPosition().y));
		if (cont_left_piece2 <= 0) {
			left_piece2_activated = false;
			cont_left_piece2 = 20;
		}
		cont_left_piece2--;
	}
	else
		App->renderer->Blit(left_piece2_tex, METERS_TO_PIXELS(left_piece2->body->GetPosition().x), METERS_TO_PIXELS(left_piece2->body->GetPosition().y));

	if (right_piece2_activated) {
		App->renderer->Blit(right_piece2_on_tex, METERS_TO_PIXELS(right_piece2->body->GetPosition().x), METERS_TO_PIXELS(right_piece2->body->GetPosition().y));
		if (cont_right_piece2 <= 0) {
			right_piece2_activated = false;
			cont_right_piece2 = 20;
		}
		cont_right_piece2--;
	}
	else
		App->renderer->Blit(right_piece2_tex, METERS_TO_PIXELS(right_piece2->body->GetPosition().x), METERS_TO_PIXELS(right_piece2->body->GetPosition().y));

	if (left_piece2_bot_activated) {
		App->renderer->Blit(left_piece2_on_tex, METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().y));
		if (cont_left_piece2_bot <= 0) {
			left_piece2_bot_activated = false;
			cont_left_piece2_bot = 20;
		}
		cont_left_piece2_bot--;
	}
	else
		App->renderer->Blit(left_piece2_tex, METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().y));

	if (right_piece2_bot_activated) {
		App->renderer->Blit(right_piece2_on_tex, METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().y));
		if (cont_right_piece2_bot <= 0) {
			right_piece2_bot_activated = false;
			cont_right_piece2_bot = 20;
		}
		cont_right_piece2_bot--;
	}
	else
		App->renderer->Blit(right_piece2_tex, METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().y));

	//Piece3-------------------------------------
	if (piece3_1_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_1->body->GetPosition().x), METERS_TO_PIXELS(piece3_1->body->GetPosition().y));
		if (cont_piece3_1 <= 0) {
			piece3_1_activated = false;
			cont_piece3_1 = 20;
		}
		cont_piece3_1--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_1->body->GetPosition().x), METERS_TO_PIXELS(piece3_1->body->GetPosition().y));

	if (piece3_2_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_2->body->GetPosition().x), METERS_TO_PIXELS(piece3_2->body->GetPosition().y));
		if (cont_piece3_2 <= 0) {
			piece3_2_activated = false;
			cont_piece3_2 = 20;
		}
		cont_piece3_2--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_2->body->GetPosition().x), METERS_TO_PIXELS(piece3_2->body->GetPosition().y));

	if (piece3_3_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_3->body->GetPosition().x), METERS_TO_PIXELS(piece3_3->body->GetPosition().y));
		if (cont_piece3_3 <= 0) {
			piece3_3_activated = false;
			cont_piece3_3 = 20;
		}
		cont_piece3_3--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_3->body->GetPosition().x), METERS_TO_PIXELS(piece3_3->body->GetPosition().y));

	if (piece3_4_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_4->body->GetPosition().x), METERS_TO_PIXELS(piece3_4->body->GetPosition().y));
		if (cont_piece3_4 <= 0) {
			piece3_4_activated = false;
			cont_piece3_4 = 20;
		}
		cont_piece3_4--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_4->body->GetPosition().x), METERS_TO_PIXELS(piece3_4->body->GetPosition().y));

	if (piece3_5_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_5->body->GetPosition().x), METERS_TO_PIXELS(piece3_5->body->GetPosition().y));
		if (cont_piece3_5 <= 0) {
			piece3_5_activated = false;
			cont_piece3_5 = 20;
		}
		cont_piece3_5--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_5->body->GetPosition().x), METERS_TO_PIXELS(piece3_5->body->GetPosition().y));

	if (piece3_6_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_6->body->GetPosition().x), METERS_TO_PIXELS(piece3_6->body->GetPosition().y));
		if (cont_piece3_6 <= 0) {
			piece3_6_activated = false;
			cont_piece3_6 = 20;
		}
		cont_piece3_6--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_6->body->GetPosition().x), METERS_TO_PIXELS(piece3_6->body->GetPosition().y));

	if (piece3_7_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_7->body->GetPosition().x), METERS_TO_PIXELS(piece3_7->body->GetPosition().y));
		if (cont_piece3_7 <= 0) {
			piece3_7_activated = false;
			cont_piece3_7 = 20;
		}
		cont_piece3_7--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_7->body->GetPosition().x), METERS_TO_PIXELS(piece3_7->body->GetPosition().y));

	if (piece3_8_activated) {
		App->renderer->Blit(piece3_on_tex, METERS_TO_PIXELS(piece3_8->body->GetPosition().x), METERS_TO_PIXELS(piece3_8->body->GetPosition().y));
		if (cont_piece3_8 <= 0) {
			piece3_8_activated = false;
			cont_piece3_8 = 20;
		}
		cont_piece3_8--;
	}
	else
		App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_8->body->GetPosition().x), METERS_TO_PIXELS(piece3_8->body->GetPosition().y));

	//Hole-------------------------------
	if (ball_in_hole_bot) {
		App->renderer->Blit(hole_ball_tex, METERS_TO_PIXELS(hole_bot->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_bot->body->GetPosition().y) - circle_hole);
		App->player->StopBall(1);
		if (hole_bot_cont <= 0) {
			ball_in_hole_bot = false;
			App->player->PlayBall(1);
			hole_bot_cont = 150;
		}
		hole_bot_cont--;
	}
	else
		App->renderer->Blit(hole_tex, METERS_TO_PIXELS(hole_bot->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_bot->body->GetPosition().y) - circle_hole);

	if (ball_in_hole_top) {
		App->renderer->Blit(hole_ball_tex, METERS_TO_PIXELS(hole_top->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_top->body->GetPosition().y) - circle_hole);
		App->player->StopBall(2);
		if (hole_top_cont <= 0) {
			ball_in_hole_top = false;
			App->player->PlayBall(2);
			hole_top_cont = 150;
		}
		hole_top_cont--;
	}
	else
		App->renderer->Blit(hole_tex, METERS_TO_PIXELS(hole_top->body->GetPosition().x) - circle_hole, METERS_TO_PIXELS(hole_top->body->GetPosition().y) - circle_hole);

	
	//Green Light-----------------------
	//Top
	if (green_light_off_activated_1) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_1 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}else if (cont_green_light_1 <= 0) {
			green_light_off_activated_1 = false;
			green_cont_top--;
			cont_green_light_1 = 2000;
		}
		cont_green_light_1--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_2) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_2 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_2 <= 0) {
			green_light_off_activated_2 = false;
			green_cont_top--;
			cont_green_light_2 = 2000;
		}
		cont_green_light_2--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_3) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_3 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_3 <= 0) {
			green_light_off_activated_3 = false;
			green_cont_top--;
			cont_green_light_3 = 2000;
		}
		cont_green_light_3--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_4) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_4 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_4 <= 0) {
			green_light_off_activated_4 = false;
			green_cont_top--;
			cont_green_light_4 = 2000;
		}
		cont_green_light_4--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_5) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_5 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_5 <= 0) {
			green_light_off_activated_5 = false;
			green_cont_top--;
			cont_green_light_5 = 2000;
		}
		cont_green_light_5--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_6) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_6 == 1999) {
			score += 200;
			green_cont_top++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_6 <= 0) {
			green_light_off_activated_6 = false;
			green_cont_top--;
			cont_green_light_6 = 2000;
		}
		cont_green_light_6--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().y) - circle_radio_green);
	//Bot
	if (green_light_off_activated_7) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_7 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_7 <= 0) {
			green_light_off_activated_7 = false;
			green_cont_bot--;
			cont_green_light_7 = 2000;
		}
		cont_green_light_7--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_8) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_8 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_8 <= 0) {
			green_light_off_activated_8 = false;
			green_cont_bot--;
			cont_green_light_8 = 2000;
		}
		cont_green_light_8--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_9) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_9 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_9 <= 0) {
			green_light_off_activated_9 = false;
			green_cont_bot--;
			cont_green_light_9 = 2000;
		}
		cont_green_light_9--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_10) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_10 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_10 <= 0) {
			green_light_off_activated_10 = false;
			green_cont_bot--;
			cont_green_light_10 = 2000;
		}
		cont_green_light_10--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_11) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_11 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_11 <= 0) {
			green_light_off_activated_11 = false;
			green_cont_bot--;
			cont_green_light_11 = 2000;
		}
		cont_green_light_11--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_12) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_12 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_12 <= 0) {
			green_light_off_activated_12 = false;
			green_cont_bot--;
			cont_green_light_12 = 2000;
		}
		cont_green_light_12--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_13) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_13 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_13 <= 0) {
			green_light_off_activated_13 = false;
			green_cont_bot--;
			cont_green_light_13 = 2000;
		}
		cont_green_light_13--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_14) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_14 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_14 <= 0) {
			green_light_off_activated_14 = false;
			green_cont_bot--;
			cont_green_light_14 = 2000;
		}
		cont_green_light_14--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_15) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_15 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_15 <= 0) {
			green_light_off_activated_15 = false;
			green_cont_bot--;
			cont_green_light_15 = 2000;
		}
		cont_green_light_15--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_16) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_16 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_16 <= 0) {
			green_light_off_activated_16 = false;
			green_cont_bot--;
			cont_green_light_16 = 2000;
		}
		cont_green_light_16--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_17) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_17 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_17 <= 0) {
			green_light_off_activated_17 = false;
			green_cont_bot--;
			cont_green_light_17 = 2000;
		}
		cont_green_light_17--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_18) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().y) - circle_radio_green);
		if (cont_green_light_18 == 1999) {
			score += 200;
			green_cont_bot++;
			App->audio->PlayFx(green_light_sound);
		}
		else if (cont_green_light_18 <= 0) {
			green_light_off_activated_18 = false;
			green_cont_bot--;
			cont_green_light_18 = 2000;
		}
		cont_green_light_18--;
	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().y) - circle_radio_green);

	

	//Red Light ------------------------------------------------
	//Left
	if (red_light_off_activated_1) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_1->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_1 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_left++;
			score += 200;
		}else if (cont_red_light_1 <= 0) {
			red_light_off_activated_1 = false;
			red_cont_left--;
			cont_red_light_1 = 2000;
		}
		cont_red_light_1--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_1->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_2) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_2->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_2 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_left++;
			score += 200;
		}
		else if (cont_red_light_2 <= 0) {
			red_light_off_activated_2 = false;
			red_cont_left--;
			cont_red_light_2 = 2000;
		}
		cont_red_light_2--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_2->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_3) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_3->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_3 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_left++;
			score += 200;
		}
		else if (cont_red_light_3 <= 0) {
			red_light_off_activated_3 = false;
			red_cont_left--;
			cont_red_light_3 = 2000;
		}
		cont_red_light_3--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_3->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_4) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_4->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_4 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_left++;
			score += 200;
		}
		else if (cont_red_light_4 <= 0) {
			red_light_off_activated_4 = false;
			red_cont_left--;
			cont_red_light_4 = 2000;
		}
		cont_red_light_4--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_4->body->GetPosition().y) - circle_radio_green);
	//Right
	if (red_light_off_activated_5) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_5->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_5 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_right++;
			score += 200;
		}
		else if (cont_red_light_5 <= 0) {
			red_light_off_activated_5 = false;
			red_cont_right--;
			cont_red_light_5 = 2000;
		}
		cont_red_light_5--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_5->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_6) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_6->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_6 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_right++;
			score += 200;
		}
		else if (cont_red_light_6 <= 0) {
			red_light_off_activated_6 = false;
			red_cont_right--;
			cont_red_light_6 = 2000;
		}
		cont_red_light_6--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_6->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_7) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_7->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_7 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_right++;
			score += 200;
		}
		else if (cont_red_light_7 <= 0) {
			red_light_off_activated_7 = false;
			red_cont_right--;
			cont_red_light_7 = 2000;
		}
		cont_red_light_7--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_7->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_8) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_8->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_8 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_right++;
			score += 200;
		}
		else if (cont_red_light_8 <= 0) {
			red_light_off_activated_8 = false;
			red_cont_right--;
			cont_red_light_8 = 2000;
		}
		cont_red_light_8--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_8->body->GetPosition().y) - circle_radio_green);
	//Mid
	if (red_light_off_activated_9) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_9->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_9 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_mid++;
			score += 200;
		}
		else if (cont_red_light_9 <= 0) {
			red_light_off_activated_9 = false;
			red_cont_mid--;
			cont_red_light_9 = 2000;
		}
		cont_red_light_9--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_9->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_10) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_10->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_10 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_mid++;
			score += 200;
		}
		else if (cont_red_light_10 <= 0) {
			red_light_off_activated_10 = false;
			red_cont_mid--;
			cont_red_light_10 = 2000;
		}
		cont_red_light_10--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_10->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_11) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_11->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_11 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_mid++;
			score += 200;
		}
		else if (cont_red_light_11 <= 0) {
			red_light_off_activated_11 = false;
			red_cont_mid--;
			cont_red_light_11 = 2000;
		}
		cont_red_light_11--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_11->body->GetPosition().y) - circle_radio_green);

	if (red_light_off_activated_12) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_12->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_12 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_mid++;
			score += 200;
		}
		else if (cont_red_light_12 <= 0) {
			red_light_off_activated_12 = false;
			red_cont_mid--;
			cont_red_light_12 = 2000;
		}
		cont_red_light_12--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_12->body->GetPosition().y) - circle_radio_green);
	
	if (red_light_off_activated_13) {
		App->renderer->Blit(circle_tex_red_on, METERS_TO_PIXELS(red_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_13->body->GetPosition().y) - circle_radio_green);
		if (cont_red_light_13 == 1999) {
			App->audio->PlayFx(red_light_sound);
			red_cont_mid++;
			score += 200;
		}
		else if (cont_red_light_13 <= 0) {
			red_light_off_activated_13 = false;
			red_cont_mid--;
			cont_red_light_13 = 2000;
		}
		cont_red_light_13--;
	}
	else
		App->renderer->Blit(circle_tex_red, METERS_TO_PIXELS(red_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(red_light_off_13->body->GetPosition().y) - circle_radio_green);


	




	//SCORE CONDITIONS

	//Green score combos

	if (green_cont_bot == 6 && ball_in_hole_bot == true) 
		score += 12000;
	//if (green_cont_bot < 6 && button_bot_pressed == true) score += (500 * green_cont_bot);

	if (green_cont_bot == 12 && ball_in_hole_bot == true)
	{
		score += 48000;
		life_ball++;
		//light_eyes_activated = true;
	
	}

	if (green_cont_top == 6 && ball_in_hole_top == true) score += 48000;
		
	//if (green_cont_top < 6 && button_top_pressed == true) score += (500 * green_cont_top);



	//Red score combos

	//if(red_cont_left == 4 && button_left_pressed == true) score += 10000;
	//if (red_cont_right == 4 && button_right_pressed == true) score += 10000;

	if(red_cont_mid == 5 && ball_in_hole_top == true)
	{
		score += 100000;
	//	boss_hit++;
		life_ball++;
	}

	//if (red_cont_mid == 5 && ball_in_hole_top == true && boss_hit == 3) 
	//{

	
		
	

	

	

	

	//Set title as Score-------------------------------------------------

	p2SString title("Score: %i  Lifes: %i", score, life_ball);
	if(score > 200000)
		title = ("YOU WIN!! press F3 to try again...");
	App->window->SetTitle(title.GetString());

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB, b2Contact* contact)
{
	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);

	if (bodyA == App->player->ball || bodyB == App->player->ball) {
		//Piece2----------------------------------
		if (bodyA == left_piece2_action || bodyB == left_piece2_action) {
			App->player->ball->body->ApplyForceToCenter(piece2_force * worldManifold.normal, true);
			left_piece2_activated = true;
			App->audio->PlayFx(piece2_sound);
			score += 100;
		}else if (bodyA == right_piece2_action || bodyB == right_piece2_action) {
			App->player->ball->body->ApplyForceToCenter(piece2_force * worldManifold.normal, true);
			right_piece2_activated = true;
			App->audio->PlayFx(piece2_sound);
			score += 100;
		}else if (bodyA == left_piece2_bot_action || bodyB == left_piece2_bot_action) {
			App->player->ball->body->ApplyForceToCenter(piece2_force * worldManifold.normal, true);
			left_piece2_bot_activated = true;
			App->audio->PlayFx(piece2_sound);
			score += 100;
		}else if (bodyA == right_piece2_bot_action || bodyB == right_piece2_bot_action) {
			App->player->ball->body->ApplyForceToCenter(piece2_force * worldManifold.normal, true);
			right_piece2_bot_activated = true;
			App->audio->PlayFx(piece2_sound);
			score += 100;
		}//Piece3-------------------------------
		else if (bodyA == piece3_1 || bodyB == piece3_1) {
			piece3_1_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_2 || bodyB == piece3_2) {
			piece3_2_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_3 || bodyB == piece3_3) {
			piece3_3_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_4 || bodyB == piece3_4) {
			piece3_4_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_5 || bodyB == piece3_5) {
			piece3_5_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_6 || bodyB == piece3_6) {
			piece3_6_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_7 || bodyB == piece3_7) {
			piece3_7_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}
		else if (bodyA == piece3_8 || bodyB == piece3_8) {
			piece3_8_activated = true;
			App->player->ball->body->ApplyForceToCenter(piece3_force * worldManifold.normal, true);
			App->audio->PlayFx(piece3_sound);
			score += 100;
		}//Bumpers--------------------------------
		else if (bodyA == circle_1 || bodyB == circle_1) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_2 || bodyB == circle_2) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_3 || bodyB == circle_3) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_4 || bodyB == circle_4) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_5 || bodyB == circle_5) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_6 || bodyB == circle_6) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_7 || bodyB == circle_7) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_8 || bodyB == circle_8) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_9 || bodyB == circle_9) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_10 || bodyB == circle_10) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}
		else if (bodyA == circle_11 || bodyB == circle_11) {
			App->player->ball->body->ApplyForceToCenter(circle_force * worldManifold.normal, true);
			App->audio->PlayFx(bumper_sound);
			score += 100;
		}//Hole----------------------------------
		else if (bodyA == hole_bot || bodyB == hole_bot) {
			ball_in_hole_bot = true;
			App->audio->PlayFx(hole_sound);
			score += 200;
		}
		else if (bodyA == hole_top || bodyB == hole_top) {
			ball_in_hole_top = true;
			App->audio->PlayFx(hole_sound);
			score += 200;
		}//Green lights--------------------------------
		else if (bodyA == green_light_off_1 || bodyB == green_light_off_1) {
			green_light_off_activated_1 = true;
		}
		else if (bodyA == green_light_off_2 || bodyB == green_light_off_2) {
			green_light_off_activated_2 = true;
		}
		else if (bodyA == green_light_off_3 || bodyB == green_light_off_3) {
			green_light_off_activated_3 = true;
		}
		else if (bodyA == green_light_off_4 || bodyB == green_light_off_4) {
			green_light_off_activated_4 = true;
		}
		else if (bodyA == green_light_off_5 || bodyB == green_light_off_5) {
			green_light_off_activated_5 = true;
		}
		else if (bodyA == green_light_off_6 || bodyB == green_light_off_6) {
			green_light_off_activated_6 = true;
		}
		else if (bodyA == green_light_off_7 || bodyB == green_light_off_7) {
			green_light_off_activated_7 = true;
		}
		else if (bodyA == green_light_off_8 || bodyB == green_light_off_8) {
			green_light_off_activated_8 = true;
		}
		else if (bodyA == green_light_off_9 || bodyB == green_light_off_9) {
			green_light_off_activated_9 = true;
		}
		else if (bodyA == green_light_off_10 || bodyB == green_light_off_10) {
			green_light_off_activated_10 = true;
		}
		else if (bodyA == green_light_off_11 || bodyB == green_light_off_11) {
			green_light_off_activated_11 = true;
		}
		else if (bodyA == green_light_off_12 || bodyB == green_light_off_12) {
			green_light_off_activated_12 = true;
		}
		else if (bodyA == green_light_off_13 || bodyB == green_light_off_13) {
			green_light_off_activated_13 = true;
		}
		else if (bodyA == green_light_off_14 || bodyB == green_light_off_14) {
			green_light_off_activated_14 = true;
		}
		else if (bodyA == green_light_off_15 || bodyB == green_light_off_15) {
			green_light_off_activated_15 = true;
		}
		else if (bodyA == green_light_off_16 || bodyB == green_light_off_16) {
			green_light_off_activated_16 = true;
		}
		else if (bodyA == green_light_off_17 || bodyB == green_light_off_17) {
			green_light_off_activated_17 = true;
		}
		else if (bodyA == green_light_off_18 || bodyB == green_light_off_18) {
			green_light_off_activated_18 = true;
		}//Red lights activation-------------------------------------
		else if (bodyA == red_light_off_1 || bodyB == red_light_off_1) {
			red_light_off_activated_1 = true;
		}
		else if (bodyA == red_light_off_2 || bodyB == red_light_off_2) {
			red_light_off_activated_2 = true;
		}
		else if (bodyA == red_light_off_3 || bodyB == red_light_off_3) {
			red_light_off_activated_3 = true;
		}
		else if (bodyA == red_light_off_4 || bodyB == red_light_off_4) {
			red_light_off_activated_4 = true;
		}
		else if (bodyA == red_light_off_5 || bodyB == red_light_off_5) {
			red_light_off_activated_5 = true;
		}
		else if (bodyA == red_light_off_6 || bodyB == red_light_off_6) {
			red_light_off_activated_6 = true;
		}
		else if (bodyA == red_light_off_7 || bodyB == red_light_off_7) {
			red_light_off_activated_7 = true;
		}
		else if (bodyA == red_light_off_8 || bodyB == red_light_off_8) {
			red_light_off_activated_8 = true;
		}
		else if (bodyA == red_light_off_9 || bodyB == red_light_off_9) {
			red_light_off_activated_9 = true;
		}
		else if (bodyA == red_light_off_10 || bodyB == red_light_off_10) {
			red_light_off_activated_10 = true;
		}
		else if (bodyA == red_light_off_11 || bodyB == red_light_off_11) {
			red_light_off_activated_11 = true;
		}
		else if (bodyA == red_light_off_12 || bodyB == red_light_off_12) {
			red_light_off_activated_12 = true;
		}
		else if (bodyA == red_light_off_13 || bodyB == red_light_off_13) {
			red_light_off_activated_13 = true;
		}


		
	}
}
