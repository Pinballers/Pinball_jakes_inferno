#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ChainPointsPlayer.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	ball_tex = App->textures->Load("Sprites/ball.png");
	left_flipper_tex = App->textures->Load("Sprites/left_flipper.png");
	right_flipper_tex = App->textures->Load("Sprites/right_flipper.png");
	close_piece_tex = App->textures->Load("Sprites/close_piece.png");

	
	ball_sound = App->audio->LoadFx("Audio/ball_sound.wav");
	flipper_sound = App->audio->LoadFx("Audio/flipper_sound.wav");


	//Close piece
	

	//Springy
	springy = App->physics->CreateRectangle(344, 994, 8, 18);

	b2MouseJointDef def;
	def.bodyA = App->physics->ground;
	def.bodyB = springy->body;
	def.target = { PIXEL_TO_METERS(344), PIXEL_TO_METERS(994) };
	def.dampingRatio = 3.0f;
	def.maxForce = 1000.0f * springy->body->GetMass();
	springy_joint = (b2MouseJoint*)App->physics->world->CreateJoint(&def);



	//Flippers
	left_flipper = App->physics->CreateChain(115, 521, left_flipper_points, 14);
	left_flipper->body->SetGravityScale(0.0f);
	right_flipper = App->physics->CreateChain(205, 521, right_flipper_points, 14);
	right_flipper->body->SetGravityScale(0.0f);
	left_flipper_bot = App->physics->CreateChain(115, 1019, left_flipper_points, 14);
	left_flipper_bot->body->SetGravityScale(0.0f);
	right_flipper_bot = App->physics->CreateChain(205, 1019, right_flipper_points, 14);
	right_flipper_bot->body->SetGravityScale(0.0f);

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	b2Body* b = App->physics->world->CreateBody(&bd);
	b->SetTransform({ -200,-200 }, 0);


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
	left_flipper_def.bodyA = App->scene_intro->background->body;
	left_flipper_def.bodyB = left_flipper->body;
	left_flipper_def.Initialize(left_flipper_def.bodyA, left_flipper_def.bodyB, { PIXEL_TO_METERS(120), PIXEL_TO_METERS(520) });
	left_flipper_def.enableLimit = true;
	left_flipper_def.lowerAngle = -0.15f * b2_pi;
	left_flipper_def.enableMotor = true;
	left_flipper_def.maxMotorTorque = 10.0f;
	left_flipper_def.motorSpeed = 10.0f;
	left_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_def);

	b2RevoluteJointDef right_flipper_def;
	right_flipper_def.bodyA = App->scene_intro->background->body;
	right_flipper_def.bodyB = right_flipper->body;
	right_flipper_def.Initialize(right_flipper_def.bodyA, right_flipper_def.bodyB, { PIXEL_TO_METERS(250), PIXEL_TO_METERS(520) });
	right_flipper_def.enableLimit = true;
	right_flipper_def.upperAngle = 0.19f * b2_pi;
	right_flipper_def.enableMotor = true;
	right_flipper_def.maxMotorTorque = 10.0f;
	right_flipper_def.motorSpeed = -10.0f;
	right_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&right_flipper_def);

	b2RevoluteJointDef left_flipper_bot_def;
	left_flipper_bot_def.bodyA = App->scene_intro->background->body;
	left_flipper_bot_def.bodyB = left_flipper_bot->body;
	left_flipper_bot_def.Initialize(left_flipper_bot_def.bodyA, left_flipper_bot_def.bodyB, { PIXEL_TO_METERS(120), PIXEL_TO_METERS(1018) });
	left_flipper_bot_def.enableLimit = true;
	left_flipper_bot_def.lowerAngle = -0.15f * b2_pi;
	left_flipper_bot_def.enableMotor = true;
	left_flipper_bot_def.maxMotorTorque = 10.0f;
	left_flipper_bot_def.motorSpeed = 10.0f;
	left_flipper_bot_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_bot_def);

	b2RevoluteJointDef right_flipper_bot_def;
	right_flipper_bot_def.bodyA = App->scene_intro->background->body;
	right_flipper_bot_def.bodyB = right_flipper_bot->body;
	right_flipper_bot_def.Initialize(right_flipper_bot_def.bodyA, right_flipper_bot_def.bodyB, { PIXEL_TO_METERS(250), PIXEL_TO_METERS(1018) });
	right_flipper_bot_def.enableLimit = true;
	right_flipper_bot_def.upperAngle = 0.19f * b2_pi;
	right_flipper_bot_def.enableMotor = true;
	right_flipper_bot_def.maxMotorTorque = 10.0f;
	right_flipper_bot_def.motorSpeed = -10.0f;
	right_flipper_bot_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&right_flipper_bot_def);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(ball_tex);
	App->textures->Unload(left_flipper_tex);
	App->textures->Unload(right_flipper_tex);
	App->textures->Unload(close_piece_tex);
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//Inputs
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		springy_joint->SetTarget({ PIXEL_TO_METERS(344), PIXEL_TO_METERS(1040) });
		springy_joint->SetFrequency(1.0f);
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		springy_joint->SetTarget({ PIXEL_TO_METERS(344), PIXEL_TO_METERS(994) });
		springy_joint->SetFrequency(20.0f);
	}

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
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		RestartBall();
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		RestartGame();
	}

	if (App->scene_intro->life_ball == 0) {
		RestartGame();
	}
	
	if (!ball_created) {
		App->audio->PlayFx(ball_sound);
		ball = App->physics->CreateCircle(ball_position_x, ball_position_y, 6);
		ball->listener = App->scene_intro;
		b2Filter filter;
		ball->body->GetFixtureList()->SetFilterData(filter);
		ball->body->SetBullet(true);
		ball_created = true;
	}

	
	ball->GetPosition(ball_position_x,ball_position_y);
	if (ball_position_y > 1042 && ball_position_x < 328) {

		App->audio->PlayFx(ball_sound);
		if (dead_cont <= 0) {
			App->scene_intro->life_ball--;
			RestartBall();
		}
		dead_cont--;
	}
	
	if (ball_position_y < 750 && !close_piece_created) {
		close_piece = App->physics->CreateStaticChain(334, 782, close_piece_points, 12);
		close_piece_created = true;
	}

	//Blit
	App->renderer->Blit(ball_tex, ball_position_x, ball_position_y, NULL, 1.0f, ball->GetRotation());

	//Close_Piece
	App->renderer->Blit(close_piece_tex, 334, 782);

	//Flippers
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper->body->GetPosition().x), METERS_TO_PIXELS(left_flipper->body->GetPosition().y), NULL, 1.0F, left_flipper->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(right_flipper_tex, METERS_TO_PIXELS(right_flipper->body->GetPosition().x), METERS_TO_PIXELS(right_flipper->body->GetPosition().y), NULL, 1.0F, right_flipper->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper_bot->body->GetPosition().x), METERS_TO_PIXELS(left_flipper_bot->body->GetPosition().y), NULL, 1.0F, left_flipper_bot->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	App->renderer->Blit(right_flipper_tex, METERS_TO_PIXELS(right_flipper_bot->body->GetPosition().x), METERS_TO_PIXELS(right_flipper_bot->body->GetPosition().y), NULL, 1.0F, right_flipper_bot->GetRotation(), PIXEL_TO_METERS(1), PIXEL_TO_METERS(1));
	


	return UPDATE_CONTINUE;
}

void ModulePlayer::StopBall(int type) {
	if (type == 1) {
		ball->body->SetTransform({ App->scene_intro->hole_bot->body->GetPosition().x, App->scene_intro->hole_bot->body->GetPosition().y }, 0);
	}
	else if(type == 2){
		ball->body->SetTransform({ App->scene_intro->hole_top->body->GetPosition().x, App->scene_intro->hole_top->body->GetPosition().y }, 0);
	}
}

void ModulePlayer::PlayBall(int type) {
	if (type == 1) {
		random++;
		if (random % 2 == 0)
			ball->body->SetTransform({ App->scene_intro->hole_right->body->GetPosition().x, App->scene_intro->hole_right->body->GetPosition().y }, 0);
		else
			ball->body->SetTransform({ App->scene_intro->hole_left->body->GetPosition().x, App->scene_intro->hole_left->body->GetPosition().y }, 0);
	}
	else if (type == 2) {
		ball->body->SetTransform({ App->scene_intro->hole_top->body->GetPosition().x, App->scene_intro->hole_top->body->GetPosition().y }, 0);
	}
}

void ModulePlayer::RestartBall() {
	App->physics->world->DestroyBody(ball->body);
	App->physics->world->DestroyBody(close_piece->body);
	ball_created = false;
	close_piece_created = false;
	dead_cont = 120;
	ball_position_x = 340;
	ball_position_y = 980;
}

void ModulePlayer::RestartGame() {
	RestartBall();
	App->scene_intro->score = 0;
}




