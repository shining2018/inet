/*
 * UAVRTx.cc
 *
 *  Created on: 2018年12月6日
 *      Author: ChenXi
 */


#include "UAVRTx.h"
#include "inet/common/InitStages.h"
namespace inet
{
Define_Module(UAVRTx);

UAVRTx::UAVRTx()
{
    bs=nullptr;
}

UAVRTx::~UAVRTx()
{

}

void UAVRTx::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if(stage == INITSTAGE_LOCAL)
    {
        //发现基站
        bs = getModuleByPath("bs");
        if(!bs)
        {
            throw cRuntimeError("Noma: BS not found!");
        }
        else
        {
            EV_INFO<<"Noma: BS found-"<<bs->getFullPath()<<endl;
        }
    }
}

void UAVRTx::handleMessage(cMessage *msg)
{
    switch(msg->getKind())
    {
    case PACKET_TYPE_HOST_NOTIFIER:
    {
        sendDirect(msg, bs->gate("radioIn"));
    }

    }
}
}

