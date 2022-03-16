#pragma once

#include <string>
#include "../glad/glad.hpp"
#include "../../../math/math.hpp"

namespace vcl
{
	void opengl_uniform(GLuint shader, std::string const& name, int value, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, float value, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, vec3 const& value, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, vec4 const& value, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, float x, float y, float z, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, float x, float y, float z, float w, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, mat4 const& m, bool expected=true);
	void opengl_uniform(GLuint shader, std::string const& name, mat3 const& m, bool expected=true);
}

