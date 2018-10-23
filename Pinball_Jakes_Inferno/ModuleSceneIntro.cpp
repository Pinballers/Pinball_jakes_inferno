#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ChainPoints.h"
#include "ModulePlayer.h"

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
	background_tex = App->textures->Load("Sprites/out_structure_1.png");
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

	left_flipper_tex = App->textures->Load("Sprites/left_flipper.png");
	right_flipper_tex = App->textures->Load("Sprites/right_flipper.png");

	

	//Load Audio
	flipper_sound = App->audio->LoadFx("Audio/flipper_sound.wav");



	//Adding physic Background 
	background = App->physics->CreateStaticChain(25, 34, background_points, 172);

	//top static elements
	left_piece1 = App->physics->CreateStaticChain(59, 441, left_piece1_points, 18);
	right_piece1 = App->physics->CreateStaticChain(247, 441, right_piece1_points, 16);
	left_piece2 = App->physics->CreateStaticChain(82, 436, left_piece2_points, 18);
	right_piece2 = App->physics->CreateStaticChain(247, 436, right_piece2_points, 18);
	left_wheel_piece = App->physics->CreateStaticChain(67, 90, left_wheel_piece_points, 48);
	right_wheel_piece = App->physics->CreateStaticChain(235, 90, right_wheel_piece_points, 50);

	//bot static elements
	left_piece1_bot = App->physics->CreateStaticChain(59, 939, left_piece1_points, 18);
	right_piece1_bot = App->physics->CreateStaticChain(247, 939, right_piece1_points, 16);
	left_piece2_bot = App->physics->CreateStaticChain(82, 934, left_piece2_points, 18);
	right_piece2_bot = App->physics->CreateStaticChain(247, 934, right_piece2_points, 18);
	

	//Actions elements
	circle_1 = App->physics->CreateStaticCircle(78 + circle_radio, 711 + circle_radio, circle_radio);
	circle_2 = App->physics->CreateStaticCircle(132 + circle_radio, 656 + circle_radio, circle_radio);
	circle_3 = App->physics->CreateStaticCircle(132 + circle_radio, 774 + circle_radio, circle_radio);
	circle_4 = App->physics->CreateStaticCircle(212 + circle_radio, 656 + circle_radio, circle_radio);
	circle_5 = App->physics->CreateStaticCircle(212 + circle_radio, 774 + circle_radio, circle_radio);
	circle_6 = App->physics->CreateStaticCircle(265 + circle_radio, 711 + circle_radio, circle_radio);
	circle_7 = App->physics->CreateStaticCircle(99 + circle_radio, 395 + circle_radio, circle_radio);
	circle_8 = App->physics->CreateStaticCircle(123 + circle_radio, 204 + circle_radio, circle_radio);
	circle_9 = App->physics->CreateStaticCircle(171 + circle_radio, 319 + circle_radio, circle_radio);
	circle_10 = App->physics->CreateStaticCircle(221 + circle_radio, 204 + circle_radio, circle_radio);
	circle_11 = App->physics->CreateStaticCircle(243 + circle_radio, 395 + circle_radio, circle_radio);

	piece3_1 = App->physics->CreateStaticChain(83, 632, piece3_points, 16);
	piece3_2 = App->physics->CreateStaticChain(112, 608, piece3_points, 16);
	piece3_3 = App->physics->CreateStaticChain(245, 608, piece3_points, 16);
	piece3_4 = App->physics->CreateStaticChain(274, 632, piece3_points, 16);
	piece3_5 = App->physics->CreateStaticChain(136, 141, piece3_points, 16);
	piece3_6 = App->physics->CreateStaticChain(164, 126, piece3_points, 16);
	piece3_7 = App->physics->CreateStaticChain(207, 126, piece3_points, 16);
	piece3_8 = App->physics->CreateStaticChain(235, 141, piece3_points, 16);

	green_light_off_1 = App->physics->CreateCircleSensor(71 + circle_radio_green, 330 + circle_radio_green, circle_radio_green);
	green_light_off_2 = App->physics->CreateCircleSensor(71 + circle_radio_green, 350 + circle_radio_green, circle_radio_green);
	green_light_off_3 = App->physics->CreateCircleSensor(71 + circle_radio_green, 370 + circle_radio_green, circle_radio_green);

	green_light_off_4 = App->physics->CreateCircleSensor(282 + circle_radio_green, 330 + circle_radio_green, circle_radio_green);
	green_light_off_5 = App->physics->CreateCircleSensor(282 + circle_radio_green, 350 + circle_radio_green, circle_radio_green);
	green_light_off_6 = App->physics->CreateCircleSensor(282 + circle_radio_green, 370 + circle_radio_green, circle_radio_green);

	green_light_off_7 = App->physics->CreateCircleSensor(80 + circle_radio_green, 830 + circle_radio_green, circle_radio_green);
	green_light_off_8 = App->physics->CreateCircleSensor(80 + circle_radio_green, 850 + circle_radio_green, circle_radio_green);
	green_light_off_9 = App->physics->CreateCircleSensor(80 + circle_radio_green, 870 + circle_radio_green, circle_radio_green);

	green_light_off_10 = App->physics->CreateCircleSensor(282 + circle_radio_green, 830 + circle_radio_green, circle_radio_green);
	green_light_off_11 = App->physics->CreateCircleSensor(282 + circle_radio_green, 850 + circle_radio_green, circle_radio_green);
	green_light_off_12 = App->physics->CreateCircleSensor(282 + circle_radio_green, 870 + circle_radio_green, circle_radio_green);

	green_light_off_13 = App->physics->CreateCircleSensor(179 + circle_radio_green, 695 + circle_radio_green, circle_radio_green);
	green_light_off_14 = App->physics->CreateCircleSensor(179 + circle_radio_green, 745 + circle_radio_green, circle_radio_green);

	green_light_off_15 = App->physics->CreateCircleSensor(95 + circle_radio_green, 595 + circle_radio_green, circle_radio_green);
	green_light_off_16 = App->physics->CreateCircleSensor(125 + circle_radio_green, 580 + circle_radio_green, circle_radio_green);

	green_light_off_17 = App->physics->CreateCircleSensor(263 + circle_radio_green, 595 + circle_radio_green, circle_radio_green);
	green_light_off_18 = App->physics->CreateCircleSensor(227 + circle_radio_green, 580 + circle_radio_green, circle_radio_green);	


	left_piece2_action = App->physics->CreateCircleSensor(105, 465, 18);
	right_piece2_action = App->physics->CreateCircleSensor(270, 465, 18);

	left_piece2_bot_action = App->physics->CreateCircleSensor(105, 965, 18);
	right_piece2_bot_action = App->physics->CreateCircleSensor(270, 965, 18);
	
	
	

	//Flippers
	left_flipper = App->physics->CreateChain(115, 521, left_flipper_points, 14);
	left_flipper->body->SetGravityScale(0.0f);
	right_flipper = App->physics->CreateChain(207, 521, right_flipper_points, 14);
	right_flipper->body->SetGravityScale(0.0f);
	left_flipper_bot = App->physics->CreateChain(115, 1019, left_flipper_points, 14);
	left_flipper_bot->body->SetGravityScale(0.0f);
	right_flipper_bot = App->physics->CreateChain(207, 1019, right_flipper_points, 14);
	right_flipper_bot->body->SetGravityScale(0.0f);

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	b2Body* b = App->physics->world->CreateBody(&bd);

	b2PolygonShape dshape;
	dshape.SetAsBox(PIXEL_TO_METERS(32), PIXEL_TO_METERS(16));

	b2FixtureDef dummyfix;
	dummyfix.shape = &dshape;
	dummyfix.density = 1.0f;

	b->CreateFixture(&dummyfix);

	b2MassData* massdata = new b2MassData();
	b->GetMassData(massdata);
	left_flipper->body->SetMassData(massdata);
	right_flipper->body->SetMassData(massdata);
	left_flipper_bot->body->SetMassData(massdata);
	right_flipper_bot->body->SetMassData(massdata);

	b2RevoluteJointDef left_flipper_def;
	left_flipper_def.bodyA = background->body;
	left_flipper_def.bodyB = left_flipper->body;
	left_flipper_def.Initialize(left_flipper_def.bodyA, left_flipper_def.bodyB, { PIXEL_TO_METERS(110), PIXEL_TO_METERS(520) });
	left_flipper_def.enableLimit = true;
	left_flipper_def.lowerAngle = -0.15f * b2_pi; 
	left_flipper_def.enableMotor = true;
	left_flipper_def.maxMotorTorque = 10.0f;
	left_flipper_def.motorSpeed = 10.0f;
	left_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_def);

	b2RevoluteJointDef right_flipper_def;
	right_flipper_def.bodyA = background->body;
	right_flipper_def.bodyB = right_flipper->body;
	right_flipper_def.Initialize(right_flipper_def.bodyA, right_flipper_def.bodyB, { PIXEL_TO_METERS(250), PIXEL_TO_METERS(520) });
	right_flipper_def.enableLimit = true;
	right_flipper_def.upperAngle = 0.15f * b2_pi; 
	right_flipper_def.enableMotor = true;
	right_flipper_def.maxMotorTorque = 10.0f;
	right_flipper_def.motorSpeed = -10.0f;
	right_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&right_flipper_def);

	b2RevoluteJointDef left_flipper_bot_def;
	left_flipper_bot_def.bodyA = background->body;
	left_flipper_bot_def.bodyB = left_flipper_bot->body;
	left_flipper_bot_def.Initialize(left_flipper_bot_def.bodyA, left_flipper_bot_def.bodyB, { PIXEL_TO_METERS(110), PIXEL_TO_METERS(1018) });
	left_flipper_bot_def.enableLimit = true;
	left_flipper_bot_def.lowerAngle = -0.15f * b2_pi;
	left_flipper_bot_def.enableMotor = true;
	left_flipper_bot_def.maxMotorTorque = 10.0f;
	left_flipper_bot_def.motorSpeed = 10.0f;
	left_flipper_bot_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_bot_def);

	b2RevoluteJointDef right_flipper_bot_def;
	right_flipper_bot_def.bodyA = background->body;
	right_flipper_bot_def.bodyB = right_flipper_bot->body;
	right_flipper_bot_def.Initialize(right_flipper_bot_def.bodyA, right_flipper_bot_def.bodyB, { PIXEL_TO_METERS(250), PIXEL_TO_METERS(1018) });
	right_flipper_bot_def.enableLimit = true;
	right_flipper_bot_def.upperAngle = 0.19f * b2_pi; // 45 degrees
	right_flipper_bot_def.enableMotor = true;
	right_flipper_bot_def.maxMotorTorque = 10.0f;
	right_flipper_bot_def.motorSpeed = -10.0f;
	right_flipper_bot_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&right_flipper_bot_def);






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
	App->textures->Unload(left_flipper_tex);
	App->textures->Unload(right_flipper_tex);
	App->textures->Unload(circle_tex_green_on);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	//Inputs	
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		left_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		left_flipper->body->ApplyTorque(-500, true);

		left_flipper_bot->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		left_flipper_bot->body->ApplyTorque(-500, true);

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_UP)
		{
			left_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
			left_flipper_bot->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		right_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		right_flipper->body->ApplyTorque(500, true);

		right_flipper_bot->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		right_flipper_bot->body->ApplyTorque(500, true);

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_UP)
		{
			
			right_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
			right_flipper_bot->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN))
	{
		App->audio->PlayFx(flipper_sound);
	}

	


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

	//Bot static elements
	App->renderer->Blit(left_piece1_tex, METERS_TO_PIXELS(left_piece1_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece1_bot->body->GetPosition().y));
	App->renderer->Blit(right_piece1_tex, METERS_TO_PIXELS(right_piece1_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece1_bot->body->GetPosition().y));

	
		
	

	//Action elements
	if (left_piece2_activated) {
		App->renderer->Blit(left_piece2_on_tex, METERS_TO_PIXELS(left_piece2->body->GetPosition().x), METERS_TO_PIXELS(left_piece2->body->GetPosition().y));
		cont_left_piece2--;
		if (cont_left_piece2 <= 0) {
			left_piece2_activated = false;
			cont_left_piece2 = 20;
		}

	}
	else
		App->renderer->Blit(left_piece2_tex, METERS_TO_PIXELS(left_piece2->body->GetPosition().x), METERS_TO_PIXELS(left_piece2->body->GetPosition().y));

	if (right_piece2_activated) {
		App->renderer->Blit(right_piece2_on_tex, METERS_TO_PIXELS(right_piece2->body->GetPosition().x), METERS_TO_PIXELS(right_piece2->body->GetPosition().y));
		cont_right_piece2--;
		if (cont_right_piece2 <= 0) {
			right_piece2_activated = false;
			cont_right_piece2 = 20;
		}

	}
	else
		App->renderer->Blit(right_piece2_tex, METERS_TO_PIXELS(right_piece2->body->GetPosition().x), METERS_TO_PIXELS(right_piece2->body->GetPosition().y));

	if (left_piece2_bot_activated) {
		App->renderer->Blit(left_piece2_on_tex, METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().y));
		cont_left_piece2_bot--;
		if (cont_left_piece2_bot <= 0) {
			left_piece2_bot_activated = false;
			cont_left_piece2_bot = 20;
		}

	}
	else
		App->renderer->Blit(left_piece2_tex, METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(left_piece2_bot->body->GetPosition().y));

	if (right_piece2_bot_activated) {
		App->renderer->Blit(right_piece2_on_tex, METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().y));
		cont_right_piece2_bot--;
		if (cont_right_piece2_bot <= 0) {
			right_piece2_bot_activated = false;
			cont_right_piece2_bot = 20;
		}

	}
	else
		App->renderer->Blit(right_piece2_tex, METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().x), METERS_TO_PIXELS(right_piece2_bot->body->GetPosition().y));


	//SENSOR GREEN LIGHT 1 FALTA CONDICION DE REINICIO DE GREEN ON!!!
	if (green_light_off_activated_1) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_2) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_3) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_4) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_5) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_6) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_7) {
		//App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_7>body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_8) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_9) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_10) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_11) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_12) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_13) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_14) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_15) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_16) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_17) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().y) - circle_radio_green);
	
	if (green_light_off_activated_18) {
		App->renderer->Blit(circle_tex_green_on, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().y) - circle_radio_green);
		/*cont_green_light_off_1--;
		if (cont_green_light_off_1 <= 0) {
			green_light_off_activated_1 = false;
			cont_green_light_off_1 = 20;
		}*/

	}
	else
		App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().y) - circle_radio_green);
	


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

	/*App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_1->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_2->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_3->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_4->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_5->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_6->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_7->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_8->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_9->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_10->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_11->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_12->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_13->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_14->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_15->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_16->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_17->body->GetPosition().y) - circle_radio_green);
	App->renderer->Blit(circle_tex_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().x) - circle_radio_green, METERS_TO_PIXELS(green_light_off_18->body->GetPosition().y) - circle_radio_green);*/


	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_1->body->GetPosition().x), METERS_TO_PIXELS(piece3_1->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_2->body->GetPosition().x), METERS_TO_PIXELS(piece3_2->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_3->body->GetPosition().x), METERS_TO_PIXELS(piece3_3->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_4->body->GetPosition().x), METERS_TO_PIXELS(piece3_4->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_5->body->GetPosition().x), METERS_TO_PIXELS(piece3_5->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_6->body->GetPosition().x), METERS_TO_PIXELS(piece3_6->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_7->body->GetPosition().x), METERS_TO_PIXELS(piece3_7->body->GetPosition().y));
	App->renderer->Blit(piece3_tex, METERS_TO_PIXELS(piece3_8->body->GetPosition().x), METERS_TO_PIXELS(piece3_8->body->GetPosition().y));

	//Flippers
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper->body->GetPosition().x), METERS_TO_PIXELS(left_flipper->body->GetPosition().y), NULL, 1.0F, left_flipper->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(right_flipper_tex, METERS_TO_PIXELS(right_flipper->body->GetPosition().x), METERS_TO_PIXELS(right_flipper->body->GetPosition().y), NULL, 1.0F, right_flipper->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper_bot->body->GetPosition().x), METERS_TO_PIXELS(left_flipper_bot->body->GetPosition().y), NULL, 1.0F, left_flipper_bot->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(right_flipper_tex, METERS_TO_PIXELS(right_flipper_bot->body->GetPosition().x), METERS_TO_PIXELS(right_flipper_bot->body->GetPosition().y), NULL, 1.0F, right_flipper_bot->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	

	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	if (bodyA == App->player->ball || bodyB == App->player->ball) {
		//Piece2
		if (bodyA == left_piece2_action || bodyB == left_piece2_action) {
			left_piece2_activated = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == right_piece2_action || bodyB == right_piece2_action) {
			right_piece2_activated = true;
			App->audio->PlayFx(flipper_sound);
		}else if (bodyA == left_piece2_bot_action || bodyB == left_piece2_bot_action) {
			left_piece2_bot_activated = true;
			App->audio->PlayFx(flipper_sound);
		}else if (bodyA == right_piece2_bot_action || bodyB == right_piece2_bot_action) {
			right_piece2_bot_activated = true;
			App->audio->PlayFx(flipper_sound);
		}//Green lights--------------------------------
		else if (bodyA == green_light_off_1 || bodyB == green_light_off_1) {
			green_light_off_activated_1 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_2 || bodyB == green_light_off_2) {
			green_light_off_activated_2 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_3 || bodyB == green_light_off_3) {
			green_light_off_activated_3 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_4 || bodyB == green_light_off_4) {
			green_light_off_activated_4 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_5 || bodyB == green_light_off_5) {
			green_light_off_activated_5 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_6 || bodyB == green_light_off_6) {
			green_light_off_activated_6 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_7 || bodyB == green_light_off_7) {
			green_light_off_activated_7 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_8 || bodyB == green_light_off_8) {
			green_light_off_activated_8 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_9 || bodyB == green_light_off_9) {
			green_light_off_activated_9 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_10 || bodyB == green_light_off_10) {
			green_light_off_activated_10 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_11 || bodyB == green_light_off_11) {
			green_light_off_activated_11 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_12 || bodyB == green_light_off_12) {
			green_light_off_activated_12 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_13 || bodyB == green_light_off_13) {
			green_light_off_activated_13 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_14 || bodyB == green_light_off_14) {
			green_light_off_activated_14 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_15 || bodyB == green_light_off_15) {
			green_light_off_activated_15 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_16 || bodyB == green_light_off_16) {
			green_light_off_activated_16 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_17 || bodyB == green_light_off_17) {
			green_light_off_activated_17 = true;
			App->audio->PlayFx(flipper_sound);
		}
		else if (bodyA == green_light_off_18 || bodyB == green_light_off_18) {
			green_light_off_activated_18 = true;
			App->audio->PlayFx(flipper_sound);
		}//--------------------------------
		
		
	}
}
