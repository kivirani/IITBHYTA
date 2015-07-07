
bool is_Reachable_by_bfs_fb(vector<vector<State> > R_f,vector<vector<State> > R_i,Automaton a)
{
	for(vector<State>::iterator it=R_i.begin()->begin();it!=R_i.begin()->end();it++)
	{
		/*if(it->l.name==R_f.begin()->begin()->l.name)
		{
			cout<<"My god"<<endl;
			return true;
		}*/
		{
			string post=it->l.name;
				
			std::string prefix=R_f.begin()->begin()->l.name;
			
			if (prefix.length() > post.length()) {
				//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
				//return 2;
			}
			else
			{
				if (std::equal(prefix.begin(), prefix.end(), post.begin())) {
					//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << post<< '"' << std::endl;

					return true;
				} else {
					//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< post << '"' << std::endl;
					//return 1;
				}
			}				

		}
		map<string,bool> is_visited;

		queue<string> q;
		q.push(it->l.name);
		
		is_visited[it->l.name]=true;
		while(!q.empty())
		{
			string curr=q.front();
			q.pop();
			pair <std::multimap<string,LocEdge>::iterator, std::multimap<string,LocEdge>::iterator> r;
    			r = a.pre_to_edge_plus_post.equal_range(curr);
 
    			for (std::multimap<string,LocEdge>::iterator itt=r.first; itt!=r.second; ++itt)      				
			//for every post of curr 
			{
				string post=itt->second.loc;
				
				std::string prefix=R_f.begin()->begin()->l.name;
				
				if (prefix.length() > post.length()) {
					//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
					//return 2;
				}
				else
				{
					if (std::equal(prefix.begin(), prefix.end(), post.begin())) {
						//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << post<< '"' << std::endl;

						return true;
					} else {
						//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< post << '"' << std::endl;
						//return 1;
					}
				}				




				if(is_visited.find(post)==is_visited.end())
				{
					q.push(post);	
					is_visited[post]=true;
					
				}
				else
				{
					//discard this state
				}
				
			}
		}
	}
	return false;
}

bool is_Reachable_by_dfs_fb(vector<vector<State> > R_f,vector<vector<State> > R_i,Automaton a)
{
	for(vector<State>::iterator it=R_i.begin()->begin();it!=R_i.begin()->end();it++)
	{
		//vector<State>::iterator it=R_i.begin()->begin();
		/*if(it->l.name==R_f.begin()->begin()->l.name)
		{
			return true;
		}*/
		{
			string post=it->l.name;
				
			std::string prefix=R_f.begin()->begin()->l.name;
			
			if (prefix.length() > post.length()) {
				//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
				//return 2;
			}
			else
			{
				if (std::equal(prefix.begin(), prefix.end(), post.begin())) {
					//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << post<< '"' << std::endl;

					return true;
				} else {
					//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< post << '"' << std::endl;
					//return 1;
				}
			}				

		}

		map<string,bool> is_visited;

		stack<string> stk;
		stk.push(it->l.name);
		
		is_visited[it->l.name]=true;
		while(!stk.empty())
		{
			string curr=stk.top();
			stk.pop();
			pair <std::multimap<string,LocEdge>::iterator, std::multimap<string,LocEdge>::iterator> r;
    			r = a.pre_to_edge_plus_post.equal_range(curr);
 
    			for (std::multimap<string,LocEdge>::iterator itt=r.first; itt!=r.second; ++itt)      				
			//for every post of curr 
			{
				string post=itt->second.loc;
				
				std::string prefix=R_f.begin()->begin()->l.name;
				
				if (prefix.length() > post.length()) {
					//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
					//return 2;
				}
				else
				{
					if (std::equal(prefix.begin(), prefix.end(), post.begin())) {
						//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << post<< '"' << std::endl;

						return true;
					} else {
						//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< post << '"' << std::endl;
						//return 1;
					}
				}				




				if(is_visited.find(post)==is_visited.end())
				{
					stk.push(post);	
					is_visited[post]=true;
					
				}
				else
				{
					//discard this state
				}
				
			}
		}
	}
	return false;
}

bool is_Reachable_by_bfs_bk(vector<vector<State> > R_f,vector<vector<State> > R_i,Automaton a)
{
	for(vector<State>::iterator it=R_f.begin()->begin();it!=R_f.begin()->end();it++)
	{
		/*if(it->l.name==R_i.begin()->begin()->l.name)
		{
			return true;
		}*/
		{
			string pre=it->l.name;
				
			std::string prefix=R_i.begin()->begin()->l.name;
			
			if (prefix.length() > pre.length()) {
				//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
				//return 2;
			}
			else
			{
				if (std::equal(prefix.begin(), prefix.end(), pre.begin())) {
					//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << pre<< '"' << std::endl;

					return true;
				} else {
					//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< pre << '"' << std::endl;
					//return 1;
				}
			}				

		}
		map<string,bool> is_visited;

		queue<string> q;
		q.push(it->l.name);
		
		is_visited[it->l.name]=true;
		while(!q.empty())
		{
			string curr=q.front();
			q.pop();
			pair <std::multimap<string,LocEdge>::iterator, std::multimap<string,LocEdge>::iterator> r;
    			r = a.post_to_edge_plus_pre.equal_range(curr);
 
    			for (std::multimap<string,LocEdge>::iterator itt=r.first; itt!=r.second; ++itt)      				
			//for every pre of curr 
			{
				string pre=itt->second.loc;
				
				std::string prefix=R_i.begin()->begin()->l.name;
				
				if (prefix.length() > pre.length()) {
					//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
					//return 2;
				}
				else
				{
					if (std::equal(prefix.begin(), prefix.end(), pre.begin())) {
						//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << pre<< '"' << std::endl;

						return true;
					} else {
						//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< pre << '"' << std::endl;
						//return 1;
					}
				}				




				if(is_visited.find(pre)==is_visited.end())
				{
					q.push(pre);	
					is_visited[pre]=true;
					
				}
				else
				{
					//discard this state
				}
				
			}
		}
	}
	return false;
}

bool is_Reachable_by_dfs_bk(vector<vector<State> > R_f,vector<vector<State> > R_i,Automaton a)
{
	for(vector<State>::iterator it=R_f.begin()->begin();it!=R_f.begin()->end();it++)
	{
		/*if(it->l.name==R_i.begin()->begin()->l.name)
		{
			return true;
		}*/
		{
			string pre=it->l.name;
				
			std::string prefix=R_i.begin()->begin()->l.name;
			
			if (prefix.length() > pre.length()) {
				//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
				//return 2;
			}
			else
			{
				if (std::equal(prefix.begin(), prefix.end(), pre.begin())) {
					//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << pre<< '"' << std::endl;

					return true;
				} else {
					//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< pre << '"' << std::endl;
					//return 1;
				}
			}				

		}

		
		map<string,bool> is_visited;

		stack<string> stk;
		stk.push(it->l.name);
		
		is_visited[it->l.name]=true;
		while(!stk.empty())
		{
			string curr=stk.top();
			stk.pop();
			pair <std::multimap<string,LocEdge>::iterator, std::multimap<string,LocEdge>::iterator> r;
    			r = a.post_to_edge_plus_pre.equal_range(curr);
 
    			for (std::multimap<string,LocEdge>::iterator itt=r.first; itt!=r.second; ++itt)      				
			//for every pre of curr 
			{
				string pre=itt->second.loc;
				
				std::string prefix=R_i.begin()->begin()->l.name;
				
				if (prefix.length() > pre.length()) {
					//std::cerr << "Usage: " << argv[0] << " prefix string" << std::endl<< "'prefix' is longer than 'string'" << std::endl;
					//return 2;
				}
				else
				{
					if (std::equal(prefix.begin(), prefix.end(), pre.begin())) {
						//std::cout << '"' << prefix << '"' << " is a prefix of " << '"' << pre<< '"' << std::endl;

						return true;
					} else {
						//std::cout << '"' << prefix << '"' << " is NOT a prefix of " << '"'<< pre << '"' << std::endl;
						//return 1;
					}
				}				




				if(is_visited.find(pre)==is_visited.end())
				{
					stk.push(pre);	
					is_visited[pre]=true;
					
				}
				else
				{
					//discard this state
				}
				
			}
		}
	}
	return false;
}
vector<vector<State> > pre(vector<vector<State> > &R_cur,Automaton_List &a_lst)
{


	vector<vector<State> > rt;



	for(vector<vector<State> >::iterator itr=R_cur.begin();itr!=R_cur.end();itr++)
	{

		vector<State> ret;
		for(vector<State>::iterator it=(*itr).begin();it!=(*itr).end();it++)
		{
			for(vector<Automaton>::iterator itt=a_lst.aut_arr.begin();itt!=a_lst.aut_arr.end();itt++)
			{

				pair<multimap<string,LocEdge>::iterator,multimap<string,LocEdge>::iterator> mm_to_mm;
				mm_to_mm=(*itt).post_to_edge_plus_pre.equal_range((*it).l.name);


				for(multimap<string,LocEdge>::iterator mer=mm_to_mm.first;mer!=mm_to_mm.second;mer++)
				{

					Edge *ittt;
					ittt=&(*mer).second.e;

					//cout<<"Found "<<(*it).l.name<<" with guards "<<(*ittt).guards<<endl;


					State tmpstate;
					Location tmploc;
					NNC_Polyhedron tmp_poly;
					tmp_poly.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
					tmp_poly=(*it).poly;
					//add_trivial_constraints_to_poly(tmp_poly);
					cout<<"tmppoly:"<<tmp_poly<<endl;


					tmploc=(*itt).loc_to_Location[(*it).l.name];
					//cout<<tmploc.name<<" found"<<endl;



					NNC_Polyhedron invar;
					invar.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
					invar=invar^tmploc.invariants;
					//invar.add_constraints(tmploc.invariants);

					//add_trivial_constraints_to_poly(invar);
					//cout<<"Invariant:"<<invar<<endl;


					//add_trivial_constraints_to_poly((*it).poly);


					(*it).poly=(*it).poly^invar;
					//if(invar.contains((*it).poly))
					//{


						//take time elapse by negative rate
						NNC_Polyhedron rate_poly;
						rate_poly.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());


						//cout<<"Rate:"<<tmploc.rate<<endl;
						//rate_poly.add_constraints(invert_Coefficients(tmploc.rate));
						rate_poly=rate_poly^invert_Coefficients(tmploc.rate);
						//cout<<"Rate poly:"<<rate_poly<<endl;



						tmp_poly=(*it).poly;
						//cout<<"tmp_poly:"<<(*it).poly<<endl;
						//cout<<"Rate poly:"<<rate_poly<<endl;
						tmp_poly.time_elapse_assign(rate_poly);
						cout<<"After 0st time elapse:"<<tmp_poly<<endl;
						//cout<<"After post location time elapse:"<<tmp_poly<<endl;

						///add_trivial_constraints_to_poly(tmp_poly);

						cout<<"After post location time elapse:"<<tmp_poly<<endl;





						//take anding of this with invariant of this location
						tmp_poly.intersection_assign(invar);
						///add_trivial_constraints_to_poly(tmp_poly);
						cout<<"After intersecting with invariants of post location:"<<tmp_poly<<endl;

						//replace updation vector of the edge in the representation of polyhedron


						if(tmp_poly.is_empty())
						{
								cout<<"Got empty polytope after updates are performed:"<<endl;
								//action has to be taken

						}




						//transform tmp_poly's constraint_system with updates i.e. replace for every occurence of left with right
						NNC_Polyhedron ttpoly;
						ttpoly.add_space_dimensions_and_embed(tmp_poly.space_dimension());
						ttpoly=tmp_poly;
						//ttpoly.add_constraints((*ittt).updates);
						ttpoly=ttpoly^(*ittt).updates;


						if(!ttpoly.is_empty())
						{
							cout<<"Polygon contains updates"<<endl;
						}
						else
							cout<<"Polygon does not contain updates"<<endl;

						//tmp_poly.add_constraints((*ittt).updates);

						tmp_poly=tmp_poly^(*ittt).updates;

						tmp_poly=apply_Updates(tmp_poly,(*ittt).updates);
						///add_trivial_constraints_to_poly(tmp_poly);



						cout<<"After applying updates:"<<tmp_poly<<endl;
						//cout<<"Updates:"<<(*ittt).updates<<endl;









						//cout<<"After adding updates:"<<tmp_poly<<endl;






						//take anding of this with the guards of selected edge

						cout<<"Guards:"<<(*ittt).guards<<endl;
						//tmp_poly.add_constraints((*ittt).guards);
						tmp_poly=tmp_poly^(*ittt).guards;
						///add_trivial_constraints_to_poly(tmp_poly);

						cout<<"After applying guards:"<<tmp_poly<<endl;

						//int idd;
						//scanf("%d",&idd);



						//time elapse with rate of pre location take anding of this with the invariant of the pre location

						map<string,Location>::iterator itk=(*itt).loc_to_Location.find((*ittt).pre);
						if(itk!=(*itt).loc_to_Location.end())
						{

							Location *locit;
							locit=&(*itk).second;
							//tmp_poly.add_constraints((*locit).invariants);
							tmp_poly=tmp_poly^(*locit).invariants;
							///add_trivial_constraints_to_poly(tmp_poly);
							cout<<"After checking invariants of the pre location:"<<tmp_poly<<endl;

							//evolve with the time elapse relation of pre

							NNC_Polyhedron rate_poly1;
							rate_poly1.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
							//cout<<"Rate:"<<tmploc.rate<<endl;
							//rate_poly1.add_constraints(invert_Coefficients((*locit).rate));
							rate_poly1=rate_poly1^invert_Coefficients((*locit).rate);
							//cout<<"Rate poly:"<<rate_poly<<endl;
							tmp_poly.time_elapse_assign(rate_poly1);
							///add_trivial_constraints_to_poly(tmp_poly);

							cout<<"After pre time elapse:"<<tmp_poly<<endl;



							//again take anding with invariants
							//tmp_poly.add_constraints((*locit).invariants);
							tmp_poly=tmp_poly^(*locit).invariants;
							///add_trivial_constraints_to_poly(tmp_poly);

							cout<<"After checking invariants of pre location:"<<tmp_poly<<endl;

							tmpstate.l=(*locit);


						}

						//push back this state to the returning state vector
						tmpstate.poly=tmp_poly;
						///add_trivial_constraints_to_poly(tmpstate.poly);
						//cout<<"Output:"<<tmp_poly<<endl;
						if(!tmp_poly.is_empty())
						{
							//cout<<"Here:"<<tmp_poly<<endl;
							ret.push_back(tmpstate);
						}
					//}
					//else
					//{
					//	cout<<"Invariant doesn't carry poly:"<<invar<<endl;
					//}

				}


			}

		}
		if(ret.size()>0)
			rt.push_back(ret);
	}
	cout<<"End of pre:"<<endl<<endl;
	return rt;


}



vector<vector<State> > post(vector<vector<State> > &R_cur,Automaton_List &a_lst)
{

	vector<vector<State> > rt;



	for(vector<vector<State> >::iterator itr=R_cur.begin();itr!=R_cur.end();itr++)
	{

		vector<State> ret;
		for(vector<State>::iterator it=(*itr).begin();it!=(*itr).end();it++)
		{
			for(vector<Automaton>::iterator itt=a_lst.aut_arr.begin();itt!=a_lst.aut_arr.end();itt++)
			{

				pair<multimap<string,LocEdge>::iterator,multimap<string,LocEdge>::iterator> mm_to_mm;
				mm_to_mm=(*itt).pre_to_edge_plus_post.equal_range((*it).l.name);
				for(multimap<string,LocEdge>::iterator mer=mm_to_mm.first;mer!=mm_to_mm.second;mer++)
				{
					Edge *ittt;
					ittt=&(*mer).second.e;

					//cout<<"Found "<<(*it).l.name<<" with guards "<<(*ittt).guards<<endl;

					//cout<<"post find out:"<<endl;
					State tmpstate;
					Location tmploc;
					NNC_Polyhedron tmp_poly;
					tmp_poly.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
					tmp_poly=(*it).poly;
					//add_trivial_constraints_to_poly(tmp_poly);
					cout<<"tmppoly:"<<tmp_poly<<endl;



					tmploc=(*itt).loc_to_Location[(*it).l.name];
					//cout<<tmploc.name<<" found"<<endl;


					NNC_Polyhedron invar;
					invar.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
					//invar.add_constraints(tmploc.invariants);
					invar=invar^tmploc.invariants;
					//add_trivial_constraints_to_poly(invar);
					//cout<<"Invariant:"<<invar<<endl;


					//add_trivial_constraints_to_poly((*it).poly);


					//if(invar.contains((*it).poly))
					//{
						//cout<<"Before:"<<(*it).poly<<endl;

						tmp_poly=(*it).poly;
						tmp_poly.intersection_assign(invar);
						add_trivial_constraints_to_poly(tmp_poly);
						//cout<<"After:"<<tmp_poly<<endl;


						//take time elapse by negative rate
						NNC_Polyhedron rate_poly;
						rate_poly.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());


						//rate_poly.add_constraints(tmploc.rate);
						rate_poly=rate_poly^tmploc.rate;
						//cout<<"Rate poly:"<<rate_poly<<endl;




						//cout<<"tmp_poly:"<<(*it).poly<<endl;
						//cout<<"Rate poly:"<<rate_poly<<endl;
						tmp_poly.time_elapse_assign(rate_poly);
						cout<<"Applying time elapse by rate:"<<rate_poly<<endl;
						cout<<"After 0st time elapse:"<<tmp_poly<<endl;
						//cout<<"After first location time elapse:"<<tmp_poly<<endl;

						///add_trivial_constraints_to_poly(tmp_poly);

						cout<<"After pre location time elapse:"<<tmp_poly<<endl;





						//take anding of this with invariant of this location
						tmp_poly.intersection_assign(invar);
						///add_trivial_constraints_to_poly(tmp_poly);
						cout<<"After intersecting with invariants of pre location:"<<tmp_poly<<endl;

						//replace updation vector of the edge in the representation of polyhedron
						/*for(Constraint_System_const_iterator csit=(*ittt).updates.begin();csit!=(*ittt).updates.end();csit++)
						{
							tmp_poly.add_constraint(*csit);
						}*/

						//cout<<"Updates of transition:"<<(*ittt).updates<<endl;


						if(tmp_poly.is_empty())
						{
								cout<<"Got empty polytope after updates are performed:"<<endl;
								//action has to be taken

						}










						/*tmp_poly.add_constraints((*ittt).updates);
						add_trivial_constraints_to_poly(tmp_poly);*/
						//cout<<"After adding updates:"<<tmp_poly<<endl;






						//take anding of this with the guards of selected edge


						//cout<<"Guards:"<<(*ittt).guards<<endl;
						//tmp_poly.add_constraints((*ittt).guards);
						tmp_poly=tmp_poly^(*ittt).guards;

						///add_trivial_constraints_to_poly(tmp_poly);
						cout<<"After applying guards:"<<tmp_poly<<endl;

						//int idd;
						//scanf("%d",&idd);


						//transform tmp_poly's constraint_system with updates i.e. replace for every occurence of left with right

						tmp_poly=apply_Updates(tmp_poly,(*ittt).updates);

						//tmp_poly.add_constraints((*ittt).updates);
						tmp_poly=tmp_poly^(*ittt).updates;

						///add_trivial_constraints_to_poly(tmp_poly);
						cout<<"After applying updates:"<<tmp_poly<<endl;
						//cout<<"Updates:"<<(*ittt).updates<<endl;


						//time elapse with rate of pre location take anding of this with the invariant of the pre location

						map<string,Location>::iterator itk=(*itt).loc_to_Location.find((*ittt).post);
						if(itk!=(*itt).loc_to_Location.end())
						{

							Location *locit;
							locit=&(*itk).second;
							/*for(Constraint_System_const_iterator cssit=(*locit).invariants.begin();cssit!=(*locit).invariants.end();cssit++)
							{
								tmp_poly.add_constraint(*cssit);
							}*/
							//tmp_poly.add_constraints((*locit).invariants);
							tmp_poly=tmp_poly^(*locit).invariants;
							///add_trivial_constraints_to_poly(tmp_poly);
							cout<<"After checking invariants of the post location:"<<tmp_poly<<endl;

							//evolve with the time elapse relation of pre

							NNC_Polyhedron rate_poly1;
							rate_poly1.add_space_dimensions_and_embed(a_lst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());
							//cout<<"Rate:"<<tmploc.rate<<endl;
							//rate_poly1.add_constraints((*locit).rate);
							rate_poly1=rate_poly1^(*locit).rate;

							//cout<<"Rate poly:"<<rate_poly<<endl;
							tmp_poly.time_elapse_assign(rate_poly1);
							///add_trivial_constraints_to_poly(tmp_poly);

							cout<<"After post time elapse:"<<tmp_poly<<endl;



							//again take anding with invariants
							//tmp_poly.add_constraints((*locit).invariants);
							tmp_poly=tmp_poly^(*locit).invariants;
							///add_trivial_constraints_to_poly(tmp_poly);

							cout<<"After checking invariants of post location:"<<tmp_poly<<endl;

							tmpstate.l=(*locit);


						}

						//push back this state to the returning state vector
						tmpstate.poly=tmp_poly;
						///add_trivial_constraints_to_poly(tmpstate.poly);
						//cout<<"Output:"<<tmp_poly<<endl;
						if(!tmp_poly.is_empty())
						{
							//cout<<"Here:"<<tmp_poly<<endl;
							ret.push_back(tmpstate);
						}
					//}
					//else
					//{
					//	cout<<"Invariant doesn't carry poly:"<<endl;
					//}
				}

			}

		}
		if(ret.size()>0)
			rt.push_back(ret);
	}
	return rt;

}

vector<NNC_Polyhedron> reduceVectorNNCPoly(vector<NNC_Polyhedron> in)
{
	vector<NNC_Polyhedron> newer;
	vector<NNC_Polyhedron> tmp2;
	newer=in;
	while(newer.size()!=tmp2.size())
	{
		tmp2=newer;
		
		//tmp1=reduce(tmp2);
		newer.clear();

		
		for(vector<NNC_Polyhedron>::iterator it=tmp2.begin();it!=tmp2.end();it++)
		{
			
			vector<NNC_Polyhedron>::iterator itt;
			for(itt=newer.begin();itt!=newer.end();itt++)
			{
				//if(intersection of *it & *itt is not phi)
				//{
					//break
				//}
				NNC_Polyhedron tmp;	
				tmp.add_space_dimensions_and_embed(it->space_dimension());
				tmp=*it;
				tmp.intersection_assign(*itt);
				if(!tmp.is_empty())
				{
					break;
				}
			}
			
			if(itt!=newer.end())
			{	
				vector<NNC_Polyhedron> tmp3;
				for(vector<NNC_Polyhedron>::iterator newit=newer.begin();newit!=newer.end();newit++)
				{
					if(newit==itt)
					{	
						//it union itt
						NNC_Polyhedron tmp;
						tmp.add_space_dimensions_and_embed(it->space_dimension());
						//tmp3.push_back(it union itt);
						tmp=*it;
						tmp.poly_hull_assign(*itt);

						tmp3.push_back(tmp);
					}
					else
					{
						tmp3.push_back(*it);
					}
				}	
				newer=tmp3;								
			}
			else
			{
				newer.push_back(*it);
				//keep newer as it is
			}
		}
		
	}
	/*cout<<"Returning:"<<endl;
	for(vector<NNC_Polyhedron>::iterator iit=newer.begin();iit!=newer.end();iit++)
	{
		cout<<(*iit)<<endl;
	}*/
	return newer;
}

map<string,vector<NNC_Polyhedron> > groupByStateNameAndPolyhedron(vector<State> vs)
{
	map<string,vector<NNC_Polyhedron> > tmp;
	for(vector<State>::iterator it=vs.begin();it!=vs.end();it++)
	{
		map<string,vector<NNC_Polyhedron> >::iterator itt=tmp.find(it->l.name);
		if(itt!=tmp.end())
		{
			vector<NNC_Polyhedron> vpoly=itt->second;
			vpoly.push_back(it->poly);
			tmp[it->l.name]=vpoly;
		}
		else
		{
			vector<NNC_Polyhedron> vpoly;
			vpoly.push_back(it->poly);
			tmp[it->l.name]=vpoly;
		}
	}
	
	/*cout<<"Intermediate"<<endl;
	for (map<string,vector<NNC_Polyhedron> >::iterator it=tmp.begin(); it!=tmp.end(); ++it)
	{
    		//std::cout << it->first << " => " << it->second << '\n';
		cout<<it->first<<" ";
			
		for(vector<NNC_Polyhedron>::iterator iit=it->second.begin();iit!=it->second.end();iit++)
		{
			cout<<(*iit)<<endl;
		}
	}*/


	map<string,vector<NNC_Polyhedron> > ret;
	for(map<string,vector<NNC_Polyhedron> >::iterator it=tmp.begin();it!=tmp.end();it++)
	{
		ret[it->first]=reduceVectorNNCPoly(it->second);
	}
	return ret;
}
bool is_intersection_phi2(vector<vector<State> > R_cur,vector<vector<State> > R_i)
{
	vector<vector<State> >::iterator it,itt;
	bool thisIterationAns=false;
	if(R_cur.size()==0 || R_i.size()==0)		
		return true;
	for(it=R_i.begin(),itt=R_cur.begin();it!=R_i.end() && itt!=R_cur.end();it++,itt++)
	{

		thisIterationAns=false;		
		map<string,vector<NNC_Polyhedron> > m1=groupByStateNameAndPolyhedron(*it);
		map<string,vector<NNC_Polyhedron> > m2=groupByStateNameAndPolyhedron(*itt);
		
		/*cout<<"M1 map:"<<endl;
		for (std::map<string,vector<NNC_Polyhedron> >::iterator myit=m1.begin(); myit!=m1.end(); ++myit)
		{
			//std::cout << it->first << " => " << it->second << '\n';
			cout<<myit->first<<" ";
			
			for(vector<NNC_Polyhedron>::iterator iit=myit->second.begin();iit!=myit->second.end();iit++)
			{
				cout<<(*iit)<<endl;
			}
		}
		
		cout<<"M2 map:"<<endl;
		for (std::map<string,vector<NNC_Polyhedron> >::iterator myit=m2.begin(); myit!=m2.end(); ++myit)
		{
			//std::cout << it->first << " => " << it->second << '\n';
			cout<<myit->first<<" ";
			
			for(vector<NNC_Polyhedron>::iterator iit=myit->second.begin();iit!=myit->second.end();iit++)
			{
				cout<<(*iit)<<endl;
			}
		}*/
		for(map<string,vector<NNC_Polyhedron> >::iterator m1it=m1.begin();m1it!=m1.end();m1it++)
		{
			string loc=m1it->first;
			vector<NNC_Polyhedron> vm1poly=m1it->second;
			map<string,vector<NNC_Polyhedron> >::iterator m2it=m2.find(loc);
			if(m2it!=m2.end())
			{
				vector<NNC_Polyhedron> vm2poly=m2it->second;
				bool flg=false;
				for(vector<NNC_Polyhedron>::iterator poly1it=vm1poly.begin();poly1it!=vm1poly.end();poly1it++)
				{
					flg=false;
					for(vector<NNC_Polyhedron>::iterator poly2it=vm2poly.begin();poly2it!=vm2poly.end();poly2it++)
					{
						NNC_Polyhedron nnc;
						nnc.add_space_dimensions_and_embed(poly2it->space_dimension());
						nnc=*poly2it;
					
						nnc=nnc^(*poly1it);
						if(!nnc.is_empty())
						//if(poly2it->contains(*poly1it))
						{
							flg=true;
							break;
						}	
					}
					if(flg==true)
					{
						return false;
					}
					
				}
				if(flg==false)
				{
					thisIterationAns=true;			
				}
			}
			else
			{
				thisIterationAns=true;		
			}
		}	
				
	}
	if(thisIterationAns==true)
		return true;
	
	return false;	
}

bool is_subset_of2(vector<vector<State> > R_cur,vector<vector<State> > R_old)
{
	cout<<"R_cur size:"<<R_cur.size()<<endl;
	if(R_cur.size()==0)
		return true;
	if(R_old.size()==0 && R_cur.size()>0)
		return false;
	vector<vector<State> >::iterator it,itt;
	bool thisIterationAns=false;	
	for(it=R_cur.begin(),itt=R_old.begin();it!=R_cur.end() && itt!=R_old.end();it++,itt++)
	{

		thisIterationAns=false;		
		map<string,vector<NNC_Polyhedron> > m1=groupByStateNameAndPolyhedron(*it);
		map<string,vector<NNC_Polyhedron> > m2=groupByStateNameAndPolyhedron(*itt);

		/*cout<<"M1 map:"<<endl;
		for (std::map<string,vector<NNC_Polyhedron> >::iterator myit=m1.begin(); myit!=m1.end(); ++myit)
		{
			//std::cout << it->first << " => " << it->second << '\n';
			cout<<myit->first<<" ";
			
			for(vector<NNC_Polyhedron>::iterator iit=myit->second.begin();iit!=myit->second.end();iit++)
			{
				cout<<(*iit)<<endl;
			}
		}
		
		cout<<"M2 map:"<<endl;
		for (std::map<string,vector<NNC_Polyhedron> >::iterator myit=m2.begin(); myit!=m2.end(); ++myit)
		{
			//std::cout << it->first << " => " << it->second << '\n';
			cout<<myit->first<<" ";
			
			for(vector<NNC_Polyhedron>::iterator iit=myit->second.begin();iit!=myit->second.end();iit++)
			{
				cout<<(*iit)<<endl;
			}
		}*/

		for(map<string,vector<NNC_Polyhedron> >::iterator m1it=m1.begin();m1it!=m1.end();m1it++)
		{
			string loc=m1it->first;
			vector<NNC_Polyhedron> vm1poly=m1it->second;
			map<string,vector<NNC_Polyhedron> >::iterator m2it=m2.find(loc);
			if(m2it!=m2.end())
			{
				vector<NNC_Polyhedron> vm2poly=m2it->second;
				bool flg=false;
				for(vector<NNC_Polyhedron>::iterator poly1it=vm1poly.begin();poly1it!=vm1poly.end();poly1it++)
				{
					flg=false;
					for(vector<NNC_Polyhedron>::iterator poly2it=vm2poly.begin();poly2it!=vm2poly.end();poly2it++)
					{
						if(poly2it->contains(*poly1it))
						{
							flg=true;
							break;
						}	
					}
					if(flg==false)
					{
						return false;
					}
				}
				if(flg==true)
				{
					thisIterationAns=true;			
				}
			}
			else
			{
				return false;		
			}
		}	
				
	}
	if(thisIterationAns==true)
		return true;
	return false;
}
vector<vector<State> > time_elapse_on_vector_state(vector<vector<State> > R_i,Automaton_List a_lst)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_i.begin();it!=R_i.end();it++)
	{
		vector<State> vstmp;
		for(vector<State>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			State s;
			for(vector<Automaton>::iterator ait=a_lst.aut_arr.begin();ait!=a_lst.aut_arr.end();ait++)
			{
				if(ait->loc_to_rate.end()!=ait->loc_to_rate.find(itt->l.name))
				{
					
					s.l=itt->l;
					s.poly.add_space_dimensions_and_embed(ait->cntr_var_lst.cntr_var_arr.size());
					s.poly=itt->poly^ait->loc_to_invar[itt->l.name];
					cout<<"After applying invar:"<<s.poly<<endl;
					NNC_Polyhedron ratepoly;
					ratepoly.add_space_dimensions_and_embed(ait->cntr_var_lst.cntr_var_arr.size());
					ratepoly.add_constraints(ait->loc_to_rate[itt->l.name]);
					s.poly.time_elapse_assign(ratepoly);	
					cout<<"IAfter elapsing time:"<<s.poly<<endl;
					s.poly=s.poly^ait->loc_to_invar[itt->l.name];
					cout<<"IAfter applying invar again:"<<s.poly<<endl;
					break;
				}
			}
			vstmp.push_back(s);			
		}
		ret.push_back(vstmp);
	}
	return ret;
}

vector<vector<State> > inverted_time_elapse_on_vector_state(vector<vector<State> > R_i,Automaton_List a_lst)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_i.begin();it!=R_i.end();it++)
	{
		vector<State> vstmp;
		for(vector<State>::iterator itt=it->begin();itt!=it->end();itt++)
		{
			State s;
			for(vector<Automaton>::iterator ait=a_lst.aut_arr.begin();ait!=a_lst.aut_arr.end();ait++)
			{
				if(ait->loc_to_rate.end()!=ait->loc_to_rate.find(itt->l.name))
				{
					
					s.l=itt->l;
					s.poly.add_space_dimensions_and_embed(ait->cntr_var_lst.cntr_var_arr.size());
					s.poly=itt->poly;
					//cout<<"Original applying invar:"<<s.poly<<endl;
					

					/*NNC_Polyhedron invarpoly;
					invarpoly.add_space_dimensions_and_embed(ait->cntr_var_lst.cntr_var_arr.size());
					invarpoly.add_constraints(ait->loc_to_invar[itt->l.name]);
					cout<<"invar:"<<invarpoly<<endl;*/

					s.poly=s.poly^ait->loc_to_invar[itt->l.name];
					//cout<<"IFirst applying invar:"<<s.poly<<endl;
					NNC_Polyhedron ratepoly;
					ratepoly.add_space_dimensions_and_embed(ait->cntr_var_lst.cntr_var_arr.size());
					ratepoly.add_constraints(invert_Coefficients(ait->loc_to_rate[itt->l.name]));
					//cout<<"Inverted rate poly:"<<ratepoly<<endl;
					s.poly.time_elapse_assign(ratepoly);
					//cout<<"Inverted time elapse:"<<s.poly<<endl;
					s.poly=s.poly^ait->loc_to_invar[itt->l.name];
					//ratepoly=ratepoly^ait->loc_to_invariants[itt->l.name];
					//ratepoly.add_constraints(ait->loc_to_rate[itt->l.name]);


					//s.poly.time_elapse_assign(ratepoly);	
					
					break;
				}
			}
			vstmp.push_back(s);			
		}
		ret.push_back(vstmp);
	}
	return ret;
}

bool is_Reachable_by_backward_fixpoint_computation(vector<vector<State> > R_f,vector<vector<State> > R_i,int max_iterations,Automaton_List &a_lst)
{
	vector<vector<State> > R_old,R_cur,R;
	//R_cur=R_f;
	R_cur=inverted_time_elapse_on_vector_state(R_f,a_lst);


	int it=0;
	cout<<"R_i:"<<endl;
	printR(R_i,-1);
	cout<<"R_cur:"<<endl;
	printR(R_cur,-1);
	cout<<"R_f:"<<endl;
	printR(R_f,-1);
	//cout<<"In isreachable:"<<endl;
	cout<<"Is inter phi -1:"<<is_intersection_phi2(R_cur,R_i)<<endl;
	cout<<"Is subset of -1:"<<is_subset_of2(R_cur,R_old)<<endl;
	//cout<<"In isreachable:"<<endl;
	//cout<<"Is inter phi:"<<is_intersection_phi(R_cur,R_i)<<endl;
	//cout<<"Is subset of:"<<is_subset_of(R_cur,R_old)<<endl;
	while(is_intersection_phi2(R_cur,R_i)==true && is_subset_of2(R_cur,R_old)!=true && it<max_iterations)
	{

		
		R=pre(R_cur,a_lst);
		



		//cout<<"New R:"<<endl;	
		//printR(R,it+1);
		//cout<<"Pre calculated:"<<endl;
		//R_old=take_union(R_old,R_cur);
		R_old=R_old+R_cur;
		R_cur=R;
		it++;

		cout<<"R_cur:"<<endl;
		printR(R_cur,it);
		cout<<"R:"<<endl;
		printR(R,it);
		cout<<"R_old:"<<endl;
		printR(R_old,it);
		cout<<"Is inter phi:"<<is_intersection_phi2(R_cur,R_i)<<endl;
		cout<<"Is subset of:"<<is_subset_of2(R_cur,R_old)<<endl;

		//cout<<"Size:"<<R_old.size()<<endl;
	}
	cout<<"Is inter phi:"<<is_intersection_phi2(R_cur,R_i)<<endl;
	cout<<"Is subset of:"<<is_subset_of2(R_cur,R_old)<<endl;

	cout<<"It:"<<it<<endl;
	if(it==max_iterations)
		cout<<"Max limit reached:"<<endl;
	//printR(R_cur,0);
	//printR(R_old,0);

	//cout<<is_subset_of(R_cur,R_old)<<endl;

	return !(is_intersection_phi2(R_cur,R_i));
}

bool is_Reachable_by_forward_fixpoint_computation(vector<vector<State> > R_f,vector<vector<State> > R_i,int max_iterations,Automaton_List &a_lst)
{
	vector<vector<State> > R_old,R_cur,R;	

	//R_cur=R_i;
	R_cur=time_elapse_on_vector_state(R_i,a_lst);
	
	
	
	int it=0;
	cout<<"R_i:"<<endl;
	printR(R_i,-1);
	cout<<"R_cur:"<<endl;
	printR(R_cur,-1);
	cout<<"R_f:"<<endl;
	printR(R_f,-1);
	//cout<<"In isreachable:"<<endl;
	cout<<"Is inter phi:"<<is_intersection_phi2(R_cur,R_f)<<endl;
	cout<<"Is subset of:"<<is_subset_of2(R_cur,R_old)<<endl;
	while(is_intersection_phi2(R_cur,R_f)==true && is_subset_of2(R_cur,R_old)!=true && it<max_iterations)
	{
		
		R=post(R_cur,a_lst);
		//cout<<"R_i:"<<endl;
		//printR(R_i,it+1);
		
		//R_old=take_union(R_old,R_cur);
		R_old=R_old+R_cur;
		R_cur=R;
		it++;

		cout<<"R_cur:"<<endl;
		printR(R_cur,it);
		cout<<"R:"<<endl;
		printR(R,it);
		cout<<"R_old:"<<endl;
		printR(R_old,it);
		cout<<"Is inter phi:"<<is_intersection_phi2(R_cur,R_f)<<endl;
		cout<<"Is subset of:"<<is_subset_of2(R_cur,R_old)<<endl;
		//cout<<"Size:"<<R_old.size()<<endl;
	}
	cout<<"Is inter phi:"<<is_intersection_phi2(R_cur,R_f)<<endl;
	//cout<<"Is subset of:"<<is_subset_of2(R_cur,R_old)<<endl;
	cout<<"It:"<<it<<endl;
	if(it==max_iterations)
		cout<<"Max limit reached:"<<endl;
	return !(is_intersection_phi2(R_cur,R_f));
}


/*bool is_Reachable_by_backward_fixpoint_computation(vector<vector<State> > R_f,vector<vector<State> > R_i,int max_iterations,Automaton_List &a_lst)
{
	vector<vector<State> > R_old,R_cur,R;
	R_cur=R_f;
	int it=0;
	//cout<<"In isreachable:"<<endl;
	//cout<<"Is inter phi:"<<is_intersection_phi(R_cur,R_i)<<endl;
	//cout<<"Is subset of:"<<is_subset_of(R_cur,R_old)<<endl;
	while(is_intersection_phi(R_cur,R_i)==true && is_subset_of(R_cur,R_old)!=true && it<max_iterations)
	{
		R=pre(R_cur,a_lst);

		printR(R,it+1);
		//cout<<"Pre calculated:"<<endl;
		//R_old=take_union(R_old,R_cur);
		R_old=R_old+R_cur;
		R_cur=R;
		it++;
		//cout<<"Size:"<<R_old.size()<<endl;
	}
	cout<<"It:"<<it<<endl;
	if(it==max_iterations)
		cout<<"Max limit reached:"<<endl;
	//printR(R_cur,0);
	//printR(R_old,0);
	cout<<is_subset_of(R_cur,R_old)<<endl;

	return !(is_intersection_phi(R_cur,R_i));
}


bool is_Reachable_by_forward_fixpoint_computation(vector<vector<State> > R_f,vector<vector<State> > R_i,int max_iterations,Automaton_List &a_lst)
{
	vector<vector<State> > R_old,R_cur,R;
	R_cur=R_i;
	int it=0;
	//cout<<"In isreachable:"<<endl;
	//cout<<"Is inter phi:"<<is_intersection_phi(R_cur,R_i)<<endl;
	//cout<<"Is subset of:"<<is_subset_of(R_cur,R_old)<<endl;
	while(is_intersection_phi(R_cur,R_f)==true && is_subset_of(R_cur,R_old)!=true && it<max_iterations)
	{
		R=post(R_cur,a_lst);

		printR(R,it+1);

		//R_old=take_union(R_old,R_cur);
		R_old=R_old+R_cur;
		R_cur=R;
		it++;
		//cout<<"Size:"<<R_old.size()<<endl;
	}
	cout<<"It:"<<it<<endl;
	if(it==max_iterations)
		cout<<"Max limit reached:"<<endl;
	return !(is_intersection_phi(R_cur,R_f));
}
*/
