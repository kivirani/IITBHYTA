#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "newyacc.y"
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

/*Automaton_List aut_lst;*/

enum TYPE{NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL};
map<string,TYPE> varmap; 

map<string,AutomatonStr*> autstrmap;
map<string,Automaton*> autmap;

map<string,vector<AutomatonStr> > vautstrmap;

map<string,AutomatonStr*> hybridautstrmap;
map<string,Automaton*> hybridautmap;

/*map<string,vector<string> > autToVCntrVar;*/
/*map<string,vector<string> > autToVInVar;*/


map<string,vector<AutomatonStr> > vhybridautstrmap;


map<string,AutomatonStr*> timedautstrmap;
map<string,Automaton*> timedautmap;
/*map<string,vector<string> > timedautToVCntrVar;*/
/*map<string,vector<string> > timedautToVInVar;*/

map<string,vector<AutomatonStr> > vtimedautstrmap;



/*map<string,AutomatonStr*> autstrmap;*/
/*map<string,Automaton*> autmap;*/

/*map<string,vector<string> > regionautToVCntrVar;*/
/*map<string,vector<string> > regionautToVInVar;*/


map<string,Automaton*> ictahybridmap;
map<string,Automaton*> ictamap;

/*map<string,vector<string> > icTAToVCntrVar;*/
/*map<string,vector<string> > icTAToVInVar;*/


map<string,vector<string> > valsetstrmap;

map<string,string> statestrmap;

map<string,pair<string,vector<string> > > symstatestrmap;

map<string,bool> boolmap;


int maxiterations=12;
#line 73 "newyacc.y"
typedef union{
 char * mystring;
 vector<string> *strv;
 string *str;
} YYSTYPE;
#line 83 "y.tab.c"
#define MERGE_SPLITTED 257
#define ASAP 258
#define PRIORITY 259
#define par_USE_HIOA_AUTOMATA 260
#define par_CREATION_GRAPH_OUTPUT 261
#define par_TIME_POST_LAMBDA 262
#define par_TIME_POST_CONE_ITER 263
#define par_TIME_POST_ITER 264
#define par_ELAPSE_TIME 265
#define par_BOUND_BOX_BITSIZE 266
#define par_CONSTRAINT_BITSIZE 267
#define par_REACH_STOP_USE_BITSIZE 268
#define par_MEMORY_MODE 269
#define par_CHEAP_CONTAIN_RETURN_OTHERS 270
#define par_USE_CONVEX_HULL 271
#define par_USE_CONSTRAINT_HULL 272
#define par_REACH_STOP_AT_FORB 273
#define par_REACH_ONLY_EXPLORE 274
#define par_REACH_USE_BBOX 275
#define par_REACH_MAX_ITER 276
#define par_REACH_USE_BBOX_ITER 277
#define par_REACH_STOP_USE_CONVEX_HULL_ITER 278
#define par_REACH_STOP_USE_CONVEX_HULL_SETTLE 279
#define par_REACH_CONSTRAINT_LIMIT 280
#define par_LIMIT_CONSTRAINTS_METHOD 281
#define par_TP_CONSTRAINT_LIMIT 282
#define par_REACH_CONSTRAINT_TRIGGER 283
#define par_REACH_BITSIZE_TRIGGER 284
#define par_SEARCH_METHOD 285
#define par_SNAPSHOT_INTERVAL 286
#define par_USE_CONVEX_HULL_FOR_PRIMING 287
#define par_PRIME_R_WITH_REACH 288
#define par_SHOW_BAD_STATES 289
#define par_SIM_SIMPLIFY_R 290
#define par_PRIME_R_WITH_DISCRETE_REACH 291
#define par_MINIM_USE_CONVEX_HULL_FOR_PRIMING 292
#define par_MINIM_PRIME_R_WITH_REACH 293
#define COMPOSE 294
#define par_COMPOSE_WITH_REACH_MIN 295
#define par_COMPOSE_USE_CONVEX_HULL_FOR_REACH 296
#define par_REFINE_DERIVATIVE_METHOD 297
#define par_REFINE_PRIORITIZE_REACH_SPLIT 298
#define par_REFINE_SMALLEST_FIRST 299
#define par_REFINE_USE_FP 300
#define par_REFINE_DERIV_MINANGLE 301
#define par_REFINE_PRIORITIZE_ANGLE 302
#define par_REFINE_CHECK_TIME_RELEVANCE 303
#define par_REFINE_CHECK_TIME_RELEVANCE_DURING 304
#define par_REFINE_CHECK_TIME_RELEVANCE_FINAL 305
#define par_REFINE_CHECK_TRANS_DIMS 306
#define par_REFINE_PARTITION_INSIDE 307
#define par_REACH_FB_REFINE_METHOD 308
#define par_REFINE_INTERSECT_METHOD 309
#define par_REFINE_LOCATION_PLANE 310
#define SET_DHR_VARS 311
#define par_DHR_THRESHOLD 312
#define IS_REACHABLE_BY_DFS_FB 313
#define IS_REACHABLE_BY_BFS_FB 314
#define IS_REACHABLE_BY_DFS_BK 315
#define IS_REACHABLE_BY_BFS_BK 316
#define IS_REACHABLE_FB 317
#define IS_REACHABLE_DHR 318
#define par_REFINE_MAX_CHECKS 319
#define PROJECT_TO 320
#define DIFFERENCE_ASSIGN 321
#define RENAME 322
#define IS_REACHABLE 323
#define INVARIANT_ASSIGN 324
#define REVERSE 325
#define SAVE_FP_SURFACE 326
#define REACH_FORWARD_ITER 327
#define UNLOCK_SURFACE_LOCS 328
#define UNLOCK_LOCS 329
#define GET_INVARIANTS 330
#define PRINT_GRAPH 331
#define PROJECT_TO_FIRST 332
#define INVERSE 333
#define CONTAINS 334
#define REFINE_CONSTRAINTS 335
#define ADD_LABEL 336
#define WHO 337
#define SAVE_FP_INVARS 338
#define INITIAL_STATES 339
#define REFINE_LOCS 340
#define REFINE_LOC_DERIV 341
#define GET_SIM 342
#define IS_EMPTY 343
#define INTERSECTION_ASSIGN 344
#define LOC_INTERSECTION 345
#define LOC_UNION 346
#define REMOVE 347
#define STRING_TEXT 348
#define ECHO 349
#define GET_PARAMETERS 350
#define IS_SIM 351
#define IS_BISIM 352
#define AGSIM 353
#define AGCSIM 354
#define PRINT 355
#define SAVE_CON_FP 356
#define SAVE_GEN_FP 357
#define REACH 358
#define REACH_STOP 359
#define DEFNE 360
#define HYBRIDAUTOMATON 361
#define TIMEDAUTOMATON 362
#define AUTOMATON 363
#define INTERNAL_VAR 364
#define EXTERNAL_VAR 365
#define PARAMETER 366
#define SYNCLABS 367
#define INITIALLY 368
#define LOC 369
#define WHILE 370
#define WAIT 371
#define WHEN 372
#define DO 373
#define SYNC 374
#define GOTO 375
#define END 376
#define TRUE 377
#define FALSE 378
#define ASSIGN 379
#define IS_REACHABLE_BK 380
#define TO_ICTA 381
#define TO_DOT 382
#define TO_REGION_AUTOMATA 383
#define ADD_AUT 384
#define TO_AUT_STR 385
#define TAKE_COMPOSITION 386
#define ICTA_TO_TIMEDAUT_FOR_EXISTENTIAL 387
#define MAXITERATIONS 388
#define HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT 389
#define IDENT 390
#define INT 391
#define GE 392
#define LE 393
#define EQ 394
#define PRIM 395
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,   10,   10,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   16,   13,   17,   12,
   18,   14,   15,   19,   19,   19,   19,   19,   22,   23,
   24,   25,    2,    2,    3,    3,    4,    4,    1,    1,
   21,   21,   26,   26,   26,   26,   20,   20,   20,   20,
   27,   27,   28,   28,   29,   29,   29,   30,   30,   31,
   31,    5,    5,    5,    6,    6,    7,    8,    8,    8,
    8,    8,    8,    8,    9,    9,    9,    9,    9,    9,
    9,    9,    9,
};
short yylen[] = {                                         2,
    1,    2,    1,    1,    1,    1,    7,    4,    4,    4,
    6,    6,    7,    7,    4,    4,    9,    9,    9,    9,
    9,    9,    9,    7,    7,    7,    0,    5,    0,    5,
    0,    5,    3,    0,    2,    2,    2,    2,    4,    4,
    4,    4,    3,    1,    3,    1,    3,    1,    3,    1,
    4,    3,    3,    1,    3,    5,    3,    4,    2,    3,
    9,    5,    2,    0,   11,   11,    7,    3,    1,    5,
    7,    3,    3,    1,    3,    1,    1,    3,    3,    3,
    3,    3,    1,    1,    1,    2,    1,    3,    3,    3,
    3,    2,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    3,    4,    5,
    6,   27,   31,   29,    0,    0,    0,    2,   34,   34,
   34,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   84,    0,    0,    0,    0,    0,    0,    0,   85,    0,
    0,    0,   74,   77,    0,    0,    0,    0,    0,    0,
    0,    0,   10,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   86,   15,    0,
    0,   92,    0,    0,    0,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,    9,    0,   28,    0,
    0,    0,    0,    0,    0,   35,   36,   37,   38,    0,
   32,   30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   73,   93,   72,
    0,    0,    0,    0,    0,    0,    0,   88,   89,    0,
    0,    0,    0,    0,    0,    0,   33,    0,   64,    0,
    0,    0,    0,    0,    0,    0,   12,    0,    0,    0,
    0,    0,    0,   11,    0,   44,    0,   46,    0,   48,
    0,   50,    0,    0,    0,    0,    0,   64,    0,    0,
    0,   63,    0,    0,    0,    0,    0,    0,    0,   24,
   26,   14,   13,   25,    7,   39,    0,   40,    0,   42,
    0,   41,    0,    0,    0,    0,   52,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   43,   45,   47,
   49,    0,    0,   51,    0,    0,    0,   17,   18,   19,
   20,   22,   21,   23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   76,    0,    0,    0,    0,   61,
    0,    0,   67,   75,    0,    0,    0,    0,    0,    0,
   66,   65,
};
short yydgoto[] = {                                       6,
  163,  157,  159,  161,   42,  234,   43,   44,   45,    7,
    8,    9,   10,   11,   49,   19,   21,   20,   50,   95,
  137,   96,   97,   98,   99,  167,  100,  140,  172,    0,
    0,
};
short yysindex[] = {                                   -332,
 -294, -282, -278, -260,  -43,    0, -332,    0,    0,    0,
    0,    0,    0,    0, -266,   48, -303,    0,    0,    0,
    0,   73,   97,  101,  110,  112,  119,  122,  148,    0,
    0,  147,  149,  152,  153,  154,  155,  -38,    0,  -39,
   30,    3,    0,    0,   12,  129,  137,  158, -177, -209,
 -176, -175,    0, -187, -185, -184, -183, -182, -181, -180,
 -178, -174, -173, -172, -171, -169, -166,    0,    0, -193,
  -39,    0,    2,    6,   30,    0,  -39,  -39,  -39,  -39,
  -39,  -39,  -39,  -39,  -39,    0,    0, -165,    0,  156,
  157,  168,  170, -161, -247,    0,    0,    0,    0,  171,
    0,    0,  169,  187,  188,  190,  191,  192,  178,  194,
  198,  199,  200,  201,  202,  185,  106,    0,    0,    0,
  121,  121,  121,  121,  121,  -15,  -15,    0,    0,  204,
 -144, -143, -142, -141,  193,  -36,    0,  195,    0, -122,
 -138, -137, -135, -134, -133, -131,    0, -130,  203,  205,
  206,  207,  208,    0,  209,    0,  -21,    0,   -9,    0,
   36,    0,   39, -112,  223, -127,   41,    0, -122, -122,
   30,    0,  228,  229,  230,  231,  232,  233,  234,    0,
    0,    0,    0,    0,    0,    0, -114,    0, -113,    0,
 -111,    0, -110,   30,   30,   42,    0, -109, -122,  -24,
  219,  224,  225,  226,  227,  235,  236,    0,    0,    0,
    0,  -18,  244,    0,  249,  165, -101,    0,    0,    0,
    0,    0,    0,    0,  167,   30,   30, -231,   33,  244,
  -33,  173,  -99,  -22,    0,  -82,   30,  238,   33,    0,
  -97,  -14,    0,    0,  -77,  -76,  -90,  -89,  243,  245,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,  303,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -34,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -254,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   72,   79,   86,   95,  102,  -26,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -254,    0, -240,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   43,    0,    0,    0, -199, -188,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -186,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -57,   45,    0,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,    0,   -4,   66, -132,    0,   94,    0,
  299,    0,    0,    0,  164,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  141,  213,  -62,    0,    0,
    0,
};
#define YYTABLESIZE 476
short yytable[] = {                                      67,
   71,   62,   17,   87,   75,   40,   87,   87,   87,   87,
   87,   90,   87,   75,   90,  239,   90,   90,   90,   75,
   69,  166,  187,   75,   87,   87,   84,   87,    1,    2,
    3,   85,   90,   90,  189,   90,   73,  186,   91,   75,
   75,   91,  118,   91,   91,   91,  119,   84,   82,  188,
   83,   46,   85,   84,   82,    4,   83,    5,   85,   91,
   91,   76,   91,   87,   87,   80,   87,   81,   87,   41,
  120,   80,   71,   81,   40,  169,  170,   40,   47,  191,
   48,   87,  193,   87,  198,  198,   54,   41,   53,   55,
   87,  236,   40,   56,  190,   12,  235,  192,   90,  197,
  214,   54,  240,   53,   55,  199,  235,   13,   56,   80,
  246,   14,   80,   64,   64,   80,   81,   64,   15,   81,
  136,   94,   81,   82,   22,   91,   82,   59,   59,   82,
   80,   53,   78,   72,   74,   78,   54,   81,   78,   79,
   55,  232,   79,  233,   82,   79,  119,   84,   82,   56,
   83,   57,   85,   78,   90,   91,   92,   93,   58,   94,
   79,   59,   84,   82,  117,   83,  200,   85,   57,   57,
  121,  122,  123,  124,  125,  126,  127,  128,  129,   60,
   60,   58,   58,   51,   52,   60,   61,   86,   62,  212,
  213,   63,   64,   65,   66,   87,   80,   88,   89,  101,
  102,   68,  103,   81,  104,  105,  106,  107,  108,  109,
   82,  110,  141,  131,  132,  111,  112,  113,  114,   78,
  115,  230,  231,  116,  130,  133,   79,  134,  135,  139,
  142,  143,  242,  144,  145,  146,  147,  148,  149,  150,
  151,  152,  153,  154,  155,  156,  158,  160,  162,  171,
  164,  173,  174,  168,  175,  176,  177,  194,  178,  179,
  195,  180,  165,  181,  182,  183,  184,  185,  201,  202,
  203,  204,  205,  206,  207,  208,  209,  218,  210,  211,
  215,   75,  219,  220,  221,  222,  226,  227,  228,  229,
  238,  241,  245,  223,  224,  237,  243,  247,  248,  249,
  250,  251,    1,  252,  244,   18,  196,  138,    0,    0,
   62,   62,    0,    0,   62,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   87,   87,   16,   87,   87,   87,   87,
    0,   90,   90,    0,   90,   90,   90,   90,  216,  217,
   70,   39,  225,  165,    0,    0,   68,   87,   87,   87,
   23,   24,   25,   26,   27,   90,   90,   90,   91,   91,
   28,   91,   91,   91,   91,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   91,   91,   91,   29,    0,   77,   78,   79,
    0,    0,    0,   77,   78,   79,   30,   31,    0,   30,
   31,    0,    0,   87,   87,   87,    0,    0,    0,   70,
   39,    0,   70,   39,   30,   31,    0,   32,   33,    0,
   34,    0,   35,   36,    0,    0,   37,   38,   39,   80,
   80,    0,   80,   80,   80,   80,   81,   81,    0,   81,
   81,   81,   81,   82,   82,    0,   82,   82,   82,   82,
    0,    0,   78,   78,    0,   78,   78,   78,   78,   79,
   79,    0,   79,   79,   79,   79,
};
short yycheck[] = {                                      38,
   40,   59,   46,   38,   38,   45,   41,   42,   43,   44,
   45,   38,   47,   38,   41,   38,   43,   44,   45,   38,
   59,   58,   44,   38,   59,   60,   42,   62,  361,  362,
  363,   47,   59,   60,   44,   62,   41,   59,   38,   38,
   38,   41,   41,   43,   44,   45,   41,   42,   43,   59,
   45,  355,   47,   42,   43,  388,   45,  390,   47,   59,
   60,   59,   62,   42,   43,   60,   45,   62,   47,   40,
   75,   60,   40,   62,   45,  138,  139,   45,  382,   44,
  384,   60,   44,   62,   44,   44,   44,   40,   44,   44,
  125,  125,   45,   44,   59,  390,  229,   59,  125,   59,
   59,   59,  125,   59,   59,  168,  239,  390,   59,   38,
  125,  390,   41,  368,  369,   44,   38,  372,  379,   41,
  368,  369,   44,   38,  391,  125,   41,  368,  369,   44,
   59,   59,   38,   40,   41,   41,   40,   59,   44,   38,
   40,  373,   41,  375,   59,   44,   41,   42,   43,   40,
   45,   40,   47,   59,  364,  365,  366,  367,   40,  369,
   59,   40,   42,   43,   71,   45,  171,   47,  368,  369,
   77,   78,   79,   80,   81,   82,   83,   84,   85,  368,
  369,  368,  369,   20,   21,   38,   40,   59,   40,  194,
  195,   40,   40,   40,   40,   59,  125,   40,  376,  376,
  376,  395,  390,  125,  390,  390,  390,  390,  390,  390,
  125,  390,   44,   58,   58,  390,  390,  390,  390,  125,
  390,  226,  227,  390,  390,   58,  125,   58,  390,   59,
   44,   44,  237,   44,   44,   44,   59,   44,   41,   41,
   41,   41,   41,   59,   41,  390,  390,  390,  390,  372,
   58,  390,  390,   59,  390,  390,  390,  370,  390,  390,
   38,   59,  390,   59,   59,   59,   59,   59,   41,   41,
   41,   41,   41,   41,   41,  390,  390,   59,  390,  390,
  390,   38,   59,   59,   59,   59,   38,  123,  390,  123,
  390,  374,  390,   59,   59,  123,   59,  375,  375,  390,
  390,   59,    0,   59,  239,    7,  166,   95,   -1,   -1,
  368,  369,   -1,   -1,  372,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  368,  369,  379,  371,  372,  373,  374,
   -1,  368,  369,   -1,  371,  372,  373,  374,  373,  374,
  390,  391,  371,  390,   -1,   -1,  395,  392,  393,  394,
  313,  314,  315,  316,  317,  392,  393,  394,  368,  369,
  323,  371,  372,  373,  374,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  392,  393,  394,  348,   -1,  392,  393,  394,
   -1,   -1,   -1,  392,  393,  394,  377,  378,   -1,  377,
  378,   -1,   -1,  392,  393,  394,   -1,   -1,   -1,  390,
  391,   -1,  390,  391,  377,  378,   -1,  380,  381,   -1,
  383,   -1,  385,  386,   -1,   -1,  389,  390,  391,  368,
  369,   -1,  371,  372,  373,  374,  368,  369,   -1,  371,
  372,  373,  374,  368,  369,   -1,  371,  372,  373,  374,
   -1,   -1,  368,  369,   -1,  371,  372,  373,  374,  368,
  369,   -1,  371,  372,  373,  374,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 395
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"MERGE_SPLITTED","ASAP","PRIORITY",
"par_USE_HIOA_AUTOMATA","par_CREATION_GRAPH_OUTPUT","par_TIME_POST_LAMBDA",
"par_TIME_POST_CONE_ITER","par_TIME_POST_ITER","par_ELAPSE_TIME",
"par_BOUND_BOX_BITSIZE","par_CONSTRAINT_BITSIZE","par_REACH_STOP_USE_BITSIZE",
"par_MEMORY_MODE","par_CHEAP_CONTAIN_RETURN_OTHERS","par_USE_CONVEX_HULL",
"par_USE_CONSTRAINT_HULL","par_REACH_STOP_AT_FORB","par_REACH_ONLY_EXPLORE",
"par_REACH_USE_BBOX","par_REACH_MAX_ITER","par_REACH_USE_BBOX_ITER",
"par_REACH_STOP_USE_CONVEX_HULL_ITER","par_REACH_STOP_USE_CONVEX_HULL_SETTLE",
"par_REACH_CONSTRAINT_LIMIT","par_LIMIT_CONSTRAINTS_METHOD",
"par_TP_CONSTRAINT_LIMIT","par_REACH_CONSTRAINT_TRIGGER",
"par_REACH_BITSIZE_TRIGGER","par_SEARCH_METHOD","par_SNAPSHOT_INTERVAL",
"par_USE_CONVEX_HULL_FOR_PRIMING","par_PRIME_R_WITH_REACH",
"par_SHOW_BAD_STATES","par_SIM_SIMPLIFY_R","par_PRIME_R_WITH_DISCRETE_REACH",
"par_MINIM_USE_CONVEX_HULL_FOR_PRIMING","par_MINIM_PRIME_R_WITH_REACH",
"COMPOSE","par_COMPOSE_WITH_REACH_MIN","par_COMPOSE_USE_CONVEX_HULL_FOR_REACH",
"par_REFINE_DERIVATIVE_METHOD","par_REFINE_PRIORITIZE_REACH_SPLIT",
"par_REFINE_SMALLEST_FIRST","par_REFINE_USE_FP","par_REFINE_DERIV_MINANGLE",
"par_REFINE_PRIORITIZE_ANGLE","par_REFINE_CHECK_TIME_RELEVANCE",
"par_REFINE_CHECK_TIME_RELEVANCE_DURING",
"par_REFINE_CHECK_TIME_RELEVANCE_FINAL","par_REFINE_CHECK_TRANS_DIMS",
"par_REFINE_PARTITION_INSIDE","par_REACH_FB_REFINE_METHOD",
"par_REFINE_INTERSECT_METHOD","par_REFINE_LOCATION_PLANE","SET_DHR_VARS",
"par_DHR_THRESHOLD","IS_REACHABLE_BY_DFS_FB","IS_REACHABLE_BY_BFS_FB",
"IS_REACHABLE_BY_DFS_BK","IS_REACHABLE_BY_BFS_BK","IS_REACHABLE_FB",
"IS_REACHABLE_DHR","par_REFINE_MAX_CHECKS","PROJECT_TO","DIFFERENCE_ASSIGN",
"RENAME","IS_REACHABLE","INVARIANT_ASSIGN","REVERSE","SAVE_FP_SURFACE",
"REACH_FORWARD_ITER","UNLOCK_SURFACE_LOCS","UNLOCK_LOCS","GET_INVARIANTS",
"PRINT_GRAPH","PROJECT_TO_FIRST","INVERSE","CONTAINS","REFINE_CONSTRAINTS",
"ADD_LABEL","WHO","SAVE_FP_INVARS","INITIAL_STATES","REFINE_LOCS",
"REFINE_LOC_DERIV","GET_SIM","IS_EMPTY","INTERSECTION_ASSIGN",
"LOC_INTERSECTION","LOC_UNION","REMOVE","STRING_TEXT","ECHO","GET_PARAMETERS",
"IS_SIM","IS_BISIM","AGSIM","AGCSIM","PRINT","SAVE_CON_FP","SAVE_GEN_FP",
"REACH","REACH_STOP","DEFNE","HYBRIDAUTOMATON","TIMEDAUTOMATON","AUTOMATON",
"INTERNAL_VAR","EXTERNAL_VAR","PARAMETER","SYNCLABS","INITIALLY","LOC","WHILE",
"WAIT","WHEN","DO","SYNC","GOTO","END","TRUE","FALSE","ASSIGN",
"IS_REACHABLE_BK","TO_ICTA","TO_DOT","TO_REGION_AUTOMATA","ADD_AUT",
"TO_AUT_STR","TAKE_COMPOSITION","ICTA_TO_TIMEDAUT_FOR_EXISTENTIAL",
"MAXITERATIONS","HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT","IDENT","INT","GE",
"LE","EQ","PRIM",
};
char *yyrule[] = {
"$accept : program",
"program : commands",
"commands : commands command",
"commands : command",
"command : automaton",
"command : hybridautomaton",
"command : timedautomaton",
"command : IDENT '.' ADD_AUT '(' IDENT ')' ';'",
"command : IDENT '.' PRINT ';'",
"command : IDENT '.' TO_DOT ';'",
"command : MAXITERATIONS ASSIGN INT ';'",
"command : IDENT ASSIGN IDENT '&' IDENT ';'",
"command : IDENT ASSIGN STRING_TEXT '&' IDENT ';'",
"command : IDENT ASSIGN TAKE_COMPOSITION '(' IDENT ')' ';'",
"command : IDENT ASSIGN TO_AUT_STR '(' IDENT ')' ';'",
"command : IDENT ASSIGN IDENT ';'",
"command : IDENT ASSIGN val_set ';'",
"command : IDENT ASSIGN IS_REACHABLE_BY_DFS_FB '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE_BY_BFS_FB '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE_BY_DFS_BK '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE_BY_BFS_BK '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE_FB '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN IS_REACHABLE_BK '(' IDENT ',' IDENT ')' ';'",
"command : IDENT ASSIGN TO_ICTA '(' IDENT ')' ';'",
"command : IDENT ASSIGN HYBRID_FLAVOURED_TIMED_AUT_TO_TIMED_AUT '(' IDENT ')' ';'",
"command : IDENT ASSIGN TO_REGION_AUTOMATA '(' IDENT ')' ';'",
"$$1 :",
"hybridautomaton : HYBRIDAUTOMATON IDENT $$1 automaton_body END",
"$$2 :",
"automaton : AUTOMATON IDENT $$2 automaton_body END",
"$$3 :",
"timedautomaton : TIMEDAUTOMATON IDENT $$3 automaton_body END",
"automaton_body : declaration location_list initial",
"declaration :",
"declaration : declaration internal_vars",
"declaration : declaration external_vars",
"declaration : declaration synclab",
"declaration : declaration parameters",
"internal_vars : INTERNAL_VAR ':' ivar_list ';'",
"external_vars : EXTERNAL_VAR ':' evar_list ';'",
"synclab : SYNCLABS ':' ident_list ';'",
"parameters : PARAMETER ':' param_list ';'",
"ivar_list : ivar_list ',' IDENT",
"ivar_list : IDENT",
"evar_list : evar_list ',' IDENT",
"evar_list : IDENT",
"param_list : param_list ',' IDENT",
"param_list : IDENT",
"ident_list : ident_list ',' IDENT",
"ident_list : IDENT",
"initial : INITIALLY ':' state_list ';'",
"initial : INITIALLY state_list ';'",
"state_list : IDENT '&' val_set",
"state_list : IDENT",
"state_list : state_list ',' IDENT",
"state_list : state_list ',' IDENT '&' val_set",
"location_list : location_list location transition_list",
"location_list : location_list location ';' transition_list",
"location_list : location transition_list",
"location_list : location ';' transition_list",
"location : LOC IDENT ':' WHILE val_set WAIT '{' constr_list '}'",
"location : LOC IDENT ':' WHILE val_set",
"transition_list : transition_list transition",
"transition_list :",
"transition : WHEN val_set SYNC IDENT DO '{' val_set '}' GOTO IDENT ';'",
"transition : WHEN val_set DO '{' val_set '}' SYNC IDENT GOTO IDENT ';'",
"transition : WHEN val_set SYNC IDENT GOTO IDENT ';'",
"constraint_rat_pair_list : constraint_rat_pair_list ',' constraint_rat_pair",
"constraint_rat_pair_list : constraint_rat_pair",
"constraint_rat_pair : '(' linearexpr ',' linearexpr ')'",
"constraint_rat_pair : '(' linearexpr ',' linearexpr ',' linearexpr ')'",
"val_set : val_set '&' val_set",
"val_set : '(' val_set ')'",
"val_set : constr_list_no_and",
"constr_list : constr_list '&' constr_list",
"constr_list : constr_list_no_and",
"constr_list_no_and : constraint",
"constraint : linearexpr '<' linearexpr",
"constraint : linearexpr '>' linearexpr",
"constraint : linearexpr GE linearexpr",
"constraint : linearexpr LE linearexpr",
"constraint : linearexpr EQ linearexpr",
"constraint : TRUE",
"constraint : FALSE",
"linearexpr : INT",
"linearexpr : IDENT PRIM",
"linearexpr : IDENT",
"linearexpr : linearexpr '*' linearexpr",
"linearexpr : linearexpr '/' linearexpr",
"linearexpr : linearexpr '+' linearexpr",
"linearexpr : linearexpr '-' linearexpr",
"linearexpr : '-' linearexpr",
"linearexpr : '(' linearexpr ')'",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 2629 "newyacc.y"
int main (void) {
	return yyparse();
	}

/* Added because panther doesn't have liby.a installed. */
int yyerror (char *msg) {
	return fprintf (stderr, "YACC: %s\n", msg);
	}

#line 631 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 7:
#line 269 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-6].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];
			switch(t2)
			{
				case AUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=AUTSET;
										
							vautstrmap[*yyvsp[-6].str]=vautstrmap[*yyvsp[-2].str];
						}
						else
						{

							if(t1==AUTSET)
							{
								varmap[*yyvsp[-6].str]=AUTSET;
								vector<AutomatonStr> vautstr;
								for(vector<AutomatonStr>::iterator it=vautstrmap[*yyvsp[-6].str].begin();it!=vautstrmap[*yyvsp[-6].str].end();it++)
								{
									vautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vautstrmap[*yyvsp[-2].str].begin();it!=vautstrmap[*yyvsp[-2].str].end();it++)
								{
									vautstr.push_back(*it);
								}					
								vautstrmap[*yyvsp[-6].str]=vautstr;
							}
						}
					}
					break;
				case AUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=AUTSET;
							vector<AutomatonStr> vautstr;
							vautstr.push_back(*autstrmap[*yyvsp[-2].str]);						
			
							vautstrmap[*yyvsp[-6].str]=vautstr;
						}
						else
						{

							if(t1==AUTSET)
							{
								varmap[*yyvsp[-6].str]=AUTSET;
								vector<AutomatonStr> vautstr;
								for(vector<AutomatonStr>::iterator it=vautstrmap[*yyvsp[-6].str].begin();it!=vautstrmap[*yyvsp[-6].str].end();it++)
								{
									vautstr.push_back(*it);
								}
								vautstr.push_back(*autstrmap[*yyvsp[-2].str]);											
								vautstrmap[*yyvsp[-6].str]=vautstr;
							}
						}	
					}
					break;
				case HYBRIDAUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=HYBRIDAUTSET;
										
							vhybridautstrmap[*yyvsp[-6].str]=vhybridautstrmap[*yyvsp[-2].str];
						}
						else
						{

							if(t1==HYBRIDAUTSET)
							{
								varmap[*yyvsp[-6].str]=HYBRIDAUTSET;
								vector<AutomatonStr> vhybridautstr;
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*yyvsp[-6].str].begin();it!=vhybridautstrmap[*yyvsp[-6].str].end();it++)
								{
									vhybridautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*yyvsp[-2].str].begin();it!=vhybridautstrmap[*yyvsp[-2].str].end();it++)
								{
									vhybridautstr.push_back(*it);
								}					
								vhybridautstrmap[*yyvsp[-6].str]=vhybridautstr;
							}
						}																								
						
					}
					break;
				case HYBRIDAUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=HYBRIDAUTSET;
							vector<AutomatonStr> vhybridautstr;
							vhybridautstr.push_back(*hybridautstrmap[*yyvsp[-2].str]);						
			
							vhybridautstrmap[*yyvsp[-6].str]=vhybridautstr;
						}
						else
						{

							if(t1==HYBRIDAUTSET)
							{
								varmap[*yyvsp[-6].str]=HYBRIDAUTSET;
								vector<AutomatonStr> vhybridautstr;
								for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*yyvsp[-6].str].begin();it!=vhybridautstrmap[*yyvsp[-6].str].end();it++)
								{
									vhybridautstr.push_back(*it);
								}
								vhybridautstr.push_back(*hybridautstrmap[*yyvsp[-2].str]);											
								vhybridautstrmap[*yyvsp[-6].str]=vhybridautstr;
							}
						}						
					}
					break;
				case TIMEDAUTSET:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=TIMEDAUTSET;
										
							vtimedautstrmap[*yyvsp[-6].str]=vtimedautstrmap[*yyvsp[-2].str];
						}
						else
						{

							if(t1==TIMEDAUTSET)
							{
								varmap[*yyvsp[-6].str]=TIMEDAUTSET;
								vector<AutomatonStr> vtimedautstr;
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*yyvsp[-6].str].begin();it!=vtimedautstrmap[*yyvsp[-6].str].end();it++)
								{
									vtimedautstr.push_back(*it);
								}
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*yyvsp[-2].str].begin();it!=vtimedautstrmap[*yyvsp[-2].str].end();it++)
								{
									vtimedautstr.push_back(*it);
								}					
								vtimedautstrmap[*yyvsp[-6].str]=vtimedautstr;
							}
						}					
					}
					break;
				case TIMEDAUTSTR:
					{
						if(t1==NOTYPE)
						{
							varmap[*yyvsp[-6].str]=TIMEDAUTSET;
							vector<AutomatonStr> vtimedautstr;
							vtimedautstr.push_back(*timedautstrmap[*yyvsp[-2].str]);						
			
							vtimedautstrmap[*yyvsp[-6].str]=vtimedautstr;
						}
						else
						{

							if(t1==TIMEDAUTSET)
							{
								varmap[*yyvsp[-6].str]=TIMEDAUTSET;
								vector<AutomatonStr> vtimedautstr;
								for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*yyvsp[-6].str].begin();it!=vtimedautstrmap[*yyvsp[-6].str].end();it++)
								{
									vtimedautstr.push_back(*it);
								}
								vtimedautstr.push_back(*timedautstrmap[*yyvsp[-2].str]);											
								vtimedautstrmap[*yyvsp[-6].str]=vtimedautstr;
							}
						}
					}
					break;
			}
			
		}
break;
case 8:
#line 445 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			/*cout<<"In print:"<<endl;*/
			enum TYPE t=varmap[*yyvsp[-3].str];
			switch(t)
			{
				case AUT:					
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomaton(*autmap[*yyvsp[-3].str]);				 
					break;
				case AUTSTR:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomatonStr(autstrmap[*yyvsp[-3].str]);
					break;
				case AUTSET:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutStrSet(vautstrmap[*yyvsp[-3].str]);				
					break;
				case HYBRIDAUT:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomaton(*hybridautmap[*yyvsp[-3].str]);				 
					break;
				case HYBRIDAUTSTR:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomatonStr(hybridautstrmap[*yyvsp[-3].str]);
					break;
				case HYBRIDAUTSET:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutStrSet(vhybridautstrmap[*yyvsp[-3].str]);				
					break;
				case TIMEDAUT:				
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;						
					printHybridAutomaton(*timedautmap[*yyvsp[-3].str]);				 
					break;
				case TIMEDAUTSTR:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomatonStr(timedautstrmap[*yyvsp[-3].str]);
					break;
				case TIMEDAUTSET:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutStrSet(vtimedautstrmap[*yyvsp[-3].str]);				
					break;
				case ICTA:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomaton(*ictamap[*yyvsp[-3].str]);				 
					break;
				case ICTAHYBRID:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					printHybridAutomaton(*ictahybridmap[*yyvsp[-3].str]);
					break;
				case VALSETSTR:	
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					for(vector<string>::iterator it=valsetstrmap[*yyvsp[-3].str].begin();it!=valsetstrmap[*yyvsp[-3].str].end();it++)
					{
						cout<<(*it)<<endl;
					}									
					break;
				case STATESTR:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					cout<<statestrmap[*yyvsp[-3].str]<<endl;
					break;
				case SYMSTATESTR:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;					
					{
						pair<string,vector<string> > p(symstatestrmap[*yyvsp[-3].str]);	
						cout<<p.first<<" ";		
						for(vector<string>::iterator it=p.second.begin();it!=p.second.end();it++)
						{
							cout<<(*it)<<" ";
						}
						cout<<endl;
					}
					break;
				case BOOL:
					cout<<(*yyvsp[-3].str)<<" contains"<<endl;
					cout<<boolmap[*yyvsp[-3].str]<<endl;
					break;
				
			}
		}
break;
case 9:
#line 526 "newyacc.y"
{
			/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-3].str];
			
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
								a=*autmap[*yyvsp[-3].str];
								break;
							case HYBRIDAUT:
								a=*hybridautmap[*yyvsp[-3].str];
								break;
							case TIMEDAUT:
								a=*timedautmap[*yyvsp[-3].str];
								break;
							case ICTA:
								a=*ictamap[*yyvsp[-3].str];
								break;
							case ICTAHYBRID:
								a=*ictahybridmap[*yyvsp[-3].str];
								break;
						}
						createDotFileFromAut(a,*yyvsp[-3].str);
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
								a=*autstrmap[*yyvsp[-3].str];
								break;
							case HYBRIDAUTSTR:
								a=*hybridautstrmap[*yyvsp[-3].str];
								break;
							case TIMEDAUTSTR:
								a=*timedautstrmap[*yyvsp[-3].str];
								break;
						}
						createDotFileFromAutStr(a,*yyvsp[-3].str);
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
								vautstr=vautstrmap[*yyvsp[-3].str];
								break;
							case HYBRIDAUTSET:
								vautstr=vhybridautstrmap[*yyvsp[-3].str];
								break;
							case TIMEDAUTSET:
								vautstr=vtimedautstrmap[*yyvsp[-3].str];
								break;
						}
						createDotFileFromVAutStr(vautstr,*yyvsp[-3].str);
					}
					break;			
				
			}
		}
break;
case 10:
#line 606 "newyacc.y"
{
			maxiterations=atoi(yyvsp[-1].str->c_str());
		}
break;
case 11:
#line 610 "newyacc.y"
{	/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-3].str];
			enum TYPE t2=varmap[*yyvsp[-1].str];
			if(t1==AUTSTR && t2==AUTSTR)
			{
				/*cout<<"AutAut type"<<endl;				*/
				varmap[*yyvsp[-5].str]=AUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*autstrmap[*yyvsp[-3].str];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*autstrmap[*yyvsp[-1].str];
				

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
					autmap[*yyvsp[-5].str]=prod;
				/*}
				else
				{
					//cout<<"This is the mistake of yours while giving writing input var"<<endl;
					yyerror("This is the mistake of yours while giving writing input var");
				}*/
			}
			else if(t1==HYBRIDAUTSTR && t2==HYBRIDAUTSTR)
			{
				/*cout<<"AutAut type"<<endl;				*/
				varmap[*yyvsp[-5].str]=HYBRIDAUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*hybridautstrmap[*yyvsp[-3].str];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*hybridautstrmap[*yyvsp[-1].str];
				

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
					hybridautmap[*yyvsp[-5].str]=prod;
				/*}
				else
				{
					//cout<<"This is the mistake of yours while giving writing input var"<<endl;
					yyerror("This is the mistake of yours while giving writing input var");
				}*/
			}
			else if(t1==TIMEDAUTSTR && t2==TIMEDAUTSTR)
			{
				/*cout<<"AutAut type"<<endl;				*/
				varmap[*yyvsp[-5].str]=TIMEDAUT;
				
				
			
				/*Automaton *a1=new Automaton();
				(*a1)=autstrToaut(*autstrmap[*$3]);
				Automaton *a2=new Automaton();
				(*a2)=autstrToaut(*autstrmap[*$5]);*/
				


				
				AutomatonStr *tmpa1=new AutomatonStr();
				(*tmpa1)=*timedautstrmap[*yyvsp[-3].str];

				AutomatonStr *tmpa2=new AutomatonStr();
				(*tmpa2)=*timedautstrmap[*yyvsp[-1].str];
				

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
					timedautmap[*yyvsp[-5].str]=prod;
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
					/*cout<<"Here"<<endl;*/
					varmap[*yyvsp[-5].str]=SYMSTATESTR;
					pair<string,vector<string> > p(*yyvsp[-3].str,valsetstrmap[*yyvsp[-1].str]);				
					symstatestrmap[*yyvsp[-5].str]=p;			
				}
			}
			else
			{
				/*cout<<"Rahul2:"<<endl;*/
				if(t2==VALSETSTR)
				{
					/*cout<<"Here"<<endl;*/
					varmap[*yyvsp[-5].str]=SYMSTATESTR;
					pair<string,vector<string> > p(*yyvsp[-3].str,valsetstrmap[*yyvsp[-1].str]);				
					symstatestrmap[*yyvsp[-5].str]=p;			
				}
			}
			
		}
break;
case 12:
#line 853 "newyacc.y"
{	/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
		enum TYPE t2=varmap[*yyvsp[-1].str];
		if(t2==VALSETSTR)
		{
			/*cout<<"Here"<<endl;*/
			varmap[*yyvsp[-5].str]=SYMSTATESTR;
			pair<string,vector<string> > p(*yyvsp[-3].str,valsetstrmap[*yyvsp[-1].str]);				
			symstatestrmap[*yyvsp[-5].str]=p;			
		}
		
	}
break;
case 13:
#line 866 "newyacc.y"
{
			/*varmap[*$1]=HYBRIDAUT;*/
			
			enum TYPE t1=varmap[*yyvsp[-2].str];
			
			switch(t1)
			{
				case AUTSET:
					{
						/*cout<<"Autset"<<endl;*/
						varmap[*yyvsp[-6].str]=AUT;
						/*cntr_var_lst.cntr_arr take union*/
						vector<AutomatonStr> alst=vautstrmap[*yyvsp[-2].str];
			
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
				
						/*take product of these hybridautset*/

						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}

				
						Automaton *prod=new Automaton();

						(*prod)=take_product2(*atlist);				

						prod->cntrToautmap=cntrToautmap;


						prod->fillMaps();
						autmap[*yyvsp[-6].str]=prod;
					}
					break;
				case HYBRIDAUTSET:
					{	
						/*cout<<"HybridAutset"<<endl;*/
						varmap[*yyvsp[-6].str]=HYBRIDAUT;		
						/*cntr_var_lst.cntr_arr take union*/
						vector<AutomatonStr> alst=vhybridautstrmap[*yyvsp[-2].str];
			
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
				
						/*take product of these hybridautset*/

						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}

				
						Automaton *prod=new Automaton();
				
						(*prod)=take_product2(*atlist);
						prod->cntrToautmap=cntrToautmap;
						prod->fillMaps();
						hybridautmap[*yyvsp[-6].str]=prod;
					}
					break;
				case TIMEDAUTSET:
					{
						/*cout<<"TimedAutset"<<endl;*/
						varmap[*yyvsp[-6].str]=TIMEDAUT;			
						/*cntr_var_lst.cntr_arr take union*/
						vector<AutomatonStr> alst=vtimedautstrmap[*yyvsp[-2].str];
			
						vector<string> *vs=new vector<string>();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{
							for(vector<string>::iterator itt=it->cntr_var_lst.cntr_var_arr.begin();itt!=it->cntr_var_lst.cntr_var_arr.end();itt++)
							{
								vs->push_back(*itt);
							}		
						}
						/*cout<<"1"<<endl;*/
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



						/*cout<<"2"<<endl;*/
						Automaton_List *atlist=new Automaton_List();
						for(vector<AutomatonStr>::iterator it=alst.begin();it!=alst.end();it++)
						{			
					
					
					
							AutomatonStr *tmp=new AutomatonStr();
							(*tmp)=(*it);
							tmp->cntr_var_lst.cntr_var_arr=(*vss);					
		
					
							Automaton *a=new Automaton();
							/*cout<<"2a"<<endl;*/
							(*a)=autstrToaut(*tmp);
							/*cout<<"2b"<<endl;*/
							a->fillMaps();
							atlist->aut_arr.push_back(*a);
					
					
						}
				
						/*take product of these hybridautset*/
						/*cout<<"3"<<endl;*/
						for(vector<Automaton>::iterator it=atlist->aut_arr.begin();it!=atlist->aut_arr.end();it++)
						{
							printHybridAutomaton(*it);				 			
						}
						/*cout<<"4"<<endl;*/
				
						Automaton *prod=new Automaton();

						

						(*prod)=take_product2(*atlist);
						prod->cntrToautmap=cntrToautmap;

						prod->fillMaps();
						timedautmap[*yyvsp[-6].str]=prod;
						/*cout<<"5"<<endl;*/
					}
					break;
			}
		}
break;
case 14:
#line 1095 "newyacc.y"
{
						
		}
break;
case 15:
#line 1099 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/


			enum TYPE t=varmap[*yyvsp[-1].str];
			switch(t)
			{
				case AUT:
					{
						varmap[*yyvsp[-3].str]=AUT;				
						Automaton *a=new Automaton();
						(*a)=(*autmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						autmap[*yyvsp[-3].str]=a;			
					}
					break;
				case AUTSTR:
					{
						varmap[*yyvsp[-3].str]=AUT;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*autstrmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
					
						autmap[*yyvsp[-3].str]=a;					
					
					}
					break;
				case AUTSET:
					{
						varmap[*yyvsp[-3].str]=AUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vautstrmap[*yyvsp[-1].str];
						/*va->cntrToautmap=createAutomatonMap(*va);*/
						vautstrmap[*yyvsp[-3].str]=(*va);						
					}
					break;
				case HYBRIDAUT:
					{	
						varmap[*yyvsp[-3].str]=HYBRIDAUT;	
						Automaton *a=new Automaton();					
						(*a)=(*hybridautmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						hybridautmap[*yyvsp[-3].str]=a;					
					
					}
					break;
				case HYBRIDAUTSTR:
					{
						varmap[*yyvsp[-3].str]=HYBRIDAUT;
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*hybridautstrmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						hybridautmap[*yyvsp[-3].str]=a;					
					}
					break;
				case HYBRIDAUTSET:
					{
						varmap[*yyvsp[-3].str]=HYBRIDAUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vhybridautstrmap[*yyvsp[-1].str];
						/*va->cntrToautmap=createAutomatonMap(*va);*/
						vhybridautstrmap[*yyvsp[-3].str]=(*va);						
					
					}
					break;
				case TIMEDAUT:			
					{
						varmap[*yyvsp[-3].str]=TIMEDAUT;

						Automaton *a=new Automaton();
						(*a)=(*timedautmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						timedautmap[*yyvsp[-3].str]=a;			
				
					}
					break;
				case TIMEDAUTSTR:
					{
						varmap[*yyvsp[-3].str]=TIMEDAUT;	
						Automaton *a=new Automaton();
						(*a)=autstrToaut(*timedautstrmap[*yyvsp[-1].str]);						
						a->cntrToautmap=createAutomatonMap(*a);
						timedautmap[*yyvsp[-3].str]=a;				
					}					
					break;
				case TIMEDAUTSET:
					{
						varmap[*yyvsp[-3].str]=TIMEDAUTSET;
					
						vector<AutomatonStr> *va=new vector<AutomatonStr>();
						(*va)=vtimedautstrmap[*yyvsp[-1].str];
						/*va->cntrToautmap=createAutomatonMap(*va);*/
						vtimedautstrmap[*yyvsp[-3].str]=(*va);
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
						varmap[*yyvsp[-3].str]=ICTA;
					
						Automaton *a=new Automaton();
						(*a)=(*ictamap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						ictamap[*yyvsp[-3].str]=a;				
					}
					break;
				case ICTAHYBRID:
					{
						varmap[*yyvsp[-3].str]=ICTAHYBRID;
					
						Automaton *a=new Automaton();
						(*a)=(*ictahybridmap[*yyvsp[-1].str]);
						a->cntrToautmap=createAutomatonMap(*a);
						ictahybridmap[*yyvsp[-3].str]=a;				
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
					varmap[*yyvsp[-3].str]=VALSETSTR;				
					valsetstrmap[*yyvsp[-3].str]=valsetstrmap[*yyvsp[-1].str];
					break;
				case STATESTR:
					varmap[*yyvsp[-3].str]=STATESTR;
					statestrmap[*yyvsp[-3].str]=statestrmap[*yyvsp[-1].str];
					break;
				case SYMSTATESTR:
					varmap[*yyvsp[-3].str]=SYMSTATESTR;
					symstatestrmap[*yyvsp[-3].str]=symstatestrmap[*yyvsp[-1].str];
					break;
				case BOOL:
					varmap[*yyvsp[-3].str]=BOOL;
					boolmap[*yyvsp[-3].str]=boolmap[*yyvsp[-1].str];
					break;
	
			}
		}
break;
case 16:
#line 1260 "newyacc.y"
{
			varmap[*yyvsp[-3].str]=VALSETSTR;
			valsetstrmap[*yyvsp[-3].str]=(*yyvsp[-1].strv);	
		}
break;
case 17:
#line 1275 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			
			switch(t1)
			{
				case AUT:
					{
						
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);
							Automaton a;
							a=*autmap[*yyvsp[-4].str];

							a.fillMaps();
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_dfs_fb(R_f,R_i,a);
						}
					}
					break;

			}
		}
break;
case 18:
#line 1309 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);
							Automaton a;
							a=*autmap[*yyvsp[-4].str];
							a.fillMaps();
					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_bfs_fb(R_f,R_i,a);
						}
					}
					break;

			}
		}
break;
case 19:
#line 1342 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			/*cout<<"Here"<<endl;*/
			switch(t1)
			{
				case AUT:
					{
						/*cout<<"Here2"<<endl;*/
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);
							Automaton a;
							a=*autmap[*yyvsp[-4].str];
							a.fillMaps();
					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_dfs_bk(R_f,R_i,a);
						}
					}
					break;

			}
		}
break;
case 20:
#line 1376 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);
							Automaton a;
							a=*autmap[*yyvsp[-4].str];
							a.fillMaps();
					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_bfs_bk(R_f,R_i,a);
						}
					}
					break;

			}
		}
break;
case 21:
#line 1409 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*hybridautmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							/*here forward reachability algo is used*/
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
			}
		}
break;
case 22:
#line 1479 "newyacc.y"
{
/*NOTYPE,AUT,AUTSTR,AUTSET,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,TIMEDAUTSET,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];			
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);
							
					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;



							Automaton a;
							a=*hybridautmap[*yyvsp[-4].str];
							a.fillMaps();
							Automaton_List autlst;
							/*autlst.aut_arr.push_back(*hybridautmap[*$5]);*/
							autlst.aut_arr.push_back(a);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);

							boolmap[*yyvsp[-8].str]=is_Reachable_by_forward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
						}
					}
					break;
			}
			
		}
break;
case 23:
#line 1553 "newyacc.y"
{
/*NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t1=varmap[*yyvsp[-4].str];
			enum TYPE t2=varmap[*yyvsp[-2].str];
			switch(t1)
			{
				case AUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*autmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*yyvsp[-8].str]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
				case HYBRIDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton a;	
							a=*hybridautmap[*yyvsp[-4].str];
							a.fillMaps();

							Automaton_List autlst;
							/*autlst.aut_arr.push_back(*hybridautmap[*$5]);*/
							autlst.aut_arr.push_back(a);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*yyvsp[-8].str]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
				case TIMEDAUT:
					{
						if(t2==SYMSTATESTR)
						{
							varmap[*yyvsp[-8].str]=BOOL;
							vector<vector<State> > R_f,R_i;

							Automaton_List autlst;
							autlst.aut_arr.push_back(*timedautmap[*yyvsp[-4].str]);

					
							/*initialize_final_states_compo_demo(R_f,aut_lst);*/
							initialize_final_states_from_symstate(R_f,symstatestrmap[*yyvsp[-2].str],autlst);
							initialize_initial_states(R_i,autlst);
					

							boolmap[*yyvsp[-8].str]=is_Reachable_by_backward_fixpoint_computation(R_f,R_i,maxiterations,autlst);
					
						}
					}
					break;
			}
		}
break;
case 24:
#line 1630 "newyacc.y"
{
/*NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTAHYBRID,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t=varmap[*yyvsp[-2].str];
			switch(t)
			{
				case TIMEDAUTSET:
					{
						Automaton_List alist;					
						set<string> s;
						for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*yyvsp[-2].str].begin();it!=vtimedautstrmap[*yyvsp[-2].str].end();it++)
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
						
						
						/*cout<<"Rahul3:"<<endl;*/
						map<string,string> cntrToautmap=createAutomatonMap(vtimedautstrmap[*yyvsp[-2].str]);

						for(vector<AutomatonStr>::iterator it=vtimedautstrmap[*yyvsp[-2].str].begin();it!=vtimedautstrmap[*yyvsp[-2].str].end();it++)
						{
							AutomatonStr *atmp=new AutomatonStr();
							(*atmp)=(*it);
							atmp->cntr_var_lst.cntr_var_arr=vs;
						
						
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*atmp);
							a->cntr_var_lst.cntr_var_arr=vs;
							a->fillMaps();


							/*(*a)=removeinvariants(*a);*/
							
							/*printHybridAutomaton(*a);				 */

	
							alist.aut_arr.push_back(*a);
						
						}
						Automaton *prod=new Automaton();
						/*cout<<"Rahul1:"<<endl;*/
						(*prod)=to_ICTA2(alist);
						/*cout<<"Rahul2:"<<endl;*/
						prod->cntrToautmap=cntrToautmap;						
						prod->fillMaps();
						varmap[*yyvsp[-6].str]=ICTA;
					
						ictamap[*yyvsp[-6].str]=prod;				
					
					
					}
					break;
				case HYBRIDAUTSET:
					{
						Automaton_List alist;

					
						set<string> s;
						for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*yyvsp[-2].str].begin();it!=vhybridautstrmap[*yyvsp[-2].str].end();it++)
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
						
						
						
						map<string,string> cntrToautmap=createAutomatonMap(vhybridautstrmap[*yyvsp[-2].str]);

						

						for(vector<AutomatonStr>::iterator it=vhybridautstrmap[*yyvsp[-2].str].begin();it!=vhybridautstrmap[*yyvsp[-2].str].end();it++)
						{
							AutomatonStr *atmp=new AutomatonStr();
							(*atmp)=(*it);
							atmp->cntr_var_lst.cntr_var_arr=vs;
						
						
							Automaton *a=new Automaton();
							(*a)=autstrToaut(*atmp);
							a->cntr_var_lst.cntr_var_arr=vs;
							a->fillMaps();



							/*(*a)=removeinvariants(*a);*/
							
							/*printHybridAutomaton(*a);				 */

							alist.aut_arr.push_back(*a);
						
						}
						Automaton *prod=new Automaton();
						(*prod)=to_ICTA2(alist);
						prod->cntrToautmap=cntrToautmap;
						prod->fillMaps();
						varmap[*yyvsp[-6].str]=ICTAHYBRID;
					
						ictahybridmap[*yyvsp[-6].str]=prod;				
										
						
					}
					break;
			}		
		}
break;
case 25:
#line 1760 "newyacc.y"
{
			enum TYPE t=varmap[*yyvsp[-2].str];
			switch(t)
			{
				case ICTA:
				{
					varmap[*yyvsp[-6].str]=ICTA;
					Automaton *a=new Automaton();
					(*a)=(*ictamap[*yyvsp[-2].str]);
					a->fillMaps();				

					Automaton *prod=new Automaton();
					(*prod)=hybrid_flavoured_timed_aut_to_timed_aut(*a);
					prod->fillMaps();
					prod->cntrToautmap=a->cntrToautmap;
					ictamap[*yyvsp[-6].str]=prod;	
					
					/*prod_aut.cntr_var_lst.cntr_var_arr.clear();
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("z");*/
					/*prod->cntr_var_lst.cntr_var_arr.push_back("l");*/


					/*Automaton *region_aut=new Automaton();*/
					/*(*region_aut)=construct_Region_Automata(*prod);*/

					/*region_aut->fillMaps();*/
					break;
				}
				case ICTAHYBRID:
				{
					varmap[*yyvsp[-6].str]=ICTA;
					Automaton *a=new Automaton();
					(*a)=(*ictahybridmap[*yyvsp[-2].str]);
					a->fillMaps();				

					Automaton *prod=new Automaton();
					(*prod)=hybrid_flavoured_timed_aut_to_timed_aut(*a);
					prod->fillMaps();
					prod->cntrToautmap=a->cntrToautmap;
					ictamap[*yyvsp[-6].str]=prod;	
					
					/*prod_aut.cntr_var_lst.cntr_var_arr.clear();
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("x");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("y");
					prod_aut.cntr_var_lst.cntr_var_arr.push_back("z");*/
					/*prod->cntr_var_lst.cntr_var_arr.push_back("l");*/


					/*Automaton *region_aut=new Automaton();*/
					/*(*region_aut)=construct_Region_Automata(*prod);*/

					/*region_aut->fillMaps();*/
					break;
				}
			}	
		}
break;
case 26:
#line 1820 "newyacc.y"
{
/*NOTYPE,HYBRIDAUT,HYBRIDAUTSTR,HYBRIDAUTSET,TIMEDAUT,TIMEDAUTSTR,REGIONAUT,REGIONAUTSTR,ICTA,ICTASTR,VALSETSTR,STATESTR,SYMSTATESTR,BOOL*/
			enum TYPE t=varmap[*yyvsp[-2].str];
			switch(t)
			{
				case TIMEDAUT:					
					{	
						varmap[*yyvsp[-6].str]=AUT;
						timedautmap[*yyvsp[-2].str]->fillMaps();
						Automaton *without_invar=new Automaton();
						(*without_invar)=*timedautmap[*yyvsp[-2].str];
						/*(*without_invar)=removeinvariants(*timedautmap[*$5]);*/
						/*cout<<"Without invariants:"<<endl;*/
						/*printHybridAutomaton(*without_invar);*/
						Automaton *region_aut=new Automaton();						
						(*region_aut)=construct_Region_Automata(*without_invar);
						region_aut->fillMaps();
						region_aut->cntrToautmap=without_invar->cntrToautmap;
						autmap[*yyvsp[-6].str]=region_aut;			

						
						
					}	
					break;				
				case ICTA:
					{	
						varmap[*yyvsp[-6].str]=AUT;

						ictamap[*yyvsp[-2].str]->fillMaps(); 						
						
						Automaton *without_invar=new Automaton();
						(*without_invar)=*ictamap[*yyvsp[-2].str];
						/*(*without_invar)=removeinvariants(*ictamap[*$5]);*/
						without_invar->fillMaps();
						Automaton *region_aut=new Automaton();							
						
						(*region_aut)=construct_Region_Automata_for_ICTA(*without_invar);
						region_aut->fillMaps();
						/*region_aut->cntrToautmap=without_invar->cntrToautmap;*/
						autmap[*yyvsp[-6].str]=region_aut;						
					}
					break;			
				
			}
			
		}
break;
case 27:
#line 1870 "newyacc.y"
{ a=new AutomatonStr(); a->name=(*yyvsp[0].str);}
break;
case 28:
#line 1871 "newyacc.y"
{
			varmap[*yyvsp[-3].str]=HYBRIDAUTSTR;
			hybridautstrmap[*yyvsp[-3].str]=a;
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
break;
case 29:
#line 1954 "newyacc.y"
{ a=new AutomatonStr(); a->name=(*yyvsp[0].str);}
break;
case 30:
#line 1955 "newyacc.y"
{
			varmap[*yyvsp[-3].str]=AUTSTR;
			autstrmap[*yyvsp[-3].str]=a;
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
break;
case 31:
#line 2038 "newyacc.y"
{ a=new AutomatonStr(); a->name=(*yyvsp[0].str);}
break;
case 32:
#line 2039 "newyacc.y"
{
			varmap[*yyvsp[-3].str]=TIMEDAUTSTR;
			timedautstrmap[*yyvsp[-3].str]=a;
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
break;
case 39:
#line 2138 "newyacc.y"
{
			a->cntr_var_lst.cntr_var_arr=*((vector<string> *)yyvsp[-1].strv);
			/*cout<<"Control var size:"<<a->cntr_var_lst.cntr_var_arr.size()<<endl;*/
			/*cout<<"Control var size:"<<((vector<string> *)$3)->size()<<endl;*/
			
		}
break;
case 40:
#line 2147 "newyacc.y"
{
			Input_Variable i;
			for(vector<string>::iterator it=((vector<string> *)yyvsp[-1].strv)->begin();it!=((vector<string> *)yyvsp[-1].strv)->end();it++)
			{
				i.name=(*it);
				a->in_var_lst.in_var_arr.push_back(i);
			}
			
			/*cout<<"External var size:"<<a->in_var_lst.in_var_arr.size()<<endl;*/
			
		}
break;
case 41:
#line 2161 "newyacc.y"
{
			Synchronizing_Label sl;
			for(vector<string>::iterator it=((vector<string> *)yyvsp[-1].strv)->begin();it!=((vector<string> *)yyvsp[-1].strv)->end();it++)
			{
				sl.name=(*it);
				a->syn_lab_lst.syn_lab_arr.push_back(sl);
			}
			/*cout<<"Sync Lab Size:"<<a->syn_lab_lst.syn_lab_arr.size()<<endl;*/
      		}
break;
case 42:
#line 2173 "newyacc.y"
{
			Parameter par;
			for(vector<string>::iterator it=((vector<string> *)yyvsp[-1].strv)->begin();it!=((vector<string> *)yyvsp[-1].strv)->end();it++)
			{
				par.name=(*it);
				a->parameter_lst.par_list_arr.push_back(par);
			}
			
			/*cout<<"Par Size:"<<a->parameter_lst.par_list_arr.size()<<endl;*/
		}
break;
case 43:
#line 2186 "newyacc.y"
{						
			
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
			
		}
break;
case 44:
#line 2191 "newyacc.y"
{ 
			
			yyval.strv=new vector<string>();
			
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
		}
break;
case 45:
#line 2200 "newyacc.y"
{
			
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
			
		}
break;
case 46:
#line 2205 "newyacc.y"
{
			
			yyval.strv=new vector<string>();
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
		}
break;
case 47:
#line 2215 "newyacc.y"
{
			
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
		}
break;
case 48:
#line 2219 "newyacc.y"
{  
			
			yyval.strv=new vector<string>();
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
		}
break;
case 49:
#line 2227 "newyacc.y"
{
			
			
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
                }
break;
case 50:
#line 2233 "newyacc.y"
{
                 	
			yyval.strv=new vector<string>();
			((vector<string> *)yyval.strv)->push_back(*yyvsp[0].str);
                }
break;
case 51:
#line 2242 "newyacc.y"
{ 
		}
break;
case 52:
#line 2245 "newyacc.y"
{
		}
break;
case 53:
#line 2250 "newyacc.y"
{ 
			/*cout<<"Rahul:"<<*$1<<endl;*/
			lstr.name=(*yyvsp[-2].str);
			lstr.invariants=(*yyvsp[0].strv);
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			/*cout<<"Initial Loc parsed"<<endl;*/
			
		}
break;
case 54:
#line 2260 "newyacc.y"
{
			lstr.name=(*yyvsp[0].str);
			lstr.invariants.clear();
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			/*cout<<"Initial Loc parsed"<<endl;*/
		}
break;
case 55:
#line 2268 "newyacc.y"
{
			lstr.name=(*yyvsp[0].str);
			lstr.invariants.clear();
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			/*cout<<"Initial Loc parsed"<<endl;*/
		}
break;
case 56:
#line 2276 "newyacc.y"
{ 
			lstr.name=(*yyvsp[-2].str);
			lstr.invariants=(*yyvsp[0].strv);
			lstr.rate.clear();
			a->initial_loc_lst.push_back(lstr);			
			/*cout<<"Initial Loc parsed"<<endl;*/
			

		}
break;
case 61:
#line 2298 "newyacc.y"
{			
			
			lstr.name=(*yyvsp[-7].str);
			lstr.invariants=(*yyvsp[-4].strv);
			lstr.rate=(*yyvsp[-1].strv);
			a->loc_lst.push_back(lstr);

			varmap[*yyvsp[-7].str]=STATESTR;
			statestrmap[*yyvsp[-7].str]=a->name;			
			/*cout<<"Loc parsed"<<endl;*/
      		}
break;
case 62:
#line 2310 "newyacc.y"
{
			lstr.name=(*yyvsp[-3].str);
			/*cout<<"\nInvariants:"<<endl;
			for(vector<string>::iterator it=$5->begin();it!=$5->end();it++)
			{
				cout<<(*it)<<endl;
			}
			cout<<endl;*/
			lstr.invariants=(*yyvsp[0].strv);		
			/*lstr.rate=(*$8);*/
			lstr.rate.clear();
			a->loc_lst.push_back(lstr);

			varmap[*yyvsp[-3].str]=STATESTR;
			statestrmap[*yyvsp[-3].str]=a->name;			
			/*cout<<"Loc parsed"<<endl;*/
		}
break;
case 65:
#line 2336 "newyacc.y"
{
			
			e.pre=a->loc_lst.back().name;
			e.post=(*yyvsp[-1].str);
			e.guards=(*yyvsp[-9].strv);
			e.updates=(*yyvsp[-4].strv);
			e.syn_lab=(*yyvsp[-7].str);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
break;
case 66:
#line 2347 "newyacc.y"
{ 
			
			e.pre=a->loc_lst.back().name;
			e.post=(*yyvsp[-1].str);
			e.guards=(*yyvsp[-9].strv);
			e.updates=(*yyvsp[-6].strv);
			e.syn_lab=(*yyvsp[-3].str);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
break;
case 67:
#line 2358 "newyacc.y"
{ 
			
			e.pre=a->loc_lst.back().name;
			e.post=(*yyvsp[-1].str);
			e.guards=(*yyvsp[-5].strv);
			e.updates.clear();
			e.syn_lab=(*yyvsp[-3].str);
			e.aut_nm=a->name; 
			a->edge_lst.push_back(e);
		}
break;
case 68:
#line 2372 "newyacc.y"
{ }
break;
case 69:
#line 2374 "newyacc.y"
{  }
break;
case 70:
#line 2379 "newyacc.y"
{ 
		
		}
break;
case 71:
#line 2383 "newyacc.y"
{ 
		
		}
break;
case 72:
#line 2391 "newyacc.y"
{	
			yyval.strv=new vector<string>();	
			for(vector<string>::iterator it=yyvsp[-2].strv->begin();it!=yyvsp[-2].strv->end();it++)
			{
				yyval.strv->push_back(*it);
			}
			for(vector<string>::iterator it=yyvsp[0].strv->begin();it!=yyvsp[0].strv->end();it++)
			{
				yyval.strv->push_back(*it);
			}
		}
break;
case 73:
#line 2403 "newyacc.y"
{
			/*$$=$2;*/
			yyval.strv=new vector<string>();
			(*yyval.strv)=(*yyvsp[-1].strv);
		}
break;
case 74:
#line 2410 "newyacc.y"
{
			yyval.strv=new vector<string>();
			(*yyval.strv).push_back(*yyvsp[0].str);
			
		}
break;
case 75:
#line 2420 "newyacc.y"
{ 
			yyval.strv=new vector<string>();
			for(vector<string>::iterator it=yyvsp[-2].strv->begin();it!=yyvsp[-2].strv->end();it++)
			{
				yyval.strv->push_back(*it);
			}
			for(vector<string>::iterator it=yyvsp[0].strv->begin();it!=yyvsp[0].strv->end();it++)
			{
				yyval.strv->push_back(*it);
			}
		}
break;
case 76:
#line 2433 "newyacc.y"
{
			yyval.strv=new vector<string>();
			yyval.strv->push_back(*yyvsp[0].str);
		}
break;
case 77:
#line 2441 "newyacc.y"
{
			string *s=new string();
			(*s)=(*yyvsp[0].str); 
			/*$$=$1;*/
			yyval.str=s;
		}
break;
case 78:
#line 2473 "newyacc.y"
{
			/*cout<<"l:"<<(*$1)<<" r:"<<(*$3)<<endl;*/
			string s=yyvsp[-2].str->append(" < ").append(yyvsp[0].str->c_str());
		
			string *m=new string();
			(*m)=s;
			/*cout<<"Constraint:"<<s<<endl;*/
			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 79:
#line 2484 "newyacc.y"
{
			string s=yyvsp[-2].str->append(" > ").append(yyvsp[0].str->c_str());
			/*cout<<"Constraint:"<<s<<endl;*/
			
			string *m=new string();
			(*m)=s;
			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 80:
#line 2494 "newyacc.y"
{
			string s=yyvsp[-2].str->append(" >= ").append(yyvsp[0].str->c_str());
			/*cout<<"Constraint:"<<s<<endl;*/

			string *m=new string();
			(*m)=s;

			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 81:
#line 2505 "newyacc.y"
{
			string s=yyvsp[-2].str->append(" <= ").append(yyvsp[0].str->c_str());
			/*cout<<"Constraint:"<<s<<endl;*/
			string *m=new string();
			(*m)=s;

			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 82:
#line 2515 "newyacc.y"
{
			/*cout<<"Got:"<<(*$3)<<endl;*/
			string s=yyvsp[-2].str->append(" == ").append(yyvsp[0].str->c_str());
			/*cout<<"Constraint:"<<s<<endl;*/
			string *m=new string();
			(*m)=s;

			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 83:
#line 2526 "newyacc.y"
{
			/*cout<<"Here"<<endl;*/
			string *s=new string("true");
			yyval.str=s;
		}
break;
case 84:
#line 2532 "newyacc.y"
{
			string *s=new string("false");
			yyval.str=s;
		}
break;
case 85:
#line 2541 "newyacc.y"
{
			string *s=new string();
			(*s)=(*yyvsp[0].str);
			/*$$=$1;	*/
			yyval.str=s;
		}
break;
case 86:
#line 2548 "newyacc.y"
{
			string *s=new string();
			(*s)=(*yyvsp[-1].str);
			/*string s=$1->append("'");*/
			/*$$=&s;*/
			/*$$=$1;	*/
			yyval.str=s;
		}
break;
case 87:
#line 2557 "newyacc.y"
{ 
			string *s=new string();
			(*s)=(*yyvsp[0].str);
			/*$$=$1;*/
			yyval.str=s;
      		}
break;
case 88:
#line 2564 "newyacc.y"
{
			/*cout<<*$1<<" bata "<<*$3<<endl;*/
			string t=yyvsp[-2].str->append(" * ").append(yyvsp[0].str->c_str()); 
			string *m=new string();
			(*m)=t;
			/*cout<<"New:"<<t<<endl;*/
			yyval.str=m;
      		}
break;
case 89:
#line 2573 "newyacc.y"
{ 
			string s=yyvsp[-2].str->append(" / ").append(yyvsp[0].str->c_str());
			string *m=new string();
			(*m)=s;
			/*$$=&s;*/
			yyval.str=m;
      		}
break;
case 90:
#line 2581 "newyacc.y"
{
			/*cout<<"here:"<<*$1<<" + "<<*$3<<endl;*/
			string s=yyvsp[-2].str->append(" + ").append(yyvsp[0].str->c_str());
			
			string *m=new string();
			(*m)=s;

			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 91:
#line 2592 "newyacc.y"
{
			string s=yyvsp[-2].str->append(" - ").append(yyvsp[0].str->c_str());


			string *m=new string();
			(*m)=s;

			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 92:
#line 2603 "newyacc.y"
{
			string *minus=new string("-");
			string s=minus->append(yyvsp[0].str->c_str()); 
			/*cout<<"Here"<<s<<endl;*/
			string *m=new string();
			(*m)=s;
			/*$$=&s;*/
			yyval.str=m;
		}
break;
case 93:
#line 2613 "newyacc.y"
{
			string *opencurly=new string("( ");
			string *closedcurly=new string(" )");
			string s=opencurly->append(yyvsp[-1].str->c_str()).append(closedcurly->c_str());

			string *m=new string();
			(*m)=s;
			yyval.str=m;
			/*$$=&s;*/
			/*$$=$2;*/
		}
break;
#line 3156 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
