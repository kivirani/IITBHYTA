#include <vector>

#include "Automaton_List.h"


using namespace std;

using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::IO_Operators;

void initialize_final_states_simple_Alur(vector<vector<State> > &R_f,Automaton_List &aut_lst)
{
	vector<State> tmp;
	State final;
	final.l.name="s3";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	final.poly.add_constraint(Variable(0)==0);
	final.poly.add_constraint(Variable(1)==0);

	add_trivial_constraints_to_poly(final.poly);
	tmp.push_back(final);


	//cout<<"Final:"<<final.poly<<endl;



	R_f.push_back(tmp);


}




void initialize_final_states_compo_demo(vector<vector<State> > &R_f,Automaton_List &aut_lst)
{
	vector<State> tmp;
	State final;
	final.l.name="one_two";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	final.poly.add_constraint(Variable(0)==0);
	final.poly.add_constraint(Variable(1)==6);

	add_trivial_constraints_to_poly(final.poly);
	tmp.push_back(final);


	//cout<<"Final:"<<final.poly<<endl;



	R_f.push_back(tmp);


}


void initialize_final_states_gas_burner(vector<vector<State> > &R_f,Automaton_List &aut_lst)
{
	vector<State> tmp;
	State final;
	final.l.name="l2";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());

	final.poly.add_constraint(20*Variable(2)>Variable(1));
	final.poly.add_constraint(Variable(1)>=60);


	//final.poly.add_constraint(Variable(0)==0);
	//final.poly.add_constraint(Variable(1)>=0);
	//final.poly.add_constraint(Variable(2)<=1);
	add_trivial_constraints_to_poly(final.poly);
	tmp.push_back(final);






	State final1;
	final1.l.name="l1";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final1.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());

	final1.poly.add_constraint(Variable(0)<=1);
	final1.poly.add_constraint(20*Variable(2)>Variable(1));
	final1.poly.add_constraint(Variable(1)>=60);


	//final.poly.add_constraint(Variable(0)==0);
	//final.poly.add_constraint(Variable(1)>=0);
	//final.poly.add_constraint(Variable(2)<=1);
	add_trivial_constraints_to_poly(final1.poly);


	tmp.push_back(final1);

	R_f.push_back(tmp);
}



void initialize_final_states_water_level_monitor(vector<vector<State> > &R_f,Automaton_List &aut_lst)
{
	vector<State> tmp;
	State final;
	final.l.name="l2";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());

	final.poly.add_constraint(Variable(0)>=0);
	final.poly.add_constraint(Variable(1)>5);


	//final.poly.add_constraint(Variable(0)==0);
	//final.poly.add_constraint(Variable(1)>=0);
	//final.poly.add_constraint(Variable(2)<=1);
	add_trivial_constraints_to_poly(final.poly);
	tmp.push_back(final);


	//cout<<"Final:"<<final.poly<<endl;



	R_f.push_back(tmp);
}








void initialize_final_states_prod(vector<vector<State> > &R_f,Automaton_List &aut_lst)
{
	vector<State> tmp;
	State final;
	final.l.name="l02~l12";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());

	final.poly.add_constraint(Variable(0)>=0);
	final.poly.add_constraint(Variable(1)>5);


	//final.poly.add_constraint(Variable(0)==0);
	//final.poly.add_constraint(Variable(1)>=0);
	//final.poly.add_constraint(Variable(2)<=1);
	add_trivial_constraints_to_poly(final.poly);
	tmp.push_back(final);


	//cout<<"Final:"<<final.poly<<endl;



	R_f.push_back(tmp);



}



/*
	State final1;
	final1.l.name="l1";
	//final.poly.remove_higher_space_dimensions(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
	//dimension_type d=2;
	final1.poly.add_space_dimensions_and_embed(aut_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());

	final1.poly.add_constraint(Variable(0)<=1);
	final1.poly.add_constraint(20*Variable(2)>Variable(1));
	final1.poly.add_constraint(Variable(1)>=60);


	//final.poly.add_constraint(Variable(0)==0);
	//final.poly.add_constraint(Variable(1)>=0);
	//final.poly.add_constraint(Variable(2)<=1);
	add_trivial_constraints_to_poly(final1.poly);


	tmp.push_back(final1);
	*/


/*
void initialize_initial_states(vector<vector<State> > &R_i,Automaton_List &aut_lst)
{
	State init;
	vector<State> tmp;
	for(vector<Automaton>::iterator it=aut_lst.aut_arr.begin();it!=aut_lst.aut_arr.end();it++)
	{
		for(vector<Location>::iterator itt=(*it).initial_loc_lst.location_arr.begin();itt!=(*it).initial_loc_lst.location_arr.end();itt++)
		{
			init.l.name=(*itt).name;
			cout<<"InitLoc:"<<init.l.name<<endl;

			//init.poly.remove_higher_space_dimensions((*it).cntr_var_lst.cntr_var_arr.size());
			init.poly.add_space_dimensions_and_embed((*it).cntr_var_lst.cntr_var_arr.size());
			for(Constraint_System_const_iterator ittt=(*itt).invariants.begin();ittt!=(*itt).invariants.end();ittt++)
			{
				init.poly.add_constraint(*ittt);
			}
			add_trivial_constraints_to_poly(init.poly);

			cout<<"Initial:"<<init.poly<<endl;
			tmp.push_back(init);
		}
	}
	R_i.push_back(tmp);

}
*/
void find_Initial_States(vector<State> &Ri_queue,vector<vector<State> > &R_i,vector<Automaton>::iterator curr,vector<Automaton>::iterator ed)
{
	//cout<<"Start:"<<endl;
	for(vector<Location>::iterator itt=curr->initial_loc_lst.location_arr.begin();itt!=curr->initial_loc_lst.location_arr.end();itt++)
	{
		//Ri_queue.push_back(*itt);
		//cout<<"In here:"<<endl;
		State s;
		s.l.name=(*itt).name;

		s.poly.add_space_dimensions_and_embed(curr->cntr_var_lst.cntr_var_arr.size());

		s.poly.add_constraints((*itt).invariants);


		add_trivial_constraints_to_poly(s.poly);


		Ri_queue.push_back(s);

		if( (curr+1)==ed )
		{
			//R_i.push_back(Ri_queue);
			string tmpnm;
			tmpnm="";
			Constraint_System tmpcs;
			tmpcs.set_space_dimension(curr->cntr_var_lst.cntr_var_arr.size());
			for(vector<State>::iterator it=Ri_queue.begin();it!=Ri_queue.end();it++)
			{
				if(it!=Ri_queue.begin())
				{
					tmpnm=tmpnm+"~";
				}
				tmpnm=tmpnm+it->l.name;

				for(Constraint_System_const_iterator csit=(it->poly).constraints().begin();csit!=(it->poly).constraints().end();csit++)
					tmpcs.insert(*csit);

			}

			vector<State> vst;


			State tmps;
			tmps.poly.add_space_dimensions_and_embed(curr->cntr_var_lst.cntr_var_arr.size());
			tmps.l.name=tmpnm;
			tmps.poly.add_constraints(tmpcs);

			vst.push_back(tmps);
			R_i.push_back(vst);


			/*for(vector<State>::iterator it=Ri_queue.begin();it!=Ri_queue.end();it++)
			{
				cout<<"Generated initloc:"<<it->l.name<<", "<<it->poly<<endl;
			}*/
		}
		else
		{
			find_Initial_States(Ri_queue,R_i,curr+1,ed);
		}

		Ri_queue.pop_back();





	}
}


void initialize_initial_states(vector<vector<State> > &R_i,Automaton_List &aut_lst)
{
	vector<State> Ri_queue;
	//cout<<"A:"<<endl;
	find_Initial_States(Ri_queue,R_i,aut_lst.aut_arr.begin(),aut_lst.aut_arr.end());


	/*State init;
	vector<State> tmp;
	for(vector<Automaton>::iterator it=aut_lst.aut_arr.begin();it!=aut_lst.aut_arr.end();it++)
	{
		for(vector<Location>::iterator itt=(*it).initial_loc_lst.location_arr.begin();itt!=(*it).initial_loc_lst.location_arr.end();itt++)
		{
			init.l.name=(*itt).name;
			cout<<"InitLoc:"<<init.l.name<<endl;

			//init.poly.remove_higher_space_dimensions((*it).cntr_var_lst.cntr_var_arr.size());
			init.poly.add_space_dimensions_and_embed((*it).cntr_var_lst.cntr_var_arr.size());
			for(Constraint_System_const_iterator ittt=(*itt).invariants.begin();ittt!=(*itt).invariants.end();ittt++)
			{
				init.poly.add_constraint(*ittt);
			}
			add_trivial_constraints_to_poly(init.poly);

			cout<<"Initial:"<<init.poly<<endl;
			tmp.push_back(init);
		}
	}
	R_i.push_back(tmp);*/

}

