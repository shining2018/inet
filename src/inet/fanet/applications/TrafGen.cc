/*
 * TrafGen.cc
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#include "TrafGen.h"

namespace inet
{
Define_Module(TrafGen);

TrafGen::TrafGen()
{
    sendInterval=nullptr;
    numPacketPerBurst=nullptr;
    packetLength=nullptr;
    selfTimerMsg=nullptr;
}

TrafGen::~TrafGen()
{
    cancelAndDelete(selfTimerMsg);
}

void TrafGen::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if(stage == INITSTAGE_LOCAL)
    {
        sendInterval=&par("sendInterval");
        numPacketPerBurst=&par("numPacketsPerBurst");
        packetLength=&par("packetLength");

        startTime = par("startTime");
        stopTime = par("stopTime");

        packetsSent=0;
        WATCH(packetsSent);

        EV_INFO<<"sendInterval:"<<sendInterval->doubleValue()<<endl;

        packetSentSignal = cComponent::registerSignal("packetSent");

        if(stopTime>=SIMTIME_ZERO && stopTime < startTime)
        {
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        }
    }
    else
    {
        if(stage == INITSTAGE_APPLICATION_LAYER)
        {
            selfTimerMsg=new cMessage ("generateNextPacket");
            scheduleNextPacket(-1);
        }
    }
}

void TrafGen::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        if(msg->getKind() == START)
        {

        }
        sendBurstPackets();
        scheduleNextPacket(simTime());
    }
}

void TrafGen::scheduleNextPacket(simtime_t previous)
{
    simtime_t next;
    if(previous == -1)
    {
        next=simTime() <= startTime ? startTime: simTime();
        selfTimerMsg->setKind(START);
    }
    else
    {
        next = previous + *sendInterval;
        selfTimerMsg->setKind(NEXT);
    }
    if(stopTime < SIMTIME_ZERO || next < stopTime)
    {
        scheduleAt(next,selfTimerMsg);
    }
}

void TrafGen::cancelNextPacket()
{
    cancelEvent(selfTimerMsg);
}

void TrafGen::sendBurstPackets()
{
    int n=*numPacketPerBurst;
    for(int i=0; i<n; i++)
    {
        seqNum++;

        char msgname[40];
        sprintf(msgname,"pk-%d-%ld",getId(),seqNum);

        cPacket *datapacket = new cPacket(msgname);
        long len=*packetLength;
        datapacket->setBitLength(len);

        EV_INFO<<"TrafGen Send packet "<<msgname<<endl;
        emit(packetSentSignal,datapacket);
        send(datapacket,"outToQueue");
        packetsSent++;
    }
}
}



