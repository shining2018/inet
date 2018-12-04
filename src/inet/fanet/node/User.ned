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

import inet.applications.ethernet.EtherTrafGen;
import inet.common.queue.IOutputQueue;
import inet.linklayer.contract.IWirelessInterface;
import inet.mobility.contract.IMobility;

module Host
{
    parameters:
        string queueType = default("DropTailQueue");
        string wlanType = default("");
        string mobilityType = default("RandomWaypointMobility");
    gates:
        input in @directIn;
    submodules:
        app: EtherTrafGen {
            @display("p=200,100");
        }

        queue: <queueType> like IOutputQueue {

            @display("p=322,203");
        }

        wlan: <wlanType> like IWirelessInterface {

            @display("p=200,311");
        }

        mobility: <mobilityType> like IMobility 
        {

            @display("p=53,100");
        }

    connections:
        app.out --> queue.in;
        app.in <-- queue.out;

        queue.out --> wlan.upperLayerIn;
        queue.in <-- wlan.upperLayerOut;

        in --> wlan.radioIn;
}
