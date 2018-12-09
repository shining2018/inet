/*
 * UAVRTx.cc
 *
 *  Created on: 2018��12��6��
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
        //���ֻ�վ
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

