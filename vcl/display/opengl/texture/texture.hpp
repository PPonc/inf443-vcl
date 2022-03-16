#pragma once

#include "../../image/image.hpp"
#include "../opengl.hpp"
#include "../../../containers/containers.hpp"

namespace vcl
{
	GLuint opengl_texture_to_gpu(image_raw const& im, GLint wrap_s=GL_CLAMP_TO_EDGE, GLint wrap_t=GL_CLAMP_TO_EDGE);
	GLuint opengl_texture_to_gpu(grid_2D<vec3> const& im, GLint wrap_s=GL_CLAMP_TO_EDGE, GLint wrap_t=GL_CLAMP_TO_EDGE);
	void opengl_update_texture_gpu(GLuint texture_id, grid_2D<vec3> const& im);

}
