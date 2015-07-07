#include <cstring>
#include <vector>
#include <map>

#include "Control_Variable_List.h"
#include "Parameter_List.h"
#include "Synchronizing_Label_List.h"
#include "Location_List.h"
#include "Input_Variable_List.h"
#include "Edge_List.h"
#include "State.h"

using namespace std;
using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::IO_Operators;


class LocEdge
{
public:
	string loc;
	Edge e;
};
struct CompareLocEdge
{
	bool operator() (const LocEdge &lhs,const LocEdge &rhs)
	{
		return (lhs.loc.compare(rhs.loc)<0);
	}
};


class Automaton
{
public:
	string name;
	string id;
	Control_Variable_List cntr_var_lst;
	Parameter_List parameter_lst;
	Synchronizing_Label_List syn_lab_lst;
	Input_Variable_List in_var_lst;
	Location_List loc_lst;
	Location_List initial_loc_lst;
	Location_List final_loc_lst;
	Edge_List edge_lst;
	vector<State> region;

	map<string,Location> loc_to_Location;
	map<string,Constraint_System> loc_to_invar;
	map<string,Constraint_System> loc_to_rate;

	map<LocEdge,string,CompareLocEdge> pre_plus_edge_to_post;
	map<LocEdge,string,CompareLocEdge> post_plus_edge_to_pre;

	multimap<string,LocEdge> pre_to_edge_plus_post;
	multimap<string,LocEdge> post_to_edge_plus_pre;
	map<string,string> cntrToautmap;
	void assign_Name(string s);
	void fillRegions();
	void fillMaps();
};
void Automaton::assign_Name(string s)
{
	name=s;
}
void Automaton::fillMaps()
{
	for(vector<Edge>::iterator it=edge_lst.edge_arr.begin();it!=edge_lst.edge_arr.end();it++)
	{
		LocEdge le1;
		le1.loc=(*it).pre;
		le1.e=(*it);

		LocEdge le2;
		le2.loc=(*it).post;
		le2.e=(*it);

		//cout<<"Parsed post as:"<<it->post<<endl;

		pre_to_edge_plus_post.insert(pair<string,LocEdge>((*it).pre,le2));
		post_to_edge_plus_pre.insert(pair<string,LocEdge>((*it).post,le1));


		pre_plus_edge_to_post[le1]=(*it).post;


		post_plus_edge_to_pre[le2]=(*it).pre;

	}
	for(vector<Location>::iterator it=loc_lst.location_arr.begin();it!=loc_lst.location_arr.end();it++)
	{
		loc_to_Location[(*it).name]=(*it);
		loc_to_invar[(*it).name]=(*it).invariants;
		loc_to_rate[(*it).name]=(*it).rate;
	}

	//pair<multimap<string,LocEdge>::iterator,multimap<string,LocEdge>::iterator> mm_to_mm;
	//mm_to_mm=post_to_edge_plus_pre.equal_range("l0");



}

/*void Automaton::fillRegions()
{

	for(vector<Location>::iterator it=loc_lst.location_arr.begin();it!=loc_lst.location_arr.end();it++)
	{
		State s;
		s.l=(*it);

		s.poly.add_space_dimensions_and_embed(cntr_var_lst.cntr_var_arr.size());
		for(Constraint_System_const_iterator itt=s.l.invariants.begin();itt!=s.l.invariants.end();itt++)
		{
			s.poly.add_constraint(*itt);
		}

	}
}
*/

