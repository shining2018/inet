/*
 * UAVInfoNotifier.cc
 *
 *  Created on: 2018年12月6日
 *      Author: ChenXi
 */


#include "UAVInfoNotifier.h"

namespace inet
{
Define_Module(UAVInfoNotifier);

UAVInfoNotifier::UAVInfoNotifier()
{

}

UAVInfoNotifier::~UAVInfoNotifier()
{

}

void UAVInfoNotifier::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if(stage == INITSTAGE_LOCAL)
    {
        parent=getParentModule();
        cModule *mobility=parent->getSubmodule("mobility");
        mobilityModule = dynamic_cast<IMobility*>(mobility);

        sendInterval=par("sendInterval");
    }
    else if(stage == INITSTAGE_APPLICATION_LAYER)
    {
        selfNotifierTimer = new cMessage("selfNotifierTimer");
        scheduleAt(simTime(),selfNotifierTimer);
    }
}

void UAVInfoNotifier::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        if(msg==selfNotifierTimer)
        {
            //TODO
            //修改为notifier信息
            UAVInfoNotifierMsg *pk = new UAVInfoNotifierMsg("NotifierPk");
            pk->setKind(PACKET_TYPE_HOST_NOTIFIER);
            pk->setUAVID(parent->getId());
            pk->setUAVPath(parent->getFullPath().c_str());
            pk->setUAVPositionX(mobilityModule->getCurrentPosition().x);
            pk->setUAVPositionY(mobilityModule->getCurrentPosition().y);
            send(pk,"outToRTx");

            scheduleAt(simTime()+sendInterval,selfNotifierTimer);
        }
    }
}
}

