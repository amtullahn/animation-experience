#pragma once
#include "ActorFactory.h"
#include "Actor.h"

/**
 * Factory class that builds the Sparty character
 */
class CSpartyFactory :
	public CActorFactory
{
public:
	CSpartyFactory();
	virtual ~CSpartyFactory();
	std::shared_ptr<CActor> Create();
};

