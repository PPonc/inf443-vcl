#pragma once

#include "../../opengl/opengl.hpp"
#include "../../../containers/containers.hpp"
#include <map>

namespace vcl
{
	struct curve_drawable
	{
		curve_drawable();
		// Send mesh data to GPU and store IDs into gpu_elements. Set also shader.
		explicit curve_drawable(buffer<vec3> const& position, GLuint shader=default_shader, GLuint draw_type=GL_DYNAMIC_DRAW);

		GLuint vbo_position;
		GLuint vao;

		GLuint number_position;
		GLuint shader;

		// Uniform
		affine_rts transform;
		vec3 color;

		static GLuint default_shader;

		void clear();
		void update(buffer<vec3> const& new_position);
	};
}


namespace vcl
{
	template <typename SCENE>
	void draw(curve_drawable const& drawable, SCENE const& scene)
	{
		// Setup shader
		assert_vcl(drawable.shader!=0, "Try to draw curve_drawable without shader");
		glUseProgram(drawable.shader); opengl_check;

		// Send uniforms for this shader
		opengl_uniform(drawable.shader, scene);
		opengl_uniform(drawable.shader, "color", drawable.color);
		opengl_uniform(drawable.shader, "model", drawable.transform.matrix());

		// Call draw function
		assert_vcl(drawable.number_position>0, "Try to draw mesh_wireframe_drawable with 0 position"); opengl_check;
		glBindVertexArray(drawable.vao); opengl_check;
		glDrawArrays(GL_LINE_STRIP, 0, drawable.number_position); opengl_check;

		// Clean buffers
		glBindVertexArray(0);
	}
}
