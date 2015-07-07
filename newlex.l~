%option yylineno
%{
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#include "y.tab.h"


//extern int yylval;
void yyerror(char *);
unsigned int line_number=1;
char* outchar;
char* mychars;
%}
DIGIT      [0-9]
LETTER     [a-zA-Z]

%%
"merge_splitted" { return MERGE_SPLITTED; }
"ASAP" { return ASAP; }
"priority" { return PRIORITY; }
"USE_HIOA_AUTOMATA" { return par_USE_HIOA_AUTOMATA; }
"compose" { return COMPOSE;}
"CREATION_GRAPH_OUTPUT" {return par_CREATION_GRAPH_OUTPUT;}
"MEMORY_MODE" {return par_MEMORY_MODE;}
"LIMIT_CONSTRAINTS_METHOD" {return par_LIMIT_CONSTRAINTS_METHOD;}
"TIME_POST_LAMBDA" {return par_TIME_POST_LAMBDA;}
"TIME_POST_CONE_ITER" {return par_TIME_POST_CONE_ITER;}
"project_to" {return PROJECT_TO;}
"rename" {return RENAME;}
"difference_assign" {return DIFFERENCE_ASSIGN;}
"REFINE_MAX_CHECKS" {return par_REFINE_MAX_CHECKS;}
"is_reachable_DHR" {return IS_REACHABLE_DHR;}
"DHR_THRESHOLD" {return par_DHR_THRESHOLD;}
"set_DHR_vars" {return SET_DHR_VARS;}
"REFINE_LOCATION_PLANE" {return par_REFINE_LOCATION_PLANE;}
"REFINE_INTERSECT_METHOD" {return par_REFINE_INTERSECT_METHOD;}
"REACH_FB_REFINE_METHOD" {return par_REACH_FB_REFINE_METHOD;}
"is_reachable_fb" {return IS_REACHABLE_FB;}
"is_reachable_bk" {return IS_REACHABLE_BK;}
"is_reachable_by_dfs_fb" {return IS_REACHABLE_BY_DFS_FB;}
"is_reachable_by_bfs_fb" {return IS_REACHABLE_BY_BFS_FB;}
"is_reachable_by_dfs_bk" {return IS_REACHABLE_BY_DFS_BK;}
"is_reachable_by_bfs_bk" {return IS_REACHABLE_BY_BFS_BK;}
"to_ICTA" {return TO_ICTA;}
"to_Region_Automata" {return TO_REGION_AUTOMATA;}
"is_reachable" {return IS_REACHABLE;}
"invariant_assign" {return INVARIANT_ASSIGN;}
"reverse" {return REVERSE;}
"SNAPSHOT_INTERVAL" {return par_SNAPSHOT_INTERVAL;}
"REFINE_PARTITION_INSIDE" {return par_REFINE_PARTITION_INSIDE;}
"reachable_forward_iter" {return REACH_FORWARD_ITER;}
"unlock_surface_locs" {return UNLOCK_SURFACE_LOCS;}
"unlock_locs" {return UNLOCK_LOCS;}
"get_invariants" {return GET_INVARIANTS;}
"print_graph" {return PRINT_GRAPH;}
"REFINE_CHECK_TIME_RELEVANCE" {return par_REFINE_CHECK_TIME_RELEVANCE;}
"REFINE_CHECK_TIME_RELEVANCE_DURING" {return par_REFINE_CHECK_TIME_RELEVANCE_DURING;}
"REFINE_CHECK_TIME_RELEVANCE_FINAL" {return par_REFINE_CHECK_TIME_RELEVANCE_FINAL;}
"REFINE_CHECK_TRANS_DIMS" {return par_REFINE_CHECK_TRANS_DIMS;}
"PARTITION_CHECK_TIME_RELEVANCE" {return par_REFINE_CHECK_TIME_RELEVANCE;}
"PARTITION_CHECK_TIME_RELEVANCE_DURING" {return par_REFINE_CHECK_TIME_RELEVANCE_DURING;}
"PARTITION_CHECK_TIME_RELEVANCE_FINAL" {return par_REFINE_CHECK_TIME_RELEVANCE_FINAL;}
"PARTITION_CHECK_TRANS_DIMS" {return par_REFINE_CHECK_TRANS_DIMS;}
"SEARCH_METHOD" {return par_SEARCH_METHOD;}
"project_to_first" {return PROJECT_TO_FIRST;}
"get_inverse" {return INVERSE;}
"contains" {return CONTAINS;}
"TIME_POST_ITER" {return par_TIME_POST_ITER;}
"REACH_CONSTRAINT_TRIGGER" {return par_REACH_CONSTRAINT_TRIGGER;}
"REACH_BITSIZE_TRIGGER" {return par_REACH_BITSIZE_TRIGGER;}
"REFINE_PRIORITIZE_ANGLE" {return par_REFINE_PRIORITIZE_ANGLE;}
"REFINE_DERIV_MINANGLE" {return par_REFINE_DERIV_MINANGLE;}
"PARTITION_PRIORITIZE_ANGLE" {return par_REFINE_PRIORITIZE_ANGLE;}
"PARTITION_DERIV_MINANGLE" {return par_REFINE_DERIV_MINANGLE;}
"REACH_STOP_USE_BITSIZE" {return par_REACH_STOP_USE_BITSIZE;}
"REACH_CONSTRAINT_LIMIT" {return par_REACH_CONSTRAINT_LIMIT;}
"TP_CONSTRAINT_LIMIT" {return par_TP_CONSTRAINT_LIMIT;}
"REFINE_USE_FP" {return par_REFINE_USE_FP;}
"REFINE_PRIORITIZE_REACH_SPLIT" {return par_REFINE_PRIORITIZE_REACH_SPLIT;}
"REFINE_SMALLEST_FIRST" {return par_REFINE_SMALLEST_FIRST;}
"PARTITION_PRIORITIZE_REACH_SPLIT" {return par_REFINE_PRIORITIZE_REACH_SPLIT;}
"PARTITION_SMALLEST_FIRST" {return par_REFINE_SMALLEST_FIRST;}
"REACH_STOP_USE_CONVEX_HULL_SETTLE" {return par_REACH_STOP_USE_CONVEX_HULL_SETTLE;}
"REACH_STOP_USE_CONVEX_HULL_ITER" {return par_REACH_STOP_USE_CONVEX_HULL_ITER;}
"REACH_USE_BBOX_ITER" {return par_REACH_USE_BBOX_ITER;}
"set_refine_constraints" {return REFINE_CONSTRAINTS;}
"set_partition_constraints" {return REFINE_CONSTRAINTS;}
"save_fp_invars" {return SAVE_FP_INVARS;}
"save_fp_surface_inv" {return SAVE_FP_SURFACE;}
"initial_states" {return INITIAL_STATES;}
"refine_locs" {return REFINE_LOCS;}
"refine_loc_deriv" {return REFINE_LOC_DERIV;}
"ELAPSE_TIME" {return par_ELAPSE_TIME;}
"CHEAP_CONTAIN_RETURN_OTHERS" {return par_CHEAP_CONTAIN_RETURN_OTHERS;}
"REACH_USE_CONSTRAINT_HULL" {return par_USE_CONSTRAINT_HULL;}
"REACH_USE_CONVEX_HULL" {return par_USE_CONVEX_HULL;}
"REACH_STOP_AT_FORB" {return par_REACH_STOP_AT_FORB;}
"REACH_ONLY_EXPLORE" {return par_REACH_ONLY_EXPLORE;}
"REACH_USE_BBOX" {return par_REACH_USE_BBOX;}
"REACH_MAX_ITER" {return par_REACH_MAX_ITER;}
"BOUND_BOX_BITSIZE" {return par_BOUND_BOX_BITSIZE;}
"CONSTRAINT_BITSIZE" {return par_CONSTRAINT_BITSIZE;}
"REFINE_DERIVATIVE_METHOD" {return par_REFINE_DERIVATIVE_METHOD;}
"SIM_USE_CONVEX_HULL_FOR_PRIMING" {return par_USE_CONVEX_HULL_FOR_PRIMING;}
"SIM_PRIME_WITH_REACH" {return par_PRIME_R_WITH_REACH;}
"SIM_PRIME_R_WITH_DISCRETE_REACH" {return par_PRIME_R_WITH_DISCRETE_REACH;}
"SIM_SIMPLIFY_R" {return par_SIM_SIMPLIFY_R;}
"SHOW_BAD_STATES" {return par_SHOW_BAD_STATES;}
"MINIM_USE_CONVEX_HULL_FOR_PRIMING" {return par_MINIM_USE_CONVEX_HULL_FOR_PRIMING;}
"MINIM_PRIME_R_WITH_REACH" {return par_MINIM_PRIME_R_WITH_REACH;}
"COMPOSE_WITH_REACH_MIN" {return par_COMPOSE_WITH_REACH_MIN;}
"COMPOSE_USE_CONVEX_HULL_FOR_REACH" {return par_COMPOSE_USE_CONVEX_HULL_FOR_REACH;}
"get_sim" {return GET_SIM;}
"is_empty" {return IS_EMPTY;}
"intersection_assign" {return INTERSECTION_ASSIGN;}
"loc_intersection" {return LOC_INTERSECTION;}
"loc_union" {return LOC_UNION;}
"remove" {return REMOVE;}
"echo" {return ECHO;}
"get_parameters" {return GET_PARAMETERS;}
"is_sim" {return IS_SIM;}
"is_bisim" {return IS_BISIM;}
"agc_sim" {return AGCSIM;}
"ag_sim" {return AGSIM;}
"print" {return PRINT;}
"save_gen_fp" {return SAVE_GEN_FP;}
"save_con_fp" {return SAVE_CON_FP;}
"reachable" {return REACH;}
"define" {return DEFNE;}
"hybridautomaton" {return HYBRIDAUTOMATON;}
"timedautomaton" {return TIMEDAUTOMATON;}
"automaton" {return AUTOMATON;}
"state_var" {return INTERNAL_VAR;}
"contr_var" {return INTERNAL_VAR;}
"input_var" {return EXTERNAL_VAR;}
"parameter" {return PARAMETER;}
"synclabs" {return SYNCLABS;}
"initially" {return INITIALLY;}
"loc" {return LOC;}
"while" {return WHILE;}
"wait"  {return WAIT;}
"when" {return WHEN;}
"do"   {return DO;}
"sync" {return SYNC;}
"goto" {return GOTO;}
"end"   {return END;}
"true"  {return TRUE;}
"True"  {return TRUE;}
"TRUE"  {return TRUE;}
"false"  {return FALSE;}
"False"  {return FALSE;}
"FALSE"  {return FALSE;}
"who" {return WHO;}
"add_label" {return ADD_LABEL;}
"add_aut" {return ADD_AUT;}
"to_aut_str" {return TO_AUT_STR;}
"take_composition" {return TAKE_COMPOSITION;}
"icta_to_timedaut_for_existential" {return ICTA_TO_TIMEDAUT_FOR_EXISTENTIAL;}
"maxiterations" {return MAXITERATIONS;}
"hybrid_flavoured_timed_aut_to_timed_aut" {return HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT;}
"to_dot" {return TO_DOT;}

  /* rules for operators */

"==" {return EQ;}
">=" {return GE;}
"<=" {return LE;}
"'"  {return PRIM;}
":=" {return ASSIGN;}

  /* rules for float */
  
([0-9]+)(("."[0-9]+)?)((([eE])([+-]?)([0-9]+))?)  {  yylval.str=new string(yytext); /*cout<<"INT:"<<*(yylval.str)<<endl;*/ /*yylval.mystring = strdup(yytext);*/ return INT;}
  

  
[-+<>*/&|(){}:;,.=!]|"["|"]" {return *yytext;}



(["$""?"a-zA-Z]|[_])("$"|"?"|[a-zA-Z]|[0-9]|[_]|[~])* { yylval.str=new string(yytext); /*cout<<"IDENT:"<<*(yylval.str)<<endl;*/ /*yylval.mystring = strdup(yytext); cout<<yylval.mystring<<endl;*/ return IDENT; }

  /* rules for comments */
  
"/*"([^*]|("*"+[^*/]))*"*"+"/" /* skip comment */
"//".*                         /* skip comment XS*/
"--".*                         /* skip comment */

  /* rules for quoted strings */
  
\"(.*)\" {
    /*yylval.mystring = strdup(yytext+1);
    yylval.mystring[strlen(yylval.mystring)-1]= '\0';*/
    yylval.str=new string(yytext+1,yytext+strlen(yytext)-1);
    //cout<<"String text:"<<*(yylval.str)<<endl;
    return STRING_TEXT;}

  /* rule for whitespace */

[\n] { ++line_number; 
//cout << line_number << endl << flush;
}
[ \t\r]                        /* \r skip whitespace */

. { //outchar=strcat("invalid character",strdup(yytext));
    outchar=strdup(yytext);
    yyerror(outchar);}
