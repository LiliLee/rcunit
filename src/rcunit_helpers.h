/*
 * RCUNIT - A unit testing framework for C.
 * Copyright (C) 2006 Jerrico L. Gamis
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 *
 */

#ifndef RCUNIT_HELPERS_H
#define RCUNIT_HELPERS_H

/** Calculates the n-byte aligned value */
#define RCU_ALIGN_N(n,val) \
    ((val + (n)-1) & ~((n)-1))

/** @brief Calculates the number of n-bytes required to store value */
#define RCU_SIZE_IN_N(n,val) (((val)+(((n))-1)) >> 2)

/** @brief Defines a "generic" function */
#define RCU_DEF_GENERIC_FUNC(fname,param) \
    RCU_VOID fname(RCU_VOID *param)

/** @brief Defines a test function */
#define RCU_DEF_TEST_FUNC(func,param) \
    RCU_DEF_GENERIC_FUNC(func,param)

/** @brief Defines a start of test function table */
#define RCU_DEF_FUNC_TBL(tbl_name) \
    RCU_TEST_FUNCTION_ENTRY tbl_name[]={

/** @brief Defines an end of a test function table */
#define RCU_DEF_FUNC_TBL_END \
    {RCU_NULL,RCU_NULL,RCU_NULL,RCU_NULL,RCU_TRUE}, \
    };

/** @brief Defines a test function table entry */
#define RCU_INC_FUNC(name,func,init,destroy,enable) \
    {#name,func,init,destroy,enable},

/** @brief Defines a test function table entry with autogenerated name */
#define RCU_INC_FUNC_AUTONAME(func,init,destroy,enable) \
    {#func,func,init,destroy,enable},

/** @brief Defines a test module */
#define RCU_DEF_TEST_MOD(mod)\
    RCU_TEST_MODULE *mod=RCU_NULL;

/** @brief Defines a start of test module table */
#define RCU_DEF_MOD_TBL(mod) \
    RCU_TEST_MODULE_ENTRY mod[]={

/** @brief Defines an end of a test module table */
#define RCU_DEF_MOD_TBL_END \
    {RCU_NULL,RCU_NULL,RCU_NULL,RCU_NULL,RCU_TRUE}, \
    };

/** @brief Defines a test module table entry */
#define RCU_INC_MOD(name,init,destroy,func_tbl,enable) \
    {name,init,destroy,func_tbl,enable},

/** @brief Defines a test registry */
#define RCU_DEF_TEST_REG(reg)\
    RCU_TEST_REGISTRY *reg=RCU_NULL;

/** @brief Defines an initialization function */
#define RCU_DEF_INIT_FUNC(init_func,param) \
    RCU_DEF_GENERIC_FUNC(init_func,param)

/** @brief Defines a destruction function */
#define RCU_DEF_DESTROY_FUNC(destroy_func,param) \
    RCU_DEF_GENERIC_FUNC(destroy_func,param)

/** @brief Defines a test run hook */
#define RCU_DEF_TEST_RUN_HOOK(run_hook,param) \
    RCU_DEF_GENERIC_FUNC(run_hook,param)

/** @brief Defines an assertion hook */
#define RCU_DEF_ASSERT_HOOK(run_hook,param) \
    RCU_DEF_GENERIC_FUNC(run_hook,param)

/** @brief Defines a log handler implementation */
#define RCU_DEF_LOG_HANDLER_IMPL(log_impl,param) \
     RCU_DEF_GENERIC_FUNC(log_impl,param)

/** @brief Defines an output handler implementation */
#define RCU_DEF_OUT_HANDLER_IMPL(out_impl,param) \
     RCU_DEF_GENERIC_FUNC(out_impl,param)

/** @brief Increments an integer value */
#define RCU_INCR(value) \
    (++value);

/** @brief Decrements an integer value */
#define RCU_DECR(value) \
    (--value);

/** @brief Increments an integer value by a specified amount */
#define RCU_INCR_BY(value,inc) \
    value +=inc;

/** @brief Decrements an integer value by a specified amount */
#define RCU_DECR_BY(value,dec) \
    value -=dec;

/** @brief Resets a counter */
#define RCU_RESET(value) \
    value = 0;

/** @brief Traverses a test function table */
#define RCU_FOR_EACH_FUNC_ENTRY(func_tbl,cursor,index) \
    for(index=0,cursor=func_tbl;cursor->name!=RCU_NULL;cursor++,index++)

/** @brief Traverses a test module table */
#define RCU_FOR_EACH_MOD_ENTRY(mod_tbl,cursor,index) \
    for(index=0,cursor=mod_tbl;cursor->name!=RCU_NULL;cursor++,index++)


/** @brief Declares a test function */
#define RCU_DEC_GENERIC_FUNC(func,param) \
    extern RCU_VOID func(RCU_VOID* param);

/** @brief Declares a test function */
#define RCU_DEC_TEST_FUNC(func,param) \
    extern RCU_VOID func(RCU_VOID* param);

/** @brief Declares a test function table */
#define RCU_DEC_TEST_FUNC_TBL(func_tbl) \
    extern RCU_TEST_FUNCTION_ENTRY func_tbl[];

/** @brief Declares a test module */
#define RCU_DEC_TEST_MOD(mod) \
    extern RCU_TEST_MODULE mod;

/** @brief Declares a test module table */
#define RCU_DEC_TEST_MOD_TBL(mod) \
    extern RCU_TEST_MODULE_ENTRY mod[];

/** @brief Declares a test registry */
#define RCU_DEC_TEST_REG(reg) \
    extern RCU_TEST_REGISTER reg[];

/** @brief Declares an init function */
#define RCU_DEC_INIT_FUNC(init_func,param) \
    extern RCU_VOID init_func(RCU_VOID *param);

/** @brief Declares a destroy function */
#define RCU_DEC_DESTROY_FUNC(destroy_func,param) \
     extern RCU_VOID destroy_func(RCU_VOID *param);

/** @brief Declares a test run hook */
#define RCU_DEC_TEST_RUN_HOOK(run_hook,param) \
     extern RCU_VOID run_hook(RCU_VOID *param);

/** @brief Declares an assertion hook */
#define RCU_DEC_ASSERT_HOOK(assert_hook,param)
     extern RCU_VOID assert_hook(RCU_VOID *param);

/** @brief Declares a log handler implementation */
#define RCU_DEC_LOG_HANDLER_IMPL(log_impl,param)
    extern RCU_VOID log_impl(RCU_VOID *param);

/** @brief Declares an output handler implementation */
#define RCU_DEC_OUT_HANDLER_IMPL(out_impl,param)
    extern RCU_VOID out_impl(RCU_VOID *param);

#endif /* RCUNIT_HELPERS_H */

