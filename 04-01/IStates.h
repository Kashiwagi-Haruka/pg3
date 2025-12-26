#pragma once

class IState {
public:
	virtual ~IState() {}
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;
	virtual bool IsFinished() = 0;
};