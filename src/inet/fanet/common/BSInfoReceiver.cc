/*
 * BSInfoReceiver.cc
 *
 *  Created on: 2018��12��6��
 *      Author: ChenXi
 */

#include "BSinfoReceiver.h"

namespace inet
{
Define_Module(BSInfoReceiver);

BSInfoReceiver::BSInfoReceiver()
{

}

BSInfoReceiver::~BSInfoReceiver()
{

}

void BSInfoReceiver::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if(stage == INITSTAGE_LAST)
    {
        cModule *parent=getParentModule();
        cModule *mobility=parent->getSubmodule("mobility");
        IMobility *bsmobility=dynamic_cast<IMobility*>(mobility);
        bsPosition=bsmobility->getCurrentPosition();
    }
}

void BSInfoReceiver::handleMessage(cMessage *msg)
{
    if(msg->getKind()==PACKET_TYPE_HOST_NOTIFIER)
    {
        int UAVID;
        double distance;
        bool isUAVInfoExist=false;
        UAVInfoNotifierMsg *UAVInfoMsg=dynamic_cast<UAVInfoNotifierMsg*>(msg);
        UAVID=UAVInfoMsg->getUAVID();
        distance=sqrt(pow(bsPosition.x-UAVInfoMsg->getUAVPositionX(),2)+pow(bsPosition.y-UAVInfoMsg->getUAVPositionY(),2));

        for(vector<UAVInfo>::iterator i=uavInfoVector.begin();i!=uavInfoVector.end();i++)
        {
            if(i->UAVID == UAVID)
            {
                //����
                isUAVInfoExist=true;
                i->UAVPath=UAVInfoMsg->getUAVPath();
                i->Distance=distance;
            }
        }
        if(isUAVInfoExist==false)
        {
            //�²���
            UAVInfo newUAVInfo= {UAVInfoMsg->getUAVID(),UAVInfoMsg->getUAVPath(),distance};

            uavInfoVector.push_back(newUAVInfo);

        }

        //��ӡ���vector�е�����
        for(vector<UAVInfo>::iterator i=uavInfoVector.begin();i!=uavInfoVector.end();i++)
        {
            EV_INFO<<"UAV ID: "<<i->UAVID<<", path:"<<i->UAVPath<<", distance:"<<i->Distance<<endl;
        }

        delete UAVInfoMsg;

    }
}


}


