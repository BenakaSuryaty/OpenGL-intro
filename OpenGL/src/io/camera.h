#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

enum class CameraDirection {
	NONE = 0,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera {

public:
	glm::vec3 cameraPos;

	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

	glm::vec3 worldUp;

	float pitch;
	float yaw;
	float speed;

	float zoom;

	Camera(glm::vec3 position);

	void cameraDirectionUpdate(double dx, double dy);
	void cameraPosUpdate(CameraDirection Dir, double dt);
	void cameraZoomUpdate(double dy);

	glm::mat4 getViewMx();

private:
	void updateCameraVec();
};
#endif // !CAMERA_H
