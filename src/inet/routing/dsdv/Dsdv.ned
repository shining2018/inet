//
// Copyright (C) 2009 by Alfonso Ariza
// Malaga University
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

package inet.routing.dsdv;

import inet.routing.contract.IManetRouting;

//
// Implements Destination-Sequenced Distance Vector.
//
// The host using this routing algoritm is required to have a SINGLE interface
// which has "wlan" in its name.
//
// NOTE:
//  - This is a fairly incomplete implementation of the originally published DSDV
//    algorithm. It does not implement full routing table dumps, hello message forwarding,
//    there is no logic that sends out full updates if the size of the incremental update reaches
//    the network unit size.
//
// WARNING: This is a partial / unfinished implementation.
//
simple Dsdv like IManetRouting
{
    parameters:
        @display("i=block/routing");
        string interfaceTableModule;   // The path to the InterfaceTable module
        string routingTableModule;
        double helloInterval @unit(s) = default(5s);  // how often hello messages should be sent out
        string netmask = default("255.255.0.0");  // netmask for the ad-hoc network
        double maxVariance = default(1); // This is the maximum of a random value to determine when the first hello message will be sent out
        double routeLifetime @unit(s) = default(5s);  // the expiry time of the routing entries
        bool manetPurgeRoutingTables = default(true);
        volatile double broadcastDelay @unit(s) = default(uniform(0s,0.01s));
    gates:
        input ipIn;
        output ipOut;
}
