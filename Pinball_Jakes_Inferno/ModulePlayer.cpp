#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleRender.h"
#include "ModuleInput.h"

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
	ball_sound = App->audio->LoadFx("Audio/ball_sound.wav");


	//Springy
	springy = App->physics->CreateRectangle(344, 994, 8, 18);

	b2MouseJointDef def;
	def.bodyA = App->physics->ground;
	def.bodyB = springy->body;
	def.target = { PIXEL_TO_METERS(344), PIXEL_TO_METERS(994) };
	def.dampingRatio = 3.0f;
	def.maxForce = 1000.0f * springy->body->GetMass();
	springy_joint = (b2MouseJoint*)App->physics->world->CreateJoint(&def);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(ball_tex);
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


	if (!ball_created) {
		App->audio->PlayFx(ball_sound);
		ball = App->physics->CreateCircle(340, 980, 6);
		ball->listener = App->scene_intro;
		b2Filter filter;
		ball->body->GetFixtureList()->SetFilterData(filter);
		ball->body->SetBullet(true);
		ball_created = true;

	}

	
	ball->GetPosition(ball_position_x,ball_position_y);
	if (ball_position_y > 1042 && ball_position_x < 328) {

		App->audio->PlayFx(ball_sound);
		if (dead_cont > 180) {
			App->physics->world->DestroyBody(ball->body);
			ball_created = false;
			dead_cont = 0;
		}
		dead_cont++;
		
	}
	App->renderer->Blit(ball_tex, ball_position_x, ball_position_y, NULL, 1.0f, ball->GetRotation());


	return UPDATE_CONTINUE;
}



