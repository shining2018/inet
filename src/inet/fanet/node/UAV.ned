//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package inet.fanet.node;

import inet.mobility.single.RandomWaypointMobility;
import inet.common.queue.DropTailQueue;
import inet.fanet.common.UAVRTx;
import inet.fanet.common.UAVInfoNotifier;
import inet.fanet.linklayer.noma.UAVNomaMac;
import inet.fanet.applications.TrafGen;

module UAV
{
    parameters:
        @display("i=device/satellite_l");

    gates:
        input radioIn @directIn;

    submodules:
        mobility: RandomWaypointMobility {
            @display("p=50,69");
        }

        mac: UAVNomaMac {
            @display("p=225,249");
        }
        rtx: UAVRTx {
            @display("p=225,347");
        }
        notifier: UAVInfoNotifier {
            @display("p=317,249");
        }
        app: TrafGen {
            @display("p=225,69");
        }
        queue: DropTailQueue {
            @display("p=225,160");
        }
        reQueue: DropTailQueue {

            @display("p=128,160");
        }
    connections:
        app.outToQueue --> queue.in;
        queue.out --> mac.inFromQueue;
        mac.outToRTx --> rtx.inFromMac;
        mac.outToReQueue --> reQueue.in;
        reQueue.out --> mac.inFromReQueue;
        notifier.outToRTx --> rtx.inFromNotifier;
        rtx.outToMac --> mac.inFromRTx;
        radioIn --> rtx.inFromUAV;

}
