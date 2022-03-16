#pragma once

#include "../../containers/buffer_stack/buffer_stack.hpp"
#include "../../containers/buffer/buffer.hpp"

namespace vcl
{
	buffer<vec3> curve_primitive_circle(float radius=1.0f, vec3 const& center={0,0,0}, vec3 const& normal={0,0,1}, int N_sample=20);
}
