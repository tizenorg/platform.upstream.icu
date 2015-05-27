 /*
  * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
  *
  * Contact: Hakjoo Ko <hakjoo.ko@samsung.com>
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

static void utc_tizen_icu_api_ucnv_getCanonicalName_func_01(void);
static void utc_tizen_icu_api_ucnv_getCanonicalName_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucnv_getCanonicalName_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucnv_getCanonicalName_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_ucnv_getCanonicalName start");
	return;
}

static void cleanup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_ucnv_getCanonicalName ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucnv_getCanonicalName()
 */
static void utc_tizen_icu_api_ucnv_getCanonicalName_func_01(void)
{
	const char *alias = "ibm-1208";
	const char *standard = "IBM";
	UErrorCode status = U_ZERO_ERROR;
	const char *result = NULL;
	const char *expect = "UTF-8";

	result = ucnv_getCanonicalName(alias, standard, &status);
	if ((U_SUCCESS(status)) && (NULL != result)) {
		if(strcmp(expect, result) == 0) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getCanonicalName test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getCanonicalName test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_ucnv_getCanonicalName test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucnv_getCanonicalName()
 * sending converter as null will return error
 */
static void utc_tizen_icu_api_ucnv_getCanonicalName_func_02(void)
{
	const char *alias = "ibm-5305";
	const char *standard = "IBM";
	UErrorCode status = U_ZERO_ERROR;
	const char *result = NULL;
	const char *expect = "UTF-16BE";

	result = ucnv_getCanonicalName(alias, standard, &status);
	if ((U_SUCCESS(status)) && (NULL != result)) {
		if(alias == result || strcmp(expect, result) != 0) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getCanonicalName test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getCanonicalName test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_ucnv_getCanonicalName test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;
}
