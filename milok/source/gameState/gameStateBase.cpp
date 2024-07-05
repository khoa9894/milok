#include "gameStateBase.h"
#include "GSIntro.h"
gameStateBase* gameStateBase::CreateState(StateTypes st)
{
	gameStateBase* gs = nullptr;
	switch (st)
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	/*case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case SETTING:
		gs = new GSSetting();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	case HIGHSCORE:
		gs = new GSHighScore();
		break;
	case END:
		gs = new GSEnd();
		break;*/
	default:
		break;
	}
	return gs;
	}

