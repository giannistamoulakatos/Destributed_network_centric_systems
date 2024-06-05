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

#include "metrics_node.h"
#include "node.h"

Define_Module(Metrics_node);

void Metrics_node::initialize()
{
   nodes_des=par("nodes_des");
   sinkindex=par("sinkindex");
   l=par("l");
   countVisit=0;
   bool NetCon=true;
   bool visit2=true;
   vectNodes=new std::vector<Node*>();
   int counter_msg=0;
   for(int i=0;i<nodes_des;i++)
   {
       Node* nt=(Node*)(this->getParentModule()->getSubmodule("node", i));
       vectNodes->push_back(nt);
       EV<<"Node ID: "<<vectNodes->at(i)->getNodeID()<<endl;

   }
   scheduleAt(simTime()+0.1,new cMessage("start"));
   scheduleAt(simTime()+100,new cMessage("visit"));


}

void Metrics_node::handleMessage(cMessage *msg)
{
    std::string mes=msg->getName();

    if(mes=="start")
    {
        Node* parentnode = vectNodes->at(0);
        cGate* parentGate=parentnode->gate("node_metric");
        sendDirect(new cMessage("floodNodes"),parentGate);
        delete msg;

    }
    else if (mes=="visit")
    {
        for(int i=0;i<nodes_des;i++)
        {
            if(vectNodes->at(i)->nodes_visited()==true)
            {
                countVisit++;
                counter_msg++;
            }
            else
            {
                NetCon=false;
            }
      }
        Node *sinknode=vectNodes->at(sinkindex);
        cGate* sinkGate=sinknode->gate("node_metric");
        cMessage* newMsg = new cMessage("Im sink");
        sendDirect(new cMessage("Im sink"),sinkGate);
        scheduleAt(simTime()+1,newMsg);
        delete msg;

}


 }


double Metrics_node::euclidian_distance(int i,int j)
{
    double edst=sqrt(pow(vectNodes->at(i)-vectNodes->at(j),2) + pow(vectNodes->at(i)-vectNodes->at(j),2));
    return edst;
}

void Metrics_node::finish()
{
  double ed;
  FILE* file=fopen("euclidian_distance.txt","a");
  if(NetCon==true)
  {
      EV<<"seed net"<<this->seednum<<" : is connected!!!"<<endl;
  }
  else
  {
      EV<<"seed net"<<this->seednum<<" : not connected!!!"<<endl;
      std::cout<<this->countVisit<<" : nodes"<<endl;
  }
  for(int i=0;i<nodes_des;i++)
  {
   if(i!=sinkindex)
   {
       ed=euclidian_distance(i,sinkindex);
       fprintf(file,"%f\t \n" ,ed);
       fprintf(file,"%d\t \n",counter_msg);
       EV<<"euclidian distance is"<<ed<<endl;
       EV<<"total messages from nodes"<<counter_msg<<endl;
   }
  }
  fclose(file);
}
