#pragma once
#include "characterStateBase.h"
#include "Hitbox.h"
class Iplayer {
public:	virtual void changeState(characterStateBase::characterState nextState) = 0;
	  virtual skeleton* getSkeleton() = 0;
};