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

#ifndef __DESTRIBUTED_NETWORK_CENTRIC_SYSTEMS_ASSIGMENT_NODE_H_
#define __DESTRIBUTED_NETWORK_CENTRIC_SYSTEMS_ASSIGMENT_NODE_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Node : public cSimpleModule
{
  public:
    int getNodeID();
    bool nodes_visited();
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    int nodeID;
    int nodes_des;
    int neighboors_nodes;
    int sinkindex;
    double l;
    bool visit;
    double yPos;
    double xPos;
    bool visit2;
};

#endif
