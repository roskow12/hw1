// Transform.cpp: implementation of the Transform class.

#include <cstdio>
#include "Transform.h"

//Please implement the following functions:

#define PI_OVER_180 .01745329
// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	const float radians = degrees*PI_OVER_180; 
	const float c = cos(radians);
	const float s = sin(radians);
	const float t = 1.0 - c;
	const float x =  axis.x;
	const float y =  axis.y;
	const float z =  axis.z;
	// You will change this return call
	return mat3(	t*x*x+c, t*x*y+z*s, t*x*z-y*s,
			t*x*y-z*s, t*y*y+c, t*y*z+x*s,
			t*x*z+y*s, t*y*z-x*s, t*z*z+c);
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	mat3 rotated = rotate(degrees, up);
	eye = rotated*eye;

	vec3 x_unit(1,0,0);
	vec3 cross = glm::cross(eye, x_unit);
	printf("up:%.2f, %.2f, %.2f", up.x, up.y, up.z);
	printf(" eye: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	const float radians = degrees*PI_OVER_180; 	
	
	vec3 rotate_around(glm::cross(up, eye));
	rotate_around = glm::normalize(rotate_around);
	printf("rotate_around:%.2f, %.2f, %.2f", rotate_around.x, rotate_around.y, rotate_around.z);
	mat3 rotated = rotate(degrees, rotate_around);

	eye = rotated*eye;
	
	up = glm::cross(eye, rotate_around);
	up = glm::normalize(up);

	printf(" eye: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE

	// You will change this return call
	return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
