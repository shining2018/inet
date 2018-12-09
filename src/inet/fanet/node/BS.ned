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
import inet.fanet.common.BSRTx;
import inet.fanet.common.BSInfoReceiver;
import inet.fanet.linklayer.noma.BSNomaMac;
import inet.common.queue.Sink;
import inet.mobility.static.StationaryMobility;

module BS
{
    parameters:
        @display("i=device/receiverdish");

    gates:
        input radioIn @directIn;

    submodules:
        mobility: StationaryMobility {
            parameters:
                @display("p=70,50");
        }
        rtx: BSRTx {
            @display("p=200,300");
        }
        infoReceiver: BSInfoReceiver {
            @display("p=300,250");
        }
        mac: BSNomaMac {
            @display("p=200,150");
        }
        sink: Sink {

            @display("p=70,150");
        }
    connections:
        radioIn --> rtx.inFromBS;
        rtx.outToMac --> mac.inFromRTx;
        rtx.outToInfoReceiver --> infoReceiver.inFromRTx;
        mac.outToRTx --> rtx.inFromMac;
        mac.outToSink --> sink.in++;

}
