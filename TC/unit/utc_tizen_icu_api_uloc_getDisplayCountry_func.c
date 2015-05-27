/*
 *  tizen-icu-api
 *
 * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Jayoun Lee <airjany@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <tet_api.h>
#include <unicode/utypes.h>
#include <unicode/uloc.h>
#include <unicode/ucal.h>
#include <unicode/udat.h>
#include <unicode/unum.h>
#include <unicode/ucnv.h>
#include <unicode/ustring.h>
#include <unistd.h>
#include<unicode/utmscale.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup) (void) = startup;
void (*tet_cleanup) (void) = cleanup;

static void utc_tizen_icu_api_uloc_getDisplayCountry_func_01(void);
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_02(void);
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_03(void);
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_04(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_uloc_getDisplayCountry_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getDisplayCountry_func_02, NEGATIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getDisplayCountry_func_03, NEGATIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getDisplayCountry_func_04, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_uloc_getDisplayCountry start");
	return;
}

static void cleanup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_uloc_getDisplayCountry ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_uloc_getDisplayCountry()
 */
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_01(void)
{
	const char *locale = uloc_getDefault();
	UChar Country[50] = { 0, };
	int32_t Country_capacity = 50;
	int32_t result;
	UErrorCode status = U_ZERO_ERROR;

	result =
	    uloc_getDisplayCountry(locale, NULL, Country, Country_capacity,
				   &status);
	if ((U_SUCCESS(status)) ) {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test PASS!");
		tet_printf("Display Country %s\n", Country);
		tet_result(TET_PASS);
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test FAIL!");
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getDisplayCountry()
 * status variable null will return error
 */
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_02(void)
{
	const char *locale = uloc_getDefault();
	UChar Country[50] = { 0, };
	int32_t Country_capacity = 50;
	int32_t result;

	result =
	    uloc_getDisplayCountry(locale, NULL, Country, Country_capacity,
				   NULL);
	if (result == 0) {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test FAIL!");
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getDisplayCountry()
 * if Country is null it should return the status as U_ILLEGAL_ARGUMENT_ERROR
 *
 */
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_03(void)
{
	int32_t Country_capacity = 50;
	int32_t result;
	UErrorCode status = U_ZERO_ERROR;

	result =
	    uloc_getDisplayCountry(NULL, NULL, NULL, Country_capacity, &status);
	if ((result == 0) || (U_FAILURE(status))) {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test FAIL!");
		tet_printf("Status %d\n", status);
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getDisplayCountry()
 * if Country capacity is less than zero it will return  status as U_ILLEGAL_ARGUMENT_ERROR
 *
 */
static void utc_tizen_icu_api_uloc_getDisplayCountry_func_04(void)
{
	UChar Country[50] = { 0, };
	int32_t Country_capacity = 0;
	int32_t result;
	UErrorCode status = U_ZERO_ERROR;

	result =
	    uloc_getDisplayCountry(NULL, NULL, Country, Country_capacity,
				   &status);
	if ((result == 0) || (U_FAILURE(status))) {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_uloc_getDisplayCountry test FAIL!");
		tet_printf("Status %d\n", status);
		tet_result(TET_FAIL);
	}
	return;
}
