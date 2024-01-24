#pragma once

class Transforms
{
public:
	typedef struct Coords {
		float x, y;

		Coords(float x = 0, float y = 0) : x(x), y(y) {}
	};
private:
	Coords position;
	float rotation;
	Coords scale;
public:
	Transforms(Coords position = Coords(), float rotation = 0.f, Coords scale = Coords()) 
		: position(position), rotation(rotation), scale(scale) {}

	Coords getPosition() { return position; }
	Coords getScale() { return scale; }
	float getRotation() { return rotation; }

	void setPosition(Coords position) { this->position = position; }
	void setScale(Coords scale) { this->scale = scale; }
	void setRotation(float rotation) { this->rotation; }
};

