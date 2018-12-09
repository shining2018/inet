/*
 * BSRTx.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef COMMON_BSRTX_H_
#define COMMON_BSRTX_H_
#include <omnetpp.h>
using namespace omnetpp;
#include "inet/common/InitStages.h"
#include "PacketType.h"
namespace inet
{
class BSRTx:public cSimpleModule
{
private:

protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
public:
    BSRTx();
    ~BSRTx();
};
}



#endif /* COMMON_BSRTX_H_ */
