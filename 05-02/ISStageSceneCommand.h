#pragma once

class ISStageSceneCommand {
public:
	virtual ~ISStageSceneCommand() = default;
	virtual void Exec() = 0;
	virtual void Undo() = 0;
};
