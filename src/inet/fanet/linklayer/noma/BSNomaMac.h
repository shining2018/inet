/*
 * BSNomaMac.h
 *
 *  Created on: 2018Äê12ÔÂ6ÈÕ
 *      Author: ChenXi
 */

#ifndef LINKLAYER_NOMA_BSNOMAMAC_H_
#define LINKLAYER_NOMA_BSNOMAMAC_H_
#include <omnetpp.h>
using namespace omnetpp;
namespace inet
{
class BSNomaMac:public cSimpleModule
{
private:

protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
public:
    BSNomaMac();
    ~BSNomaMac();
};
}



#endif /* LINKLAYER_NOMA_BSNOMAMAC_H_ */
