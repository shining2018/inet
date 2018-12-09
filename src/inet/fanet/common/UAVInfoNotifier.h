/*
 * UAVInfoNotifier.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef COMMON_UAVINFONOTIFIER_H_
#define COMMON_UAVINFONOTIFIER_H_
#include <omnetpp.h>
using namespace omnetpp;
#include "inet/common/InitStages.h"
#include "inet/mobility/contract/IMobility.h"
#include "PacketType.h"
#include "UAVInfoNotifierMsg_m.h"

namespace inet
{
class UAVInfoNotifier:public cSimpleModule
{
private:
    cMessage *selfNotifierTimer;
    IMobility *mobilityModule;
    cModule *parent;

    simtime_t sendInterval;
protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
public:
    UAVInfoNotifier();
    ~UAVInfoNotifier();
};
}



#endif /* COMMON_UAVINFONOTIFIER_H_ */
