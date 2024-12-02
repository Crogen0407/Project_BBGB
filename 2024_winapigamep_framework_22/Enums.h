#pragma once
enum class LAYER
{
	DEFAULT,
	BACKGROUND,
	PLAYER,
	PROJECTILE,
	PLAYERATTACK,
	ENEMY,
	UI,
	SCREENEFFECT,
	END = 30
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};
