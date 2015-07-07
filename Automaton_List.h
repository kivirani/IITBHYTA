#include <vector>

#include "Automaton.h"
using namespace std;


class Automaton_List
{
public:
	vector<Automaton> aut_arr;
	Input_Variable_List in_var_lst;
	void fill_Regions();
	void fill_Maps();
};

/*void Automaton_List ::fill_Regions()
{
	for(vector<Automaton>::iterator it=aut_arr.begin();it!=aut_arr.end();it++)
	{
		it->fillRegions();
	}
}
*/
void Automaton_List:: fill_Maps()
{
	for(vector<Automaton>::iterator it=aut_arr.begin();it!=aut_arr.end();it++)
	{
		it->fillMaps();
	}
}
void find_Initial_Locations(vector<Location> &Riloc_queue,vector<vector<Location> > &initial_states,vector<Automaton>::iterator curr,vector<Automaton>::iterator ed)
{

	for(vector<Location>::iterator itt=curr->initial_loc_lst.location_arr.begin();itt!=curr->initial_loc_lst.location_arr.end();itt++)
	{
		Riloc_queue.push_back(*itt);

		if( (curr+1)==ed )
		{
			initial_states.push_back(Riloc_queue);
		}
		else
		{
			find_Initial_Locations(Riloc_queue,initial_states,curr+1,ed);
		}

		Riloc_queue.pop_back();
	}
}

Location convert_vector_loc_to_location_with_original_invariants(vector<Location> st,Automaton_List aut_lst)
{
	Location ret;
	ret.name="";
	for(vector<Location>::iterator it=st.begin();it!=st.end();it++)
	{
		if(it!=st.begin())
		{
			ret.name=ret.name+"~";
		}
		ret.name=ret.name+(*it).name;


		Location tmp;

		for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
		{
			if((*aut_it).loc_to_Location.find((*it).name)!=(*aut_it).loc_to_Location.end())
			{
				tmp=(*aut_it).loc_to_Location[(*it).name];
				break;
			}
		}

		ret.invariants=ret.invariants^tmp.invariants;

		ret.rate=ret.rate^tmp.rate;
	}
	return ret;
}


Location convert_vector_loc_to_location(vector<Location> st,Automaton_List aut_lst)
{
	Location ret;
	ret.name="";
	for(vector<Location>::iterator it=st.begin();it!=st.end();it++)
	{
		if(it!=st.begin())
		{
			ret.name=ret.name+"~";
		}
		ret.name=ret.name+(*it).name;

		ret.invariants=ret.invariants^(*it).invariants;

		ret.rate=ret.rate^(*it).rate;

	}
	return ret;
}
bool sort_by_aut_to_vector(pair<string,string> p1,pair<string,string> p2)
{
	return (p1.second.compare(p2.second)<0);
}


bool sort_by_aut(Edge e1,Edge e2)
{
	return (e1.aut_nm.compare(e2.aut_nm)<0);
}

void insert_Location_Into_Prod(Automaton &prod,vector<Location> post,Automaton_List aut_lst)
{
	Location l;
	
	l.name="";
	
	for(vector<Location>::iterator lit=post.begin();lit!=post.end();lit++)
	{
		if(lit!=post.begin())
		{
			l.name=l.name+"~";
		}
		l.name=l.name+(*lit).name;



		l.invariants=l.invariants^(*lit).invariants;

		l.rate=l.rate^(*lit).rate;

	}
	prod.loc_lst.location_arr.push_back(l);

}

void insert_Location_Into_Prod2(Automaton &prod,vector<Location> post,Automaton_List aut_lst)
{
	Location l;
	
	l.name="";
	
	for(vector<Location>::iterator lit=post.begin();lit!=post.end();lit++)
	{
		if(lit!=post.begin())
		{
			l.name=l.name+"~";
		}
		l.name=l.name+(*lit).name;


		for(vector<Automaton>::iterator ait=aut_lst.aut_arr.begin();ait!=aut_lst.aut_arr.end();ait++)
		{			
			map<string,Location>::iterator llit=ait->loc_to_Location.find(lit->name);
			if(llit!=ait->loc_to_Location.end())
			{
				
				Location foundl=ait->loc_to_Location[lit->name];
				l.invariants=l.invariants^foundl.invariants;
				l.rate=l.rate^foundl.rate;
				break;
			}
		}

		//l.invariants=l.invariants^(*lit).invariants;

		//l.rate=l.rate^(*lit).rate;

	}
	prod.loc_lst.location_arr.push_back(l);

}
Edge find_Edge(vector<Edge> el)
{
	Edge e;
	e.syn_lab=el.begin()->syn_lab;

	for(vector<Edge>::iterator eit=el.begin();eit!=el.end();eit++)
	{
		e.guards=e.guards^(*eit).guards;
		e.updates=e.updates^(*eit).updates;
	}
	return e;

}
void insert_Edge_List_Into_Prod(Automaton &prod,vector<vector<Edge> > el)
{

	//e.aut_nm
	//e.guards
	//e.post
	//e.pre
	//e.syn_lab
	//e.updates


	for(vector<vector<Edge> >::iterator veit=el.begin();veit!=el.end();veit++)
	{
		Edge e;
		e.aut_nm=prod.name;
		e.syn_lab=veit->begin()->syn_lab;

		for(vector<Edge>::iterator eit=veit->begin();eit!=veit->end();eit++)
		{
			if(eit!=veit->begin())
			{
				e.pre=e.pre+"~";
				e.post=e.post+"~";
			}
			e.pre=e.pre+(*eit).pre;
			e.post=e.post+(*eit).post;

			e.guards=e.guards^(*eit).guards;
			e.updates=e.updates^(*eit).updates;
		}
		prod.edge_lst.edge_arr.push_back(e);
	}

}
void findPostLocEdge(vector<Location>::iterator vlbegin,vector<Location>::iterator vlcurr,vector<Location>::iterator vlend,vector<vector<Location> > &llist,vector<vector<Edge> > &elist,vector<vector<Edge> > vvelist,vector<Location> &vl_stack,vector<Edge> &el_stack,Automaton_List aut_lst,Automaton &prod)
{
	//vector<Location>::iterator vlcurr
	//vector<Location>::iterator vlend
	//vector<vector<Location> > &llist
	//vector<vector<Edge> > &elist
	//vector<vector<Edge> > vvelist
	//vector<Location> &vl_stack
	//vector<Edge> &el_stack
	if(vlcurr==vlend)
	{

		llist.push_back(vl_stack);
		elist.push_back(el_stack);

		//insert_Edge_List_Into_Prod
		Edge e=find_Edge(el_stack);
		e.aut_nm=prod.name;
		e.pre="";
		for(vector<Location>::iterator vit=vlbegin;vit!=vlend;vit++)
		{
			if(vit!=vlbegin)
			{
				e.pre=e.pre+"~";
			}
			e.pre=e.pre+vit->name;
		}

		e.post="";

		for(vector<Location>::iterator vit=vl_stack.begin();vit!=vl_stack.end();vit++)
		{
			if(vit!=vl_stack.begin())
			{
				e.post=e.post+"~";
			}
			e.post=e.post+vit->name;
		}
		prod.edge_lst.edge_arr.push_back(e);
		//vl_stack.pop_back();
		//el_stack.pop_back();
		//cout<<"here now:"<<llist.size()<<" "<<elist.size()<<endl;
		return;
	}
	bool flg=false;
	//assuming vvelist is only list of single synchronization label & is sorted by automaton
	for(vector<vector<Edge> >::iterator veit=vvelist.begin();veit!=vvelist.end();veit++)
	{
		if(veit->begin()->pre.compare(vlcurr->name)==0)
		{

			for(vector<Edge>::iterator eit=veit->begin();eit!=veit->end();eit++)
			{

				//put post location into vl_stack
				for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
				{
					if(aut_it->name.compare(eit->aut_nm)==0)
					{
						//cout<<"Compared:"<<veit->begin()->pre<<" "<<vlcurr->name<<endl;
						vl_stack.push_back(aut_it->loc_to_Location[eit->post]);
						break;
					}
				}

				el_stack.push_back(*eit);
				findPostLocEdge(vlbegin,vlcurr+1,vlend,llist,elist,vvelist,vl_stack,el_stack,aut_lst,prod);

				vl_stack.pop_back();
				el_stack.pop_back();

			}
			flg=true;

		}
	}
	if(flg==false)
	{
		vl_stack.push_back(*vlcurr);
		findPostLocEdge(vlbegin,vlcurr+1,vlend,llist,elist,vvelist,vl_stack,el_stack,aut_lst,prod);
		vl_stack.pop_back();
	}

}
bool is_in_vector_vector_location(vector<Location> post,vector<vector<Location> > que)
{
	for(vector<vector<Location> >::iterator vvlit=que.begin();vvlit!=que.end();vvlit++)
	{
		bool val=true;
		vector<Location>::iterator postlit;
		postlit=post.begin();
		for(vector<Location>::iterator vlit=vvlit->begin();vlit!=vvlit->end();vlit++)
		{
			if(vlit->name.compare(postlit->name)!=0)
			{
				val=false;
				break;
			}
			postlit++;

		}
		if(val==true)
			return true;
	}
	return false;
}

void generate_LocList_EdgeList(vector<vector<Location> > &llist,vector<vector<Edge> > &elist,vector<vector<Edge> > vvelist,vector<Location> vl,Automaton_List aut_lst,Automaton &prod)
{
	vector<Location> vl_stack;
	vector<Edge> el_stack;
	findPostLocEdge(vl.begin(),vl.begin(),vl.end(),llist,elist,vvelist,vl_stack,el_stack,aut_lst,prod);
	//cout<<"LList:"<<llist.size()<<endl;
}

void calculate_States(Automaton_List aut_lst,Automaton &prod,multimap<string,string> synlab_to_aut_map)
{
	vector<vector<Location> > initial_states;
	vector<Location> Riloc_queue;
	find_Initial_Locations(Riloc_queue,initial_states,aut_lst.aut_arr.begin(),aut_lst.aut_arr.end());

	for(vector<vector<Location> >::iterator it=initial_states.begin();it!=initial_states.end();it++)
	{
		Location l=convert_vector_loc_to_location(*it,aut_lst);
		prod.initial_loc_lst.location_arr.push_back(l);
		//cout<<"Added initial location:"<<l.name<<" ,invar:"<<l.invariants<<endl;
	}

	vector<vector<Location> > loc_under_process_que;
	vector<vector<Location> > loc_already_processed_que;
	//cout<<"Size:"<<initial_states.size()<<endl;
	for(vector<vector<Location> >::iterator it=initial_states.begin();it!=initial_states.end();it++)
	{
		
		Location vl=convert_vector_loc_to_location_with_original_invariants(*it,aut_lst);
		prod.loc_lst.location_arr.push_back(vl);
		loc_under_process_que.push_back(*it);
		//cout<<"Added location under process:"<<vl.name<<" ,invar:"<<vl.invariants<<endl;
	}




	while(!loc_under_process_que.empty())
	{
		vector<Location> vl;
		vl=loc_under_process_que.front();
		//cout<<"Before erasing:"<<loc_under_process_que.size()<<endl;
		loc_under_process_que.erase(loc_under_process_que.begin());

		//cout<<"After erasing:"<<loc_under_process_que.size()<<endl;

		loc_already_processed_que.push_back(vl);

		Edge_List elist;
		for(vector<Location>::iterator lit=vl.begin();lit!=vl.end();lit++)
		{
			//cout<<"Here"<<endl;

			Automaton aut;
			for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
			{
				if((*aut_it).loc_to_Location.find((*lit).name)!=(*aut_it).loc_to_Location.end())
				{
					aut=(*aut_it);
					break;
				}
			}
			pair<multimap<string,LocEdge>::iterator,multimap<string,LocEdge>::iterator> mm_to_mm;
			mm_to_mm=aut.pre_to_edge_plus_post.equal_range((*lit).name);
			for(multimap<string,LocEdge>::iterator mer=mm_to_mm.first;mer!=mm_to_mm.second;mer++)
			{
				//Edge e;
				//e=(*mer).second.e;
				(*mer).second.e.aut_nm=aut.name;
				elist.edge_arr.push_back((*mer).second.e);
			}
		}


		vector<vector<Edge> > velist;
		velist=elist.aggregate_on_sync_lab();


		//for each active syn label on edge
		for(vector<vector<Edge> >::iterator veit=velist.begin();veit!=velist.end();veit++)
		{
			//veit synctoautmap
			vector<vector<Edge> > vvelist;
			Edge_List tmpedgelist;
			for(vector<Edge>::iterator eit=(*veit).begin();eit!=(*veit).end();eit++)
			{
				tmpedgelist.edge_arr.push_back(*eit);
			}


			vvelist=tmpedgelist.aggregate_on_aut();

			//cout<<"Number of edges:"<<vvelist.size()<<endl;


			pair<multimap<string,string>::iterator,multimap<string,string>::iterator> syn_aut;
			syn_aut=synlab_to_aut_map.equal_range(veit->begin()->syn_lab);
			//cout<<"Current synlab:"<<veit->begin()->syn_lab<<endl;

			vector<pair<string,string> > vp;
			for(multimap<string,string>::iterator stst=syn_aut.first;stst!=syn_aut.second;stst++)
			{
				vp.push_back(pair<string,string>(stst->first,stst->second));
			}
			sort(vp.begin(),vp.end(),sort_by_aut_to_vector);
			//cout<<"Number of aut having "<<veit->begin()->syn_lab<<" as label "<<vp.size()<<endl;

			if(vp.begin()->first.compare("")!=0)
			{
				vector<pair<string,string> >::iterator vpit=vp.begin();
				vector<vector<Edge> >::iterator vvelistit=vvelist.begin();

				while(vpit!=vp.end() && vvelistit!=vvelist.end())
				{
					//cout<<"AL:"<<vpit->second<<" "<<vvelistit->begin()->aut_nm<<" "<<vpit->second.compare(vvelistit->begin()->aut_nm)<<endl;
					if(vpit->second.compare(vvelistit->begin()->aut_nm)==0)
					{
						//cout<<"Compared successfully "<<vpit->second<<" "<<vvelistit->begin()->aut_nm<<endl;
						vpit++;
						vvelistit++;


					}
					else
						break;
				}

				if(vpit==vp.end() && vvelistit==vvelist.end())
				{
					//cout<<"Hahaha"<<endl;
					//generate location and edge of resultant automata
					vector<vector<Location> > llist;
					vector<vector<Edge> > elist;
					generate_LocList_EdgeList(llist,elist,vvelist,vl,aut_lst,prod);

					//cout<<"Location size:"<<llist.size()<<endl;
					for(vector<vector<Location> >::iterator postlit=llist.begin();postlit!=llist.end();postlit++)
					{
						//loc_already_processed_que (*postlit)
						//if(loc_already_processed_que.end()==find(loc_already_processed_que.begin(),loc_already_processed_que.end(),*postlit) && loc_under_process_que.end()==find(loc_under_process_que.begin(),loc_under_process_que.end(),*postlit))
						bool ans1=is_in_vector_vector_location(*postlit,loc_already_processed_que);
						bool ans2=is_in_vector_vector_location(*postlit,loc_under_process_que);
						if((!ans1) && (!ans2))
						{
							loc_under_process_que.push_back(*postlit);
							insert_Location_Into_Prod2(prod,*postlit,aut_lst);
						}
					}


					//insert_Edge_List_Into_Prod(prod,elist);

					//if post location formed by it is already in the loc list of prod
						//add_this_aggregate edge to the edge of prod
					//else
						//add post location to loc list
						//add_this_aggregate edge to the edge of prod

				}
			}
			else
			{
				//generate location and edge of resultant automata
				//if post location formed by it is already in the loc list of prod
					//add_this_aggregate edge to the edge of prod
				//else
					//add post location to loc list
					//add_this_aggregate edge to the edge of prod

			}


			//if current set of edges have exactly same automatons
				//if post location formed by it is already in the loc list of prod
					//add_this_aggregate edge to the edge of prod
				//else
					//add post location to loc list
					//add_this_aggregate edge to the edge of prod
			//else
				//discard the edge


		}
	}
}

Automaton take_product(Automaton_List aut_lst)
{
	multimap<string,string> synlab_to_aut_map;
	Automaton prod;
	/*	Control_Variable_List cntr_var_lst;
		Parameter_List parameter_lst;
		Synchronizing_Label_List syn_lab_lst;
		Input_Variable_List in_var_lst;*/
	int var_no=0;
	string aut_nm;
	aut_nm="";
	for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
	{
		if(aut_it!=aut_lst.aut_arr.begin())
		{
			aut_nm=aut_nm+"~";
		}
		aut_nm=aut_nm+aut_it->name;
		for(vector<string>::iterator cntr_it=aut_it->cntr_var_lst.cntr_var_arr.begin();cntr_it!=aut_it->cntr_var_lst.cntr_var_arr.end();cntr_it++)
		{

			prod.cntr_var_lst.cntr_var_arr.push_back(*cntr_it);
			prod.cntr_var_lst.cntr_vars.push_back(Variable(var_no));
			var_no++;
		}
		for(vector<Parameter>::iterator par_it=aut_it->parameter_lst.par_list_arr.begin();par_it!=aut_it->parameter_lst.par_list_arr.end();par_it++)
		{
			if(prod.parameter_lst.par_list_arr.end()==find(prod.parameter_lst.par_list_arr.begin(),prod.parameter_lst.par_list_arr.end(),*par_it))
			{
				prod.parameter_lst.par_list_arr.push_back(*par_it);
			}
		}
		for(vector<Synchronizing_Label>::iterator syn_it=aut_it->syn_lab_lst.syn_lab_arr.begin();syn_it!=aut_it->syn_lab_lst.syn_lab_arr.end();syn_it++)
		{
			synlab_to_aut_map.insert(pair<string,string>(syn_it->name,aut_it->name));

			if(prod.syn_lab_lst.syn_lab_arr.end()==find(prod.syn_lab_lst.syn_lab_arr.begin(),prod.syn_lab_lst.syn_lab_arr.end(),*syn_it))
			{
				prod.syn_lab_lst.syn_lab_arr.push_back(*syn_it);
			}
		}


	}
	prod.assign_Name(aut_nm);
	//cout<<"Automaton name:"<<prod.name<<endl;

	calculate_States(aut_lst,prod,synlab_to_aut_map);

	return prod;
}


Automaton take_product2(Automaton_List aut_lst)
{
	multimap<string,string> synlab_to_aut_map;
	Automaton prod;

	int var_no=0;
	string aut_nm;
	aut_nm="";

	set<string> cntr,param,invar,synlab;

	for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
	{
		if(aut_it!=aut_lst.aut_arr.begin())
		{
			aut_nm=aut_nm+"~";
		}
		aut_nm=aut_nm+aut_it->name;
		for(vector<string>::iterator cntr_it=aut_it->cntr_var_lst.cntr_var_arr.begin();cntr_it!=aut_it->cntr_var_lst.cntr_var_arr.end();cntr_it++)
		{
			int prevsize=cntr.size();
			cntr.insert(*cntr_it);
			int newsize=cntr.size();
			
			if(prevsize!=newsize)
			{
				prod.cntr_var_lst.cntr_var_arr.push_back(*cntr_it);
				prod.cntr_var_lst.cntr_vars.push_back(Variable(var_no));
				var_no++;
			}
		}
		for(vector<Parameter>::iterator par_it=aut_it->parameter_lst.par_list_arr.begin();par_it!=aut_it->parameter_lst.par_list_arr.end();par_it++)
		{
			if(prod.parameter_lst.par_list_arr.end()==find(prod.parameter_lst.par_list_arr.begin(),prod.parameter_lst.par_list_arr.end(),*par_it))
			{
				prod.parameter_lst.par_list_arr.push_back(*par_it);
			}
		}
		for(vector<Synchronizing_Label>::iterator syn_it=aut_it->syn_lab_lst.syn_lab_arr.begin();syn_it!=aut_it->syn_lab_lst.syn_lab_arr.end();syn_it++)
		{
			synlab_to_aut_map.insert(pair<string,string>(syn_it->name,aut_it->name));

			if(prod.syn_lab_lst.syn_lab_arr.end()==find(prod.syn_lab_lst.syn_lab_arr.begin(),prod.syn_lab_lst.syn_lab_arr.end(),*syn_it))
			{
				prod.syn_lab_lst.syn_lab_arr.push_back(*syn_it);
			}
		}


	}
	prod.assign_Name(aut_nm);
	//cout<<"Automaton name:"<<prod.name<<endl;

	calculate_States(aut_lst,prod,synlab_to_aut_map);

	return prod;
}


vector<string> find_fireable_Syn_Lab(Edge_List elist,multimap<string,string> synlab_to_aut_map)
{
	vector<string> ret;
	if(elist.edge_arr.size()==0)	
		return ret;

	vector<vector<Edge> > velist;
	velist=elist.aggregate_on_sync_lab();
	bool blanksyncflag=false;
	for(vector<vector<Edge> >::iterator veit=velist.begin();veit!=velist.end();veit++)
	{
		//veit synctoautmap
		vector<vector<Edge> > vvelist;
		Edge_List tmpedgelist;
		for(vector<Edge>::iterator eit=(*veit).begin();eit!=(*veit).end();eit++)
		{
			tmpedgelist.edge_arr.push_back(*eit);
		}


		vvelist=tmpedgelist.aggregate_on_aut();

		//cout<<"Number of edges:"<<vvelist.size()<<endl;


		pair<multimap<string,string>::iterator,multimap<string,string>::iterator> syn_aut;
		syn_aut=synlab_to_aut_map.equal_range(veit->begin()->syn_lab);
		//cout<<"Current synlab:"<<veit->begin()->syn_lab<<endl;

		vector<pair<string,string> > vp;
		for(multimap<string,string>::iterator stst=syn_aut.first;stst!=syn_aut.second;stst++)
		{
			vp.push_back(pair<string,string>(stst->first,stst->second));
		}
		sort(vp.begin(),vp.end(),sort_by_aut_to_vector);
		//cout<<"Number of aut having "<<veit->begin()->syn_lab<<" as label "<<vp.size()<<endl;

		if(vp.begin()->first.compare("")!=0)
		{
			vector<pair<string,string> >::iterator vpit=vp.begin();
			vector<vector<Edge> >::iterator vvelistit=vvelist.begin();

			while(vpit!=vp.end() && vvelistit!=vvelist.end())
			{
				//cout<<"AL:"<<vpit->second<<" "<<vvelistit->begin()->aut_nm<<" "<<vpit->second.compare(vvelistit->begin()->aut_nm)<<endl;
				if(vpit->second.compare(vvelistit->begin()->aut_nm)==0)
				{
					//cout<<"Compared successfully "<<vpit->second<<" "<<vvelistit->begin()->aut_nm<<endl;
					vpit++;
					vvelistit++;


				}
				else
					break;
			}

			if(vpit==vp.end() && vvelistit==vvelist.end())
			{
				//veit->begin()->syn_lab
				ret.push_back(veit->begin()->syn_lab);
				/*
				//cout<<"Hahaha"<<endl;
				//generate location and edge of resultant automata
				vector<vector<Location> > llist;
				vector<vector<Edge> > elist;
				generate_LocList_EdgeList(llist,elist,vvelist,vl,aut_lst,prod);

				cout<<"Location size:"<<llist.size()<<endl;
				for(vector<vector<Location> >::iterator postlit=llist.begin();postlit!=llist.end();postlit++)
				{
					//loc_already_processed_que (*postlit)
					//if(loc_already_processed_que.end()==find(loc_already_processed_que.begin(),loc_already_processed_que.end(),*postlit) && loc_under_process_que.end()==find(loc_under_process_que.begin(),loc_under_process_que.end(),*postlit))
					bool ans1=is_in_vector_vector_location(*postlit,loc_already_processed_que);
					bool ans2=is_in_vector_vector_location(*postlit,loc_under_process_que);
					if((!ans1) && (!ans2))
					{
						loc_under_process_que.push_back(*postlit);
						insert_Location_Into_Prod(prod,*postlit);
					}
				}


				//insert_Edge_List_Into_Prod(prod,elist);

				//if post location formed by it is already in the loc list of prod
					//add_this_aggregate edge to the edge of prod
				//else
					//add post location to loc list
					//add_this_aggregate edge to the edge of prod
				*/
			}
		}
		else
		{
			blanksyncflag=true;
			//generate location and edge of resultant automata
			//if post location formed by it is already in the loc list of prod
				//add_this_aggregate edge to the edge of prod
			//else
				//add post location to loc list
				//add_this_aggregate edge to the edge of prod

		}


	}
	if(blanksyncflag==true)
		ret.push_back("");

	return ret;


}

void find_next_power_set(vector<vector<string> > &ret,vector<string> &tmp,vector<string>::iterator firableSynLabcurr,vector<string>::iterator firableSynLabend)
{
	if(firableSynLabcurr==firableSynLabend)
	{
		/*cout<<"My:"<<endl;
		//cout<<"    "<<*(ret.begin())<<endl;
		for(vector<vector<string> >::iterator it=ret.begin();it!=ret.end();it++)
		{
			for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
				cout<<" "<<*itt<<endl;
		}*/
		if(tmp.size()!=0)
			ret.push_back(tmp);
		return;
	}
	//cout<<"Curr_symb: "<<*firableSynLabcurr<<endl;
	tmp.push_back(*firableSynLabcurr);
	find_next_power_set(ret,tmp,firableSynLabcurr+1,firableSynLabend);
	tmp.pop_back();
	find_next_power_set(ret,tmp,firableSynLabcurr+1,firableSynLabend);
}
vector<vector<string> > find_Power_Set(vector<string> firableSynLab)
{
	vector<vector<string> > ret;
	vector<string> tmp;
	//cout<<"Before:"<<*firableSynLab.begin()<<endl;
	find_next_power_set(ret,tmp,firableSynLab.begin(),firableSynLab.end());
	return ret;
}

bool is_Automaton_Requirement_disjoint(vector<string> synset,multimap<string,string> synlab_to_aut_map)
{
	set<string> autset;
	for(vector<string>::iterator stit=synset.begin();stit!=synset.end();stit++)
	{
		pair<multimap<string,string>::iterator,multimap<string,string>::iterator> syn_aut;
		syn_aut=synlab_to_aut_map.equal_range(*stit);
		//cout<<"Current synlab:"<<(*stit)<<endl;

		vector<pair<string,string> > vp;
		for(multimap<string,string>::iterator stst=syn_aut.first;stst!=syn_aut.second;stst++)
		{
			if(autset.end()==autset.find(stst->second))
			{
				autset.insert(stst->second);
			}
			else
			{
				return false;
			}

		}

	}
	return true;
}
void generate_seq(vector<string> &seq_stack,vector<vector<string> > &vseq,vector<string> vsyn)
{
	vector<string> tmpsyn=vsyn;
	if(vsyn.size()==0)
	{
		//cout<<"Seq stack size:"<<seq_stack.size()<<endl;
		vseq.push_back(seq_stack);
		return;
	}
	for(vector<string>::iterator it=vsyn.begin();it!=vsyn.end();it++)
	{
		seq_stack.push_back(*it);
		tmpsyn.erase(tmpsyn.begin()+(it-vsyn.begin()));
		//cout<<"tmpsynsize:"<<tmpsyn.size()<<endl;
		generate_seq(seq_stack,vseq,tmpsyn);

		seq_stack.pop_back();
		tmpsyn=vsyn;
	}
}
vector<vector<string> > generate_all_sequences(vector<string> vsyn)
{
	vector<vector<string> > vseq;
	vector<string> seq_stack;
	generate_seq(seq_stack,vseq,vsyn);
	return vseq;
}
Edge_List remove_unwanted_edges(Edge_List elist,vector<string> seq)
{
	Edge_List ret;
	for(vector<Edge>::iterator it=elist.edge_arr.begin();it!=elist.edge_arr.end();it++)
	{
		if(seq.end()!=find(seq.begin(),seq.end(),it->syn_lab))
		{
			ret.edge_arr.push_back(*it);
		}
	}
	return ret;
}
vector<Edge> find_edgelist_on_sync(string synlab,vector<vector<Edge> > agregate_syn_elist)
{
	vector<Edge> ret;
	for(vector<vector<Edge> >::iterator it=agregate_syn_elist.begin();it!=agregate_syn_elist.end();it++)
	{
		if(it->begin()->syn_lab==synlab)
		{
			ret=*it;
			break;
		}
	}
	return ret;
}
vector<Edge_List> sequentialize_and_aggregate_elist_on_seq(Edge_List newelist,vector<string> seq)
{
	vector<vector<Edge> > agregate_syn_elist=newelist.aggregate_on_sync_lab();
	vector<Edge_List> ret;
	Edge_List tmp;
	for(vector<string>::iterator it=seq.begin();it!=seq.end();it++)
	{
		vector<Edge> ve=find_edgelist_on_sync(*it,agregate_syn_elist);
		tmp.edge_arr=ve;
		ret.push_back(tmp);
	}
	return ret;
}
void findNextEdgeofICTA(vector<vector<Edge> > &ret,vector<Edge> &edgestack,vector<vector<Edge> >::iterator curr,vector<vector<Edge> >::iterator end)
{
	if(curr==end)
	{
		/*Edge e;
		for(vector<Edge>::iterator it=edgestack.begin();it!=edgestack.end();it++)
		{
			if(it!=edgestack.begin())
			{
				e.aut_nm=e.aut_nm+"~";
				e.post=e.post+"~";
				e.pre=e.pre+"~";
			}

			e.aut_nm=e.aut_nm+it->aut_nm;
			e.guards=e.guards^it->guards;
			e.post=e.post+it->post;
			e.pre=e.pre+it->pre;
			e.updates=e.updates^it->updates;

		}

		ret.push_back(e);*/
		ret.push_back(edgestack);
		/*cout<<"Pushing edgestack to ret:"<<endl;
		for(vector<Edge>::iterator it=edgestack.begin();it!=edgestack.end();it++)
		{
			cout<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->updates<<" "<<it->syn_lab<<endl;
		}
		cout<<endl;*/
		return;
	}
	for(vector<Edge>::iterator it=curr->begin();it!=curr->end();it++)
	{
		edgestack.push_back(*it);
		findNextEdgeofICTA(ret,edgestack,curr+1,end);
		edgestack.pop_back();
	}
}
vector<vector<Edge> > findEdgeListFromEdgeListList(vector<vector<Edge> > vve)
{
	vector<Edge> edgestack;
	vector<vector<Edge> > ret;
	/*cout<<"Inputtttt:"<<endl;
	for(vector<vector<Edge> >::iterator itt=vve.begin();itt!=vve.end();itt++)
	{
		for(vector<Edge>::iterator it=itt->begin();it!=itt->end();it++)
		{
			cout<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->updates<<" "<<it->syn_lab<<endl;
		}
		cout<<endl;
	}	
	*/
	findNextEdgeofICTA(ret,edgestack,vve.begin(),vve.end());
	return ret;
}
vector<vector<Edge> > make_additions_into_edge_syn_dim(vector<vector<Edge> > ret,vector<vector<Edge> > tmpedgevector)
{
	vector<vector<Edge> > newret;
	vector<Edge> tmp;
	if(ret.size()==0)
	{
		return tmpedgevector;
	}
	for(vector<vector<Edge> >::iterator it=ret.begin();it!=ret.end();it++)
	{
		
		for(vector<vector<Edge> >::iterator itt=tmpedgevector.begin();itt!=tmpedgevector.end();itt++)
		{
			tmp=*it;
			for(vector<Edge>::iterator ittt=itt->begin();ittt!=itt->end();ittt++)
			{
				tmp.push_back(*ittt);
			}
			newret.push_back(tmp);
		}
		

	}
	return newret;
}

vector<vector<Edge> > generate_all_edges_from_syn_seq(Edge_List elist,vector<string> seq,Automaton_List aut_lst)
{



	//remove all edges from elist in which syn lab seq is not present
	//cout<<"Prevelist size:"<<elist.edge_arr.size()<<endl;
	Edge_List newelist=remove_unwanted_edges(elist,seq);
	//cout<<"Newelist size:"<<newelist.edge_arr.size()<<endl;
	//sequentialize all remaining elist on the seq
	vector<Edge_List> vve=sequentialize_and_aggregate_elist_on_seq(newelist,seq);
	
	/*cout<<"Seq:"<<endl;
	for(vector<string>::iterator it=seq.begin();it!=seq.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\nAggregated on seq:"<<endl;
	for(vector<Edge_List>::iterator it=vve.begin();it!=vve.end();it++)
	{
		for(vector<Edge>::iterator itt=it->edge_arr.begin();itt!=it->edge_arr.end();itt++)
		{
			cout<<itt->pre<<" "<<itt->post<<" "<<itt->guards<<" "<<itt->updates<<" "<<itt->syn_lab<<"	"<<endl;
		}
		cout<<endl;
	}
	*/
	vector<vector<vector<Edge> > > agre_on_seq_and_aut;
	//for each edgepart
	for(vector<Edge_List>::iterator it=vve.begin();it!=vve.end();it++)
	{
		//aggregate each edgepart on automaton
		vector<vector<Edge> > eit=it->aggregate_on_aut();
		//cout<<"Sizzzzze:"<<eit.size()<<endl;

		agre_on_seq_and_aut.push_back(it->aggregate_on_aut());
	//end
	}

	//initialize ret vector<vector<Edge> >
	vector<vector<Edge> > ret;
	//initialize tmp vector<vector<Edge> >
	vector<vector<Edge> > tmpedgevector;
	//for every synlab in seq
	for(vector<vector<vector<Edge> > >::iterator it=agre_on_seq_and_aut.begin();it!=agre_on_seq_and_aut.end();it++)
	{
		//tmpsynedlst=findedgelist(edgelistlist,currentlypickedsynlab)
		tmpedgevector=findEdgeListFromEdgeListList(*it);


		//tmp=tmp*tmpsynedlst
		ret=make_additions_into_edge_syn_dim(ret,tmpedgevector);

	//end
	}
	/*cout<<"Return:"<<endl;
	for(vector<vector<Edge> >::iterator eiit=ret.begin();eiit!=ret.end();eiit++)
	{
		for(vector<Edge>::iterator eit=eiit->begin();eit!=eiit->end();eit++)
		{
			cout<<eit->pre<<" "<<eit->post<<" "<<eit->guards<<" "<<eit->updates<<" "<<eit->syn_lab<<endl;
		}
		cout<<endl;
	}
	cout<<"Return size:"<<ret.size()<<endl;*/
	//ret=tmp
	//return ret
	return ret;
}
Constraint_System reset_All_Variables(Constraint_System rt)
{
	Constraint_System cs;
	cs.set_space_dimension(rt.space_dimension());
	for(int i=0;i<rt.space_dimension();i++)
	{
		cs.insert(Variable(i)==0);
	}
	return cs;
}
vector<Location> generate_all_locations_for_syn_seq(vector<Location> preset,vector<vector<Location> > &loc_under_process_que,vector<vector<Location> > &loc_already_processed_que,vector<string> seq,vector<Edge> ve,Automaton_List aut_lst,Automaton prod)
{
	vector<Location> ret;
	Location pre;
	/*cout<<"Seq:";
	for(vector<string>::iterator it=seq.begin();it!=seq.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;*/

	/*cout<<"Preset:";
	for(vector<Location>::iterator itp=preset.begin();itp!=preset.end();itp++)
	{
		cout<<itp->name<<" ";
	}
	cout<<endl;*/



	vector<Location> postset;

	for(vector<Location>::iterator it=preset.begin();it!=preset.end();it++)
	{
		if(it!=preset.begin())
		{
			pre.name=pre.name+"~";
		}
		Automaton tmpaut;
		for(vector<Automaton>::iterator ait=aut_lst.aut_arr.begin();ait!=aut_lst.aut_arr.end();ait++)
		{
			if(ait->loc_to_Location.end()!=ait->loc_to_Location.find(it->name))
			{
				tmpaut=*ait;
				break;
			}
		}
		pre.name=pre.name+it->name;
		pre.invariants=pre.invariants^tmpaut.loc_to_invar[it->name];
		pre.rate=pre.rate^tmpaut.loc_to_rate[it->name];
	}

	Location pr=pre;
	pr.name=pr.name+",phi";
	ret.push_back(pr);

	bool ans1=is_in_vector_vector_location(preset,loc_already_processed_que);
	bool ans2=is_in_vector_vector_location(preset,loc_under_process_que);
	if((!ans1) && (!ans2))
	{
		loc_under_process_que.push_back(preset);
	}



	Location post;
	string postloc="";
	for(vector<Location>::iterator lit=preset.begin();lit!=preset.end();lit++)
	{
		if(lit!=preset.begin())
		{
			post.name=post.name.append("~");
		}
		bool flg=false;
		for(vector<Edge>::iterator it=ve.begin();it!=ve.end();it++)
		{
			if(lit->name==it->pre)
			{
				flg=true;
				postloc=it->post;
				break;
			}

		}
		if(flg==false)
		{
			postset.push_back(*lit);
			post.name=post.name.append(lit->name);
			post.invariants=post.invariants^lit->invariants;
			post.rate=post.rate^lit->rate;
		}
		else
		{
			Automaton tmpaut;
			//cout<<"Comparing "<<postloc<<""<<postloc.size()<<endl;
			for(vector<Automaton>::iterator ait=aut_lst.aut_arr.begin();ait!=aut_lst.aut_arr.end();ait++)
			{
				/*cout<<"Map:";
				for(map<string,Location>::iterator itc=ait->loc_to_Location.begin();itc!=ait->loc_to_Location.end();itc++)
				{
					cout<<itc->first<<" ";
				}
				cout<<endl;
				*/
				//if(ait->loc_to_Location.count(postloc)>0)
				if(ait->loc_to_Location.end()!=ait->loc_to_Location.find(postloc))
				{
					//cout<<"Compared successfully"<<endl;
					tmpaut=*ait;
					break;
				}
			}
			Location postlocc;
			postlocc=tmpaut.loc_to_Location[postloc];
			postset.push_back(postlocc);
			post.name=post.name.append(postlocc.name);
			post.invariants=post.invariants^postlocc.invariants;
			post.rate=post.rate^postlocc.rate;

		}
	}


	//cout<<"Generated post:"<<post.name<<endl;

	int cnt=seq.size();
	Location pst=post;
	pst.name=pst.name+","+"phi";
	ret.push_back(pst);

	ans1=is_in_vector_vector_location(postset,loc_already_processed_que);
	ans2=is_in_vector_vector_location(postset,loc_under_process_que);
	if((!ans1) && (!ans2))
	{
		loc_under_process_que.push_back(postset);
	}


	for(int i=0;i<cnt;i++)
	{
		pst=post;
		string synlabset;
		synlabset="";

		vector<string> sortseq=seq;
		sort(sortseq.begin(),sortseq.end());
		for(vector<string>::iterator it=sortseq.begin();it!=sortseq.end();it++)
		{
			if(it!=sortseq.begin())
				synlabset=synlabset+",";
			synlabset=synlabset+(*it);
		}
		pst.name=pst.name+","+synlabset;
		pst.rate.set_space_dimension(prod.cntr_var_lst.cntr_var_arr.size());
		pst.rate=reset_All_Variables(pst.rate);
		//cout<<"Reseted rate:"<<pst.rate<<pst.rate.space_dimension()<<endl;
		//cout<<"generated:"<<pst.name<<endl;
		ret.push_back(pst);
		seq.erase(seq.begin());
	}
	return ret;
}
vector<Edge> generate_all_edges_for_syn_seq(vector<Location> vl,vector<Edge> el,vector<string> seq,Automaton prod)
{
	string pre;
	pre="";
	string post;
	post="";

	Constraint_System guards;
	guards.set_space_dimension(el.begin()->guards.space_dimension());

	Constraint_System updates;
	updates.set_space_dimension(el.begin()->updates.space_dimension());

	for(vector<Edge>::iterator eit=el.begin();eit!=el.end();eit++)
	{
		//guards=guards^eit->guards;
		for(Constraint_System_const_iterator csit=eit->guards.begin();csit!=eit->guards.end();csit++)
		{
			guards.insert(*csit);
		}
		
		//updates=updates^eit->updates;
		for(Constraint_System_const_iterator csit=eit->updates.begin();csit!=eit->updates.end();csit++)
		{
			updates.insert(*csit);
		}
	}
	//cout<<"Generated guard:"<<guards<<endl;
	//cout<<"Generated update:"<<updates<<endl;


	for(vector<Location>::iterator it=vl.begin();it!=vl.end();it++)
	{
		if(it!=vl.begin())
		{
			pre=pre+"~";
		}
		pre=pre+it->name;
	}
	//cout<<"Pre:"<<pre<<endl;


	bool flg=false;
	string tmp="";
	for(vector<Location>::iterator it=vl.begin();it!=vl.end();it++)
	{
		flg=false;
		for(vector<Edge>::iterator eit=el.begin();eit!=el.end();eit++)
		{
			if(eit->pre==it->name)
			{
				flg=true;
				tmp=eit->post;
				break;
			}

		}
		if(it!=vl.begin())
			post=post+"~";
		if(flg==true)
			post=post+tmp;
		else
			post=post+it->name;
	}
	//cout<<"Post:"<<post<<endl;
	vector<Edge> ve;
	Edge e;


	string strseq="";
	vector<string> sortseq=seq;
	sort(sortseq.begin(),sortseq.end());
	for(vector<string>::iterator it=sortseq.begin();it!=sortseq.end();it++)
	{
		if(it!=sortseq.begin())
			strseq=strseq+",";
		strseq=strseq+(*it);
	}

	/*for(vector<string>::iterator it=seq.begin();it!=seq.end();it++)
	{
		if(it!=seq.begin())
			strseq=strseq+",";
		strseq=strseq+(*it);
	}*/
	//cout<<"Seq:"<<strseq<<endl;

	//generate first edge
	e.pre=pre+",phi";
	e.post=post+","+strseq;
	e.guards=guards;
	e.updates=updates;
	e.aut_nm=prod.name;
	ve.push_back(e);


	string next;
	string prev=e.post;
	string curr_syn;

	Constraint_System trueConstraint;
	trueConstraint.set_space_dimension(el.begin()->guards.space_dimension());



	for(int i=0;i<seq.size();i++)
	{
		next="";
		curr_syn=(*seq.begin());
		seq.erase(seq.begin());

		vector<string> sortseq=seq;
		sort(sortseq.begin(),sortseq.end());
		for(vector<string>::iterator it=sortseq.begin();it!=sortseq.end();it++)
		{
			if(it!=sortseq.begin())
				next=next+",";
			next=next+(*it);
		}

		/*for(vector<string>::iterator it=seq.begin();it!=seq.end();it++)
		{
			if(it!=seq.begin())
				next=next+",";
			next=next+(*it);
		}*/
		if(next=="")
			next="phi";
		next=post+","+next;
		e.pre=prev;

		e.post=next;
		e.syn_lab=curr_syn;
		e.guards=trueConstraint;
		e.updates=trueConstraint;
		ve.push_back(e);

		prev=next;

	}
	return ve;
}
void generate_Locations_And_Edges_of_ICTA_From(vector<vector<Location> > &loc_under_process_que,vector<vector<Location> > &loc_already_processed_que,Edge_List elist,vector<Location> vl,vector<string> vsyn,Automaton_List aut_lst,Automaton &prod)
{
	/*cout<<"SynList:"<<endl;
	for(vector<string>::iterator it=vsyn.begin();it!=vsyn.end();it++)
	{
		cout<<*it<<" ";
	}	
	cout<<endl;

	cout<<"Edge list inputed:"<<endl;
	for(vector<Edge>::iterator it=elist.edge_arr.begin();it!=elist.edge_arr.end();it++)
	{
		cout<<it->pre<<" "<<it->post<<" "<<it->guards<<" "<<it->updates<<" "<<it->syn_lab<<endl;
	}
	cout<<endl;*/

	vector<vector<string> > vseq=generate_all_sequences(vsyn);
	//cout<<"sizeofseq:"<<vseq.size()<<endl;
	//cout<<"Seqlength:"<<vsyn.size()<<" generated seqlength:"<<vseq.size()<<endl;//<<" "<<(*(vseq.begin()->begin()))<<" "<<(*((vseq.begin()+1)->begin()))<<endl;
	


	for(vector<vector<string> >::iterator it=vseq.begin();it!=vseq.end();it++)
	{
		//generate all edge sequences from this corresponding to current seq
		vector<vector<Edge> > vve=generate_all_edges_from_syn_seq(elist,*it,aut_lst);
		//cout<<"Edges sizee:"<<vve.size()<<endl;

		/*cout<<"Seq Generated:"<<endl;
		for(vector<string>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			cout<<*itt;
		}
		cout<<endl;


		for(vector<vector<Edge> >::iterator itp=vve.begin();itp!=vve.end();itp++)
		{
			cout<<"Edge "<<endl;
			for(vector<Edge>::iterator itc=itp->begin();itc!=itp->end();itc++)
			{
				cout<<itc->pre<<" "<<itc->post<<" "<<itc->guards<<" "<<itc->updates<<" "<<itc->syn_lab<<endl;
			}
			cout<<endl;
		}*/


		//for each set of edges choosen
		for(vector<vector<Edge> >::iterator veit=vve.begin();veit!=vve.end();veit++)
		{

			//generate all locations for current syn seq
			vector<Location> vll=generate_all_locations_for_syn_seq(vl,loc_under_process_que,loc_already_processed_que,*it,*veit,aut_lst,prod);

			/*cout<<"Generated locations size:"<<vll.size()<<endl;

			for(vector<Location>::iterator itc=vll.begin();itc!=vll.end();itc++)
			{
				cout<<itc->name<<" "<<itc->invariants<<" "<<itc->rate<<endl;
			}
			*/

			//push these locations to prod automata locations
			for(vector<Location>::iterator vlit=vll.begin();vlit!=vll.end();vlit++)
			{
				//if(prod.loc_lst.location_arr.end()==find(prod.loc_lst.location_arr.begin(),prod.loc_lst.location_arr.end(),*vlit))
					//prod.loc_lst.location_arr.push_back(*vlit);
				bool flg=false;
				for(vector<Location>::iterator lit=prod.loc_lst.location_arr.begin();lit!=prod.loc_lst.location_arr.end();lit++)
				{
					if(lit->name==vlit->name)
					{
						flg=true;
						break;
					}
				}
				if(flg==false)
					prod.loc_lst.location_arr.push_back(*vlit);
			}

			//generate all these edges into set of edges of prod automata
			//generate_and_push_all_edges_for_syn_seq(vl,vll,prod);
			vector<Edge> el=generate_all_edges_for_syn_seq(vl,*veit,*it,prod);

			//cout<<"edges:"<<el.size()<<endl;
			//push these edges into set of edges of prod automata
			for(vector<Edge>::iterator elit=el.begin();elit!=el.end();elit++)
			{

				bool flg=false;
				for(vector<Edge>::iterator eit=prod.edge_lst.edge_arr.begin();eit!=prod.edge_lst.edge_arr.end();eit++)
				{
					NNC_Polyhedron p_guards;
					p_guards.add_space_dimensions_and_embed(eit->guards.space_dimension());
					p_guards.add_constraints(eit->guards);

					NNC_Polyhedron q_guards;
					q_guards.add_space_dimensions_and_embed(elit->guards.space_dimension());
					q_guards.add_constraints(elit->guards);

					NNC_Polyhedron p_updates;
					p_updates.add_space_dimensions_and_embed(eit->updates.space_dimension());
					p_updates.add_constraints(eit->updates);


					NNC_Polyhedron q_updates;
					q_updates.add_space_dimensions_and_embed(elit->updates.space_dimension());
					q_updates.add_constraints(elit->updates);


					//if(eit->pre==elit->pre && eit->post==elit->post && eit->guards==elit->guards && eit->syn_lab==elit->syn_lab && eit->updates==elit->updates && eit->aut_nm==elit->aut_nm)
					if(eit->pre==elit->pre && eit->post==elit->post && p_guards==q_guards && eit->syn_lab==elit->syn_lab && p_updates==q_updates && eit->aut_nm==elit->aut_nm)
					{
						flg=true;
						break;
					}
				}
				if(flg==false)
				{	prod.edge_lst.edge_arr.push_back(*elit);
					//cout<<"T3 pushed "<<elit->pre<<" "<<elit->post<<" "<<elit->guards<<" "<<elit->updates<<" "<<elit->syn_lab<<endl;
				}
			}
		//end
		}

	}


}

void calculate_States_of_ICTA(Automaton_List aut_lst,Automaton &prod,multimap<string,string> synlab_to_aut_map)
{
	vector<vector<Location> > initial_states;
	vector<Location> Riloc_queue;
	find_Initial_Locations(Riloc_queue,initial_states,aut_lst.aut_arr.begin(),aut_lst.aut_arr.end());

	for(vector<vector<Location> >::iterator it=initial_states.begin();it!=initial_states.end();it++)
	{
		Location l=convert_vector_loc_to_location(*it,aut_lst);
		l.name=l.name+",phi";
		//cout<<"Initial_Loc:"<<l.name<<" "<<l.invariants<<endl;
		prod.initial_loc_lst.location_arr.push_back(l);
	}
	//int d;
	//cin>>d;
	

	vector<vector<Location> > loc_under_process_que;
	vector<vector<Location> > loc_already_processed_que;
	//cout<<"InitialSize:"<<initial_states.size()<<endl;
	for(vector<vector<Location> >::iterator it=initial_states.begin();it!=initial_states.end();it++)
	{
		Location vl=convert_vector_loc_to_location_with_original_invariants(*it,aut_lst);
		vl.name=vl.name+",phi";

		//cout<<"Location under process:"<<vl.name<<" "<<vl.invariants<<"   "<<vl.rate<<endl;
		prod.loc_lst.location_arr.push_back(vl);
		loc_under_process_que.push_back(*it);
	}

	//int d;
	//cin>>d;


	while(!loc_under_process_que.empty())
	{
		/*for(vector<vector<Location> >::iterator it=loc_under_process_que.begin();it!=loc_under_process_que.end();it++)
		{
			cout<<"Location under process:";
			for(vector<Location>::iterator itt=it->begin();itt!=it->end();itt++)
			{
				cout<<itt->name<<" "<<itt->invariants<<" "<<itt->rate;
			}
			cout<<endl;
		}*/


		//cout<<"Sizeoflocunderproc:"<<loc_under_process_que.size()<<endl;
		vector<Location> vl;
		vl=loc_under_process_que.front();
		//cout<<"Before erasing:"<<loc_under_process_que.size()<<endl;
		loc_under_process_que.erase(loc_under_process_que.begin());

		//cout<<"After erasing:"<<loc_under_process_que.size()<<endl;

		loc_already_processed_que.push_back(vl);

		Edge_List elist;
		for(vector<Location>::iterator lit=vl.begin();lit!=vl.end();lit++)
		{
			//cout<<"Here"<<endl;

			Automaton aut;
			for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
			{
				if((*aut_it).loc_to_Location.find((*lit).name)!=(*aut_it).loc_to_Location.end())
				{
					aut=(*aut_it);
					break;
				}
			}
			pair<multimap<string,LocEdge>::iterator,multimap<string,LocEdge>::iterator> mm_to_mm;
			mm_to_mm=aut.pre_to_edge_plus_post.equal_range((*lit).name);
			for(multimap<string,LocEdge>::iterator mer=mm_to_mm.first;mer!=mm_to_mm.second;mer++)
			{
				//Edge e;
				//e=(*mer).second.e;
				(*mer).second.e.aut_nm=aut.name;
				elist.edge_arr.push_back((*mer).second.e);
				//cout<<"T2 pushing "<<(*mer).second.e.pre<<" "<<(*mer).second.e.post<<" "<<(*mer).second.e.guards<<" "<<(*mer).second.e.updates<<" "<<(*mer).second.e.syn_lab<<endl;
				//cout<<"Too pushing "<<(*mer).second.e.post<<(*mer).second.e.pre<<endl;

			}
		}

		//cout<<"Elistsize:"<<elist.edge_arr.size()<<endl;
		//vector<vector<Edge> > velist;
		//velist=elist.aggregate_on_sync_lab();

		vector<string> fireableSynLab=find_fireable_Syn_Lab(elist,synlab_to_aut_map);

		//cout<<"sizeoffireable:"<<fireableSynLab.size()<<endl;
		vector<vector<string> > fireableSynLabPowerSet=find_Power_Set(fireableSynLab);
		//cout<<"PowerSetSize:"<<fireableSynLabPowerSet.size()<<endl;
		for(vector<vector<string> >::iterator vvsynit=fireableSynLabPowerSet.begin();vvsynit!=fireableSynLabPowerSet.end();vvsynit++)
		{
			if(is_Automaton_Requirement_disjoint(*vvsynit,synlab_to_aut_map))
			{
				//form set of edges and locations from them
				//add these edges and locations into prod automaton
				//cout<<"Disjoint:"<<endl;

				generate_Locations_And_Edges_of_ICTA_From(loc_under_process_que,loc_already_processed_que,elist,vl,*vvsynit,aut_lst,prod);
				//vector<Location> ltmp=generate_Locations_And_Edges_of_ICTA_From(elist,vl,*vvsynit,aut_lst);

				//add final locations to the set of current locations
				//bool ans1=is_in_vector_vector_location(ltmp,loc_already_processed_que);
				//bool ans2=is_in_vector_vector_location(ltmp,loc_under_process_que);
				//if((!ans1) && (!ans2))
				//{
				//	loc_under_process_que.push_back(ltmp);
				//}

				//cout<<"pppp"<<endl;



			}
			else
			{
				//discard this edge set
			}
		}

		//find set of actions(syn labels) that can be actually taken
		//find power set of above set
		//for each entry in power set
			//check if automaton requirement of each component is mutually disjoint
			//if yes
				//form set of edges and locations from them
				//add these edges and locations into prod automaton
				//add final locations to the set of current locations
			//else
				//do nothing

	}
}

Automaton to_ICTA2(Automaton_List aut_lst)
{
	multimap<string,string> synlab_to_aut_map;
	Automaton prod;

	int var_no=0;
	string aut_nm;
	aut_nm="";

	set<string> cntr;
	for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
	{
		if(aut_it!=aut_lst.aut_arr.begin())
		{
			aut_nm=aut_nm+"~";
		}
		aut_nm=aut_nm+aut_it->name;

		for(vector<string>::iterator cntr_it=aut_it->cntr_var_lst.cntr_var_arr.begin();cntr_it!=aut_it->cntr_var_lst.cntr_var_arr.end();cntr_it++)
		{
			int prevsize=cntr.size();
			cntr.insert(*cntr_it);
			int newsize=cntr.size();
			if(prevsize!=newsize)
			{
				prod.cntr_var_lst.cntr_var_arr.push_back(*cntr_it);
				prod.cntr_var_lst.cntr_vars.push_back(Variable(var_no));
				var_no++;
			}
		}
		for(vector<Parameter>::iterator par_it=aut_it->parameter_lst.par_list_arr.begin();par_it!=aut_it->parameter_lst.par_list_arr.end();par_it++)
		{
			if(prod.parameter_lst.par_list_arr.end()==find(prod.parameter_lst.par_list_arr.begin(),prod.parameter_lst.par_list_arr.end(),*par_it))
			{
				prod.parameter_lst.par_list_arr.push_back(*par_it);
			}
		}
		for(vector<Synchronizing_Label>::iterator syn_it=aut_it->syn_lab_lst.syn_lab_arr.begin();syn_it!=aut_it->syn_lab_lst.syn_lab_arr.end();syn_it++)
		{
			synlab_to_aut_map.insert(pair<string,string>(syn_it->name,aut_it->name));

			if(prod.syn_lab_lst.syn_lab_arr.end()==find(prod.syn_lab_lst.syn_lab_arr.begin(),prod.syn_lab_lst.syn_lab_arr.end(),*syn_it))
			{
				prod.syn_lab_lst.syn_lab_arr.push_back(*syn_it);
			}
		}


	}
	prod.assign_Name(aut_nm);
	//cout<<"Automaton name:"<<prod.name<<endl;

	calculate_States_of_ICTA(aut_lst,prod,synlab_to_aut_map);
	//cout<<"Automaton name2:"<<prod.name<<endl;
	return prod;
}


Automaton to_ICTA(Automaton_List aut_lst)
{
	multimap<string,string> synlab_to_aut_map;
	Automaton prod;

	int var_no=0;
	string aut_nm;
	aut_nm="";
	for(vector<Automaton>::iterator aut_it=aut_lst.aut_arr.begin();aut_it!=aut_lst.aut_arr.end();aut_it++)
	{
		if(aut_it!=aut_lst.aut_arr.begin())
		{
			aut_nm=aut_nm+"~";
		}
		aut_nm=aut_nm+aut_it->name;
		for(vector<string>::iterator cntr_it=aut_it->cntr_var_lst.cntr_var_arr.begin();cntr_it!=aut_it->cntr_var_lst.cntr_var_arr.end();cntr_it++)
		{

			prod.cntr_var_lst.cntr_var_arr.push_back(*cntr_it);
			prod.cntr_var_lst.cntr_vars.push_back(Variable(var_no));
			var_no++;
		}
		for(vector<Parameter>::iterator par_it=aut_it->parameter_lst.par_list_arr.begin();par_it!=aut_it->parameter_lst.par_list_arr.end();par_it++)
		{
			if(prod.parameter_lst.par_list_arr.end()==find(prod.parameter_lst.par_list_arr.begin(),prod.parameter_lst.par_list_arr.end(),*par_it))
			{
				prod.parameter_lst.par_list_arr.push_back(*par_it);
			}
		}
		for(vector<Synchronizing_Label>::iterator syn_it=aut_it->syn_lab_lst.syn_lab_arr.begin();syn_it!=aut_it->syn_lab_lst.syn_lab_arr.end();syn_it++)
		{
			synlab_to_aut_map.insert(pair<string,string>(syn_it->name,aut_it->name));

			if(prod.syn_lab_lst.syn_lab_arr.end()==find(prod.syn_lab_lst.syn_lab_arr.begin(),prod.syn_lab_lst.syn_lab_arr.end(),*syn_it))
			{
				prod.syn_lab_lst.syn_lab_arr.push_back(*syn_it);
			}
		}


	}
	prod.assign_Name(aut_nm);
	//cout<<"Automaton name:"<<prod.name<<endl;

	calculate_States_of_ICTA(aut_lst,prod,synlab_to_aut_map);

	return prod;
}

