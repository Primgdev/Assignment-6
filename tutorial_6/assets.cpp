#include "assets.h"
#include "shader.h"
#include "shader_program.h"
#include "triangle_mesh.h"
#include "square_mesh.h"
#include "texture.h"
#include "colored_3D_shader_program.h"
#include "textured_3D_shader_program.h"
#include "cube_mesh.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
	Triangle_Mesh* traingle_mesh = new Triangle_Mesh();
	_assets.insert({traingle_mesh->id(), traingle_mesh});

	Square_Mesh* square_mesh = new Square_Mesh();
	_assets.insert({square_mesh->id(), square_mesh});

	Texture* airplane_sprite = new Texture("Sprite.Airplane", "Assets/sprite.airplane.png");
	_assets.insert({airplane_sprite->id(), airplane_sprite});

	Texture* airplane_background_mask = new Texture("Mask.Airplane_Background", "Assets/mask.airplane_background.png");
	_assets.insert({airplane_background_mask->id(), airplane_background_mask});

	Texture* airplane_mask = new Texture("Mask.Airplane", "Assets/mask.airplane.png");
	_assets.insert({airplane_mask->id(), airplane_mask});

	Texture* polygons_mask = new Texture("Mask.Polygons", "Assets/mask.polygons.png");
	_assets.insert({polygons_mask->id(), polygons_mask});


	Shader* colored_3D_vertex_shader = new Shader("Shader.Colored.3D.Vertex", "Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	_assets.insert({colored_3D_vertex_shader->id(), colored_3D_vertex_shader});

	Shader* colored_3D_fragment_shader = new Shader("Shader.Colored.3D.Fragment", "Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	_assets.insert({colored_3D_fragment_shader->id(), colored_3D_fragment_shader});

	Colored_3D_Shader_Program* colored_3D_program = new Colored_3D_Shader_Program(colored_3D_vertex_shader, colored_3D_fragment_shader);
	_assets.insert({colored_3D_program->id(), colored_3D_program});

	Cube_Mesh* cube_mesh = new Cube_Mesh();
	_assets.insert({cube_mesh->id(), cube_mesh});

	Shader* textured_3D_vertex_shader = new Shader("Shader.Textured.3D.Vertex", "Shaders/textured.3D.vertex_shader.glsl", Shader::Type::Vertex);
	_assets.insert({textured_3D_vertex_shader->id(), textured_3D_vertex_shader});

	Shader* textured_3D_fragment_shader = new Shader("Shader.Textured.3D.Fragment", "Shaders/textured.3D.fragment_shader.glsl", Shader::Type::Fragment);
	_assets.insert({textured_3D_fragment_shader->id(), textured_3D_fragment_shader});

	Textured_3D_Shader_Program* textured_3D_program = new Textured_3D_Shader_Program(textured_3D_vertex_shader, textured_3D_fragment_shader);
	_assets.insert({textured_3D_program->id(), textured_3D_program});

	Texture* crate_texture = new Texture("Texture.Crate", "Assets/texture.crate.jpg");
	_assets.insert({crate_texture->id(), crate_texture});

	Texture* crate_sides_texture = new Texture("Texture.Crate_With_Sides_Marked", "Assets/texture.crate_with_sides_marked.jpg");
	_assets.insert({crate_sides_texture->id(), crate_sides_texture});
}
Assets::~Assets()
{
}

const Asset* Assets::get_asset(const char* id) const
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets.find(id)->second;
}