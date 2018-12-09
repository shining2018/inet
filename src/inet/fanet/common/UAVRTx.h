/*
 * UAVRTx.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef COMMON_UAVRTX_H_
#define COMMON_UAVRTX_H_
#include <omnetpp.h>
using namespace omnetpp;
#include "PacketType.h"
#include "inet/common/InitStages.h"
namespace inet
{
class UAVRTx:public cSimpleModule
{
private:
    cModule *bs;

protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;

public:
    UAVRTx();
    ~UAVRTx();
};
}



#endif /* COMMON_UAVRTX_H_ */
