/*-------------------------------------------------------------------------
 *
 * pg_aggregate_d.h
 *    Macro definitions for pg_aggregate
 *
 * Portions Copyright (c) 1996-2023, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * NOTES
 *  ******************************
 *  *** DO NOT EDIT THIS FILE! ***
 *  ******************************
 *
 *  It has been GENERATED by src/backend/catalog/genbki.pl
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AGGREGATE_D_H
#define PG_AGGREGATE_D_H

#define AggregateRelationId 2600
#define AggregateFnoidIndexId 2650

#define Anum_pg_aggregate_aggfnoid 1
#define Anum_pg_aggregate_aggkind 2
#define Anum_pg_aggregate_aggnumdirectargs 3
#define Anum_pg_aggregate_aggtransfn 4
#define Anum_pg_aggregate_aggfinalfn 5
#define Anum_pg_aggregate_aggcombinefn 6
#define Anum_pg_aggregate_aggserialfn 7
#define Anum_pg_aggregate_aggdeserialfn 8
#define Anum_pg_aggregate_aggmtransfn 9
#define Anum_pg_aggregate_aggminvtransfn 10
#define Anum_pg_aggregate_aggmfinalfn 11
#define Anum_pg_aggregate_aggfinalextra 12
#define Anum_pg_aggregate_aggmfinalextra 13
#define Anum_pg_aggregate_aggfinalmodify 14
#define Anum_pg_aggregate_aggmfinalmodify 15
#define Anum_pg_aggregate_aggsortop 16
#define Anum_pg_aggregate_aggtranstype 17
#define Anum_pg_aggregate_aggtransspace 18
#define Anum_pg_aggregate_aggmtranstype 19
#define Anum_pg_aggregate_aggmtransspace 20
#define Anum_pg_aggregate_agginitval 21
#define Anum_pg_aggregate_aggminitval 22

#define Natts_pg_aggregate 22


/*
 * Symbolic values for aggkind column.  We distinguish normal aggregates
 * from ordered-set aggregates (which have two sets of arguments, namely
 * direct and aggregated arguments) and from hypothetical-set aggregates
 * (which are a subclass of ordered-set aggregates in which the last
 * direct arguments have to match up in number and datatypes with the
 * aggregated arguments).
 */
#define AGGKIND_NORMAL			'n'
#define AGGKIND_ORDERED_SET		'o'
#define AGGKIND_HYPOTHETICAL	'h'

/* Use this macro to test for "ordered-set agg including hypothetical case" */
#define AGGKIND_IS_ORDERED_SET(kind)  ((kind) != AGGKIND_NORMAL)

/*
 * Symbolic values for aggfinalmodify and aggmfinalmodify columns.
 * Preferably, finalfns do not modify the transition state value at all,
 * but in some cases that would cost too much performance.  We distinguish
 * "pure read only" and "trashes it arbitrarily" cases, as well as the
 * intermediate case where multiple finalfn calls are allowed but the
 * transfn cannot be applied anymore after the first finalfn call.
 */
#define AGGMODIFY_READ_ONLY			'r'
#define AGGMODIFY_SHAREABLE			's'
#define AGGMODIFY_READ_WRITE		'w'


#endif							/* PG_AGGREGATE_D_H */
