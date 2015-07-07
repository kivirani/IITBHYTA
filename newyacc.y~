%{
#include <cstdio>
#include <iostream>
#include <cstring>
#include "parsing_Automaton_List.h"


using namespace std;
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int yynerrs; 

Parser_Automaton_List paut_lst;
AutomatonStr *a;
LocationStr lstr;
EdgeStr e;

//Automaton_List aut_lst;

enum TYPE{NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL};
map<string,TYPE> varmap; 

map<string,AutomatonStr*> autstrmap;
map<string,Automaton*> autmap;

map<string,vector<AutomatonStr> > vautstrmap;

map<string,AutomatonStr*> hybridautstrmap;
map<string,Automaton*> hybridautmap;

//map<string,vector<string> > autToVCntrVar;
//map<string,vector<string> > autToVInVar;


map<string,vector<AutomatonStr> > vhybridautstrmap;


map<string,AutomatonStr*> timedautstrmap;
map<string,Automaton*> timedautmap;
//map<string,vector<string> > timedautToVCntrVar;
//map<string,vector<string> > timedautToVInVar;

map<string,vector<AutomatonStr> > vtimedautstrmap;



//map<string,AutomatonStr*> autstrmap;
//map<string,Automaton*> autmap;

//map<string,vector<string> > regionautToVCntrVar;
//map<string,vector<string> > regionautToVInVar;


map<string,Automaton*> ictahybridmap;
map<string,Automaton*> ictamap;

//map<string,vector<string> > icTAToVCntrVar;
//map<string,vector<string> > icTAToVInVar;


map<string,vector<string> > valsetstrmap;

map<string,string> statestrmap;

map<string,pair<string,vector<string> > > symstatestrmap;

map<string,bool> boolmap;


int maxiterations=12;
%}
%union{
 char * mystring;
 vector<string> *strv;
 string *str;
};

%token MERGE_SPLITTED
%token ASAP
%token PRIORITY
%token par_USE_HIOA_AUTOMATA
%token par_CREATION_GRAPH_OUTPUT
%token par_TIME_POST_LAMBDA
%token par_TIME_POST_CONE_ITER
%token par_TIME_POST_ITER
%token par_ELAPSE_TIME
%token par_BOUND_BOX_BITSIZE
%token par_CONSTRAINT_BITSIZE
%token par_REACH_STOP_USE_BITSIZE
%token par_MEMORY_MODE
// Reachability
%token par_CHEAP_CONTAIN_RETURN_OTHERS
%token par_USE_CONVEX_HULL
%token par_USE_CONSTRAINT_HULL
%token par_REACH_STOP_AT_FORB
%token par_REACH_ONLY_EXPLORE
%token par_REACH_USE_BBOX
%token par_REACH_MAX_ITER
%token par_REACH_USE_BBOX_ITER
%token par_REACH_STOP_USE_CONVEX_HULL_ITER
%token par_REACH_STOP_USE_CONVEX_HULL_SETTLE
%token par_REACH_CONSTRAINT_LIMIT
%token par_LIMIT_CONSTRAINTS_METHOD
%token par_TP_CONSTRAINT_LIMIT
%token par_REACH_CONSTRAINT_TRIGGER
%token par_REACH_BITSIZE_TRIGGER
%token par_SEARCH_METHOD
%token par_SNAPSHOT_INTERVAL

// Simulation
%token par_USE_CONVEX_HULL_FOR_PRIMING
%token par_PRIME_R_WITH_REACH
%token par_SHOW_BAD_STATES
%token par_SIM_SIMPLIFY_R
%token par_PRIME_R_WITH_DISCRETE_REACH
// Minimization
%token par_MINIM_USE_CONVEX_HULL_FOR_PRIMING
%token par_MINIM_PRIME_R_WITH_REACH
// Composition
%token COMPOSE
%token par_COMPOSE_WITH_REACH_MIN
%token par_COMPOSE_USE_CONVEX_HULL_FOR_REACH
// Refinement
%token par_REFINE_DERIVATIVE_METHOD
%token par_REFINE_PRIORITIZE_REACH_SPLIT;
%token par_REFINE_SMALLEST_FIRST;
%token par_REFINE_USE_FP;
%token par_REFINE_DERIV_MINANGLE;
%token par_REFINE_PRIORITIZE_ANGLE;
%token par_REFINE_CHECK_TIME_RELEVANCE; 
%token par_REFINE_CHECK_TIME_RELEVANCE_DURING;
%token par_REFINE_CHECK_TIME_RELEVANCE_FINAL; 
%token par_REFINE_CHECK_TRANS_DIMS;
%token par_REFINE_PARTITION_INSIDE;
%token par_REACH_FB_REFINE_METHOD;
%token par_REFINE_INTERSECT_METHOD;
%token par_REFINE_LOCATION_PLANE;
%token SET_DHR_VARS;
%token par_DHR_THRESHOLD;
%token IS_REACHABLE_BY_DFS_FB
%token IS_REACHABLE_BY_BFS_FB
%token IS_REACHABLE_BY_DFS_BK
%token IS_REACHABLE_BY_BFS_BK
%token IS_REACHABLE_FB

%token IS_REACHABLE_DHR;
%token par_REFINE_MAX_CHECKS;

%token PROJECT_TO
%token DIFFERENCE_ASSIGN
%token RENAME
%token IS_REACHABLE

%token INVARIANT_ASSIGN
%token REVERSE
%token SAVE_FP_SURFACE
%token REACH_FORWARD_ITER
%token UNLOCK_SURFACE_LOCS
%token UNLOCK_LOCS
%token GET_INVARIANTS
%token PRINT_GRAPH
%token PROJECT_TO_FIRST
%token INVERSE
%token CONTAINS
%token REFINE_CONSTRAINTS
%token ADD_LABEL
%token WHO
%token SAVE_FP_INVARS
%token INITIAL_STATES
%token REFINE_LOCS
%token REFINE_LOC_DERIV
%token GET_SIM
%token IS_EMPTY
%token INTERSECTION_ASSIGN
%token LOC_INTERSECTION
%token LOC_UNION
%token REMOVE
%token STRING_TEXT
%token ECHO
%token GET_PARAMETERS
%token IS_SIM
%token IS_BISIM
%token AGSIM
%token AGCSIM
%token PRINT
%token SAVE_CON_FP
%token SAVE_GEN_FP
%token REACH
%token REACH_STOP
%token DEFNE
%token HYBRIDAUTOMATON
%token TIMEDAUTOMATON
%token AUTOMATON
%token INTERNAL_VAR
%token EXTERNAL_VAR
%token PARAMETER
%token SYNCLABS
%token INITIALLY
%token LOC
%token WHILE
%token WAIT
%token WHEN
%token DO
%token SYNC
%token GOTO
%token END
%token TRUE
%token FALSE
%token ASSIGN

%token IS_REACHABLE_BK


%token TO_ICTA

%token TO_DOT

%token TO_REGION_AUTOMATA
%token ADD_AUT
%token TO_AUT_STR
%token TAKE_COMPOSITION
%token ICTA_TO_TIMEDAUT_FOR_EXISTENTIAL
%token MAXITERATIONS
%token HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT


%token <str> IDENT
%token <str> INT
%token <str> STRING_TEXT


%left '|' '&'
%left GE LE EQ '<' '>'
%left '+' '-'
%left '*' '/'
%left '!'
%left '(' ')'
%left PRIM


%type <strv> ident_list
%type <strv> ivar_list
%type <strv> evar_list
%type <strv> param_list
%type <strv> val_set
%type <strv> constr_list


%type <str> constr_list_no_and
%type <str> constraint
%type <str> linearexpr

%%

program:
  commands
	;

commands: commands command
	| command
 	;


command: automaton
	| hybridautomaton
	| timedautomaton
	| IDENT '.' ADD_AUT '(' IDENT ')' ';'
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$1];
			enum TYPE t2=varmap[*$5];
			switch(t2)
			{
				case AUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=AUTSET;
										
							vautstrmap[*$1]=vautstrmap[*$5];
						}
						else
						{

							if(t1==AUTSET)
							{
								varmap[*$1]=AUTSET;
								vector<AutomatonStr> vautstr;
								for(vector<AutomatonStr>::iterator it=vautstrmap[*$1].begin();it!=vautstrmap[*$1].end();it++)
								{
									vautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vautstrmap[*$5].begin();it!=vautstrmap[*$5].end();it++)
								{
									vautstr.push_back(*it);
								}					
								vautstrmap[*$1]=vautstr;
							}
						}
					}
					break;
				case AUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=AUTSET;
							vector<AutomatonStr> vautstr;
							vautstr.push_back(*autstrmap[*$5]);						
			
							vautstrmap[*$1]=vautstr;
						}
						else
						{

							if(t1==AUTSET)
							{
								varmap[*$1]=AUTSET;
								vector<AutomatonStr> vautstr;
								for(vector<AutomatonStr>::iterator it=vautstrmap[*$1].begin();it!=vautstrmap[*$1].end();it++)
								{
									vautstr.push_back(*it);
								}
								vautstr.push_back(*autstrmap[*$5]);											
								vautstrmap[*$1]=vautstr;
							}
						}	
					}
					break;
				case HYBRIDAUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=HYBRIDAUTSET;
										
							vhybridautstrmap[*$1]=vhybridautstrmap[*$5];
						}
						else
						{

							if(t1==HYBRIDAUTSET)
							{
								varmap[*$1]=HYBRIDAUTSET;
								vector<AutomatonStr> vhybridautstr;
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*$1].begin();it!=vhybridautstrmap[*$1].end();it++)
								{
									vhybridautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*$5].begin();it!=vhybridautstrmap[*$5].end();it++)
								{
									vhybridautstr.push_back(*it);
								}					
								vhybridautstrmap[*$1]=vhybridautstr;
							}
						}																								
						
					}
					break;
				case HYBRIDAUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=HYBRIDAUTSET;
							vector<AutomatonStr> vhybridautstr;
							vhybridautstr.push_back(*hybridautstrmap[*$5]);						
			
							vhybridautstrmap[*$1]=vhybridautstr;
						}
						else
						{

							if(t1==HYBRIDAUTSET)
							{
								varmap[*$1]=HYBRIDAUTSET;
								vector<AutomatonStr> vhybridautstr;
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*$1].begin();it!=vhybridautstrmap[*$1].end();it++)
								{
									vhybridautstr.push_back(*it);
								}
								vhybridautstr.push_back(*hybridautstrmap[*$5]);											
								vhybridautstrmap[*$1]=vhybridautstr;
							}
						}						
					}
					break;
				case TIMEDAUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=TIMEDAUTSET;
										
							vtimedautstrmap[*$1]=vtimedautstrmap[*$5];
						}
						else
						{

							if(t1==TIMEDAUTSET)
							{
								varmap[*$1]=TIMEDAUTSET;
								vector<AutomatonStr> vtimedautstr;
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*$1].begin();it!=vtimedautstrmap[*$1].end();it++)
								{
									vtimedautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*$5].begin();it!=vtimedautstrmap[*$5].end();it++)
								{
									vtimedautstr.push_back(*it);
								}					
								vtimedautstrmap[*$1]=vtimedautstr;
							}
						}					
					}
					break;
				case TIMEDAUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*$1]=TIMEDAUTSET;
							vector<AutomatonStr> vtimedautstr;
							vtimedautstr.push_back(*timedautstrmap[*$5]);						
			
							vtimedautstrmap[*$1]=vtimedautstr;
						}
						else
						{

							if(t1==TIMEDAUTSET)
							{
								varmap[*$1]=TIMEDAUTSET;
								vector<AutomatonStr> vtimedautstr;
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*$1].begin();it!=vtimedautstrmap[*$1].end();it++)
								{
									vtimedautstr.push_back(*it);
								}
								vtimedautstr.push_back(*timedautstrmap[*$5]);											
								vtimedautstrmap[*$1]=vtimedautstr;
							}
						}
					}
					break;
			}
			
		}
	| IDENT '.' PRINT ';'
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			//cout<<"In print:"<<endl;
			enum TYPE t=varmap[*$1];
			switch(t)
			{
				case AUT:					
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomaton(*autmap[*$1]);				 
					break;
				case AUTSTR:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomatonStr(autstrmap[*$1]);
					break;
				case AUTSET:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutStrSet(vautstrmap[*$1]);				
					break;
				case HYBRIDAUT:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomaton(*hybridautmap[*$1]);				 
					break;
				case HYBRIDAUTSTR:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomatonStr(hybridautstrmap[*$1]);
					break;
				case HYBRIDAUTSET:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutStrSet(vhybridautstrmap[*$1]);				
					break;
				case TIMEDAUT:				
					cout<<(*$1)<<" contains"<<endl;						
					printHybridAutomaton(*timedautmap[*$1]);				 
					break;
				case TIMEDAUTSTR:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomatonStr(timedautstrmap[*$1]);
					break;
				case TIMEDAUTSET:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutStrSet(vtimedautstrmap[*$1]);				
					break;
				case ICTA:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomaton(*ictamap[*$1]);				 
					break;
				case ICTAHYBRID:
					cout<<(*$1)<<" contains"<<endl;
					printHybridAutomaton(*ictahybridmap[*$1]);
					break;
				case VALSETSTR:	
					cout<<(*$1)<<" contains"<<endl;
					for(vector<string>::iterator it=valsetstrmap[*$1].begin();it!=valsetstrmap[*$1].end();it++)
					{
						cout<<(*it)<<endl;
					}									
					break;
				case STATESTR:
					cout<<(*$1)<<" contains"<<endl;
					cout<<statestrmap[*$1]<<endl;
					break;
				case SYMSTATESTR:
					cout<<(*$1)<<" contains"<<endl;					
					{
						pair<string,vector<string> > p(symstatestrmap[*$1]);	
						cout<<p.first<<" ";		
						for(vector<string>::iterator it=p.second.begin();it!=p.second.end();it++)
						{
							cout<<(*it)<<" ";
						}
						cout<<endl;
					}
					break;
				case BOOL:
					cout<<(*$1)<<" contains"<<endl;
					cout<<boolmap[*$1]<<endl;
					break;
				
			}
		}
		| IDENT '.' TO_DOT ';'
		{
			//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$1];
			
			switch(t1)
			{
				case AUT:
				case HYBRIDAUT:
				case TIMEDAUT:
				case ICTA:
				case ICTAHYBRID:
					{
						Automaton a;
						switch(t1)
						{
							case AUT:
								a=*autmap[*$1];
								break;
							case HYBRIDAUT:
								a=*hybridautmap[*$1];
								break;
							case TIMEDAUT:
								a=*timedautmap[*$1];
								break;
							case ICTA:
								a=*ictamap[*$1];
								break;
							case ICTAHYBRID:
								a=*ictahybridmap[*$1];
								break;
						}
						createDotFileFromAut(a,*$1);
					}
					
					break;
				case AUTSTR:
				case HYBRIDAUTSTR:
				case TIMEDAUTSTR:
					{
						
						AutomatonStr a;
						switch(t1)
						{
							case AUTSTR:
								a=*autstrmap[*$1];
								break;
							case HYBRIDAUTSTR:
								a=*hybridautstrmap[*$1];
								break;
							case TIMEDAUTSTR:
								a=*timedautstrmap[*$1];
								break;
						}
						createDotFileFromAutStr(a,*$1);
					}
					break;
				case AUTSET:
				case HYBRIDAUTSET:
				case TIMEDAUTSET:
					{
						vector<AutomatonStr> vautstr;
						switch(t1)
						{
							case AUTSET:
								vautstr=vautstrmap[*$1];
								break;
							case HYBRIDAUTSET:
								vautstr=vhybridautstrmap[*$1];
								break;
							case TIMEDAUTSET:
								vautstr=vtimedautstrmap[*$1];
								break;
						}
						createDotFileFromVAutStr(vautstr,*$1);
					}
					break;			
				
			}
		}
	| MAXITERATIONS ASSIGN INT ';'
		{
			maxiterations=atoi($3->c_str());
		}
	| IDENT ASSIGN IDENT '&' IDENT ';'
		{	//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$3];
			enum TYPE t2=varmap[*$5];
			if(t1==AUTSTR && t2==AUTSTR)
			{
				//cout<<"AutAut type"<<endl;				
				varmap[*$1]=AUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*autstrmap[*$3];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*autstrmap[*$5];
				

				vector<string> vs1=takeUnionVS(tmpa1->cntr_var_lst.cntr_var_arr,tmpa2->cntr_var_lst.cntr_var_arr);
				vector<string> vs2=takeUnionVINV(tmpa1->in_var_lst.in_var_arr,tmpa2->in_var_lst.in_var_arr);


				
				tmpa1->cntr_var_lst.cntr_var_arr=vs1;
				tmpa2->cntr_var_lst.cntr_var_arr=vs1;




				Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*tmpa1);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*tmpa2);


				/*if(is_disjoint(a1->cntr_var_lst.cntr_var_arr,a2->cntr_var_lst.cntr_var_arr) && is_in(a1->in_var_lst.in_var_arr,vs1) && is_in(a2->in_var_lst.in_var_arr,vs1))
				{*/
					Automaton_List auta_lst;
					auta_lst.aut_arr.push_back(*a1);
					auta_lst.aut_arr.push_back(*a2);					
					
					
					map<string,string> cntrToautmap=createAutomatonMap(auta_lst);




					a1->cntr_var_lst.cntr_var_arr=vs1;
					a2->cntr_var_lst.cntr_var_arr=vs1;
					a1->fillMaps();
					a2->fillMaps();
					
					Automaton_List alst;
					alst.aut_arr.push_back(*a1);
					alst.aut_arr.push_back(*a2);
					
					Automaton *prod=new Automaton();
					(*prod)=take_product2(alst);
					prod->cntrToautmap=cntrToautmap;
					prod->fillMaps();
					autmap[*$1]=prod;
				/*}
				else
				{
					//cout<<"This is the mistake of yours while giving writing input var"<<endl;
					yyerror("This is the mistake of yours while giving writing input var");
				}*/
			}
			else if(t1==HYBRIDAUTSTR && t2==HYBRIDAUTSTR)
			{
				//cout<<"AutAut type"<<endl;				
				varmap[*$1]=HYBRIDAUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*hybridautstrmap[*$3];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*hybridautstrmap[*$5];
				

				vector<string> vs1=takeUnionVS(tmpa1->cntr_var_lst.cntr_var_arr,tmpa2->cntr_var_lst.cntr_var_arr);
				vector<string> vs2=takeUnionVINV(tmpa1->in_var_lst.in_var_arr,tmpa2->in_var_lst.in_var_arr);


				
				tmpa1->cntr_var_lst.cntr_var_arr=vs1;
				tmpa2->cntr_var_lst.cntr_var_arr=vs1;




				Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*tmpa1);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*tmpa2);


				/*if(is_disjoint(a1->cntr_var_lst.cntr_var_arr,a2->cntr_var_lst.cntr_var_arr) && is_in(a1->in_var_lst.in_var_arr,vs1) && is_in(a2->in_var_lst.in_var_arr,vs1))
				{*/

					Automaton_List auta_lst;
					auta_lst.aut_arr.push_back(*a1);
					auta_lst.aut_arr.push_back(*a2);					
					map<string,string> cntrToautmap=createAutomatonMap(auta_lst);
					




					a1->cntr_var_lst.cntr_var_arr=vs1;
					a2->cntr_var_lst.cntr_var_arr=vs1;
					a1->fillMaps();
					a2->fillMaps();
					Automaton_List alst;
					alst.aut_arr.push_back(*a1);
					alst.aut_arr.push_back(*a2);					
					
					

					Automaton *prod=new Automaton();
					(*prod)=take_product2(alst);
					prod->cntrToautmap=cntrToautmap;
					prod->fillMaps();
					hybridautmap[*$1]=prod;
				/*}
				else
				{
					//cout<<"This is the mistake of yours while giving writing input var"<<endl;
					yyerror("This is the mistake of yours while giving writing input var");
				}*/
			}
			else if(t1==TIMEDAUTSTR && t2==TIMEDAUTSTR)
			{
				//cout<<"AutAut type"<<endl;				
				varmap[*$1]=TIMEDAUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*timedautstrmap[*$3];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*timedautstrmap[*$5];
				

				vector<string> vs1=takeUnionVS(tmpa1->cntr_var_lst.cntr_var_arr,tmpa2->cntr_var_lst.cntr_var_arr);
				vector<string> vs2=takeUnionVINV(tmpa1->in_var_lst.in_var_arr,tmpa2->in_var_lst.in_var_arr);


				
				tmpa1->cntr_var_lst.cntr_var_arr=vs1;
				tmpa2->cntr_var_lst.cntr_var_arr=vs1;




				Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*tmpa1);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*tmpa2);


				/*if(is_disjoint(a1->cntr_var_lst.cntr_var_arr,a2->cntr_var_lst.cntr_var_arr) && is_in(a1->in_var_lst.in_var_arr,vs1) && is_in(a2->in_var_lst.in_var_arr,vs1))
				{*/

					Automaton_List auta_lst;
					auta_lst.aut_arr.push_back(*a1);
					auta_lst.aut_arr.push_back(*a2);					
					
					map<string,string> cntrToautmap=createAutomatonMap(auta_lst);



					a1->cntr_var_lst.cntr_var_arr=vs1;
					a2->cntr_var_lst.cntr_var_arr=vs1;
					a1->fillMaps();
					a2->fillMaps();
					Automaton_List alst;
					alst.aut_arr.push_back(*a1);
					alst.aut_arr.push_back(*a2);
					
					Automaton *prod=new Automaton();
					(*prod)=take_product2(alst);				
					prod->cntrToautmap=cntrToautmap;
					prod->fillMaps();
					timedautmap[*$1]=prod;
				/*}
				else
				{
					//cout<<"This is the mistake of yours while giving writing input var"<<endl;
					yyerror("This is the mistake of yours while giving writing input var");
				}*/
			}
			else if(t1==STATESTR)
			{
				
				if(t2==VALSETSTR)
				{
					//cout<<"Here"<<endl;
					varmap[*$1]=SYMSTATESTR;
					pair<string,vector<string> > p(*$3,valsetstrmap[*$5]);				
					symstatestrmap[*$1]=p;			
				}
			}
			else
			{
				//cout<<"Rahul2:"<<endl;
				if(t2==VALSETSTR)
				{
					//cout<<"Here"<<endl;
					varmap[*$1]=SYMSTATESTR;
					pair<string,vector<string> > p(*$3,valsetstrmap[*$5]);				
					symstatestrmap[*$1]=p;			
				}
			}
			
		}
	| IDENT ASSIGN STRING_TEXT '&' IDENT ';'
	{	//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
		enum TYPE t2=varmap[*$5];
		if(t2==VALSETSTR)
		{
			//cout<<"Here"<<endl;
			varmap[*$1]=SYMSTATESTR;
			pair<string,vector<string> > p(*$3,valsetstrmap[*$5]);				
			symstatestrmap[*$1]=p;			
		}
		
	}

	| IDENT ASSIGN TAKE_COMPOSITION '(' IDENT ')' ';'
		{
			//varmap[*$1]=HYBRIDAUT;
			
			enum TYPE t1=varmap[*$5];
			
			switch(t1)
			{
				case AUTSET:
					{
						//cout<<"Autset"<<endl;
						varmap[*$1]=AUT;
						//cntr_var_lst.cntr_arr take union
						vector<AutomatonStr> alst=vautstrmap[*$5];
			
						vector<string> *vs=new vector<string>();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								vs->push_back(*itt);
							}		
						}

						vector<string> *vss=new vector<string>();
						(*vss)=remove_duplicates(*vs);


						/*Automaton_List auta_lst;
						for(vector<AutomatonStr>::iterator aai=alst.begin();aai!=alst.end();aai++)
						{
							Automaton *atmp=new Automaton();
							(*atmp)=autstrToaut(*aai);
							auta_lst.aut_arr.push_back(*atmp);	
						}*/
						
						
						
						map<string,string> cntrToautmap=createAutomatonMap(alst);



						Automaton_List *atlist=new Automaton_List();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{			
					
					
					
							AutomatonStr *tmp=new AutomatonStr();
							(*tmp)=(*it);
							tmp->cntr_var_lst.cntr_var_arr=(*vss);					
		
					
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*tmp);
					
							a->fillMaps();
							atlist->aut_arr.push_back(*a);
					
					
						}
				
						//take product of these hybridautset

						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}

				
						Automaton *prod=new Automaton();

						(*prod)=take_product2(*atlist);				

						prod->cntrToautmap=cntrToautmap;


						prod->fillMaps();
						autmap[*$1]=prod;
					}
					break;
				case HYBRIDAUTSET:
					{	
						//cout<<"HybridAutset"<<endl;
						varmap[*$1]=HYBRIDAUT;		
						//cntr_var_lst.cntr_arr take union
						vector<AutomatonStr> alst=vhybridautstrmap[*$5];
			
						vector<string> *vs=new vector<string>();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								vs->push_back(*itt);
							}		
						}

						vector<string> *vss=new vector<string>();
						(*vss)=remove_duplicates(*vs);

						/*Automaton_List auta_lst;
						for(vector<AutomatonStr>::iterator aai=alst.begin();aai!=alst.end();aai++)
						{
							Automaton *atmp=new Automaton();
							(*atmp)=autstrToaut(*aai);
							auta_lst.aut_arr.push_back(*atmp);	
						}*/
						
						
						
						map<string,string> cntrToautmap=createAutomatonMap(alst);




						Automaton_List *atlist=new Automaton_List();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{			
					
					
					
							AutomatonStr *tmp=new AutomatonStr();
							(*tmp)=(*it);
							tmp->cntr_var_lst.cntr_var_arr=(*vss);					
		
					
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*tmp);
					
							a->fillMaps();
							atlist->aut_arr.push_back(*a);
					
					
						}
				
						//take product of these hybridautset

						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}

				
						Automaton *prod=new Automaton();
				
						(*prod)=take_product2(*atlist);
						prod->cntrToautmap=cntrToautmap;
						prod->fillMaps();
						hybridautmap[*$1]=prod;
					}
					break;
				case TIMEDAUTSET:
					{
						//cout<<"TimedAutset"<<endl;
						varmap[*$1]=TIMEDAUT;			
						//cntr_var_lst.cntr_arr take union
						vector<AutomatonStr> alst=vtimedautstrmap[*$5];
			
						vector<string> *vs=new vector<string>();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								vs->push_back(*itt);
							}		
						}
						//cout<<"1"<<endl;
						vector<string> *vss=new vector<string>();
						(*vss)=remove_duplicates(*vs);


						/*Automaton_List auta_lst;
						for(vector<AutomatonStr>::iterator aai=alst.begin();aai!=alst.end();aai++)
						{
							Automaton *atmp=new Automaton();
							(*atmp)=autstrToaut(*aai);
							auta_lst.aut_arr.push_back(*atmp);	
						}*/
						
						
						
						map<string,string> cntrToautmap=createAutomatonMap(alst);



						//cout<<"2"<<endl;
						Automaton_List *atlist=new Automaton_List();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{			
					
					
					
							AutomatonStr *tmp=new AutomatonStr();
							(*tmp)=(*it);
							tmp->cntr_var_lst.cntr_var_arr=(*vss);					
		
					
							Automaton *a=new Automaton();
							//cout<<"2a"<<endl;
							(*a)=autstrToaut(*tmp);
							//cout<<"2b"<<endl;
							a->fillMaps();
							atlist->aut_arr.push_back(*a);
					
					
						}
				
						//take product of these hybridautset
						//cout<<"3"<<endl;
						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}
						//cout<<"4"<<endl;
				
						Automaton *prod=new Automaton();

						

						(*prod)=take_product2(*atlist);
						prod->cntrToautmap=cntrToautmap;

						prod->fillMaps();
						timedautmap[*$1]=prod;
						//cout<<"5"<<endl;
					}
					break;
			}
		}
	| IDENT ASSIGN TO_AUT_STR '(' IDENT ')' ';'
		{
						
		}
	| IDENT ASSIGN IDENT ';'
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL


			enum TYPE t=varmap[*$3];
			switch(t)
			{
				case AUT:
					{
						varmap[*$1]=AUT;				
						Automaton *a=new Automaton();
						(*a)=(*autmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						autmap[*$1]=a;			
					}
					break;
				case AUTSTR:
					{
						varmap[*$1]=AUT;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*autstrmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
					
						autmap[*$1]=a;					
					
					}
					break;
				case AUTSET:
					{
						varmap[*$1]=AUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vautstrmap[*$3];
						//va->cntrToautmap=createAutomatonMap(*va);
						vautstrmap[*$1]=(*va);						
					}
					break;
				case HYBRIDAUT:
					{	
						varmap[*$1]=HYBRIDAUT;	
						Automaton *a=new Automaton();					
						(*a)=(*hybridautmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						hybridautmap[*$1]=a;					
					
					}
					break;
				case HYBRIDAUTSTR:
					{
						varmap[*$1]=HYBRIDAUT;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*hybridautstrmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						hybridautmap[*$1]=a;					
					}
					break;
				case HYBRIDAUTSET:
					{
						varmap[*$1]=HYBRIDAUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vhybridautstrmap[*$3];
						//va->cntrToautmap=createAutomatonMap(*va);
						vhybridautstrmap[*$1]=(*va);						
					
					}
					break;
				case TIMEDAUT:			
					{
						varmap[*$1]=TIMEDAUT;

						Automaton *a=new Automaton();
						(*a)=(*timedautmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						timedautmap[*$1]=a;			
				
					}
					break;
				case TIMEDAUTSTR:
					{
						varmap[*$1]=TIMEDAUT;	
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*timedautstrmap[*$3]);						
						a->cntrToautmap=createAutomatonMap(*a);
						timedautmap[*$1]=a;				
					}					
					break;
				case TIMEDAUTSET:
					{
						varmap[*$1]=TIMEDAUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vtimedautstrmap[*$3];
						//va->cntrToautmap=createAutomatonMap(*va);
						vtimedautstrmap[*$1]=(*va);
					}
					break;
				/*case REGIONAUT:	
				{	varmap[*$1]=REGIONAUT;				
					Automaton *a=new Automaton();
					(*a)=(*regionautmap[*$3]);
					regionautmap[*$1]=a;
					//regionautmap[*$1]=regionautmap[*$3];
					break;
				}
				case REGIONAUTSTR:		
					{
						varmap[*$1]=REGIONAUTSTR;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*regionautstrmap[*$3]);
						autmap[*$1]=a;							
					}
					break;*/
				case ICTA:
					{
						varmap[*$1]=ICTA;
					
						Automaton *a=new Automaton();
						(*a)=(*ictamap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						ictamap[*$1]=a;				
					}
					break;
				case ICTAHYBRID:
					{
						varmap[*$1]=ICTAHYBRID;
					
						Automaton *a=new Automaton();
						(*a)=(*ictahybridmap[*$3]);
						a->cntrToautmap=createAutomatonMap(*a);
						ictahybridmap[*$1]=a;				
					}
					break;
				/*case ICTASTR:	
					{
						varmap[*$1]=ICTASTR;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*ictastrmap[*$3]);
						autmap[*$1]=a;							
					}
					break;*/				
				case VALSETSTR:	
					varmap[*$1]=VALSETSTR;				
					valsetstrmap[*$1]=valsetstrmap[*$3];
					break;
				case STATESTR:
					varmap[*$1]=STATESTR;
					statestrmap[*$1]=statestrmap[*$3];
					break;
				case SYMSTATESTR:
					varmap[*$1]=SYMSTATESTR;
					symstatestrmap[*$1]=symstatestrmap[*$3];
					break;
				case BOOL:
					varmap[*$1]=BOOL;
					boolmap[*$1]=boolmap[*$3];
					break;
	
			}
		}
	| IDENT ASSIGN val_set ';'
		{
			varmap[*$1]=VALSETSTR;
			valsetstrmap[*$1]=(*$3);	
		}
	/*| IDENT ASSIGN TRUE ';'
		{			
			varmap[*$1]=BOOL;
			boolmap[*$1]=true;		
		}
	| IDENT ASSIGN FALSE ';'
		{	
			varmap[*$1]=BOOL;
			boolmap[*$1]=false;	
		}*/
	| IDENT ASSIGN IS_REACHABLE_BY_DFS_FB '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			
			switch(t1)
			{
				case AUT:
					{
						
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);
							Automaton a;
							a=*autmap[*$5];

							a.fillMaps();
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_dfs_fb(R_f,R_i,a);
						}
					}
					break;

			}
		}
	| IDENT ASSIGN IS_REACHABLE_BY_BFS_FB '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);
							Automaton a;
							a=*autmap[*$5];
							a.fillMaps();
					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_bfs_fb(R_f,R_i,a);
						}
					}
					break;

			}
		}
		| IDENT ASSIGN IS_REACHABLE_BY_DFS_BK '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			//cout<<"Here"<<endl;
			switch(t1)
			{
				case AUT:
					{
						//cout<<"Here2"<<endl;
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);
							Automaton a;
							a=*autmap[*$5];
							a.fillMaps();
					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_dfs_bk(R_f,R_i,a);
						}
					}
					break;

			}
		}
	| IDENT ASSIGN IS_REACHABLE_BY_BFS_BK '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);
							Automaton a;
							a=*autmap[*$5];
							a.fillMaps();
					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_bfs_bk(R_f,R_i,a);
						}
					}
					break;

			}
		}
	| IDENT ASSIGN IS_REACHABLE '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*hybridautmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							//here forward reachability algo is used
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
			}
		}
	| IDENT ASSIGN IS_REACHABLE_FB '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							
							autlst.aut_arr.push_back(*autmap[*$5]);
							
					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;



							Automaton a;
							a=*hybridautmap[*$5];
							a.fillMaps();
							Automaton_List autlst;
							//autlst.aut_arr.push_back(*hybridautmap[*$5]);
							autlst.aut_arr.push_back(a);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*$1]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
			}
			
		}
	| IDENT ASSIGN IS_REACHABLE_BK '(' IDENT ',' IDENT ')' ';'	
		{
//NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t1=varmap[*$5];
			enum TYPE t2=varmap[*$7];
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*$1]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton a;	
							a=*hybridautmap[*$5];
							a.fillMaps();

							Automaton_List autlst;
							//autlst.aut_arr.push_back(*hybridautmap[*$5]);
							autlst.aut_arr.push_back(a);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*$1]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*$1]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*$5]);

					
							//initialize_final_states_compo_demo(R_f,aut_lst);
							initialize_final_states_from_symstate(R_f,symstatestrmap[*$7],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*$1]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
			}
		}
	| IDENT ASSIGN TO_ICTA '(' IDENT ')' ';'
		{
//NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t=varmap[*$5];
			switch(t)
			{
				case TIMEDAUTSET:
					{
						Automaton_List alist;					
						set<string> s;
						for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*$5].begin();it!=vtimedautstrmap[*$5].end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								s.insert(*itt);
							}
						}
						vector<string> vs(s.begin(),s.end());
						
						
						/*Automaton_List auta_lst;
						for(vector<AutomatonStr>::iterator aai=vtimedautstrmap[*$5].begin();aai!=vtimedautstrmap[*$5].end();aai++)
						{
							Automaton *atmp=new Automaton();
							(*atmp)=autstrToaut(*aai);
							auta_lst.aut_arr.push_back(*atmp);	
						}*/
						
						
						//cout<<"Rahul3:"<<endl;
						map<string,string> cntrToautmap=createAutomatonMap(vtimedautstrmap[*$5]);

						for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*$5].begin();it!=vtimedautstrmap[*$5].end();it++)
						{
							AutomatonStr *atmp=new AutomatonStr();
							(*atmp)=(*it);
							atmp->cntr_var_lst.cntr_var_arr=vs;
						
						
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*atmp);
							a->cntr_var_lst.cntr_var_arr=vs;
							a->fillMaps();


							//(*a)=removeinvariants(*a);
							
							//printHybridAutomaton(*a);				 

	
							alist.aut_arr.push_back(*a);
						
						}
						Automaton *prod=new Automaton();
						//cout<<"Rahul1:"<<endl;
						(*prod)=to_ICTA2(alist);
						//cout<<"Rahul2:"<<endl;
						prod->cntrToautmap=cntrToautmap;						
						prod->fillMaps();
						varmap[*$1]=ICTA;
					
						ictamap[*$1]=prod;				
					
					
					}
					break;
				case HYBRIDAUTSET:
					{
						Automaton_List alist;

					
						set<string> s;
						for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*$5].begin();it!=vhybridautstrmap[*$5].end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								s.insert(*itt);
							}
						}
						vector<string> vs(s.begin(),s.end());

						/*Automaton_List auta_lst;
						for(vector<AutomatonStr>::iterator aai=vhybridautstrmap[*$5].begin();aai!=vhybridautstrmap[*$5].end();aai++)
						{
							Automaton *atmp=new Automaton();
							(*atmp)=autstrToaut(*aai);
							auta_lst.aut_arr.push_back(*atmp);	
						}*/
						
						
						
						map<string,string> cntrToautmap=createAutomatonMap(vhybridautstrmap[*$5]);

						

						for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*$5].begin();it!=vhybridautstrmap[*$5].end();it++)
						{
							AutomatonStr *atmp=new AutomatonStr();
							(*atmp)=(*it);
							atmp->cntr_var_lst.cntr_var_arr=vs;
						
						
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*atmp);
							a->cntr_var_lst.cntr_var_arr=vs;
							a->fillMaps();



							//(*a)=removeinvariants(*a);
							
							//printHybridAutomaton(*a);				 

							alist.aut_arr.push_back(*a);
						
						}
						Automaton *prod=new Automaton();
						(*prod)=to_ICTA2(alist);
						prod->cntrToautmap=cntrToautmap;
						prod->fillMaps();
						varmap[*$1]=ICTAHYBRID;
					
						ictahybridmap[*$1]=prod;				
										
						
					}
					break;
			}		
		}

	| IDENT ASSIGN HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT '(' IDENT ')' ';'
		{
			enum TYPE t=varmap[*$5];
			switch(t)
			{
				case ICTA:
				{
					varmap[*$1]=ICTA;
					Automaton *a=new Automaton();
					(*a)=(*ictamap[*$5]);
					a->fillMaps();				

					Automaton *prod=new Automaton();
					(*prod)=hybrid_flavoured_timed_aut_to_timed_aut(*a);
					prod->fillMaps();
					prod->cntrToautmap=a->cntrToautmap;
					ictamap[*$1]=prod;	
					
					/*prod_aut.cntr_var_lst.cntr_var_arr.clear();
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("z");*/
					//prod->cntr_var_lst.cntr_var_arr.push_back("l");


					//Automaton *region_aut=new Automaton();
					//(*region_aut)=construct_Region_Automata(*prod);

					//region_aut->fillMaps();
					break;
				}
				case ICTAHYBRID:
				{
					varmap[*$1]=ICTA;
					Automaton *a=new Automaton();
					(*a)=(*ictahybridmap[*$5]);
					a->fillMaps();				

					Automaton *prod=new Automaton();
					(*prod)=hybrid_flavoured_timed_aut_to_timed_aut(*a);
					prod->fillMaps();
					prod->cntrToautmap=a->cntrToautmap;
					ictamap[*$1]=prod;	
					
					/*prod_aut.cntr_var_lst.cntr_var_arr.clear();
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("z");*/
					//prod->cntr_var_lst.cntr_var_arr.push_back("l");


					//Automaton *region_aut=new Automaton();
					//(*region_aut)=construct_Region_Automata(*prod);

					//region_aut->fillMaps();
					break;
				}
			}	
		}

	| IDENT ASSIGN TO_REGION_AUTOMATA '(' IDENT ')' ';'
		{
//NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTASTR,VALSETSTR,STATESTR,SYMSTATESTR,BOOL
			enum TYPE t=varmap[*$5];
			switch(t)
			{
				case TIMEDAUT:					
					{	
						varmap[*$1]=AUT;
						timedautmap[*$5]->fillMaps();
						Automaton *without_invar=new Automaton();
						(*without_invar)=*timedautmap[*$5];
						//(*without_invar)=removeinvariants(*timedautmap[*$5]);
						//cout<<"Without invariants:"<<endl;
						//printHybridAutomaton(*without_invar);
						Automaton *region_aut=new Automaton();						
						(*region_aut)=construct_Region_Automata(*without_invar);
						region_aut->fillMaps();
						region_aut->cntrToautmap=without_invar->cntrToautmap;
						autmap[*$1]=region_aut;			

						
						
					}	
					break;				
				case ICTA:
					{	
						varmap[*$1]=AUT;

						ictamap[*$5]->fillMaps(); 						
						
						Automaton *without_invar=new Automaton();
						(*without_invar)=*ictamap[*$5];
						//(*without_invar)=removeinvariants(*ictamap[*$5]);
						without_invar->fillMaps();
						Automaton *region_aut=new Automaton();							
						
						(*region_aut)=construct_Region_Automata_for_ICTA(*without_invar);
						region_aut->fillMaps();
						//region_aut->cntrToautmap=without_invar->cntrToautmap;
						autmap[*$1]=region_aut;						
					}
					break;			
				
			}
			
		}
	
		
	;

hybridautomaton: HYBRIDAUTOMATON IDENT { a=new AutomatonStr(); a->name=(*$2);} automaton_body END
		{
			varmap[*$2]=HYBRIDAUTSTR;
			hybridautstrmap[*$2]=a;
			paut_lst.aut_arr.push_back(*a);

			/*cout<<"\nAutomaton Name:"<<a->name<<endl;			
			
			
			cout<<"Control Variable List:"<<endl;
			for(vector<string>::iterator it=a->cntr_var_lst.cntr_var_arr.begin();it!=a->cntr_var_lst.cntr_var_arr.end();it++)
			{
				cout<<*it<<",";
			}
			cout<<endl;

			cout<<"Parameter List:"<<endl;
			for(vector<Parameter>::iterator it=a->parameter_lst.par_list_arr.begin();it!=a->parameter_lst.par_list_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;
			
			cout<<"Synchronizing Label List:"<<endl;
			for(vector<Synchronizing_Label>::iterator it=a->syn_lab_lst.syn_lab_arr.begin();it!=a->syn_lab_lst.syn_lab_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Input Variable List:"<<endl;
			for(vector<Input_Variable>::iterator it=a->in_var_lst.in_var_arr.begin();it!=a->in_var_lst.in_var_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->loc_lst.begin();it!=a->loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			cout<<"Initial Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->initial_loc_lst.begin();it!=a->initial_loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<endl;
			}

			cout<<"Edge List:"<<endl;
			for(vector<EdgeStr>::iterator it=a->edge_lst.begin();it!=a->edge_lst.end();it++)
			{
				cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" ";
				for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			*/
			
		}
	;


automaton: AUTOMATON IDENT { a=new AutomatonStr(); a->name=(*$2);} automaton_body END
		{
			varmap[*$2]=AUTSTR;
			autstrmap[*$2]=a;
			paut_lst.aut_arr.push_back(*a);

			/*cout<<"\nAutomaton Name:"<<a->name<<endl;			
			
			
			cout<<"Control Variable List:"<<endl;
			for(vector<string>::iterator it=a->cntr_var_lst.cntr_var_arr.begin();it!=a->cntr_var_lst.cntr_var_arr.end();it++)
			{
				cout<<*it<<",";
			}
			cout<<endl;

			cout<<"Parameter List:"<<endl;
			for(vector<Parameter>::iterator it=a->parameter_lst.par_list_arr.begin();it!=a->parameter_lst.par_list_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;
			
			cout<<"Synchronizing Label List:"<<endl;
			for(vector<Synchronizing_Label>::iterator it=a->syn_lab_lst.syn_lab_arr.begin();it!=a->syn_lab_lst.syn_lab_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Input Variable List:"<<endl;
			for(vector<Input_Variable>::iterator it=a->in_var_lst.in_var_arr.begin();it!=a->in_var_lst.in_var_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->loc_lst.begin();it!=a->loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			cout<<"Initial Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->initial_loc_lst.begin();it!=a->initial_loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<endl;
			}

			cout<<"Edge List:"<<endl;
			for(vector<EdgeStr>::iterator it=a->edge_lst.begin();it!=a->edge_lst.end();it++)
			{
				cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" ";
				for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			*/
			
		}
	;


timedautomaton: TIMEDAUTOMATON IDENT { a=new AutomatonStr(); a->name=(*$2);} automaton_body END
		{
			varmap[*$2]=TIMEDAUTSTR;
			timedautstrmap[*$2]=a;
			paut_lst.aut_arr.push_back(*a);

			/*cout<<"\nAutomaton Name:"<<a->name<<endl;			
			
			
			cout<<"Control Variable List:"<<endl;
			for(vector<string>::iterator it=a->cntr_var_lst.cntr_var_arr.begin();it!=a->cntr_var_lst.cntr_var_arr.end();it++)
			{
				cout<<*it<<",";
			}
			cout<<endl;

			cout<<"Parameter List:"<<endl;
			for(vector<Parameter>::iterator it=a->parameter_lst.par_list_arr.begin();it!=a->parameter_lst.par_list_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;
			
			cout<<"Synchronizing Label List:"<<endl;
			for(vector<Synchronizing_Label>::iterator it=a->syn_lab_lst.syn_lab_arr.begin();it!=a->syn_lab_lst.syn_lab_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Input Variable List:"<<endl;
			for(vector<Input_Variable>::iterator it=a->in_var_lst.in_var_arr.begin();it!=a->in_var_lst.in_var_arr.end();it++)
			{
				cout<<it->name<<",";
			}
			cout<<endl;

			cout<<"Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->loc_lst.begin();it!=a->loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			cout<<"Initial Location List:"<<endl;
			for(vector<LocationStr>::iterator it=a->initial_loc_lst.begin();it!=a->initial_loc_lst.end();it++)
			{
				cout<<it->name<<" ";
				for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<endl;
			}

			cout<<"Edge List:"<<endl;
			for(vector<EdgeStr>::iterator it=a->edge_lst.begin();it!=a->edge_lst.end();it++)
			{
				cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" ";
				for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
				{
					cout<<*itt<<",";
				}
				cout<<"      ";
				for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
				{
					cout<<*itt<<",";
				}				
				cout<<endl;
			}
			*/
			
		}
	;





automaton_body: declaration location_list initial
		;

declaration:
	// empty
	| declaration internal_vars 
   	| declaration external_vars 
	| declaration synclab
   	| declaration parameters 
	;

internal_vars:
	INTERNAL_VAR ':' ivar_list ';'
		{
			a->cntr_var_lst.cntr_var_arr=*((vector<string> *)$3);
			//cout<<"Control var size:"<<a->cntr_var_lst.cntr_var_arr.size()<<endl;
			//cout<<"Control var size:"<<((vector<string> *)$3)->size()<<endl;
			
		}
	;
external_vars:
	EXTERNAL_VAR ':' evar_list ';'
		{
			Input_Variable i;
			for(vector<string>::iterator it=((vector<string> *)$3)->begin();it!=((vector<string> *)$3)->end();it++)
			{
				i.name=(*it);
				a->in_var_lst.in_var_arr.push_back(i);
			}
			
			//cout<<"External var size:"<<a->in_var_lst.in_var_arr.size()<<endl;
			
		}
	;
synclab:
	SYNCLABS ':' ident_list ';' 
		{
			Synchronizing_Label sl;
			for(vector<string>::iterator it=((vector<string> *)$3)->begin();it!=((vector<string> *)$3)->end();it++)
			{
				sl.name=(*it);
				a->syn_lab_lst.syn_lab_arr.push_back(sl);
			}
			//cout<<"Sync Lab Size:"<<a->syn_lab_lst.syn_lab_arr.size()<<endl;
      		}
	;
parameters:
	PARAMETER ':' param_list ';'
		{
			Parameter par;
			for(vector<string>::iterator it=((vector<string> *)$3)->begin();it!=((vector<string> *)$3)->end();it++)
			{
				par.name=(*it);
				a->parameter_lst.par_list_arr.push_back(par);
			}
			
			//cout<<"Par Size:"<<a->parameter_lst.par_list_arr.size()<<endl;
		}
	;

ivar_list: ivar_list ',' IDENT
		{						
			
			((vector<string> *)$$)->push_back(*$3);
			
		}
	| IDENT { 
			
			$$=new vector<string>();
			
			((vector<string> *)$$)->push_back(*$1);
		}
	;

evar_list: evar_list ',' IDENT
		{
			
			((vector<string> *)$$)->push_back(*$3);
			
		}
	| IDENT {
			
			$$=new vector<string>();
			((vector<string> *)$$)->push_back(*$1);
		}
	;



param_list: param_list ',' IDENT 
		{
			
			((vector<string> *)$$)->push_back(*$3);
		}
	| IDENT {  
			
			$$=new vector<string>();
			((vector<string> *)$$)->push_back(*$1);
		}
	;

ident_list: ident_list ',' IDENT  
        	{
			
			
			((vector<string> *)$$)->push_back(*$3);
                }
	| IDENT 
                {
                 	
			$$=new vector<string>();
			((vector<string> *)$$)->push_back(*$1);
                }
	;

initial:
  	INITIALLY ':' state_list ';' 
		{ 
		}
  	| INITIALLY state_list ';' 
		{
		}
	; 
state_list:
  	IDENT '&' val_set
      		{ 
			//cout<<"Rahul:"<<*$1<<endl;
			lstr.name=(*$1);
			lstr.invariants=(*$3);
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			//cout<<"Initial Loc parsed"<<endl;
			
		}
	| IDENT
		{
			lstr.name=(*$1);
			lstr.invariants.clear();
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			//cout<<"Initial Loc parsed"<<endl;
		}
	| state_list ',' IDENT
		{
			lstr.name=(*$3);
			lstr.invariants.clear();
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			//cout<<"Initial Loc parsed"<<endl;
		}
  	| state_list ',' IDENT '&' val_set
      		{ 
			lstr.name=(*$3);
			lstr.invariants=(*$5);
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			//cout<<"Initial Loc parsed"<<endl;
			

		}
		
  	;

location_list:
    	location_list location transition_list
  	| location_list location ';' transition_list
	| location transition_list
	| location ';' transition_list	
	;

	
location: 
	LOC IDENT ':' WHILE val_set WAIT '{' constr_list '}'  
		{			
			
			lstr.name=(*$2);
			lstr.invariants=(*$5);
			lstr.rate=(*$8);
			a->loc_lst.push_back(lstr);

			varmap[*$2]=STATESTR;
			statestrmap[*$2]=a->name;			
			//cout<<"Loc parsed"<<endl;
      		}
	| LOC IDENT ':' WHILE val_set
		{
			lstr.name=(*$2);
			/*cout<<"\nInvariants:"<<endl;
			for(vector<string>::iterator it=$5->begin();it!=$5->end();it++)
			{
				cout<<(*it)<<endl;
			}
			cout<<endl;*/
			lstr.invariants=(*$5);		
			//lstr.rate=(*$8);
			lstr.rate.clear();
			a->loc_lst.push_back(lstr);

			varmap[*$2]=STATESTR;
			statestrmap[*$2]=a->name;			
			//cout<<"Loc parsed"<<endl;
		}
	;

transition_list: transition_list transition
  	|
  	;
  
transition:
    	// NOTE: ident_list semantics: add a transition for each label in the ident_list;
    	WHEN val_set SYNC IDENT DO '{' val_set '}' GOTO IDENT ';'
      		{
			
			e.pre=a->loc_lst.back().name;
			e.post=(*$10);
			e.guards=(*$2);
			e.updates=(*$7);
			e.syn_lab=(*$4);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
	| WHEN val_set DO '{' val_set '}' SYNC IDENT GOTO IDENT ';'
      		{ 
			
			e.pre=a->loc_lst.back().name;
			e.post=(*$10);
			e.guards=(*$2);
			e.updates=(*$5);
			e.syn_lab=(*$8);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
	| WHEN val_set SYNC IDENT GOTO IDENT ';'
      		{ 
			
			e.pre=a->loc_lst.back().name;
			e.post=(*$6);
			e.guards=(*$2);
			e.updates.clear();
			e.syn_lab=(*$4);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
  	;

constraint_rat_pair_list:
	constraint_rat_pair_list ',' constraint_rat_pair
		{ }
	| constraint_rat_pair
		{  }
	;
	
constraint_rat_pair: 
  	'(' linearexpr ',' linearexpr ')' 
		{ 
		
		}
	|  '(' linearexpr ',' linearexpr ',' linearexpr ')' 
		{ 
		
		}
	;
	

val_set:
	val_set '&' val_set
		{	
			$$=new vector<string>();	
			for(vector<string>::iterator it=$1->begin();it!=$1->end();it++)
			{
				$$->push_back(*it);
			}
			for(vector<string>::iterator it=$3->begin();it!=$3->end();it++)
			{
				$$->push_back(*it);
			}
		}
	| '(' val_set ')' 
		{
			//$$=$2;
			$$=new vector<string>();
			(*$$)=(*$2);
		}
	//| constr_list_no_and
	| constr_list_no_and
		{
			$$=new vector<string>();
			(*$$).push_back(*$1);
			
		}
	;


constr_list:
	constr_list '&' constr_list
		{ 
			$$=new vector<string>();
			for(vector<string>::iterator it=$1->begin();it!=$1->end();it++)
			{
				$$->push_back(*it);
			}
			for(vector<string>::iterator it=$3->begin();it!=$3->end();it++)
			{
				$$->push_back(*it);
			}
		}
   
   	| constr_list_no_and
		{
			$$=new vector<string>();
			$$->push_back(*$1);
		}
	;

constr_list_no_and:
   	constraint
		{
			string *s=new string();
			(*s)=(*$1); 
			//$$=$1;
			$$=s;
		}
   	/*| linearexpr LE linearexpr LE linearexpr	
		{
			string s=$1->append("<=").append($3->c_str()).append("<=").append($5->c_str());
			$$=&s;
         	}   
   	| linearexpr '<' linearexpr LE linearexpr	
		{
			string s=$1->append("<").append($3->c_str()).append("<=").append($5->c_str());
			$$=&s;
		}   
	| linearexpr LE linearexpr '<' linearexpr	
		{
			string s=$1->append("<=").append($3->c_str()).append("<").append($5->c_str());
			$$=&s;
                }
   	| linearexpr '<' linearexpr '<' linearexpr	
		{
			string s=$1->append("<").append($3->c_str()).append("<").append($5->c_str());
         		$$=&s;
		}            	
*/
   	;
   
   
constraint:
	linearexpr '<' linearexpr	
		{
			//cout<<"l:"<<(*$1)<<" r:"<<(*$3)<<endl;
			string s=$1->append(" < ").append($3->c_str());
		
			string *m=new string();
			(*m)=s;
			//cout<<"Constraint:"<<s<<endl;
			//$$=&s;
			$$=m;
		}
	| linearexpr '>' linearexpr	
		{
			string s=$1->append(" > ").append($3->c_str());
			//cout<<"Constraint:"<<s<<endl;
			
			string *m=new string();
			(*m)=s;
			//$$=&s;
			$$=m;
		}
	| linearexpr GE linearexpr		
		{
			string s=$1->append(" >= ").append($3->c_str());
			//cout<<"Constraint:"<<s<<endl;

			string *m=new string();
			(*m)=s;

			//$$=&s;
			$$=m;
		}
	| linearexpr LE linearexpr	
		{
			string s=$1->append(" <= ").append($3->c_str());
			//cout<<"Constraint:"<<s<<endl;
			string *m=new string();
			(*m)=s;

			//$$=&s;
			$$=m;
		}
	| linearexpr EQ linearexpr	
		{
			//cout<<"Got:"<<(*$3)<<endl;
			string s=$1->append(" == ").append($3->c_str());
			//cout<<"Constraint:"<<s<<endl;
			string *m=new string();
			(*m)=s;

			//$$=&s;
			$$=m;
		}
	| TRUE
    		{
			//cout<<"Here"<<endl;
			string *s=new string("true");
			$$=s;
		}
	| FALSE
    		{
			string *s=new string("false");
			$$=s;
		}
	;


linearexpr:
	INT			
		{
			string *s=new string();
			(*s)=(*$1);
			//$$=$1;	
			$$=s;
		}
	| IDENT PRIM
		{
			string *s=new string();
			(*s)=(*$1);
			//string s=$1->append("'");
			//$$=&s;
			//$$=$1;	
			$$=s;
		}	
	| IDENT
	 	{ 
			string *s=new string();
			(*s)=(*$1);
			//$$=$1;
			$$=s;
      		}
	| linearexpr '*' linearexpr
      		{
			//cout<<*$1<<" bata "<<*$3<<endl;
			string t=$1->append(" * ").append($3->c_str()); 
			string *m=new string();
			(*m)=t;
			//cout<<"New:"<<t<<endl;
			$$=m;
      		}
	| linearexpr '/' linearexpr
      		{ 
			string s=$1->append(" / ").append($3->c_str());
			string *m=new string();
			(*m)=s;
			//$$=&s;
			$$=m;
      		}
	| linearexpr '+' linearexpr		
		{
			//cout<<"here:"<<*$1<<" + "<<*$3<<endl;
			string s=$1->append(" + ").append($3->c_str());
			
			string *m=new string();
			(*m)=s;

			//$$=&s;
			$$=m;
		}
	| linearexpr '-' linearexpr		
		{
			string s=$1->append(" - ").append($3->c_str());


			string *m=new string();
			(*m)=s;

			//$$=&s;
			$$=m;
		}
	| '-' linearexpr	%prec  '*'
		{
			string *minus=new string("-");
			string s=minus->append($2->c_str()); 
			//cout<<"Here"<<s<<endl;
			string *m=new string();
			(*m)=s;
			//$$=&s;
			$$=m;
		}
	| '(' linearexpr ')' 
		{
			string *opencurly=new string("( ");
			string *closedcurly=new string(" )");
			string s=opencurly->append($2->c_str()).append(closedcurly->c_str());

			string *m=new string();
			(*m)=s;
			$$=m;
			//$$=&s;
			//$$=$2;
		}
	;



%%
int main (void) {
	return yyparse();
	}

/* Added because panther doesn't have liby.a installed. */
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
	}

