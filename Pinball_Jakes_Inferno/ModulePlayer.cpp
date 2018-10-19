#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleRender.h"

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
	if (!ball_created) {
		App->audio->PlayFx(ball_sound);
		ball = App->physics->CreateCircle(100, 100, 25);
		ball->listener = App->scene_intro;
		b2Filter filter;
		//filter.categoryBits = ;
		//filter.maskBits = ;
		ball->body->GetFixtureList()->SetFilterData(filter);
		ball->body->SetBullet(true);
		ball_created = true;

	}
	
	ball->GetPosition(ball_position_x,ball_position_y);
	App->renderer->Blit(ball_tex, ball_position_x, ball_position_y, NULL, 1.0f, ball->GetRotation());


	return UPDATE_CONTINUE;
}



