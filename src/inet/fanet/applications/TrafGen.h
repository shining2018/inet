/*
 * TrafGen.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef APPLICATIONS_TRAFGEN_H_
#define APPLICATIONS_TRAFGEN_H_

#include <omnetpp.h>
using namespace omnetpp;
#include "inet/common/InitStages.h"
namespace inet
{
class TrafGen: public cSimpleModule
{
private:
    cPar *sendInterval = nullptr;
    cPar *numPacketPerBurst = nullptr;
    cPar *packetLength = nullptr;

    long seqNum=0;

    simtime_t startTime;
    simtime_t stopTime;

    cMessage *selfTimerMsg=nullptr;
    long packetsSent = 0;

    simsignal_t packetSentSignal;

protected:
    enum Kinds {START = 100, NEXT};
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    void scheduleNextPacket(simtime_t previous);
    void cancelNextPacket();
    void sendBurstPackets();
public:
    TrafGen();
    ~TrafGen();
};
}


#endif /* APPLICATIONS_TRAFGEN_H_ */
