/**
 * \file SpartyFactory.cpp
 *
 * \author Amtullah Naalwala
 *
 * Factory class that builds the Sparty Character
 */

#include "pch.h"
#include "SpartyFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"
#include "SpartyHeadTop.h"

using namespace std;
using namespace Gdiplus;

CSpartyFactory::CSpartyFactory()
{
}

CSpartyFactory::~CSpartyFactory()
{
}

/** This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CSpartyFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Sparty");

    auto torso = make_shared<CImageDrawable>(L"Torso", L"images/sparty_torso.png");
    torso->SetCenter(Point(74, 210));
    torso->SetPosition(Point(0, -114));
    actor->SetRoot(torso);

    auto lleg = make_shared<CImageDrawable>(L"Left leg", L"images/sparty_lleg.png");
    lleg->SetCenter(Point(0, 0));
    lleg->SetPosition(Point(-10, -60));
    torso->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
    rleg->SetCenter(Point(74, 0));
    rleg->SetPosition(Point(5, -60));
    torso->AddChild(rleg);

    auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
    larm->SetCenter(Point(0, 0));
    larm->SetPosition(Point(25, -217));
    torso->AddChild(larm);

    auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
    rarm->SetCenter(Point(121, 0));
    rarm->SetPosition(Point(-25, -217));
    torso->AddChild(rarm);

    auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
    headb->SetCenter(Point(56, 0));
    headb->SetPosition(Point(0, -217));
    torso->AddChild(headb);

    auto headt = make_shared<CSpartyHeadTop>(L"Head Top", L"images/sparty_head.png");
    headt->SetCenter(Point(52, 147));
    headt->SetPosition(Point(0, 10));
    headb->AddChild(headt);

    auto mug = make_shared<CImageDrawable>(L"Beer", L"images/mug.png");
    mug->SetCenter(Point(0, 0));
    mug->SetPosition(Point(90, 125));
    larm->AddChild(mug);

    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(torso);   
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);
    actor->AddDrawable(mug);

    return actor;
}