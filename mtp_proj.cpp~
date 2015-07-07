#include "mtp_proj.h"


using namespace std;
using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::IO_Operators;







int mainprod() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	//r.open("compo.pha");
	r.open("new_compo.pha");


	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();

	//cout<<"Before calling:"<<aut_lst.aut_arr.size()<<endl;





	vector<vector<State> > R_f,R_i;

	initialize_final_states_prod(R_f,aut_lst);
	//initialize_initial_states(R_i,aut_lst);
	//cout<<"End1:"<<endl;
	Automaton prod_aut=take_product(aut_lst);
	//aut_lst.aut_arr.push_back(prod_aut);

	/*cout<<"Automaton Name:"<<prod_aut.name<<endl;
	cout<<"Control Variable List:";
	for(vector<string>::iterator sit=prod_aut.cntr_var_lst.cntr_var_arr.begin();sit!=prod_aut.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cout<<" "<<(*sit);
	}
	cout<<endl;

	cout<<"Synchronization Label:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=prod_aut.syn_lab_lst.syn_lab_arr.begin();it!=prod_aut.syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;

	cout<<"Parameters:"<<endl;
	for(vector<Parameter>::iterator it=prod_aut.parameter_lst.par_list_arr.begin();it!=prod_aut.parameter_lst.par_list_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;
	cout<<"Initial Location:"<<endl;
	for(vector<Location>::iterator it=prod_aut.initial_loc_lst.location_arr.begin();it!=prod_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/
	cout<<"Location List:"<<endl;
	for(vector<Location>::iterator it=prod_aut.loc_lst.location_arr.begin();it!=prod_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<","<<it->rate<<endl;
	}

	cout<<"Edge List:"<<endl;
	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<" "<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->syn_lab<<endl;
	}
	cout<<"End2:"<<endl;



	int max_iterations=12;


	//cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;




	return 0;
}



int mainreachwaterlevel_monitor() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	r.open("water_level_monitor.pha");
	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();




	vector<vector<State> > R_f,R_i;

	initialize_final_states_water_level_monitor(R_f,aut_lst);
	initialize_initial_states(R_i,aut_lst);
	int max_iterations=12;


	cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;


	return 0;
}
int mainreachgas_burner() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();




	vector<vector<State> > R_f,R_i;

	initialize_final_states_gas_burner(R_f,aut_lst);
	initialize_initial_states(R_i,aut_lst);
	int max_iterations=12;


	cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;


	return 0;
}

int mainreachcompo_demo() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();




	vector<vector<State> > R_f,R_i;

	initialize_final_states_compo_demo(R_f,aut_lst);
	initialize_initial_states(R_i,aut_lst);
	int max_iterations=12;


	cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;


	return 0;
}

int mainreachsimpleAlur() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	r.open("simpleAlur.pha");
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();




	vector<vector<State> > R_f,R_i;

	initialize_final_states_simple_Alur(R_f,aut_lst);
	initialize_initial_states(R_i,aut_lst);
	int max_iterations=12;


	//cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;


	return 0;
}
int mainDisTAtoIcTA()
{
	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	//r.open("compo.pha");
	r.open("new_compo.pha");


	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();

	//cout<<"Before calling:"<<aut_lst.aut_arr.size()<<endl;





	vector<vector<State> > R_f,R_i;

	initialize_final_states_prod(R_f,aut_lst);
	//initialize_initial_states(R_i,aut_lst);
	//cout<<"End1:"<<endl;
	//Automaton prod_aut=take_product(aut_lst);
	Automaton prod_aut=to_ICTA(aut_lst);

	//aut_lst.aut_arr.push_back(prod_aut);

	/*cout<<"Automaton Name:"<<prod_aut.name<<endl;
	cout<<"Control Variable List:";
	for(vector<string>::iterator sit=prod_aut.cntr_var_lst.cntr_var_arr.begin();sit!=prod_aut.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cout<<" "<<(*sit);
	}
	cout<<endl;

	cout<<"Synchronization Label:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=prod_aut.syn_lab_lst.syn_lab_arr.begin();it!=prod_aut.syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;

	cout<<"Parameters:"<<endl;
	for(vector<Parameter>::iterator it=prod_aut.parameter_lst.par_list_arr.begin();it!=prod_aut.parameter_lst.par_list_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;
	cout<<"Initial Location:"<<endl;
	for(vector<Location>::iterator it=prod_aut.initial_loc_lst.location_arr.begin();it!=prod_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/
	cout<<"Location List:"<<endl;
	for(vector<Location>::iterator it=prod_aut.loc_lst.location_arr.begin();it!=prod_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<","<<it->rate<<endl;
	}

	cout<<"Edge List:"<<endl;
	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<" "<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->syn_lab<<endl;
	}
	cout<<"End2:"<<endl;



	int max_iterations=12;


	//cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;




	return 0;

}
vector<Constraint_System> generate_possible_set(int i,int max,int no_clock_var)
{
	vector<Constraint_System> ret;
	for(int k=0;k<=max;k++)
	{
		Constraint_System cs;
		cs.set_space_dimension(no_clock_var);
		cs.insert(Variable(i)==k);
		ret.push_back(cs);
	}
	for(int k=1;k<=max;k++)
	{
		Constraint_System cs;
		cs.set_space_dimension(no_clock_var);
		cs.insert(Variable(i)>k-1);
		cs.insert(Variable(i)<k);
		ret.push_back(cs);
	}
	Constraint_System cs;
	cs.set_space_dimension(no_clock_var);
	cs.insert(Variable(i)>max);
	ret.push_back(cs);



	return ret;

}


vector<Constraint_System> generate_possible_set_for_ICTA(int i,int max,int no_clock_var)
{
	vector<Constraint_System> ret;
	for(int k=0;k<=max;k++)
	{
		Constraint_System cs;
		cs.set_space_dimension(no_clock_var);
		cs.insert(Variable(i)==k);
		ret.push_back(cs);
	}
	for(int k=1;k<=max;k++)
	{
		Constraint_System cs;
		cs.set_space_dimension(no_clock_var);
		cs.insert(Variable(i)>k-1);
		cs.insert(Variable(i)<k);
		ret.push_back(cs);
	}
	Constraint_System cs;
	cs.set_space_dimension(no_clock_var);
	cs.insert(Variable(i)>max);
	ret.push_back(cs);



	return ret;

}


void generate_partial_regions(vector<Constraint_System> &vvstack,vector<vector<Constraint_System> > &partial_result,vector<vector<Constraint_System> >::iterator vvcscurr,vector<vector<Constraint_System> >::iterator vvcsend)
{
	if(vvcscurr==vvcsend)
	{

		partial_result.push_back(vvstack);
		return;
	}
	for(vector<Constraint_System>::iterator it=vvcscurr->begin();it!=vvcscurr->end();it++)
	{
		vvstack.push_back(*it);
		generate_partial_regions(vvstack,partial_result,vvcscurr+1,vvcsend);
		vvstack.pop_back();
	}
	return;
}
void generate_partial_seq_subsets(vector<vector<vector<string> > > &vvvres,vector<vector<string> > &vvstack,vector<string>::iterator vvscurr,vector<string>::iterator vvsend,vector<string>::iterator vvsbegin)
{
	if(vvscurr==vvsend)
	{
		vector<vector<string> > vvstacktmp;
		for(vector<vector<string> >::iterator it=vvstack.begin();it!=vvstack.end();it++)
		{
			vector<string> vs;
			for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
			{
				vs.push_back(*itt);
			}
			sort(vs.begin(),vs.end());
			vvstacktmp.push_back(vs);
		}
		/*cout<<"Pushing:"<<endl;
		for(vector<vector<string> >::iterator it=vvstack.begin();it!=vvstack.end();it++)
		{
			for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
			{
				cout<<(*itt);
			}
			cout<<endl;
		}*/
		//vvvres.push_back(vvstack);
		vvvres.push_back(vvstacktmp);

		return;
	}

	if(vvsbegin==vvscurr)
	{
		vector<string> newset;
		newset.push_back(*vvscurr);
		vvstack.push_back(newset);
		generate_partial_seq_subsets(vvvres,vvstack,vvscurr+1,vvsend,vvsbegin);
		vvstack.pop_back();
	}
	else
	{
		//for inerting into last set choosen
		vector<string> lastset=vvstack.back();
		vvstack.pop_back();
		lastset.push_back(*vvscurr);
		vvstack.push_back(lastset);
		generate_partial_seq_subsets(vvvres,vvstack,vvscurr+1,vvsend,vvsbegin);
		lastset.pop_back();
		vvstack.pop_back();
		vvstack.push_back(lastset);

		//for inserting new set
		vector<string> newset;
		newset.push_back(*vvscurr);
		vvstack.push_back(newset);
		generate_partial_seq_subsets(vvvres,vvstack,vvscurr+1,vvsend,vvsbegin);
		vvstack.pop_back();

	}


	return;

}

vector<vector<vector<string> > > generate_seq_subsets(vector<string> vvs)
{
	vector<vector<vector<string> > > vvvres;
	vector<vector<string> > vvstack;

	/*cout<<"Input:";
	for(vector<string>::iterator it=vvs.begin();it!=vvs.end();it++)
	{
		cout<<(*it)<<",";
	}
	cout<<endl;*/
	generate_partial_seq_subsets(vvvres,vvstack,vvs.begin(),vvs.end(),vvs.begin());

	return vvvres;
}

bool are_equal_vvstring(vector<vector<string> > vvs1,vector<vector<string> > vvs2)
{
	//cout<<"Here:"<<endl;
	vector<vector<string> >::iterator it1=vvs1.begin();
	vector<vector<string> >::iterator it2=vvs2.begin();
	while(it1!=vvs1.end() || it2!=vvs2.end())
	{
		vector<string> s1;
		for(vector<string>::iterator itt=it1->begin();itt!=it1->end();itt++)
		{
			s1.push_back(*itt);
		}
		vector<string> s2;
		for(vector<string>::iterator itt=it2->begin();itt!=it2->end();itt++)
		{
			s2.push_back(*itt);
		}
		//cout<<"Mark1"<<endl;
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		//cout<<"Mark2"<<endl;
		if(!equal(s1.begin(),s1.end(),s2.begin()))
		{
			return false;
		}
		it1++;
		it2++;
		//cout<<"Mark3"<<endl;

	}
	//cout<<"Rahul:"<<endl;
	if(it1==vvs1.end() && it2==vvs2.end() )
		return true;
	return false;
}
vector<pair<vector<Constraint_System>,vector<vector<string> > > > generate_all_combined_constraints(vector<vector<Constraint_System> > vvcs)
{
	vector<pair<vector<Constraint_System>,vector<vector<string> > > > ret;
	vector<Constraint_System> vvstack;
	vector<vector<Constraint_System> > partial_result;
	generate_partial_regions(vvstack,partial_result,vvcs.begin(),vvcs.end());

	//cout<<"Partial result size:"<<partial_result.size()<<endl;
	for(vector<vector<Constraint_System> >::iterator it=partial_result.begin();it!=partial_result.end();it++)
	{
		vector<string> s;
		vector<string> zeros;
		int constrno=0;
		for(vector<Constraint_System>::iterator itt=it->begin();itt!=it->end();itt++)
		{

			int constr_size=0;
			for(Constraint_System_const_iterator csit=itt->begin();csit!=itt->end();csit++)
			{
				constr_size++;
			}

			if(constr_size>1)
			{
				//cout<<(*itt)<<endl;
				//s.push_back(""+(it->end()-itt));
				char stt[100];
				sprintf(stt,"%d",constrno);
				s.push_back(stt);
			}
			else
			{
				if(itt->begin()->is_equality())
				{
					//zeros.push_back(""+(it->end()-itt));
					char stt[100];
					sprintf(stt,"%d",constrno);
					zeros.push_back(stt);
				}

			}
			constrno++;
		}

		if(s.size()>0)
		{
			vector<vector<string> > vvs=generate_all_sequences(s);
			//cout<<"For "<<s.size()<<" vvssize:"<<vvs.size()<<endl;


			for(vector<vector<string> >::iterator vvsit=vvs.begin();vvsit!=vvs.end();vvsit++)
			{

				vector<vector<vector<string> > > subsets=generate_seq_subsets(*vvsit);
				//cout<<"For vvsit "<<vvsit->size()<<" subsize:"<<subsets.size()<<endl;
				for(vector<vector<vector<string> > >::iterator subit=subsets.begin();subit!=subsets.end();subit++)
				{
					bool flg=false;
					for(vector<vector<vector<string> > >::iterator subiit=subsets.begin();subiit!=subit;subiit++)
					{

						if((*subiit)==(*subit))
						//if(are_equal_vvstring((*subiit),(*subit)))
						{
							flg=true;
							break;
						}

					}
					if(flg==false)
					{
						vector< vector<string> > offsetseq;
						if(zeros.size()>0)
							offsetseq.push_back(zeros);
						for(vector<vector<string> >::iterator offit=subit->begin();offit!=subit->end();offit++)
						{
							if(offit->size()>0)
								offsetseq.push_back(*offit);
						}
						//pair<Constraint_System,vector<vector<string> > > p(tmpcs,(*subit));
						pair<vector<Constraint_System>,vector<vector<string> > > p((*it),offsetseq);


						bool yes=false;
						for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator itc=ret.begin();itc!=ret.end();itc++)
						{
							if((*itc)==p)
							{
								yes=true;
								break;
							}
						}
						if(yes==false)
						{
							ret.push_back(p);

							//cout<<"subit size:"<<subit->size()<<endl;
							vector<Constraint_System> fir=p.first;
							vector<vector<string> > sec=p.second;
							/*for(vector<Constraint_System>::iterator itt=fir.begin();itt!=fir.end();itt++)
							{
								cout<<(*itt)<<",";
							}
							cout<<endl;
							for(vector<vector<string> >::iterator itt=sec.begin();itt!=sec.end();itt++)
							{
								for(vector<string>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
								{
									cout<<(*ittt)<<",";
								}
								cout<<endl;
							}*/

						}

					}

				}
			}
		}
		else
		{
			vector<vector<string> > st;
			if(zeros.size()>0)
				st.push_back(zeros);
			pair<vector<Constraint_System>,vector<vector<string> > > p((*it),st);


			bool yes=false;
			for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator itc=ret.begin();itc!=ret.end();itc++)
			{
				if((*itc)==p)
				{
					yes=true;
					break;
				}
			}
			if(yes==false)
			{
				ret.push_back(p);

				//cout<<"Else part:"<<endl;
				vector<Constraint_System> fir=p.first;
				vector<vector<string> > sec=p.second;
				/*for(vector<Constraint_System>::iterator itt=fir.begin();itt!=fir.end();itt++)
				{
					cout<<(*itt)<<",";
				}
				cout<<endl;
				for(vector<vector<string> >::iterator itt=sec.begin();itt!=sec.end();itt++)
				{
					for(vector<string>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
					{
						cout<<(*ittt)<<",";
					}
					cout<<endl;
				}*/

			}





		}

	}
	//cout<<"Region size:"<<ret.size()<<endl;
	/*for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator it=ret.begin();it!=ret.end();it++)
	{
		vector<Constraint_System> fir=it->first;
		vector<vector<string> > sec=it->second;
		for(vector<Constraint_System>::iterator itt=fir.begin();itt!=fir.end();itt++)
		{
			cout<<(*itt)<<",";
		}
		cout<<endl;
		for(vector<vector<string> >::iterator itt=sec.begin();itt!=sec.end();itt++)
		{
			for(vector<string>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
			{
				cout<<(*ittt)<<",";
			}
			cout<<endl;
		}
	}*/
	return ret;
}

vector<vector<Constraint_System> > generate_all_combined_constraints_for_ICTA(vector<vector<Constraint_System> > vvcs)
{
	vector<vector<Constraint_System> > ret;
	vector<Constraint_System> vvstack;
	vector<vector<Constraint_System> > partial_result;
	generate_partial_regions(vvstack,partial_result,vvcs.begin(),vvcs.end());

	return partial_result;
	
	//cout<<"Region size:"<<ret.size()<<endl;
	/*for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator it=ret.begin();it!=ret.end();it++)
	{
		vector<Constraint_System> fir=it->first;
		vector<vector<string> > sec=it->second;
		for(vector<Constraint_System>::iterator itt=fir.begin();itt!=fir.end();itt++)
		{
			cout<<(*itt)<<",";
		}
		cout<<endl;
		for(vector<vector<string> >::iterator itt=sec.begin();itt!=sec.end();itt++)
		{
			for(vector<string>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
			{
				cout<<(*ittt)<<",";
			}
			cout<<endl;
		}
	}*/
	//return ret;
}




vector<pair<vector<Constraint_System>,vector<vector<string> > > > generate_Regions(int no_clock_var,vector<int> max)
{
	vector<vector<Constraint_System> > vvcs;
	for(int i=0;i<no_clock_var;i++)
	{
		vector<Constraint_System> tmp=generate_possible_set(i,max[i],no_clock_var);
		vvcs.push_back(tmp);
		//cout<<"For clock, region size:"<<tmp.size()<<endl;
	}

	vector<pair<vector<Constraint_System>,vector<vector<string> > > > ret=generate_all_combined_constraints(vvcs);

	return ret;
}

vector<vector<Constraint_System> > generate_Regions_for_ICTA(int no_clock_var,vector<int> max)
{
	vector<vector<Constraint_System> > vvcs;
	for(int i=0;i<no_clock_var;i++)
	{
		vector<Constraint_System> tmp=generate_possible_set_for_ICTA(i,max[i],no_clock_var);
		vvcs.push_back(tmp);
		//cout<<"For clock, region size:"<<tmp.size()<<endl;
	}

	vector<vector<Constraint_System> > ret=generate_all_combined_constraints_for_ICTA(vvcs);

	return ret;
}


vector<string> findSetofResetVar(Constraint_System resets)
{
	vector<string> resetvar;
	for(Constraint_System_const_iterator csit=resets.begin();csit!=resets.end();csit++)
	{
		int i=0;
		for(i=0;i<resets.space_dimension();i++)
		{
			if(csit->coefficient(Variable(i))!=0)
				break;
		}
		char a[100];
		sprintf(a,"%d",i);
		resetvar.push_back(a);
	}
	sort(resetvar.begin(),resetvar.end());
	return resetvar;
}
pair<vector<Constraint_System>,vector<vector<string> > > find_reset_region(pair<vector<Constraint_System>,vector<vector<string> > > p,Constraint_System resets)
{
	vector<Constraint_System> vcs=p.first;
	vector<vector<string> > vvs=p.second;

	vector<string> vs=findSetofResetVar(resets);
	//cout<<"vs.size():"<<vs.size()<<endl;


	for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
	{
		//cout<<"Clearing:"<<vcs[atoi((*it).c_str())]<<endl;
		vcs[atoi((*it).c_str())].clear();
		for(Constraint_System_const_iterator csit=resets.begin();csit!=resets.end();csit++)
		{
			if(csit->coefficient(Variable(atoi((*it).c_str())))!=0)
			{
				vcs[atoi((*it).c_str())].insert(*csit);
				break;
			}
		}
	}
	vector<vector<string> > retvvs;
	for(vector<vector<string> >::iterator it=vvs.begin();it!=vvs.end();it++)
	{
		vector<string> s;
		for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			bool flg=false;
			for(vector<string>::iterator ittt=vs.begin();ittt!=vs.end();ittt++)
			{
				if((*itt)==(*ittt))
				{
					flg=true;
					break;
				}
			}
			if(flg==false)
			{
				s.push_back(*itt);
			}
		}
		if(s.size()>0)
		{
			retvvs.push_back(s);
		}
	}

	if(retvvs.size()==0)
	{
		retvvs.push_back(vs);
		pair<vector<Constraint_System>,vector<vector<string> > > ret(vcs,retvvs);

		return ret;

	}

	vector<string> fr=retvvs.front();
	int cnt=0;
	for(Constraint_System_const_iterator csit=vcs[atoi(fr.begin()->c_str())].begin();csit!=vcs[atoi(fr.begin()->c_str())].end();csit++)
	{
		cnt++;
	}
	if(cnt==1)
	{
		if(vcs[atoi(fr.begin()->c_str())].begin()->is_equality())
	    {
			retvvs.erase(retvvs.begin());
			for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
			{
				fr.push_back(*it);
			}
			sort(fr.begin(),fr.end());
			retvvs.insert(retvvs.begin(),fr);

	    }
		else
		{
			retvvs.insert(retvvs.begin(),vs);
		}
	}
	else
	{
		retvvs.insert(retvvs.begin(),vs);
	}

	pair<vector<Constraint_System>,vector<vector<string> > > ret(vcs,retvvs);

	return ret;
}

vector<Constraint_System> find_reset_region_for_ICTA(vector<Constraint_System> p,Constraint_System resets)
{
	vector<Constraint_System> vcs=p;
	

	vector<string> vs=findSetofResetVar(resets);
	//cout<<"vs.size():"<<vs.size()<<endl;


	for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
	{
		//cout<<"Clearing:"<<vcs[atoi((*it).c_str())]<<endl;
		vcs[atoi((*it).c_str())].clear();
		for(Constraint_System_const_iterator csit=resets.begin();csit!=resets.end();csit++)
		{
			if(csit->coefficient(Variable(atoi((*it).c_str())))!=0)
			{
				vcs[atoi((*it).c_str())].insert(*csit);
				break;
			}
		}
	}
	

	
	

	//pair<vector<Constraint_System>,vector<vector<string> > > ret(vcs,retvvs);

	return vcs;
}





pair<vector<Constraint_System>,vector<vector<string> > > find_time_successor_region(pair<vector<Constraint_System>,vector<vector<string> > > p,vector<int> max)
{
	vector<Constraint_System> retvcs;


	vector<Constraint_System> vcs;
	vcs=p.first;
	vector<vector<string> > pseqvector;
	pseqvector=p.second;
	int varno=0;
	//cout<<"Seqvectsize:"<<pseqvector.size()<<endl;
	/*for(vector<Constraint_System>::iterator it=vcs.begin();it!=vcs.end();it++)
	{
		cout<<(*it)<<endl;
	}*/

	if(pseqvector.size()==0)
		return p;

	if(pseqvector.size()==1)
	{

		vector<string> vsfront=pseqvector.front();

		vector<string> newvsfront=vsfront;

		for(vector<Constraint_System>::iterator it=vcs.begin();it!=vcs.end();it++)
		{

			Constraint_System tmpcs;
			tmpcs.set_space_dimension(it->space_dimension());

			int cnt=0;
			//cout<<(*it)<<endl;
			for(Constraint_System_const_iterator csit=it->begin();csit!=it->end();csit++)
			{
				cnt++;

			}
			if(cnt==1)
			{
				if(it->begin()->is_equality())
				{
					//cout<<"Hey:"<<it->begin()->inhomogeneous_term().get_si()<<endl;

					int lower=abs(it->begin()->inhomogeneous_term().get_si());
					int upper=lower+1;
					tmpcs.insert(Variable(varno)>lower);
					if(lower!=max[varno])
					{
						tmpcs.insert(Variable(varno)<upper);
					}
					else
					{
						//remove varno from group
						for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
						{
							if(varno==atoi(ipt->c_str()))
							{
								(*ipt)="";
								break;
							}
						}


					}
				}
				else
				{
					tmpcs.insert(*(it->begin()));
				}

			}
			else
			{
				int maxinhomo=0;
				int inhomo;
				for(Constraint_System_const_iterator csit=it->begin();csit!=it->end();csit++)
				{
					inhomo=abs(csit->inhomogeneous_term().get_si());
					if(maxinhomo<inhomo)
					{
						maxinhomo=inhomo;
					}
				}
				tmpcs.insert(Variable(varno)==maxinhomo);
			}

			retvcs.push_back(tmpcs);
			varno++;
		}

		pseqvector.erase(pseqvector.begin());

		vector<string> tmpvs;
		for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
		{
			if((*ipt)!="")
				tmpvs.push_back(*ipt);
		}
		newvsfront=tmpvs;

		if(newvsfront.size()>0)
			pseqvector.insert(pseqvector.begin(),newvsfront);

	}
	else
	{
		vector<string> vsfront=pseqvector.front();
		vector<string> vsback=pseqvector.back();

		vector<string> newvsfront=vsfront;
		vector<string> newvsback=vsback;
		//cout<<"Indeed:"<<endl;
		/*for(vector<vector<string> >::iterator itp=pseqvector.begin();itp!=pseqvector.end();itp++)
		{
			for(vector<string>::iterator ittp=itp->begin();ittp!=itp->end();ittp++)
			{
				cout<<(*ittp)<<",";
			}
			cout<<endl;
		}

		for(vector<Constraint_System>::iterator itp=vcs.begin();itp!=vcs.end();itp++)
		{
			cout<<(*itp)<<endl;
		}*/
		if(vcs[atoi(vsfront.begin()->c_str())].begin()->is_equality())
		{
			for(vector<string>::iterator it=vsfront.begin();it!=vsfront.end();it++)
			{
				Constraint_System cs;
				cs.set_space_dimension(vcs[atoi(it->c_str())].space_dimension());
				cs=vcs[atoi(it->c_str())];
				vcs[atoi(it->c_str())].clear();

				Constraint_System newcs;
				newcs.set_space_dimension(cs.space_dimension());

				int cnt=0;
				for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
				{
					cnt++;
				}

				if(cnt==1)
				{
					if(cs.begin()->is_equality())
					{

						int inhomo=abs(cs.begin()->inhomogeneous_term().get_si());
						newcs.insert(Variable(atoi(it->c_str()))>inhomo);
						if(inhomo!=max[atoi(it->c_str())])
							newcs.insert(Variable(atoi(it->c_str()))<(inhomo+1));
						else
						{
							//remove this from set
							for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
							{
								if(atoi(it->c_str())==atoi(ipt->c_str()))
								{
									(*ipt)="";
									break;
								}
							}

						}

					}
					else
					{
						newcs.insert(*(cs.begin()));
					}
				}
				else
				{

					for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
					{
						newcs.insert(*csit);
					}

				}

				vcs[atoi(it->c_str())]=newcs;

			}
			retvcs=vcs;

			//pseqvector.pop_back();
			pseqvector.erase(pseqvector.begin());

			vector<string> tmpvs;
			for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
			{
				if((*ipt)!="")
					tmpvs.push_back(*ipt);
			}
			newvsfront=tmpvs;
			if(newvsfront.size()>0)
				pseqvector.insert(pseqvector.begin(),newvsfront);
		}
		else
		{

			for(vector<string>::iterator it=vsback.begin();it!=vsback.end();it++)
			{
				Constraint_System cs;
				cs.set_space_dimension(vcs[atoi(it->c_str())].space_dimension());
				cs=vcs[atoi(it->c_str())];
				vcs[atoi(it->c_str())].clear();

				Constraint_System newcs;
				newcs.set_space_dimension(cs.space_dimension());

				int cnt=0;
				for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
				{
					cnt++;
				}

				if(cnt==1)
				{
					if(cs.begin()->is_equality())
					{
						//this is not possible
						cout<<"This is not possible"<<endl;
					}
					else
					{
						newcs.insert(*(cs.begin()));
					}
				}
				else
				{
					int maxinhomo=0;
					int inhomo;
					for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
					{
						inhomo=abs(csit->inhomogeneous_term().get_si());
						if(maxinhomo<inhomo)
						{
							maxinhomo=inhomo;
						}
					}
					newcs.insert(Variable(atoi(it->c_str()))==maxinhomo);
				}

				vcs[atoi(it->c_str())]=newcs;
			}

			for(vector<string>::iterator it=vsfront.begin();it!=vsfront.end();it++)
			{
				Constraint_System cs;
				cs.set_space_dimension(vcs[atoi(it->c_str())].space_dimension());
				cs=vcs[atoi(it->c_str())];
				vcs[atoi(it->c_str())].clear();

				Constraint_System newcs;
				newcs.set_space_dimension(cs.space_dimension());

				int cnt=0;
				for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
				{
					cnt++;
				}

				if(cnt==1)
				{
					if(cs.begin()->is_equality())
					{

						int inhomo=abs(cs.begin()->inhomogeneous_term().get_si());
						newcs.insert(Variable(atoi(it->c_str()))>inhomo);
						if(inhomo!=max[atoi(it->c_str())])
							newcs.insert(Variable(atoi(it->c_str()))<(inhomo+1));
						else
						{
							//remove this from set
							for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
							{
								if(atoi(it->c_str())==atoi(ipt->c_str()))
								{
									(*ipt)="";
									break;
								}
							}

						}

					}
					else
					{
						newcs.insert(*(cs.begin()));
					}
				}
				else
				{

					for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
					{
						newcs.insert(*csit);
					}

				}

				vcs[atoi(it->c_str())]=newcs;

			}

			retvcs=vcs;

			pseqvector.pop_back();
			pseqvector.erase(pseqvector.begin());

			vector<string> tmpvs;
			for(vector<string>::iterator ipt=newvsfront.begin();ipt!=newvsfront.end();ipt++)
			{
				if((*ipt)!="")
					tmpvs.push_back(*ipt);
			}
			newvsfront=tmpvs;
			if(newvsfront.size()>0)
				pseqvector.insert(pseqvector.begin(),newvsfront);


			vector<string> tmpvs1;
			for(vector<string>::iterator ipt=newvsback.begin();ipt!=newvsback.end();ipt++)
			{
				if((*ipt)!="")
					tmpvs1.push_back(*ipt);
			}
			newvsback=tmpvs1;
			if(newvsback.size()>0)
				pseqvector.insert(pseqvector.begin(),newvsback);
		}


		/*cout<<"After size:"<<pseqvector.size()<<endl;
		for(vector<vector<string> >::iterator itp=pseqvector.begin();itp!=pseqvector.end();itp++)
		{
			for(vector<string>::iterator ittp=itp->begin();ittp!=itp->end();ittp++)
			{
				cout<<(*ittp)<<",";
			}
			cout<<endl;
		}

		for(vector<Constraint_System>::iterator itp=retvcs.begin();itp!=retvcs.end();itp++)
		{
			cout<<(*itp)<<endl;
		}*/
		//int q;
		//cin>>q;
	}

	//cout<<"End of time successor"<<endl;



	pair<vector<Constraint_System>,vector<vector<string> > > ret(retvcs,pseqvector);
	return ret;


}


void find_all_subsets_of(vector<int>::iterator cur,vector<int>::iterator eend,vector<int> &tmpstack,vector<vector<int> > &subsets)
{
	if(cur==eend)
	{
		if(tmpstack.size()>0)
		{
			vector<int> tmp(tmpstack.begin(),tmpstack.end());
			if(subsets.end()==find(subsets.begin(),subsets.end(),tmp))
			{
				subsets.push_back(tmp);
			}
		}
		return;
	}
	tmpstack.push_back(*cur);
	find_all_subsets_of(cur+1,eend,tmpstack,subsets);
	tmpstack.pop_back();
	find_all_subsets_of(cur+1,eend,tmpstack,subsets);
}

int find_Max_Bound_of_Constraint_System(Constraint_System cs, int i)
{
	int ret=0,inhomo;
	for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
	{
		if(csit->is_equality())
		{

			if(csit->coefficient(Variable(i))!=0)
			{
				inhomo=csit->inhomogeneous_term().get_si()*(-1);
				if(ret<inhomo)
					ret=inhomo;
				//cout<<inhomo<<endl;
				
			}


		}
		else
		{
			//cout<<(*csit)<<" is inequality "<<endl;
			if(csit->is_nonstrict_inequality())
			{
				//cout<<(*csit)<<" is not strict inequality ";
				
				if(csit->coefficient(Variable(i))!=0)
				{
					if(csit->coefficient(Variable(i))<0)
					{
						inhomo=csit->inhomogeneous_term().get_si();
						if(ret<inhomo)
							ret=inhomo;
					}
					else
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(ret<inhomo)
							ret=inhomo;
					}
					//cout<<inhomo<<endl;
					
				}
			
			}
			else
			{

				if(csit->coefficient(Variable(i))!=0)
				{
					if(csit->coefficient(Variable(i))<0)
					{
						inhomo=csit->inhomogeneous_term().get_si();
						if(ret<inhomo)
							ret=inhomo;
					}
					else
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(ret<inhomo)
							ret=inhomo;
					}

					
				}
				
			}


		}
	}
	return ret;
}

vector<Constraint_System> apply_evolve(vector<Constraint_System> p,vector<int> subset,vector<int> max)
{
	
	vector<Constraint_System> ret=p;
	for(vector<int>::iterator it=subset.begin();it!=subset.end();it++)
	{
		//ret[*it]=update(ret[*it],max[*it]);
			
		int size=0;
		for(Constraint_System_const_iterator csit=p[*it].begin();csit!=p[*it].end();csit++)
		{
			size++;
		}		
		

		int b=find_Max_Bound_of_Constraint_System(p[*it],*it);
		//if(b==max[*it] && p[*it].size()==1)
		if(b==max[*it] && size==1)
		{
			Constraint_System tmp;
			tmp.set_space_dimension(max.size());
			tmp.insert(Variable(*it)>max[*it]);
			ret[*it].clear();
			ret[*it]=tmp;
		}			
		else
		{
			
			//if(p[*it].size()==1)
			if(size==1)		
			{
				Constraint_System tmp;
				tmp.set_space_dimension(max.size());
				tmp.insert(Variable(*it)>b);
				tmp.insert(Variable(*it)<b+1);
				ret[*it].clear();
				ret[*it]=tmp;
			}
			else
			{
				//size will be two
				Constraint_System tmp;
				tmp.set_space_dimension(max.size());
				tmp.insert(Variable(*it)==b);
				ret[*it].clear();
				ret[*it]=tmp;
			}
		}
		
	}
	return ret;
}

vector<vector<Constraint_System> > find_time_successor_region_for_ICTA(vector<Constraint_System> p,vector<int> max,Automaton time_aut)
{
	vector<vector<Constraint_System> > retvcs;
	vector<int> intervals;	
	vector<int> points;	
	int t=0;
	for(vector<Constraint_System>::iterator it=p.begin();it!=p.end();it++)
	{
		int size=0;
		for(Constraint_System_const_iterator csit=it->begin();csit!=it->end();csit++)
		{
			size++;
		}
		//if(it->size()>1)
		if(size>1)
		{
			intervals.push_back(t);
		}
		else
		{	
			if(it->begin()->is_equality())
			{
				points.push_back(t);	
			}
			else
			{
				//discard this type of clocks
			}
		}
		t++;
	}

	//vector<vector<Constraint_System> > retvcs;
	vector<int> tmpstack;
	vector<vector<int> > subsets;
	find_all_subsets_of(intervals.begin(),intervals.end(),tmpstack,subsets);
	
	tmpstack.clear();
	//stack<int> tmpstack2;
	//vector<vector<int> > pointsubsets;
	find_all_subsets_of(points.begin(),points.end(),tmpstack,subsets);
	

	for(vector<vector<int> >::iterator it=subsets.begin();it!=subsets.end();it++)
	{
		vector<Constraint_System> vcs=apply_evolve(p,*it,max);
		retvcs.push_back(vcs);
	}

	return retvcs;


}







void mainRegionAutomata()
{
	vector<int> max;
	max.push_back(1);
	max.push_back(2);
	vector<pair<vector<Constraint_System>,vector<vector<string> > > > vcs=generate_Regions(2,max);

	/*for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator it=vcs.begin();it!=vcs.end();it++)
	{
		vector<vector<string> > vvs;
		vvs=it->second;
		for(vector<vector<string> >::iterator itt=vvs.begin();itt!=vvs.end();itt++)
		{
			for(vector<string>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
			{
				cout<<(*ittt)<<",";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}*/

	cout<<"Size:"<<vcs.size()<<endl;

	vector<Constraint_System> vcs1;
	Constraint_System cs;
	cs.set_space_dimension(2);
	cs.insert(Variable(0)==2);
	//cs.insert(Variable(0)<1);
	//cs.insert(Variable(0)<2);
	vcs1.push_back(cs);
	Constraint_System cs1;
	cs1.set_space_dimension(2);
	cs1.insert(Variable(1)>2);
	//cs1.insert(Variable(1)<2);
	vcs1.push_back(cs1);
	vector<vector<string> > vvs;
	vector<string> vs1;
	vs1.push_back("0");
	vvs.push_back(vs1);

	vector<string> vs2;
	vs2.push_back("1");
	vvs.push_back(vs2);

	pair<vector<Constraint_System>,vector<vector<string> > > p(vcs1,vvs);

	pair<vector<Constraint_System>,vector<vector<string> > > q=find_time_successor_region(p,max);




	cout<<"Output1:"<<endl;
	for(vector<Constraint_System>::iterator it=q.first.begin();it!=q.first.end();it++)
	{
		cout<<(*it)<<endl;
	}
	for(vector<vector<string> >::iterator it=q.second.begin();it!=q.second.end();it++)
	{
		for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			cout<<(*itt)<<",";
		}
		cout<<endl;
	}
	//find_reset_region(pair<vector<Constraint_System>,vector<vector<string> > > p,Constraint_System resets)
	Constraint_System resets;
	resets.set_space_dimension(2);
	resets.insert(Variable(1)==1);
	pair<vector<Constraint_System>,vector<vector<string> > > r=find_reset_region(p,resets);

	cout<<"Output2:"<<endl;
	for(vector<Constraint_System>::iterator it=r.first.begin();it!=r.first.end();it++)
	{
		cout<<(*it)<<endl;
	}
	for(vector<vector<string> >::iterator it=r.second.begin();it!=r.second.end();it++)
	{
		for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			cout<<(*itt)<<",";
		}
		cout<<endl;
	}


	cout<<"End:"<<endl;

}

vector<int> find_Max_Bounds(Automaton region_aut)
{
	vector<int> maxbound;
	for(int i=0;i<region_aut.cntr_var_lst.cntr_var_arr.size();i++)
	{
		maxbound.push_back(0);
	}
	int inhomo;
	//cout<<"Came here:"<<region_aut.edge_lst.edge_arr.size()<<endl;

	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		//cout<<(it->guards)<<" is current constraint"<<endl;
		for(Constraint_System_const_iterator csit=it->guards.begin();csit!=it->guards.end();csit++)
		{
			//cout<<(*csit)<<" is current constraint"<<endl;
			if(csit->is_equality())
			{
				//cout<<(*csit)<<" is equality ";
				for(int i=0;i<maxbound.size();i++)
				{
					if(csit->coefficient(Variable(i))!=0)
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(maxbound[i]<inhomo)
							maxbound[i]=inhomo;
						//cout<<inhomo<<endl;
						break;
					}
				}

			}
			else
			{
				//cout<<(*csit)<<" is inequality "<<endl;
				if(csit->is_nonstrict_inequality())
				{
					//cout<<(*csit)<<" is not strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							//cout<<inhomo<<endl;
							break;
						}
					}
				}
				else
				{
					//cout<<(*csit)<<" is strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}

							//cout<<inhomo<<endl;
							break;
						}
					}
				}


			}
		}
	}
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		//cout<<(it->guards)<<" is current constraint"<<endl;
		for(Constraint_System_const_iterator csit=it->updates.begin();csit!=it->updates.end();csit++)
		{
			//cout<<(*csit)<<" is current constraint"<<endl;
			if(csit->is_equality())
			{
				//cout<<(*csit)<<" is equality ";
				for(int i=0;i<maxbound.size();i++)
				{
					if(csit->coefficient(Variable(i))!=0)
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(maxbound[i]<inhomo)
							maxbound[i]=inhomo;
						//cout<<inhomo<<endl;
						break;
					}
				}

			}
			else
			{
				//cout<<(*csit)<<" is inequality "<<endl;
				if(csit->is_nonstrict_inequality())
				{
					//cout<<(*csit)<<" is not strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							//cout<<inhomo<<endl;
							break;
						}
					}
				}
				else
				{
					//cout<<(*csit)<<" is strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}

							//cout<<inhomo<<endl;
							break;
						}
					}
				}


			}
		}
	}
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		//cout<<(it->guards)<<" is current constraint"<<endl;
		for(Constraint_System_const_iterator csit=it->invariants.begin();csit!=it->invariants.end();csit++)
		{
			//cout<<(*csit)<<" is current constraint"<<endl;
			if(csit->is_equality())
			{
				//cout<<(*csit)<<" is equality ";
				for(int i=0;i<maxbound.size();i++)
				{
					if(csit->coefficient(Variable(i))!=0)
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(maxbound[i]<inhomo)
							maxbound[i]=inhomo;
						//cout<<inhomo<<endl;
						break;
					}
				}

			}
			else
			{
				//cout<<(*csit)<<" is inequality "<<endl;
				if(csit->is_nonstrict_inequality())
				{
					//cout<<(*csit)<<" is not strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							//cout<<inhomo<<endl;
							break;
						}
					}
				}
				else
				{
					//cout<<(*csit)<<" is strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}

							//cout<<inhomo<<endl;
							break;
						}
					}
				}


			}
		}
	}
	for(vector<Location>::iterator it=region_aut.initial_loc_lst.location_arr.begin();it!=region_aut.initial_loc_lst.location_arr.end();it++)
	{
		//cout<<(it->guards)<<" is current constraint"<<endl;
		for(Constraint_System_const_iterator csit=it->invariants.begin();csit!=it->invariants.end();csit++)
		{
			//cout<<(*csit)<<" is current constraint"<<endl;
			if(csit->is_equality())
			{
				//cout<<(*csit)<<" is equality ";
				for(int i=0;i<maxbound.size();i++)
				{
					if(csit->coefficient(Variable(i))!=0)
					{
						inhomo=csit->inhomogeneous_term().get_si()*(-1);
						if(maxbound[i]<inhomo)
							maxbound[i]=inhomo;
						//cout<<inhomo<<endl;
						break;
					}
				}

			}
			else
			{
				//cout<<(*csit)<<" is inequality "<<endl;
				if(csit->is_nonstrict_inequality())
				{
					//cout<<(*csit)<<" is not strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							//cout<<inhomo<<endl;
							break;
						}
					}
				}
				else
				{
					//cout<<(*csit)<<" is strict inequality ";
					for(int i=0;i<maxbound.size();i++)
					{
						if(csit->coefficient(Variable(i))!=0)
						{
							if(csit->coefficient(Variable(i))<0)
							{
								inhomo=csit->inhomogeneous_term().get_si();
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}
							else
							{
								inhomo=csit->inhomogeneous_term().get_si()*(-1);
								if(maxbound[i]<inhomo)
									maxbound[i]=inhomo;
							}

							//cout<<inhomo<<endl;
							break;
						}
					}
				}


			}
		}
	}
	
	return  maxbound;
}

NNC_Polyhedron generate_polyhedra_from(pair<vector<Constraint_System>,vector<vector<string> > > st)
{
	/*for(vector<vector<string> >::iterator itp=st.second.begin();itp!=st.second.end();itp++)
	{
		for(vector<string>::iterator ittp=itp->begin();ittp!=itp->end();ittp++)
		{
			cout<<(*ittp)<<",";
		}
		cout<<endl;
	}

	for(vector<Constraint_System>::iterator itp=st.first.begin();itp!=st.first.end();itp++)
	{
		cout<<(*itp)<<endl;
	}*/


	NNC_Polyhedron ret;
	ret.add_space_dimensions_and_embed(st.first.begin()->space_dimension());

	vector<int> minimum;
	vector<int> maximum;

	int varno=0;
	for(vector<Constraint_System>::iterator it=st.first.begin();it!=st.first.end();it++)
	{
		//cout<<"CS:"<<(*it)<<endl;
		ret.add_constraints(*it);

		int cnt=0;
		for(Constraint_System_const_iterator csit=it->begin();csit!=it->end();csit++)
		{
			cnt++;
		}

		if(cnt==1)
		{
			if(it->begin()->is_equality())
			{
				//minimum[varno]=it->begin()->inhomogeneous_term().get_si()*(-1);
				minimum.push_back(it->begin()->inhomogeneous_term().get_si()*(-1));
				//maximum[varno]=it->begin()->inhomogeneous_term().get_si()*(-1);
				maximum.push_back(it->begin()->inhomogeneous_term().get_si()*(-1));
			}
			else
			{
				//minimum[varno]=it->begin()->inhomogeneous_term().get_si()*(-1);
				minimum.push_back(it->begin()->inhomogeneous_term().get_si()*(-1));

				//maximum[varno]=(-1);
				maximum.push_back(-1);
			}
		}
		else
		{
			for(Constraint_System_const_iterator csit=it->begin();csit!=it->end();csit++)
			{
				if(csit->coefficient(Variable(varno))>0)
				{
					//minimum[varno]=csit->inhomogeneous_term().get_si()*(-1);
					minimum.push_back(csit->inhomogeneous_term().get_si()*(-1));
				}
				else
				{
					//coefficient is less than 0
					//maximum[varno]=csit->inhomogeneous_term().get_si();
					maximum.push_back(csit->inhomogeneous_term().get_si());
				}
			}

		}
		varno++;
	}

	//cout<<"atleast came here:"<<endl;

	vector<vector<string> > vvs=st.second;

	for(vector<vector<string> >::iterator it=vvs.begin();it!=vvs.end();it++)
	{
		for(vector<vector<string> >::iterator itt=it;itt!=vvs.end();itt++)
		{
			if(itt==it)
			{
				int firstvarno=atoi(it->begin()->c_str());
				for(vector<string>::iterator ittt=it->begin();ittt!=it->end();ittt++)
				{
					if(ittt!=it->begin())
					{
						int currvarno=atoi(ittt->c_str());
						Constraint c;
						c.set_space_dimension(st.first.begin()->space_dimension());
						c=(Variable(firstvarno)-Variable(currvarno)==(minimum[firstvarno]-minimum[currvarno]));
						ret.add_constraint(c);

					}
				}
			}
			else
			{
				int firstvarno=atoi(it->begin()->c_str());
				int currvarno=atoi(itt->begin()->c_str());
				Constraint c;
				c.set_space_dimension(st.first.begin()->space_dimension());
				c=(Variable(firstvarno)-Variable(currvarno)<(minimum[firstvarno]-minimum[currvarno]));
				ret.add_constraint(c);
			}
		}
	}



	//cout<<"End ttt:"<<endl;
	//cout<<"Output:"<<ret<<endl;
	//int q;
	//cin>>q;
	return ret;
}


NNC_Polyhedron generate_polyhedra_from_for_ICTA(vector<Constraint_System> st)
{
	
	NNC_Polyhedron ret;
	ret.add_space_dimensions_and_embed(st.begin()->space_dimension());

	
	for(vector<Constraint_System>::iterator it=st.begin();it!=st.end();it++)
	{
		//cout<<"CS:"<<(*it)<<endl;
		ret.add_constraints(*it);
	
	}

	
	return ret;
}





vector<pair<vector<Constraint_System>,vector<vector<string> > > > find_Regions_satisfying_guards(vector<pair<vector<Constraint_System>,vector<vector<string> > > > vcs,Constraint_System guards)
{
	vector<pair<vector<Constraint_System>,vector<vector<string> > > > ret;
	//cout<<"Mark:"<<vcs.size()<<endl;
	for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator it=vcs.begin();it!=vcs.end();it++)
	{

		NNC_Polyhedron region;
		region.add_space_dimensions_and_embed(guards.space_dimension());
		region=generate_polyhedra_from(*it);
		//cout<<"Created polyhedra:"<<endl;


		NNC_Polyhedron guardpoly;
		guardpoly.add_space_dimensions_and_embed(region.space_dimension());
		guardpoly.add_constraints(guards);

		if(!region.is_empty())
		{
			if(guardpoly.contains(region))
			{
				//cout<<guardpoly<<" contains "<<region<<endl;
				ret.push_back(*it);
			}
			else
			{
				//cout<<guardpoly<<" does not contain "<<region<<endl;
			}
		}
	}
	//cout<<"ret size:"<<ret.size()<<endl;
	return ret;
}

vector<vector<Constraint_System> > find_Regions_satisfying_guards_for_ICTA(vector<vector<Constraint_System> > vcs,Constraint_System guards)
{
	vector<vector<Constraint_System> > ret;
	//cout<<"Mark:"<<vcs.size()<<endl;
	for(vector<vector<Constraint_System> >::iterator it=vcs.begin();it!=vcs.end();it++)
	{

		NNC_Polyhedron region;
		region.add_space_dimensions_and_embed(guards.space_dimension());
		region=generate_polyhedra_from_for_ICTA(*it);
		//cout<<"Created polyhedra:"<<endl;


		NNC_Polyhedron guardpoly;
		guardpoly.add_space_dimensions_and_embed(region.space_dimension());
		guardpoly.add_constraints(guards);

		if(!region.is_empty())
		{
			if(guardpoly.contains(region))
			{
				//cout<<guardpoly<<" contains "<<region<<endl;
				ret.push_back(*it);
			}
			else
			{
				//cout<<guardpoly<<" does not contain "<<region<<endl;
			}
		}
	}
	//cout<<"ret size:"<<ret.size()<<endl;
	return ret;
}



string consttoStr(Constraint c)
{
	ostringstream test;
	test << c;
	string str(test.str());
	return str;
}

string toStr(NNC_Polyhedron p)
{
	ostringstream test;
	test << p;
	string str(test.str());
	return str;
}

string toStr_for_ICTA(NNC_Polyhedron p)
{
	ostringstream test;
	test << p;
	string str(test.str());
	return str;
}


bool is_In_List_of_Regions(vector<pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > >::iterator ytbegin,vector<pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > >::iterator ytend,pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > timesuccpair)
{
	bool flg=false;
	for(vector<pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > >::iterator yt=ytbegin;yt!=ytend;yt++)
	{
		if(timesuccpair.first==(*yt).first)
		{
			NNC_Polyhedron jt1;
			jt1.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
			jt1=generate_polyhedra_from(yt->second);

			NNC_Polyhedron jt2;
			jt2.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
			jt2=generate_polyhedra_from(timesuccpair.second);


			if(jt1.contains(jt2) && jt2.contains(jt1))
			{
				flg=true;
				break;
			}
		}
	}
	return flg;
}

bool is_In_List_of_Regions_for_ICTA(vector<pair<string,vector<Constraint_System> > >::iterator ytbegin,vector<pair<string,vector<Constraint_System> > >::iterator ytend,pair<string,vector<Constraint_System> > timesuccpair)
{
	bool flg=false;
	for(vector<pair<string,vector<Constraint_System> > >::iterator yt=ytbegin;yt!=ytend;yt++)
	{
		if(timesuccpair.first==(*yt).first)
		{
			NNC_Polyhedron jt1;
			jt1.add_space_dimensions_and_embed(timesuccpair.second.begin()->space_dimension());
			jt1=generate_polyhedra_from_for_ICTA(yt->second);

			NNC_Polyhedron jt2;
			jt2.add_space_dimensions_and_embed(timesuccpair.second.begin()->space_dimension());
			jt2=generate_polyhedra_from_for_ICTA(timesuccpair.second);


			if(jt1.contains(jt2) && jt2.contains(jt1))
			{
				flg=true;
				break;
			}
		}
	}
	return flg;
}



Automaton construct_Region_Automata(Automaton time_aut)
{
	if(time_aut.cntr_var_lst.cntr_var_arr.size()==0)
	{
		Automaton region_aut;
		region_aut=time_aut;
		region_aut.name=time_aut.name+"region";		
		return region_aut;
	}
	Automaton region_aut;
	region_aut.name=time_aut.name+"region";
	vector<int> maxbound=find_Max_Bounds(time_aut);

	region_aut.cntr_var_lst=time_aut.cntr_var_lst;
	region_aut.in_var_lst=time_aut.in_var_lst;
	region_aut.syn_lab_lst=time_aut.syn_lab_lst;
	region_aut.parameter_lst=time_aut.parameter_lst;
	//cout<<"Size:"<<maxbound.size()<<endl;
	//int q;
	//cin>>q;
	/*for(vector<vector<State> >::iterator it=R_i.begin();it!=R_i.end();it++)
	{
		for(vector<State>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			cout<<itt->l.name<<","<<itt->poly<<endl;
		}
		cout<<"End of state vector"<<endl;
	}*/

	/*for(vector<Location>::iterator it=time_aut.initial_loc_lst.location_arr.begin();it!=time_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/

	/*for(vector<int>::iterator it=maxbound.begin();it!=maxbound.end();it++);
	{
		cout<<(*it)<<" ";
	}*/
	vector<pair<vector<Constraint_System>,vector<vector<string> > > > vcs=generate_Regions(maxbound.size(),maxbound);


	vector<pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > > under_process;
	vector<pair<string,pair<vector<Constraint_System>,vector<vector<string> > > > > already_processed;




	for(vector<Location>::iterator it=time_aut.initial_loc_lst.location_arr.begin();it!=time_aut.initial_loc_lst.location_arr.end();it++)
	{

		Constraint_System mycs;
		mycs.set_space_dimension(time_aut.cntr_var_lst.cntr_var_arr.size());
		mycs=it->invariants;
		for(Constraint_System_const_iterator mycsit=time_aut.loc_to_invar[it->name].begin();mycsit!=time_aut.loc_to_invar[it->name].end();mycsit++)
		{
			mycs.insert(*mycsit);
		}
		//vector<pair<vector<Constraint_System>,vector<vector<string> > > > satguards=find_Regions_satisfying_guards(vcs,it->invariants);
		vector<pair<vector<Constraint_System>,vector<vector<string> > > > satguards=find_Regions_satisfying_guards(vcs,mycs);
		

		for(vector<pair<vector<Constraint_System>,vector<vector<string> > > >::iterator itt=satguards.begin();itt!=satguards.end();itt++)
		{
			pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > st(it->name,*itt);
			//if(already_processed.end()==find(already_processed.begin(),already_processed.end(),st))
			//{
				//if(under_process.end()==find(under_process.begin(),under_process.end(),st))
				//{
			
			if(!is_In_List_of_Regions(already_processed.begin(),already_processed.end(),st))
			{
				
				if(!is_In_List_of_Regions(under_process.begin(),under_process.end(),st))
				{
					
					under_process.push_back(st);
					//add this pair into init loc list of region automata
					NNC_Polyhedron currregion;
					currregion.add_space_dimensions_and_embed(st.second.first.begin()->space_dimension());
					currregion=generate_polyhedra_from(st.second);

					Location l;
					l.name=st.first+","+toStr(currregion);
					//l.invariants=currregion.constraints();
					l.invariants.clear();
					l.rate.clear();	
					
					region_aut.initial_loc_lst.location_arr.push_back(l);



					//l.invariants=time_aut.loc_to_invar[st.first];



					//add this pair into loc list of region automata
					region_aut.loc_lst.location_arr.push_back(l);


				}
				else
				{
					//discard this location
				}

			}
			else
			{
				//discard this location
			}
		}
	}
	//cout<<"Initial Location Done"<<endl;
	while(!under_process.empty())
	{
		
		pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > fr=under_process.front();
		under_process.erase(under_process.begin());
		already_processed.push_back(fr);

		//cout<<"Currstate:"<<fr.first<<endl;

		string currlocstr=fr.first;

		pair<vector<Constraint_System>,vector<vector<string> > > currtimeregion=fr.second;



		pair<vector<Constraint_System>,vector<vector<string> > > nexttimeregion=find_time_successor_region(currtimeregion,maxbound);



		//create one pair of the same location name and nexttimeregion
		pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > timesuccpair(currlocstr,nexttimeregion);



		
		
		//push this pair into under process queue
		//under_process.push_back(timesuccpair);

		//push this pair into loc list of region automata
		/*NNC_Polyhedron succcurrregion;
		succcurrregion.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
		succcurrregion=generate_polyhedra_from(timesuccpair.second);*/
		
		/*Location l;
		l.name=timesuccpair.first+","+toStr(succcurrregion);
		l.invariants.clear();
		l.rate.clear();*/

		//l.invariants=currregion.constraints();

		//l.invariants=time_aut.loc_to_invar[l.name];
		
		

		//l.invariants=time_aut.loc_to_invar[timesuccpair.first];
		
		NNC_Polyhedron npp;
		npp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
		npp=generate_polyhedra_from(timesuccpair.second);


		NNC_Polyhedron n2pp;
		n2pp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
		n2pp.add_constraints(time_aut.loc_to_invar[timesuccpair.first]);
		
		

		if(n2pp.contains(npp))
		{
		
			
			//vector<pair<vector<Constraint_System>,vector<vector<string> > > > satguards=find_Regions_satisfying_guards(vcs,mycs);
			//if l.invariants contains that currregion
			NNC_Polyhedron succcurrregion;
			succcurrregion.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
			succcurrregion=generate_polyhedra_from(timesuccpair.second);

			Location l;
			l.name=timesuccpair.first+","+toStr(succcurrregion);
			l.invariants.clear();
			l.rate.clear();
			
			if(!is_In_List_of_Regions(already_processed.begin(),already_processed.end(),timesuccpair))
			{
				if(!is_In_List_of_Regions(under_process.begin(),under_process.end(),timesuccpair))
				{
					under_process.push_back(timesuccpair);
					region_aut.loc_lst.location_arr.push_back(l);	
				}
			}
			
			/*if(already_processed.end()==find(already_processed.begin(),already_processed.end(),timesuccpair))
			{
			
				if(under_process.end()==find(under_process.begin(),under_process.end(),timesuccpair))
				{
					under_process.push_back(timesuccpair);
					region_aut.loc_lst.location_arr.push_back(l);	
				}
			}*/
			
			NNC_Polyhedron currpolyregion;
			currpolyregion.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
			currpolyregion=generate_polyhedra_from(fr.second);



			NNC_Polyhedron nextpolyregion;
			nextpolyregion.add_space_dimensions_and_embed(timesuccpair.second.first.begin()->space_dimension());
			nextpolyregion=generate_polyhedra_from(timesuccpair.second);


			Edge e;
			e.aut_nm=region_aut.name;
			e.pre=currlocstr+","+toStr(currpolyregion);
			e.post=currlocstr+","+toStr(nextpolyregion);
			e.guards.clear();
			e.updates.clear();
			e.syn_lab="";
			region_aut.edge_lst.edge_arr.push_back(e);
			//cout<<"Pushing edge "<<e.pre<<" to "<<e.post<<" "<<e.syn_lab<<endl;
			//cout<<"Pushed "<<l.name<<" to region aut"<<endl;
		}


		



		
		NNC_Polyhedron currregion;
		currregion.add_space_dimensions_and_embed(currtimeregion.first.begin()->space_dimension());
		//currregion=generate_polyhedra_from(currtimeregion);
		currregion=generate_polyhedra_from(fr.second);
		
		//for each edge of time aut

		for(vector<Edge>::iterator eit=time_aut.edge_lst.edge_arr.begin();eit!=time_aut.edge_lst.edge_arr.end();eit++)
		{
			//if pre location is currlocstr
			if(eit->pre==currlocstr)
			{
				
				//cout<<"Hi:"<<endl;
				NNC_Polyhedron guardpoly;
				//cout<<eit->guards.space_dimension()<<endl;
				
				//guardpoly.add_space_dimensions_and_embed(eit->guards.space_dimension());
				guardpoly.add_space_dimensions_and_embed(currtimeregion.first.begin()->space_dimension());
				guardpoly.add_constraints(eit->guards);

				
				//if currtimeregion is in guard of this edge

				//cout<<"Edge:"<<eit->pre<<" "<<eit->post<<" guards:"<<eit->guards<<" update:"<<eit->updates<<endl;
				//cout<<guardpoly<<" doesn't contain "<<currregion<<endl;
				if(guardpoly.contains(currregion))
				{
					
					//cout<<guardpoly<<" yes it is "<<currregion<<endl;
					int count=0;
					for(Constraint_System_const_iterator csit=eit->updates.begin();csit!=eit->updates.end();csit++)
					{
						count++;
					}
					pair<vector<Constraint_System>,vector<vector<string> > > resetedtimeregion;

					if(count==0)
					{
						resetedtimeregion=currtimeregion;					
						
					}
					else
					{
						resetedtimeregion=find_reset_region(currtimeregion,eit->updates);
					}

					//guardpoly.add_constraints(time_aut.loc_to_invar[eit->post]);
					NNC_Polyhedron nppp;
					nppp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
					nppp=generate_polyhedra_from(resetedtimeregion);
					//cout<<"resetted time region:"<<nppp<<endl;
					

					NNC_Polyhedron n2ppp;
					n2ppp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
					n2ppp.add_constraints(time_aut.loc_to_invar[eit->post]);

					if(n2ppp.contains(nppp))
					{									

						//create new pair with post location name of this edge and same region as currtimeregion
						pair<string,pair<vector<Constraint_System>,vector<vector<string> > >  > discretesuccpair(eit->post,resetedtimeregion);
						NNC_Polyhedron resetedcurrregion;
						resetedcurrregion.add_space_dimensions_and_embed(discretesuccpair.second.first.begin()->space_dimension());
						resetedcurrregion=generate_polyhedra_from(discretesuccpair.second);


						
						//push this new pair into loc list of region automata
						
						Location l;
						l.name=discretesuccpair.first+","+toStr(resetedcurrregion);
						//l.invariants=currregion.constraints();
						l.invariants.clear();
						l.rate.clear();

						//if this new  pair is not in already processed queue
						//if(already_processed.end()==find(already_processed.begin(),already_processed.end(),discretesuccpair))
						//{
							//if this new pair is not in under process queue
							//if(under_process.end()==find(under_process.begin(),under_process.end(),discretesuccpair))
						if(!is_In_List_of_Regions(already_processed.begin(),already_processed.end(),discretesuccpair))
						{
							if(!is_In_List_of_Regions(under_process.begin(),under_process.end(),discretesuccpair))
				
							{
								

								//l.invariants=time_aut.loc_to_invar[discretesuccpair.first];

								region_aut.loc_lst.location_arr.push_back(l);

								//push this new pair into under process queue
								under_process.push_back(discretesuccpair);
							}
						}
						//end if
						//create new edge in region automata with curr as pre and new post loc as post and sync label as label on edge choosen
						NNC_Polyhedron resettedpolyegion;
						resettedpolyegion.add_space_dimensions_and_embed(discretesuccpair.second.first.begin()->space_dimension());
						resettedpolyegion=generate_polyhedra_from(discretesuccpair.second);



						Edge ee;
						ee.aut_nm=region_aut.name;
						ee.pre=currlocstr+","+toStr(currregion);
						ee.post=discretesuccpair.first+","+toStr(resettedpolyegion);
						ee.syn_lab=eit->syn_lab;
						region_aut.edge_lst.edge_arr.push_back(ee);
						//cout<<"PPushing edge "<<ee.pre<<" to "<<ee.post<<" "<<ee.syn_lab<<endl;			

					}
					//end if										


				//end if
				}

			//end if
			}
		//end for
		}
	}
	//cout<<"My end"<<endl;
	return region_aut;
}
bool locationcompare(Location l1,Location l2)
{
	/*NNC_Polyhedron l1in;
	l1in.add_space_dimensions_and_embed(l1.invariants.space_dimension());
	l1in.add_constraints(l1.invariants);

	NNC_Polyhedron l2in;
	l2in.add_space_dimensions_and_embed(l2.invariants.space_dimension());
	l2in.add_constraints(l2.invariants);

	NNC_Polyhedron l1rt;
	l1rt.add_space_dimensions_and_embed(l1.rate.space_dimension());
	l1rt.add_constraints(l1.rate);

	NNC_Polyhedron l2rt;
	l2rt.add_space_dimensions_and_embed(l2.rate.space_dimension());
	l2rt.add_constraints(l2.rate);
*/



	if(l1.name==l2.name && l1.invariants==l2.invariants && l1.rate==l2.rate)
	{
		return true;
	}
	/*else
	{
		cout<<"HAAA:"<<l1.name<<" "<<l2.name<<" "<<l1in.constraints()<<" "<<l2in.constraints()<<" "<<l1rt.constraints()<<" "<<l2rt.constraints()<<endl;
	}*/
	return false;
}

int mainRegionAutomatasimpleAlur() {

	Automaton_List aut_lst;
	string s;
	ifstream r;
	r.open("simpleAlur.pha");
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();




	vector<vector<State> > R_f,R_i;

	initialize_final_states_simple_Alur(R_f,aut_lst);
	initialize_initial_states(R_i,aut_lst);
	int max_iterations=12;


	Automaton region_aut=construct_Region_Automata(*aut_lst.aut_arr.begin());

	//cout<<"End of region constr"<<endl;



	//cout<<"Location list size before:"<<region_aut.loc_lst.location_arr.size()<<endl;
	//cout<<"Edge list size before:"<<region_aut.edge_lst.edge_arr.size()<<endl;


	/*vector<Location>::iterator it;
	it = unique(region_aut.loc_lst.location_arr.begin(), region_aut.loc_lst.location_arr.end(),locationcompare);

	region_aut.loc_lst.location_arr.resize( std::distance(region_aut.loc_lst.location_arr.begin(),it) );*/









	vector<Location> tmplocrr;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		bool fllg=false;
		for(vector<Location>::iterator itt=it;itt!=region_aut.loc_lst.location_arr.end();itt++)
		{
			if(it!=itt)
			{
				if(it->name==itt->name && it->invariants==itt->invariants && it->rate==itt->rate)
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are equal"<<endl<<endl;
					fllg=true;
					break;
				}
				/*else
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are not equal"<<endl<<endl;
				}*/
			}
		}
		if(fllg==false)
		{
			tmplocrr.push_back(*it);
		}
		//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	region_aut.loc_lst.location_arr=tmplocrr;



	vector<Edge> tmpedgrr;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		if(it->pre!=it->post)
		{
			bool fllg=false;
			for(vector<Edge>::iterator itt=it;itt!=region_aut.edge_lst.edge_arr.end();itt++)
			{
				if(it!=itt)
				{
					if(it->aut_nm==itt->aut_nm && it->guards==itt->guards && it->post==itt->post && it->pre==itt->pre && it->syn_lab==itt->syn_lab && it->updates==itt->updates)
					{
						fllg=true;
						break;
					}

				}
			}
			if(fllg==false)
			{
				tmpedgrr.push_back(*it);
			}
		}
	}
	region_aut.edge_lst.edge_arr=tmpedgrr;






	//cout<<"Location list size after:"<<region_aut.loc_lst.location_arr.size()<<endl;
	//cout<<"Edge list size after:"<<region_aut.edge_lst.edge_arr.size()<<endl;

	cout<<"Location list:"<<endl;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	cout<<"Edge list:"<<endl;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" "<<endl;
	}

	cout<<region_aut.name<<endl;

	return 0;
}

int mainRegionAutomataIcTA() {
	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	//r.open("compo.pha");
	r.open("new_compo.pha");


	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();

	//cout<<"Before calling:"<<aut_lst.aut_arr.size()<<endl;





	vector<vector<State> > R_f,R_i;

	initialize_final_states_prod(R_f,aut_lst);
	//initialize_initial_states(R_i,aut_lst);
	//cout<<"End1:"<<endl;
	//Automaton prod_aut=take_product(aut_lst);
	Automaton prod_aut=to_ICTA(aut_lst);

	//temporary doing cntr list as only two variables
	prod_aut.cntr_var_lst.cntr_var_arr.clear();
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");

	//aut_lst.aut_arr.push_back(prod_aut);

	/*cout<<"Automaton Name:"<<prod_aut.name<<endl;
	cout<<"Control Variable List:";
	for(vector<string>::iterator sit=prod_aut.cntr_var_lst.cntr_var_arr.begin();sit!=prod_aut.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cout<<" "<<(*sit);
	}
	cout<<endl;

	cout<<"Synchronization Label:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=prod_aut.syn_lab_lst.syn_lab_arr.begin();it!=prod_aut.syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;

	cout<<"Parameters:"<<endl;
	for(vector<Parameter>::iterator it=prod_aut.parameter_lst.par_list_arr.begin();it!=prod_aut.parameter_lst.par_list_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;
	cout<<"Initial Location:"<<endl;
	for(vector<Location>::iterator it=prod_aut.initial_loc_lst.location_arr.begin();it!=prod_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/
	cout<<"Location List:"<<endl;
	for(vector<Location>::iterator it=prod_aut.loc_lst.location_arr.begin();it!=prod_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<","<<it->rate<<endl;
	}

	cout<<"Edge List:"<<endl;
	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<" "<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->syn_lab<<endl;
	}
	cout<<"End2:"<<endl;



	int max_iterations=12;


	//cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;



	Automaton region_aut=construct_Region_Automata(prod_aut);
	cout<<region_aut.name<<endl;

	cout<<"Location list size before:"<<region_aut.loc_lst.location_arr.size()<<endl;
	cout<<"Edge list size before:"<<region_aut.edge_lst.edge_arr.size()<<endl;


	/*vector<Location>::iterator it;
	it = unique(region_aut.loc_lst.location_arr.begin(), region_aut.loc_lst.location_arr.end(),locationcompare);

	region_aut.loc_lst.location_arr.resize( std::distance(region_aut.loc_lst.location_arr.begin(),it) );*/









	vector<Location> tmplocrr;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		bool fllg=false;
		for(vector<Location>::iterator itt=it;itt!=region_aut.loc_lst.location_arr.end();itt++)
		{
			if(it!=itt)
			{
				if(it->name==itt->name && it->invariants==itt->invariants && it->rate==itt->rate)
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are equal"<<endl<<endl;
					fllg=true;
					break;
				}
				/*else
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are not equal"<<endl<<endl;
				}*/
			}
		}
		if(fllg==false)
		{
			tmplocrr.push_back(*it);
		}
		//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	region_aut.loc_lst.location_arr=tmplocrr;



	vector<Edge> tmpedgrr;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		if(it->pre!=it->post)
		{
			bool fllg=false;
			for(vector<Edge>::iterator itt=it;itt!=region_aut.edge_lst.edge_arr.end();itt++)
			{
				if(it!=itt)
				{
					if(it->aut_nm==itt->aut_nm && it->guards==itt->guards && it->post==itt->post && it->pre==itt->pre && it->syn_lab==itt->syn_lab && it->updates==itt->updates)
					{
						fllg=true;
						break;
					}

				}
			}
			if(fllg==false)
			{
				tmpedgrr.push_back(*it);
			}
		}
	}
	region_aut.edge_lst.edge_arr=tmpedgrr;






	cout<<"Location list size after:"<<region_aut.loc_lst.location_arr.size()<<endl;
	cout<<"Edge list size after:"<<region_aut.edge_lst.edge_arr.size()<<endl;

	cout<<"Location list:"<<endl;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	cout<<"Edge list:"<<endl;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" "<<endl;
	}

	cout<<region_aut.name<<endl;


	return 0;
}
bool are_all_zero(Constraint_System rate,int vardim)
{
	//cout<<"Input rate:"<<rate<<endl;
	int ithvar=0;
	for(Constraint_System_const_iterator csit=rate.begin();csit!=rate.end();csit++)
	{
		Constraint c;
		c.set_space_dimension(csit->space_dimension());
		c=(Variable(ithvar)==0);
		//cout<<c<<(*csit)<<endl;
		//if(csit->is_equal_to(c))
		//if(csit->is_equivalent_to(c))
		if(consttoStr(c)!=consttoStr(*csit))
			break;
		ithvar++;

	}
	if(ithvar==vardim)
	{
		//cout<<"Returning true"<<endl;
		return true;
	}
	//cout<<"Returning false"<<endl;
	return false;

}
Automaton hybrid_flavoured_timed_aut_to_timed_aut(Automaton prod_aut)
{
	Automaton ret;
	ret.name=prod_aut.name;
	int newvardimno=prod_aut.edge_lst.edge_arr.begin()->guards.space_dimension();

	ret.cntr_var_lst=prod_aut.cntr_var_lst;

	char a[100];
	sprintf(a,"%c",newvardimno+65);
	//cout<<"Pushed:"<<a<<endl;
	ret.cntr_var_lst.cntr_var_arr.push_back(a);

	//ret.in_var_lst
	ret.in_var_lst=prod_aut.in_var_lst;

	//ret.parameter_lst
	ret.parameter_lst=prod_aut.parameter_lst;

	//ret.syn_lab_lst
	ret.syn_lab_lst=prod_aut.syn_lab_lst;


	for(vector<Location>::iterator itc=prod_aut.initial_loc_lst.location_arr.begin();itc!=prod_aut.initial_loc_lst.location_arr.end();itc++)
	{
		Location l;
		l.name=itc->name;
		l.invariants.set_space_dimension(newvardimno+1);
		for(Constraint_System_const_iterator csit=itc->invariants.begin();csit!=itc->invariants.end();csit++)
		{
			l.invariants.insert(*csit);
		}
		l.invariants.insert(Variable(newvardimno)==0);

		l.rate.set_space_dimension(newvardimno+1);
		for(Constraint_System_const_iterator csit=itc->rate.begin();csit!=itc->rate.end();csit++)
		{
			l.rate.insert(*csit);
		}


		ret.initial_loc_lst.location_arr.push_back(l);
	}
	

	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		Constraint_System preinvar=prod_aut.loc_to_Location[it->pre].invariants;
		//NNC_Polyhedron poly;
		//poly.add_space_dimensions_and_embed(preinvar.space_dimension());
		//poly.add_constraints(preinvar);

		Location newpre;
		newpre.name=it->pre;
		newpre.invariants.set_space_dimension(newvardimno+1);
		newpre.rate.set_space_dimension(newvardimno+1);

		Location newpost;
		newpost.name=it->post;
		newpost.invariants.set_space_dimension(newvardimno+1);
		newpost.rate.set_space_dimension(newvardimno+1);



		Edge e;
		e.aut_nm=it->aut_nm;
		e.pre=it->pre;
		e.post=it->post;
		e.syn_lab=it->syn_lab;


		e.guards.set_space_dimension(newvardimno+1);

		e.updates.set_space_dimension(newvardimno+1);

		for(Constraint_System_const_iterator csit=it->guards.begin();csit!=it->guards.end();csit++)
		{
			e.guards.insert(*csit);
		}

		for(Constraint_System_const_iterator csit=it->updates.begin();csit!=it->updates.end();csit++)
		{
			e.updates.insert(*csit);
		}

		if(are_all_zero(prod_aut.loc_to_Location[it->pre].rate,newvardimno))
		{
			e.guards.insert(Variable(newvardimno)<=0);

		}
		else
		{
			
			if(are_all_zero(prod_aut.loc_to_Location[it->post].rate,newvardimno))
			{
				e.updates.insert(Variable(newvardimno)==0);
			}
			else
			{
				cout<<"Not compared:"<<prod_aut.loc_to_Location[it->post].rate<<endl;
			}
			
		}

		for(Constraint_System_const_iterator ccit=preinvar.begin();ccit!=preinvar.end();ccit++)
		{
			e.guards.insert(*ccit);
		}

		//e.guards
		NNC_Polyhedron tmppolyguards;
		tmppolyguards.add_space_dimensions_and_embed(e.guards.space_dimension());
		tmppolyguards.add_constraints(e.guards);

		e.guards.clear();
		for(Constraint_System_const_iterator cspit=tmppolyguards.constraints().begin();cspit!=tmppolyguards.constraints().end();cspit++)
		{
			e.guards.insert(*cspit);
		}
		//e.guards=tmppolyguards;

		//e.updates
		NNC_Polyhedron tmppolyupdates;
		tmppolyupdates.add_space_dimensions_and_embed(e.updates.space_dimension());
		tmppolyupdates.add_constraints(e.updates);

		e.updates.clear();
		for(Constraint_System_const_iterator cspit=tmppolyupdates.constraints().begin();cspit!=tmppolyupdates.constraints().end();cspit++)
		{
			e.updates.insert(*cspit);
		}
		//e.updates=tmppolyupdates;


		ret.edge_lst.edge_arr.push_back(e);

		bool flgg=false;
		for(vector<Location>::iterator itp=ret.loc_lst.location_arr.begin();itp!=ret.loc_lst.location_arr.end();itp++)
		{
			NNC_Polyhedron newinpoly;
			newinpoly.add_space_dimensions_and_embed(newpre.invariants.space_dimension());
			newinpoly.add_constraints(newpre.invariants);

			newpre.invariants=newinpoly.constraints();

			NNC_Polyhedron inpoly;
			inpoly.add_space_dimensions_and_embed(itp->invariants.space_dimension());
			inpoly.add_constraints(itp->invariants);

			NNC_Polyhedron newratepoly;
			newratepoly.add_space_dimensions_and_embed(newpre.rate.space_dimension());
			newratepoly.add_constraints(newpre.rate);

			newpre.rate=newratepoly.constraints();

			NNC_Polyhedron ratepoly;
			ratepoly.add_space_dimensions_and_embed(itp->rate.space_dimension());
			ratepoly.add_constraints(itp->rate);



			if(newpre.name==itp->name && newinpoly==inpoly && newratepoly==ratepoly)
			{
				flgg=true;
				break;
			}
		}

		if(flgg==false)
		{
			ret.loc_lst.location_arr.push_back(newpre);
		}

		

		for(vector<Location>::iterator itp=ret.loc_lst.location_arr.begin();itp!=ret.loc_lst.location_arr.end();itp++)
		{
			NNC_Polyhedron newinpoly;
			newinpoly.add_space_dimensions_and_embed(newpost.invariants.space_dimension());
			newinpoly.add_constraints(newpost.invariants);

			newpost.invariants=newinpoly.constraints();

			NNC_Polyhedron inpoly;
			inpoly.add_space_dimensions_and_embed(itp->invariants.space_dimension());
			inpoly.add_constraints(itp->invariants);



			NNC_Polyhedron newratepoly;
			newratepoly.add_space_dimensions_and_embed(newpost.rate.space_dimension());
			newratepoly.add_constraints(newpost.rate);

			newpost.rate=newratepoly.constraints();

			NNC_Polyhedron ratepoly;
			ratepoly.add_space_dimensions_and_embed(itp->rate.space_dimension());
			ratepoly.add_constraints(itp->rate);



			if(newpost.name==itp->name && newinpoly==inpoly && newratepoly==ratepoly)
			{
				flgg=true;
				break;
			}
		}

		if(flgg==false)
		{
			ret.loc_lst.location_arr.push_back(newpost);
		}



	}

	ret.fillMaps();



	/*cout<<"Prod aut loc:"<<prod_aut.loc_lst.location_arr.size()<<endl;
	cout<<"Prod aut edge:"<<prod_aut.edge_lst.edge_arr.size()<<endl;


	cout<<"Refined aut loc:"<<ret.loc_lst.location_arr.size()<<endl;
	cout<<"Refined aut edge:"<<ret.edge_lst.edge_arr.size()<<endl;


	cout<<"Refined Locations:"<<endl;
	for(vector<Location>::iterator lit=ret.loc_lst.location_arr.begin();lit!=ret.loc_lst.location_arr.end();lit++)
	{
		cout<<lit->name<<" "<<lit->invariants<<" "<<lit->rate<<endl;
	}

	cout<<"Refined Edges:"<<endl;
	for(vector<Edge>::iterator eit=ret.edge_lst.edge_arr.begin();eit!=ret.edge_lst.edge_arr.end();eit++)
	{
		cout<<eit->pre<<" "<<eit->post<<" "<<eit->guards<<" "<<eit->updates<<" "<<eit->syn_lab<<endl;
	}
	cout<<"PPEnd"<<endl;*/
	

	return ret;
}

int mainRegionAutomataIcTAdisTA() {
	Automaton_List aut_lst;
	string s;
	ifstream r;
	//r.open("composition_demo.pha");
	//r.open("gas_burner.pha");
	//r.open("water_level_monitor.pha");
	//r.open("compo.pha");
	//r.open("new_compo.pha");

	r.open("disTA.pha");


	parseFile(r,aut_lst);


	//aut_lst.fill_Regions();

	aut_lst.fill_Maps();

	cout<<"Before calling:"<<aut_lst.aut_arr.size()<<endl;


	//cout<<"Map size:"<<aut_lst.aut_arr.begin()->loc_to_Location.size()<<endl;


	//vector<vector<State> > R_f,R_i;

	//initialize_final_states_prod(R_f,aut_lst);




	//initialize_initial_states(R_i,aut_lst);
	//cout<<"End1:"<<endl;
	//Automaton prod_aut=take_product(aut_lst);
	Automaton prod_aut=to_ICTA(aut_lst);




	//temporary doing cntr list as only two variables
	prod_aut.cntr_var_lst.cntr_var_arr.clear();
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");

	//aut_lst.aut_arr.push_back(prod_aut);

	/*cout<<"Automaton Name:"<<prod_aut.name<<endl;
	cout<<"Control Variable List:";
	for(vector<string>::iterator sit=prod_aut.cntr_var_lst.cntr_var_arr.begin();sit!=prod_aut.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cout<<" "<<(*sit);
	}
	cout<<endl;

	cout<<"Synchronization Label:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=prod_aut.syn_lab_lst.syn_lab_arr.begin();it!=prod_aut.syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;

	cout<<"Parameters:"<<endl;
	for(vector<Parameter>::iterator it=prod_aut.parameter_lst.par_list_arr.begin();it!=prod_aut.parameter_lst.par_list_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;
	cout<<"Initial Location:"<<endl;
	for(vector<Location>::iterator it=prod_aut.initial_loc_lst.location_arr.begin();it!=prod_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/

	prod_aut.fillMaps();
	//prod_aut.fillRegions();


	cout<<"ICTA Location List:"<<endl;
	for(vector<Location>::iterator it=prod_aut.loc_lst.location_arr.begin();it!=prod_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<","<<it->rate<<endl;
	}

	cout<<"ICTA Edge List:"<<endl;
	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<" "<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->syn_lab<<endl;
	}
	cout<<"End2:"<<endl;



	int max_iterations=12;


	//cout<<"Output1:"<<is_Reachable_by_backward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;

	//cout<<"Output2:"<<is_Reachable_by_forward_fixpoint_computation(R_f,R_i,max_iterations,aut_lst)<<endl;


	prod_aut=hybrid_flavoured_timed_aut_to_timed_aut(prod_aut);

	prod_aut.cntr_var_lst.cntr_var_arr.clear();
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");
	prod_aut.cntr_var_lst.cntr_var_arr.push_back("z");



	Automaton region_aut=construct_Region_Automata(prod_aut);
	cout<<region_aut.name<<endl;

	region_aut.fillMaps();
	//region_aut.fillRegions();





	cout<<"Location list size before:"<<region_aut.loc_lst.location_arr.size()<<endl;
	cout<<"Edge list size before:"<<region_aut.edge_lst.edge_arr.size()<<endl;


	/*vector<Location>::iterator it;
	it = unique(region_aut.loc_lst.location_arr.begin(), region_aut.loc_lst.location_arr.end(),locationcompare);

	region_aut.loc_lst.location_arr.resize( std::distance(region_aut.loc_lst.location_arr.begin(),it) );*/









	vector<Location> tmplocrr;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		bool fllg=false;
		for(vector<Location>::iterator itt=it;itt!=region_aut.loc_lst.location_arr.end();itt++)
		{
			if(it!=itt)
			{
				if(it->name==itt->name && it->invariants==itt->invariants && it->rate==itt->rate)
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are equal"<<endl<<endl;
					fllg=true;
					break;
				}
				/*else
				{
					//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
					//cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate<<endl;
					//cout<<"are not equal"<<endl<<endl;
				}*/
			}
		}
		if(fllg==false)
		{
			tmplocrr.push_back(*it);
		}
		//cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	region_aut.loc_lst.location_arr=tmplocrr;



	vector<Edge> tmpedgrr;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		if(it->pre==it->post && it->syn_lab=="")
		{
			//discard such type of edge
		}
		//if(it->pre!=it->post)
		else
		{
			bool fllg=false;
			for(vector<Edge>::iterator itt=it;itt!=region_aut.edge_lst.edge_arr.end();itt++)
			{
				if(it!=itt)
				{
					if(it->aut_nm==itt->aut_nm && it->guards==itt->guards && it->post==itt->post && it->pre==itt->pre && it->syn_lab==itt->syn_lab && it->updates==itt->updates)
					{
						fllg=true;
						break;
					}

				}
			}
			if(fllg==false)
			{
				tmpedgrr.push_back(*it);
			}
		}
	}
	region_aut.edge_lst.edge_arr=tmpedgrr;






	cout<<"Location list size after:"<<region_aut.loc_lst.location_arr.size()<<endl;
	cout<<"Edge list size after:"<<region_aut.edge_lst.edge_arr.size()<<endl;

	cout<<"Location list:"<<endl;
	for(vector<Location>::iterator it=region_aut.loc_lst.location_arr.begin();it!=region_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<" "<<it->invariants<<" "<<it->rate<<endl;
	}
	cout<<"Edge list:"<<endl;
	for(vector<Edge>::iterator it=region_aut.edge_lst.edge_arr.begin();it!=region_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" "<<endl;
	}

	cout<<region_aut.name<<endl;


	return 0;
}

Automaton construct_Region_Automata_for_ICTA(Automaton time_aut)
{
	if(time_aut.cntr_var_lst.cntr_var_arr.size()==0)
	{
		Automaton region_aut;
		region_aut=time_aut;
		region_aut.name=time_aut.name+"region";		
		return region_aut;
	}
	Automaton region_aut;
	region_aut.name=time_aut.name+"region";
	vector<int> maxbound=find_Max_Bounds(time_aut);

	region_aut.cntr_var_lst=time_aut.cntr_var_lst;
	region_aut.in_var_lst=time_aut.in_var_lst;
	region_aut.syn_lab_lst=time_aut.syn_lab_lst;
	region_aut.parameter_lst=time_aut.parameter_lst;
	//cout<<"Size:"<<maxbound.size()<<endl;
	//int q;
	//cin>>q;
	/*for(vector<vector<State> >::iterator it=R_i.begin();it!=R_i.end();it++)
	{
		for(vector<State>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			cout<<itt->l.name<<","<<itt->poly<<endl;
		}
		cout<<"End of state vector"<<endl;
	}*/

	/*for(vector<Location>::iterator it=time_aut.initial_loc_lst.location_arr.begin();it!=time_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<","<<it->invariants<<endl;
	}*/

	/*for(vector<int>::iterator it=maxbound.begin();it!=maxbound.end();it++);
	{
		cout<<(*it)<<" ";
	}*/
	vector<vector<Constraint_System> > vcs=generate_Regions_for_ICTA(maxbound.size(),maxbound);
	//cout<<"Size:"<<vcs.size()<<endl;

	vector<pair<string,vector<Constraint_System> > > under_process;
	vector<pair<string,vector<Constraint_System> > > already_processed;




	for(vector<Location>::iterator it=time_aut.initial_loc_lst.location_arr.begin();it!=time_aut.initial_loc_lst.location_arr.end();it++)
	{
		
		Constraint_System mycs;
		mycs.set_space_dimension(time_aut.cntr_var_lst.cntr_var_arr.size());
		mycs=it->invariants;
		
		for(Constraint_System_const_iterator mycsit=time_aut.loc_to_invar[it->name].begin();mycsit!=time_aut.loc_to_invar[it->name].end();mycsit++)
		{
			mycs.insert(*mycsit);
		}
		
		vector<vector<Constraint_System> > satguards=find_Regions_satisfying_guards_for_ICTA(vcs,mycs);
		

		for(vector<vector<Constraint_System> >::iterator itt=satguards.begin();itt!=satguards.end();itt++)
		{
			pair<string,vector<Constraint_System> > st(it->name,*itt);

			if(!is_In_List_of_Regions_for_ICTA(already_processed.begin(),already_processed.end(),st))
			{
				if(!is_In_List_of_Regions_for_ICTA(under_process.begin(),under_process.end(),st))
				{
					under_process.push_back(st);
					//add this pair into init loc list of region automata
					NNC_Polyhedron currregion;
					currregion.add_space_dimensions_and_embed(st.second.begin()->space_dimension());
					currregion=generate_polyhedra_from_for_ICTA(st.second);

					Location l;
					l.name=st.first+","+toStr_for_ICTA(currregion);
					//l.invariants=currregion.constraints();
					l.invariants.clear();
					l.rate.clear();	
					
					region_aut.initial_loc_lst.location_arr.push_back(l);

					

					//l.invariants=time_aut.loc_to_invar[st.first];



					//add this pair into loc list of region automata
					region_aut.loc_lst.location_arr.push_back(l);


				}
				else
				{
					//discard this location
				}

			}
			else
			{
				//discard this location
			}
		}
	}
	//cout<<"Initial Location Done"<<endl;
	while(!under_process.empty())
	{
		
		pair<string,vector<Constraint_System> > fr=under_process.front();
		under_process.erase(under_process.begin());
		already_processed.push_back(fr);

		//cout<<"Currstate:"<<fr.first<<endl;

		string currlocstr=fr.first;

		vector<Constraint_System> currtimeregion=fr.second;

		

		vector<vector<Constraint_System> > nexttimeregions=find_time_successor_region_for_ICTA(currtimeregion,maxbound,time_aut);

		//cout<<"Rahul2:"<<endl;

		//create one pair of the same location name and nexttimeregion
		for(vector<vector<Constraint_System> >::iterator ikt=nexttimeregions.begin();ikt!=nexttimeregions.end();ikt++)
		{
			pair<string,vector<Constraint_System> > timesuccpair(currlocstr,*ikt);
		
		
		
			NNC_Polyhedron npp;
			npp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
			npp=generate_polyhedra_from_for_ICTA(timesuccpair.second);


			NNC_Polyhedron n2pp;
			n2pp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
			n2pp.add_constraints(time_aut.loc_to_invar[timesuccpair.first]);
		


			if(n2pp.contains(npp))
			{
		
		
				//vector<pair<vector<Constraint_System>,vector<vector<string> > > > satguards=find_Regions_satisfying_guards(vcs,mycs);
				//if l.invariants contains that currregion
				NNC_Polyhedron succcurrregion;
				succcurrregion.add_space_dimensions_and_embed(timesuccpair.second.begin()->space_dimension());
				succcurrregion=generate_polyhedra_from_for_ICTA(timesuccpair.second);

				Location l;
				l.name=timesuccpair.first+","+toStr_for_ICTA(succcurrregion);
				l.invariants.clear();
				l.rate.clear();
			
				if(!is_In_List_of_Regions_for_ICTA(already_processed.begin(),already_processed.end(),timesuccpair))
				{
					if(!is_In_List_of_Regions_for_ICTA(under_process.begin(),under_process.end(),timesuccpair))
					{
						under_process.push_back(timesuccpair);
						region_aut.loc_lst.location_arr.push_back(l);	
					}
				}
			
			
				NNC_Polyhedron currpolyregion;
				currpolyregion.add_space_dimensions_and_embed(timesuccpair.second.begin()->space_dimension());
				currpolyregion=generate_polyhedra_from_for_ICTA(fr.second);



				NNC_Polyhedron nextpolyregion;
				nextpolyregion.add_space_dimensions_and_embed(timesuccpair.second.begin()->space_dimension());
				nextpolyregion=generate_polyhedra_from_for_ICTA(timesuccpair.second);


				Edge e;
				e.aut_nm=region_aut.name;
				e.pre=currlocstr+","+toStr_for_ICTA(currpolyregion);
				e.post=currlocstr+","+toStr_for_ICTA(nextpolyregion);
				e.guards.clear();
				e.updates.clear();
				e.syn_lab="";
				region_aut.edge_lst.edge_arr.push_back(e);
				//cout<<"Pushing edge "<<e.pre<<" to "<<e.post<<" "<<e.syn_lab<<endl;
				//cout<<"Pushed "<<l.name<<" to region aut"<<endl;
			}


		}		

		

		
		NNC_Polyhedron currregion;
		currregion.add_space_dimensions_and_embed(currtimeregion.begin()->space_dimension());
		//currregion=generate_polyhedra_from(currtimeregion);
		currregion=generate_polyhedra_from_for_ICTA(fr.second);

		//cout<<"Rahul:"<<endl;
		//for each edge of time aut

		for(vector<Edge>::iterator eit=time_aut.edge_lst.edge_arr.begin();eit!=time_aut.edge_lst.edge_arr.end();eit++)
		{
			//if pre location is currlocstr
			if(eit->pre==currlocstr)
			{
				
				//cout<<"Hi:"<<endl;
				NNC_Polyhedron guardpoly;
				//cout<<eit->guards.space_dimension()<<endl;
				//guardpoly.add_space_dimensions_and_embed(eit->guards.space_dimension());
				guardpoly.add_space_dimensions_and_embed(currregion.space_dimension());
				guardpoly.add_constraints(eit->guards);

				
				//if currtimeregion is in guard of this edge

				//cout<<"Edge:"<<eit->pre<<" "<<eit->post<<" guards:"<<eit->guards<<" update:"<<eit->updates<<endl;
				//cout<<guardpoly<<" doesn't contain "<<currregion<<endl;
				//cout<<"Rahul4"<<endl;
				if(guardpoly.contains(currregion))
				{
					//cout<<"Rahul5"<<endl;					
					//cout<<guardpoly<<" yes it is "<<currregion<<endl;
					int count=0;
					for(Constraint_System_const_iterator csit=eit->updates.begin();csit!=eit->updates.end();csit++)
					{
						count++;
					}
					vector<Constraint_System> resetedtimeregion;
					
					if(count==0)
					{
						resetedtimeregion=currtimeregion;					
						
					}
					else
					{
						resetedtimeregion=find_reset_region_for_ICTA(currtimeregion,eit->updates);
					}
					//cout<<"Rahul3"<<endl;
					//guardpoly.add_constraints(time_aut.loc_to_invar[eit->post]);
					NNC_Polyhedron nppp;
					nppp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
					nppp=generate_polyhedra_from_for_ICTA(resetedtimeregion);
					//cout<<"resetted time region:"<<nppp<<endl;
					

					NNC_Polyhedron n2ppp;
					n2ppp.add_space_dimensions_and_embed(time_aut.cntr_var_lst.cntr_var_arr.size());
					n2ppp.add_constraints(time_aut.loc_to_invar[eit->post]);

					if(n2ppp.contains(nppp))
					{									

						//create new pair with post location name of this edge and same region as currtimeregion
						pair<string,vector<Constraint_System> > discretesuccpair(eit->post,resetedtimeregion);
						NNC_Polyhedron resetedcurrregion;
						resetedcurrregion.add_space_dimensions_and_embed(discretesuccpair.second.begin()->space_dimension());
						resetedcurrregion=generate_polyhedra_from_for_ICTA(discretesuccpair.second);


						
						//push this new pair into loc list of region automata
						
						Location l;
						l.name=discretesuccpair.first+","+toStr_for_ICTA(resetedcurrregion);
						//l.invariants=currregion.constraints();
						l.invariants.clear();
						l.rate.clear();

						if(!is_In_List_of_Regions_for_ICTA(already_processed.begin(),already_processed.end(),discretesuccpair))
						{
							if(!is_In_List_of_Regions_for_ICTA(under_process.begin(),under_process.end(),discretesuccpair))
				
							{
								

								//l.invariants=time_aut.loc_to_invar[discretesuccpair.first];

								region_aut.loc_lst.location_arr.push_back(l);

								//push this new pair into under process queue
								under_process.push_back(discretesuccpair);
							}
						}
						//end if
						//create new edge in region automata with curr as pre and new post loc as post and sync label as label on edge choosen
						NNC_Polyhedron resettedpolyegion;
						resettedpolyegion.add_space_dimensions_and_embed(discretesuccpair.second.begin()->space_dimension());
						resettedpolyegion=generate_polyhedra_from_for_ICTA(discretesuccpair.second);



						Edge ee;
						ee.aut_nm=region_aut.name;
						ee.pre=currlocstr+","+toStr_for_ICTA(currregion);
						ee.post=discretesuccpair.first+","+toStr_for_ICTA(resettedpolyegion);
						ee.syn_lab=eit->syn_lab;
						region_aut.edge_lst.edge_arr.push_back(ee);
						//cout<<"PPushing edge "<<ee.pre<<" to "<<ee.post<<" "<<ee.syn_lab<<endl;			

					}
					//end if										


				//end if
				}

			//end if
			}
		//end for
		}
	}
	//cout<<"My end"<<endl;
	return region_aut;
}



/*
int main()
{
	//mainprod();
	//mainreachcompo_demo();
	//mainreachgas_burner();
	//mainreachwaterlevel_monitor();
	//mainreachsimpleAlur();
	//mainDisTAtoIcTA();

	//mainRegionAutomata();

	//mainRegionAutomatasimpleAlur();

	//mainRegionAutomataIcTA();
	mainRegionAutomataIcTAdisTA();

	return 0;
}
*/
