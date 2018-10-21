#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ChainPoints.h"

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
	background_tex = App->textures->Load("Sprites/background.png");
	left_flipper_tex = App->textures->Load("Sprites/left_flipper.png");
	right_flipper_tex = App->textures->Load("Sprites/right_flipper.png");

	//Load Audio
	flipper_sound = App->audio->LoadFx("Game/Sounds/flipper_sound.wav");



	//Adding physic Background and Flippers
	background = App->physics->CreateStaticChain(25, 34, background_points, 238);
	left_flipper = App->physics->CreateChain(98, 494, left_flipper_points, 20);
	left_flipper->body->SetGravityScale(0.0f);
	right_flipper = App->physics->CreateChain(226, 494, right_flipper_points, 22);
	right_flipper->body->SetGravityScale(0.0f);

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	b2Body* b = App->physics->world->CreateBody(&bd);

	b2PolygonShape dshape;
	dshape.SetAsBox(PIXEL_TO_METERS(64)*0.5f, PIXEL_TO_METERS(35)*0.5f);

	b2FixtureDef dummyfix;
	dummyfix.shape = &dshape;
	dummyfix.density = 1.0f;

	b->CreateFixture(&dummyfix);

	b2MassData* massdata = new b2MassData();
	b->GetMassData(massdata);
	right_flipper->body->SetMassData(massdata);
	left_flipper->body->SetMassData(massdata);

	b2RevoluteJointDef left_flipper_def;
	left_flipper_def.bodyA = background->body;
	left_flipper_def.bodyB = left_flipper->body;
	left_flipper_def.Initialize(left_flipper_def.bodyA, left_flipper_def.bodyB, { PIXEL_TO_METERS(98), PIXEL_TO_METERS(494) });
	left_flipper_def.enableLimit = true;
	left_flipper_def.lowerAngle = -0.15f * b2_pi; // -90 degrees
	left_flipper_def.upperAngle = 0.15f * b2_pi; // 45 degrees
	left_flipper_def.enableMotor = true;
	left_flipper_def.maxMotorTorque = 10.0f;
	left_flipper_def.motorSpeed = 10.0f;
	left_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_def);

	b2RevoluteJointDef right_flipper_def;
	right_flipper_def.bodyA = background->body;
	right_flipper_def.bodyB = right_flipper->body;
	right_flipper_def.Initialize(right_flipper_def.bodyA, right_flipper_def.bodyB, { PIXEL_TO_METERS(226), PIXEL_TO_METERS(494) });
	right_flipper_def.enableLimit = true;
	right_flipper_def.lowerAngle = -0.15f * b2_pi; // -90 degrees
	right_flipper_def.upperAngle = 0.15f * b2_pi; // 45 degrees
	right_flipper_def.enableMotor = true;
	right_flipper_def.maxMotorTorque = 10.0f;
	right_flipper_def.motorSpeed = 10.0f;
	right_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&right_flipper_def);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	

	
	
	
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		left_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		left_flipper->body->ApplyTorque(-500, true);
		App->audio->PlayFx(flipper_sound);

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_UP)
		{
			left_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		right_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		right_flipper->body->ApplyTorque(-500, true);

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_UP)
		{
			right_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
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
	App->renderer->Blit(background_tex, 0, 0);
	//Flippers
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper->body->GetPosition().x), METERS_TO_PIXELS(left_flipper->body->GetPosition().y), NULL, 1.0F, left_flipper->GetRotation(), PIXEL_TO_METERS(2), PIXEL_TO_METERS(2));
	App->renderer->Blit(right_flipper_tex, METERS_TO_PIXELS(right_flipper->body->GetPosition().x), METERS_TO_PIXELS(right_flipper->body->GetPosition().y), NULL, 1.0F, right_flipper->GetRotation(), PIXEL_TO_METERS(2), PIXEL_TO_METERS(2));
	

	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	App->audio->PlayFx(flipper_sound);
}
