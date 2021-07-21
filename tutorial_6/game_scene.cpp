#include "game_scene.h"
#include "pointy_head.h"
#include "blocky_boy.h"
#include "airplane.h"
#include "crazy_crate.h"
#include "input.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Blocky_Boy* blocky_boy = new Blocky_Boy("Game_Object.Blocky_Boy");
	_game_objects[blocky_boy->id()] = blocky_boy;

	Pointy_Head* pointy_head = new Pointy_Head("Game_Object.Pointy_Head");
	_game_objects[pointy_head->id()] = pointy_head;
	
	Airplane* airplane = new Airplane("Game_Object.Airplane");
	_game_objects[airplane->id()] = airplane;
	
	
	Crazy_Crate* crazy_crate = new Crazy_Crate("Game_Object.Crate");
	_game_objects[crazy_crate->id()] = crazy_crate;
	
	
}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double seconds_to_simulate, Input* input)
{
	if(input->is_button_state(Input::Button::FORWARD, Input::Button_State::DOWN))
	{
		_camera_position += _camera_forward * (float)seconds_to_simulate;
	}
	if(input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		_camera_position -= glm::cross(_camera_forward, _camera_up) * (float)seconds_to_simulate;
	}
	if(input->is_button_state(Input::Button::BACKWARD, Input::Button_State::DOWN))
	{
		_camera_position -= _camera_forward * (float)seconds_to_simulate;
	}
	if(input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		_camera_position += glm::cross(_camera_forward, _camera_up) * (float)seconds_to_simulate;
	}
}