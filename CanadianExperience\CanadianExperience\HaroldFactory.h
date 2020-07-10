#pragma once
#include "Actor.h"
#include "ActorFactory.h"

using namespace std;
/**
 * Factory class that builds the Harold character
 */
class CHaroldFactory : public CActorFactory
{
public:
    CHaroldFactory();
    virtual ~CHaroldFactory();
    std::shared_ptr<CActor> Create();
};

