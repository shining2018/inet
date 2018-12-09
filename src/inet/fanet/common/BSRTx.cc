/*
 * BSRTx.cc
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */


#include "BSRTx.h"

namespace inet
{
Define_Module(BSRTx);

BSRTx::BSRTx()
{

}

BSRTx::~BSRTx()
{

}

void BSRTx::initialize(int stage)
{
    cSimpleModule::initialize(stage);
}

void BSRTx::handleMessage(cMessage *msg)
{
    if(msg->getKind()==PACKET_TYPE_HOST_NOTIFIER)
    {
        send(msg,"outToInfoReceiver");
    }
}
}

