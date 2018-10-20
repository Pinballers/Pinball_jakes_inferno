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



	//Adding physic
	background.add(App->physics->CreateChain(0, 0, background_points, 108));
	left_flipper = App->physics->CreateFlipper(112, 666, left_flipper_points, 20);
	left_flipper->body->SetGravityScale(0.0f);



	b2RevoluteJointDef left_flipper_def;
	left_flipper_def.bodyA = background.getFirst()->data->body;
	left_flipper_def.bodyB = left_flipper->body;
	left_flipper_def.Initialize(left_flipper_def.bodyA, left_flipper_def.bodyB, { PIXEL_TO_METERS(120), PIXEL_TO_METERS(676) });
	left_flipper_def.enableLimit = true;
	left_flipper_def.lowerAngle = -0.15f * b2_pi; // -90 degrees
	left_flipper_def.upperAngle = 0.15f * b2_pi; // 45 degrees
	left_flipper_def.enableMotor = true;
	left_flipper_def.maxMotorTorque = 10.0f;
	left_flipper_def.motorSpeed = 10.0f;
	left_flipper_joint = (b2RevoluteJoint*)App->physics->world->CreateJoint(&left_flipper_def);

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
	//Background
	App->renderer->Blit(background_tex, 0, 0);

	//Flippers
	
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		App->audio->PlayFx(flipper_sound);
	}
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		left_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		left_flipper->body->ApplyTorque(-500, true);
		App->audio->PlayFx(flipper_sound);

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_UP)
		{
			App->physics->left_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		}
	}

	/*if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		App->physics->right_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_UP)
		{
			App->physics->right_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN))
	{
		App->audio->PlayFx(flipper_sound);
	}*/

	


	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	// All draw functions ------------------------------------------------------
	App->renderer->Blit(left_flipper_tex, METERS_TO_PIXELS(left_flipper->body->GetPosition().x), METERS_TO_PIXELS(left_flipper->body->GetPosition().y), NULL, 1.0F, left_flipper->GetRotation(), PIXEL_TO_METERS(42), PIXEL_TO_METERS(10));
	//App->renderer->Blit(right_flipper, 200, 447, NULL, 1.0f, App->physics->right_flipper->GetRotation(), 62, 9);

	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	App->audio->PlayFx(flipper_sound);
}
