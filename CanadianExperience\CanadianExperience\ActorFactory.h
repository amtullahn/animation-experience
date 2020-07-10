/**
 * \file ActorFactory.h
 *
 * \author Amtullah Naalwala
 *
 *  Base class for actor factories
 */

#pragma once
#include <memory>
#include "Actor.h"

/**
 * Abstract base class for actor factories.
 */
class CActorFactory
{
public:
	CActorFactory();
	virtual ~CActorFactory();

	/// Create actors
	/// \return in derived classes
	virtual std::shared_ptr<CActor> Create() = 0;

};

