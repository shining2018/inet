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

package inet.fanet.applications;

simple TrafGen
{
	parameters:
	    double startTime @unit(s) = default(this.sendInterval);
	    double stopTime @unit(s) = default(-1s);
	    volatile double sendInterval @unit(s);
	    volatile int numPacketsPerBurst = default(1);
	    volatile int packetLength @unit(b);
	    
	    @display("i=block/app");
	    
	    @signal[packetSent](type=Packet);
	    @statistic[packetSent](title="packets sent";source=packetSent;record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
	
		@class(TrafGen);
	gates:
	    output outToQueue;   
}