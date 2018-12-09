/*
 * BSInfoReceiver.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef COMMON_BSINFORECEIVER_H_
#define COMMON_BSINFORECEIVER_H_


#include "inet/common/InitStages.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/mobility/contract/IMobility.h"
#include "PacketType.h"
#include "UAVInfoNotifierMsg_m.h"
#include <vector>
using namespace std;

namespace inet
{
struct UAVInfo
{
    int UAVID;
    std::string UAVPath;
    double Distance;
};

class BSInfoReceiver:public cSimpleModule
{
private:
    vector<UAVInfo> uavInfoVector;
    Coord bsPosition;
protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;

public:
    BSInfoReceiver();
    ~BSInfoReceiver();
};
}



#endif /* COMMON_BSINFORECEIVER_H_ */
