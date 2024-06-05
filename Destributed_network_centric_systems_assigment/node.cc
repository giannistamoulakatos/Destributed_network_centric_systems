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

#include "node.h"

Define_Module(Node);

void Node::initialize()
{
    visit=false;
    visit2=false;
    nodeID=par("nodeID");
    neighboors_nodes = gateSize("gates_as");
    sinkindex = par("sinkindex");
    l=par("l");

}
int Node::getNodeID()
{
    return this->nodeID;
}

bool Node::nodes_visited()
{
    return this->visit;
}

void Node::handleMessage(cMessage *msg)
{
   std::string message = msg->getName();
   if (message=="floodNodes")
   {
       if(!visit)
       {
           visit=true;
           EV<<"Message "<<msg->getKind()<<endl;
           for(int i=0;i<gateSize("gates_as");i++)
           {
               send(msg->dup(),gate("gates_as$o",i));
           }
           delete msg;
       }
   }
    if (message=="Im sink")
    {
        if(!visit2) {
              visit2=true;
              for(int i=0;i<gateSize("gates_as");i++)
              {
                if(getIndex()==sinkindex)
                {
                send(msg->dup(),gate("gates_as$o",i));
                }

              if(getIndex()!=sinkindex)
              {
                if(uniform(0,1)<l)
                {
                 cMessage *mes=new cMessage("Hey sink");
                 send(mes->dup(),gate("gates_as$o",sinkindex));
                }

               }
               }
              }
              delete msg;
            }

}



