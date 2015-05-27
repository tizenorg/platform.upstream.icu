 /*
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

static void utc_tizen_icu_api_ucnv_getAvailableName_func_01(void);
static void utc_tizen_icu_api_ucnv_getAvailableName_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucnv_getAvailableName_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucnv_getAvailableName_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_ucnv_getAvailableName start");
	return;
}

static void cleanup(void)
{
	tet_infoline
	    ("Testing API utc_tizen_icu_api_ucnv_getAvailableName ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucnv_getAvailableName()
 */
static void utc_tizen_icu_api_ucnv_getAvailableName_func_01(void)
{
	const char *result = NULL;
	int32_t max_count = ucnv_countAvailable();
	int32_t index = 0;

	for (index = 0; index < max_count; index++) {
		result = ucnv_getAvailableName(index);
		if (NULL != result) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getAvailableName test PASS!");
			tet_printf("Converter Name %s\n", result);
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_getAvailableName test FAIL!");
			tet_result(TET_FAIL);
		}
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucnv_getAvailableName()
 * giving index as out of bound will return null
 */
static void utc_tizen_icu_api_ucnv_getAvailableName_func_02(void)
{
	const char *result = NULL;
	int32_t index = 0;

	index = ucnv_countAvailable() + 2;
	result = ucnv_getAvailableName(index);	/* index is out of bound value */
	if (result == NULL) {
		tet_infoline
		    ("utc_tizen_icu_api_ucnv_getAvailableName test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline
		    ("utc_tizen_icu_api_ucnv_getAvailableName test FAIL!");
		tet_result(TET_FAIL);
	}
	return;

}
