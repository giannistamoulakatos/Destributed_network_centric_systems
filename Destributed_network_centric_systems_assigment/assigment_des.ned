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

network Assigment_des
{
    parameters:
        int nodes_des=default(100);
        double connection_node=default(0.7);
        double rc=default(1.0);
        int sinkindex=default(1);
        double l=default(1.0);
        @display("bgb=1,1");
        
        submodules:
           node[nodes_des]:Node
           {
               nodeID=1000+index;
               xPos=uniform(0,1);
               yPos=uniform(0,1);
               @display("p=$xPos,$yPos");
           }
           Metrics_node : Metrics_node;
        connections:
            for i=0..nodes_des-1,for j=i+1..nodes_des-1{
                node[i].gates_as++ <--> node[j].gates_as++ if i!=j && sqrt((node[i].xPos-node[j].xPos)^2+(node[i].yPos-node[j].yPos)^2)<rc;
            }
            
}
