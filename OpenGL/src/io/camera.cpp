#include "camera.h"

Camera::Camera(glm::vec3 position):
	cameraPos(position),
	worldUp(glm::vec3(0.0f,1.0f,0.0f)),
	yaw(-90.0f),
	pitch(0.0f),
	speed(0.25f),
	zoom(45.0f),
	cameraFront(glm::vec3(0.0f, 0.0f,-1.0f)){
	updateCameraVec();
}

void Camera::cameraDirectionUpdate(double dx, double dy) {

	yaw += dx;
	pitch += dy;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	else if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	updateCameraVec();
}

void Camera::cameraPosUpdate(CameraDirection Dir, double dt) {

	float velocity = (float)dt * speed;

	switch (Dir) {

	case CameraDirection::FORWARD:
		cameraPos += cameraFront * velocity;
		break;

	case CameraDirection::BACKWARD:
		cameraPos -= cameraFront * velocity;
		break;

	case CameraDirection::RIGHT:
		cameraPos += cameraRight * velocity;
		break;

	case CameraDirection::LEFT:
		cameraPos -= cameraRight * velocity;
		break;

	case CameraDirection::UP:
		cameraPos += cameraUp * velocity;
		break;

	case CameraDirection::DOWN:
		cameraPos -= cameraUp * velocity;
		break;
	}
}

void Camera::cameraZoomUpdate(double dy) {

	if (zoom >= 1.0f && zoom <= 45.0f) {
		zoom -= dy;
	}
	else if (zoom < 1.0f) {
		zoom = 1.0f;
	}
	else {
		zoom = 45.0f;
	}
}

glm::mat4 Camera::getViewMx() {
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::updateCameraVec() {

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);

	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));

}
