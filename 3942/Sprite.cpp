#include "Sprite.h"

Sprite::Sprite(const std::string& pTextureId): texture_id(pTextureId) {
	const Texture_Informations texture = TextureManager::Instance()->getTextureInformationsFromID(pTextureId);
	width = texture.width;
	height = texture.height;
	total_num_frames = texture.numFrames;
	anim_speed = texture.animSpeed;
	angle = 0;
}

void Sprite::changeTextureID(const std::string& pTextureId) {
	texture_id = pTextureId;
	const Texture_Informations texture = TextureManager::Instance()->getTextureInformationsFromID(texture_id);
	width = texture.width;
	height = texture.height;
	total_num_frames = texture.numFrames;
	anim_speed = texture.animSpeed;
	time_reseter = SDL_GetTicks();
}

std::string Sprite::getTextureID() const { return texture_id; }

bool Sprite::isPlayingLastFrame() const {
	return current_frame == (total_num_frames - 1);
}

void Sprite::draw(const Vector2D pPosition, const Vector2D pVelocity) const {
	if(is_visible) {
		if(pVelocity.x > 0)
			TextureManager::Instance()->drawFrame(texture_id, int(pPosition.x), int(pPosition.y), width, height, current_row, current_frame, SDL_FLIP_HORIZONTAL);
		else
			TextureManager::Instance()->drawFrame(texture_id, int(pPosition.x), int(pPosition.y), width, height, current_row, current_frame);
	}
}

void Sprite::update() {
	if(total_num_frames != 0) {
		current_frame = ((SDL_GetTicks() - time_reseter) / (1000 / anim_speed)) % total_num_frames;
	}
}

void Sprite::setWidth(int pWidth) { width = pWidth; }

int Sprite::getWidth() const { return width; }

void Sprite::setHeight(int pHeight) { height = pHeight; }

int Sprite::getHeight() const { return height; }

void Sprite::setAngle(float pAngle) { angle = pAngle; }

float Sprite::getAngle() const { return angle; }

void Sprite::setNumFrames(const int pNumFrames) { total_num_frames = pNumFrames; }

int Sprite::getNumFrames() const { return total_num_frames; }

void Sprite::setCurrentFrame(const int pFrame) { current_frame = pFrame; }

int Sprite::getCurrentFrame() const { return current_frame; }

void Sprite::setVisibility(const bool pIsVisible) { is_visible = pIsVisible; }

bool Sprite::getVisibility() const { return is_visible; }
