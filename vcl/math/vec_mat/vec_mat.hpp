#pragma once

#include "../../base/base.hpp"
#include "../../containers/containers.hpp"
#include "../matrix/matrix.hpp"
#include "../rotation/rotation.hpp"

namespace vcl
{

	// Compute a unit vector orthogonal to the current one
	//  return vector v_ortho such that dot(v,v_ortho)=0
    vec2 orthogonal_vector(vec2 const& v);
	vec3 orthogonal_vector(vec3 const& v);

	float det(mat2 const& m);
	float det(mat3 const& m);
	float det(mat4 const& m);

	mat2 inverse(mat2 const& m);
	mat3 inverse(mat3 const& m);
	mat4 inverse(mat4 const& m);


}

