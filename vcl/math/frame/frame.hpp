#pragma once

#include "../rotation/rotation.hpp"

namespace vcl
{
	struct affine_rt;

	struct frame
	{
		rotation orientation;
		vec3 position;

		frame();
		explicit frame(rotation const& orientation, vec3 const& position);
		explicit frame(affine_rt const& transformation);
		explicit frame(vec3 const& ux, vec3 const& uy, vec3 const& position={0,0,0});

		vec3 ux() const;
		vec3 uy() const;
		vec3 uz() const;

		mat4 matrix() const;

	};


	// The "inverse" of a frame corresponds to the inverse of its associated transformation
	frame inverse(frame const& f);

	// Apply affine transform to the frame
	frame operator*(affine_rt const& T, frame const& f);
	// Apply rotation to the frame
	frame operator*(rotation const& R, frame const& f);

	// Applying translation to the frame
	frame operator+(frame const& f, vec3 const& tr);
	frame operator+(vec3 const& tr, frame const& f);
	frame operator-(frame const& f, vec3 const& tr);
}
