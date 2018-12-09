/*
 * UAVNomaMac.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef LINKLAYER_NOMA_UAVNOMAMAC_H_
#define LINKLAYER_NOMA_UAVNOMAMAC_H_
#include <omnetpp.h>
using namespace omnetpp;
namespace inet
{
class UAVNomaMac:public cSimpleModule
{
private:

protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
public:
    UAVNomaMac();
    ~UAVNomaMac();
};
}



#endif /* LINKLAYER_NOMA_UAVNOMAMAC_H_ */
