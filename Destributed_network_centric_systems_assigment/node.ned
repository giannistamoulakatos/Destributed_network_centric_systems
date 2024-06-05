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

//
// TODO auto-generated module
//
simple Node
{
    parameters:
        int nodeID=default(-1);
        double connection_node=default(1);
        double xPos=default(-1);
        double yPos=default(-1);
        int sinkindex=default(1);
        double l=default(1.0);
        
    gates:
        inout gates_as[];
        input node_metric @directIn;
        
}
